

# File main.c



[**FileList**](files.md) **>** [**main**](dir_5c982d53a68cdbcd421152b4020263a9.md) **>** [**main.c**](main_8c.md)

[Go to the source code of this file](main_8c_source.md)



* `#include <stdio.h>`
* `#include "freertos/FreeRTOS.h"`
* `#include "freertos/task.h"`
* `#include "esp_log.h"`
* `#include "esp_err.h"`
* `#include "i2c_bus.h"`
* `#include "veml7700.h"`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  [**veml7700\_t**](structveml7700__t.md) | [**veml\_sensor**](#variable-veml_sensor)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**app\_main**](#function-app_main) (void) <br> |
|  void | [**setup**](#function-setup) () <br> |



























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**TAG**](main_8c.md#define-tag)  `"MAIN"`<br> |

## Public Attributes Documentation




### variable veml\_sensor 

```C++
veml7700_t veml_sensor;
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



### function setup 

```C++
void setup () 
```




<hr>
## Macro Definition Documentation





### define TAG 

```C++
#define TAG `"MAIN"`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/SWAN-MODULE/main/main.c`

