

# Struct led\_strip\_spi\_obj



[**ClassList**](annotated.md) **>** [**led\_strip\_spi\_obj**](structled__strip__spi__obj.md)


























## Public Attributes

| Type | Name |
| ---: | :--- |
|  [**led\_strip\_t**](structled__strip__t.md) | [**base**](#variable-base)  <br> |
|  uint8\_t | [**bytes\_per\_pixel**](#variable-bytes_per_pixel)  <br> |
|  [**led\_color\_component\_format\_t**](unionled__color__component__format__t.md) | [**component\_fmt**](#variable-component_fmt)  <br> |
|  uint8\_t | [**pixel\_buf**](#variable-pixel_buf)  <br> |
|  spi\_device\_handle\_t | [**spi\_device**](#variable-spi_device)  <br> |
|  spi\_host\_device\_t | [**spi\_host**](#variable-spi_host)  <br> |
|  uint32\_t | [**strip\_len**](#variable-strip_len)  <br> |












































## Public Attributes Documentation




### variable base 

```C++
led_strip_t led_strip_spi_obj::base;
```




<hr>



### variable bytes\_per\_pixel 

```C++
uint8_t led_strip_spi_obj::bytes_per_pixel;
```




<hr>



### variable component\_fmt 

```C++
led_color_component_format_t led_strip_spi_obj::component_fmt;
```




<hr>



### variable pixel\_buf 

```C++
uint8_t led_strip_spi_obj::pixel_buf[];
```




<hr>



### variable spi\_device 

```C++
spi_device_handle_t led_strip_spi_obj::spi_device;
```




<hr>



### variable spi\_host 

```C++
spi_host_device_t led_strip_spi_obj::spi_host;
```




<hr>



### variable strip\_len 

```C++
uint32_t led_strip_spi_obj::strip_len;
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/src/led_strip_spi_dev.c`

