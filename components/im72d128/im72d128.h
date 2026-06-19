#ifndef IM72D128_H
#define IM72D128_H
/** 
 * @file im72d128.h
 * @brief Driver for the IM72D128 PDM microphone
 * 
 * This driver provides initialization and audio reading functions
 * for the IM72D128 PDM microphone using the ESP-IDF I2S peripheral in PDM receive mode.
 */

#include "driver/i2s_pdm.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "esp_err.h"

/**
 * @defgroup IM72D128 IM72D128 PDM Microphone
 * @{
 */

/**
 * @brief PDM microphone pins
 */
#define MIC_CLK_PIN  GPIO_NUM_5
#define MIC_DATA_PIN GPIO_NUM_4


/**
 * @brief IM72D128 microphone configuration structure
 */
typedef struct {
    i2s_chan_handle_t rx_handle;
    gpio_num_t clk_pin;
    gpio_num_t data_pin;
    uint32_t sample_rate;
} im72d128_t;


/**
 * @brief Initialize IM72D128 microphone
 *
 * Configures the ESP32 I2S peripheral in PDM receive mode.
 *
 * @param mic Pointer to microphone structure
 * @param port I2S port (I2S_NUM_0 or I2S_NUM_1)
 * @param clk_pin GPIO used for PDM clock
 * @param data_pin GPIO used for microphone data
 * @param sample_rate Desired PCM sample rate
 *
 * @return ESP_OK on success
 */
esp_err_t im72d128_init(im72d128_t *mic,
                        i2s_port_t port,
                        gpio_num_t clk_pin,
                        gpio_num_t data_pin,
                        uint32_t sample_rate);


/**
 * @brief Read PCM audio samples
 *
 * Reads audio samples converted from the PDM microphone.
 *
 * @param mic Pointer to microphone structure
 * @param buffer Pointer to sample buffer (32 bit here)
 * @param samples Number of samples to read
 * @param bytes_read Optional pointer returning bytes read
 * @param gain Optional gain setting, set 1 for skipping gain
 *
 * @return ESP_OK on success
 */
esp_err_t im72d128_read(im72d128_t *mic,
                        int16_t *buffer,
                        size_t samples,
                        size_t *bytes_read,
                        uint8_t gain);




/** @} */

#endif // IM72D128_H