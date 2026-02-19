

# File led\_strip\_spi.h

[**File List**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**managed\_components**](dir_f14b78939adc8414aa21d6af988468d0.md) **>** [**espressif\_\_led\_strip**](dir_d0251c514b1be4d4f41659a309ca9490.md) **>** [**include**](dir_9798d67173f3cb6f216c73c0b3ea0b46.md) **>** [**led\_strip\_spi.h**](led__strip__spi_8h.md)

[Go to the documentation of this file](led__strip__spi_8h.md)


```C++
/*
 * SPDX-FileCopyrightText: 2022-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <stdint.h>
#include "esp_err.h"
#include "driver/spi_master.h"
#include "led_strip_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    spi_clock_source_t clk_src; 
    spi_host_device_t spi_bus;  
    struct {
        uint32_t with_dma: 1;   
    } flags;                    
} led_strip_spi_config_t;

esp_err_t led_strip_new_spi_device(const led_strip_config_t *led_config, const led_strip_spi_config_t *spi_config, led_strip_handle_t *ret_strip);

#ifdef __cplusplus
}
#endif
```


