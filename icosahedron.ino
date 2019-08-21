
#include "FastLED.h"

#define DATA_PIN 7
#define COLOR_ORDER GBR
#define LED_TYPE WS2812
#define NUM_LEDS 20

uint8_t max_bright = 255;
struct CRGB leds[NUM_LEDS];

int icosahedron[4][5]

uint8_t hue;
uint8_t index = 0;
uint8_t delta = 10;
uint8_t increment = 4;

void setup(){
	Leds.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS);
	FastLed.setBrightness(max_bright);
	set_max_power_in_volts_and_milliamps(5, 1000);
	
	// Set icosahedron matrix to call via leds[icosahedron[height][pixel]]
	for (int i = 0; i < 5; i++){
		icosahedron[0][i] = i;
		icosahedron[1][i] = 5 + 2*i;
		icosahedron[2][i] = 6 + 2*i;
		icosahedron[3][i] = 15 + i;
	}
}

void loop(){
	ico_fill_rainbow();
	FastLED.show();
}

void ico_fill_rainbow(){
	hue = index;
	for (int i = 0; i < 4; i++ ){
		for (int j = 0; j < 5; j++){
			leds[icosahedron[i][j]] = CHSV(hue, 255, 240);
		}
		hue += delta;
	}
	index += increment;
}

