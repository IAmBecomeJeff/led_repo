#ifndef LEDSTRUCT_H
#define LEDSTRUCT_H

//======== LED structure =========

struct LEDStruct {
	// LED data array
	struct CRGB led_data[NUM_LEDS];

	// Primary variables
	uint8_t	brightness			= 255;
	uint8_t delay_time			= 15;
	bool	use_full_range		= 1;		// Whether we want to go up and down the full strip (1), or be mirrored
	bool	this_dir			= 1;
	ArrayType array_type;					// CURRENT, NEXT, any others, for debug purposes

	// Palette variables
	CRGBPalette16 current_palette;
	CRGBPalette16 target_palette;
	TBlendType current_blending = LINEARBLEND;		// Consider NOBLEND
	uint8_t palette_index;
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
	uint8_t bounce_start;
	uint8_t bounce_start_beat;
	uint8_t bounce_pos;
	uint8_t bounce_length;
	CRGB	bounce[20];
	bool	bounce_rainbow;

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

	// Colorwave and Pride Variables
	uint16_t sPseudotime;
	uint16_t sLastMillis;
	uint16_t sHue16;
	uint8_t  brightdepth, msmultiplier, hue8, sat8, bri8, cwave_index;
	uint16_t brightnessthetainc16, hue16, hueinc16, ms, deltams, brightnesstheta16, h16_128, b16, bri16, pixelnumber;
	uint16_t strip_range;

	// Confetti Variables
	uint8_t confetti_fade;

	// Sin Variables
	uint8_t sin_inc;
	uint8_t sin_speed;
	uint8_t sin_cutoff;
	uint8_t sin_rot;
	uint8_t sin_all_freq;
	uint8_t sin_index;
	uint8_t sin_start;
	uint8_t sin_phase;
	uint8_t sin_hue;
	uint8_t sin_bri;
	uint8_t two_speed;
	uint8_t two_rot;
	uint8_t two_cutoff;
	uint8_t two_phase;
	uint8_t two_hue;
	uint8_t two_bri;

	uint8_t bg_clr;
	uint8_t bg_bri;

	// Fireworks Variables
	uint8_t firework_position;
	uint8_t firework_hue;
	uint8_t firework_bri;
	stage current_stage;
	uint32_t next_explosion_time;
	bool exploded;
	uint8_t number_of_sparks;
	float spark_pos[MAX_NUMBER_OF_SPARKS];
	float spark_vel[MAX_NUMBER_OF_SPARKS];
	bool spark_dir[MAX_NUMBER_OF_SPARKS];
	float spark_fade[MAX_NUMBER_OF_SPARKS];
	float spark_bri[MAX_NUMBER_OF_SPARKS];
	uint8_t brightest_spark;

	// Shooting Pole
	uint8_t pole_index;
	uint8_t pole_diff;

	// Noise Variables
	uint16_t noise_scale;
	uint16_t noise_dist;
	uint8_t noise_index;

	// Bouncing Balls Variables
	uint8_t bouncing_index;
	uint8_t bouncing_fade;
	uint8_t number_of_balls;
	float   bouncing_heights[MAX_NUMBER_OF_BALLS];
	float   bouncing_vImpact[MAX_NUMBER_OF_BALLS];
	float   bouncing_tCycle[MAX_NUMBER_OF_BALLS];
	int     bouncing_pos[MAX_NUMBER_OF_BALLS];
	long    bouncing_tLast[MAX_NUMBER_OF_BALLS];
	float   bouncing_COR[MAX_NUMBER_OF_BALLS];

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

void print_palette(uint8_t pn); // Forward declaration


// Debugging function
void LEDDebug(LEDStruct& leds) {
	Serial.println("");
	Serial.println("==================================================");

	// Print which Array it is
	Serial.print("LED Array:        ");
	if		(leds.array_type == CURRENT) { Serial.println("CURRENT"); }
	else if (leds.array_type == NEXT)	 { Serial.println("NEXT"); }
	else if (leds.array_type == OVERLAY) { Serial.println("OVERLAY"); }

	// Print Standard Variables
	Serial.print("Brightness:       ");
	Serial.println(max_bright);
	Serial.print("delay_time:       ");
	Serial.println(leds.delay_time);
	Serial.print("use_palette:      ");
	Serial.println(leds.use_palette);
	if (leds.use_palette) { print_palette(leds.palette_index); }
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
			if (leds.mode_name == TORCH || leds.mode_name == TORCH_SYNC) { Serial.print("=====TORCH"); }
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
			if (leds.mode_name == TORCH || leds.mode_name == TORCH_SYNC) {
				Serial.print("torch_diff:  ");
				Serial.println(leds.torch_diff);
			}
			break;
		
		case COLORWAVE:
			Serial.println("=====COLORWAVE=====");
			break;

		case PRIDE:
			Serial.println("=====PRIDE=====");
			break;

		case PACIFICA:
			Serial.println("=====PACIFCIA=====");
			break;

		case CONFETTI:
			Serial.println("=====CONFETTI=====");
			Serial.print("confetti_fade: ");
			Serial.println(leds.confetti_fade);
			break;

		case FIREWORKS:
			Serial.println("=====FIREWORKS=====");
			Serial.print("firework_position:   ");
			Serial.println(leds.firework_position);
			Serial.print("Current Stage:  ");
			switch (leds.current_stage) {
			case WAITING: Serial.println("WAITING");
			case FADEUP: Serial.println("FADEUP");
			case EXPLOSION: Serial.println("EXPLOSION");
			}
			Serial.print("Number of sparks:  ");
			Serial.println(leds.number_of_sparks);
			Serial.print("Brightest spark:   ");
			Serial.println(leds.brightest_spark);
			Serial.print("Next explosion time: ");
			Serial.println(leds.next_explosion_time);
			break;

		case ONE_SIN:
			Serial.println("=====ONE_SIN=====");
			Serial.print("sin_inc:       ");
			Serial.println(leds.sin_inc);
			Serial.print("sin_speed:     ");
			Serial.println(leds.sin_speed);
			Serial.print("sin_cutoff:    ");
			Serial.println(leds.sin_cutoff);
			Serial.print("sin_rot:       ");
			Serial.println(leds.sin_rot);
			Serial.print("sin_phase:     ");
			Serial.println(leds.sin_phase);
			Serial.print("all_freq:      ");
			Serial.println(leds.sin_all_freq);
			Serial.print("bg_clr:        ");
			Serial.println(leds.bg_clr);
			Serial.print("bg_bri:        ");
			Serial.println(leds.bg_bri);
			break;

		case TWO_SIN:
			Serial.println("=====TWO_SIN=====");
			Serial.print("sin_hue:       ");
			Serial.println(leds.sin_inc);
			Serial.print("sin_speed:     ");
			Serial.println(leds.sin_speed);
			Serial.print("sin_cutoff:    ");
			Serial.println(leds.sin_cutoff);
			Serial.print("sin_rot:       ");
			Serial.println(leds.sin_rot);
			Serial.print("sin_phase:     ");
			Serial.println(leds.sin_phase);
			Serial.print("two_hue:       ");
			Serial.println(leds.two_hue);
			Serial.print("two_speed:     ");
			Serial.println(leds.two_speed);
			Serial.print("two_cutoff:    ");
			Serial.println(leds.two_cutoff);
			Serial.print("two_rot:       ");
			Serial.println(leds.two_rot);
			Serial.print("two_phase:     ");
			Serial.println(leds.two_phase);
			Serial.print("all_freq:      ");
			Serial.println(leds.sin_all_freq);
			break;

		case SHOOTING_POLE:
			Serial.println("=====SHOOTING POLE=====");
			Serial.print("strip_range:     ");
			Serial.println(leds.strip_range);
			Serial.print("pole_diff:       ");
			Serial.println(leds.pole_diff);
			Serial.print("juggle_beat:     ");
			Serial.println(leds.juggle_beat);
			Serial.print("juggle_diff:     ");
			Serial.println(leds.juggle_diff);
			Serial.print("juggle_fade:     ");
			Serial.println(leds.juggle_fade);
			break;

		case NOISE:
			Serial.println("=====NOISE=====");
			Serial.print("noise_scale:   ");
			Serial.println(leds.noise_scale);
			Serial.print("noise_dist:    ");
			Serial.println(leds.noise_dist);
			break;

		case BOUNCE:
			Serial.println("=====BOUNCE=====");
			Serial.print("juggle_fade:       ");
			Serial.println(leds.juggle_fade);
			Serial.print("bounce_length:     ");
			Serial.println(leds.bounce_length);
			Serial.print("juggle_beat:       ");
			Serial.println(leds.juggle_beat);
			Serial.print("rainbow_diff:      ");
			Serial.println(leds.rainbow_diff);
			Serial.print("bounce_start_beat: ");
			Serial.println(leds.bounce_start_beat);
			Serial.print("bounce_rainbow:    ");
			Serial.println(leds.bounce_rainbow);
			break;

		case BOUNCING_BALLS:
			Serial.println("=====BOUNCING BALLS=====");
			Serial.print("fade:\t\t");
			Serial.println(leds.bouncing_fade);
			Serial.print("number of balls: ");
			Serial.println(leds.number_of_balls);
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