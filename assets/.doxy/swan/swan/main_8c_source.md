

# File main.c

[**File List**](files.md) **>** [**main**](dir_5c982d53a68cdbcd421152b4020263a9.md) **>** [**main.c**](main_8c.md)

[Go to the documentation of this file](main_8c.md)


```C++
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_err.h"

#include "i2c_bus.h"
#include "veml7700.h"
#include "sht40.h"

#define TAG "MAIN"

veml7700_t veml_sensor;
sht40_t sht_sensor;

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

    sht40_init(&sht_sensor, I2C_PORT, SHT40_I2C_ADDR_DEFAULT);

    uint32_t serial;
    sht40_read_serial(&sht_sensor, &serial);
    ESP_LOGI(TAG, "SHT40 Serial Number: 0x%08X", serial);

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

        vTaskDelay(pdMS_TO_TICKS(5000));

        i2c_scan();
    }
}
```


