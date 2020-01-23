#ifndef LEDSTRUCT_H
#define LEDSTRUCT_H

//======== LED structure =========

struct LEDStruct {
	// LED data array
	struct CRGB led_data[NUM_LEDS];

	// Primary variables
	uint8_t	brightness			= 255;
	uint8_t delay_time			= 10;
	bool	use_full_range		= 1;		// Whether we want to go up and down the full strip (1), or be mirrored
	bool	this_dir = 1;
	ArrayType array_type;					// CURRENT, NEXT, any others, for debug purposes

	// Palette variables
	CRGBPalette16 current_palette;
	CRGBPalette16 target_palette;
	uint8_t palette_index;
	TBlendType current_blending = LINEARBLEND;		// Consider NOBLEND
	bool	use_palette			= 1;		// Determines if palette functions should be used

	// Mode variables
	uint8_t mode_number;					// Used to determine next mode, in change_pattern()
	Mode	mode_name;						// Name of mode, listed in variables.h, used in switch_mode()
	Mode	mode_type;						// Type of mode, for debugging purposes
	bool	mode_initialized	= 0;		// Off in regular use, on if new variables need to be set via function_init()

	// Juggle Variables
	uint8_t juggle_index;
	uint8_t juggle_numdots;
	uint8_t juggle_beat;
	uint8_t juggle_fade;
	uint8_t juggle_diff;
	bool	juggle_index_reset;
	bool	juggle_one_dir;
	bool	juggle_phased;

	// Rainbow March Variables
	uint8_t rainbow_rot;
	uint8_t rainbow_diff;
	uint8_t rainbow_index;
	bool	rainbow_split;

	// Fire and Torch Variables
	uint8_t fire_sparking;
	uint8_t fire_sparking2;
	uint8_t fire_cooling;
	uint8_t fire_cooling2;
	byte	heat[ONE_SIDE];
	byte	heat2[ONE_SIDE];
	uint8_t heat_length;		// for use with mirrored fire
	uint8_t fire_offset;		// for use with mirrored fire
	bool	fire_sync;
	bool	fire_mirror;
	uint8_t torch_index;
	uint8_t torch_diff;

	// Colorwave Variables
	uint16_t sPseudotime;
	uint16_t sLastMillis;
	uint16_t sHue16;
	uint8_t brightdepth, msmultiplier, hue8, bri8, cwave_index;
	uint16_t brightnessthetainc16, hue16, hueinc16, ms, deltams, brightnesstheta16, h16_128, b16, bri16, pixelnumber;
	uint16_t strip_range;

};


// Create LED Structures
LEDStruct curr_leds;
LEDStruct next_leds;
// LEDStruct over_leds;


// To duplicate one side of the strip with the other
void strip_sync(LEDStruct& leds) {
	for (uint16_t i = 0; i < ONE_SIDE; i++) {
		leds.led_data[NUM_LEDS - i - 1] = leds.led_data[i];
	}
}



// Debugging function
void LEDDebug(LEDStruct& leds) {
	Serial.println("");
	Serial.println("=========================");

	// Print which Array it is
	Serial.print("LED Array:        ");
	if		(leds.array_type == CURRENT) { Serial.println("CURRENT"); }
	else if (leds.array_type == NEXT)	 { Serial.println("NEXT"); }
	else if (leds.array_type == OVERLAY) { Serial.println("OVERLAY"); }

	// Print Standard Variables
	Serial.print("Brightness:       ");
	Serial.println(leds.brightness);
	Serial.print("delay_time:       ");
	Serial.println(leds.delay_time);
	Serial.print("use_palette:      ");
	Serial.println(leds.use_palette);
	Serial.print("use_full_range:   ");
	Serial.println(leds.use_full_range);
	Serial.print("this_dir:         ");
	Serial.println(leds.this_dir);
	Serial.print("mode_number:      ");
	Serial.println(leds.mode_number);
	Serial.print("mode_initialized: ");
	Serial.println(leds.mode_initialized);
	Serial.println("=========================");

	// Print mode-specific variables
	switch (leds.mode_type) {
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
			Serial.print("one_dir:       ");
			Serial.println(leds.juggle_one_dir);
			Serial.print("phased:        ");
			Serial.println(leds.juggle_phased);
			break;

		case RAINBOW_MARCH:
			if (!leds.rainbow_split) { Serial.println("===RAINBOW MARCH==="); }
			else					 { Serial.println("===RAINBOW MARCH SPLIT==="); }
			Serial.print("index:     ");
			Serial.println(leds.rainbow_index);
			Serial.print("diff:      ");
			Serial.println(leds.rainbow_diff);
			Serial.print("rot:       ");
			Serial.println(leds.rainbow_rot);
			break;

		case FIRE:
			if (leds.mode_name == TORCH) { Serial.print("=====TORCH"); }
			else { Serial.print("=====FIRE"); }
			if (leds.fire_mirror) { Serial.print(" MIRROR"); }
			if (leds.fire_sync)	  { Serial.print(" SYNC"); }
			Serial.println("=====");
			Serial.print("sparking:    ");
			Serial.println(leds.fire_sparking);
			Serial.print("cooling:     ");
			Serial.println(leds.fire_cooling);
			if (!leds.fire_sync) {
				Serial.print("sparking2:   ");
				Serial.println(leds.fire_sparking2);
				Serial.print("cooling2:    ");
				Serial.println(leds.fire_cooling2);
			}
			if (leds.mode_name == TORCH) {
				Serial.print("torch_diff:  ");
				Serial.println(leds.torch_diff);
			}
			break;
		
		case COLORWAVE:
			Serial.println("=====COLORWAVE=====");
			break;

		default:
			Serial.println("");
			Serial.println("===MODE TYPE ERROR===");
			Serial.println("");
			break;
	}
	Serial.println("=========================");
	Serial.println("");
}


#endif