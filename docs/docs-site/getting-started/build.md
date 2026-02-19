# Build & Flash SWAN Module (ESP32) in VS Code

This guide explains how to build and flash the SWAN module firmware using Visual Studio Code and ESP-IDF.

---

## 1️⃣ Install Requirements

1. **ESP-IDF**  
   Download and install the ESP-IDF from [https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/).

2. **VS Code Extensions**  
   Install the following in VS Code:
   - **ESP-IDF** (by Espressif)
   - **C/C++** (for IntelliSense)

3. **Python**  
   ESP-IDF requires Python (usually ≥3.8). Make sure `python` and `pip` are in your PATH.

---

## 2️⃣ Open the Project in VS Code

1. Open VS Code.
2. Go to **File → Open Folder**.
3. Select the root folder of the SWAN module project (where `CMakeLists.txt` is located).

---

## 3️⃣ Set Up ESP-IDF Extension

1. Press `Ctrl+Shift+P` → **ESP-IDF: Configure ESP-IDF Extension**.
2. Follow the prompts to set:
   - ESP-IDF directory
   - Python interpreter
   - Serial port (optional)

> The extension automatically sets environment variables for `idf.py`.


