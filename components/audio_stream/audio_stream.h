/**
 * @file audio_stream.h
 * @brief TCP audio streaming module for ESP32
 *
 * @defgroup AUDIO_STREAM Audio Stream Module
 * This module provides functionality for streaming audio over TCP.
 * @{
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include "esp_err.h"
#include "esp_log.h"
#include "lwip/sockets.h"
#include "esp_wifi.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "im72d128.h"
#include "string.h"
#include "freertos/queue.h"




/**
 * @brief Configuration for TCP audio streaming.
 */
typedef struct {
    const char *server_ip;      // Raspberry Pi IP
    uint16_t port;              // TCP port
    uint32_t sample_rate;       // e.g. 48000
    uint16_t frame_size;        // number of samples per frame (e.g. 256)
    uint16_t audio_queque_size; // Number of frames that can be queued for streaming
    im72d128_t *mic;            // Pointer to initialized microphone driver
} audio_stream_config_t;


// define the frame structure for audio streaming
/**
 * @brief Maximum samples per frame for audio streaming
 *  */  
#define MAX_FRAME_SAMPLES 256
#define MAX_QUEUE_SIZE 8
/**
 * @brief Audio frame structure for TCP streaming
 */
typedef struct __attribute__((packed)) {
    uint64_t tsf_us;
    uint16_t seq;
    uint32_t n_samples;
    int16_t samples[MAX_FRAME_SAMPLES];
} audio_frame_t;

/**
 * @brief Initialize streaming module.
 *
 * Must be called once before start.
 */
esp_err_t audio_stream_init(const audio_stream_config_t *cfg);

/**
 * @brief Start continuous audio streaming.
 *
 * Creates a FreeRTOS task and opens TCP connection.
 */
esp_err_t audio_stream_start(void);

/**
 * @brief Stop streaming.
 *
 * Stops task AND closes TCP socket.
 */
esp_err_t audio_stream_stop(void);

/**
 * @brief Check streaming state.
 */
bool audio_stream_is_running(void);

/** @} */ // end of AUDIO_STREAM group