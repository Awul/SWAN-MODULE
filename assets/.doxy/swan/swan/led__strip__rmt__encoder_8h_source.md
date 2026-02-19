

# File led\_strip\_rmt\_encoder.h

[**File List**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**managed\_components**](dir_f14b78939adc8414aa21d6af988468d0.md) **>** [**espressif\_\_led\_strip**](dir_d0251c514b1be4d4f41659a309ca9490.md) **>** [**src**](dir_163002825b6da09af3d0cb3d07e787f0.md) **>** [**led\_strip\_rmt\_encoder.h**](led__strip__rmt__encoder_8h.md)

[Go to the documentation of this file](led__strip__rmt__encoder_8h.md)


```C++
/*
 * SPDX-FileCopyrightText: 2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <stdint.h>
#include "driver/rmt_encoder.h"
#include "led_strip_types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    uint32_t resolution;   
    led_model_t led_model; 
} led_strip_encoder_config_t;

esp_err_t rmt_new_led_strip_encoder(const led_strip_encoder_config_t *config, rmt_encoder_handle_t *ret_encoder);

#ifdef __cplusplus
}
#endif
```


