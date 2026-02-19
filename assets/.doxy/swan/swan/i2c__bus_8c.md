

# File i2c\_bus.c



[**FileList**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**i2c\_bus**](dir_b27305f47d68ba65b41a21460fb415ed.md) **>** [**i2c\_bus.c**](i2c__bus_8c.md)

[Go to the source code of this file](i2c__bus_8c_source.md)



* `#include "i2c_bus.h"`
* `#include "freertos/semphr.h"`
* `#include "esp_log.h"`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const char \* | [**TAG**](#variable-tag)   = `"I2C\_BUS"`<br> |
|  SemaphoreHandle\_t | [**i2c\_mutex**](#variable-i2c_mutex)   = `NULL`<br> |










































## Public Static Attributes Documentation




### variable TAG 

```C++
const char* TAG;
```




<hr>



### variable i2c\_mutex 

```C++
SemaphoreHandle_t i2c_mutex;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/SWAN-MODULE/components/i2c_bus/i2c_bus.c`

