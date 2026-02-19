

# File led\_strip.h



[**FileList**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**managed\_components**](dir_f14b78939adc8414aa21d6af988468d0.md) **>** [**espressif\_\_led\_strip**](dir_d0251c514b1be4d4f41659a309ca9490.md) **>** [**include**](dir_9798d67173f3cb6f216c73c0b3ea0b46.md) **>** [**led\_strip.h**](led__strip_8h.md)

[Go to the source code of this file](led__strip_8h_source.md)



* `#include <stdint.h>`
* `#include "esp_err.h"`
* `#include "led_strip_rmt.h"`
* `#include "led_strip_spi.h"`





































## Public Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**led\_strip\_clear**](#function-led_strip_clear) (led\_strip\_handle\_t strip) <br>_Clear LED strip (turn off all LEDs)._  |
|  esp\_err\_t | [**led\_strip\_del**](#function-led_strip_del) (led\_strip\_handle\_t strip) <br>_Free LED strip resources._  |
|  esp\_err\_t | [**led\_strip\_refresh**](#function-led_strip_refresh) (led\_strip\_handle\_t strip) <br>_Refresh memory colors to LEDs._  |
|  esp\_err\_t | [**led\_strip\_set\_pixel**](#function-led_strip_set_pixel) (led\_strip\_handle\_t strip, uint32\_t index, uint32\_t red, uint32\_t green, uint32\_t blue) <br>_Set RGB for a specific pixel._  |
|  esp\_err\_t | [**led\_strip\_set\_pixel\_hsv**](#function-led_strip_set_pixel_hsv) (led\_strip\_handle\_t strip, uint32\_t index, uint16\_t hue, uint8\_t saturation, uint8\_t value) <br>_Set HSV for a specific pixel._  |
|  esp\_err\_t | [**led\_strip\_set\_pixel\_hsv\_16**](#function-led_strip_set_pixel_hsv_16) (led\_strip\_handle\_t strip, uint32\_t index, uint16\_t hue, uint16\_t saturation, uint16\_t value) <br>_Set HSV for a specific pixel in 16-bit resolution._  |
|  esp\_err\_t | [**led\_strip\_set\_pixel\_rgbw**](#function-led_strip_set_pixel_rgbw) (led\_strip\_handle\_t strip, uint32\_t index, uint32\_t red, uint32\_t green, uint32\_t blue, uint32\_t white) <br>_Set RGBW for a specific pixel._  |




























## Public Functions Documentation




### function led\_strip\_clear 

_Clear LED strip (turn off all LEDs)._ 
```C++
esp_err_t led_strip_clear (
    led_strip_handle_t strip
) 
```





**Parameters:**


* `strip` LED strip



**Returns:**


* ESP\_OK: Clear LEDs successfully
* ESP\_FAIL: Clear LEDs failed because some other error occurred 







        

<hr>



### function led\_strip\_del 

_Free LED strip resources._ 
```C++
esp_err_t led_strip_del (
    led_strip_handle_t strip
) 
```





**Parameters:**


* `strip` LED strip



**Returns:**


* ESP\_OK: Free resources successfully
* ESP\_FAIL: Free resources failed because error occurred 







        

<hr>



### function led\_strip\_refresh 

_Refresh memory colors to LEDs._ 
```C++
esp_err_t led_strip_refresh (
    led_strip_handle_t strip
) 
```





**Parameters:**


* `strip` LED strip



**Returns:**


* ESP\_OK: Refresh successfully
* ESP\_FAIL: Refresh failed because some other error occurred






**Note:**

: After updating the LED colors in the memory, a following invocation of this API is needed to flush colors to strip. 





        

<hr>



### function led\_strip\_set\_pixel 

_Set RGB for a specific pixel._ 
```C++
esp_err_t led_strip_set_pixel (
    led_strip_handle_t strip,
    uint32_t index,
    uint32_t red,
    uint32_t green,
    uint32_t blue
) 
```





**Parameters:**


* `strip` LED strip 
* `index` index of pixel to set 
* `red` red part of color 
* `green` green part of color 
* `blue` blue part of color



**Returns:**


* ESP\_OK: Set RGB for a specific pixel successfully
* ESP\_ERR\_INVALID\_ARG: Set RGB for a specific pixel failed because of invalid parameters
* ESP\_FAIL: Set RGB for a specific pixel failed because other error occurred 







        

<hr>



### function led\_strip\_set\_pixel\_hsv 

_Set HSV for a specific pixel._ 
```C++
esp_err_t led_strip_set_pixel_hsv (
    led_strip_handle_t strip,
    uint32_t index,
    uint16_t hue,
    uint8_t saturation,
    uint8_t value
) 
```





**Parameters:**


* `strip` LED strip 
* `index` index of pixel to set 
* `hue` hue part of color (0 - 360) 
* `saturation` saturation part of color (0 - 255, rescaled from 0 - 1. e.g. saturation = 0.5, rescaled to 127) 
* `value` value part of color (0 - 255, rescaled from 0 - 1. e.g. value = 0.5, rescaled to 127)



**Returns:**


* ESP\_OK: Set HSV color for a specific pixel successfully
* ESP\_ERR\_INVALID\_ARG: Set HSV color for a specific pixel failed because of an invalid argument
* ESP\_FAIL: Set HSV color for a specific pixel failed because other error occurred 







        

<hr>



### function led\_strip\_set\_pixel\_hsv\_16 

_Set HSV for a specific pixel in 16-bit resolution._ 
```C++
esp_err_t led_strip_set_pixel_hsv_16 (
    led_strip_handle_t strip,
    uint32_t index,
    uint16_t hue,
    uint16_t saturation,
    uint16_t value
) 
```





**Parameters:**


* `strip` LED strip 
* `index` index of pixel to set 
* `hue` hue part of color (0 - 360) 
* `saturation` saturation part of color (0 - 65535, rescaled from 0 - 1. e.g. saturation = 0.5, rescaled to 32767) 
* `value` value part of color (0 - 65535, rescaled from 0 - 1. e.g. value = 0.5, rescaled to 32767)



**Returns:**


* ESP\_OK: Set HSV color for a specific pixel successfully
* ESP\_ERR\_INVALID\_ARG: Set HSV color for a specific pixel failed because of an invalid argument
* ESP\_FAIL: Set HSV color for a specific pixel failed because other error occurred 







        

<hr>



### function led\_strip\_set\_pixel\_rgbw 

_Set RGBW for a specific pixel._ 
```C++
esp_err_t led_strip_set_pixel_rgbw (
    led_strip_handle_t strip,
    uint32_t index,
    uint32_t red,
    uint32_t green,
    uint32_t blue,
    uint32_t white
) 
```





**Note:**

Only call this function if your led strip does have the white component (e.g. SK6812-RGBW) 




**Note:**

Also see `led_strip_set_pixel` if you only want to specify the RGB part of the color and bypass the white component




**Parameters:**


* `strip` LED strip 
* `index` index of pixel to set 
* `red` red part of color 
* `green` green part of color 
* `blue` blue part of color 
* `white` separate white component



**Returns:**


* ESP\_OK: Set RGBW color for a specific pixel successfully
* ESP\_ERR\_INVALID\_ARG: Set RGBW color for a specific pixel failed because of an invalid argument
* ESP\_FAIL: Set RGBW color for a specific pixel failed because other error occurred 







        

<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/include/led_strip.h`

