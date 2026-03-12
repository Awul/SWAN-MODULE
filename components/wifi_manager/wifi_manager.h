/**
 * @file wifi_manager.h
 * @brief Simple WiFi station manager for ESP-IDF.
 *
 * This component provides a minimal interface to connect an ESP32
 * to an existing WiFi network (station mode).
 *
 * It handles:
 *  - WiFi driver initialization
 *  - connection to an access point
 *  - automatic reconnection
 *  - IP acquisition
 *  - connection status tracking
 *
 * Typical usage:
 *
 * @code
 * wifi_manager_config_t cfg = {
 *     .ssid = "MyNetwork",
 *     .password = "password123"
 * };
 *
 * wifi_manager_init(&cfg);
 * wifi_manager_wait_connected();
 *
 * // Safe to start MQTT, sockets, streaming, etc.
 * @endcode
 */



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

/**
 * @defgroup WIFI_MANAGER WiFi Manager
 * @{
 */

/**
 * @brief WiFi configuration parameters.
 */
typedef struct
{
    /** WiFi SSID (network name) */
    const char *ssid;

    /** WiFi password */
    const char *password;

} wifi_manager_config_t;


/**
 * @brief Initialize the WiFi manager and start connection.
 *
 * This function initializes:
 *  - NVS storage
 *  - network interface
 *  - WiFi driver
 *  - event handlers
 *
 * The WiFi connection process is started immediately.
 *
 * @param config Pointer to configuration structure.
 *
 * @return
 *      - ESP_OK on success
 *      - ESP_ERR_INVALID_ARG if config is invalid
 *      - Other ESP-IDF error codes on failure
 */
esp_err_t wifi_manager_init(wifi_manager_config_t *config);


/**
 * @brief Block until WiFi connection is established.
 *
 * This function waits until the ESP32 receives an IP address
 * from the access point.
 *
 * Useful to ensure the network is ready before starting
 * services such as:
 *
 *  - MQTT clients
 *  - TCP servers
 *  - UDP streaming
 *  - HTTP requests
 *
 * @return
 *      - ESP_OK if connection successful
 *      - ESP_FAIL if connection failed
 */
esp_err_t wifi_manager_wait_connected(void);


/**
 * @brief Check whether WiFi is currently connected.
 *
 * This function can be called by other components to verify
 * that the device still has network connectivity.
 *
 * @return true if connected to WiFi, false otherwise
 */
bool wifi_manager_is_connected(void);

/** @} */