

# File swan\_mqtt\_client.c



[**FileList**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**swan\_mqtt\_client**](dir_549ee75ff438e1a8fde58d8b9df43ea6.md) **>** [**swan\_mqtt\_client.c**](swan__mqtt__client_8c.md)

[Go to the source code of this file](swan__mqtt__client_8c_source.md)



* `#include "swan_mqtt_client.h"`
* `#include "esp_log.h"`
* `#include "mqtt_client.h"`
* `#include "esp_event.h"`























## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const char \* | [**TAG**](#variable-tag)   = `"SWAN\_MQTT"`<br> |
|  esp\_mqtt\_client\_handle\_t | [**client**](#variable-client)   = `NULL`<br> |
|  bool | [**mqtt\_connected**](#variable-mqtt_connected)   = `false`<br> |
















## Public Static Functions

| Type | Name |
| ---: | :--- |
|  void | [**mqtt\_event\_handler**](#function-mqtt_event_handler) (void \* handler\_args, esp\_event\_base\_t base, int32\_t event\_id, void \* event\_data) <br> |


























## Public Static Attributes Documentation




### variable TAG 

```C++
const char* TAG;
```




<hr>



### variable client 

```C++
esp_mqtt_client_handle_t client;
```




<hr>



### variable mqtt\_connected 

```C++
bool mqtt_connected;
```




<hr>
## Public Static Functions Documentation




### function mqtt\_event\_handler 

```C++
static void mqtt_event_handler (
    void * handler_args,
    esp_event_base_t base,
    int32_t event_id,
    void * event_data
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/SWAN-MODULE/components/swan_mqtt_client/swan_mqtt_client.c`

