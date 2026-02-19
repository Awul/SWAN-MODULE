

# File i2c\_bus.c



[**FileList**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**i2c\_bus**](dir_b27305f47d68ba65b41a21460fb415ed.md) **>** [**i2c\_bus.c**](i2c__bus_8c.md)

[Go to the source code of this file](i2c__bus_8c_source.md)



* `#include "i2c_bus.h"`
* `#include "freertos/semphr.h"`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  SemaphoreHandle\_t | [**i2c\_mutex**](#variable-i2c_mutex)   = `NULL`<br> |









































## Macros

| Type | Name |
| ---: | :--- |
| define  | [**I2C\_FREQ**](i2c__bus_8c.md#define-i2c_freq)  `100000`<br> |
| define  | [**I2C\_SCL**](i2c__bus_8c.md#define-i2c_scl)  `9`<br> |
| define  | [**I2C\_SDA**](i2c__bus_8c.md#define-i2c_sda)  `8`<br> |

## Public Static Attributes Documentation




### variable i2c\_mutex 

```C++
SemaphoreHandle_t i2c_mutex;
```




<hr>
## Macro Definition Documentation





### define I2C\_FREQ 

```C++
#define I2C_FREQ `100000`
```




<hr>



### define I2C\_SCL 

```C++
#define I2C_SCL `9`
```




<hr>



### define I2C\_SDA 

```C++
#define I2C_SDA `8`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/SWAN-MODULE/components/i2c_bus/i2c_bus.c`

