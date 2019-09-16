#include "FastLED.h"

#define DATA_PIN 7
#define COLOR_ORDER RGB
#define LED_TYPE WS2812
#define NUM_LEDS 20

uint8_t max_bright = 64;
struct CRGB leds[NUM_LEDS];
CRGBPalette16 current_palette = RainbowStripeColors_p;

int icosahedron[4][5];

uint8_t pal_index = 0;
uint8_t delta = 88;
uint8_t increment = 2;
uint8_t ico_delay = 20;

void setup(){
	LEDS.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS);
	FastLED.setBrightness(max_bright);
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
	ico_palette();
	FastLED.show();
	FastLED.delay(ico_delay);
}

void ico_palette(){
	for (int i = 0; i < 4; i++ ){
		for (int j = 0; j < 5; j++){
			leds[icosahedron[i][j]] = ColorFromPalette(current_palette, pal_index + i * delta, 255);
		}
	}
	pal_index += increment;
}
