#ifndef LED_STRUCT_H
#define LED_STRUCT_H

//======== LED structure =========

struct LEDStruct {
	// LED data array
	struct CRGB led_data[NUM_LEDS];

	// Primary variables
	uint8_t	brightness				= 255;
	uint8_t delay_time				= 10;
	CRGBPalette16 current_palette;
	CRGBPalette16 target_palette;
	TBlendType current_blending		= LINEARBLEND;
	bool	use_palette				= 1;
	bool	use_full_range			= 0;
	bool	this_dir				= 1;
	uint8_t current_mode_number;			// Not in use
	Mode	mode_name;
	bool	mode_initialized		= 0;
	ArrayType array_type;					// CURRENT, NEXT, any others, for debug purposes

	// Juggle Variables
	uint8_t juggle_index;
	uint8_t juggle_numdots;
	uint8_t juggle_beat;
	uint8_t juggle_fade;
	uint8_t juggle_diff;
	bool	juggle_index_reset;
};

// Create LED Structures
LEDStruct curr_leds;
LEDStruct next_leds;


// To duplicate one side of the strip with the other
void strip_sync(LEDStruct& leds) {
	for (uint16_t i = 0; i < ONE_SIDE; i++) {
		leds.led_data[ONE_SIDE - 1 - i] = leds.led_data[i];
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
	Serial.print("current_mode_number:  ");
	Serial.println(leds.current_mode_number);
	Serial.print("mode_initialized:     ");
	Serial.println(leds.mode_initialized);

	// Print mode-specific variables
	switch(leds.mode_name) {
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
	}
	Serial.println("======================");
}


#endif