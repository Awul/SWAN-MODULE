

# File veml7700.c

[**File List**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**veml7700**](dir_0150b187d0697ce476d48596f0c108de.md) **>** [**veml7700.c**](veml7700_8c.md)

[Go to the documentation of this file](veml7700_8c.md)


```C++


#include "veml7700.h"



static esp_err_t veml7700_write16(const veml7700_t *dev, uint8_t reg, uint16_t val)
{
    uint8_t data[3] = {
        reg,
        val & 0xFF,
        val >> 8
    };

    return i2c_master_write_to_device(
        dev->i2c_port,
        dev->i2c_addr,
        data,
        sizeof(data),
        pdMS_TO_TICKS(100)
    );
}

static esp_err_t veml7700_read16(const veml7700_t *dev, uint8_t reg, uint16_t *val)
{
    uint8_t data[2];

    esp_err_t err = i2c_master_write_read_device(
        dev->i2c_port,
        dev->i2c_addr,
        &reg,
        1,
        data,
        sizeof(data),
        pdMS_TO_TICKS(100)
    );

    if (err == ESP_OK) {
        *val = data[0] | (data[1] << 8);
    }

    return err;
}

void veml7700_print_registers(const veml7700_t *dev)
{
    // The registers are all 16-bit
    uint16_t r[8];

    for (uint8_t i = 0; i <= 7; i++) {
        if (veml7700_read16(dev, i, &r[i]) != ESP_OK) {
            ESP_LOGE("VEML7700", "Failed to read register 0x%02X", i);
            return;
        }
    }

    ESP_LOGI("VEML7700", "========== VEML7700 REGISTER DUMP ==========");
    ESP_LOGI("VEML7700", "ALS_CONF_0 (0x00): 0x%04X",   r[0]);
    ESP_LOGI("VEML7700", "ALS_WH     (0x01): %u",       r[1]);
    ESP_LOGI("VEML7700", "ALS_WL     (0x02): %u",       r[2]);
    ESP_LOGI("VEML7700", "POWER_SAVE (0x03): 0x%04X",   r[3]);
    ESP_LOGI("VEML7700", "ALS        (0x04): %u",       r[4]);
    ESP_LOGI("VEML7700", "WHITE      (0x05): %u",       r[5]);
    ESP_LOGI("VEML7700", "ALS_INT    (0x06): 0x%04X",   r[6]);
    ESP_LOGI("VEML7700", "ID         (0x07): 0x%04X",   r[7]);

    /* ---------- Interpret configuration ---------- */
    uint16_t conf = r[0];

    // Decode the bit fields
    // 0x01 = 0b1, 0x03 = 0b11, 0x0F = 0b1111 -> bit masking
    // Shift right to align the field, then mask to extract the value
    uint8_t gain = (conf >> 11) & 0x03;
    uint8_t it   = (conf >> 6)  & 0x0F;
    uint8_t pers = (conf >> 4)  & 0x03;
    bool int_en  = (conf >> 1)  & 0x01;
    bool shutdown = conf & 0x01;

    // Based on the datasheet, these are the possible gain and integration time settings
    //TODO: Can use the new helper functions to calculate responsivity and gain factor instead of hardcoding the strings here
    const char *gain_str[] = {
        "x1", "x2", "x1/8", "x1/4"
    };

    char *it_str = "UNKNOWN";
    switch (it) {
        case 0x0: it_str = "100 ms"; break;
        case 0x1: it_str = "200 ms"; break;
        case 0x2: it_str = "400 ms"; break;
        case 0x3: it_str = "800 ms"; break;
        case 0x8: it_str = "50 ms";  break;
        case 0xC: it_str = "25 ms";  break;
    }

    ESP_LOGI("VEML7700", "---------- Configuration ----------");
    ESP_LOGI("VEML7700", "ALS Gain           : %s", gain_str[gain]);
    ESP_LOGI("VEML7700", "Integration Time   : %s", it_str);
    ESP_LOGI("VEML7700", "Persistence        : %u sample(s)", 1 << pers);
    ESP_LOGI("VEML7700", "Interrupt Enabled  : %s", int_en ? "YES" : "NO");
    ESP_LOGI("VEML7700", "Sensor State       : %s", shutdown ? "SHUTDOWN" : "ACTIVE");

    /* ---------- Power saving ---------- */
    uint8_t psm = (r[3] >> 1) & 0x03;
    bool psm_en = r[3] & 0x01;

    ESP_LOGI("VEML7700", "---------- Power Saving ----------");
    ESP_LOGI("VEML7700", "PSM Enabled        : %s", psm_en ? "YES" : "NO");
    ESP_LOGI("VEML7700", "PSM Mode           : %u", psm + 1);

    /* ---------- Interrupt status ---------- */
    ESP_LOGI("VEML7700", "---------- Interrupt Status ----------");
    ESP_LOGI("VEML7700", "Low Threshold Hit  : %s", (r[6] & (1 << 15)) ? "YES" : "NO");
    ESP_LOGI("VEML7700", "High Threshold Hit : %s", (r[6] & (1 << 14)) ? "YES" : "NO");

    /* ---------- ID decoding ---------- */
    uint8_t id_lsb = r[7] & 0xFF;
    uint8_t id_msb = r[7] >> 8;

    ESP_LOGI("VEML7700", "---------- Device ID ----------");
    ESP_LOGI("VEML7700", "Device ID Code     : 0x%02X (%s)",
             id_lsb, (id_lsb == 0x81) ? "VALID" : "UNKNOWN");

    ESP_LOGI("VEML7700", "Address Option     : 0x%02X", id_msb);
    ESP_LOGI("VEML7700", "==========================================");
}

esp_err_t veml7700_init(veml7700_t *dev, i2c_port_t port)
{
    if (!dev) {
        return ESP_ERR_INVALID_ARG;
    }

    dev->i2c_port = port;
    dev->i2c_addr = VEML7700_I2C_ADDR_DEFAULT;

    /* Power on the sensor */
    ESP_ERROR_CHECK(veml7700_write16(dev, VEML7700_REG_POWER_SAVING, 0x0000));

    /* Default ALS configuration:
     * Gain = 1×
     * Integration time = 100 ms
     * ALS enabled
     */
    ESP_ERROR_CHECK(veml7700_write16(dev, VEML7700_REG_ALS_CONF_0, 0x0000));

    vTaskDelay(pdMS_TO_TICKS(10));
    return ESP_OK;
}

esp_err_t veml7700_read_als(veml7700_t *dev, uint16_t *als)
{
    if (!dev || !als) {
        return ESP_ERR_INVALID_ARG;
    }

    // The ALS register is 16-bit, so we can use the read16 helper function
    // This reads the ALS but not the WHITE channel. The white channel can be read separately if needed.
    return veml7700_read16(dev, VEML7700_REG_ALS, als);
}

float veml7700_responsivity(uint8_t it_bits) {
    switch (it_bits) {
        case 0b1100: return 0.2304f; // 25 ms
        case 0b1000: return 0.1152f; // 50 ms
        case 0b0000: return 0.0576f; // 100 ms
        case 0b0001: return 0.0288f; // 200 ms
        case 0b0010: return 0.0144f; // 400 ms
        case 0b0011: return 0.0072f; // 800 ms
    }
    return 0.0576f; // fallback 100 ms
}

float veml7700_gain_factor(uint8_t gain_bits) {
    switch (gain_bits) {
        case 0b00: return 1.0f;   // x1
        case 0b01: return 2.0f;   // x2
        case 0b10: return 0.125f; // x1/8
        case 0b11: return 0.25f;  // x1/4
    }
    return 1.0f; // fallback
}

esp_err_t veml7700_read_lux(veml7700_t *dev, float *lux)
{
    if (!dev || !lux) {
        return ESP_ERR_INVALID_ARG;
    }

    uint16_t als_conf, als_data;
    esp_err_t ret;

    //read ALS_CONF_0
    ret = veml7700_read16(dev, VEML7700_REG_ALS_CONF_0, &als_conf);
    if (ret != ESP_OK) return ret;

    //read ALS data
    ret = veml7700_read_als(dev, &als_data);
    if (ret != ESP_OK) return ret;
    
    // Extract gain and integration time settings from the configuration register
    uint8_t gain_bits = (als_conf >> 11) & 0x03;
    uint8_t it_bits   = (als_conf >> 6)  & 0x0F;

    //Lookup gain factor and responsivity
    float gain_factor = veml7700_gain_factor(gain_bits);
    float responsivity = veml7700_responsivity(it_bits);

    // Conversion of als_data to lux
    *lux = als_data / gain_factor * responsivity;
    return ESP_OK;
}
```


