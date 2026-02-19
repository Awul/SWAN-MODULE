

# File i2c\_bus.h

[**File List**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**i2c\_bus**](dir_b27305f47d68ba65b41a21460fb415ed.md) **>** [**i2c\_bus.h**](i2c__bus_8h.md)

[Go to the documentation of this file](i2c__bus_8h.md)


```C++


#pragma once
#include "esp_err.h"
#include "driver/i2c.h"

#define I2C_PORT I2C_NUM_0

#define I2C_SDA  8       // Default SDA pin
#define I2C_SCL  9       // Default SCL pin
#define I2C_FREQ 100000  // Default I2C frequency (100 kHz)

esp_err_t i2c_bus_init(void);

void i2c_bus_status(void);

void i2c_scan(void);
 // end of I2C_BUS group
```


