#include "audio_stream.h"


static const char *TAG = "AUDIO_STREAM";


// Internal state
static audio_stream_config_t cfg;

static TaskHandle_t capture_task = NULL;
static TaskHandle_t network_task = NULL;
static TaskHandle_t stats_task = NULL;

static int sock = -1;
static volatile bool running = false;

// use a queue for task communication
QueueHandle_t audio_queue;


// status struct for debugging and monitoring
typedef struct {
    uint32_t i2s_reads;
    uint32_t i2s_errors;
    uint32_t queue_drops;
    uint32_t send_failures;
    uint32_t late_frames;
    uint32_t underruns;
    int64_t last_frame_tsf;

} audio_stats_t;

static audio_stats_t stats = {0};


// Debugging function to print audio streaming stats
static void audio_stats_task(void *arg)
{
    while (running) {

        ESP_LOGI(TAG,
            "AUD | reads=%lu err=%lu drop=%lu send_fail=%lu underrun=%lu",
            stats.i2s_reads,
            stats.i2s_errors,
            stats.queue_drops,
            stats.send_failures,
            stats.underruns
        );

        vTaskDelay(pdMS_TO_TICKS(5000)); // logs stats every 5 seconds
    }

    stats_task = NULL;
    vTaskDelete(NULL);
}

/**
 * @brief Connect to the TCP server specified in cfg
 * Helper function, not specified in header.
 * @return ESP_OK on success, ESP_FAIL on error
 */
static esp_err_t connect_to_server(void)
{
    struct sockaddr_in dest = {
        .sin_family = AF_INET,
        .sin_port = htons(cfg.port),
    };

    dest.sin_addr.s_addr = inet_addr(cfg.server_ip);

    sock = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
    if (sock < 0) return ESP_FAIL;

    if (connect(sock, (struct sockaddr *)&dest, sizeof(dest)) != 0) {
        close(sock);
        sock = -1;
        return ESP_FAIL;
    }

    ESP_LOGI(TAG, "Connected to %s:%d", cfg.server_ip, cfg.port);
    return ESP_OK;
}

/**
 * @brief Task function for audio reading
 * Continuously reads audio data from the microphone and sends it to the streaming queue.
 * 
 * The audio data is read into a buffer and then packed into an audio_frame_t structure before sending.
 * The timestamp is obtained using esp_wifi_get_tsf_time to synchronize with the Raspberry Pi server.
 * This requeires both devices to be on the same WiFi network.
 */
static void audio_capture_task(void *arg)
{
    // This buffer holds ONE frame of audio from the I2S microphone.
    // MALLOC_CAP_DMA is required because I2S DMA uses DMA-accessible memory.
    int16_t *buffer = heap_caps_malloc(
        MAX_FRAME_SAMPLES * sizeof(int16_t),
        MALLOC_CAP_DMA
    );

    if (!buffer) {
        ESP_LOGE(TAG, "DMA buffer alloc failed");
        vTaskDelete(NULL);
        return;
    }

    // Calculate the delay needed between reads to achieve the desired sample rate and frame size
    //TickType_t last = xTaskGetTickCount();
    // Basically milliseconds per frame
    const TickType_t period = pdMS_TO_TICKS((cfg.frame_size * 1000) / cfg.sample_rate);

    // The frame structure that will be sent over TCP. It includes:
    // - timestamp (TSF)
    // - sequence number (ordering / loss detection)
    // - sample count
    // - PCM samples
    //Allocate memory for fram
    //audio_frame_t *frame = malloc(sizeof(audio_frame_t));
    audio_frame_t frame;

    /*if (!frame) {
        ESP_LOGE(TAG, "Frame pool failed at startup");
        stats.queue_drops++;
        return;
    }*/
    // Sequence counter for debugging / packet ordering
    uint16_t seq = 0;

    
    while (running) {


        // Count the i2s reads for monitoring
        stats.i2s_reads++;

        size_t bytes_read = 0;
        // This pulls raw PCM samples from the microphone.
        // cfg.frame_size defines how many samples per packet.
        esp_err_t err = im72d128_read(
            cfg.mic,
            buffer,
            cfg.frame_size,
            &bytes_read
        );

        if (err != ESP_OK) {
            stats.i2s_errors++;
            ESP_LOGW(TAG, "Mic read failed");
            continue;
        }

        if ( (int16_t) bytes_read != cfg.frame_size * sizeof(int16_t)) {
            stats.underruns++;
            ESP_LOGW(TAG,"Underrun! expected=%d got=%d", cfg.frame_size * sizeof(int16_t), bytes_read);
        }

        // Capture timestamp for synchronization with Raspberry Pi server and construct rest of the frame
        frame.tsf_us = esp_wifi_get_tsf_time(WIFI_IF_STA);
        frame.seq = seq++;
        frame.n_samples = bytes_read / sizeof(int16_t);

        // Update stats for jitter calculation
        /*if (stats.last_frame_tsf != 0) {
            int64_t expected_us = (cfg.frame_size * 1000000LL) / cfg.sample_rate;
            int64_t delta = frame.tsf_us - stats.last_frame_tsf;
            int64_t jitter = delta - expected_us;
            if (llabs(jitter) > stats.max_jitter_us) {
                stats.max_jitter_us = llabs(jitter);
            }

            if (llabs(jitter) > 2000) { // >2ms jitter warning
                ESP_LOGW(TAG, "Audio jitter high: %lld ms", jitter/1000);
            }
        }*/

        stats.last_frame_tsf = frame.tsf_us;

        // Copy the read audio into the frame
        memcpy(frame.samples, buffer, bytes_read);

        // Send the frame to the streaming task via queue. If the queue is full, it will drop frames.
        if(audio_queue) {
            if (xQueueSend(audio_queue, &frame, pdMS_TO_TICKS(1000)) != pdTRUE) {
                //if queue full it will drop frames
                stats.queue_drops++;
                ESP_LOGW(TAG, "Audio buffer full (dropping frame) - do something please.");
            }
        }
        else{
            stats.queue_drops++;
            ESP_LOGE(TAG, "Audio queue is NULL - is the streaming task running? Dropping frame.");
        }
    }

    free(buffer);
    capture_task = NULL;
    vTaskDelete(NULL);
}

static void audio_network_task(void *arg)
{
    audio_frame_t frame;

    while (running) {

        // reconnect if socket is not connected
        if (sock < 0) {
            if (connect_to_server() != ESP_OK) {
                // If connection fails, wait and retry
                vTaskDelay(pdMS_TO_TICKS(1000));
                continue;
            }
        }

        // Wait for next frame in queue and send it via TCP.
        // If sending fails, it will attempt to reconnect in the next loop iteration.
        if(audio_queue){
            if (xQueueReceive(audio_queue, &frame, pdMS_TO_TICKS(1000)) == pdTRUE) {

                int sent = send(sock, &frame, sizeof(audio_frame_t), 0);

                if (sent < 0) {
                    stats.send_failures++;

                    ESP_LOGW(TAG, "Send failed, trying to reconnect...");

                    close(sock);
                    sock = -1;
                }
            }
        }
        else{
            stats.send_failures++;
            ESP_LOGE(TAG, "Audio queue is NULL in network task - maybe the streaming task isn't running?");
            vTaskDelay(pdMS_TO_TICKS(1000));
        }
    }

    network_task = NULL;
    vTaskDelete(NULL);
}


// Copies the config structure
esp_err_t audio_stream_init(const audio_stream_config_t *c)
{
    if (!c || !c->mic) return ESP_ERR_INVALID_ARG;

    if (c->frame_size > MAX_FRAME_SAMPLES){
        ESP_LOGE(TAG, "Frame size exceeds maximum allowed (%d)", MAX_FRAME_SAMPLES);
        return ESP_ERR_INVALID_ARG;
    }
    cfg = *c;
    return ESP_OK;
}

// starts the streaming task
esp_err_t audio_stream_start(void)
{
    if (running){
        ESP_LOGI(TAG, "Audio streaming is already running");
        return ESP_OK;
    }

    // create the stream buffer
    audio_queue = xQueueCreate(MAX_QUEUE_SIZE, sizeof(audio_frame_t));


    if (!audio_queue) {
        ESP_LOGE(TAG, "Failed to create audio queue");
        return ESP_FAIL;
    }

    running = true;

    // Start the capture task
    xTaskCreatePinnedToCore(audio_capture_task,
                "audio_capture",
                16384,
                NULL,
                10,
                &capture_task,
                1); 

    // Start the network task
    xTaskCreate(audio_network_task,
                "audio_network",
                16384,
                NULL,
                5,
                &network_task);

    // Low prio stats task to monitor the streaming performance
    xTaskCreate(audio_stats_task,
                "audio_stats",
                4096,
                NULL,
                2, 
                &stats_task);

    return ESP_OK;
}

// Stopping the streaming task and closing the socket
esp_err_t audio_stream_stop(void)
{
    running = false;

    ESP_LOGI(TAG, "Stopping audio streaming: Deleting Task and closing socket...");

    // Waits for 2000ms for tasks to exit gracefully. If they don't, they will be force deleted (which can cause memory leaks, but ensures shutdown).
    vTaskDelay(pdMS_TO_TICKS(2000));

    // Close connection if open
    if (sock >= 0) {
        close(sock);
        sock = -1;
    }

    // Delete queue
    if (audio_queue) {
        vQueueDelete(audio_queue);
        audio_queue = NULL;
    }


    // If tasks are still running delete them (they should exit on their own when running=false, but just in case)
    // BUT don't do this always, since it will result in memory leaks if done without care!
    if (capture_task) {
        ESP_LOGE(TAG, "Had to force delete capture task - this indicates a problem with task shutdown, investigate Sherlock!");
        vTaskDelete(capture_task);
        capture_task = NULL;
    }
    if (network_task) {
        ESP_LOGE(TAG, "Had to force delete network task - this indicates a problem with task shutdown, investigate Sherlock!");
        vTaskDelete(network_task);
        network_task = NULL;
    }
    if (stats_task) {
        ESP_LOGE(TAG, "Had to force delete stats task - this indicates a problem with task shutdown, investigate Sherlock!");
        vTaskDelete(stats_task);
        stats_task = NULL;
    }


    return ESP_OK;
}

