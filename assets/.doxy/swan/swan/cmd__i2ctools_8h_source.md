

# File cmd\_i2ctools.h

[**File List**](files.md) **>** [**i2c\_tools**](dir_8b4e5b8bf912f4cf55ac17b5fb8ec414.md) **>** [**main**](dir_3218ba971dba91160485f06c6137239b.md) **>** [**cmd\_i2ctools.h**](cmd__i2ctools_8h.md)

[Go to the documentation of this file](cmd__i2ctools_8h.md)


```C++
/*
 * SPDX-FileCopyrightText: 2022-2024 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include "driver/i2c_master.h"

#ifdef __cplusplus
extern "C" {
#endif

void register_i2ctools(void);

extern i2c_master_bus_handle_t tool_bus_handle;

#ifdef __cplusplus
}
#endif
```


