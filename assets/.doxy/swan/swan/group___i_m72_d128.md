

# Group IM72D128



[**Modules**](modules.md) **>** [**IM72D128**](group___i_m72_d128.md)




















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**im72d128\_t**](structim72d128__t.md) <br>_IM72D128 microphone configuration structure._  |






















## Public Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**im72d128\_init**](#function-im72d128_init) ([**im72d128\_t**](structim72d128__t.md) \* mic, i2s\_port\_t port, gpio\_num\_t clk\_pin, gpio\_num\_t data\_pin, uint32\_t sample\_rate) <br>_Initialize IM72D128 microphone._  |
|  esp\_err\_t | [**im72d128\_read**](#function-im72d128_read) ([**im72d128\_t**](structim72d128__t.md) \* mic, int16\_t \* buffer, size\_t samples, size\_t \* bytes\_read) <br>_Read PCM audio samples._  |



























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**MIC\_CLK\_PIN**](group___i_m72_d128.md#define-mic_clk_pin)  `GPIO\_NUM\_5`<br>_PDM microphone pins._  |
| define  | [**MIC\_DATA\_PIN**](group___i_m72_d128.md#define-mic_data_pin)  `GPIO\_NUM\_4`<br> |

## Public Functions Documentation




### function im72d128\_init 

_Initialize IM72D128 microphone._ 
```
esp_err_t im72d128_init (
    im72d128_t * mic,
    i2s_port_t port,
    gpio_num_t clk_pin,
    gpio_num_t data_pin,
    uint32_t sample_rate
) 
```



Configures the ESP32 I2S peripheral in PDM receive mode.




**Parameters:**


* `mic` Pointer to microphone structure 
* `port` I2S port (I2S\_NUM\_0 or I2S\_NUM\_1) 
* `clk_pin` GPIO used for PDM clock 
* `data_pin` GPIO used for microphone data 
* `sample_rate` Desired PCM sample rate



**Returns:**

ESP\_OK on success


Initialize IM72D128 microphone. 


        

<hr>



### function im72d128\_read 

_Read PCM audio samples._ 
```
esp_err_t im72d128_read (
    im72d128_t * mic,
    int16_t * buffer,
    size_t samples,
    size_t * bytes_read
) 
```



Reads audio samples converted from the PDM microphone.




**Parameters:**


* `mic` Pointer to microphone structure 
* `buffer` Pointer to sample buffer 
* `samples` Number of samples to read 
* `bytes_read` Optional pointer returning bytes read



**Returns:**

ESP\_OK on success


Read PCM audio samples. 


        

<hr>
## Macro Definition Documentation





### define MIC\_CLK\_PIN 

_PDM microphone pins._ 
```
#define MIC_CLK_PIN `GPIO_NUM_5`
```




<hr>



### define MIC\_DATA\_PIN 

```
#define MIC_DATA_PIN `GPIO_NUM_4`
```




<hr>

------------------------------


