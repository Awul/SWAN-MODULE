

# Group SWANMQTT



[**Modules**](modules.md) **>** [**SWANMQTT**](group___s_w_a_n_m_q_t_t.md)




















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**swan\_mqtt\_config\_t**](structswan__mqtt__config__t.md) <br>_Configuration for MQTT client._  |






















## Public Functions

| Type | Name |
| ---: | :--- |
|  esp\_err\_t | [**swan\_mqtt\_client\_init**](#function-swan_mqtt_client_init) (const [**swan\_mqtt\_config\_t**](structswan__mqtt__config__t.md) \* config) <br>_Initialize the MQTT client and connect to broker._  |
|  bool | [**swan\_mqtt\_client\_is\_connected**](#function-swan_mqtt_client_is_connected) (void) <br>_Returns whether the client is connected._  |
|  esp\_err\_t | [**swan\_mqtt\_client\_publish**](#function-swan_mqtt_client_publish) (const char \* topic, const char \* payload, int qos, bool retain) <br>_Publish message to a topic._  |




























## Public Functions Documentation




### function swan\_mqtt\_client\_init 

_Initialize the MQTT client and connect to broker._ 
```
esp_err_t swan_mqtt_client_init (
    const swan_mqtt_config_t * config
) 
```





**Parameters:**


* `config` Pointer to configuration struct 



**Returns:**

ESP\_OK if client started successfully, otherwise error code 





        

<hr>



### function swan\_mqtt\_client\_is\_connected 

_Returns whether the client is connected._ 
```
bool swan_mqtt_client_is_connected (
    void
) 
```




<hr>



### function swan\_mqtt\_client\_publish 

_Publish message to a topic._ 
```
esp_err_t swan_mqtt_client_publish (
    const char * topic,
    const char * payload,
    int qos,
    bool retain
) 
```





**Parameters:**


* `topic` MQTT topic string 
* `payload` Message payload 
* `qos` Quality of service (0 or 1) 
* `retain` Retain flag 



**Returns:**

ESP\_OK on success, ESP\_FAIL otherwise 





        

<hr>

------------------------------


