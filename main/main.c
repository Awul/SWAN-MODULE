#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_err.h"

#include "i2c_bus.h"
#include "veml7700.h"

#define TAG "MAIN"

veml7700_t veml_sensor;

void setup() {
    ESP_LOGI(TAG, "Setting up SWAN MODULE...");

    // Initialize the I2C bus
    esp_err_t ret = i2c_bus_init();
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize I2C: %s", esp_err_to_name(ret));
        return;
    }

    // Print the status
    i2c_bus_status();

    // Scan for devices
    i2c_scan();

    veml7700_init(&veml_sensor, I2C_PORT);

    veml7700_print_registers(&veml_sensor);
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

        vTaskDelay(pdMS_TO_TICKS(5000));

        i2c_scan();
    }
}
