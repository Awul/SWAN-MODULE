

# File sht40.c



[**FileList**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**sht40**](dir_180d7217a87f12caa6a5edfd7755cc1b.md) **>** [**sht40.c**](sht40_8c.md)

[Go to the source code of this file](sht40_8c_source.md)



* `#include "sht40.h"`
* `#include "driver/i2c.h"`
* `#include "esp_log.h"`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const char \* | [**TAG**](#variable-tag)   = `"SHT40"`<br> |
















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**sht40\_send\_cmd**](#function-sht40_send_cmd) ([**sht40\_t**](structsht40__t.md) \* dev, uint16\_t cmd) <br> |


























## Public Static Attributes Documentation




### variable TAG 

```C++
const char* TAG;
```




<hr>
## Public Static Functions Documentation




### function sht40\_send\_cmd 

```C++
static esp_err_t sht40_send_cmd (
    sht40_t * dev,
    uint16_t cmd
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/SWAN-MODULE/components/sht40/sht40.c`

