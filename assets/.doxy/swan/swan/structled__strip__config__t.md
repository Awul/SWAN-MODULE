

# Struct led\_strip\_config\_t



[**ClassList**](annotated.md) **>** [**led\_strip\_config\_t**](structled__strip__config__t.md)



_LED Strip common configurations The common configurations are not specific to any backend peripheral._ 

* `#include <led_strip_types.h>`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**led\_strip\_extra\_flags**](structled__strip__config__t_1_1led__strip__extra__flags.md) <br> |






## Public Attributes

| Type | Name |
| ---: | :--- |
|  [**led\_color\_component\_format\_t**](unionled__color__component__format__t.md) | [**color\_component\_format**](#variable-color_component_format)  <br> |
|  struct [**led\_strip\_config\_t::led\_strip\_extra\_flags**](structled__strip__config__t_1_1led__strip__extra__flags.md) | [**flags**](#variable-flags)  <br> |
|  led\_model\_t | [**led\_model**](#variable-led_model)  <br> |
|  uint32\_t | [**max\_leds**](#variable-max_leds)  <br> |
|  int | [**strip\_gpio\_num**](#variable-strip_gpio_num)  <br> |












































## Public Attributes Documentation




### variable color\_component\_format 

```C++
led_color_component_format_t led_strip_config_t::color_component_format;
```



Specifies the order of color components in each pixel. Use helper macros like `LED_STRIP_COLOR_COMPONENT_FMT_GRB` to set the format LED strip extra driver flags 


        

<hr>



### variable flags 

```C++
struct led_strip_config_t::led_strip_extra_flags led_strip_config_t::flags;
```



Extra driver flags 


        

<hr>



### variable led\_model 

```C++
led_model_t led_strip_config_t::led_model;
```



Specifies the LED strip model (e.g., WS2812, SK6812) 


        

<hr>



### variable max\_leds 

```C++
uint32_t led_strip_config_t::max_leds;
```



Maximum number of LEDs that can be controlled in a single strip 


        

<hr>



### variable strip\_gpio\_num 

```C++
int led_strip_config_t::strip_gpio_num;
```



GPIO number that used by LED strip 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/include/led_strip_types.h`

