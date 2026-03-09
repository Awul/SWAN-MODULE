

# File sht40.c



[**FileList**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**sht40**](dir_180d7217a87f12caa6a5edfd7755cc1b.md) **>** [**sht40.c**](sht40_8c.md)

[Go to the source code of this file](sht40_8c_source.md)



* `#include "sht40.h"`
* `#include "driver/i2c.h"`
* `#include "esp_log.h"`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const char \* | [**TAG**](#variable-tag)   = `"SHT40"`<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**sht40\_activate\_heater**](#function-sht40_activate_heater) ([**sht40\_t**](structsht40__t.md) \* dev) <br>_Activate the SHT40 heater._  |
|  esp\_err\_t | [**sht40\_init**](#function-sht40_init) ([**sht40\_t**](structsht40__t.md) \* dev, i2c\_port\_t i2c\_port, uint8\_t addr) <br>_Initialize SHT40 device._  |
|  esp\_err\_t | [**sht40\_read\_serial**](#function-sht40_read_serial) ([**sht40\_t**](structsht40__t.md) \* dev, uint32\_t \* serial) <br>_Read 32-bit serial number of SHT40._  |
|  esp\_err\_t | [**sht40\_read\_temp\_humidity**](#function-sht40_read_temp_humidity) ([**sht40\_t**](structsht40__t.md) \* dev, float \* temperature, float \* humidity) <br>_Read temperature (°C) and humidity (RH) from SHT40._  |
|  esp\_err\_t | [**sht40\_reset**](#function-sht40_reset) ([**sht40\_t**](structsht40__t.md) \* dev) <br>_Soft reset the SHT40 sensor._  |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**sht40\_send\_cmd**](#function-sht40_send_cmd) ([**sht40\_t**](structsht40__t.md) \* dev, uint16\_t cmd) <br> |


























## Public Static Attributes Documentation




### variable TAG 

```C++
const char* TAG;
```




<hr>
## Public Functions Documentation




### function sht40\_activate\_heater 

_Activate the SHT40 heater._ 
```C++
esp_err_t sht40_activate_heater (
    sht40_t * dev
) 
```



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



Sets I2C port and address, then performs a soft reset.




**Parameters:**


* `dev` Pointer to [**sht40\_t**](structsht40__t.md) struct 
* `i2c_port` I2C port number 
* `addr` I2C device address 



**Returns:**

ESP\_OK on success, error code otherwise 





        

<hr>



### function sht40\_read\_serial 

_Read 32-bit serial number of SHT40._ 
```C++
esp_err_t sht40_read_serial (
    sht40_t * dev,
    uint32_t * serial
) 
```



Read serial number.




**Parameters:**


* `dev` Pointer to [**sht40\_t**](structsht40__t.md) struct 
* `serial` Pointer to store serial number 



**Returns:**

ESP\_OK on success 





        

<hr>



### function sht40\_read\_temp\_humidity 

_Read temperature (°C) and humidity (RH) from SHT40._ 
```C++
esp_err_t sht40_read_temp_humidity (
    sht40_t * dev,
    float * temperature,
    float * humidity
) 
```



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

_Soft reset the SHT40 sensor._ 
```C++
esp_err_t sht40_reset (
    sht40_t * dev
) 
```



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

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/SWAN-MODULE/components/sht40/sht40.c`

