#include "im72d128.h"
#include "esp_log.h"

static const char *TAG = "IM72D128";


/**
 * @brief Initialize IM72D128 microphone using ESP-IDF PDM I2S driver
 */
esp_err_t im72d128_init(im72d128_t *mic,
                        i2s_port_t port,
                        gpio_num_t clk_pin,
                        gpio_num_t data_pin,
                        uint32_t sample_rate)
{
    if (!mic) {
        ESP_LOGE(TAG, "Invalid microphone handle");
        return ESP_ERR_INVALID_ARG;
    }

    mic->clk_pin = clk_pin;
    mic->data_pin = data_pin;
    mic->sample_rate = sample_rate;

    ESP_LOGI(TAG, "Initializing IM72D128");
    ESP_LOGI(TAG, "I2S port: %d", port);
    ESP_LOGI(TAG, "CLK pin: %d", clk_pin);
    ESP_LOGI(TAG, "DATA pin: %d", data_pin);
    ESP_LOGI(TAG, "Sample rate: %lu Hz", sample_rate);

    /* Channel configuration */
    i2s_chan_config_t chan_cfg = I2S_CHANNEL_DEFAULT_CONFIG(port, I2S_ROLE_MASTER);

    esp_err_t err = i2s_new_channel(&chan_cfg, NULL, &mic->rx_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to create I2S channel (%d)", err);
        return err;
    }

    /* PDM RX configuration */
    i2s_pdm_rx_config_t pdm_cfg = {
        .clk_cfg = I2S_PDM_RX_CLK_DEFAULT_CONFIG(sample_rate),

        .slot_cfg = I2S_PDM_RX_SLOT_DEFAULT_CONFIG(
            I2S_DATA_BIT_WIDTH_16BIT,
            I2S_SLOT_MODE_MONO
        ),

        .gpio_cfg = {
            .clk = clk_pin,
            .din = data_pin,
            .invert_flags = {
                .clk_inv = false,
            },
        },
    };

    err = i2s_channel_init_pdm_rx_mode(mic->rx_handle, &pdm_cfg);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to initialize PDM RX mode (%d)", err);
        return err;
    }

    err = i2s_channel_enable(mic->rx_handle);
    if (err != ESP_OK) {
        ESP_LOGE(TAG, "Failed to enable I2S channel (%d)", err);
        return err;
    }

    ESP_LOGI(TAG, "IM72D128 initialized successfully");

    return ESP_OK;
}

/**
 * @brief Read audio samples from microphone
 */
esp_err_t im72d128_read(im72d128_t *mic,
                        int16_t *buffer,
                        size_t samples,
                        size_t *bytes_read)
{
    if (!mic || !buffer) {
        return ESP_ERR_INVALID_ARG;
    }

    size_t bytes_to_read = samples * sizeof(int16_t);

    esp_err_t err = i2s_channel_read(
        mic->rx_handle,
        buffer,
        bytes_to_read,
        bytes_read,
        pdMS_TO_TICKS(1000)  // 1 second timeout
    );

    if (err != ESP_OK) {
        ESP_LOGE(TAG, "I2S read failed (%d)", err);
        return err;
    }

    ESP_LOGD(TAG, "Read %u bytes from microphone", (unsigned)*bytes_read);

    return ESP_OK;
}

