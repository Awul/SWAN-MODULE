

# File led\_strip\_types.h



[**FileList**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**managed\_components**](dir_f14b78939adc8414aa21d6af988468d0.md) **>** [**espressif\_\_led\_strip**](dir_d0251c514b1be4d4f41659a309ca9490.md) **>** [**include**](dir_9798d67173f3cb6f216c73c0b3ea0b46.md) **>** [**led\_strip\_types.h**](led__strip__types_8h.md)

[Go to the source code of this file](led__strip__types_8h_source.md)



* `#include <stdint.h>`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**format\_layout**](structled__color__component__format__t_1_1format__layout.md) <br> |
| struct | [**led\_strip\_config\_t**](structled__strip__config__t.md) <br>_LED Strip common configurations The common configurations are not specific to any backend peripheral._  |
| struct | [**led\_strip\_extra\_flags**](structled__strip__config__t_1_1led__strip__extra__flags.md) <br> |


## Public Types

| Type | Name |
| ---: | :--- |
| union  | [**led\_color\_component\_format\_t**](#union-led_color_component_format_t)  <br>_LED color component format._  |
| enum  | [**led\_model\_t**](#enum-led_model_t)  <br>_LED strip model._  |
| typedef struct [**led\_strip\_t**](structled__strip__t.md) \* | [**led\_strip\_handle\_t**](#typedef-led_strip_handle_t)  <br>_Type of LED strip handle._  |















































## Macros

| Type | Name |
| ---: | :--- |
| define  | [**LED\_STRIP\_COLOR\_COMPONENT\_FMT\_GRB**](led__strip__types_8h.md#define-led_strip_color_component_fmt_grb)  `([**led\_color\_component\_format\_t**](unionled__color__component__format__t.md)){.format = {.r\_pos = 1, .g\_pos = 0, .b\_pos = 2, .w\_pos = 3, .reserved = 0, .bytes\_per\_color = 1, .num\_components = 3}}`<br>_Helper macros to set the color component format._  |
| define  | [**LED\_STRIP\_COLOR\_COMPONENT\_FMT\_GRBW**](led__strip__types_8h.md#define-led_strip_color_component_fmt_grbw)  `([**led\_color\_component\_format\_t**](unionled__color__component__format__t.md)){.format = {.r\_pos = 1, .g\_pos = 0, .b\_pos = 2, .w\_pos = 3, .reserved = 0, .bytes\_per\_color = 1, .num\_components = 4}}`<br> |
| define  | [**LED\_STRIP\_COLOR\_COMPONENT\_FMT\_GRBW\_16**](led__strip__types_8h.md#define-led_strip_color_component_fmt_grbw_16)  `([**led\_color\_component\_format\_t**](unionled__color__component__format__t.md)){.format = {.r\_pos = 1, .g\_pos = 0, .b\_pos = 2, .w\_pos = 3, .reserved = 0, .bytes\_per\_color = 2, .num\_components = 4}}`<br> |
| define  | [**LED\_STRIP\_COLOR\_COMPONENT\_FMT\_GRB\_16**](led__strip__types_8h.md#define-led_strip_color_component_fmt_grb_16)  `([**led\_color\_component\_format\_t**](unionled__color__component__format__t.md)){.format = {.r\_pos = 1, .g\_pos = 0, .b\_pos = 2, .w\_pos = 3, .reserved = 0, .bytes\_per\_color = 2, .num\_components = 3}}`<br> |
| define  | [**LED\_STRIP\_COLOR\_COMPONENT\_FMT\_RGB**](led__strip__types_8h.md#define-led_strip_color_component_fmt_rgb)  `([**led\_color\_component\_format\_t**](unionled__color__component__format__t.md)){.format = {.r\_pos = 0, .g\_pos = 1, .b\_pos = 2, .w\_pos = 3, .reserved = 0, .bytes\_per\_color = 1, .num\_components = 3}}`<br> |
| define  | [**LED\_STRIP\_COLOR\_COMPONENT\_FMT\_RGBW**](led__strip__types_8h.md#define-led_strip_color_component_fmt_rgbw)  `([**led\_color\_component\_format\_t**](unionled__color__component__format__t.md)){.format = {.r\_pos = 0, .g\_pos = 1, .b\_pos = 2, .w\_pos = 3, .reserved = 0, .bytes\_per\_color = 1, .num\_components = 4}}`<br> |
| define  | [**LED\_STRIP\_COLOR\_COMPONENT\_FMT\_RGBW\_16**](led__strip__types_8h.md#define-led_strip_color_component_fmt_rgbw_16)  `([**led\_color\_component\_format\_t**](unionled__color__component__format__t.md)){.format = {.r\_pos = 0, .g\_pos = 1, .b\_pos = 2, .w\_pos = 3, .reserved = 0, .bytes\_per\_color = 2, .num\_components = 4}}`<br> |
| define  | [**LED\_STRIP\_COLOR\_COMPONENT\_FMT\_RGB\_16**](led__strip__types_8h.md#define-led_strip_color_component_fmt_rgb_16)  `([**led\_color\_component\_format\_t**](unionled__color__component__format__t.md)){.format = {.r\_pos = 0, .g\_pos = 1, .b\_pos = 2, .w\_pos = 3, .reserved = 0, .bytes\_per\_color = 2, .num\_components = 3}}`<br> |

## Public Types Documentation




### union led\_color\_component\_format\_t 

_LED color component format._ 
```C++

```





**Note:**

The format is used to specify the order of color components in each pixel, also the number of color components. 





    

<hr>



### enum led\_model\_t 

_LED strip model._ 
```C++
enum led_model_t {
    LED_MODEL_WS2812,
    LED_MODEL_SK6812,
    LED_MODEL_WS2811,
    LED_MODEL_WS2816,
    LED_MODEL_INVALID
};
```





**Note:**

Different led model may have different timing parameters, so we need to distinguish them. 





        

<hr>



### typedef led\_strip\_handle\_t 

_Type of LED strip handle._ 
```C++
typedef struct led_strip_t* led_strip_handle_t;
```




<hr>
## Macro Definition Documentation





### define LED\_STRIP\_COLOR\_COMPONENT\_FMT\_GRB 

_Helper macros to set the color component format._ 
```C++
#define LED_STRIP_COLOR_COMPONENT_FMT_GRB `( led_color_component_format_t ){.format = {.r_pos = 1, .g_pos = 0, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 1, .num_components = 3}}`
```




<hr>



### define LED\_STRIP\_COLOR\_COMPONENT\_FMT\_GRBW 

```C++
#define LED_STRIP_COLOR_COMPONENT_FMT_GRBW `( led_color_component_format_t ){.format = {.r_pos = 1, .g_pos = 0, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 1, .num_components = 4}}`
```




<hr>



### define LED\_STRIP\_COLOR\_COMPONENT\_FMT\_GRBW\_16 

```C++
#define LED_STRIP_COLOR_COMPONENT_FMT_GRBW_16 `( led_color_component_format_t ){.format = {.r_pos = 1, .g_pos = 0, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 2, .num_components = 4}}`
```




<hr>



### define LED\_STRIP\_COLOR\_COMPONENT\_FMT\_GRB\_16 

```C++
#define LED_STRIP_COLOR_COMPONENT_FMT_GRB_16 `( led_color_component_format_t ){.format = {.r_pos = 1, .g_pos = 0, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 2, .num_components = 3}}`
```




<hr>



### define LED\_STRIP\_COLOR\_COMPONENT\_FMT\_RGB 

```C++
#define LED_STRIP_COLOR_COMPONENT_FMT_RGB `( led_color_component_format_t ){.format = {.r_pos = 0, .g_pos = 1, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 1, .num_components = 3}}`
```




<hr>



### define LED\_STRIP\_COLOR\_COMPONENT\_FMT\_RGBW 

```C++
#define LED_STRIP_COLOR_COMPONENT_FMT_RGBW `( led_color_component_format_t ){.format = {.r_pos = 0, .g_pos = 1, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 1, .num_components = 4}}`
```




<hr>



### define LED\_STRIP\_COLOR\_COMPONENT\_FMT\_RGBW\_16 

```C++
#define LED_STRIP_COLOR_COMPONENT_FMT_RGBW_16 `( led_color_component_format_t ){.format = {.r_pos = 0, .g_pos = 1, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 2, .num_components = 4}}`
```




<hr>



### define LED\_STRIP\_COLOR\_COMPONENT\_FMT\_RGB\_16 

```C++
#define LED_STRIP_COLOR_COMPONENT_FMT_RGB_16 `( led_color_component_format_t ){.format = {.r_pos = 0, .g_pos = 1, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 2, .num_components = 3}}`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/include/led_strip_types.h`

