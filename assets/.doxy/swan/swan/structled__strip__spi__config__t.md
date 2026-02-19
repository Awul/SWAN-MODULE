

# Struct led\_strip\_spi\_config\_t



[**ClassList**](annotated.md) **>** [**led\_strip\_spi\_config\_t**](structled__strip__spi__config__t.md)



_LED Strip SPI specific configuration._ 

* `#include <led_strip_spi.h>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  spi\_clock\_source\_t | [**clk\_src**](#variable-clk_src)  <br> |
|  struct led\_strip\_spi\_config\_t::@053223203114067335153245354105076245251304020036 | [**flags**](#variable-flags)  <br> |
|  spi\_host\_device\_t | [**spi\_bus**](#variable-spi_bus)  <br> |
|  uint32\_t | [**with\_dma**](#variable-with_dma)  <br> |












































## Public Attributes Documentation




### variable clk\_src 

```C++
spi_clock_source_t led_strip_spi_config_t::clk_src;
```



SPI clock source 


        

<hr>



### variable flags 

```C++
struct led_strip_spi_config_t::@053223203114067335153245354105076245251304020036 led_strip_spi_config_t::flags;
```



Extra driver flags 


        

<hr>



### variable spi\_bus 

```C++
spi_host_device_t led_strip_spi_config_t::spi_bus;
```



SPI bus ID. Which buses are available depends on the specific chip 


        

<hr>



### variable with\_dma 

```C++
uint32_t led_strip_spi_config_t::with_dma;
```



Use DMA to transmit data 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/include/led_strip_spi.h`

