

# File led\_strip\_rmt\_encoder.h



[**FileList**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**managed\_components**](dir_f14b78939adc8414aa21d6af988468d0.md) **>** [**espressif\_\_led\_strip**](dir_d0251c514b1be4d4f41659a309ca9490.md) **>** [**src**](dir_163002825b6da09af3d0cb3d07e787f0.md) **>** [**led\_strip\_rmt\_encoder.h**](led__strip__rmt__encoder_8h.md)

[Go to the source code of this file](led__strip__rmt__encoder_8h_source.md)



* `#include <stdint.h>`
* `#include "driver/rmt_encoder.h"`
* `#include "led_strip_types.h"`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**led\_strip\_encoder\_config\_t**](structled__strip__encoder__config__t.md) <br>_Type of led strip encoder configuration._  |






















## Public Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**rmt\_new\_led\_strip\_encoder**](#function-rmt_new_led_strip_encoder) (const [**led\_strip\_encoder\_config\_t**](structled__strip__encoder__config__t.md) \* config, rmt\_encoder\_handle\_t \* ret\_encoder) <br>_Create RMT encoder for encoding LED strip pixels into RMT symbols._  |




























## Public Functions Documentation




### function rmt\_new\_led\_strip\_encoder 

_Create RMT encoder for encoding LED strip pixels into RMT symbols._ 
```C++
esp_err_t rmt_new_led_strip_encoder (
    const led_strip_encoder_config_t * config,
    rmt_encoder_handle_t * ret_encoder
) 
```





**Parameters:**


* `config` Encoder configuration 
* `ret_encoder` Returned encoder handle 



**Returns:**


* ESP\_ERR\_INVALID\_ARG for any invalid arguments
* ESP\_ERR\_NO\_MEM out of memory when creating led strip encoder
* ESP\_OK if creating encoder successfully 







        

<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/src/led_strip_rmt_encoder.h`

