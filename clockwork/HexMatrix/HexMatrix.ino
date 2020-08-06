#include <FastLED.h>
#include <EEPROM.h>

#define LED_PIN           2          // Output pin for LEDs [2]
#define COLOR_ORDER       RGB         // Color order of LED string [RGB]
#define CHIPSET           WS2811     // LED string type [WS2811]
#define BRIGHTNESS        55         // Overall brightness [255]
#define LAST_VISIBLE_LED  102         // Last LED that's visible [102]
#define MAX_MILLIAMPS     500        // Max current in mA to draw from supply [500]
#define SAMPLE_WINDOW     100         // How many ms to sample audio for [100]
#define DEBOUNCE_MS       20          // Number of ms to debounce the button [20]
#define LONG_PRESS        500         // Number of ms to hold the button to count as long press [500]
#define PATTERN_TIME      10          // Seconds to show each pattern on autoChange [10]
#define kMatrixWidth      8          // Matrix width [8]
#define kMatrixHeight     15          // Matrix height [15]
#define NUM_LEDS (kMatrixWidth * kMatrixHeight)                                       // Total number of Leds
#define MAX_DIMENSION ((kMatrixWidth>kMatrixHeight) ? kMatrixWidth : kMatrixHeight)   // Largest dimension of matrix

CRGB leds[ NUM_LEDS ];

// Used to check RAM availability. Usage: Serial.println(freeRam());
int freeRam () {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

// Button stuff
bool autoChangeVisuals = false;
// Include various patterns
#include "Rainbow.h"
#include "Fire.h"
#include "Squares.h"
#include "Circles.h"
#include "Plasma.h"
#include "Matrix.h"
#include "CrossHatch.h"
#include "Drops.h"
#include "Noise.h"
#include "Snake.h"

// Helper to map XY coordinates to irregular matrix
#define LAST_VISIBLE_LED 95
uint8_t XY (uint8_t x, uint8_t y) {
  // any out of bounds address maps to the first hidden pixel
  if ( (x >= kMatrixWidth) || (y >= kMatrixHeight) ) {
    return (LAST_VISIBLE_LED + 1);
  }

  const uint8_t XYTable[] = {
    96,  97,  98,   0,   1,  99, 100, 101,
   105, 104,   5,   4,   3,   2, 103, 102,
   106,   6,   7,   8,   9,  10,  11, 107,
    19,  18,  17,  16,  15,  14,  13,  12,
    20,  21,  22,  23,  24,  25,  26,  27,
    35,  34,  33,  32,  31,  30,  29,  28,
    36,  37,  38,  39,  40,  41,  42,  43,
    51,  50,  49,  48,  47,  46,  45,  44,
    52,  53,  54,  55,  56,  57,  58,  59,
    67,  66,  65,  64,  63,  62,  61,  60,
    68,  69,  70,  71,  72,  73,  74,  75,
    83,  82,  81,  80,  79,  78,  77,  76,
   108,  84,  85,  86,  87,  88,  89, 109,
   113, 112,  93,  92,  91,  90, 111, 110,
   114, 115, 116,  94,  95, 117, 118, 119
  };

  uint8_t i = (y * kMatrixWidth) + x;
  uint8_t j = XYTable[i];
  return j;
}

void setup() {
  FastLED.addLeds < CHIPSET, LED_PIN, COLOR_ORDER > (leds, NUM_LEDS).setCorrection(TypicalSMD5050);
  //FastLED.setMaxPowerInVoltsAndMilliamps(5, MAX_MILLIAMPS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear(true);
  Serial.begin(57600);
  Serial.print(F("Starting pattern "));
}


void runRainbow(){
  bool isRunning = true;
  Rainbow rainbow = Rainbow();
  while(isRunning) isRunning = rainbow.runPattern();
}

void runFire(){
  bool isRunning = true;
  Fire fire = Fire();
  while(isRunning) isRunning = fire.runPattern();
}

void runSquares(){
  bool isRunning = true;
  Squares squares = Squares();
  while(isRunning) isRunning = squares.runPattern();
}

void runCircles(){
  bool isRunning = true;
  Circles circles = Circles();
  while(isRunning) isRunning = circles.runPattern();
}

void runPlasma(){
  bool isRunning = true;
  Plasma plasma = Plasma();
  while(isRunning) isRunning = plasma.runPattern();
}

void runMatrix(){
  bool isRunning = true;
  Matrix matrix = Matrix();
  while(isRunning) isRunning = matrix.runPattern();
}

void runCrossHatch(){
  bool isRunning = true;
  CrossHatch crossHatch = CrossHatch();
  while(isRunning) isRunning = crossHatch.runPattern();
}

void runDrops(){
  bool isRunning = true;
  Drops drops = Drops();
  while(isRunning) isRunning = drops.runPattern();
}

void runNoise(){
  bool isRunning = true;
  Noise noise = Noise();
  while(isRunning) {
    isRunning = noise.runPattern();
  }
}

void runSnake(){
  bool isRunning = true;
  Snake snake = Snake();
  while(isRunning) {
    isRunning = snake.runPattern();
  }
}

// Run selected pattern
void loop() {
 
      //runRainbow();
      //runFire();
      //runCircles();
      runPlasma();
      //runMatrix();
      //runNoise();
     
  }
