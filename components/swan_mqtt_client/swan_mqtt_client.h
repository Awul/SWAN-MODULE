/**
 * @file swan_mqtt_client.h
 * @brief Simple MQTT client wrapper for ESP-IDF
 * 
 * This component provides a minimal interface to connect to an MQTT broker and publish messages.
 * It uses the ESP-IDF MQTT client under the hood and handles connection management.
 */
#pragma once
#include "esp_err.h"
#include <stdbool.h>

/**
 * @defgroup SWANMQTT SWAN MQTT Client
 * @{
 */

/**
 * @brief Configuration for MQTT client
 */
typedef struct {
    const char *broker_uri;  /**< Broker URI, e.g. "mqtt://192.168.1.100" */
    const char *client_id;   /**< MQTT client ID */
    const char *username;    /**< Optional username */
    const char *password;    /**< Optional password */
} swan_mqtt_config_t;

/**
 * @brief Initialize the MQTT client and connect to broker.
 *
 * @param config Pointer to configuration struct
 * @return ESP_OK if client started successfully, otherwise error code
 */
esp_err_t swan_mqtt_client_init(const swan_mqtt_config_t *config);

/**
 * @brief Publish message to a topic
 *
 * @param topic MQTT topic string
 * @param payload Message payload
 * @param qos Quality of service (0 or 1)
 * @param retain Retain flag
 * @return ESP_OK on success, ESP_FAIL otherwise
 */
esp_err_t swan_mqtt_client_publish(const char *topic,
                                   const char *payload,
                                   int qos,
                                   bool retain);

/**
 * @brief Returns whether the client is connected
 */
bool swan_mqtt_client_is_connected(void);

/** @} */