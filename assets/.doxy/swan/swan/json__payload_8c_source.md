

# File json\_payload.c

[**File List**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**json\_payload**](dir_8c609162cce0e03ddff604c565ee243e.md) **>** [**json\_payload.c**](json__payload_8c.md)

[Go to the documentation of this file](json__payload_8c.md)


```C++
#include "json_payload.h"


cJSON* build_heartbeat_json(const heartbeat_info_t* info) {
    if (!info) return NULL;

    cJSON* root = cJSON_CreateObject();
    if (!root) return NULL;

    cJSON_AddStringToObject(root, "firmware", info->firmware);
    cJSON_AddNumberToObject(root, "uptime", info->uptime);

    cJSON* sensors_array = cJSON_CreateArray();
    if (!sensors_array) {
        cJSON_Delete(root);
        return NULL;
    }

    for (size_t i = 0; i < info->sensor_count; i++) {
        cJSON_AddItemToArray(sensors_array, cJSON_CreateString(info->sensors[i]));
    }

    cJSON_AddItemToObject(root, "sensors", sensors_array);

    return root;
}

cJSON* build_sensor_json(const char* value_str) {
    if (!value_str) return NULL;

    cJSON* root = cJSON_CreateObject();

    cJSON_AddStringToObject(root, "value", value_str);

    return root;
}
```


