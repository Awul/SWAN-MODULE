

# File led\_strip\_rmt\_dev.c



[**FileList**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**managed\_components**](dir_f14b78939adc8414aa21d6af988468d0.md) **>** [**espressif\_\_led\_strip**](dir_d0251c514b1be4d4f41659a309ca9490.md) **>** [**src**](dir_163002825b6da09af3d0cb3d07e787f0.md) **>** [**led\_strip\_rmt\_dev.c**](led__strip__rmt__dev_8c.md)

[Go to the source code of this file](led__strip__rmt__dev_8c_source.md)



* `#include <stdlib.h>`
* `#include <string.h>`
* `#include <sys/cdefs.h>`
* `#include "esp_log.h"`
* `#include "esp_check.h"`
* `#include "driver/rmt_tx.h"`
* `#include "led_strip.h"`
* `#include "led_strip_interface.h"`
* `#include "led_strip_rmt_encoder.h"`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**led\_strip\_rmt\_obj**](structled__strip__rmt__obj.md) <br> |








## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const char \* | [**TAG**](#variable-tag)   = `"led\_strip\_rmt"`<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**led\_strip\_new\_rmt\_device**](#function-led_strip_new_rmt_device) (const [**led\_strip\_config\_t**](structled__strip__config__t.md) \* led\_config, const [**led\_strip\_rmt\_config\_t**](structled__strip__rmt__config__t.md) \* rmt\_config, led\_strip\_handle\_t \* ret\_strip) <br>_Create LED strip based on RMT TX channel._  |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**led\_strip\_rmt\_clear**](#function-led_strip_rmt_clear) ([**led\_strip\_t**](structled__strip__t.md) \* strip) <br> |
|  esp\_err\_t | [**led\_strip\_rmt\_del**](#function-led_strip_rmt_del) ([**led\_strip\_t**](structled__strip__t.md) \* strip) <br> |
|  esp\_err\_t | [**led\_strip\_rmt\_refresh**](#function-led_strip_rmt_refresh) ([**led\_strip\_t**](structled__strip__t.md) \* strip) <br> |
|  esp\_err\_t | [**led\_strip\_rmt\_set\_pixel**](#function-led_strip_rmt_set_pixel) ([**led\_strip\_t**](structled__strip__t.md) \* strip, uint32\_t index, uint32\_t red, uint32\_t green, uint32\_t blue) <br> |
|  esp\_err\_t | [**led\_strip\_rmt\_set\_pixel\_rgbw**](#function-led_strip_rmt_set_pixel_rgbw) ([**led\_strip\_t**](structled__strip__t.md) \* strip, uint32\_t index, uint32\_t red, uint32\_t green, uint32\_t blue, uint32\_t white) <br> |

























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**LED\_STRIP\_RMT\_DEFAULT\_MEM\_BLOCK\_SYMBOLS**](led__strip__rmt__dev_8c.md#define-led_strip_rmt_default_mem_block_symbols)  `48`<br> |
| define  | [**LED\_STRIP\_RMT\_DEFAULT\_RESOLUTION**](led__strip__rmt__dev_8c.md#define-led_strip_rmt_default_resolution)  `10000000`<br> |
| define  | [**LED\_STRIP\_RMT\_DEFAULT\_TRANS\_QUEUE\_SIZE**](led__strip__rmt__dev_8c.md#define-led_strip_rmt_default_trans_queue_size)  `4`<br> |

## Public Static Attributes Documentation




### variable TAG 

```C++
const char* TAG;
```




<hr>
## Public Functions Documentation




### function led\_strip\_new\_rmt\_device 

_Create LED strip based on RMT TX channel._ 
```C++
esp_err_t led_strip_new_rmt_device (
    const led_strip_config_t * led_config,
    const led_strip_rmt_config_t * rmt_config,
    led_strip_handle_t * ret_strip
) 
```





**Parameters:**


* `led_config` LED strip configuration 
* `rmt_config` RMT specific configuration 
* `ret_strip` Returned LED strip handle 



**Returns:**


* ESP\_OK: create LED strip handle successfully
* ESP\_ERR\_INVALID\_ARG: create LED strip handle failed because of invalid argument
* ESP\_ERR\_NO\_MEM: create LED strip handle failed because of out of memory
* ESP\_FAIL: create LED strip handle failed because some other error 







        

<hr>
## Public Static Functions Documentation




### function led\_strip\_rmt\_clear 

```C++
static esp_err_t led_strip_rmt_clear (
    led_strip_t * strip
) 
```




<hr>



### function led\_strip\_rmt\_del 

```C++
static esp_err_t led_strip_rmt_del (
    led_strip_t * strip
) 
```




<hr>



### function led\_strip\_rmt\_refresh 

```C++
static esp_err_t led_strip_rmt_refresh (
    led_strip_t * strip
) 
```




<hr>



### function led\_strip\_rmt\_set\_pixel 

```C++
static esp_err_t led_strip_rmt_set_pixel (
    led_strip_t * strip,
    uint32_t index,
    uint32_t red,
    uint32_t green,
    uint32_t blue
) 
```




<hr>



### function led\_strip\_rmt\_set\_pixel\_rgbw 

```C++
static esp_err_t led_strip_rmt_set_pixel_rgbw (
    led_strip_t * strip,
    uint32_t index,
    uint32_t red,
    uint32_t green,
    uint32_t blue,
    uint32_t white
) 
```




<hr>
## Macro Definition Documentation





### define LED\_STRIP\_RMT\_DEFAULT\_MEM\_BLOCK\_SYMBOLS 

```C++
#define LED_STRIP_RMT_DEFAULT_MEM_BLOCK_SYMBOLS `48`
```




<hr>



### define LED\_STRIP\_RMT\_DEFAULT\_RESOLUTION 

```C++
#define LED_STRIP_RMT_DEFAULT_RESOLUTION `10000000`
```




<hr>



### define LED\_STRIP\_RMT\_DEFAULT\_TRANS\_QUEUE\_SIZE 

```C++
#define LED_STRIP_RMT_DEFAULT_TRANS_QUEUE_SIZE `4`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/src/led_strip_rmt_dev.c`

