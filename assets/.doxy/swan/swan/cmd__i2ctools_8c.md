

# File cmd\_i2ctools.c



[**FileList**](files.md) **>** [**i2c\_tools**](dir_8b4e5b8bf912f4cf55ac17b5fb8ec414.md) **>** [**main**](dir_3218ba971dba91160485f06c6137239b.md) **>** [**cmd\_i2ctools.c**](cmd__i2ctools_8c.md)

[Go to the source code of this file](cmd__i2ctools_8c_source.md)



* `#include <stdio.h>`
* `#include <string.h>`
* `#include "argtable3/argtable3.h"`
* `#include "driver/i2c_master.h"`
* `#include "esp_console.h"`
* `#include "esp_log.h"`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  struct arg\_int \* | [**chip\_address**](#variable-chip_address)  <br> |
|  struct arg\_int \* | [**data**](#variable-data)  <br> |
|  struct arg\_int \* | [**data\_length**](#variable-data_length)  <br> |
|  struct arg\_end \* | [**end**](#variable-end)  <br> |
|  struct arg\_int \* | [**freq**](#variable-freq)  <br> |
|  struct arg\_int \* | [**port**](#variable-port)  <br> |
|  struct arg\_int \* | [**register\_address**](#variable-register_address)  <br> |
|  struct arg\_int \* | [**scl**](#variable-scl)  <br> |
|  struct arg\_int \* | [**sda**](#variable-sda)  <br> |
|  struct arg\_int \* | [**size**](#variable-size)  <br> |
|  i2c\_master\_bus\_handle\_t | [**tool\_bus\_handle**](#variable-tool_bus_handle)  <br> |


## Public Static Attributes

| Type | Name |
| ---: | :--- |
|  const char \* | [**TAG**](#variable-tag)   = `"cmd\_i2ctools"`<br> |
|  uint32\_t | [**i2c\_frequency**](#variable-i2c_frequency)   = `100 \* 1000`<br> |
|  struct @006345325225170224270346213365257010302276277367 | [**i2cconfig\_args**](#variable-i2cconfig_args)  <br> |
|  struct @374242015051045112272110213124235243134127322141 | [**i2cdump\_args**](#variable-i2cdump_args)  <br> |
|  struct @200013266364245204255007115214317010012107171171 | [**i2cget\_args**](#variable-i2cget_args)  <br> |
|  struct @066222152236124227220100022255143322065315221323 | [**i2cset\_args**](#variable-i2cset_args)  <br> |














## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**register\_i2ctools**](#function-register_i2ctools) (void) <br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  int | [**do\_i2cconfig\_cmd**](#function-do_i2cconfig_cmd) (int argc, char \*\* argv) <br> |
|  int | [**do\_i2cdetect\_cmd**](#function-do_i2cdetect_cmd) (int argc, char \*\* argv) <br> |
|  int | [**do\_i2cdump\_cmd**](#function-do_i2cdump_cmd) (int argc, char \*\* argv) <br> |
|  int | [**do\_i2cget\_cmd**](#function-do_i2cget_cmd) (int argc, char \*\* argv) <br> |
|  int | [**do\_i2cset\_cmd**](#function-do_i2cset_cmd) (int argc, char \*\* argv) <br> |
|  esp\_err\_t | [**i2c\_get\_port**](#function-i2c_get_port) (int port, i2c\_port\_t \* i2c\_port) <br> |
|  void | [**register\_i2cconfig**](#function-register_i2cconfig) (void) <br> |
|  void | [**register\_i2cdetect**](#function-register_i2cdetect) (void) <br> |
|  void | [**register\_i2cdump**](#function-register_i2cdump) (void) <br> |
|  void | [**register\_i2cget**](#function-register_i2cget) (void) <br> |
|  void | [**register\_i2cset**](#function-register_i2cset) (void) <br> |

























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**I2C\_TOOL\_TIMEOUT\_VALUE\_MS**](cmd__i2ctools_8c.md#define-i2c_tool_timeout_value_ms)  `(50)`<br> |

## Public Attributes Documentation




### variable chip\_address 

```C++
struct arg_int* chip_address;
```




<hr>



### variable data 

```C++
struct arg_int* data;
```




<hr>



### variable data\_length 

```C++
struct arg_int* data_length;
```




<hr>



### variable end 

```C++
struct arg_end* end;
```




<hr>



### variable freq 

```C++
struct arg_int* freq;
```




<hr>



### variable port 

```C++
struct arg_int* port;
```




<hr>



### variable register\_address 

```C++
struct arg_int* register_address;
```




<hr>



### variable scl 

```C++
struct arg_int* scl;
```




<hr>



### variable sda 

```C++
struct arg_int* sda;
```




<hr>



### variable size 

```C++
struct arg_int* size;
```




<hr>



### variable tool\_bus\_handle 

```C++
i2c_master_bus_handle_t tool_bus_handle;
```




<hr>
## Public Static Attributes Documentation




### variable TAG 

```C++
const char* TAG;
```




<hr>



### variable i2c\_frequency 

```C++
uint32_t i2c_frequency;
```




<hr>



### variable i2cconfig\_args 

```C++
struct @006345325225170224270346213365257010302276277367 i2cconfig_args;
```




<hr>



### variable i2cdump\_args 

```C++
struct @374242015051045112272110213124235243134127322141 i2cdump_args;
```




<hr>



### variable i2cget\_args 

```C++
struct @200013266364245204255007115214317010012107171171 i2cget_args;
```




<hr>



### variable i2cset\_args 

```C++
struct @066222152236124227220100022255143322065315221323 i2cset_args;
```




<hr>
## Public Functions Documentation




### function register\_i2ctools 

```C++
void register_i2ctools (
    void
) 
```




<hr>
## Public Static Functions Documentation




### function do\_i2cconfig\_cmd 

```C++
static int do_i2cconfig_cmd (
    int argc,
    char ** argv
) 
```




<hr>



### function do\_i2cdetect\_cmd 

```C++
static int do_i2cdetect_cmd (
    int argc,
    char ** argv
) 
```




<hr>



### function do\_i2cdump\_cmd 

```C++
static int do_i2cdump_cmd (
    int argc,
    char ** argv
) 
```




<hr>



### function do\_i2cget\_cmd 

```C++
static int do_i2cget_cmd (
    int argc,
    char ** argv
) 
```




<hr>



### function do\_i2cset\_cmd 

```C++
static int do_i2cset_cmd (
    int argc,
    char ** argv
) 
```




<hr>



### function i2c\_get\_port 

```C++
static esp_err_t i2c_get_port (
    int port,
    i2c_port_t * i2c_port
) 
```




<hr>



### function register\_i2cconfig 

```C++
static void register_i2cconfig (
    void
) 
```




<hr>



### function register\_i2cdetect 

```C++
static void register_i2cdetect (
    void
) 
```




<hr>



### function register\_i2cdump 

```C++
static void register_i2cdump (
    void
) 
```




<hr>



### function register\_i2cget 

```C++
static void register_i2cget (
    void
) 
```




<hr>



### function register\_i2cset 

```C++
static void register_i2cset (
    void
) 
```




<hr>
## Macro Definition Documentation





### define I2C\_TOOL\_TIMEOUT\_VALUE\_MS 

```C++
#define I2C_TOOL_TIMEOUT_VALUE_MS `(50)`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/i2c_tools/main/cmd_i2ctools.c`

