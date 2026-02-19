

# File README.md

[**File List**](files.md) **>** [**README.md**](blink_2managed__components_2espressif____led__strip_2examples_2led__strip__spi__ws2812_2_r_e_a_d_m_e_8md.md)

[Go to the documentation of this file](blink_2managed__components_2espressif____led__strip_2examples_2led__strip__spi__ws2812_2_r_e_a_d_m_e_8md.md)


```Markdown
# LED Strip Example (SPI backend + WS2812)

This example demonstrates how to blink the WS2812 LED using the [led_strip](https://components.espressif.com/component/espressif/led_strip) component.

## How to Use Example

### Hardware Required

* A development board with Espressif SoC
* A USB cable for Power supply and programming
* WS2812 LED strip

### Configure the Example

Before project configuration and build, be sure to set the correct chip target using `idf.py set-target <chip_name>`. Then assign the proper GPIO in the [source file](main/led_strip_spi_ws2812_main.c). If your led strip has multiple LEDs, don't forget update the number.

### Build and Flash

Run `idf.py -p PORT build flash monitor` to build, flash and monitor the project.

(To exit the serial monitor, type ``Ctrl-]``.)

See the [Getting Started Guide](https://docs.espressif.com/projects/esp-idf/en/latest/get-started/index.html) for full steps to configure and use ESP-IDF to build projects.

## Example Output

```text
I (299) gpio: GPIO[14]| InputEn: 0| OutputEn: 1| OpenDrain: 0| Pullup: 1| Pulldown: 0| Intr:0
I (309) example: Created LED strip object with SPI backend
I (309) example: Start blinking LED strip
```
```


