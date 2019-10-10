#include <FastLED.h>
#include "variables.h"
#include "gradient_palettes.h"
#include "support_functions.h"
#include "amoeboid.h"
#include "blend_into_rainbow.h"
#include "ripples.h"






void setup() {
	Serial.begin(57600);
	Serial.println("Beginning life cycle... ");
	LEDS.addLeds<CHIPSET, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS);
	LEDS.setBrightness(max_bright);
	set_max_power_in_volts_and_milliamps(5, 2000);
}




void loop() {

	// Blend palettes
	EVERY_N_MILLISECONDS(50) {
		nblendPaletteTowardPalette(current_palette, target_palette, paletteChanges);
	}

	EVERY_N_MILLISECONDS(200) {
		hue++;
	}

	EVERY_N_SECONDS(30) {
		randomPattern();
	}

	// Update to a random palette
	EVERY_N_SECONDS(20) {
		if (palette_switch) {
			random_palette();
		}
	}

	// Set pixels
	EVERY_N_MILLIS_I(this_timer, this_delay) {
		this_timer.setPeriod(this_delay);
		Patterns[current_pattern_number]();
	}

	// Show pixels
	FastLED.show();
}
