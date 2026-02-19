

# File led\_strip\_spi.h



[**FileList**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**managed\_components**](dir_f14b78939adc8414aa21d6af988468d0.md) **>** [**espressif\_\_led\_strip**](dir_d0251c514b1be4d4f41659a309ca9490.md) **>** [**include**](dir_9798d67173f3cb6f216c73c0b3ea0b46.md) **>** [**led\_strip\_spi.h**](led__strip__spi_8h.md)

[Go to the source code of this file](led__strip__spi_8h_source.md)



* `#include <stdint.h>`
* `#include "esp_err.h"`
* `#include "driver/spi_master.h"`
* `#include "led_strip_types.h"`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**led\_strip\_spi\_config\_t**](structled__strip__spi__config__t.md) <br>_LED Strip SPI specific configuration._  |






















## Public Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**led\_strip\_new\_spi\_device**](#function-led_strip_new_spi_device) (const [**led\_strip\_config\_t**](structled__strip__config__t.md) \* led\_config, const [**led\_strip\_spi\_config\_t**](structled__strip__spi__config__t.md) \* spi\_config, led\_strip\_handle\_t \* ret\_strip) <br>_Create LED strip based on SPI MOSI channel._  |




























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

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/include/led_strip_spi.h`

