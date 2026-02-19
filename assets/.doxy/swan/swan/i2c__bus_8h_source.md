

# File i2c\_bus.h

[**File List**](files.md) **>** [**components**](dir_09a931ae38154143140b5beb2823466c.md) **>** [**i2c\_bus**](dir_66d2e45a40d98921f58fab97258c3166.md) **>** [**i2c\_bus.h**](i2c__bus_8h.md)

[Go to the documentation of this file](i2c__bus_8h.md)


```C++


#pragma once
#include "esp_err.h"
#include "driver/i2c.h"

#define I2C_PORT I2C_NUM_0

esp_err_t i2c_bus_init(void);

esp_err_t i2c_bus_write_read(uint8_t addr,
                             uint8_t *write_buf, size_t write_len,
                             uint8_t *read_buf, size_t read_len,
                             TickType_t ticks_to_wait);

 // end of I2C_BUS group
```


