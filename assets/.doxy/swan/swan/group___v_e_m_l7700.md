

# Group VEML7700



[**Modules**](modules.md) **>** [**VEML7700**](group___v_e_m_l7700.md)




















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**veml7700\_t**](structveml7700__t.md) <br>_VEML7700 device descriptor._  |






















## Public Functions

| Type | Name |
| ---: | :--- |
|  float | [**veml7700\_gain\_factor**](#function-veml7700_gain_factor) (uint8\_t gain\_bits) <br>_Gets the gain factor based on the gain setting._  |
|  esp\_err\_t | [**veml7700\_init**](#function-veml7700_init) ([**veml7700\_t**](structveml7700__t.md) \* dev, i2c\_port\_t port) <br>_Initialize the VEML7700 sensor._  |
|  void | [**veml7700\_print\_registers**](#function-veml7700_print_registers) (const [**veml7700\_t**](structveml7700__t.md) \* dev) <br>_Print a full register dump and interpreted sensor status._  |
|  esp\_err\_t | [**veml7700\_read\_als**](#function-veml7700_read_als) ([**veml7700\_t**](structveml7700__t.md) \* dev, uint16\_t \* als) <br>_Read raw ALS (ambient light sensor) counts._  |
|  esp\_err\_t | [**veml7700\_read\_lux**](#function-veml7700_read_lux) ([**veml7700\_t**](structveml7700__t.md) \* dev, float \* lux) <br>_Read ambient light in lux._  |
|  float | [**veml7700\_responsivity**](#function-veml7700_responsivity) (uint8\_t it\_bits) <br>_Gets the responsivity (lux/count) based on the integration time setting._  |



























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**VEML7700\_I2C\_ADDR\_DEFAULT**](group___v_e_m_l7700.md#define-veml7700_i2c_addr_default)  `0x10`<br>_VEML7700 I2C address._  |
| define  | [**VEML7700\_REG\_ALS**](group___v_e_m_l7700.md#define-veml7700_reg_als)  `0x04`<br>_ALS measurement output._  |
| define  | [**VEML7700\_REG\_ALS\_CONF\_0**](group___v_e_m_l7700.md#define-veml7700_reg_als_conf_0)  `0x00`<br>_ALS configuration register._  |
| define  | [**VEML7700\_REG\_ALS\_INT**](group___v_e_m_l7700.md#define-veml7700_reg_als_int)  `0x06`<br>_Interrupt status register._  |
| define  | [**VEML7700\_REG\_ALS\_WH**](group___v_e_m_l7700.md#define-veml7700_reg_als_wh)  `0x01`<br>_ALS high threshold window._  |
| define  | [**VEML7700\_REG\_ALS\_WL**](group___v_e_m_l7700.md#define-veml7700_reg_als_wl)  `0x02`<br>_ALS low threshold window._  |
| define  | [**VEML7700\_REG\_ID**](group___v_e_m_l7700.md#define-veml7700_reg_id)  `0x07`<br>_Device ID register._  |
| define  | [**VEML7700\_REG\_POWER\_SAVING**](group___v_e_m_l7700.md#define-veml7700_reg_power_saving)  `0x03`<br>_Power saving mode register._  |
| define  | [**VEML7700\_REG\_WHITE**](group___v_e_m_l7700.md#define-veml7700_reg_white)  `0x05`<br>_White channel measurement output._  |

## Public Functions Documentation




### function veml7700\_gain\_factor 

_Gets the gain factor based on the gain setting._ 
```
float veml7700_gain_factor (
    uint8_t gain_bits
) 
```



The VEML7700's gain setting affects the scaling of the ALS counts. This function returns the gain factor corresponding to the gain bits from the configuration register.




**Parameters:**


* `gain_bits` The gain bits extracted from the ALS\_CONF\_0 register 



**Returns:**

The gain factor (e.g., 1.0 for x1, 2.0 for x2, etc.) corresponding to the gain setting 





        

<hr>



### function veml7700\_init 

_Initialize the VEML7700 sensor._ 
```
esp_err_t veml7700_init (
    veml7700_t * dev,
    i2c_port_t port
) 
```



Powers on the sensor and applies a default ALS configuration (Gain = 1×, Integration Time = 100 ms).




**Parameters:**


* `dev` Pointer to a VEML7700 device descriptor 
* `port` I²C port on which the sensor is connected



**Returns:**


* ESP\_OK on success
* ESP\_FAIL or ESP\_ERR\_\* on I²C communication error 







        

<hr>



### function veml7700\_print\_registers 

_Print a full register dump and interpreted sensor status._ 
```
void veml7700_print_registers (
    const veml7700_t * dev
) 
```



This function reads all registers (0x00–0x07) and prints:
* Raw register values
* Configuration decoding (gain, integration time, shutdown)
* Power saving status
* Interrupt flags
* Device ID interpretation




Intended for debugging and sensor bring-up.




**Parameters:**


* `dev` Pointer to VEML7700 device structure 




        

<hr>



### function veml7700\_read\_als 

_Read raw ALS (ambient light sensor) counts._ 
```
esp_err_t veml7700_read_als (
    veml7700_t * dev,
    uint16_t * als
) 
```



Reads the raw 16-bit ALS register value. This value is not converted to physical units.




**Parameters:**


* `dev` Pointer to initialized VEML7700 device descriptor 
* `als` Pointer to store the raw ALS value



**Returns:**


* ESP\_OK on success
* ESP\_FAIL or ESP\_ERR\_\* on I²C communication error 







        

<hr>



### function veml7700\_read\_lux 

_Read ambient light in lux._ 
```
esp_err_t veml7700_read_lux (
    veml7700_t * dev,
    float * lux
) 
```



Reads the raw ALS value and converts it to lux using the current gain and integration time settings. The conversion factors are based on the VEML7700 datasheet and the helper functions for responsivity and gain factor. The formula used is: lux = ALS\_counts / gain\_factor \* responsivity




**Parameters:**


* `dev` Pointer to initialized VEML7700 device descriptor 
* `lux` Pointer to store the calculated lux value



**Returns:**


* ESP\_OK on success
* ESP\_FAIL or ESP\_ERR\_\* on I²C communication error 







        

<hr>



### function veml7700\_responsivity 

_Gets the responsivity (lux/count) based on the integration time setting._ 
```
float veml7700_responsivity (
    uint8_t it_bits
) 
```



The VEML7700's responsivity changes based on the integration time setting. This function calculates the lux/count factor for the current integration time configuration.




**Parameters:**


* `it_bits` The integration time bits extracted from the ALS\_CONF\_0 register 



**Returns:**

The responsivity in lux/count for the given integration time setting


@ 


        

<hr>
## Macro Definition Documentation





### define VEML7700\_I2C\_ADDR\_DEFAULT 

_VEML7700 I2C address._ 
```
#define VEML7700_I2C_ADDR_DEFAULT `0x10`
```



The VEML7700 has a fixed 7-bit I2C address of 0x10. This is the default address used by the driver, but it can be overridden in the device descriptor. 


        

<hr>



### define VEML7700\_REG\_ALS 

_ALS measurement output._ 
```
#define VEML7700_REG_ALS `0x04`
```




<hr>



### define VEML7700\_REG\_ALS\_CONF\_0 

_ALS configuration register._ 
```
#define VEML7700_REG_ALS_CONF_0 `0x00`
```




<hr>



### define VEML7700\_REG\_ALS\_INT 

_Interrupt status register._ 
```
#define VEML7700_REG_ALS_INT `0x06`
```




<hr>



### define VEML7700\_REG\_ALS\_WH 

_ALS high threshold window._ 
```
#define VEML7700_REG_ALS_WH `0x01`
```




<hr>



### define VEML7700\_REG\_ALS\_WL 

_ALS low threshold window._ 
```
#define VEML7700_REG_ALS_WL `0x02`
```




<hr>



### define VEML7700\_REG\_ID 

_Device ID register._ 
```
#define VEML7700_REG_ID `0x07`
```




<hr>



### define VEML7700\_REG\_POWER\_SAVING 

_Power saving mode register._ 
```
#define VEML7700_REG_POWER_SAVING `0x03`
```




<hr>



### define VEML7700\_REG\_WHITE 

_White channel measurement output._ 
```
#define VEML7700_REG_WHITE `0x05`
```




<hr>

------------------------------


