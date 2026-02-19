

# File i2s\_pdm\_example.h

[**File List**](files.md) **>** [**i2s\_pdm**](dir_a9d5f53e1a98f7a823b6664583338eef.md) **>** [**main**](dir_8b646def77c344b31338d8d065cc4f74.md) **>** [**i2s\_pdm\_example.h**](i2s__pdm__example_8h.md)

[Go to the documentation of this file](i2s__pdm__example_8h.md)


```C++
/*
 * SPDX-FileCopyrightText: 2021-2022 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Unlicense OR CC0-1.0
 */

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define EXAMPLE_BUFF_SIZE   2048

void i2s_example_pdm_tx_task(void *args);

void i2s_example_pdm_rx_task(void *args);

#ifdef __cplusplus
}
#endif
```


