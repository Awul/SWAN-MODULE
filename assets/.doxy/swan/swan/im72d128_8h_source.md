

# File im72d128.h

[**File List**](files.md) **>** [**components**](dir_409f97388efe006bc3438b95e9edef48.md) **>** [**im72d128**](dir_c649279310fd2efffa2e805b1e47d1a6.md) **>** [**im72d128.h**](im72d128_8h.md)

[Go to the documentation of this file](im72d128_8h.md)


```C++


#include "driver/i2s_pdm.h"
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "esp_err.h"


#define MIC_CLK_PIN  GPIO_NUM_5
#define MIC_DATA_PIN GPIO_NUM_4


typedef struct {
    i2s_chan_handle_t rx_handle;
    gpio_num_t clk_pin;
    gpio_num_t data_pin;
    uint32_t sample_rate;
} im72d128_t;


esp_err_t im72d128_init(im72d128_t *mic,
                        i2s_port_t port,
                        gpio_num_t clk_pin,
                        gpio_num_t data_pin,
                        uint32_t sample_rate);


esp_err_t im72d128_read(im72d128_t *mic,
                        int16_t *buffer,
                        size_t samples,
                        size_t *bytes_read);



```


