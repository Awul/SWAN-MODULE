

# File i2s\_pdm\_rx.c



[**FileList**](files.md) **>** [**i2s\_pdm**](dir_a9d5f53e1a98f7a823b6664583338eef.md) **>** [**main**](dir_8b646def77c344b31338d8d065cc4f74.md) **>** [**i2s\_pdm\_rx.c**](i2s__pdm__rx_8c.md)

[Go to the source code of this file](i2s__pdm__rx_8c_source.md)



* `#include <stdint.h>`
* `#include <stdlib.h>`
* `#include "freertos/FreeRTOS.h"`
* `#include "freertos/task.h"`
* `#include "soc/soc_caps.h"`
* `#include "driver/i2s_pdm.h"`
* `#include "driver/gpio.h"`
* `#include "esp_err.h"`
* `#include "sdkconfig.h"`
* `#include "i2s_pdm_example.h"`
* `#include "i2s_example_pins.h"`
* `#include "esp_log.h"`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const char \* | [**TAG**](#variable-tag)   = `"i2s\_pdm\_rx"`<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**i2s\_example\_pdm\_rx\_task**](#function-i2s_example_pdm_rx_task) (void \* args) <br>_I2S PDM RX example task._  |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  i2s\_chan\_handle\_t | [**i2s\_example\_init\_pdm\_rx**](#function-i2s_example_init_pdm_rx) (void) <br> |

























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**EXAMPLE\_PDM\_RX\_CLK\_IO**](i2s__pdm__rx_8c.md#define-example_pdm_rx_clk_io)  `EXAMPLE\_I2S\_BCLK\_IO1`<br> |
| define  | [**EXAMPLE\_PDM\_RX\_DIN\_IO**](i2s__pdm__rx_8c.md#define-example_pdm_rx_din_io)  `EXAMPLE\_I2S\_DIN\_IO1`<br> |
| define  | [**EXAMPLE\_PDM\_RX\_FREQ\_HZ**](i2s__pdm__rx_8c.md#define-example_pdm_rx_freq_hz)  `2048000`<br> |

## Public Static Attributes Documentation




### variable TAG 

```C++
const char* TAG;
```




<hr>
## Public Functions Documentation




### function i2s\_example\_pdm\_rx\_task 

_I2S PDM RX example task._ 
```C++
void i2s_example_pdm_rx_task (
    void * args
) 
```





**Parameters:**


* `args` The user data given from task creating, not used in this example 




        

<hr>
## Public Static Functions Documentation




### function i2s\_example\_init\_pdm\_rx 

```C++
static i2s_chan_handle_t i2s_example_init_pdm_rx (
    void
) 
```




<hr>
## Macro Definition Documentation





### define EXAMPLE\_PDM\_RX\_CLK\_IO 

```C++
#define EXAMPLE_PDM_RX_CLK_IO `EXAMPLE_I2S_BCLK_IO1`
```




<hr>



### define EXAMPLE\_PDM\_RX\_DIN\_IO 

```C++
#define EXAMPLE_PDM_RX_DIN_IO `EXAMPLE_I2S_DIN_IO1`
```




<hr>



### define EXAMPLE\_PDM\_RX\_FREQ\_HZ 

```C++
#define EXAMPLE_PDM_RX_FREQ_HZ `2048000`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/i2s_pdm/main/i2s_pdm_rx.c`

