/**
 * @file veml7700.h
 * @brief Driver for the Vishay VEML7700 ambient light sensor
 *
 * This driver provides basic initialization, register access,
 * measurement reading, and diagnostic utilities for the VEML7700
 * ambient light sensor using the ESP-IDF I2C master driver.
 *
 * Datasheet:
 * Vishay Semiconductors VEML7700, Rev. 1.8 (28-Nov-2024)
 */

#pragma once

#include "i2c_bus.h"
#include "esp_err.h"
#include "esp_log.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/**
 * @defgroup veml7700 VEML7700 Ambient Light Sensor
 * @{
 */


/** @brief ALS configuration register */
#define VEML7700_REG_ALS_CONF_0      0x00
/** @brief ALS high threshold window */
#define VEML7700_REG_ALS_WH          0x01
/** @brief ALS low threshold window */
#define VEML7700_REG_ALS_WL          0x02
/** @brief Power saving mode register */
#define VEML7700_REG_POWER_SAVING    0x03
/** @brief ALS measurement output */
#define VEML7700_REG_ALS             0x04
/** @brief White channel measurement output */
#define VEML7700_REG_WHITE           0x05
/** @brief Interrupt status register */
#define VEML7700_REG_ALS_INT         0x06
/** @brief Device ID register */
#define VEML7700_REG_ID              0x07

/** @brief VEML7700 I2C address
 *
 * The VEML7700 has a fixed 7-bit I2C address of 0x10. This is the default
 * address used by the driver, but it can be overridden in the device descriptor.
 */
#define VEML7700_I2C_ADDR_DEFAULT    0x10

/**
 * @brief VEML7700 device descriptor
 *
 * Holds the I²C configuration required to communicate with a VEML7700
 * instance. One struct instance corresponds to one sensor on the bus.
 */
typedef struct {
    i2c_port_t i2c_port;   /**< I²C port used by the sensor */
    uint8_t    i2c_addr;   /**< 7-bit I²C address of the sensor */
} veml7700_t;

/**
 * @brief Initialize the VEML7700 sensor
 *
 * Powers on the sensor and applies a default ALS configuration
 * (Gain = 1×, Integration Time = 100 ms).
 *
 * @param[out] dev   Pointer to a VEML7700 device descriptor
 * @param[in]  port  I²C port on which the sensor is connected
 *
 * @return
 * - ESP_OK on success
 * - ESP_FAIL or ESP_ERR_* on I²C communication error
 */
esp_err_t veml7700_init(veml7700_t *dev, i2c_port_t port);

/**
 * @brief Read raw ALS (ambient light sensor) counts
 *
 * Reads the raw 16-bit ALS register value. This value is not converted
 * to physical units.
 *
 * @param[in]  dev  Pointer to initialized VEML7700 device descriptor
 * @param[out] als  Pointer to store the raw ALS value
 *
 * @return
 * - ESP_OK on success
 * - ESP_FAIL or ESP_ERR_* on I²C communication error
 */
esp_err_t veml7700_read_als(veml7700_t *dev, uint16_t *als);

/**
 * @brief Read ambient light in lux
 *
 * Reads the raw ALS value and converts it to lux using the current gain and integration time settings. The conversion factors are based on the VEML7700 datasheet and the helper functions for responsivity and gain factor.
 * The formula used is: lux = ALS_counts / gain_factor * responsivity
 *
 * @param[in]  dev  Pointer to initialized VEML7700 device descriptor
 * @param[out] lux  Pointer to store the calculated lux value
 *
 * @return
 * - ESP_OK on success
 * - ESP_FAIL or ESP_ERR_* on I²C communication error
 */
esp_err_t veml7700_read_lux(veml7700_t *dev, float *lux);

/**
 * @brief Gets the responsivity (lux/count) based on the integration time setting
 * 
 * The VEML7700's responsivity changes based on the integration time setting. This function calculates the lux/count factor for the current integration time configuration.
 * 
 * @param[in] it_bits The integration time bits extracted from the ALS_CONF_0 register
 * @return The responsivity in lux/count for the given integration time setting
 */
float veml7700_responsivity(uint8_t it_bits);

/**
 * @brief Gets the gain factor based on the gain setting
 * 
 * The VEML7700's gain setting affects the scaling of the ALS counts. This function returns the gain factor corresponding to the gain bits from the configuration register.
 * 
 * @param[in] gain_bits The gain bits extracted from the ALS_CONF_0 register
 * @return The gain factor (e.g., 1.0 for x1, 2.0 for x2, etc.) corresponding to the gain setting
 */
float veml7700_gain_factor(uint8_t gain_bits);

/**
 * @brief Print a full register dump and interpreted sensor status
 *
 * This function reads all registers (0x00–0x07) and prints:
 * - Raw register values
 * - Configuration decoding (gain, integration time, shutdown)
 * - Power saving status
 * - Interrupt flags
 * - Device ID interpretation
 *
 * Intended for debugging and sensor bring-up.
 *
 * @param[in] dev Pointer to VEML7700 device structure
 */
void veml7700_print_registers(const veml7700_t *dev);

/** @} */