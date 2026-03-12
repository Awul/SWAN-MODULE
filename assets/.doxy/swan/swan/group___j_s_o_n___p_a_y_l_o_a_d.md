

# Group JSON\_PAYLOAD



[**Modules**](modules.md) **>** [**JSON\_PAYLOAD**](group___j_s_o_n___p_a_y_l_o_a_d.md)




















## Classes

| Type | Name |
| ---: | :--- |
| struct | [**heartbeat\_info\_t**](structheartbeat__info__t.md) <br>_Information structure for heartbeat messages._  |






















## Public Functions

| Type | Name |
| ---: | :--- |
|  cJSON \* | [**build\_heartbeat\_json**](#function-build_heartbeat_json) (const [**heartbeat\_info\_t**](structheartbeat__info__t.md) \* info) <br>_Create a heartbeat JSON object._  |
|  cJSON \* | [**build\_sensor\_json**](#function-build_sensor_json) (const char \* value\_str) <br>_Create a sensor value JSON object._  |




























## Public Functions Documentation




### function build\_heartbeat\_json 

_Create a heartbeat JSON object._ 
```
cJSON * build_heartbeat_json (
    const heartbeat_info_t * info
) 
```



It has the structure: 
```
{
             "firmware": firmare_version,
             "uptime": uptime_seconds,
             "sensors": ["Sensor1", "Sensor2", "..."]
         }
```





**Parameters:**


* `info` Pointer to the heartbeat information structure 



**Returns:**

Pointer to the created JSON object, or NULL on failure 





        

<hr>



### function build\_sensor\_json 

_Create a sensor value JSON object._ 
```
cJSON * build_sensor_json (
    const char * value_str
) 
```





**Parameters:**


* `value_str` String representation of the sensor value 



**Returns:**

Pointer to the created JSON object, or NULL on failure 





        

<hr>

------------------------------


