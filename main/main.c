#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"
#include "esp_err.h"

#include "i2c_bus.h"

#define TAG "MAIN"

/*static void i2c_scan(void)
{
    printf("\nScanning I2C bus...\n");

    for (uint8_t addr = 3; addr < 0x78; addr++) {
        i2c_cmd_handle_t cmd = i2c_cmd_link_create();
        i2c_master_start(cmd);
        i2c_master_write_byte(cmd, (addr << 1) | I2C_MASTER_WRITE, true);
        i2c_master_stop(cmd);

        esp_err_t ret = i2c_master_cmd_begin(I2C_PORT, cmd, pdMS_TO_TICKS(50));
        i2c_cmd_link_delete(cmd);

        if (ret == ESP_OK) {
            printf("Found I2C device at 0x%02X\n", addr);
        }
    }

    printf("Scan done.\n\n");
}*/

/*static void i2c_probe_veml7700(void)
{
    uint8_t addr = 0x10;

    i2c_cmd_handle_t cmd = i2c_cmd_link_create();
    i2c_master_start(cmd);
    i2c_master_write_byte(cmd, (addr << 1) | I2C_MASTER_WRITE, true);
    i2c_master_stop(cmd);

    esp_err_t ret = i2c_master_cmd_begin(I2C_PORT, cmd, pdMS_TO_TICKS(100));
    i2c_cmd_link_delete(cmd);

    if (ret == ESP_OK) {
        printf("VEML7700 FOUND at 0x10\n");
    } else {
        printf("No response from VEML7700 (err=%s)\n", esp_err_to_name(ret));
    }
}*/


void app_main(void)
{
    ESP_LOGI(TAG, "BOOTING SWAN-MODULE");
    vTaskDelay(pdMS_TO_TICKS(1000));

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

    // Read from VEML7700 (if present)
    uint8_t device_addr = 0x10;       // your device's I2C address
    uint8_t reg_addr = 0x00;          // register to read
    uint8_t value = 0;

    ret = i2c_master_write_read_device(I2C_PORT, device_addr, &reg_addr, 1, &value, 1, pdMS_TO_TICKS(100));
    if (ret == ESP_OK) {
        ESP_LOGI(TAG, "Read 0x%02X from device 0x%02X", value, device_addr);
    } else {
        ESP_LOGW(TAG, "Failed to read from device 0x%02X: %s", device_addr, esp_err_to_name(ret));
    }

    while (1) {
        vTaskDelay(pdMS_TO_TICKS(5000));
        i2c_scan();
    }
}
