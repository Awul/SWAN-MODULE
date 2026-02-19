

# File i2c\_bus.c

[**File List**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**i2c\_bus**](dir_b27305f47d68ba65b41a21460fb415ed.md) **>** [**i2c\_bus.c**](i2c__bus_8c.md)

[Go to the documentation of this file](i2c__bus_8c.md)


```C++
#include "i2c_bus.h"
#include "freertos/semphr.h"
#include "esp_log.h"


static const char *TAG = "I2C_BUS";

// Mutex to protect the I2C bus for thread-safe access
static SemaphoreHandle_t i2c_mutex = NULL;

esp_err_t i2c_bus_init(void)
{
    static bool initialized = false; // Ensure bus is only initialized once
    if (initialized) return ESP_OK;

    // I2C configuration structure
    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,        // Master mode
        .sda_io_num = I2C_SDA,          // SDA pin
        .scl_io_num = I2C_SCL,          // SCL pin
        .sda_pullup_en = GPIO_PULLUP_ENABLE, // Enable internal pull-ups
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_FREQ,   // Clock speed
    };

    // Configure I2C parameters
    ESP_ERROR_CHECK(i2c_param_config(I2C_PORT, &conf));

    // Install I2C driver (no RX/TX buffer for master)
    ESP_ERROR_CHECK(i2c_driver_install(I2C_PORT, conf.mode, 0, 0, 0));

    // Create mutex if not already created
    if (!i2c_mutex) {
        i2c_mutex = xSemaphoreCreateMutex();
    }

    initialized = true;
    ESP_LOGI(TAG, "I2C bus initialized (SDA=%d, SCL=%d, Freq=%d)", I2C_SDA, I2C_SCL, I2C_FREQ);
    return ESP_OK;
}


void i2c_bus_status(void)
{
    ESP_LOGI(TAG, "I2C Status:");
    ESP_LOGI(TAG, "Port: %d", I2C_PORT);
    ESP_LOGI(TAG, "Mutex created: %s", i2c_mutex ? "Yes" : "No");
    ESP_LOGI(TAG, "SDA: %d, SCL: %d, Freq: %d Hz", I2C_SDA, I2C_SCL, I2C_FREQ);

    // test write/read to address 0x00
    uint8_t test = 0;
    esp_err_t err = i2c_master_write_read_device(I2C_PORT, 0x00, &test, 1, NULL, 0, pdMS_TO_TICKS(100));
    if (err == ESP_OK) {
        ESP_LOGI(TAG, "Test write to 0x00 succeeded");
    } else {
        ESP_LOGW(TAG, "Test write to 0x00 failed: %s", esp_err_to_name(err));
    }
}

void i2c_scan(void)
{
    ESP_LOGI(TAG, "Scanning I2C bus...");

    uint8_t dummy = 0;  // dummy byte for probing

    for (uint8_t addr = 3; addr < 0x78; addr++) {

        // ESP_LOGI(TAG, "Scanning: 0x%02X", addr);

        esp_err_t err = i2c_master_write_to_device(I2C_PORT, addr, &dummy, 1, pdMS_TO_TICKS(50));

        if (err == ESP_OK) {
            ESP_LOGI(TAG, "Found I2C device at 0x%02X", addr);
        }
    }

    ESP_LOGI(TAG, "Scan complete.");
}
```


