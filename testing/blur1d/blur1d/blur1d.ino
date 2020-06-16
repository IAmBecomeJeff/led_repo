#include <FastLED.h>

#define DATA_PIN 11
#define CLCK_PIN 13
#define NUM_LEDS 288
#define LED_TYPE APA102
#define COLOR_ORDER BGR
#define BRIGHTNESS 64

CRGB leds[NUM_LEDS];

uint16_t pos = 0;
int8_t pos_dir = 1;
uint8_t hue = 0;
uint8_t this_delay = 20;
uint8_t blur_amt = 255;


void setup() {
  delay(1000);

  FastLED.addLeds<LED_TYPE, DATA_PIN, CLCK_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

}

void pattern(){
  fill_gradient(leds, pos, CHSV(128,255,255), NUM_LEDS, CHSV(192,255,255), FORWARD_HUES);
  for(int i = 0; i < NUM_LEDS; i++){
    if(i % 10 < 1){
      leds[(i) % NUM_LEDS] = CRGB::Black;//CHSV(hue, 255, 255);
    }
    /*
    else{
      leds[(i + pos) % NUM_LEDS] = ColorFromPalette(RainbowColors_p, i % 255, 255, LINEARBLEND);
    }
    */
  }
}

void loop() {

  EVERY_N_MILLIS(this_delay){
    pattern();
    blur1d(leds, NUM_LEDS, blur_amt);
    pos += pos_dir;
    if(pos == NUM_LEDS - 1 || pos == 0){
      pos_dir *= -1;
    }
    hue++;
    FastLED.show();
  }
}
