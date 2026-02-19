

# File blink\_example\_main.c



[**FileList**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**main**](dir_d2e6f58d505f20cf0fabd2e05e91e83b.md) **>** [**blink\_example\_main.c**](blink__example__main_8c.md)

[Go to the source code of this file](blink__example__main_8c_source.md)



* `#include <stdio.h>`
* `#include "freertos/FreeRTOS.h"`
* `#include "freertos/task.h"`
* `#include "driver/i2c.h"`
* `#include "esp_err.h"`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**app\_main**](#function-app_main) (void) <br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  void | [**i2c\_probe\_veml7700**](#function-i2c_probe_veml7700) (void) <br> |
|  void | [**i2c\_scan**](#function-i2c_scan) (void) <br> |

























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**I2C\_FREQ**](blink__example__main_8c.md#define-i2c_freq)  `100000`<br> |
| define  | [**I2C\_PORT**](blink__example__main_8c.md#define-i2c_port)  `I2C\_NUM\_0`<br> |
| define  | [**I2C\_SCL**](blink__example__main_8c.md#define-i2c_scl)  `9`<br> |
| define  | [**I2C\_SDA**](blink__example__main_8c.md#define-i2c_sda)  `8`<br> |

## Public Functions Documentation




### function app\_main 

```C++
void app_main (
    void
) 
```




<hr>
## Public Static Functions Documentation




### function i2c\_probe\_veml7700 

```C++
static void i2c_probe_veml7700 (
    void
) 
```




<hr>



### function i2c\_scan 

```C++
static void i2c_scan (
    void
) 
```




<hr>
## Macro Definition Documentation





### define I2C\_FREQ 

```C++
#define I2C_FREQ `100000`
```




<hr>



### define I2C\_PORT 

```C++
#define I2C_PORT `I2C_NUM_0`
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
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/main/blink_example_main.c`

