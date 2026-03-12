

# File wifi\_manager.h



[**FileList**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**wifi\_manager**](dir_fe90acb48b1d14dd9ed13ebfae9d32ea.md) **>** [**wifi\_manager.h**](wifi__manager_8h.md)

[Go to the source code of this file](wifi__manager_8h_source.md)

_Simple WiFi station manager for ESP-IDF._ [More...](#detailed-description)

* `#include <stdbool.h>`
* `#include "esp_err.h"`
* `#include <string.h>`
* `#include "esp_wifi.h"`
* `#include "esp_log.h"`
* `#include "esp_event.h"`
* `#include "esp_netif.h"`
* `#include "nvs_flash.h"`
* `#include "freertos/FreeRTOS.h"`
* `#include "freertos/event_groups.h"`















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**wifi\_manager\_config\_t**](structwifi__manager__config__t.md) <br>_WiFi configuration parameters._  |


















































## Detailed Description


This component provides a minimal interface to connect an ESP32 to an existing WiFi network (station mode).


It handles:
* WiFi driver initialization
* connection to an access point
* automatic reconnection
* IP acquisition
* connection status tracking




Typical usage:



```C++
wifi_manager_config_t cfg = {
    .ssid = "MyNetwork",
    .password = "password123"
};

wifi_manager_init(&cfg);
wifi_manager_wait_connected();

// Safe to start MQTT, sockets, streaming, etc.
```
 


    

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/SWAN-MODULE/components/wifi_manager/wifi_manager.h`

