#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_err.h"
#include "esp_random.h"

#include "math.h"
#include "driver/uart.h"
#include "esp_timer.h"

#include "secrets.h"

#include "i2c_bus.h"
#include "veml7700.h"
#include "sht40.h"
#include "im72d128.h"

#include "wifi_manager.h"
#include "swan_mqtt_client.h"
#include "json_payload.h"
#include "audio_stream.h"


#define TAG "MAIN"

// Device Specific properties
#define NODE_ID "swan-module-TEST"
#define FIRMWARE_VERSION "0.1.1"

#define AUDIO_SERVER_PORT 9000
#define AUDIO_SERVER_IP "192.168.1.102"

#define WIFI_SSID "swan-net"

// Change when i have a proper DNS server
/**
 * @brief the SWAB-HUB must have a static IP.
 */
#define MQTT_URI "mqtt://192.168.1.100:1883"
#define MQTT_ID NODE_ID
#define MQTT_USERNAME "swan"

int READ_INTERVAL = 5000; // ms
int HEARTBEAT_INTERVAL = 15000; // ms
int JITTER_INTERVAL = 3000; // ms, added to sync read to avoid clashing with other nodes
static bool audio_enabled = false; // Is true if microphone is registered as a sensor.

#define VEML7700_ZERO_CHECK_THRESHOLD 6
#define VEML7700_ZERO_REINIT_THRESHOLD 12
#define VEML7700_EXPECTED_ID_LSB 0x81

static int consecutive_light_zero_count = 0;


/**
 * @brief Generic callback type to read a sensor. This ensures that the sensors can be expanded later.
 *
 * @param value Pointer to float where the sensor value should be stored
 * @return ESP_OK if read was successful, otherwise an error code
 */
typedef esp_err_t (*sensor_read_cb_t)(float *value);

/**
 * @brief Sensor struct to hold name and callback function.
 */
typedef struct {
    const char *name;          ///< Name of the sensor for JSON keys
    sensor_read_cb_t read_cb;  ///< Function to read the sensor
} sensor_t;

/**
 * @brief Sensor definitions. Add new sensors here.
 */
veml7700_t veml_sensor;
sht40_t sht_sensor;
im72d128_t mic_sensor;

// Add new sensors callbacks here!

static bool veml7700_it_bits_valid(uint8_t it_bits)
{
    return it_bits == 0x0 || it_bits == 0x1 || it_bits == 0x2 ||
           it_bits == 0x3 || it_bits == 0x8 || it_bits == 0xC;
}

static bool diagnose_veml7700_zero_reading(void)
{
    uint16_t als_conf = 0;
    uint16_t power_save = 0;
    uint16_t als = 0;
    uint16_t id = 0;

    esp_err_t conf_err = veml7700_read_register(&veml_sensor, VEML7700_REG_ALS_CONF_0, &als_conf);
    esp_err_t power_err = veml7700_read_register(&veml_sensor, VEML7700_REG_POWER_SAVING, &power_save);
    esp_err_t als_err = veml7700_read_register(&veml_sensor, VEML7700_REG_ALS, &als);
    esp_err_t id_err = veml7700_read_register(&veml_sensor, VEML7700_REG_ID, &id);

    if (conf_err != ESP_OK || power_err != ESP_OK || als_err != ESP_OK || id_err != ESP_OK) {
        ESP_LOGW(TAG,
                 "VEML7700 zero diagnostic read failed: conf=%s power=%s als=%s id=%s",
                 esp_err_to_name(conf_err),
                 esp_err_to_name(power_err),
                 esp_err_to_name(als_err),
                 esp_err_to_name(id_err));
        return true;
    }

    uint8_t gain_bits = (als_conf >> 11) & 0x03;
    uint8_t it_bits = (als_conf >> 6) & 0x0F;
    bool shutdown = (als_conf & 0x01) != 0;
    bool psm_enabled = (power_save & 0x01) != 0;
    bool id_valid = (id & 0xFF) == VEML7700_EXPECTED_ID_LSB;
    bool it_valid = veml7700_it_bits_valid(it_bits);

    ESP_LOGW(TAG,
             "VEML7700 zero diagnostic: ALS_CONF_0=0x%04X POWER_SAVE=0x%04X ALS=%u ID=0x%04X gain=%u it=0x%X shutdown=%s psm=%s id=%s",
             als_conf,
             power_save,
             als,
             id,
             gain_bits,
             it_bits,
             shutdown ? "YES" : "NO",
             psm_enabled ? "YES" : "NO",
             id_valid ? "VALID" : "BAD");

    if (!id_valid) {
        ESP_LOGW(TAG, "VEML7700 appears missing or misread: unexpected device ID");
        return true;
    }

    if (shutdown || psm_enabled || !it_valid) {
        ESP_LOGW(TAG, "VEML7700 appears misconfigured: shutdown=%d psm=%d it_valid=%d", shutdown, psm_enabled, it_valid);
        return true;
    }

    ESP_LOGW(TAG, "VEML7700 is active and still reports raw ALS=0; this may be true darkness or a stuck sensor state");
    return false;
}

static void handle_veml7700_light_result(esp_err_t err, float lux)
{
    if (err != ESP_OK) {
        consecutive_light_zero_count++;
        ESP_LOGW(TAG, "VEML7700 light read failed %d time(s) in a row: %s",
                 consecutive_light_zero_count,
                 esp_err_to_name(err));

        if (consecutive_light_zero_count >= VEML7700_ZERO_REINIT_THRESHOLD) {
            ESP_LOGW(TAG, "Reinitializing VEML7700 after repeated read failures");
            esp_err_t init_err = veml7700_init(&veml_sensor, I2C_PORT);
            ESP_LOGW(TAG, "VEML7700 reinit result: %s", esp_err_to_name(init_err));
            consecutive_light_zero_count = 0;
        }
        return;
    }

    if (lux > 0.0f) {
        consecutive_light_zero_count = 0;
        return;
    }

    consecutive_light_zero_count++;

    if (consecutive_light_zero_count < VEML7700_ZERO_CHECK_THRESHOLD) {
        return;
    }

    bool should_reinit = diagnose_veml7700_zero_reading();
    if (should_reinit || consecutive_light_zero_count >= VEML7700_ZERO_REINIT_THRESHOLD) {
        ESP_LOGW(TAG, "Reinitializing VEML7700 after %d consecutive zero light readings",
                 consecutive_light_zero_count);
        esp_err_t init_err = veml7700_init(&veml_sensor, I2C_PORT);
        ESP_LOGW(TAG, "VEML7700 reinit result: %s", esp_err_to_name(init_err));
        consecutive_light_zero_count = 0;
    }
}

// Temperature callback
esp_err_t read_temperature(float *value) {
    float t, h;
    esp_err_t err = sht40_read_temp_humidity(&sht_sensor, &t, &h);
    if (err == ESP_OK) *value = t;
    return err;
}

// Humidity callback
esp_err_t read_humidity(float *value) {
    float t, h;
    esp_err_t err = sht40_read_temp_humidity(&sht_sensor, &t, &h);
    if (err == ESP_OK) *value = h;
    return err;
}

// Light (lux) callback
esp_err_t read_lux(float *value) {
    esp_err_t err = veml7700_read_lux(&veml_sensor, value);
    handle_veml7700_light_result(err, err == ESP_OK ? *value : 0.0f);
    return err;
}

// Microphone callback
esp_err_t read_mic(float *value) {
    // Implement my readings...
    *value = 0.0f; // placeholder
    return ESP_OK;
}

/**
* @brief Sensors and their Callbacks, add new Sensors here!
*/
sensor_t sensors_table[] = {
    {"temperature", read_temperature},
    {"humidity", read_humidity},
    {"light", read_lux},
    {"audio", read_mic}
};

#define SENSOR_COUNT (sizeof(sensors_table) / sizeof(sensor_t))

/**
 * @brief Array to hold sensor names for the heartbeat message, populated from sensors_table. To avoid reading the names each time.
 */
const char* sensor_names[SENSOR_COUNT];

void setup_sensor_names() {
    ESP_LOGI(TAG, "Starting sensor name population...");
    for (int i = 0; i < SENSOR_COUNT; i++) {
        sensor_names[i] = sensors_table[i].name;
        ESP_LOGI(TAG, "Sensor name populated: %s", sensor_names[i]);
    }
    ESP_LOGI(TAG, "Sensor names populated successfully");
}



/**
 * @brief Struct to hold the a generic sensor readings (float values)
 */
typedef struct {
    const char *name;
    float value;
    esp_err_t err; // optional: store read status
} sensor_reading_t;

/**
 * @brief Function to read all sensors and return their readings as an array of sensor_reading_t
 * @param readings Pointer to the array where sensor readings will be stored
 * @return Number of sensors read successfully, or -1 on error
 */
esp_err_t read_all_sensors(sensor_reading_t *readings)
{
    if (!readings) return ESP_FAIL;

    // Value variable to be filled by callbacks
    float value;

    // Iterate over all sensors and read their values using the callbacks
    for (int i = 0; i < SENSOR_COUNT; i++) {
        // Get pointer to sensor
        sensor_t *sensor = &sensors_table[i];

        // Call sensor callback
        value = 0.0f;
        esp_err_t err = sensor->read_cb(&value);

        // Store the result in the readings array as sensor_reading_t
        readings[i].name = sensor->name;
        readings[i].value = value;
        readings[i].err = err;

        if (err != ESP_OK) {
            ESP_LOGE(TAG, "Failed to read sensor %s: %s", sensor->name, esp_err_to_name(err));
        } else {
            ESP_LOGD(TAG, "Read sensor %s: %.2f", sensor->name, value);
        }
    }

    // Is okay if the loop had errors, we can check the individual readings for that. So we return ESP_OK as long as the function executed.
    return ESP_OK;
}


void sync_read_and_publish(uint64_t scheduled_tsf)
{
    sensor_reading_t readings[SENSOR_COUNT];

    // Waiting for goal TSF
    int64_t diff;
    while (1) {
        diff = (int64_t)(scheduled_tsf - esp_wifi_get_tsf_time(WIFI_IF_STA));

        if (diff <= 0) break;

        if (diff > 2000) {
            esp_rom_delay_us(diff / 2);
        } else if (diff > 200) {
            esp_rom_delay_us(50);
        }
    }

    // Get TSF when actually reading
    int64_t actual_tsf = esp_wifi_get_tsf_time(WIFI_IF_STA);
    // Time sensor readings
    int64_t start_us = esp_timer_get_time();

    // Read all sensors
    read_all_sensors(readings);

    int64_t end_us = esp_timer_get_time();

    // Calculate total time taken for sensor readings
    int32_t dt_ms = (int32_t)((end_us - start_us) / 1000);

    // build json
    cJSON *root = cJSON_CreateObject();

    cJSON *sensors = cJSON_CreateObject();

    for (int i = 0; i < SENSOR_COUNT; i++) {

        if (readings[i].err == ESP_OK) {
            cJSON_AddNumberToObject(
                sensors,
                readings[i].name,
                readings[i].value
            );
        }
    }
    
    cJSON_AddNumberToObject(root, "tsf_excecuted", actual_tsf);
    cJSON_AddNumberToObject(root, "tsf_scheduled", scheduled_tsf);
    cJSON_AddItemToObject(root, "s", sensors);
    cJSON_AddNumberToObject(root, "dt_ms", dt_ms);

    // Add jitter when sending to reduce clashing with other nodes.
    esp_rom_delay_us(esp_random() % JITTER_INTERVAL); // 0–3ms

    char *payload = cJSON_PrintUnformatted(root);

    swan_mqtt_client_publish(
        "swan-hub/node/" NODE_ID "/sync_data",
        payload,
        0,
        false
    );

    free(payload);
    cJSON_Delete(root);
}


void setup_i2c(){
    // Initialize the I2C bus
    ESP_LOGI(TAG, "Starting I2C bus initialization...");
    esp_err_t ret = i2c_bus_init();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize I2C: %s", esp_err_to_name(ret));
        return;
    }

    // Print the status
    i2c_bus_status();

    // Scan for devices
    i2c_scan();
    ESP_LOGI(TAG, "I2C bus initialized successfully");
}

void setup_veml7700() {
    // Initialize the light sensor
    ESP_LOGI(TAG, "Starting VEML7700 initialization...");
    esp_err_t ret = veml7700_init(&veml_sensor, I2C_PORT);

    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize VEML7700: %s", esp_err_to_name(ret));
        return;
    }

    veml7700_print_registers(&veml_sensor);
    ESP_LOGI(TAG, "VEML7700 initialized successfully");
}

void setup_sht40() {
    // Initialize the temperature/humidity sensor
    ESP_LOGI(TAG, "Starting SHT40 initialization..."); 
    esp_err_t ret = sht40_init(&sht_sensor, I2C_PORT, SHT40_I2C_ADDR_DEFAULT);

    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize SHT40: %s", esp_err_to_name(ret));
        return;
    }

    uint32_t serial;
    sht40_read_serial(&sht_sensor, &serial);
    ESP_LOGI(TAG, "SHT40 Serial Number: 0x%08X", serial);
    ESP_LOGI(TAG, "SHT40 initialized successfully");
}

void setup_im72d128() {
    // Initialize the microphone
    ESP_LOGI(TAG, "Starting IM72D128 initialization...");
    esp_err_t ret = im72d128_init(&mic_sensor,
                                  I2S_NUM_0,
                                  MIC_CLK_PIN,
                                  MIC_DATA_PIN,
                                  48000);

    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize IM72D128: %s", esp_err_to_name(ret));
        return;
    }

    // Test reading from microphone (read 1024 samples)
    size_t bytes_read = 0;
    int16_t *audio_buffer = heap_caps_malloc(1024 * sizeof(int16_t), MALLOC_CAP_DMA);

    if (!audio_buffer) {
        ESP_LOGE(TAG, "Failed to allocate DMA buffer");
        return;
    }

    ret = im72d128_read(&mic_sensor, audio_buffer, 1024, &bytes_read, 1);
    ESP_LOGI(TAG, "Read %d bytes from microphone (err=%d)", bytes_read, ret);

    float sum_sq = 0;
    for (int i = 0; i < 1024; i++) {
        sum_sq += audio_buffer[i] * audio_buffer[i];
    }
    float rms = sqrtf(sum_sq / 1024);
    ESP_LOGI(TAG, "RMS amplitude: %.2f", rms);

    heap_caps_free(audio_buffer);

    audio_enabled = true; // Set to true if microphone initialized successfully
    ESP_LOGI(TAG, "IM72D128 initialized successfully");
}

void setup_wifi(){
    // Initialize WIFI
    ESP_LOGI(TAG, "Starting WiFi initialization...");
    wifi_manager_config_t wifi_cfg = {
        .ssid = WIFI_SSID,
        .password = WIFI_PASSWORD_SECRET,
    };

    /* Initialize WiFi */
    ESP_ERROR_CHECK(wifi_manager_init(&wifi_cfg));

    /* Wait until connected */
    if (wifi_manager_wait_connected() == ESP_OK)
    {
        ESP_LOGI(TAG, "WiFi connected successfully");
    }
    else
    {
        ESP_LOGE(TAG, "WiFi connection failed");
        return;
    }
    ESP_LOGI(TAG, "WiFi initialization complete");
}

void setup_audio_stream()
{
    if (!audio_enabled) {
        ESP_LOGW(TAG, "Audio stream setup called but audio is not enabled. Skipping.");
        return;
    }
    ESP_LOGI(TAG, "setting up audio stream...");
    audio_stream_config_t cfg = {
        .server_ip = AUDIO_SERVER_IP,
        .port = AUDIO_SERVER_PORT,
        .sample_rate = 48000,
        .frame_size = 256,
        .audio_queque_size = 8,
        .mic = &mic_sensor,
    };

    ESP_ERROR_CHECK(audio_stream_init(&cfg));
    ESP_LOGI(TAG, "Audio stream initialized");
}

// mqtt command handler for incoming MQTT commands, needs to be registered with the MQTT component
void mqtt_command_handler(const char* topic, const char* payload) {

    if (strcmp(topic, "swan-hub/command/" NODE_ID "/audio-start") == 0 || strcmp(topic, "swan-hub/command/ALL/audio-start") == 0) {

        ESP_LOGI(TAG, "Audio stream START requested");
        audio_stream_start();
    }
    else if (strcmp(topic, "swan-hub/command/" NODE_ID "/audio-stop") == 0 || strcmp(topic, "swan-hub/command/ALL/audio-stop") == 0) {

        ESP_LOGI(TAG, "Audio stream STOP requested");
        audio_stream_stop();
    }
    else if (strcmp(topic, "swan-hub/command/" NODE_ID "/sync-read") == 0 || strcmp(topic, "swan-hub/command/ALL/sync-read") == 0) {

        ESP_LOGI(TAG, "Received command for sync read: %s - payload %s", topic, payload);
        // Parse Payload
        cJSON *root = cJSON_Parse(payload);
        if (!root) {
            ESP_LOGE(TAG, "Invalid JSON payload");
            return;
        }

        cJSON *tsf_item = cJSON_GetObjectItem(root, "tsf_scheduled");
        if (!cJSON_IsNumber(tsf_item)) {
            ESP_LOGE(TAG, "Missing or invalid tsf field");
            cJSON_Delete(root);
            return;
        }
        // Cast to int
        uint64_t scheduled_tsf = (uint64_t) tsf_item->valuedouble;

        cJSON_Delete(root);

        sync_read_and_publish(scheduled_tsf);
    }
     else {
        ESP_LOGW(TAG, "Received command for unknown topic: %s", topic);
    }
}

void setup_mqtt() {
    ESP_LOGI(TAG, "Starting MQTT initialization...");
    swan_mqtt_config_t config = {
        .broker_uri = MQTT_URI,
        .username   = MQTT_USERNAME,
        .password   = MQTT_PASSWORD_SECRET,
        .client_id  = NODE_ID,
    };

    // Register main's callback with MQTT
    swan_mqtt_client_register_command_callback(mqtt_command_handler);

    swan_mqtt_client_init(&config);

        // Optionally wait until connected
    while (!swan_mqtt_client_is_connected()) {
        ESP_LOGI(TAG, "Waiting for MQTT connection...");
        vTaskDelay(pdMS_TO_TICKS(500));  // wait 500ms
    }

    ESP_LOGI(TAG, "MQTT initialization complete");
}

// Task to periodically publish heartbeat and sensor data to MQTT
void heartbeat_task(void *arg)
{
    while (1) {

        sensor_reading_t readings[SENSOR_COUNT];
        read_all_sensors(readings);

        heartbeat_info_t hb = {
            .firmware = FIRMWARE_VERSION,
            .uptime = esp_timer_get_time() / 1000000, // Convert microseconds to seconds
            .sensors = sensor_names,
            .sensor_count = SENSOR_COUNT
        };

        cJSON* heartbeat = build_heartbeat_json(&hb);
        if (!heartbeat) {
            ESP_LOGE(TAG, "Failed to build heartbeat JSON");
            vTaskDelay(pdMS_TO_TICKS(HEARTBEAT_INTERVAL));
            continue;
        }

        cJSON* sensor_values = cJSON_CreateObject();
        if (sensor_values) {
            for (int i = 0; i < SENSOR_COUNT; i++) {
                if (readings[i].err == ESP_OK) {
                    cJSON_AddNumberToObject(sensor_values, readings[i].name, readings[i].value);
                } else {
                    cJSON_AddNullToObject(sensor_values, readings[i].name);
                }
            }
            cJSON_AddItemToObject(heartbeat, "sensor_data", sensor_values);
        } else {
            ESP_LOGE(TAG, "Failed to create heartbeat sensor_data object");
        }

        char* heartbeat_str = cJSON_PrintUnformatted(heartbeat);

        ESP_LOGD(TAG, "Publishing heartbeat: %s", heartbeat_str);
        swan_mqtt_client_publish(
            "swan-hub/node/" NODE_ID "/heartbeat",
            heartbeat_str,
            0,
            false
        );

        cJSON_Delete(heartbeat);
        free(heartbeat_str);

        vTaskDelay(pdMS_TO_TICKS(HEARTBEAT_INTERVAL)); // every HEARTBEAT_INTERVAL ms
    }
}


/**
 * @brief Debug function to read sensors and print their values, can be adapted to publish to MQTT instead
 */
void print_sensor_data(void *arg)
{
    // Array to hold sensor readings
    sensor_reading_t readings[SENSOR_COUNT];

    // Infinite loop to read sensors periodically and printing the results
    while (1) {
        read_all_sensors(readings);

        for (int i = 0; i < SENSOR_COUNT; i++) {
            if (readings[i].err == ESP_OK)
                ESP_LOGI(TAG, "%s: %.2f", readings[i].name, readings[i].value);
            else
                ESP_LOGW(TAG, "Failed to read %s", readings[i].name);
        }

        vTaskDelay(pdMS_TO_TICKS(READ_INTERVAL));
    }
}

void setup() {

    ESP_LOGI(TAG, "Setting up SWAN MODULE...");
    ESP_LOGI(TAG, "#########################");
    setup_i2c();
    ESP_LOGI(TAG, "#########################");
    setup_veml7700();
    ESP_LOGI(TAG, "#########################");
    setup_sht40();
    ESP_LOGI(TAG, "#########################");
    setup_im72d128();
    ESP_LOGI(TAG, "#########################");
    setup_wifi();
    ESP_LOGI(TAG, "#########################");
    setup_mqtt();
    ESP_LOGI(TAG, "#########################");
    setup_sensor_names();
    ESP_LOGI(TAG, "#########################");
    setup_audio_stream();
    ESP_LOGI(TAG, "#########################");

    //xTaskCreate(mic_task, "mic_task", AUDIO_TASK_STACK, &mic_sensor, AUDIO_TASK_PRIORITY, NULL);
}

void app_main(void)
{
    setup();

    xTaskCreate(print_sensor_data, "print_sensor_data", 4096, NULL, 5, NULL);
    xTaskCreate(heartbeat_task, "heartbeat_task", 4096, NULL, 4, NULL);

    while (1) {

        if (!wifi_manager_is_connected()) {
            ESP_LOGW(TAG, "WiFi lost");
        }

        if (!swan_mqtt_client_is_connected()) {
            ESP_LOGW(TAG, "MQTT disconnected");
        }

        vTaskDelay(pdMS_TO_TICKS(10000));
     
    }
}
