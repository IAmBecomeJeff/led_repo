// Pool Noodle Totems
//		by JeffKarle

// Includes
#include "includes.h"



void setup() {
	if (DEBUG) {
		Serial.begin(57600);
		Serial.setTimeout(1500);
	}

	delay(1000);

	if (DEBUG) { Serial.println("DEBUG ON"); }

	LEDS.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(master_leds, NUM_LEDS);
	LEDS.setBrightness(MAX_BRIGHT);
	LEDS.setCorrection(TypicalLEDStrip);
	set_max_power_in_volts_and_milliamps(5, 3000);
	if (DEBUG) { Serial.println("LEDs ADDED"); }

	random16_set_seed(4832);
	random16_add_entropy(analogRead(2));

	current_leds.current_palette = CRGBPalette16(CRGB::Black);
	current_leds.target_palette = RainbowColors_p;
	current_leds.mode_name = JUGGLE;
	current_leds.delay_time = 10;
	
	if (DEBUG) { Serial.println("CURRENT_LED ARRAY INITIALIZED"); }

	FastLED.clear(); FastLED.show(); FastLED.delay(5);
	if (DEBUG) {
		fill_solid(master_leds, NUM_LEDS, CRGB::Red);	LEDS.delay(500);
		fill_solid(master_leds, NUM_LEDS, CRGB::Blue);  LEDS.delay(500);
		fill_solid(master_leds, NUM_LEDS, CRGB::Green); LEDS.delay(500);
		LEDS.clear();									LEDS.delay(500);
	}
	if (DEBUG) { Serial.println("SETUP COMPLETE"); }
}

void loop() {
	random16_add_entropy(random());

	EVERY_N_MILLISECONDS(50) {
		nblendPaletteTowardPalette(current_leds.current_palette, current_leds.target_palette, 24);
	}
	
	// Update delay times
	current_delay = current_leds.delay_time;
	next_delay = next_leds.delay_time;

	// Apply effect to current LEDS
	EVERY_N_MILLIS_I(current_timer, current_delay) {
		current_timer.setPeriod(current_delay);
		switch_mode(current_leds);
	}

	// Apply effect to next LEDs if in transition
	EVERY_N_MILLIS_I(next_timer, next_delay){
		if(in_transition){
			next_timer.setPeriod(next_delay);
			switch_mode(next_leds);
		}
	}
	
	if(in_transition){
		switch(transition_type){
			case BLENDING:	
				for(uint16_t i = 0; i < NUM_LEDS; i++){	master_leds[i] = blend(current_leds.led_data[i], next_leds.led_data[i], blending_ratio); }
				break;
		}
	}else{
		for(uint16_t i = 0; i < NUM_LEDS; i++){ master_leds[i] = current_leds.led_data[i] ;}
	}

	FastLED.show();
}