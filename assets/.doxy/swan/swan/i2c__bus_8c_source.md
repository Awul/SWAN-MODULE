

# File i2c\_bus.c

[**File List**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**i2c\_bus**](dir_b27305f47d68ba65b41a21460fb415ed.md) **>** [**i2c\_bus.c**](i2c__bus_8c.md)

[Go to the documentation of this file](i2c__bus_8c.md)


```C++
#include "i2c_bus.h"
#include "freertos/semphr.h"

#define I2C_SDA  8
#define I2C_SCL  9
#define I2C_FREQ 100000

static SemaphoreHandle_t i2c_mutex = NULL;

esp_err_t i2c_bus_init(void)
{
    static bool initialized = false;
    if (initialized) return ESP_OK;

    i2c_config_t conf = {
        .mode = I2C_MODE_MASTER,
        .sda_io_num = I2C_SDA,
        .scl_io_num = I2C_SCL,
        .sda_pullup_en = GPIO_PULLUP_ENABLE,
        .scl_pullup_en = GPIO_PULLUP_ENABLE,
        .master.clk_speed = I2C_FREQ,
    };

    ESP_ERROR_CHECK(i2c_param_config(I2C_PORT, &conf));
    ESP_ERROR_CHECK(i2c_driver_install(I2C_PORT, conf.mode, 0, 0, 0));

    if (!i2c_mutex) i2c_mutex = xSemaphoreCreateMutex();

    initialized = true;
    return ESP_OK;
}

esp_err_t i2c_bus_write_read(uint8_t addr,
                             uint8_t *write_buf, size_t write_len,
                             uint8_t *read_buf, size_t read_len,
                             TickType_t ticks_to_wait)
{
    esp_err_t err = ESP_OK;
    if (xSemaphoreTake(i2c_mutex, ticks_to_wait) == pdTRUE) {
        if (write_len && read_len)
            err = i2c_master_write_read_device(I2C_PORT, addr, write_buf, write_len, read_buf, read_len, ticks_to_wait);
        else if (write_len)
            err = i2c_master_write_to_device(I2C_PORT, addr, write_buf, write_len, ticks_to_wait);
        else if (read_len)
            err = i2c_master_read_from_device(I2C_PORT, addr, read_buf, read_len, ticks_to_wait);
        xSemaphoreGive(i2c_mutex);
    } else {
        err = ESP_ERR_TIMEOUT;
    }
    return err;
}
```


