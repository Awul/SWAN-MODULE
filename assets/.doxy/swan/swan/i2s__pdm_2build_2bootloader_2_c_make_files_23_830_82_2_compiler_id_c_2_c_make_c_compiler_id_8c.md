

# File CMakeCCompilerId.c



[**FileList**](files.md) **>** [**3.30.2**](dir_77a68a16d1d76794df0c1d3a462f06b3.md) **>** [**CompilerIdC**](dir_07f4232927c81f18ebba5dea104937ff.md) **>** [**CMakeCCompilerId.c**](i2s__pdm_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_2_c_make_c_compiler_id_8c.md)

[Go to the source code of this file](i2s__pdm_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_2_c_make_c_compiler_id_8c_source.md)
























## Public Attributes

| Type | Name |
| ---: | :--- |
|  char const  \* | [**info\_arch**](#variable-info_arch)   = `"INFO" ":" "arch[" ARCHITECTURE\_ID "]"`<br> |
|  char const  \* | [**info\_compiler**](#variable-info_compiler)   = `"INFO" ":" "compiler[" COMPILER\_ID "]"`<br> |
|  const char \* | [**info\_language\_extensions\_default**](#variable-info_language_extensions_default)   = `/* multi line expression */`<br> |
|  const char \* | [**info\_language\_standard\_default**](#variable-info_language_standard_default)   = `/* multi line expression */`<br> |
|  char const  \* | [**info\_platform**](#variable-info_platform)   = `"INFO" ":" "platform[" PLATFORM\_ID "]"`<br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  int | [**main**](#function-main) (int argc, char \* argv) <br> |



























## Macros

| Type | Name |
| ---: | :--- |
| define  | [**ARCHITECTURE\_ID**](i2s__pdm_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_2_c_make_c_compiler_id_8c.md#define-architecture_id)  <br> |
| define  | [**COMPILER\_ID**](i2s__pdm_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_2_c_make_c_compiler_id_8c.md#define-compiler_id)  `""`<br> |
| define  | [**C\_STD\_11**](i2s__pdm_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_2_c_make_c_compiler_id_8c.md#define-c_std_11)  `201112L`<br> |
| define  | [**C\_STD\_17**](i2s__pdm_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_2_c_make_c_compiler_id_8c.md#define-c_std_17)  `201710L`<br> |
| define  | [**C\_STD\_23**](i2s__pdm_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_2_c_make_c_compiler_id_8c.md#define-c_std_23)  `202311L`<br> |
| define  | [**C\_STD\_99**](i2s__pdm_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_2_c_make_c_compiler_id_8c.md#define-c_std_99)  `199901L`<br> |
| define  | [**C\_VERSION**](i2s__pdm_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_2_c_make_c_compiler_id_8c.md#define-c_version)  <br> |
| define  | [**DEC**](i2s__pdm_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_2_c_make_c_compiler_id_8c.md#define-dec) (n) `/* multi line expression */`<br> |
| define  | [**HEX**](i2s__pdm_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_2_c_make_c_compiler_id_8c.md#define-hex) (n) `/* multi line expression */`<br> |
| define  | [**PLATFORM\_ID**](i2s__pdm_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_2_c_make_c_compiler_id_8c.md#define-platform_id)  <br> |
| define  | [**STRINGIFY**](i2s__pdm_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_2_c_make_c_compiler_id_8c.md#define-stringify) (X) `STRINGIFY\_HELPER(X)`<br> |
| define  | [**STRINGIFY\_HELPER**](i2s__pdm_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_2_c_make_c_compiler_id_8c.md#define-stringify_helper) (X) `#X`<br> |
| define  | [**\_\_has\_include**](i2s__pdm_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_2_c_make_c_compiler_id_8c.md#define-__has_include) (x) `0`<br> |

## Public Attributes Documentation




### variable info\_arch 

```C++
char const* info_arch;
```




<hr>



### variable info\_compiler 

```C++
char const* info_compiler;
```




<hr>



### variable info\_language\_extensions\_default 

```C++
const char* info_language_extensions_default;
```




<hr>



### variable info\_language\_standard\_default 

```C++
const char* info_language_standard_default;
```




<hr>



### variable info\_platform 

```C++
char const* info_platform;
```




<hr>
## Public Functions Documentation




### function main 

```C++
int main (
    int argc,
    char * argv
) 
```




<hr>
## Macro Definition Documentation





### define ARCHITECTURE\_ID 

```C++
#define ARCHITECTURE_ID 
```




<hr>



### define COMPILER\_ID 

```C++
#define COMPILER_ID `""`
```




<hr>



### define C\_STD\_11 

```C++
#define C_STD_11 `201112L`
```




<hr>



### define C\_STD\_17 

```C++
#define C_STD_17 `201710L`
```




<hr>



### define C\_STD\_23 

```C++
#define C_STD_23 `202311L`
```




<hr>



### define C\_STD\_99 

```C++
#define C_STD_99 `199901L`
```




<hr>



### define C\_VERSION 

```C++
#define C_VERSION 
```




<hr>



### define DEC 

```C++
#define DEC (
    n
) `/* multi line expression */`
```




<hr>



### define HEX 

```C++
#define HEX (
    n
) `/* multi line expression */`
```




<hr>



### define PLATFORM\_ID 

```C++
#define PLATFORM_ID 
```




<hr>



### define STRINGIFY 

```C++
#define STRINGIFY (
    X
) `STRINGIFY_HELPER(X)`
```




<hr>



### define STRINGIFY\_HELPER 

```C++
#define STRINGIFY_HELPER (
    X
) `#X`
```




<hr>



### define \_\_has\_include 

```C++
#define __has_include (
    x
) `0`
```




<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/i2s_pdm/build/bootloader/CMakeFiles/3.30.2/CompilerIdC/CMakeCCompilerId.c`

