

# File wifi\_manager.c

[**File List**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**wifi\_manager**](dir_fe90acb48b1d14dd9ed13ebfae9d32ea.md) **>** [**wifi\_manager.c**](wifi__manager_8c.md)

[Go to the documentation of this file](wifi__manager_8c.md)


```C++
#include "wifi_manager.h"


static const char *TAG = "wifi_manager";

/* Event group bits */
#define WIFI_CONNECTED_BIT BIT0
#define WIFI_FAIL_BIT      BIT1

/* Maximum number of reconnection attempts */
#define WIFI_MAX_RETRY 5

static EventGroupHandle_t wifi_event_group;
static int retry_count = 0;
static bool wifi_connected = false;


static void event_handler(void *arg,
                          esp_event_base_t event_base,
                          int32_t event_id,
                          void *event_data)
{
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START)
    {
        ESP_LOGI(TAG, "Connecting to WiFi...");
        esp_wifi_connect();
    }

    else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED)
    {
        wifi_connected = false;

        if (retry_count < WIFI_MAX_RETRY)
        {
            esp_wifi_connect();
            retry_count++;

            ESP_LOGW(TAG, "WiFi disconnected, retry %d/%d",
                     retry_count, WIFI_MAX_RETRY);
        }
        else
        {
            xEventGroupSetBits(wifi_event_group, WIFI_FAIL_BIT);
        }
    }

    else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP)
    {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;

        ESP_LOGI(TAG, "Got IP address: " IPSTR,
                 IP2STR(&event->ip_info.ip));

        retry_count = 0;
        wifi_connected = true;

        xEventGroupSetBits(wifi_event_group, WIFI_CONNECTED_BIT);
    }
}


esp_err_t wifi_manager_init(wifi_manager_config_t *config)
{
    if (!config || !config->ssid)
    {
        return ESP_ERR_INVALID_ARG;
    }

    wifi_event_group = xEventGroupCreate();

    ESP_ERROR_CHECK(nvs_flash_init());

    ESP_ERROR_CHECK(esp_netif_init());

    ESP_ERROR_CHECK(esp_event_loop_create_default());

    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();

    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    /* Register event handlers */

    ESP_ERROR_CHECK(
        esp_event_handler_register(WIFI_EVENT,
                                   ESP_EVENT_ANY_ID,
                                   &event_handler,
                                   NULL));

    ESP_ERROR_CHECK(
        esp_event_handler_register(IP_EVENT,
                                   IP_EVENT_STA_GOT_IP,
                                   &event_handler,
                                   NULL));

    /* Configure WiFi credentials */

    wifi_config_t wifi_config = {0};

    strncpy((char *)wifi_config.sta.ssid,
            config->ssid,
            sizeof(wifi_config.sta.ssid));

    strncpy((char *)wifi_config.sta.password,
            config->password,
            sizeof(wifi_config.sta.password));

    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));

    ESP_ERROR_CHECK(
        esp_wifi_set_config(WIFI_IF_STA, &wifi_config));

    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI(TAG, "WiFi manager initialized");

    return ESP_OK;
}


esp_err_t wifi_manager_wait_connected(void)
{
    EventBits_t bits = xEventGroupWaitBits(
        wifi_event_group,
        WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
        pdFALSE,
        pdFALSE,
        portMAX_DELAY);

    if (bits & WIFI_CONNECTED_BIT)
    {
        ESP_LOGI(TAG, "WiFi connected");
        return ESP_OK;
    }
    else
    {
        ESP_LOGE(TAG, "WiFi connection failed");
        return ESP_FAIL;
    }
}


bool wifi_manager_is_connected(void)
{
    return wifi_connected;
}
```


