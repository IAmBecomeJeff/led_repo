/*

/*------------------------------------------------------------------------------------------
--------------------------------------- Start of variables ---------------------------------
------------------------------------------------------------------------------------------*/


#define qsubd(x, b)  ((x>b)?wavebright:0)                     // A digital unsigned subtraction macro. if result <0, then => 0. Otherwise, take on fixed value.
#define qsuba(x, b)  ((x>b)?x-b:0)                            // Unsigned subtraction macro. if result <0, then => 0.

#include "FastLED.h"                                          // https://github.com/FastLED/FastLED
#include "EEPROM.h"                                           // This is included with base install


// Fixed definitions cannot change on the fly.
#define LED_DT 7                                             // Serial data pin for all strands
#define COLOR_ORDER GRB                                       // It's GRB for WS2812
#define LED_TYPE WS2812                                       // Alternatively WS2801, or WS2812
#define MAX_LEDS 197                                          // Maximum number of LED's defined (at compile time).


// Initialize changeable global variables.
uint8_t NUM_LEDS;                                             // Number of LED's we're actually using, and we can change this only the fly for the strand length.

uint8_t max_bright = 255;                                     // Overall brightness definition. It can be changed on the fly.

struct CRGB leds[MAX_LEDS];                                   // Initialize our LED array.

CRGBPalette16 currentPalette;                                 // Use palettes instead of direct CHSV or CRGB assignments
CRGBPalette16 targetPalette;                                  // Also support smooth palette transitioning
TBlendType    currentBlending;                                // NOBLEND or LINEARBLEND


// EEPROM location definitions.
#define STARTMODE 0
#define STRANDLEN 1

uint8_t ledMode;                                              // Starting mode is typically 0.
uint8_t maxMode = 38;                                         // Maximum number of modes.
uint8_t demotime = 10;                                        // Set the length of the demo timer.


// Generic/shared routine variables ----------------------------------------------------------------------
uint8_t startindex = 0;
uint8_t thisbeat = 24;                                             // Standard beat
uint8_t thisbright = 255;                                       // Standard brightness
int thisdelay = 8;                  							// Standard delay
uint8_t palchg = 2;
uint8_t numdots = 2;                          
uint8_t thisdiff = 64;                                         // Standard palette jump
uint8_t thisfade = 16;                                       // Standard fade rate
uint8_t thisindex = 0;                                        // Standard palette index
uint8_t thishue;
int leftArray[35];
int rightArray[35];
int backArray[61];
int frontArray[66];
int LeftToRight[68];




extern const TProgmemRGBGradientPalettePtr gGradientPalettes[]; // These are for the fixed palettes in gradient_palettes.h
extern const uint8_t gGradientPaletteCount;                     // Total number of fixed palettes to display.
uint8_t gCurrentPaletteNumber = 0;                              // Current palette number from the 'playlist' of color palettes
uint8_t currentPatternIndex = 0;                                // Index number of which pattern is current



// Display functions -----------------------------------------------------------------------

// Support functions
#include "make_palettes.h"

// Display routines
#include "pedalArrays.h"
#include "gradient_palettes.h"
#include "juggle_pal.h"




/*------------------------------------------------------------------------------------------
--------------------------------------- Start of code --------------------------------------
------------------------------------------------------------------------------------------*/


void setup() {
  
  delay(2000);                                                // Soft startup to ease the flow of electrons.

  LEDS.setBrightness(max_bright);                                                 // Set the generic maximum brightness value.
  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER >(leds, MAX_LEDS);           // APA102 or WS2801 definition
//  LEDS.addLeds<LED_TYPE, LED_DT, LED_CK COLOR_ORDER >(leds, MAX_LEDS);                   // WS2812 definition
  
  set_max_power_in_volts_and_milliamps(5, 1000);                                  //5V, 1000mA

  random16_set_seed(4832);                                                        // Awesome randomizer of awesomeness
  random16_add_entropy(analogRead(2));
  int ranstart = random16();

  Serial.println("---SETUP COMPLETE---");
  
  ledMode = EEPROM.read(STARTMODE);                                               // Location 0 is the starting mode
  NUM_LEDS = EEPROM.read(STRANDLEN); if(NUM_LEDS >MAX_LEDS) NUM_LEDS = MAX_LEDS;  // Location 1 is the number of LED's
  //strandId = EEPROM.read(STRANDID);                                             // Which strand are we, anyways?

  currentPalette  = CRGBPalette16(CRGB::Black);
  targetPalette   = RainbowColors_p;
  currentBlending = LINEARBLEND;
  
  // Set up arrays
  for (uint8_t i = 0; i < 61; i++) {
	  backArray[i] = i;
  }
  for (uint8_t i = 0; i < 35; i++) {
	  rightArray[i] = i + 61;
	  leftArray[i] = i + 162;
  }
  for (uint8_t i = 0; i < 66; i++) {
	  frontArray[i] = i + 96;
  }

  //strobe_mode(ledMode, 1);                                                        // Initialize the first sequence
  
} // setup()



//------------------MAIN LOOP---------------------------------------------------------------
void loop() {
  
  //demo_check();                                                             // If we're in demo mode, check the timer to see if we need to increase the strobe_mode value.

  EVERY_N_MILLISECONDS(50) {                                                 // Smooth palette transitioning runs continuously.
    uint8_t maxChanges = 24; 
    nblendPaletteTowardPalette(currentPalette, targetPalette, maxChanges);   
  }

  EVERY_N_SECONDS(5) {                                                        // If selected, change the target palette to a random one every 5 seconds.
    if (palchg == 1) SetupSimilar4Palette();
    if (palchg == 2) SetupRandom4Palette();
    if (palchg == 3) SetupRandom16Palette();
}

  EVERY_N_MILLIS_I(thistimer, thisdelay) {                                    // Sets the original delay time.
    thistimer.setPeriod(thisdelay);                                           // This is how you update the delay value on the fly.
    juggle_from_center();
	//strobe_mode(ledMode, 0);                                                  // Strobe to display the current sequence, but don't initialize the variables, so mc=0;
  }

//  if(glitter) addglitter(10);                                                 // If the glitter flag is set, let's add some.
  
  FastLED.show();                                                             // Power managed display of LED's.
  
} // loop()
