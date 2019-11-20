// --- This basic sketch / example uses 1 LED strip with 144 Leds
// --- You can change this in vars.h inside the /include folder

// Fast LED & other system imports
#include <FastLED.h>

// Our custom defines
#include "vars.h"
#include "gradient_palettes.h"

// Our led effect classes
#include "ledeffect.h"

//#include "bpm.h"
#include "cylon.h"
#include "fire.h"
#include "firework.h"
#include "halloween.h"
//#include "ripple.h"
//#include "strobe.h"
//#include "trails.h"

// Create the master led array
// Declarations such as NUM_LEDS... are in variables.h
CRGBArray<NUM_LEDS> leds;
CRGBSet ledData(leds(0, NUM_LEDS));

// Create effects here:
CylonEffect		effect0(160,4);
//FireworkEffect	effect1(0, 0);
FireEffect		effect2(80, 90);
HalloweenEffect effect3(4);
FireMirrorEffect effect4(80,66);

// Array to hold effects
LedEffect* effects[] = { &effect0, &effect2, &effect3 };

const uint8_t num_effects = sizeof(effects) / sizeof(effects[0]);

void setup() {
  Serial.println("<BEGIN SETUP>");

  // Enable Serial
  Serial.begin(SERIAL_BAUDRATE);
  delay(1000);

  // Setup LEDs
  FastLED.addLeds<APA102, LED_PIN, CLOCK_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(MAX_BRIGHT);
  FastLED.setCorrection(TypicalLEDStrip);

  // Clear LEDS and then flash red, green, blue just as a quick test
  FastLED.clear(); FastLED.show(); FastLED.delay(500);

  if (STARTUP_DEBUG) {
    leds.fill_solid(CRGB::Red); FastLED.show(); FastLED.delay(500);
    leds.fill_solid(CRGB::Green); FastLED.show(); FastLED.delay(500);
    leds.fill_solid(CRGB::Blue); FastLED.show(); FastLED.delay(500);
    FastLED.clear(); FastLED.show(); FastLED.delay(500);
  }


  // Enable whatever effects we want
  effect0.enable();
  //effect2.enable();

  Serial.println("<END SETUP>");
  Serial.println(" ");
}

void renderActiveEffects() {
  // Iterate over every effect
  Serial.println("In renderActiveEffects");
  for(int i=0; i<num_effects; i++) {
    // Skip inactive / disabled effects
    Serial.print("effect: ");
    Serial.println(i);
    if (!(effects[i] -> enabled)) {
      continue;
    }

    // Call the effect's render() method, which stores the rendered led data in an instance var
    effects[i] -> render();

    // Copy the led data over to the global array (additively)
    for (uint8_t j=0; j<NUM_LEDS-1; j++) {
      ledData[j] += (effects[i] -> leddata)[j];
    }
  }
  Serial.println("finished with renderActiveEffects");
}

// Handle input - just a single character.
// This could come from anywhere, but right now it's just Serial/keyboard.
void handleInput(char input) {
  Serial.println("--> Input Received");

  // Super basic right now - just enable the number specified.
  // If not 0-9, do nothing.
  // Note: 0-9 is represented by char codes 48 thru 57
  if (input < 48 || input > 57) {
    Serial.print("   Garbage input detected: ");
    Serial.println(input);
    return;
  }

  Serial.print("--> Valid input detected: ");
  Serial.println(input);

  Serial.print("--> Toggling effect ");
  Serial.println(input - 48);
  Serial.println(" ");

  effects[input - 48]->toggle();
}

// Print all current effects to console (and their status)
void displayEffectData() {
  Serial.println("--- Current Effects ---");

  for(uint8_t i=0; i<num_effects; i++){
    Serial.print("--> Effect ");
    Serial.print(i);
    Serial.print(": ");

    if (effects[i]->enabled) {
      Serial.print("enabled ");
    } else {
      Serial.print("disabled ");
    }

    Serial.println(" ");
  }

  Serial.println("-----------------------");
  Serial.println(" ");
}

// 10ms = 200fps
void loop() {
  EVERY_N_MILLIS(10) {
    //FastLED.clear();
    Serial.println("in loop");
    renderActiveEffects();
    FastLED.show();
  }

  EVERY_N_MILLIS(5000) {
    displayEffectData();
  }

  if (Serial.available() > 0) {
    handleInput(Serial.read());
  }
}
