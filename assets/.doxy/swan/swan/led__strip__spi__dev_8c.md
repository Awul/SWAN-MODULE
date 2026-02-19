

# File led\_strip\_spi\_dev.c



[**FileList**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**managed\_components**](dir_f14b78939adc8414aa21d6af988468d0.md) **>** [**espressif\_\_led\_strip**](dir_d0251c514b1be4d4f41659a309ca9490.md) **>** [**src**](dir_163002825b6da09af3d0cb3d07e787f0.md) **>** [**led\_strip\_spi\_dev.c**](led__strip__spi__dev_8c.md)

[Go to the source code of this file](led__strip__spi__dev_8c_source.md)



* `#include <stdlib.h>`
* `#include <string.h>`
* `#include <sys/cdefs.h>`
* `#include "esp_log.h"`
* `#include "esp_check.h"`
* `#include "esp_rom_gpio.h"`
* `#include "soc/spi_periph.h"`
* `#include "led_strip.h"`
* `#include "led_strip_interface.h"`
* `#include "esp_heap_caps.h"`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**led\_strip\_spi\_obj**](structled__strip__spi__obj.md) <br> |








## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const char \* | [**TAG**](#variable-tag)   = `"led\_strip\_spi"`<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**led\_strip\_new\_spi\_device**](#function-led_strip_new_spi_device) (const [**led\_strip\_config\_t**](structled__strip__config__t.md) \* led\_config, const [**led\_strip\_spi\_config\_t**](structled__strip__spi__config__t.md) \* spi\_config, led\_strip\_handle\_t \* ret\_strip) <br>_Create LED strip based on SPI MOSI channel._  |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  void | [**\_\_led\_strip\_spi\_bit**](#function-__led_strip_spi_bit) (uint8\_t data, uint8\_t \* buf) <br> |
|  esp\_err\_t | [**led\_strip\_spi\_clear**](#function-led_strip_spi_clear) ([**led\_strip\_t**](structled__strip__t.md) \* strip) <br> |
|  esp\_err\_t | [**led\_strip\_spi\_del**](#function-led_strip_spi_del) ([**led\_strip\_t**](structled__strip__t.md) \* strip) <br> |
|  esp\_err\_t | [**led\_strip\_spi\_refresh**](#function-led_strip_spi_refresh) ([**led\_strip\_t**](structled__strip__t.md) \* strip) <br> |
|  esp\_err\_t | [**led\_strip\_spi\_set\_pixel**](#function-led_strip_spi_set_pixel) ([**led\_strip\_t**](structled__strip__t.md) \* strip, uint32\_t index, uint32\_t red, uint32\_t green, uint32\_t blue) <br> |
|  esp\_err\_t | [**led\_strip\_spi\_set\_pixel\_rgbw**](#function-led_strip_spi_set_pixel_rgbw) ([**led\_strip\_t**](structled__strip__t.md) \* strip, uint32\_t index, uint32\_t red, uint32\_t green, uint32\_t blue, uint32\_t white) <br> |

























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**LED\_STRIP\_SPI\_DEFAULT\_RESOLUTION**](led__strip__spi__dev_8c.md#define-led_strip_spi_default_resolution)  `(2.5 \* 1000 \* 1000)`<br> |
| define  | [**LED\_STRIP\_SPI\_DEFAULT\_TRANS\_QUEUE\_SIZE**](led__strip__spi__dev_8c.md#define-led_strip_spi_default_trans_queue_size)  `4`<br> |
| define  | [**SPI\_BITS\_PER\_COLOR\_BYTE**](led__strip__spi__dev_8c.md#define-spi_bits_per_color_byte)  `(SPI\_BYTES\_PER\_COLOR\_BYTE \* 8)`<br> |
| define  | [**SPI\_BYTES\_PER\_COLOR\_BYTE**](led__strip__spi__dev_8c.md#define-spi_bytes_per_color_byte)  `3`<br> |

## Public Static Attributes Documentation




### variable TAG 

```C++
const char* TAG;
```




<hr>
## Public Functions Documentation




### function led\_strip\_new\_spi\_device 

_Create LED strip based on SPI MOSI channel._ 
```C++
esp_err_t led_strip_new_spi_device (
    const led_strip_config_t * led_config,
    const led_strip_spi_config_t * spi_config,
    led_strip_handle_t * ret_strip
) 
```





**Note:**

Although only the MOSI line is used for generating the signal, the whole SPI bus can't be used for other purposes.




**Parameters:**


* `led_config` LED strip configuration 
* `spi_config` SPI specific configuration 
* `ret_strip` Returned LED strip handle 



**Returns:**


* ESP\_OK: create LED strip handle successfully
* ESP\_ERR\_INVALID\_ARG: create LED strip handle failed because of invalid argument
* ESP\_ERR\_NOT\_SUPPORTED: create LED strip handle failed because of unsupported configuration
* ESP\_ERR\_NO\_MEM: create LED strip handle failed because of out of memory
* ESP\_FAIL: create LED strip handle failed because some other error 







        

<hr>
## Public Static Functions Documentation




### function \_\_led\_strip\_spi\_bit 

```C++
static void __led_strip_spi_bit (
    uint8_t data,
    uint8_t * buf
) 
```




<hr>



### function led\_strip\_spi\_clear 

```C++
static esp_err_t led_strip_spi_clear (
    led_strip_t * strip
) 
```




<hr>



### function led\_strip\_spi\_del 

```C++
static esp_err_t led_strip_spi_del (
    led_strip_t * strip
) 
```




<hr>



### function led\_strip\_spi\_refresh 

```C++
static esp_err_t led_strip_spi_refresh (
    led_strip_t * strip
) 
```




<hr>



### function led\_strip\_spi\_set\_pixel 

```C++
static esp_err_t led_strip_spi_set_pixel (
    led_strip_t * strip,
    uint32_t index,
    uint32_t red,
    uint32_t green,
    uint32_t blue
) 
```




<hr>



### function led\_strip\_spi\_set\_pixel\_rgbw 

```C++
static esp_err_t led_strip_spi_set_pixel_rgbw (
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





### define LED\_STRIP\_SPI\_DEFAULT\_RESOLUTION 

```C++
#define LED_STRIP_SPI_DEFAULT_RESOLUTION `(2.5 * 1000 * 1000)`
```




<hr>



### define LED\_STRIP\_SPI\_DEFAULT\_TRANS\_QUEUE\_SIZE 

```C++
#define LED_STRIP_SPI_DEFAULT_TRANS_QUEUE_SIZE `4`
```




<hr>



### define SPI\_BITS\_PER\_COLOR\_BYTE 

```C++
#define SPI_BITS_PER_COLOR_BYTE `(SPI_BYTES_PER_COLOR_BYTE * 8)`
```




<hr>



### define SPI\_BYTES\_PER\_COLOR\_BYTE 

```C++
#define SPI_BYTES_PER_COLOR_BYTE `3`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/src/led_strip_spi_dev.c`

