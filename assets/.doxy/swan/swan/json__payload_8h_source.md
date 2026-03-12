

# File json\_payload.h

[**File List**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**json\_payload**](dir_8c609162cce0e03ddff604c565ee243e.md) **>** [**json\_payload.h**](json__payload_8h.md)

[Go to the documentation of this file](json__payload_8h.md)


```C++


#pragma once
#include <stdbool.h>
#include "cJSON.h"
#include <stdio.h>


typedef struct {
    const char* firmware;   // firmware version
    uint32_t uptime;        // seconds since boot
    const char** sensors;  // array of sensor names
    size_t sensor_count;    // number of sensors in the array
} heartbeat_info_t;

cJSON* build_heartbeat_json(const heartbeat_info_t* info);

cJSON* build_sensor_json(const char* value_str);

```


