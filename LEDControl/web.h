#pragma once
#include "util.h"
#include "LedController.h"

void ledApiRoutes(LedController* ledControl);

void setupWifi() {
    WiFi.mode(WIFI_STA);
    Serial.printf("Connecting to %s\n", ssid);

    if (String(WiFi.SSID()) != String(ssid)) {
        WiFi.begin(ssid, password);
    }
}

void setupWeb(fs::FS& fs, LedController *ledControl) {
    // This is an example of a route that can interact directly with the ESP32. You can call this from your webpage in order to make the ESP32 do something interesting.
    webServer.on("/api/version", [](AsyncWebServerRequest* request) {
        request->send(200, "text/plain", "0.01");
        });
    /*
        Add more custom functionality here. 
        The recomendaton is to separate static content from functionality 
        that interacts directly with the ESP32 but starting your routes with /api/...
    */
    ledApiRoutes(ledControl);

    // This serves the static content of your webpage, it needs to be uploaded to the ESP32's file storage separately
    webServer.serveStatic("/", fs, "/").setDefaultFile("index.html");

    webServer.begin();
    Serial.println("HTTP server started");
}

void ledApiRoutes(LedController* ledControl) {
    webServer.on("^\/api\/led\/power\/(0|1)$", [ledControl](AsyncWebServerRequest* request) {
        String state = request->pathArg(0);
        bool turnOn = state.charAt(0) > 48;

        ledControl->setPower(turnOn);

        request->send(200, "text/plain", state);
        });

    webServer.on("^\/api\/led\/delay\/([0-9]+)$", [ledControl](AsyncWebServerRequest* request) {
        String state = request->pathArg(0);
        uint8_t delay = (uint8_t)state.toInt();

        ledControl->setDelay(delay);
        request->send(200, "text/plain", state);
        });

    webServer.on("^\/api\/led\/bright\/([0-9]+)$", [ledControl](AsyncWebServerRequest* request) {
        String state = request->pathArg(0);
        uint8_t brightness = (uint8_t)state.toInt();

        ledControl->setBrightness(brightness);
        request->send(200, "text/plain", state);
        });

    webServer.on("^\/api\/led\/mode\/([0-9]+)\/([0-9]+)$", [ledControl](AsyncWebServerRequest* request) {
        String state = request->pathArg(0);
        String arg = request->pathArg(1);
        uint8_t mode = (uint8_t)state.toInt();
        uint32_t length = (uint32_t)arg.toInt();

        ledControl->setMode(mode, length);

        String msg = state + ", " + arg;
        request->send(200, "text/plain", msg);
        });

    webServer.on("^\/api\/led\/palette\/([0-9]+)\/([0-9]+)$", [ledControl](AsyncWebServerRequest* request) {
        String state = request->pathArg(0);
        String arg = request->pathArg(1);
        uint32_t paletteIndex = (uint32_t)state.toInt();
        uint32_t length = (uint32_t)arg.toInt();

        ledControl->setPalette(paletteIndex,length);
        request->send(200, "text/plain", state);
        });
}

void handleWeb(fs::FS& fs, LedController *ledControl) {
    static bool webServerStarted = false;

    // check for connection
    if (WiFi.status() == WL_CONNECTED) {
        if (!webServerStarted) {
            // turn off the board's LED when connected to wifi
            Serial.println();
            Serial.println("WiFi connected");
            Serial.print("IP address: ");
            Serial.println(WiFi.localIP());
            webServerStarted = true;
            setupWeb(fs,ledControl);
        }
        webServer.begin();
    }
}