

# File i2c\_basic\_example\_main.c



[**FileList**](files.md) **>** [**i2c\_basic**](dir_b48419a055961eef97b07fc597549a86.md) **>** [**main**](dir_b0b8cbbb3f2e3e27780a9da35a7f873d.md) **>** [**i2c\_basic\_example\_main.c**](i2c__basic__example__main_8c.md)

[Go to the source code of this file](i2c__basic__example__main_8c_source.md)



* `#include <stdio.h>`
* `#include "sdkconfig.h"`
* `#include "freertos/FreeRTOS.h"`
* `#include "freertos/task.h"`
* `#include "esp_log.h"`
* `#include "driver/i2c_master.h"`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const char \* | [**TAG**](#variable-tag)   = `"example"`<br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**app\_main**](#function-app_main) (void) <br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  void | [**i2c\_master\_init**](#function-i2c_master_init) (i2c\_master\_bus\_handle\_t \* bus\_handle, i2c\_master\_dev\_handle\_t \* dev\_handle) <br>_i2c master initialization_  |
|  esp\_err\_t | [**mpu9250\_register\_read**](#function-mpu9250_register_read) (i2c\_master\_dev\_handle\_t dev\_handle, uint8\_t reg\_addr, uint8\_t \* data, size\_t len) <br>_Read a sequence of bytes from a MPU9250 sensor registers._  |
|  esp\_err\_t | [**mpu9250\_register\_write\_byte**](#function-mpu9250_register_write_byte) (i2c\_master\_dev\_handle\_t dev\_handle, uint8\_t reg\_addr, uint8\_t data) <br>_Write a byte to a MPU9250 sensor register._  |

























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**I2C\_MASTER\_FREQ\_HZ**](i2c__basic__example__main_8c.md#define-i2c_master_freq_hz)  `CONFIG\_I2C\_MASTER\_FREQUENCY`<br> |
| define  | [**I2C\_MASTER\_NUM**](i2c__basic__example__main_8c.md#define-i2c_master_num)  `I2C\_NUM\_0`<br> |
| define  | [**I2C\_MASTER\_RX\_BUF\_DISABLE**](i2c__basic__example__main_8c.md#define-i2c_master_rx_buf_disable)  `0`<br> |
| define  | [**I2C\_MASTER\_SCL\_IO**](i2c__basic__example__main_8c.md#define-i2c_master_scl_io)  `CONFIG\_I2C\_MASTER\_SCL`<br> |
| define  | [**I2C\_MASTER\_SDA\_IO**](i2c__basic__example__main_8c.md#define-i2c_master_sda_io)  `CONFIG\_I2C\_MASTER\_SDA`<br> |
| define  | [**I2C\_MASTER\_TIMEOUT\_MS**](i2c__basic__example__main_8c.md#define-i2c_master_timeout_ms)  `1000`<br> |
| define  | [**I2C\_MASTER\_TX\_BUF\_DISABLE**](i2c__basic__example__main_8c.md#define-i2c_master_tx_buf_disable)  `0`<br> |
| define  | [**MPU9250\_PWR\_MGMT\_1\_REG\_ADDR**](i2c__basic__example__main_8c.md#define-mpu9250_pwr_mgmt_1_reg_addr)  `0x6B`<br> |
| define  | [**MPU9250\_RESET\_BIT**](i2c__basic__example__main_8c.md#define-mpu9250_reset_bit)  `7`<br> |
| define  | [**MPU9250\_SENSOR\_ADDR**](i2c__basic__example__main_8c.md#define-mpu9250_sensor_addr)  `0x68`<br> |
| define  | [**MPU9250\_WHO\_AM\_I\_REG\_ADDR**](i2c__basic__example__main_8c.md#define-mpu9250_who_am_i_reg_addr)  `0x75`<br> |

## Public Static Attributes Documentation




### variable TAG 

```C++
const char* TAG;
```




<hr>
## Public Functions Documentation




### function app\_main 

```C++
void app_main (
    void
) 
```




<hr>
## Public Static Functions Documentation




### function i2c\_master\_init 

_i2c master initialization_ 
```C++
static void i2c_master_init (
    i2c_master_bus_handle_t * bus_handle,
    i2c_master_dev_handle_t * dev_handle
) 
```




<hr>



### function mpu9250\_register\_read 

_Read a sequence of bytes from a MPU9250 sensor registers._ 
```C++
static esp_err_t mpu9250_register_read (
    i2c_master_dev_handle_t dev_handle,
    uint8_t reg_addr,
    uint8_t * data,
    size_t len
) 
```




<hr>



### function mpu9250\_register\_write\_byte 

_Write a byte to a MPU9250 sensor register._ 
```C++
static esp_err_t mpu9250_register_write_byte (
    i2c_master_dev_handle_t dev_handle,
    uint8_t reg_addr,
    uint8_t data
) 
```




<hr>
## Macro Definition Documentation





### define I2C\_MASTER\_FREQ\_HZ 

```C++
#define I2C_MASTER_FREQ_HZ `CONFIG_I2C_MASTER_FREQUENCY`
```



I2C master clock frequency 


        

<hr>



### define I2C\_MASTER\_NUM 

```C++
#define I2C_MASTER_NUM `I2C_NUM_0`
```



I2C port number for master dev 


        

<hr>



### define I2C\_MASTER\_RX\_BUF\_DISABLE 

```C++
#define I2C_MASTER_RX_BUF_DISABLE `0`
```



I2C master doesn't need buffer 


        

<hr>



### define I2C\_MASTER\_SCL\_IO 

```C++
#define I2C_MASTER_SCL_IO `CONFIG_I2C_MASTER_SCL`
```



GPIO number used for I2C master clock 


        

<hr>



### define I2C\_MASTER\_SDA\_IO 

```C++
#define I2C_MASTER_SDA_IO `CONFIG_I2C_MASTER_SDA`
```



GPIO number used for I2C master data 


        

<hr>



### define I2C\_MASTER\_TIMEOUT\_MS 

```C++
#define I2C_MASTER_TIMEOUT_MS `1000`
```




<hr>



### define I2C\_MASTER\_TX\_BUF\_DISABLE 

```C++
#define I2C_MASTER_TX_BUF_DISABLE `0`
```



I2C master doesn't need buffer 


        

<hr>



### define MPU9250\_PWR\_MGMT\_1\_REG\_ADDR 

```C++
#define MPU9250_PWR_MGMT_1_REG_ADDR `0x6B`
```



Register addresses of the power management register 


        

<hr>



### define MPU9250\_RESET\_BIT 

```C++
#define MPU9250_RESET_BIT `7`
```




<hr>



### define MPU9250\_SENSOR\_ADDR 

```C++
#define MPU9250_SENSOR_ADDR `0x68`
```



Address of the MPU9250 sensor 


        

<hr>



### define MPU9250\_WHO\_AM\_I\_REG\_ADDR 

```C++
#define MPU9250_WHO_AM_I_REG_ADDR `0x75`
```



Register addresses of the "who am I" register 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/i2c_basic/main/i2c_basic_example_main.c`

