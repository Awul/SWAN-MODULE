

# File i2ctools\_example\_main.c



[**FileList**](files.md) **>** [**i2c\_tools**](dir_8b4e5b8bf912f4cf55ac17b5fb8ec414.md) **>** [**main**](dir_3218ba971dba91160485f06c6137239b.md) **>** [**i2ctools\_example\_main.c**](i2ctools__example__main_8c.md)

[Go to the source code of this file](i2ctools__example__main_8c_source.md)



* `#include <stdio.h>`
* `#include <string.h>`
* `#include "sdkconfig.h"`
* `#include "esp_log.h"`
* `#include "esp_console.h"`
* `#include "esp_vfs_fat.h"`
* `#include "cmd_system.h"`
* `#include "cmd_i2ctools.h"`
* `#include "driver/i2c_master.h"`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const char \* | [**TAG**](#variable-tag)   = `"i2c-tools"`<br> |
|  gpio\_num\_t | [**i2c\_gpio\_scl**](#variable-i2c_gpio_scl)   = `CONFIG\_EXAMPLE\_I2C\_MASTER\_SCL`<br> |
|  gpio\_num\_t | [**i2c\_gpio\_sda**](#variable-i2c_gpio_sda)   = `CONFIG\_EXAMPLE\_I2C\_MASTER\_SDA`<br> |
|  i2c\_port\_t | [**i2c\_port**](#variable-i2c_port)   = `I2C\_NUM\_0`<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**app\_main**](#function-app_main) (void) <br> |




























## Public Static Attributes Documentation




### variable TAG 

```C++
const char* TAG;
```




<hr>



### variable i2c\_gpio\_scl 

```C++
gpio_num_t i2c_gpio_scl;
```




<hr>



### variable i2c\_gpio\_sda 

```C++
gpio_num_t i2c_gpio_sda;
```




<hr>



### variable i2c\_port 

```C++
i2c_port_t i2c_port;
```




<hr>
## Public Functions Documentation




### function app\_main 

```C++
void app_main (
    void
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/i2c_tools/main/i2ctools_example_main.c`

