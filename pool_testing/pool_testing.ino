// Pool Noodle Totems
//		by JeffKarle

// Includes
#include "includes.h"

void setup() {
	if (DEBUG) { Serial.begin(57600); Serial.setTimeout(1500); Serial.println("DEBUG ON"); }

	delay(1000);

	LEDS.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(master_leds, NUM_LEDS);
	LEDS.setBrightness(MAX_BRIGHT);
	LEDS.setCorrection(TypicalLEDStrip);
	set_max_power_in_volts_and_milliamps(5, 3000);

	if (DEBUG) { Serial.println("LEDs ADDED"); }

	random16_set_seed(4832);
	random16_add_entropy(analogRead(2));

	FastLED.clear(); FastLED.show(); FastLED.delay(20);

	if (DEBUG) {
		fill_solid(master_leds, NUM_LEDS, CRGB::Red);	LEDS.delay(500);
		fill_solid(master_leds, NUM_LEDS, CRGB::Blue);  LEDS.delay(500);
		fill_solid(master_leds, NUM_LEDS, CRGB::Green); LEDS.delay(500);
		LEDS.clear();									LEDS.delay(500);
	}

	initialize();

	if (DEBUG) { Serial.println("SETUP COMPLETE"); }
}

void loop() {
	random16_add_entropy(random());

	EVERY_N_MILLISECONDS(50) {
		nblendPaletteTowardPalette(curr_leds.current_palette, curr_leds.target_palette, 24);
	}
	
	// Update delay times
	curr_delay = curr_leds.delay_time;

	// Apply effect to current LEDS
	EVERY_N_MILLIS_I(curr_timer, curr_delay) {
		curr_timer.setPeriod(curr_delay);
		switch_mode(curr_leds);
	}
	

	for(uint16_t i = 0; i < NUM_LEDS; i++){ master_leds[i] = curr_leds.led_data[i] ;}
	
	if (DEBUG) { EVERY_N_SECONDS(5) { LEDDebug(curr_leds); }; }


	FastLED.show();
}