

# File i2s\_pdm\_tx.c



[**FileList**](files.md) **>** [**i2s\_pdm**](dir_a9d5f53e1a98f7a823b6664583338eef.md) **>** [**main**](dir_8b646def77c344b31338d8d065cc4f74.md) **>** [**i2s\_pdm\_tx.c**](i2s__pdm__tx_8c.md)

[Go to the source code of this file](i2s__pdm__tx_8c_source.md)



* `#include <stdint.h>`
* `#include <math.h>`
* `#include "freertos/FreeRTOS.h"`
* `#include "freertos/task.h"`
* `#include "driver/i2s_pdm.h"`
* `#include "driver/gpio.h"`
* `#include "esp_check.h"`
* `#include "sdkconfig.h"`
* `#include "i2s_pdm_example.h"`
* `#include "i2s_example_pins.h"`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const uint8\_t | [**rhythm**](#variable-rhythm)   = `{1, 1, 1, 1, 1, 1, 2}`<br> |
|  const uint8\_t | [**song**](#variable-song)   = `/* multi line expression */`<br> |
|  const uint32\_t | [**tone**](#variable-tone)   = `/* multi line expression */`<br> |
|  const char \* | [**tone\_name**](#variable-tone_name)   = `{"bass", "alto", "treble"}`<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**i2s\_example\_pdm\_tx\_task**](#function-i2s_example_pdm_tx_task) (void \* args) <br>_I2S PDM TX example task._  |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  i2s\_chan\_handle\_t | [**i2s\_example\_init\_pdm\_tx**](#function-i2s_example_init_pdm_tx) (void) <br> |

























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**CONST\_PI**](i2s__pdm__tx_8c.md#define-const_pi)  `(3.1416f)`<br> |
| define  | [**EXAMPLE\_BYTE\_NUM\_EVERY\_TONE**](i2s__pdm__tx_8c.md#define-example_byte_num_every_tone)  `(EXAMPLE\_TONE\_LAST\_TIME\_MS \* EXAMPLE\_PDM\_TX\_FREQ\_HZ / 1000)`<br> |
| define  | [**EXAMPLE\_PDM\_TX\_CLK\_IO**](i2s__pdm__tx_8c.md#define-example_pdm_tx_clk_io)  `EXAMPLE\_I2S\_BCLK\_IO1`<br> |
| define  | [**EXAMPLE\_PDM\_TX\_DOUT\_IO**](i2s__pdm__tx_8c.md#define-example_pdm_tx_dout_io)  `EXAMPLE\_I2S\_DOUT\_IO1`<br> |
| define  | [**EXAMPLE\_PDM\_TX\_FREQ\_HZ**](i2s__pdm__tx_8c.md#define-example_pdm_tx_freq_hz)  `16000`<br> |
| define  | [**EXAMPLE\_SINE\_WAVE\_LEN**](i2s__pdm__tx_8c.md#define-example_sine_wave_len) (tone) `(uint32\_t)((EXAMPLE\_PDM\_TX\_FREQ\_HZ / (float)tone) + 0.5)`<br> |
| define  | [**EXAMPLE\_TONE\_LAST\_TIME\_MS**](i2s__pdm__tx_8c.md#define-example_tone_last_time_ms)  `500`<br> |
| define  | [**EXAMPLE\_WAVE\_AMPLITUDE**](i2s__pdm__tx_8c.md#define-example_wave_amplitude)  `(1000.0)`<br> |

## Public Static Attributes Documentation




### variable rhythm 

```C++
const uint8_t rhythm[7];
```




<hr>



### variable song 

```C++
const uint8_t song[28];
```




<hr>



### variable tone 

```C++
const uint32_t tone[3][7];
```




<hr>



### variable tone\_name 

```C++
const char* tone_name[3];
```




<hr>
## Public Functions Documentation




### function i2s\_example\_pdm\_tx\_task 

_I2S PDM TX example task._ 
```C++
void i2s_example_pdm_tx_task (
    void * args
) 
```





**Parameters:**


* `args` The user data given from task creating, not used in this example 




        

<hr>
## Public Static Functions Documentation




### function i2s\_example\_init\_pdm\_tx 

```C++
static i2s_chan_handle_t i2s_example_init_pdm_tx (
    void
) 
```




<hr>
## Macro Definition Documentation





### define CONST\_PI 

```C++
#define CONST_PI `(3.1416f)`
```




<hr>



### define EXAMPLE\_BYTE\_NUM\_EVERY\_TONE 

```C++
#define EXAMPLE_BYTE_NUM_EVERY_TONE `(EXAMPLE_TONE_LAST_TIME_MS * EXAMPLE_PDM_TX_FREQ_HZ / 1000)`
```




<hr>



### define EXAMPLE\_PDM\_TX\_CLK\_IO 

```C++
#define EXAMPLE_PDM_TX_CLK_IO `EXAMPLE_I2S_BCLK_IO1`
```




<hr>



### define EXAMPLE\_PDM\_TX\_DOUT\_IO 

```C++
#define EXAMPLE_PDM_TX_DOUT_IO `EXAMPLE_I2S_DOUT_IO1`
```




<hr>



### define EXAMPLE\_PDM\_TX\_FREQ\_HZ 

```C++
#define EXAMPLE_PDM_TX_FREQ_HZ `16000`
```




<hr>



### define EXAMPLE\_SINE\_WAVE\_LEN 

```C++
#define EXAMPLE_SINE_WAVE_LEN (
    tone
) `(uint32_t)((EXAMPLE_PDM_TX_FREQ_HZ / (float)tone) + 0.5)`
```




<hr>



### define EXAMPLE\_TONE\_LAST\_TIME\_MS 

```C++
#define EXAMPLE_TONE_LAST_TIME_MS `500`
```




<hr>



### define EXAMPLE\_WAVE\_AMPLITUDE 

```C++
#define EXAMPLE_WAVE_AMPLITUDE `(1000.0)`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/i2s_pdm/main/i2s_pdm_tx.c`

