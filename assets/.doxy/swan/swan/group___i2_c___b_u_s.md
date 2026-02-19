

# Group I2C\_BUS



[**Modules**](modules.md) **>** [**I2C\_BUS**](group___i2_c___b_u_s.md)



[More...](#detailed-description)






































## Public Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**i2c\_bus\_init**](#function-i2c_bus_init) (void) <br>_Initialize the I2C bus._  |
|  void | [**i2c\_bus\_status**](#function-i2c_bus_status) (void) <br>_Print the current I2C bus status._  |
|  void | [**i2c\_scan**](#function-i2c_scan) (void) <br>_Scan the I2C bus for connected devices._  |



























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**I2C\_FREQ**](group___i2_c___b_u_s.md#define-i2c_freq)  `100000`<br>_Default I2C Frequency._  |
| define  | [**I2C\_PORT**](group___i2_c___b_u_s.md#define-i2c_port)  `I2C\_NUM\_0`<br>_The I2C port used by the bus._  |
| define  | [**I2C\_SCL**](group___i2_c___b_u_s.md#define-i2c_scl)  `9`<br>_Default I2C SCL Pin._  |
| define  | [**I2C\_SDA**](group___i2_c___b_u_s.md#define-i2c_sda)  `8`<br>_Default I2C SDA Pin._  |

## Detailed Description


This module provides initialization, status reporting, and scanning utilities for the I2C bus. 


    
## Public Functions Documentation




### function i2c\_bus\_init 

_Initialize the I2C bus._ 
```
esp_err_t i2c_bus_init (
    void
) 
```



Sets up the I2C peripheral with predefined SDA/SCL pins (8, 9) and frequency (100kHz). Creates a mutex for thread-safe access.




**Returns:**

ESP\_OK if bus initialized successfully 




**Returns:**

ESP\_ERR\_INVALID\_ARG if configuration fails


Configures the I2C peripheral with default pins and frequency. Creates a mutex for thread-safe operations. 


        

<hr>



### function i2c\_bus\_status 

_Print the current I2C bus status._ 
```
void i2c_bus_status (
    void
) 
```



Logs whether the I2C bus is initialized and whether the mutex exists. Useful for debugging and verifying proper initialization. 


        

<hr>



### function i2c\_scan 

_Scan the I2C bus for connected devices._ 
```
void i2c_scan (
    void
) 
```



Attempts communication with all valid 7-bit I2C addresses (1–126) and logs any devices that respond. Useful for detecting attached sensors. 


        

<hr>
## Macro Definition Documentation





### define I2C\_FREQ 

_Default I2C Frequency._ 
```
#define I2C_FREQ `100000`
```




<hr>



### define I2C\_PORT 

_The I2C port used by the bus._ 
```
#define I2C_PORT `I2C_NUM_0`
```




<hr>



### define I2C\_SCL 

_Default I2C SCL Pin._ 
```
#define I2C_SCL `9`
```




<hr>



### define I2C\_SDA 

_Default I2C SDA Pin._ 
```
#define I2C_SDA `8`
```




<hr>

------------------------------


