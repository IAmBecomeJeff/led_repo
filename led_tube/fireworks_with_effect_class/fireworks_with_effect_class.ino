#include <Arduino.h>
#include <FastLED.h>
#include "vars.h"

// Effects
#include "ledeffect.h"
//#include "trails.cpp"
//#include "bpm.cpp"
//#include "strobe.cpp"
#include "firework.h"

// Master LED array
CRGBArray<NUM_LEDS> leds;
CRGBSet ledData(leds(0,NUM_LEDS));

// All LED effects
// TrailEffect trail1(1,0,false);
// TrailEffect trail2(NUM_LEDS-1,1,true,10,0);
// StrobeEffect strobe1;
// BPMEffect bpm1(240);
FireworkEffect firework1(0,0);
FireworkEffect firework2(0,0);
FireworkEffect firework3(0,0);
FireworkEffect firework4(40,0);
FireworkEffect firework5(100,0);
FireworkEffect firework6(200,0);
FireworkEffect firework7(150,0);
FireworkEffect firework8(0,0);
FireworkEffect firework9(0,0);
FireworkEffect firework10(0,0);
FireworkEffect firework11(0,0);
FireworkEffect firework12(0,0);
FireworkEffect firework13(0,0);
FireworkEffect firework14(0,0);
FireworkEffect firework15(0,0);

LedEffect *effects[] = { &firework1, &firework2, &firework3, &firework4, &firework5, &firework6, &firework7, &firework8, &firework9, &firework10, &firework11, &firework12, &firework13, &firework14, &firework15 };

const uint8_t num_effects = sizeof( effects ) / sizeof(effects[0]);
uint8_t frame_number = 0;




void setup() {
  // Set up serial connection
  Serial.begin(57600);
  Serial.setTimeout(1500);

  delay(1500);

  if (DEBUG) { Serial.println("DEBUG ON"); }
  else { Serial.println("DEBUG OFF"); }

  // Setup LEDS
  FastLED.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds,NUM_LEDS);
  FastLED.setBrightness(MAX_BRIGHTNESS);
  FastLED.clear();
  FastLED.show();

// Clear LEDS and then flash red, green, blue just as a quick test
  FastLED.clear(); FastLED.show(); FastLED.delay(500);
  if (DEBUG) {
    leds.fill_solid(CRGB::Red); FastLED.show(); FastLED.delay(500);
    leds.fill_solid(CRGB::Green); FastLED.show(); FastLED.delay(500);
    leds.fill_solid(CRGB::Blue); FastLED.show(); FastLED.delay(500);
    FastLED.clear(); FastLED.show(); FastLED.delay(500);
  }

  effects[0]->enable();
  effects[1]->enable();
  effects[2]->enable();
  effects[3]->enable();
  effects[4]->enable();
  effects[5]->enable();
  effects[6]->enable();
  effects[7]->enable();
  effects[8]->enable();
  effects[9]->enable();
  effects[10]->enable();
  effects[11]->enable();
  effects[12]->enable();
  effects[13]->enable();
  effects[14]->enable();
}




void loop() {
  
  // Clear the global LED array
  fill_solid(leds, NUM_LEDS, CRGB::Black);
  
  // Iterate over each effect
  for(int i = 0; i< num_effects; i++) { 
    
    //Skip any that are disabled
    if(!(effects[i]->enabled)){
      if (DEBUG) { Serial.print("Effect render skipped - effect disabled for effect: "); Serial.println(i); }
      continue;
    }

    // Render each effect if it's delay time has elapsed
    if (DEBUG) { Serial.print("Beginning effect & frame: "); Serial.print(i); Serial.print(" "); Serial.println(frame_number); }
    effects[i] -> update();
    if (DEBUG) { Serial.print("Done with effect & frame: "); Serial.print(i); Serial.print(" "); Serial.println(frame_number); }

    // Copy the data to the global array
    for(uint16_t j = 0; j< NUM_LEDS; j++){
      ledData[j] += (effects[i]->led_data)[j];
    }
  }

  //firework1.debug_info();

  if (DEBUG) { Serial.print("Global frame complete: "); Serial.println(frame_number); }
  if (DEBUG) { frame_number++; }

  FastLED.show();
}
  
