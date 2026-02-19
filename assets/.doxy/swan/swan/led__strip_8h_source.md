

# File led\_strip.h

[**File List**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**managed\_components**](dir_f14b78939adc8414aa21d6af988468d0.md) **>** [**espressif\_\_led\_strip**](dir_d0251c514b1be4d4f41659a309ca9490.md) **>** [**include**](dir_9798d67173f3cb6f216c73c0b3ea0b46.md) **>** [**led\_strip.h**](led__strip_8h.md)

[Go to the documentation of this file](led__strip_8h.md)


```C++
/*
 * SPDX-FileCopyrightText: 2022-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <stdint.h>
#include "esp_err.h"
#include "led_strip_rmt.h"
#include "led_strip_spi.h"

#ifdef __cplusplus
extern "C" {
#endif

esp_err_t led_strip_set_pixel(led_strip_handle_t strip, uint32_t index, uint32_t red, uint32_t green, uint32_t blue);

esp_err_t led_strip_set_pixel_rgbw(led_strip_handle_t strip, uint32_t index, uint32_t red, uint32_t green, uint32_t blue, uint32_t white);

esp_err_t led_strip_set_pixel_hsv(led_strip_handle_t strip, uint32_t index, uint16_t hue, uint8_t saturation, uint8_t value);

esp_err_t led_strip_set_pixel_hsv_16(led_strip_handle_t strip, uint32_t index, uint16_t hue, uint16_t saturation, uint16_t value);

esp_err_t led_strip_refresh(led_strip_handle_t strip);

esp_err_t led_strip_clear(led_strip_handle_t strip);

esp_err_t led_strip_del(led_strip_handle_t strip);

#ifdef __cplusplus
}
#endif
```


