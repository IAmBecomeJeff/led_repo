#ifndef LED_STRUCT_H
#define LED_STRUCT_H

//======== LED structure =========

struct LEDStruct {
	// LED data array
	struct CRGB led_data[NUM_LEDS];

	// Primary variables
	uint8_t	brightness			= 255;
	uint8_t delay_time			= 10;
	CRGBPalette16 current_palette;
	CRGBPalette16 target_palette;
	uint8_t palette_index;
	TBlendType current_blending = LINEARBLEND;
	bool	use_palette			= 1;		// Determines if palette functions should be used
	bool	use_full_range		= 0;		// Whether we want to go up and down the full strip (1), or be mirrored
	bool	this_dir			= 1;
	uint8_t mode_number;					// Used to determine next mode
	Mode	mode_name;						// Name of mode, listed in variables.h
	bool	mode_initialized	= 0;		// Off in regular use, on if new variables need to be set
	ArrayType array_type;					// CURRENT, NEXT, any others, for debug purposes

	// Juggle Variables
	uint8_t juggle_index;
	uint8_t juggle_numdots;
	uint8_t juggle_beat;
	uint8_t juggle_fade;
	uint8_t juggle_diff;
	bool	juggle_index_reset;

	// Rainbow March Variables
	uint8_t rainbow_rot;
	uint8_t rainbow_diff;
	uint8_t rainbow_index;

};


// Create LED Structures
LEDStruct curr_leds;
LEDStruct next_leds;


// To duplicate one side of the strip with the other
void strip_sync(LEDStruct& leds) {
	for (uint16_t i = 0; i < ONE_SIDE; i++) {
		leds.led_data[NUM_LEDS - i - 1] = leds.led_data[i];
	}
}



// Debug function
void LEDDebug(LEDStruct& leds) {
	Serial.println("");
	Serial.println("======================");

	// Print which Array it is
	Serial.print("LED Array:            ");
	if (leds.array_type == CURRENT) { Serial.println("CURRENT"); }
	else if (leds.array_type == NEXT) { Serial.println("NEXT"); }

	// Print Standard Variables
	Serial.print("Brightness:           ");
	Serial.println(leds.brightness);
	Serial.print("delay_time:           ");
	Serial.println(leds.delay_time);
	Serial.print("use_palette:          ");
	Serial.println(leds.use_palette);
	Serial.print("use_full_range:       ");
	Serial.println(leds.use_full_range);
	Serial.print("this_dir:             ");
	Serial.println(leds.this_dir);
	Serial.print("mode_number:  ");
	Serial.println(leds.mode_number);
	Serial.print("mode_initialized:     ");
	Serial.println(leds.mode_initialized);

	// Print mode-specific variables
	switch (leds.mode_name) {
		case JUGGLE:
			Serial.println("===JUGGLE VARIABLES===");
			Serial.print("index:         ");
			Serial.println(leds.juggle_index);
			Serial.print("numdots:       ");
			Serial.println(leds.juggle_numdots);
			Serial.print("beat:          ");
			Serial.println(leds.juggle_beat);
			Serial.print("fade:          ");
			Serial.println(leds.juggle_fade);
			Serial.print("diff:          ");
			Serial.println(leds.juggle_diff);
			Serial.print("index_reset:   ");
			Serial.println(leds.juggle_index_reset);
			break;

		case RAINBOW_MARCH:
			Serial.println("===RAINBOW MARCH===");
			Serial.print("index:     ");
			Serial.println(leds.rainbow_index);
			Serial.print("diff:      ");
			Serial.println(leds.rainbow_diff);
			Serial.print("rot:       ");
			Serial.println(leds.rainbow_rot);
			break;

		case RAINBOW_MARCH_SPLIT:
			Serial.println("===RAINBOW MARCH SPLIT===");
			Serial.print("index:     ");
			Serial.println(leds.rainbow_index);
			Serial.print("diff:      ");
			Serial.println(leds.rainbow_diff);
			Serial.print("rot:       ");
			Serial.println(leds.rainbow_rot);
			break;
	}
	Serial.println("======================");
}


#endif