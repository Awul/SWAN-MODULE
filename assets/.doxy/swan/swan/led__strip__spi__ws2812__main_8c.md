

# File led\_strip\_spi\_ws2812\_main.c



[**FileList**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**managed\_components**](dir_f14b78939adc8414aa21d6af988468d0.md) **>** [**espressif\_\_led\_strip**](dir_d0251c514b1be4d4f41659a309ca9490.md) **>** [**examples**](dir_b29a9b692691c0bf29bb1cf5ebdcb579.md) **>** [**led\_strip\_spi\_ws2812**](dir_590355ad36e3e70e7d5556411221244d.md) **>** [**main**](dir_d48da02055f114612ac4c1145b3b54ed.md) **>** [**led\_strip\_spi\_ws2812\_main.c**](led__strip__spi__ws2812__main_8c.md)

[Go to the source code of this file](led__strip__spi__ws2812__main_8c_source.md)



* `#include <stdio.h>`
* `#include "freertos/FreeRTOS.h"`
* `#include "freertos/task.h"`
* `#include "led_strip.h"`
* `#include "esp_log.h"`
* `#include "esp_err.h"`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const char \* | [**TAG**](#variable-tag)   = `"example"`<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**app\_main**](#function-app_main) (void) <br> |
|  led\_strip\_handle\_t | [**configure\_led**](#function-configure_led) (void) <br> |



























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**LED\_STRIP\_GPIO\_PIN**](led__strip__spi__ws2812__main_8c.md#define-led_strip_gpio_pin)  `2`<br> |
| define  | [**LED\_STRIP\_LED\_COUNT**](led__strip__spi__ws2812__main_8c.md#define-led_strip_led_count)  `24`<br> |

## Public Static Attributes Documentation




### variable TAG 

```C++
const char* TAG;
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



### function configure\_led 

```C++
led_strip_handle_t configure_led (
    void
) 
```




<hr>
## Macro Definition Documentation





### define LED\_STRIP\_GPIO\_PIN 

```C++
#define LED_STRIP_GPIO_PIN `2`
```




<hr>



### define LED\_STRIP\_LED\_COUNT 

```C++
#define LED_STRIP_LED_COUNT `24`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/examples/led_strip_spi_ws2812/main/led_strip_spi_ws2812_main.c`

