#include <FastLED.h>
#include "variables.h"
#include "gradient_palettes.h"
#include "support_functions.h"
#include "read_keyboard.h"
#include "amoeboid.h"

void setup() { 
	Serial.begin(57600);
	Serial.println("Beginning life cycle... ");
	LEDS.addLeds<CHIPSET,DATA_PIN,CLOCK_PIN,COLOR_ORDER>(leds,NUM_LEDS);
	LEDS.setBrightness(max_bright);
	set_max_power_in_volts_and_milliamps(5, 2000);
}

void loop() { 

	// Check for keyboard input
	readkeyboard();

	// Blend palettes
	EVERY_N_MILLISECONDS(50) {
		nblendPaletteTowardPalette(current_palette, target_palette, paletteChanges);
	}
	
	// Update to a random palette
	EVERY_N_SECONDS(20) {
		if (palette_switch) {
			palette_number = random8(g_gradient_palette_count + 1);
			target_palette = g_gradient_palettes[palette_number];
			Serial.println("Attempting  meiosis...");
			print_palette(palette_number);
		}
	}
	
	// Set pixels
	EVERY_N_MILLIS_I(this_timer, this_delay){
		this_timer.setPeriod(this_delay);
		amoeba();
	}
	
	// Show pixels
	FastLED.show();
}
