

# File i2c\_bus.h

[**File List**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**i2c\_bus**](dir_b27305f47d68ba65b41a21460fb415ed.md) **>** [**i2c\_bus.h**](i2c__bus_8h.md)

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


