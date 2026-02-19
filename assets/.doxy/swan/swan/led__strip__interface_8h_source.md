

# File led\_strip\_interface.h

[**File List**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**managed\_components**](dir_f14b78939adc8414aa21d6af988468d0.md) **>** [**espressif\_\_led\_strip**](dir_d0251c514b1be4d4f41659a309ca9490.md) **>** [**interface**](dir_853002c9a0c16e1e5afe2f5095699801.md) **>** [**led\_strip\_interface.h**](led__strip__interface_8h.md)

[Go to the documentation of this file](led__strip__interface_8h.md)


```C++
/*
 * SPDX-FileCopyrightText: 2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <stdint.h>
#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct led_strip_t led_strip_t; 

struct led_strip_t {
    esp_err_t (*set_pixel)(led_strip_t *strip, uint32_t index, uint32_t red, uint32_t green, uint32_t blue);

    esp_err_t (*set_pixel_rgbw)(led_strip_t *strip, uint32_t index, uint32_t red, uint32_t green, uint32_t blue, uint32_t white);

    esp_err_t (*refresh)(led_strip_t *strip);

    esp_err_t (*clear)(led_strip_t *strip);

    esp_err_t (*del)(led_strip_t *strip);
};

#ifdef __cplusplus
}
#endif
```


