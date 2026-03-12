#include "swan_mqtt_client.h"
#include "esp_log.h"
#include "mqtt_client.h"
#include "esp_event.h"

static const char *TAG = "SWAN_MQTT";
static esp_mqtt_client_handle_t client = NULL;
static bool mqtt_connected = false;

/* MQTT event handler */
static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    esp_mqtt_event_handle_t event = event_data;

    switch (event->event_id) {
        case MQTT_EVENT_CONNECTED:
            ESP_LOGI(TAG, "MQTT connected");
            mqtt_connected = true;
            break;
        case MQTT_EVENT_DISCONNECTED:
            ESP_LOGW(TAG, "MQTT disconnected");
            mqtt_connected = false;
            break;
        case MQTT_EVENT_PUBLISHED:
            ESP_LOGD(TAG, "Message published, msg_id=%d", event->msg_id);
            break;
        case MQTT_EVENT_ERROR:
            ESP_LOGE(TAG, "MQTT error");
            mqtt_connected = false;
            break;
        default:
            break;
    }
}

esp_err_t swan_mqtt_client_init(const swan_mqtt_config_t *config)
{
    if (!config || !config->broker_uri) {
        return ESP_ERR_INVALID_ARG;
    }

    const esp_mqtt_client_config_t mqtt_cfg = {
        .broker.address.uri = config->broker_uri,
        .credentials.username = config->username,
        .credentials.authentication.password = config->password,
    };

    client = esp_mqtt_client_init(&mqtt_cfg);

    if (!client) {
        ESP_LOGE(TAG, "Failed to init MQTT client");
        return ESP_FAIL;
    }

    esp_mqtt_client_register_event(client, ESP_EVENT_ANY_ID, mqtt_event_handler, NULL);

    esp_err_t err = esp_mqtt_client_start(client);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to start MQTT client: %d", err);
        return err;
    }

    return ESP_OK;
}

esp_err_t swan_mqtt_client_publish(const char *topic,
                                   const char *payload,
                                   int qos,
                                   bool retain)
{
    if (!client || !mqtt_connected || !topic || !payload) {
        return ESP_FAIL;
    }

    int msg_id = esp_mqtt_client_publish(client, topic, payload, 0, qos, retain);
    if (msg_id < 0) {
        ESP_LOGE(TAG, "Failed to publish to %s", topic);
        return ESP_FAIL;
    }
    return ESP_OK;
}

bool swan_mqtt_client_is_connected(void)
{
    return mqtt_connected;
}