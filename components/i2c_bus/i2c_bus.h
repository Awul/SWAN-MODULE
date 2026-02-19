/**
 * @file i2c_bus.h
 * @brief I2C Bus testing and utility module
 *
 * @defgroup I2C_BUS I2C Bus Module
 * This module provides initialization, status reporting, and scanning utilities for the I2C bus.
 * @{
 */

#pragma once
#include "esp_err.h"
#include "driver/i2c.h"

/**
 * @brief The I2C port used by the bus
 */
#define I2C_PORT I2C_NUM_0

/**
 * @brief Default I2C SDA Pin
 */
#define I2C_SDA  8       // Default SDA pin
/**
 * @brief Default I2C SCL Pin
 */
#define I2C_SCL  9       // Default SCL pin
/**
 * @brief Default I2C Frequency
 */
#define I2C_FREQ 100000  // Default I2C frequency (100 kHz)

/**
 * @brief Initialize the I2C bus
 *
 * Sets up the I2C peripheral with predefined SDA/SCL pins (8, 9) and frequency (100kHz).
 * Creates a mutex for thread-safe access.
 *
 * @return ESP_OK if bus initialized successfully
 * @return ESP_ERR_INVALID_ARG if configuration fails
 */
esp_err_t i2c_bus_init(void);

/**
 * @brief Print the current I2C bus status
 *
 * Logs whether the I2C bus is initialized and whether the mutex exists.
 * Useful for debugging and verifying proper initialization.
 */
void i2c_bus_status(void);

/**
 * @brief Scan the I2C bus for connected devices
 *
 * Attempts communication with all valid 7-bit I2C addresses (1–126) and logs
 * any devices that respond. Useful for detecting attached sensors.
 */
void i2c_scan(void);

/** @} */ // end of I2C_BUS group