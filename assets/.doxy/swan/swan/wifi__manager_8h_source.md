

# File wifi\_manager.h

[**File List**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**wifi\_manager**](dir_fe90acb48b1d14dd9ed13ebfae9d32ea.md) **>** [**wifi\_manager.h**](wifi__manager_8h.md)

[Go to the documentation of this file](wifi__manager_8h.md)


```C++




#include <stdbool.h>
#include "esp_err.h"


#include <string.h>

#include "esp_wifi.h"
#include "esp_log.h"
#include "esp_event.h"
#include "esp_netif.h"
#include "nvs_flash.h"


#include "freertos/FreeRTOS.h"
#include "freertos/event_groups.h"


typedef struct
{
    const char *ssid;

    const char *password;

} wifi_manager_config_t;


esp_err_t wifi_manager_init(wifi_manager_config_t *config);


esp_err_t wifi_manager_wait_connected(void);


bool wifi_manager_is_connected(void);

```


