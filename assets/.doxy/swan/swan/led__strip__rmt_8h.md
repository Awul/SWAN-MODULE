

# File led\_strip\_rmt.h



[**FileList**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**managed\_components**](dir_f14b78939adc8414aa21d6af988468d0.md) **>** [**espressif\_\_led\_strip**](dir_d0251c514b1be4d4f41659a309ca9490.md) **>** [**include**](dir_9798d67173f3cb6f216c73c0b3ea0b46.md) **>** [**led\_strip\_rmt.h**](led__strip__rmt_8h.md)

[Go to the source code of this file](led__strip__rmt_8h_source.md)



* `#include <stdint.h>`
* `#include "esp_err.h"`
* `#include "led_strip_types.h"`
* `#include "esp_idf_version.h"`
* `#include "driver/rmt_types.h"`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**led\_strip\_rmt\_config\_t**](structled__strip__rmt__config__t.md) <br>_LED Strip RMT specific configuration._  |
| struct | [**led\_strip\_rmt\_extra\_config**](structled__strip__rmt__config__t_1_1led__strip__rmt__extra__config.md) <br> |






















## Public Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**led\_strip\_new\_rmt\_device**](#function-led_strip_new_rmt_device) (const [**led\_strip\_config\_t**](structled__strip__config__t.md) \* led\_config, const [**led\_strip\_rmt\_config\_t**](structled__strip__rmt__config__t.md) \* rmt\_config, led\_strip\_handle\_t \* ret\_strip) <br>_Create LED strip based on RMT TX channel._  |




























## Public Functions Documentation




### function led\_strip\_new\_rmt\_device 

_Create LED strip based on RMT TX channel._ 
```C++
esp_err_t led_strip_new_rmt_device (
    const led_strip_config_t * led_config,
    const led_strip_rmt_config_t * rmt_config,
    led_strip_handle_t * ret_strip
) 
```





**Parameters:**


* `led_config` LED strip configuration 
* `rmt_config` RMT specific configuration 
* `ret_strip` Returned LED strip handle 



**Returns:**


* ESP\_OK: create LED strip handle successfully
* ESP\_ERR\_INVALID\_ARG: create LED strip handle failed because of invalid argument
* ESP\_ERR\_NO\_MEM: create LED strip handle failed because of out of memory
* ESP\_FAIL: create LED strip handle failed because some other error 







        

<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/include/led_strip_rmt.h`

