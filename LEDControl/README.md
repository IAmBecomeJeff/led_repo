ESP32 based remote controller for addressable LEDs (types supported by FastLED). Create a secrets.h file and put your wifi
stuff in there. Check out any esp32 examples to see exactly how that needs to be setup. 

This project has a controller for the LEDs which supports palettes, animations, and transitions. It also has a web server
which hosts a frontend for the controller that allows users to change the operating behavior for the LED controller. It is 
currently setup expecting that the frontend (provided separately) is hosted from an SD card formatted with FAT32 and attached
to the ESP32 (not provided). The project can be nominally modified to host the frontend from a SPIFFS filesystem so that this
project can be run without any additional components besides the ESP32.

Okay, you need a few libraries to compile this.

+ FastLED
+ ESPAsyncWebServer (https://github.com/me-no-dev/ESPAsyncWebServer)
+ AsyncTCP (https://github.com/me-no-dev/AsyncTCP)

The last two have to be installed manually
1. Download each from their respective github link
2. Extract each into your Documents/Arduino/libraries folder
3. Rejoice

