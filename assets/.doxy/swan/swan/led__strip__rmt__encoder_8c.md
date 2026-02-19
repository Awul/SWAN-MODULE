

# File led\_strip\_rmt\_encoder.c



[**FileList**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**managed\_components**](dir_f14b78939adc8414aa21d6af988468d0.md) **>** [**espressif\_\_led\_strip**](dir_d0251c514b1be4d4f41659a309ca9490.md) **>** [**src**](dir_163002825b6da09af3d0cb3d07e787f0.md) **>** [**led\_strip\_rmt\_encoder.c**](led__strip__rmt__encoder_8c.md)

[Go to the source code of this file](led__strip__rmt__encoder_8c_source.md)



* `#include "sdkconfig.h"`
* `#include "esp_idf_version.h"`
* `#include "esp_check.h"`
* `#include "esp_attr.h"`
* `#include "led_strip_rmt_encoder.h"`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**rmt\_led\_strip\_encoder\_t**](structrmt__led__strip__encoder__t.md) <br> |








## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const char \* | [**TAG**](#variable-tag)   = `"led\_rmt\_encoder"`<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**rmt\_new\_led\_strip\_encoder**](#function-rmt_new_led_strip_encoder) (const [**led\_strip\_encoder\_config\_t**](structled__strip__encoder__config__t.md) \* config, rmt\_encoder\_handle\_t \* ret\_encoder) <br>_Create RMT encoder for encoding LED strip pixels into RMT symbols._  |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**rmt\_del\_led\_strip\_encoder**](#function-rmt_del_led_strip_encoder) (rmt\_encoder\_t \* encoder) <br> |
|  RMT\_ENCODER\_FUNC\_ATTR size\_t | [**rmt\_encode\_led\_strip**](#function-rmt_encode_led_strip) (rmt\_encoder\_t \* encoder, rmt\_channel\_handle\_t channel, const void \* primary\_data, size\_t data\_size, rmt\_encode\_state\_t \* ret\_state) <br> |
|  RMT\_ENCODER\_FUNC\_ATTR esp\_err\_t | [**rmt\_led\_strip\_encoder\_reset**](#function-rmt_led_strip_encoder_reset) (rmt\_encoder\_t \* encoder) <br> |


























## Public Static Attributes Documentation




### variable TAG 

```C++
const char* TAG;
```




<hr>
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
## Public Static Functions Documentation




### function rmt\_del\_led\_strip\_encoder 

```C++
static esp_err_t rmt_del_led_strip_encoder (
    rmt_encoder_t * encoder
) 
```




<hr>



### function rmt\_encode\_led\_strip 

```C++
static RMT_ENCODER_FUNC_ATTR size_t rmt_encode_led_strip (
    rmt_encoder_t * encoder,
    rmt_channel_handle_t channel,
    const void * primary_data,
    size_t data_size,
    rmt_encode_state_t * ret_state
) 
```




<hr>



### function rmt\_led\_strip\_encoder\_reset 

```C++
static RMT_ENCODER_FUNC_ATTR esp_err_t rmt_led_strip_encoder_reset (
    rmt_encoder_t * encoder
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/blink/managed_components/espressif__led_strip/src/led_strip_rmt_encoder.c`

