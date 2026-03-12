

# File swan\_mqtt\_client.h

[**File List**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**swan\_mqtt\_client**](dir_549ee75ff438e1a8fde58d8b9df43ea6.md) **>** [**swan\_mqtt\_client.h**](swan__mqtt__client_8h.md)

[Go to the documentation of this file](swan__mqtt__client_8h.md)


```C++

#pragma once
#include "esp_err.h"
#include <stdbool.h>


typedef struct {
    const char *broker_uri;  
    const char *client_id;   
    const char *username;    
    const char *password;    
} swan_mqtt_config_t;

esp_err_t swan_mqtt_client_init(const swan_mqtt_config_t *config);

esp_err_t swan_mqtt_client_publish(const char *topic,
                                   const char *payload,
                                   int qos,
                                   bool retain);

bool swan_mqtt_client_is_connected(void);

```


