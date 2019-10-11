//***************************************************************
// Messing with blending a moving cycling color into a moving
// background rainbow.
//
// Marc Miller, Sept 2019
//***************************************************************

#include "FastLED.h"
#define DATA_PIN    7
#define CLK_PIN     14
#define LED_TYPE    APA102
#define COLOR_ORDER GRB
#define NUM_LEDS    300
#define BRIGHTNESS  100
CRGB leds[NUM_LEDS];

uint16_t pos, pos2, pos3;  //stores a position for color being blended in
uint8_t hue = 115;
uint8_t hue2;  //stores a color
uint8_t bpm  = 4;
uint8_t bpm2 = 6;
uint8_t bpm3 = 5;



//---------------------------------------------------------------
void setup() {
  Serial.begin(115200);  // Allows serial monitor output (check baud rate)
  delay(2500); // startup delay
  //FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);
  set_max_power_in_volts_and_milliamps(5, 2000);
  Serial.println("Setup done. \n");
}


//---------------------------------------------------------------
void loop() {
  EVERY_N_MILLISECONDS(150){
    hue++;  //used to cycle through the rainbow
  }

  fill_rainbow(leds, NUM_LEDS, hue, 255/NUM_LEDS/4);  //draw part of the rainbow into the strip
  fadeToBlackBy(leds, NUM_LEDS, 70);  //fade the whole strip down some

  EVERY_N_MILLISECONDS(10) {
    pos  = beatsin16(bpm , 0, NUM_LEDS-1);
    pos2 = beatsin16(bpm2, 0, NUM_LEDS-1);
    pos3 = beatsin16(bpm3, 0, NUM_LEDS-1,0,32768);
    //pos++;
    //if (pos == NUM_LEDS) { pos = 0; }  //reset to begining
  }
  //Serial.println(pos);

  EVERY_N_MILLISECONDS(5){
    hue2 = hue2 - 1;  //used to change the moving color
  }
  CRGB blendThisIn  = CHSV(hue2, 140, 255);  //color to blend into the background
  CRGB blendThisIn2 = CHSV(hue2, 170, 255);  //color to blend into the background
  CRGB blendThisIn3 = CHSV(hue2, 210, 255);  //color to blend into the background
  CRGB blendThisIn4 = CHSV(hue2, 255, 255);  //color to blend into the background

  CRGB blendThisIn21  = CHSV(hue2+128, 140, 255);  //color to blend into the background
  CRGB blendThisIn22 = CHSV(hue2+128, 170, 255);  //color to blend into the background
  CRGB blendThisIn23 = CHSV(hue2+128, 210, 255);  //color to blend into the background
  CRGB blendThisIn24 = CHSV(hue2+128, 255, 255);  //color to blend into the background
  
  static uint8_t blendAmount = 240;  //amount of blend  [range: 0-255]

  leds[pos]              = nblend(leds[pos],              blendThisIn4, blendAmount/3);
  leds[(pos+1)%NUM_LEDS] = nblend(leds[(pos+1)%NUM_LEDS], blendThisIn3, blendAmount/2);
  leds[(pos+2)%NUM_LEDS] = nblend(leds[(pos+2)%NUM_LEDS], blendThisIn2, blendAmount);
  leds[(pos+3)%NUM_LEDS] = nblend(leds[(pos+3)%NUM_LEDS], blendThisIn,  blendAmount);
  leds[(pos+4)%NUM_LEDS] = nblend(leds[(pos+4)%NUM_LEDS], blendThisIn2, blendAmount);
  leds[(pos+5)%NUM_LEDS] = nblend(leds[(pos+5)%NUM_LEDS], blendThisIn3, blendAmount/2);
  leds[(pos+6)%NUM_LEDS] = nblend(leds[(pos+6)%NUM_LEDS], blendThisIn4, blendAmount/3);

  leds[pos2]              = nblend(leds[pos2],              blendThisIn24, blendAmount/3);
  leds[(pos2+1)%NUM_LEDS] = nblend(leds[(pos2+1)%NUM_LEDS], blendThisIn23, blendAmount/2);
  leds[(pos2+2)%NUM_LEDS] = nblend(leds[(pos2+2)%NUM_LEDS], blendThisIn22, blendAmount);
  leds[(pos2+3)%NUM_LEDS] = nblend(leds[(pos2+3)%NUM_LEDS], blendThisIn21,  blendAmount);
  leds[(pos2+4)%NUM_LEDS] = nblend(leds[(pos2+4)%NUM_LEDS], blendThisIn22, blendAmount);
  leds[(pos2+5)%NUM_LEDS] = nblend(leds[(pos2+5)%NUM_LEDS], blendThisIn23, blendAmount/2);
  leds[(pos2+6)%NUM_LEDS] = nblend(leds[(pos2+6)%NUM_LEDS], blendThisIn24, blendAmount/3);

  leds[pos3]              = nblend(leds[pos3],              blendThisIn4, blendAmount/3);
  leds[(pos3+1)%NUM_LEDS] = nblend(leds[(pos3+1)%NUM_LEDS], blendThisIn3, blendAmount/2);
  leds[(pos3+2)%NUM_LEDS] = nblend(leds[(pos3+2)%NUM_LEDS], blendThisIn2, blendAmount);
  leds[(pos3+3)%NUM_LEDS] = nblend(leds[(pos3+3)%NUM_LEDS], blendThisIn,  blendAmount);
  leds[(pos3+4)%NUM_LEDS] = nblend(leds[(pos3+4)%NUM_LEDS], blendThisIn2, blendAmount);
  leds[(pos3+5)%NUM_LEDS] = nblend(leds[(pos3+5)%NUM_LEDS], blendThisIn3, blendAmount/2);
  leds[(pos3+6)%NUM_LEDS] = nblend(leds[(pos3+6)%NUM_LEDS], blendThisIn4, blendAmount/3);
  FastLED.show();  //update the display

  //EVERY_N_SECONDS(random8(5,21)) {
    //delay(3000);  //randomly stop the animation to observe the blending
  //}

}//end_main_loop
