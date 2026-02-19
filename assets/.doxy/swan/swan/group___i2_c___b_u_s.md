

# Group I2C\_BUS



[**Modules**](modules.md) **>** [**I2C\_BUS**](group___i2_c___b_u_s.md)



[More...](#detailed-description)






































## Public Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**i2c\_bus\_init**](#function-i2c_bus_init) (void) <br>_Initialize the I2C bus._  |
|  esp\_err\_t | [**i2c\_bus\_write\_read**](#function-i2c_bus_write_read) (uint8\_t addr, uint8\_t \* write\_buf, size\_t write\_len, uint8\_t \* read\_buf, size\_t read\_len, TickType\_t ticks\_to\_wait) <br>_Perform a write/read operation on the I2C bus._  |



























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**I2C\_PORT**](group___i2_c___b_u_s.md#define-i2c_port)  `I2C\_NUM\_0`<br>_The I2C port used by the bus._  |

## Detailed Description


This module provides a singleton I2C bus instance and thread-safe functions to read/write over the bus. 


    
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





        

<hr>



### function i2c\_bus\_write\_read 

_Perform a write/read operation on the I2C bus._ 
```
esp_err_t i2c_bus_write_read (
    uint8_t addr,
    uint8_t * write_buf,
    size_t write_len,
    uint8_t * read_buf,
    size_t read_len,
    TickType_t ticks_to_wait
) 
```



This function is mutex-protected to allow multiple sensors to safely share the same I2C bus.




**Parameters:**


* `addr` The 7-bit I2C address of the device 
* `write_buf` Pointer to data to write (can be NULL if no write) 
* `write_len` Number of bytes to write 
* `read_buf` Pointer to buffer for read data (can be NULL if no read) 
* `read_len` Number of bytes to read 
* `ticks_to_wait` Maximum time to wait for bus access (FreeRTOS ticks)



**Returns:**

ESP\_OK on success 




**Returns:**

ESP\_ERR\_TIMEOUT if mutex or bus timed out 




**Returns:**

Other ESP\_ERR\_\* codes if I2C operation fails 





        

<hr>
## Macro Definition Documentation





### define I2C\_PORT 

_The I2C port used by the bus._ 
```
#define I2C_PORT `I2C_NUM_0`
```




<hr>

------------------------------


