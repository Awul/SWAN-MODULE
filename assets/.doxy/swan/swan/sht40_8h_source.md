

# File sht40.h

[**File List**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**sht40**](dir_180d7217a87f12caa6a5edfd7755cc1b.md) **>** [**sht40.h**](sht40_8h.md)

[Go to the documentation of this file](sht40_8h.md)


```C++


#pragma once
#include "driver/i2c.h"
#include "esp_err.h"

#define SHT40_I2C_ADDR_DEFAULT 0x44

#define READ_WRITE_DELAY_MS 4

typedef enum {
    SHT40_CMD_MEASURE_HIGHREP               = 0xFD, 
    SHT40_CMD_MEASURE_MEDREP                = 0xF6, 
    SHT40_CMD_MEASURE_LOWREP                = 0xE0, 
    SHT40_CMD_READ_SERIAL                   = 0x89, 
    SHT40_CMD_SOFT_RESET                    = 0x94, 
    SHT40_CMD_ACTIVATE_HEATER_HIGH_LONG     = 0x39, 
    SHT40_CMD_ACTIVATE_HEATER_HIGH_SHORT    = 0x32, 
    SHT40_CMD_ACTIVATE_HEATER_LOW_LONG      = 0x1E, 
    SHT40_CMD_ACTIVATE_HEATER_LOW_SHORT     = 0x15  
} sht40_cmd_t;

typedef struct {
    i2c_port_t i2c_port;  
    uint8_t i2c_addr;     
} sht40_t;

esp_err_t sht40_init(sht40_t *dev, i2c_port_t i2c_port, uint8_t addr);

esp_err_t sht40_reset(sht40_t *dev);

esp_err_t sht40_read_temp_humidity(sht40_t *dev, float *temperature, float *humidity);

esp_err_t sht40_read_serial(sht40_t *dev, uint32_t *serial);

esp_err_t sht40_activate_heater(sht40_t *dev);

static esp_err_t sht40_send_cmd(sht40_t *dev, uint16_t cmd);
```


