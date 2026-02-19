

# File led\_strip\_types.h

[**File List**](files.md) **>** [**blink**](dir_ed75a055ae422585327f9cac7433a4c6.md) **>** [**managed\_components**](dir_f14b78939adc8414aa21d6af988468d0.md) **>** [**espressif\_\_led\_strip**](dir_d0251c514b1be4d4f41659a309ca9490.md) **>** [**include**](dir_9798d67173f3cb6f216c73c0b3ea0b46.md) **>** [**led\_strip\_types.h**](led__strip__types_8h.md)

[Go to the documentation of this file](led__strip__types_8h.md)


```C++
/*
 * SPDX-FileCopyrightText: 2022-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct led_strip_t *led_strip_handle_t;

typedef enum {
    LED_MODEL_WS2812, 
    LED_MODEL_SK6812, 
    LED_MODEL_WS2811, 
    LED_MODEL_WS2816, 
    LED_MODEL_INVALID 
} led_model_t;

typedef union {
    struct format_layout {
        uint32_t r_pos: 2;           
        uint32_t g_pos: 2;           
        uint32_t b_pos: 2;           
        uint32_t w_pos: 2;           
        uint32_t reserved: 19;       
        uint32_t bytes_per_color: 2; 
        uint32_t num_components: 3;  
    } format;                        
    uint32_t format_id;              
} led_color_component_format_t;

#define LED_STRIP_COLOR_COMPONENT_FMT_GRB (led_color_component_format_t){.format = {.r_pos = 1, .g_pos = 0, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 1, .num_components = 3}}
#define LED_STRIP_COLOR_COMPONENT_FMT_GRB_16 (led_color_component_format_t){.format = {.r_pos = 1, .g_pos = 0, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 2, .num_components = 3}}
#define LED_STRIP_COLOR_COMPONENT_FMT_GRBW (led_color_component_format_t){.format = {.r_pos = 1, .g_pos = 0, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 1, .num_components = 4}}
#define LED_STRIP_COLOR_COMPONENT_FMT_GRBW_16 (led_color_component_format_t){.format = {.r_pos = 1, .g_pos = 0, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 2, .num_components = 4}}
#define LED_STRIP_COLOR_COMPONENT_FMT_RGB (led_color_component_format_t){.format = {.r_pos = 0, .g_pos = 1, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 1, .num_components = 3}}
#define LED_STRIP_COLOR_COMPONENT_FMT_RGB_16 (led_color_component_format_t){.format = {.r_pos = 0, .g_pos = 1, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 2, .num_components = 3}}
#define LED_STRIP_COLOR_COMPONENT_FMT_RGBW (led_color_component_format_t){.format = {.r_pos = 0, .g_pos = 1, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 1, .num_components = 4}}
#define LED_STRIP_COLOR_COMPONENT_FMT_RGBW_16 (led_color_component_format_t){.format = {.r_pos = 0, .g_pos = 1, .b_pos = 2, .w_pos = 3, .reserved = 0, .bytes_per_color = 2, .num_components = 4}}

typedef struct {
    int strip_gpio_num;           
    uint32_t max_leds;            
    led_model_t led_model;        
    led_color_component_format_t color_component_format; 
    struct led_strip_extra_flags {
        uint32_t invert_out: 1; 
    } flags; 
} led_strip_config_t;

#ifdef __cplusplus
}
#endif
```


