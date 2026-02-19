

# Struct led\_strip\_rmt\_config\_t



[**ClassList**](annotated.md) **>** [**led\_strip\_rmt\_config\_t**](structled__strip__rmt__config__t.md)



_LED Strip RMT specific configuration._ 

* `#include <led_strip_rmt.h>`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**led\_strip\_rmt\_extra\_config**](structled__strip__rmt__config__t_1_1led__strip__rmt__extra__config.md) <br> |






## Public Attributes

| Type | Name |
| ---: | :--- |
|  rmt\_clock\_source\_t | [**clk\_src**](#variable-clk_src)  <br> |
|  struct [**led\_strip\_rmt\_config\_t::led\_strip\_rmt\_extra\_config**](structled__strip__rmt__config__t_1_1led__strip__rmt__extra__config.md) | [**flags**](#variable-flags)  <br> |
|  size\_t | [**mem\_block\_symbols**](#variable-mem_block_symbols)  <br> |
|  uint32\_t | [**resolution\_hz**](#variable-resolution_hz)  <br> |












































## Public Attributes Documentation




### variable clk\_src 

```C++
rmt_clock_source_t led_strip_rmt_config_t::clk_src;
```



RMT clock source 


        

<hr>



### variable flags 

```C++
struct led_strip_rmt_config_t::led_strip_rmt_extra_config led_strip_rmt_config_t::flags;
```



Extra driver flags 


        

<hr>



### variable mem\_block\_symbols 

```C++
size_t led_strip_rmt_config_t::mem_block_symbols;
```



How many RMT symbols can one RMT channel hold at one time. Set to 0 will fallback to use the default size. Extra RMT specific driver flags 


        

<hr>



### variable resolution\_hz 

```C++
uint32_t led_strip_rmt_config_t::resolution_hz;
```



RMT tick resolution, if set to zero, a default resolution (10MHz) will be applied 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/include/led_strip_rmt.h`

