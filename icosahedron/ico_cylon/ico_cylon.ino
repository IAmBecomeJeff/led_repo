//#define FASTLED_ALLOW_INTERRUPTS 0
#include "FastLED.h"

// How many leds in your strip?
#define NUM_LEDS 20

// For led chips like Neopixels, which have a data line, ground, and power, you just
// need to define DATA_PIN.  For led chipsets that are SPI based (four wires - data, clock,
// ground, and power), like the LPD8806, define both DATA_PIN and CLOCK_PIN
#define DATA_PIN 7
//#define CLOCK_PIN 13

// Define the array of leds
CRGB leds[NUM_LEDS];
int order[20]= {0, 1, 2, 3, 4, 11, 12, 13, 14, 5, 6, 7, 8, 9, 10, 15, 18, 19, 17, 16};

void setup() { 
  Serial.begin(57600);
  Serial.println("resetting");
  LEDS.addLeds<WS2812,DATA_PIN,RGB>(leds,NUM_LEDS);
  LEDS.setBrightness(100);
}

void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(128); } }

void loop() { 
  static uint8_t hue = 0;
  //Serial.print("x");
  // First slide the led in one direction
  for(int i = 0; i < NUM_LEDS; i++) {
    // Set the i'th led to red 
    leds[order[i]] = CHSV(hue++, 255, 255);
    Serial.println(i);
    // Show the leds
    FastLED.show(); 
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(80);
  }


  // Now go in the other direction.  
  for(int i = (NUM_LEDS)-1; i >= 0; i--) {
    // Set the i'th led to red 
    leds[order[i]] = CHSV(hue++, 255, 255);
    Serial.println(i);
    // Show the leds
    FastLED.show();
    // now that we've shown the leds, reset the i'th led to black
    // leds[i] = CRGB::Black;
    fadeall();
    // Wait a little bit before we loop around and do it again
    delay(80);
  }
}
