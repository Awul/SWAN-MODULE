#include "sht40.h"


static const char *TAG = "SHT40";

#define SHT40_I2C_TIMEOUT pdMS_TO_TICKS(250)

/**
 * @brief Initialize SHT40 device
 * 
 * Sets I2C port and address, then performs a soft reset.
 * 
 * @param dev Pointer to sht40_t struct
 * @param i2c_port I2C port number
 * @param addr I2C device address
 * @return ESP_OK on success, error code otherwise
 */
esp_err_t sht40_init(sht40_t *dev, i2c_port_t i2c_port, uint8_t addr)
{
    if (!dev) return ESP_ERR_INVALID_ARG;

    // Set the cool I2C port and address in the device struct
    dev->i2c_port = i2c_port;
    dev->i2c_addr = addr;

    ESP_LOGI(TAG, "Initializing SHT40 at 0x%02X on I2C port %d", addr, i2c_port);
    esp_err_t err = sht40_reset(dev);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to reset SHT40 (err=%d)", err);
    } else {
        ESP_LOGI(TAG, "SHT40 reset successful");
    }

    //wait READ_WRITE_DELAY_MS after init reset
    vTaskDelay(pdMS_TO_TICKS(READ_WRITE_DELAY_MS)); 
    return err;
}

/**
 * @brief Soft reset the SHT40 sensor
 * 
 * @param dev Pointer to sht40_t struct
 * @return ESP_OK on success
 */
esp_err_t sht40_reset(sht40_t *dev)
{
    uint8_t cmd = SHT40_CMD_SOFT_RESET;
    ESP_LOGI(TAG, "Sending soft reset command: 0x%02X", cmd);

    esp_err_t err = i2c_bus_lock(SHT40_I2C_TIMEOUT);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to lock I2C bus for soft reset (err=%d)", err);
        return err;
    }

    err = i2c_master_write_to_device(dev->i2c_port, dev->i2c_addr, &cmd, 1, pdMS_TO_TICKS(100));
    i2c_bus_unlock();

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Soft reset failed (err=%d)", err);
    }
    return err;
}

/**
 * @brief Read temperature (°C) and humidity (%RH) from SHT40
 * 
 * Uses high repeatability measurement by default.
 * 
 * @param dev Pointer to sht40_t struct
 * @param temperature Pointer to float to store temperature
 * @param humidity Pointer to float to store relative humidity
 * @return ESP_OK on success
 */
esp_err_t sht40_read_temp_humidity(sht40_t *dev, float *temperature, float *humidity)
{
    if (!dev || !temperature || !humidity) return ESP_ERR_INVALID_ARG;

    uint8_t cmd = SHT40_CMD_MEASURE_HIGHREP;
    uint8_t data[6] = {0};

    ESP_LOGI(TAG, "Starting high repeatability measurement: 0x%02X", cmd);

    esp_err_t err = i2c_bus_lock(SHT40_I2C_TIMEOUT);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to lock I2C bus for measurement (err=%d)", err);
        return err;
    }

    err = i2c_master_write_to_device(
        dev->i2c_port,
        dev->i2c_addr,
        &cmd,
        1,
        pdMS_TO_TICKS(100)
        );

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Writing measurement command failed (err=%d)", err);
        i2c_bus_unlock();
        return err;
    }

    ESP_LOGD(TAG, "Waiting READ_WRITE_DELAY_MS for SHT40 to prepare serial number...");
    // Step 2: wait READ_WRITE_DELAY_MS for sensor to prepare the measurement
    vTaskDelay(pdMS_TO_TICKS(READ_WRITE_DELAY_MS));

    err = i2c_master_read_from_device(
        dev->i2c_port,
        dev->i2c_addr,
        data,
        sizeof(data),
        pdMS_TO_TICKS(100)
        );

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to read temperature and humidity (err=%d)", err);
        i2c_bus_unlock();
        return err;
    }

    i2c_bus_unlock();

    uint16_t raw_temp = (data[0] << 8) | data[1];
    uint16_t raw_hum  = (data[3] << 8) | data[4];

    *temperature = -45.0f + 175.0f * ((float)raw_temp / 65535.0f);
    *humidity    = 100.0f * ((float)raw_hum / 65535.0f);

    ESP_LOGD(TAG, "Temperature: %.2f °C, Humidity: %.2f %%RH", *temperature, *humidity);

    ESP_LOGD(TAG, "Waiting READ_WRITE_DELAY_MS after reading temperature and humidity...");
    vTaskDelay(pdMS_TO_TICKS(READ_WRITE_DELAY_MS));

    return ESP_OK;
}

/**
 * @brief Read 32-bit serial number of SHT40
 * 
 * @param dev Pointer to sht40_t struct
 * @param serial Pointer to store serial number
 * @return ESP_OK on success
 */
esp_err_t sht40_read_serial(sht40_t *dev, uint32_t *serial)
{
    if (!dev || !serial) return ESP_ERR_INVALID_ARG;

    uint8_t cmd = SHT40_CMD_READ_SERIAL;
    uint8_t data[6];

    ESP_LOGI(TAG, "Reading serial number with command: 0x%02X", cmd);

    esp_err_t err = i2c_bus_lock(SHT40_I2C_TIMEOUT);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to lock I2C bus for serial read (err=%d)", err);
        return err;
    }

    // Write command
    err = i2c_master_write_to_device(
        dev->i2c_port,
         dev->i2c_addr,
          &cmd,
          1,
          pdMS_TO_TICKS(100)
        );

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to send serial command (err=%d)", err);
        i2c_bus_unlock();
        return err;
    }

    ESP_LOGD(TAG, "Waiting READ_WRITE_DELAY_MS for SHT40 to prepare serial number...");
    // wait READ_WRITE_DELAY_MS for sensor to prepare the serial
    vTaskDelay(pdMS_TO_TICKS(READ_WRITE_DELAY_MS));

    // read 6 bytes
    err = i2c_master_read_from_device(
        dev->i2c_port,
         dev->i2c_addr,
          data,
          sizeof(data),
          pdMS_TO_TICKS(100)
        );

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to read serial number (err=%d)", err);
        i2c_bus_unlock();
        return err;
    }

    i2c_bus_unlock();

    // Sensirion uses data[0..1] + data[3..4] for serial
    *serial = ((uint32_t)data[0] << 24) | ((uint32_t)data[1] << 16) |
              ((uint32_t)data[3] << 8)  | ((uint32_t)data[4]);

    ESP_LOGI(TAG, "SHT40 Serial number read successfully: 0x%08X", *serial);

    ESP_LOGD(TAG, "Waiting READ_WRITE_DELAY_MS after reading serial number...");
    vTaskDelay(pdMS_TO_TICKS(READ_WRITE_DELAY_MS));

    return ESP_OK;
}

/**
 * @brief Activate the SHT40 heater
 * 
 * Heater is mainly for anti-condensation. Should not be used during measurement.
 * Heater commands are defined in the sht40_cmd_t enum. This function uses the high power long duration command.
 * 
 * @param dev Pointer to sht40_t struct
 * @return ESP_OK on success
 */
esp_err_t sht40_activate_heater(sht40_t *dev)
{
    if (!dev) return ESP_ERR_INVALID_ARG;

    uint8_t cmd = SHT40_CMD_ACTIVATE_HEATER_HIGH_LONG; // Turn on heater for 1 second at high power
    ESP_LOGI(TAG, "Turning heater ON: 0x%02X", cmd);

    esp_err_t err = sht40_send_cmd(dev, cmd);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to activate heater (err=%d)", err);
    }
    return err;
}

/* Internal helper to send commands */
// implemented this later, so it is not used everywhere yet.
esp_err_t sht40_send_cmd(sht40_t *dev, uint8_t cmd)
{
    esp_err_t err = i2c_bus_lock(SHT40_I2C_TIMEOUT);
    if (err != ESP_OK) {
        return err;
    }

    err = i2c_master_write_to_device(
        dev->i2c_port,
        dev->i2c_addr,
        &cmd,
        1,
        pdMS_TO_TICKS(100)
        );

    i2c_bus_unlock();
    return err;
}
