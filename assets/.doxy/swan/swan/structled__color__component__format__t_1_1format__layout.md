

# Struct led\_color\_component\_format\_t::format\_layout



[**ClassList**](annotated.md) **>** [**led\_color\_component\_format\_t**](unionled__color__component__format__t.md) **>** [**format\_layout**](structled__color__component__format__t_1_1format__layout.md)


























## Public Attributes

| Type | Name |
| ---: | :--- |
|  uint32\_t | [**b\_pos**](#variable-b_pos)  <br> |
|  uint32\_t | [**bytes\_per\_color**](#variable-bytes_per_color)  <br> |
|  uint32\_t | [**g\_pos**](#variable-g_pos)  <br> |
|  uint32\_t | [**num\_components**](#variable-num_components)  <br> |
|  uint32\_t | [**r\_pos**](#variable-r_pos)  <br> |
|  uint32\_t | [**reserved**](#variable-reserved)  <br> |
|  uint32\_t | [**w\_pos**](#variable-w_pos)  <br> |












































## Public Attributes Documentation




### variable b\_pos 

```C++
uint32_t led_color_component_format_t::format_layout::b_pos;
```



Position of the blue channel in the color order: 0~3 


        

<hr>



### variable bytes\_per\_color 

```C++
uint32_t led_color_component_format_t::format_layout::bytes_per_color;
```



Bytes per color component: 1 or 2. If set to 0, it will fallback to 1 


        

<hr>



### variable g\_pos 

```C++
uint32_t led_color_component_format_t::format_layout::g_pos;
```



Position of the green channel in the color order: 0~3 


        

<hr>



### variable num\_components 

```C++
uint32_t led_color_component_format_t::format_layout::num_components;
```



Number of color components per pixel: 3 or 4. If set to 0, it will fallback to 3 


        

<hr>



### variable r\_pos 

```C++
uint32_t led_color_component_format_t::format_layout::r_pos;
```



Position of the red channel in the color order: 0~3 


        

<hr>



### variable reserved 

```C++
uint32_t led_color_component_format_t::format_layout::reserved;
```



Reserved 


        

<hr>



### variable w\_pos 

```C++
uint32_t led_color_component_format_t::format_layout::w_pos;
```



Position of the white channel in the color order: 0~3 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/include/led_strip_types.h`

