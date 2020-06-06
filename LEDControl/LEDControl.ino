/*
 Name:		ESP32_LED_CTRL.ino
 Created:	3/7/2020 4:26:01 PM
 Author:	poop
*/
#include <AsyncTCP.h>
#include <FastLED.h>
#include <WiFi.h>
#include <FS.h>
#include <SPI.h>
#include <SD.h>
//#include <SPIFFS.h> //Uncomment this and comment out SD.h to use SPIFFS
#include <ESPAsyncWebServer.h>
#include <dummy.h>

#define FS_HANDLE SD //Update this to use SPIFFS

AsyncWebServer webServer(80);

#include "palettes.h"
#include "secrets.h"
#include "web.h"
#include "util.h"
//#include "led.h"
#include "LedController.h"

LedController ledControl = LedController();

void setup() {
    Serial.begin(115200);
    delay(3000);

    if (!FS_HANDLE.begin()) {
        Serial.println("Failed to mount SD");
    }

    listDir(FS_HANDLE, "/", 1);
    
    setupWifi();
    setupWeb(FS_HANDLE, &ledControl);

    ledControl.setPaletteLibrary(palettes);
    ledControl.setup();
}

// the loop function runs over and over again until power down or reset
void loop() {
    handleWeb(FS_HANDLE, &ledControl);

    //led_loop();
    ledControl.loop();
}
