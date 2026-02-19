

# File CMakeCXXCompilerId.cpp



[**FileList**](files.md) **>** [**3.30.2**](dir_838b91b5750bf600f3a9869ecafa0d17.md) **>** [**CompilerIdCXX**](dir_699f87c68b6554acb89c93f5f50d60c1.md) **>** [**CMakeCXXCompilerId.cpp**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md)

[Go to the source code of this file](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp_source.md)
























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
| define  | [**ARCHITECTURE\_ID**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md#define-architecture_id)  <br> |
| define  | [**COMPILER\_ID**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md#define-compiler_id)  `""`<br> |
| define  | [**CXX\_STD**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md#define-cxx_std)  `\_\_cplusplus`<br> |
| define  | [**CXX\_STD\_11**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md#define-cxx_std_11)  `201103L`<br> |
| define  | [**CXX\_STD\_14**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md#define-cxx_std_14)  `201402L`<br> |
| define  | [**CXX\_STD\_17**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md#define-cxx_std_17)  `201703L`<br> |
| define  | [**CXX\_STD\_20**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md#define-cxx_std_20)  `202002L`<br> |
| define  | [**CXX\_STD\_23**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md#define-cxx_std_23)  `202302L`<br> |
| define  | [**CXX\_STD\_98**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md#define-cxx_std_98)  `199711L`<br> |
| define  | [**DEC**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md#define-dec) (n) `/* multi line expression */`<br> |
| define  | [**HEX**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md#define-hex) (n) `/* multi line expression */`<br> |
| define  | [**PLATFORM\_ID**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md#define-platform_id)  <br> |
| define  | [**STRINGIFY**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md#define-stringify) (X) `STRINGIFY\_HELPER(X)`<br> |
| define  | [**STRINGIFY\_HELPER**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md#define-stringify_helper) (X) `#X`<br> |
| define  | [**\_\_has\_include**](_s_w_a_n-_m_o_d_u_l_e_2build_2bootloader_2_c_make_files_23_830_82_2_compiler_id_c_x_x_2_c_make_c_x_x_compiler_id_8cpp.md#define-__has_include) (x) `0`<br> |

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



### define CXX\_STD 

```C++
#define CXX_STD `__cplusplus`
```




<hr>



### define CXX\_STD\_11 

```C++
#define CXX_STD_11 `201103L`
```




<hr>



### define CXX\_STD\_14 

```C++
#define CXX_STD_14 `201402L`
```




<hr>



### define CXX\_STD\_17 

```C++
#define CXX_STD_17 `201703L`
```




<hr>



### define CXX\_STD\_20 

```C++
#define CXX_STD_20 `202002L`
```




<hr>



### define CXX\_STD\_23 

```C++
#define CXX_STD_23 `202302L`
```




<hr>



### define CXX\_STD\_98 

```C++
#define CXX_STD_98 `199711L`
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
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/SWAN-MODULE/build/bootloader/CMakeFiles/3.30.2/CompilerIdCXX/CMakeCXXCompilerId.cpp`

