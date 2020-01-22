#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

// Find index of current (target) palette
void updatePaletteIndex(LEDStruct& leds) {
	for (int i = 0; i < palette_count; i++) {
		if (leds.target_palette == palettes[i]) {
			leds.palette_index = i;
			break;
		}
	}
}

// Initialization function
void initialize() {
	// Initialize curr_leds
	fill_solid(curr_leds.led_data, NUM_LEDS, CRGB::Black);
	curr_leds.array_type = CURRENT;
	curr_leds.current_palette = Colorfull_gp;
	curr_leds.target_palette = Magenta_Evening_gp;
	updatePaletteIndex(curr_leds);
	curr_leds.mode_name = JUGGLE;

	// Initialize next_leds
	fill_solid(next_leds.led_data, NUM_LEDS, CRGB::Black);
	next_leds.array_type = NEXT;
}



// Change pattern 
void change_pattern() {
	// Transition variables
	in_transition    = 1;
	transition_type  = BLENDING;
	transition_speed = 4;
	transition_ratio = 0;

	// Next LED Variables
	next_leds.mode_initialized = 0;
	next_leds.mode_number = random8(ARRAY_SIZE(ModeList));
	next_leds.mode_name = ModeList[next_leds.mode_number];
	
}

// Change palette
void change_palette() {
	if (curr_leds.use_palette) {
		curr_leds.palette_index = random8(palette_count);
		curr_leds.target_palette = palettes[curr_leds.palette_index];
	}
}

// Transition functions

void blending() {
	for (uint16_t i = 0; i < NUM_LEDS; i++) { master_leds[i] = blend(curr_leds.led_data[i], next_leds.led_data[i], transition_ratio); }
	EVERY_N_MILLIS(transition_speed * 4) { transition_ratio++;	}
	if (transition_ratio == 255) {
		in_transition = 0;
		curr_leds = next_leds;
		curr_leds.array_type = CURRENT;
		fill_solid(next_leds.led_data, NUM_LEDS, CRGB::Black);
	}
}



void switch_transition(TransitionType tt) {
	switch (tt) {
		case BLENDING:
			blending();
			break;

		default: 
			blending();
			break;
	}
}