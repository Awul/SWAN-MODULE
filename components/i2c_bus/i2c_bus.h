/**
 * @file i2c_bus.h
 * @brief Thread-safe I2C bus access for multiple sensors
 *
 * @defgroup I2C_BUS I2C Bus Module
 * This module provides a singleton I2C bus instance and
 * thread-safe functions to read/write over the bus.
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
 * @brief Perform a write/read operation on the I2C bus
 *
 * This function is mutex-protected to allow multiple sensors to safely
 * share the same I2C bus.
 *
 * @param addr The 7-bit I2C address of the device
 * @param write_buf Pointer to data to write (can be NULL if no write)
 * @param write_len Number of bytes to write
 * @param read_buf Pointer to buffer for read data (can be NULL if no read)
 * @param read_len Number of bytes to read
 * @param ticks_to_wait Maximum time to wait for bus access (FreeRTOS ticks)
 *
 * @return ESP_OK on success
 * @return ESP_ERR_TIMEOUT if mutex or bus timed out
 * @return Other ESP_ERR_* codes if I2C operation fails
 */
esp_err_t i2c_bus_write_read(uint8_t addr,
                             uint8_t *write_buf, size_t write_len,
                             uint8_t *read_buf, size_t read_len,
                             TickType_t ticks_to_wait);


/** @} */ // end of I2C_BUS group