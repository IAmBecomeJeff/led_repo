// Pool Noodle Totems
//		by JeffKarle

// Includes
#include "includes.h"

Mode start_mode = TWINKLE;

// ================ SETUP ================

void setup() {
	if (DEBUG) { Serial.begin(57600); Serial.setTimeout(500); Serial.println("DEBUG ON"); }

	delay(1000);

	FastLED.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(master_leds, NUM_LEDS);
	FastLED.setBrightness(max_bright);
	FastLED.setCorrection(TypicalLEDStrip);
	set_max_power_in_volts_and_milliamps(5, 3000);

	random16_set_seed(4832);
	random16_add_entropy(analogRead(2));

	FastLED.clear(); FastLED.show(); FastLED.delay(50);

	if (DEBUG) {
		fill_solid(master_leds, NUM_LEDS, CRGB::Red);	FastLED.delay(250);
		fill_solid(master_leds, NUM_LEDS, CRGB::Blue);  FastLED.delay(250);
		fill_solid(master_leds, NUM_LEDS, CRGB::Green); FastLED.delay(250);
		FastLED.clear();								FastLED.delay(250);
	}

	// Set up initial parameters for cur_leds and next_leds
	initialize(); 

	if (DEBUG) { Serial.println("SETUP COMPLETE"); }
}





// ================ LOOP ================

void loop() {
	// Add entropy to randomness
	random16_add_entropy(random());
	
	// Check for keyboard updates
	read_keyboard();

	// Change patterns
	EVERY_N_SECONDS_I(modeTimer,20){
		modeTimer.setPeriod(mode_change_time);
		if (mode_change) { change_mode(); }
	}

	// Change palette
	EVERY_N_SECONDS(30) {
		if (random_palette) {
			if (in_transition) { change_palette(next_leds); }
			else { change_palette(curr_leds); }
		}
	}

	// Blend palettes
	EVERY_N_MILLISECONDS(50) {
		nblendPaletteTowardPalette(curr_leds.current_palette, curr_leds.target_palette, 24);
		if(in_transition){ nblendPaletteTowardPalette(next_leds.current_palette, next_leds.target_palette, 24); }
	}	

	// Update delay times
	curr_delay = curr_leds.delay_time;
	next_delay = next_leds.delay_time;
	constrain(curr_delay, 5, 20);
	constrain(next_delay, 5, 20);

	// Apply effect to curr_leds
	EVERY_N_MILLIS_I(curr_timer, curr_delay) {
		curr_timer.setPeriod(curr_delay);
		switch_mode(curr_leds);
	}

	// Apply effect to next_leds
	EVERY_N_MILLIS_I(next_timer, next_delay){
		if (!keyboard_update) {
			if (in_transition) {
				next_timer.setPeriod(next_delay);
				switch_mode(next_leds);
			}
		}
	}
	
	// Add leds from curr_leds (and maybe next_leds) to master_leds
	if (in_transition && !keyboard_update) {
		switch_transition(transition_type);
	}
	else {
		for (uint16_t i = 0; i < NUM_LEDS; i++) { master_leds[i] = curr_leds.led_data[i]; }
	}

	if (DEBUG) {
		EVERY_N_MINUTES(1) { number_of_min_on++; }
		EVERY_N_SECONDS(5) {
			LEDDebug(curr_leds);
			if (in_transition) {
				LEDDebug(next_leds);
			}
			number_of_sec_on = (number_of_sec_on + 5) % 60;
			global_debug();
		}
	}

	FastLED.show();

}