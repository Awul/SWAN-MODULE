/**
 * @file sht40.h
 * @brief Driver for SHT40 temperature & humidity sensor
 * 
 * This driver provides basic initialization, measurement reading, and serial number retrieval for the SHT40 sensor using the ESP-IDF I2C master driver.
 * 
 * Datasheet:
 * Sensirion SHT40, Version 7.1 March 2025
 */

#pragma once
#include "driver/i2c.h"
#include "esp_err.h"

/**
 * @brief SHT40 I2C default address
 */
#define SHT40_I2C_ADDR_DEFAULT 0x44

/**
 * @brief Delay in milliseconds between write and read operations
 */
#define READ_WRITE_DELAY_MS 4

/**
 * @brief SHT40 commands
 */
typedef enum {
    SHT40_CMD_MEASURE_HIGHREP               = 0xFD, /**< Measure T & RH, high repeatability, clock stretching disabled */
    SHT40_CMD_MEASURE_MEDREP                = 0xF6, /**< Measure T & RH, medium repeatability */
    SHT40_CMD_MEASURE_LOWREP                = 0xE0, /**< Measure T & RH, low repeatability */
    SHT40_CMD_READ_SERIAL                   = 0x89, /**< Read device serial number */
    SHT40_CMD_SOFT_RESET                    = 0x94, /**< Soft reset command */
    SHT40_CMD_ACTIVATE_HEATER_HIGH_LONG     = 0x39, /**< Activate heater for 1 second at high power (200mW)*/
    SHT40_CMD_ACTIVATE_HEATER_HIGH_SHORT    = 0x32, /**< Activate heater for 0.1 second at high power (200mW) */
    SHT40_CMD_ACTIVATE_HEATER_LOW_LONG      = 0x1E, /**< Activate heater for 1 second at low power (20mW) */
    SHT40_CMD_ACTIVATE_HEATER_LOW_SHORT     = 0x15  /**< Activate heater for 0.1 second at low power (20mW) */
} sht40_cmd_t;

/**
 * @brief SHT40 device structure
 */
typedef struct {
    i2c_port_t i2c_port;  /**< I2C port */
    uint8_t i2c_addr;     /**< Device I2C address */
} sht40_t;

/**
 * @brief Initialize SHT40 device
 * @param dev Pointer to sht40_t struct
 * @param i2c_port I2C port number
 * @param addr I2C device address
 * @return ESP_OK on success
 */
esp_err_t sht40_init(sht40_t *dev, i2c_port_t i2c_port, uint8_t addr);

/**
 * @brief Soft reset the SHT40
 * @param dev Pointer to sht40_t struct
 * @return ESP_OK on success
 */
esp_err_t sht40_reset(sht40_t *dev);

/**
 * @brief Read temperature and humidity
 * @param dev Pointer to sht40_t struct
 * @param temperature Pointer to float to store temperature (°C)
 * @param humidity Pointer to float to store relative humidity (%RH)
 * @return ESP_OK on success
 */
esp_err_t sht40_read_temp_humidity(sht40_t *dev, float *temperature, float *humidity);

/**
 * @brief Read serial number
 * @param dev Pointer to sht40_t struct
 * @param serial Pointer to 32-bit variable to store serial number
 * @return ESP_OK on success
 */
esp_err_t sht40_read_serial(sht40_t *dev, uint32_t *serial);

/**
 * @brief Enable or disable the heater
 * 
 * @param dev Pointer to sht40_t structure
 * @return ESP_OK on success
 */
esp_err_t sht40_activate_heater(sht40_t *dev);

static esp_err_t sht40_send_cmd(sht40_t *dev, uint16_t cmd);