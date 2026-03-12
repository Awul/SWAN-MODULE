/**
 * 
 * @file json_payload.h
 * @brief Utility functions for building JSON payloads for MQTT messages
 * 
 * This component provides helper functions to construct JSON objects for
 * heartbeat messages and sensor data, using the cJSON library.
 * 
 * Have fun.
 */

#pragma once
#include <stdbool.h>
#include "cJSON.h"
#include <stdio.h>

/**
 * @defgroup JSON_PAYLOAD JSON Payload Builder
 * @{
 */

/**
 * @brief Information structure for heartbeat messages
 */
typedef struct {
    const char* firmware;   // firmware version
    uint32_t uptime;        // seconds since boot
    const char** sensors;  // array of sensor names
    size_t sensor_count;    // number of sensors in the array
} heartbeat_info_t;

/**
 * @brief Create a heartbeat JSON object
 * @param info Pointer to the heartbeat information structure
 * @return Pointer to the created JSON object, or NULL on failure
 */
cJSON* build_heartbeat_json(const heartbeat_info_t* info);

/**
 * @brief Create a sensor value JSON object
 * @param value_str String representation of the sensor value
 * @return Pointer to the created JSON object, or NULL on failure
 */
cJSON* build_sensor_json(const char* value_str);

/** @} */