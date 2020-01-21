#ifndef LED_STRUCT_H
#define LED_STRUCT_H

// LED structure

struct LEDStruct {
	// LED data array
	struct CRGB led_data[NUM_LEDS];

	// Primary variables
	uint8_t brightness;
	uint8_t delay_time;
	CRGBPalette16 current_palette;
	CRGBPalette16 target_palette;
	TBlendType current_blending = LINEARBLEND;
	bool use_palette;
	bool use_full_range = 0;
	uint8_t this_dir;
	uint8_t current_mode_number;
	Mode mode_name;
	bool mode_initialized = 0;

	// Juggle Variables
	uint8_t juggle_index;
	uint8_t juggle_numdots;
	uint8_t juggle_beat;
	uint8_t juggle_fade;
	uint8_t juggle_diff;
	bool juggle_index_reset;

};

LEDStruct current_leds;
LEDStruct next_leds;

// To duplicate one side of the strip with the other
void strip_sync(LEDStruct& leds) {
	for (uint16_t i = 0; i < STRIP_LENGTH; i++) {
		leds.led_data[STRIP_LENGTH - 1 - i] = leds.led_data[i];
	}
}

#endif