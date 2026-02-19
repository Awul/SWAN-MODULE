

# File veml7700.h

[**File List**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**veml7700**](dir_0150b187d0697ce476d48596f0c108de.md) **>** [**veml7700.h**](veml7700_8h.md)

[Go to the documentation of this file](veml7700_8h.md)


```C++


#pragma once

#include "i2c_bus.h"
#include "esp_err.h"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"



#define VEML7700_REG_ALS_CONF_0      0x00
#define VEML7700_REG_ALS_WH          0x01
#define VEML7700_REG_ALS_WL          0x02
#define VEML7700_REG_POWER_SAVING    0x03
#define VEML7700_REG_ALS             0x04
#define VEML7700_REG_WHITE           0x05
#define VEML7700_REG_ALS_INT         0x06
#define VEML7700_REG_ID              0x07

#define VEML7700_I2C_ADDR_DEFAULT    0x10

typedef struct {
    i2c_port_t i2c_port;   
    uint8_t    i2c_addr;   
} veml7700_t;

esp_err_t veml7700_init(veml7700_t *dev, i2c_port_t port);

esp_err_t veml7700_read_als(veml7700_t *dev, uint16_t *als);

esp_err_t veml7700_read_lux(veml7700_t *dev, float *lux);

float veml7700_responsivity(uint8_t it_bits);

float veml7700_gain_factor(uint8_t gain_bits);

void veml7700_print_registers(const veml7700_t *dev);

```


