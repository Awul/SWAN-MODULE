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


#define TAG "MAIN"

// Device Specific properties
#define NODE_ID "swan-module-TEST"
#define FIRMWARE_VERSION "0.1.0"



#define WIFI_SSID "swan-net"

// Change when i have a proper DNS server
/**
 * @brief the SWAB-HUB must have a static IP.
 */
#define MQTT_URI "mqtt://192.168.1.100:1883"
#define MQTT_ID NODE_ID
#define MQTT_USERNAME "swan"

int READ_INTERVAL = 2000; // ms
int HEARTBEAT_INTERVAL = 10000; // ms
int JITTER_INTERVAL = 3000; // ms, added to sync read to avoid clashing with other nodes


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
    return veml7700_read_lux(&veml_sensor, value);
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

    ret = im72d128_read(&mic_sensor, audio_buffer, 1024, &bytes_read);
    ESP_LOGI(TAG, "Read %d bytes from microphone (err=%d)", bytes_read, ret);

    float sum_sq = 0;
    for (int i = 0; i < 1024; i++) {
        sum_sq += audio_buffer[i] * audio_buffer[i];
    }
    float rms = sqrtf(sum_sq / 1024);
    ESP_LOGI(TAG, "RMS amplitude: %.2f", rms);

    heap_caps_free(audio_buffer);

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

// mqtt command handler for incoming MQTT commands, needs to be registered with the MQTT component
void mqtt_command_handler(const char* topic, const char* payload) {
    // react to individual
    if (strcmp(topic, "swan-hub/command/" NODE_ID "/last_read") == 0 || strcmp(topic, "swan-hub/command/ALL/last_read") == 0) {
        // trigger sensor read task
        //publish_all_sensors();
        ESP_LOGI(TAG, "Received command for last read: %s - payload %s", topic, payload);
    }
    else if (strcmp(topic, "swan-hub/command/" NODE_ID "/sync_read") == 0 || strcmp(topic, "swan-hub/command/ALL/sync_read") == 0) {
        // trigger sensor read task
        //read_and_publish_all_sensors();
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


        heartbeat_info_t hb = {
            .firmware = FIRMWARE_VERSION,
            .uptime = esp_timer_get_time() / 1000000, // Convert microseconds to seconds
            .sensors = sensor_names,
            .sensor_count = SENSOR_COUNT
        };

        cJSON* heartbeat = build_heartbeat_json(&hb);
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
        esp_err_t err = read_all_sensors(readings);

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

    //xTaskCreate(mic_task, "mic_task", AUDIO_TASK_STACK, &mic_sensor, AUDIO_TASK_PRIORITY, NULL);
}

void app_main(void)
{
    setup();

    xTaskCreate(print_sensor_data, "print_sensor_data", 4096, NULL, 5, NULL);
    xTaskCreate(heartbeat_task, "heartbeat_task", 4096, NULL, 4, NULL);

    while (1) {

        // Wifi connection check!
        if (wifi_manager_is_connected())
        {
            ESP_LOGI(TAG, "WiFi still connected");
        }
        else
        {
            ESP_LOGW(TAG, "WiFi lost connection");
        }

        // Test broadcasting MQTT message
        /*if (false) { // deactivated for now
            // PUBLISH Temperature
            char temperature_str[32];  // buffer to hold the string
            // Convert float to string
            snprintf(temperature_str, sizeof(temperature_str), "%.2f", temperature);
            ESP_LOGD(TAG, "Converted temperature to string: %s", temperature_str);

            cJSON* temp_sensor_json = build_sensor_json(temperature_str);
            char* temp_sensor_str = cJSON_PrintUnformatted(temp_sensor_json);

            ESP_LOGD(TAG, "Publishing temp sensor data: %s", temp_sensor_str);
            swan_mqtt_client_publish("swan-hub/node/" NODE_ID "/temperature", temp_sensor_str, 0, false);

            // avoid memory leak again pls
            cJSON_Delete(temp_sensor_json);
            free(temp_sensor_str);

            //PUBLISH Humidity
            char humidity_str[32];  // buffer to hold the string
            // Convert float to string
            snprintf(humidity_str, sizeof(humidity_str), "%.2f", humidity);
            ESP_LOGD(TAG, "Converted humidity to string: %s", humidity_str);

            cJSON* humidity_sensor_json = build_sensor_json(humidity_str);
            char* humidity_sensor_str = cJSON_PrintUnformatted(humidity_sensor_json);

            ESP_LOGD(TAG, "Publishing humidity sensor data: %s", humidity_sensor_str);
            swan_mqtt_client_publish("swan-hub/node/" NODE_ID "/humidity", humidity_sensor_str, 0, false);

            // avoid memory leak again pls
            cJSON_Delete(humidity_sensor_json);
            free(humidity_sensor_str);

            //PUBLISH Light
            char light_str[32];  // buffer to hold the string
            // Convert float to string
            snprintf(light_str, sizeof(light_str), "%.2f", lux);
            ESP_LOGD(TAG, "Converted light to string: %s", light_str);

            cJSON* light_sensor_json = build_sensor_json(light_str);
            char* light_sensor_str = cJSON_PrintUnformatted(light_sensor_json);

            ESP_LOGD(TAG, "Publishing light sensor data: %s", light_sensor_str);
            swan_mqtt_client_publish("swan-hub/node/" NODE_ID "/light", light_sensor_str, 0, false);

            // avoid memory leak again pls
            cJSON_Delete(light_sensor_json);
            free(light_sensor_str);
        }*/

        vTaskDelay(pdMS_TO_TICKS(5000));

        i2c_scan();
    }
}

