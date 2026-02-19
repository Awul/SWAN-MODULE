

# File led\_strip\_rmt\_ws2812\_main.c



[**FileList**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**managed\_components**](dir_f14b78939adc8414aa21d6af988468d0.md) **>** [**espressif\_\_led\_strip**](dir_d0251c514b1be4d4f41659a309ca9490.md) **>** [**examples**](dir_b29a9b692691c0bf29bb1cf5ebdcb579.md) **>** [**led\_strip\_rmt\_ws2812**](dir_84edcc5c633d4d1e3c0a9855e1a92751.md) **>** [**main**](dir_21d6b06af47cd3baa7cd0dc7767b5b5c.md) **>** [**led\_strip\_rmt\_ws2812\_main.c**](led__strip__rmt__ws2812__main_8c.md)

[Go to the source code of this file](led__strip__rmt__ws2812__main_8c_source.md)



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
| define  | [**LED\_STRIP\_GPIO\_PIN**](led__strip__rmt__ws2812__main_8c.md#define-led_strip_gpio_pin)  `2`<br> |
| define  | [**LED\_STRIP\_LED\_COUNT**](led__strip__rmt__ws2812__main_8c.md#define-led_strip_led_count)  `24`<br> |
| define  | [**LED\_STRIP\_MEMORY\_BLOCK\_WORDS**](led__strip__rmt__ws2812__main_8c.md#define-led_strip_memory_block_words)  `0`<br> |
| define  | [**LED\_STRIP\_RMT\_RES\_HZ**](led__strip__rmt__ws2812__main_8c.md#define-led_strip_rmt_res_hz)  `(10 \* 1000 \* 1000)`<br> |
| define  | [**LED\_STRIP\_USE\_DMA**](led__strip__rmt__ws2812__main_8c.md#define-led_strip_use_dma)  `0`<br> |

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



### define LED\_STRIP\_MEMORY\_BLOCK\_WORDS 

```C++
#define LED_STRIP_MEMORY_BLOCK_WORDS `0`
```




<hr>



### define LED\_STRIP\_RMT\_RES\_HZ 

```C++
#define LED_STRIP_RMT_RES_HZ `(10 * 1000 * 1000)`
```




<hr>



### define LED\_STRIP\_USE\_DMA 

```C++
#define LED_STRIP_USE_DMA `0`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/examples/led_strip_rmt_ws2812/main/led_strip_rmt_ws2812_main.c`

