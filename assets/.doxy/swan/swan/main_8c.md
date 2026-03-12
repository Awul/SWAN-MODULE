

# File main.c



[**FileList**](files.md) **>** [**main**](dir_5c982d53a68cdbcd421152b4020263a9.md) **>** [**main.c**](main_8c.md)

[Go to the source code of this file](main_8c_source.md)



* `#include <stdio.h>`
* `#include "freertos/FreeRTOS.h"`
* `#include "freertos/task.h"`
* `#include "esp_log.h"`
* `#include "esp_err.h"`
* `#include "math.h"`
* `#include "driver/uart.h"`
* `#include "esp_timer.h"`
* `#include "secrets.h"`
* `#include "i2c_bus.h"`
* `#include "veml7700.h"`
* `#include "sht40.h"`
* `#include "im72d128.h"`
* `#include "wifi_manager.h"`
* `#include "swan_mqtt_client.h"`
* `#include "json_payload.h"`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  [**im72d128\_t**](structim72d128__t.md) | [**mic\_sensor**](#variable-mic_sensor)  <br> |
|  const char \* | [**sensors**](#variable-sensors)   = `{"temperature", "humidity", "light"}`<br> |
|  [**sht40\_t**](structsht40__t.md) | [**sht\_sensor**](#variable-sht_sensor)  <br> |
|  [**veml7700\_t**](structveml7700__t.md) | [**veml\_sensor**](#variable-veml_sensor)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**app\_main**](#function-app_main) (void) <br> |
|  void | [**setup**](#function-setup) () <br> |
|  void | [**setup\_i2c**](#function-setup_i2c) () <br> |
|  void | [**setup\_im72d128**](#function-setup_im72d128) () <br> |
|  void | [**setup\_mqtt**](#function-setup_mqtt) () <br> |
|  void | [**setup\_sht40**](#function-setup_sht40) () <br> |
|  void | [**setup\_veml7700**](#function-setup_veml7700) () <br> |
|  void | [**setup\_wifi**](#function-setup_wifi) () <br> |



























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**FIRMWARE\_VERSION**](main_8c.md#define-firmware_version)  `"0.1.0"`<br> |
| define  | [**MQTT\_ID**](main_8c.md#define-mqtt_id)  `NODE\_ID`<br> |
| define  | [**MQTT\_URI**](main_8c.md#define-mqtt_uri)  `"mqtt://192.168.122.237:1883"`<br> |
| define  | [**MQTT\_USERNAME**](main_8c.md#define-mqtt_username)  `"swan"`<br> |
| define  | [**NODE\_ID**](main_8c.md#define-node_id)  `"swan-module-TEST"`<br> |
| define  | [**SENSOR\_COUNT**](main_8c.md#define-sensor_count)  `3`<br> |
| define  | [**TAG**](main_8c.md#define-tag)  `"MAIN"`<br> |
| define  | [**WIFI\_SSID**](main_8c.md#define-wifi_ssid)  `"swan-net"`<br> |

## Public Attributes Documentation




### variable mic\_sensor 

```C++
im72d128_t mic_sensor;
```




<hr>



### variable sensors 

```C++
const char* sensors[];
```




<hr>



### variable sht\_sensor 

```C++
sht40_t sht_sensor;
```




<hr>



### variable veml\_sensor 

```C++
veml7700_t veml_sensor;
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



### function setup 

```C++
void setup () 
```




<hr>



### function setup\_i2c 

```C++
void setup_i2c () 
```




<hr>



### function setup\_im72d128 

```C++
void setup_im72d128 () 
```




<hr>



### function setup\_mqtt 

```C++
void setup_mqtt () 
```




<hr>



### function setup\_sht40 

```C++
void setup_sht40 () 
```




<hr>



### function setup\_veml7700 

```C++
void setup_veml7700 () 
```




<hr>



### function setup\_wifi 

```C++
void setup_wifi () 
```




<hr>
## Macro Definition Documentation





### define FIRMWARE\_VERSION 

```C++
#define FIRMWARE_VERSION `"0.1.0"`
```




<hr>



### define MQTT\_ID 

```C++
#define MQTT_ID `NODE_ID`
```




<hr>



### define MQTT\_URI 

```C++
#define MQTT_URI `"mqtt://192.168.122.237:1883"`
```




<hr>



### define MQTT\_USERNAME 

```C++
#define MQTT_USERNAME `"swan"`
```




<hr>



### define NODE\_ID 

```C++
#define NODE_ID `"swan-module-TEST"`
```




<hr>



### define SENSOR\_COUNT 

```C++
#define SENSOR_COUNT `3`
```




<hr>



### define TAG 

```C++
#define TAG `"MAIN"`
```




<hr>



### define WIFI\_SSID 

```C++
#define WIFI_SSID `"swan-net"`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/SWAN-MODULE/main/main.c`

