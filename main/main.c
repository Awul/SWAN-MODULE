#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_err.h"

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
const char* sensors[] = {"temperature", "humidity", "light"};
#define SENSOR_COUNT 3
#define FIRMWARE_VERSION "0.1.0"



#define WIFI_SSID "swan-net"

// Change when i have a proper DNS server
#define MQTT_URI "mqtt://192.168.122.237:1883"
#define MQTT_ID NODE_ID
#define MQTT_USERNAME "swan"



veml7700_t veml_sensor;
sht40_t sht_sensor;
im72d128_t mic_sensor;


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

void setup_mqtt() {
    ESP_LOGI(TAG, "Starting MQTT initialization...");
    swan_mqtt_config_t config = {
        .broker_uri = MQTT_URI,
        .username   = MQTT_USERNAME,
        .password   = MQTT_PASSWORD_SECRET,
        .client_id  = NODE_ID,
    };

    swan_mqtt_client_init(&config);

        // Optionally wait until connected
    while (!swan_mqtt_client_is_connected()) {
        ESP_LOGI(TAG, "Waiting for MQTT connection...");
        vTaskDelay(pdMS_TO_TICKS(500));  // wait 500ms
    }

    ESP_LOGI(TAG, "MQTT initialization complete");
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


    //xTaskCreate(mic_task, "mic_task", AUDIO_TASK_STACK, &mic_sensor, AUDIO_TASK_PRIORITY, NULL);




    

}

void app_main(void)
{
    setup();

    while (1) {

        float lux;
        esp_err_t err = veml7700_read_lux(&veml_sensor, &lux);
        if (err == ESP_OK) {
            ESP_LOGI(TAG, "Ambient Light: %.2f lux", lux);
        } else {
            ESP_LOGE(TAG, "Failed to read lux: %s", esp_err_to_name(err));
        }

        float temperature, humidity;
        err = sht40_read_temp_humidity(&sht_sensor, &temperature, &humidity);
        if (err == ESP_OK) {
            ESP_LOGI(TAG, "Temperature: %.2f °C, Humidity: %.2f %%RH", temperature, humidity);
        } else {
            ESP_LOGE(TAG, "Failed to read temperature/humidity: %s", esp_err_to_name(err));
        }

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
        if (swan_mqtt_client_is_connected()) {
            // Build heartbeat JSON
            heartbeat_info_t hb = {
                .firmware = FIRMWARE_VERSION,
                .uptime = esp_timer_get_time() / 1000000, // Convert microseconds to seconds
                .sensors = sensors,
                .sensor_count = SENSOR_COUNT
            };
            cJSON* heartbeat = build_heartbeat_json(&hb);
            char* heartbeat_str = cJSON_PrintUnformatted(heartbeat);

            ESP_LOGD(TAG, "Publishing heartbeat: %s", heartbeat_str);
            swan_mqtt_client_publish("swan-hub/node/" NODE_ID "/heartbeat", heartbeat_str, 0, false);
            
            // avoid memory leak pls
            cJSON_Delete(heartbeat);
            free(heartbeat_str);

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
        }

        vTaskDelay(pdMS_TO_TICKS(5000));

        i2c_scan();
    }
}

