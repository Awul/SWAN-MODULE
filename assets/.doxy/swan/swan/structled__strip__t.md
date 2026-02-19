

# Struct led\_strip\_t



[**ClassList**](annotated.md) **>** [**led\_strip\_t**](structled__strip__t.md)



_LED strip interface definition._ 

* `#include <led_strip_interface.h>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  esp\_err\_t(\* | [**clear**](#variable-clear)  <br>_Clear LED strip (turn off all LEDs)._  |
|  esp\_err\_t(\* | [**del**](#variable-del)  <br>_Free LED strip resources._  |
|  esp\_err\_t(\* | [**refresh**](#variable-refresh)  <br>_Refresh memory colors to LEDs._  |
|  esp\_err\_t(\* | [**set\_pixel**](#variable-set_pixel)  <br>_Set RGB for a specific pixel._  |
|  esp\_err\_t(\* | [**set\_pixel\_rgbw**](#variable-set_pixel_rgbw)  <br>_Set RGBW for a specific pixel. Similar to_ `set_pixel` _but also set the white component._ |












































## Public Attributes Documentation




### variable clear 

_Clear LED strip (turn off all LEDs)._ 
```C++
esp_err_t(* led_strip_t::clear) (led_strip_t *strip);
```





**Parameters:**


* `strip` LED strip 
* `timeout_ms` timeout value for clearing task



**Returns:**


* ESP\_OK: Clear LEDs successfully
* ESP\_FAIL: Clear LEDs failed because some other error occurred 







        

<hr>



### variable del 

_Free LED strip resources._ 
```C++
esp_err_t(* led_strip_t::del) (led_strip_t *strip);
```





**Parameters:**


* `strip` LED strip



**Returns:**


* ESP\_OK: Free resources successfully
* ESP\_FAIL: Free resources failed because error occurred 







        

<hr>



### variable refresh 

_Refresh memory colors to LEDs._ 
```C++
esp_err_t(* led_strip_t::refresh) (led_strip_t *strip);
```





**Parameters:**


* `strip` LED strip 
* `timeout_ms` timeout value for refreshing task



**Returns:**


* ESP\_OK: Refresh successfully
* ESP\_FAIL: Refresh failed because some other error occurred






**Note:**

: After updating the LED colors in the memory, a following invocation of this API is needed to flush colors to strip. 





        

<hr>



### variable set\_pixel 

_Set RGB for a specific pixel._ 
```C++
esp_err_t(* led_strip_t::set_pixel) (led_strip_t *strip, uint32_t index, uint32_t red, uint32_t green, uint32_t blue);
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



### variable set\_pixel\_rgbw 

_Set RGBW for a specific pixel. Similar to_ `set_pixel` _but also set the white component._
```C++
esp_err_t(* led_strip_t::set_pixel_rgbw) (led_strip_t *strip, uint32_t index, uint32_t red, uint32_t green, uint32_t blue, uint32_t white);
```





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
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/interface/led_strip_interface.h`

