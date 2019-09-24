#include <FastLED.h>
#include "gradient_palettes.h"

#define NUM_LEDS 300 
#define DATA_PIN 7
#define CLOCK_PIN 14
#define CHIPSET APA102
#define COLOR_ORDER BGR

// Array of LEDs
CRGB leds[NUM_LEDS];

// Palette variables
CRGBPalette16 current_palette;
CRGBPalette16 target_palette = RainbowColors_p;
uint8_t paletteChanges = 24;
uint8_t palette_index = 0;
uint8_t palette_index_beat = 10;
uint8_t palette_index_forward_beat = 25;
uint8_t palette_index_backward_beat = 30;

// Operational Variables
uint8_t fade_val = 180;
uint8_t this_delay = 5;
uint8_t hue = 0;

// Positional Variables
int position = 0;
int position_beat = 4;

uint8_t forward_edge;
uint8_t forward_range = 10;
uint8_t forward_beat = 9;

uint8_t backward_edge;
uint8_t backward_range = 14;
uint8_t backward_beat = 21;



void setup() { 
	Serial.begin(57600);
	Serial.println("resetting");
	LEDS.addLeds<CHIPSET,DATA_PIN,CLOCK_PIN,COLOR_ORDER>(leds,NUM_LEDS);
	LEDS.setBrightness(84);
}

// Fade function
void fadeall() { for(int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(fade_val); } }


// Amoeba program
void amoeba(){
	
	// Fade everything
	fadeall();
	
	// Determine the current LED
	position = beatsin16(position_beat, 0, NUM_LEDS-1);
	
	// Also determine index of palette
	//palette_index = beatsin8(palette_index);
	//leds[position] = ColorFromPalette(current_palette, palette_index);
	leds[position] = CHSV(hue, 255,255);
	forward_edge = beatsin16(forward_beat,0,forward_range);
	backward_edge = beatsin16(backward_beat,0,backward_range);
	
	for (int i = 0; i < forward_edge; i++){
		if(position + i < NUM_LEDS-1){
			palette_index = beatsin8(palette_index_forward_beat);
			//leds[position+i] = ColorFromPalette(current_palette, palette_index);
		  leds[position+i] = CHSV(hue,255,255);
		}
	}
	
	for (int i = 0; i < backward_edge; i++){
		if(position - i > 0){
			palette_index = beatsin8(palette_index_backward_beat);
			//leds[position-i] = ColorFromPalette(current_palette, palette_index);
      leds[position-i] = CHSV(hue,255,255);
		}
	}
 hue++;
}


void loop() { 

	EVERY_N_MILLISECONDS(50) {
		nblendPaletteTowardPalette(current_palette, target_palette, paletteChanges);
	}
	
	EVERY_N_SECONDS(20) {
		target_palette = g_gradient_palettes[random8(g_gradient_palette_count+1)];
	}
	
	EVERY_N_MILLIS_I(this_timer, this_delay){
		this_timer.setPeriod(this_delay);
		amoeba();
	}
	
	FastLED.show();
}
