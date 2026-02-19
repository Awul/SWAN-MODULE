

# Struct veml7700\_t



[**ClassList**](annotated.md) **>** [**veml7700\_t**](structveml7700__t.md)



_VEML7700 device descriptor._ [More...](#detailed-description)

* `#include <veml7700.h>`





















## Public Attributes

| Type | Name |
| ---: | :--- |
|  uint8\_t | [**i2c\_addr**](#variable-i2c_addr)  <br> |
|  i2c\_port\_t | [**i2c\_port**](#variable-i2c_port)  <br> |












































## Detailed Description


Holds the I²C configuration required to communicate with a VEML7700 instance. One struct instance corresponds to one sensor on the bus. 


    
## Public Attributes Documentation




### variable i2c\_addr 

```C++
uint8_t veml7700_t::i2c_addr;
```



7-bit I²C address of the sensor 


        

<hr>



### variable i2c\_port 

```C++
i2c_port_t veml7700_t::i2c_port;
```



I²C port used by the sensor 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `C:/Users/schliep/Documents/Software/ESP32/SWAN-MODULE/components/veml7700/veml7700.h`

