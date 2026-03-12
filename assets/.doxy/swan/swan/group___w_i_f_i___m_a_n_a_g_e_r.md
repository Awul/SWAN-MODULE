

# Group WIFI\_MANAGER



[**Modules**](modules.md) **>** [**WIFI\_MANAGER**](group___w_i_f_i___m_a_n_a_g_e_r.md)




















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**wifi\_manager\_config\_t**](structwifi__manager__config__t.md) <br>_WiFi configuration parameters._  |






















## Public Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**wifi\_manager\_init**](#function-wifi_manager_init) ([**wifi\_manager\_config\_t**](structwifi__manager__config__t.md) \* config) <br>_Initialize the WiFi manager and start connection._  |
|  bool | [**wifi\_manager\_is\_connected**](#function-wifi_manager_is_connected) (void) <br>_Check whether WiFi is currently connected._  |
|  esp\_err\_t | [**wifi\_manager\_wait\_connected**](#function-wifi_manager_wait_connected) (void) <br>_Block until WiFi connection is established._  |




























## Public Functions Documentation




### function wifi\_manager\_init 

_Initialize the WiFi manager and start connection._ 
```
esp_err_t wifi_manager_init (
    wifi_manager_config_t * config
) 
```



This function initializes:
* NVS storage
* network interface
* WiFi driver
* event handlers




The WiFi connection process is started immediately.




**Parameters:**


* `config` Pointer to configuration structure.



**Returns:**


* ESP\_OK on success
* ESP\_ERR\_INVALID\_ARG if config is invalid
* Other ESP-IDF error codes on failure 







        

<hr>



### function wifi\_manager\_is\_connected 

_Check whether WiFi is currently connected._ 
```
bool wifi_manager_is_connected (
    void
) 
```



This function can be called by other components to verify that the device still has network connectivity.




**Returns:**

true if connected to WiFi, false otherwise 





        

<hr>



### function wifi\_manager\_wait\_connected 

_Block until WiFi connection is established._ 
```
esp_err_t wifi_manager_wait_connected (
    void
) 
```



This function waits until the ESP32 receives an IP address from the access point.


Useful to ensure the network is ready before starting services such as:



* MQTT clients
* TCP servers
* UDP streaming
* HTTP requests






**Returns:**


* ESP\_OK if connection successful
* ESP\_FAIL if connection failed 







        

<hr>

------------------------------


