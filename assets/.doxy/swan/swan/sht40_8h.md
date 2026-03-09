

# File sht40.h



[**FileList**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**sht40**](dir_180d7217a87f12caa6a5edfd7755cc1b.md) **>** [**sht40.h**](sht40_8h.md)

[Go to the source code of this file](sht40_8h_source.md)

_Driver for SHT40 temperature & humidity sensor._ [More...](#detailed-description)

* `#include "driver/i2c.h"`
* `#include "esp_err.h"`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**sht40\_t**](structsht40__t.md) <br>_SHT40 device structure._  |


## Public Types

| Type | Name |
| ---: | :--- |
| enum  | [**sht40\_cmd\_t**](#enum-sht40_cmd_t)  <br>_SHT40 commands._  |




















## Public Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**sht40\_activate\_heater**](#function-sht40_activate_heater) ([**sht40\_t**](structsht40__t.md) \* dev) <br>_Enable or disable the heater._  |
|  esp\_err\_t | [**sht40\_init**](#function-sht40_init) ([**sht40\_t**](structsht40__t.md) \* dev, i2c\_port\_t i2c\_port, uint8\_t addr) <br>_Initialize SHT40 device._  |
|  esp\_err\_t | [**sht40\_read\_serial**](#function-sht40_read_serial) ([**sht40\_t**](structsht40__t.md) \* dev, uint32\_t \* serial) <br>_Read serial number._  |
|  esp\_err\_t | [**sht40\_read\_temp\_humidity**](#function-sht40_read_temp_humidity) ([**sht40\_t**](structsht40__t.md) \* dev, float \* temperature, float \* humidity) <br>_Read temperature and humidity._  |
|  esp\_err\_t | [**sht40\_reset**](#function-sht40_reset) ([**sht40\_t**](structsht40__t.md) \* dev) <br>_Soft reset the SHT40._  |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**sht40\_send\_cmd**](#function-sht40_send_cmd) ([**sht40\_t**](structsht40__t.md) \* dev, uint16\_t cmd) <br> |

























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**READ\_WRITE\_DELAY\_MS**](sht40_8h.md#define-read_write_delay_ms)  `4`<br>_Delay in milliseconds between write and read operations._  |
| define  | [**SHT40\_I2C\_ADDR\_DEFAULT**](sht40_8h.md#define-sht40_i2c_addr_default)  `0x44`<br>_SHT40 I2C default address._  |

## Detailed Description


This driver provides basic initialization, measurement reading, and serial number retrieval for the SHT40 sensor using the ESP-IDF I2C master driver.


Datasheet: Sensirion SHT40, Version 7.1 March 2025 


    
## Public Types Documentation




### enum sht40\_cmd\_t 

_SHT40 commands._ 
```C++
enum sht40_cmd_t {
    SHT40_CMD_MEASURE_HIGHREP = 0xFD,
    SHT40_CMD_MEASURE_MEDREP = 0xF6,
    SHT40_CMD_MEASURE_LOWREP = 0xE0,
    SHT40_CMD_READ_SERIAL = 0x89,
    SHT40_CMD_SOFT_RESET = 0x94,
    SHT40_CMD_ACTIVATE_HEATER_HIGH_LONG = 0x39,
    SHT40_CMD_ACTIVATE_HEATER_HIGH_SHORT = 0x32,
    SHT40_CMD_ACTIVATE_HEATER_LOW_LONG = 0x1E,
    SHT40_CMD_ACTIVATE_HEATER_LOW_SHORT = 0x15
};
```




<hr>
## Public Functions Documentation




### function sht40\_activate\_heater 

_Enable or disable the heater._ 
```C++
esp_err_t sht40_activate_heater (
    sht40_t * dev
) 
```





**Parameters:**


* `dev` Pointer to [**sht40\_t**](structsht40__t.md) structure 



**Returns:**

ESP\_OK on success


Enable or disable the heater.


Heater is mainly for anti-condensation. Should not be used during measurement. Heater commands are defined in the [**sht40\_cmd\_t**](sht40_8h.md#enum-sht40_cmd_t) enum. This function uses the high power long duration command.




**Parameters:**


* `dev` Pointer to [**sht40\_t**](structsht40__t.md) struct 



**Returns:**

ESP\_OK on success 





        

<hr>



### function sht40\_init 

_Initialize SHT40 device._ 
```C++
esp_err_t sht40_init (
    sht40_t * dev,
    i2c_port_t i2c_port,
    uint8_t addr
) 
```





**Parameters:**


* `dev` Pointer to [**sht40\_t**](structsht40__t.md) struct 
* `i2c_port` I2C port number 
* `addr` I2C device address 



**Returns:**

ESP\_OK on success


Sets I2C port and address, then performs a soft reset.




**Parameters:**


* `dev` Pointer to [**sht40\_t**](structsht40__t.md) struct 
* `i2c_port` I2C port number 
* `addr` I2C device address 



**Returns:**

ESP\_OK on success, error code otherwise 





        

<hr>



### function sht40\_read\_serial 

_Read serial number._ 
```C++
esp_err_t sht40_read_serial (
    sht40_t * dev,
    uint32_t * serial
) 
```





**Parameters:**


* `dev` Pointer to [**sht40\_t**](structsht40__t.md) struct 
* `serial` Pointer to 32-bit variable to store serial number 



**Returns:**

ESP\_OK on success


Read serial number.




**Parameters:**


* `dev` Pointer to [**sht40\_t**](structsht40__t.md) struct 
* `serial` Pointer to store serial number 



**Returns:**

ESP\_OK on success 





        

<hr>



### function sht40\_read\_temp\_humidity 

_Read temperature and humidity._ 
```C++
esp_err_t sht40_read_temp_humidity (
    sht40_t * dev,
    float * temperature,
    float * humidity
) 
```





**Parameters:**


* `dev` Pointer to [**sht40\_t**](structsht40__t.md) struct 
* `temperature` Pointer to float to store temperature (°C) 
* `humidity` Pointer to float to store relative humidity (RH) 



**Returns:**

ESP\_OK on success


Read temperature and humidity.


Uses high repeatability measurement by default.




**Parameters:**


* `dev` Pointer to [**sht40\_t**](structsht40__t.md) struct 
* `temperature` Pointer to float to store temperature 
* `humidity` Pointer to float to store relative humidity 



**Returns:**

ESP\_OK on success 





        

<hr>



### function sht40\_reset 

_Soft reset the SHT40._ 
```C++
esp_err_t sht40_reset (
    sht40_t * dev
) 
```





**Parameters:**


* `dev` Pointer to [**sht40\_t**](structsht40__t.md) struct 



**Returns:**

ESP\_OK on success


Soft reset the SHT40.




**Parameters:**


* `dev` Pointer to [**sht40\_t**](structsht40__t.md) struct 



**Returns:**

ESP\_OK on success 





        

<hr>
## Public Static Functions Documentation




### function sht40\_send\_cmd 

```C++
static esp_err_t sht40_send_cmd (
    sht40_t * dev,
    uint16_t cmd
) 
```




<hr>
## Macro Definition Documentation





### define READ\_WRITE\_DELAY\_MS 

_Delay in milliseconds between write and read operations._ 
```C++
#define READ_WRITE_DELAY_MS `4`
```




<hr>



### define SHT40\_I2C\_ADDR\_DEFAULT 

_SHT40 I2C default address._ 
```C++
#define SHT40_I2C_ADDR_DEFAULT `0x44`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/SWAN-MODULE/components/sht40/sht40.h`

