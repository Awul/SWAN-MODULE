#include "swan_mqtt_client.h"
#include "esp_log.h"
#include "mqtt_client.h"
#include "esp_event.h"

static const char *TAG = "SWAN_MQTT";
static esp_mqtt_client_handle_t client = NULL;
static bool mqtt_connected = false;

// Storing the command callback
static mqtt_command_cb_t command_cb = NULL;

/* MQTT event handler */
static void mqtt_event_handler(void *handler_args, esp_event_base_t base, int32_t event_id, void *event_data)
{
    esp_mqtt_event_handle_t event = event_data;

    switch (event->event_id) {
        case MQTT_EVENT_CONNECTED:
            ESP_LOGI(TAG, "MQTT connected");
            mqtt_connected = true;
            // Subscribe to the command topic
            esp_mqtt_client_subscribe(client, "swan-hub/command/#", 0);
            ESP_LOGI(TAG, "MQTT subscribed to command topic (swan-hub/command/#)");
            break;
        case MQTT_EVENT_DISCONNECTED:
            ESP_LOGW(TAG, "MQTT disconnected");
            mqtt_connected = false;
            break;
        case MQTT_EVENT_SUBSCRIBED:
            ESP_LOGI(TAG, "Subscribed, msg_id=%d", event->msg_id);
            break;
        case MQTT_EVENT_PUBLISHED:
            ESP_LOGD(TAG, "Message published, msg_id=%d", event->msg_id);
            break;
        case MQTT_EVENT_ERROR:
            ESP_LOGE(TAG, "MQTT error");
            mqtt_connected = false;
            break;
        case MQTT_EVENT_DATA:
        {   // Read the topic and payload from the event
            char topic[event->topic_len + 1];
            char data[event->data_len + 1];

            // Copy topic and payload to null-terminated strings
            memcpy(topic, event->topic, event->topic_len);
            topic[event->topic_len] = '\0';
            
            memcpy(data, event->data, event->data_len);
            data[event->data_len] = '\0';
            
            ESP_LOGD(TAG, "Message received, topic=%s, data=%s", topic, data);
            if (command_cb) {
                // Forward the message to the registered command callback
                command_cb(topic, data);
            }
            break;
        }
        case MQTT_EVENT_UNSUBSCRIBED:
        case MQTT_EVENT_BEFORE_CONNECT:
        case MQTT_EVENT_DELETED:
        case MQTT_EVENT_ANY:
        case MQTT_USER_EVENT:
        default:
            ESP_LOGW(TAG, "MQTT unknown event_id=%d handler", event->event_id);
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


// Here the function is registered to handle incoming mqtt topics, in this architecture main is responsible for this
// Please hit me with a PR if you disagree.
esp_err_t swan_mqtt_client_register_command_callback(mqtt_command_cb_t cb) {
    command_cb = cb;
    return ESP_OK;
}