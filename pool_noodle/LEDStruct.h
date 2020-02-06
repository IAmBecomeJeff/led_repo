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
	bool	use_overlay			= 0;

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
	bool	mode_initialized	= 0;		// On in regular use, off if new variables need to be set via function_init()

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
	CRGB	bounce[BOUNCE_MAX_LENGTH];
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
	uint16_t noise_yscale;
	uint16_t noise_dist;
	uint8_t noise_index;
	uint8_t noise_fade;

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

	// Lightsaber Variables
	uint16_t		tip_pos;
	uint8_t			blade_color;
	uint16_t		hold_time;
	uint16_t		ls_begin;
	uint16_t		ls_end;
	uint8_t			ls_val;
	uint8_t			delta_bright;
	saber_stages	saber_stage;
};


// Create LED Structures
LEDStruct curr_leds;
LEDStruct next_leds;
LEDStruct over_leds;


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
	Serial.println("==================================");

	// Print which Array it is
	if		(leds.array_type == CURRENT) { Serial.println("==============CURRENT============="); }
	else if (leds.array_type == NEXT)	 { Serial.println("~~~~~~~~~~~~~~~NEXT~~~~~~~~~~~~~~~"); }
	else if (leds.array_type == OVERLAY) { Serial.println("=============OVERLAY=============="); }

	// Print Standard Variables
	Serial.print("|| (B) Brightness:\t");
	Serial.print(max_bright);
	Serial.println("\t||");
	Serial.print("|| (D) delay_time:\t");
	Serial.print(leds.delay_time);
	Serial.println("\t||");
	Serial.print("|| (N) this_dir:\t");
	Serial.print(leds.this_dir);
	Serial.println("\t||");
	Serial.print("|| (M) mode_number:\t");
	Serial.print(leds.mode_number);
	Serial.println("\t||");
	Serial.print("|| mode_initialized:\t"); // 3 tabs
	Serial.print(leds.mode_initialized);
	Serial.println("\t||");
	Serial.print("|| use_palette:\t\t");
	Serial.print(leds.use_palette);
	Serial.println("\t||");
	if (leds.use_palette) { print_palette(leds.palette_index); }
	Serial.println("=================================="); //4 tabs then ||

	// Print mode-specific variables
	switch (leds.mode_type) {
		case JUGGLE:
			if(leds.mode_name == JUGGLE_HALF){ Serial.println("============JUGGLE HALF==========="); }
			else							 { Serial.println("==============JUGGLE=============="); } // 34 characters
			Serial.print("|| (a) use_full_range:\t");
			Serial.print(leds.use_full_range);
			Serial.println("\t||");
			Serial.print("|| (b) one_dir:\t\t");
			Serial.print(leds.juggle_one_dir);
			Serial.println("\t||");
			Serial.print("|| (c) phased:\t\t");
			Serial.print(leds.juggle_phased);
			Serial.println("\t||");
			Serial.print("|| (d) numdots:\t\t");
			Serial.print(leds.juggle_numdots);
			Serial.println("\t||");
			Serial.print("|| (e) beat:\t\t");
			Serial.print(leds.juggle_beat);
			Serial.println("\t||");
			Serial.print("|| (f) fade:\t\t");
			Serial.print(leds.juggle_fade);
			Serial.println("\t||");
			Serial.print("|| (g) diff:\t\t");
			Serial.print(leds.juggle_diff);
			Serial.println("\t||");
			Serial.print("|| (h) index_reset:\t");
			Serial.print(leds.juggle_index_reset);
			Serial.println("\t||");
			break;

		case RAINBOW_MARCH:
			if (!leds.rainbow_split) { Serial.println("==========RAINBOW MARCH==========="); }
			else					 { Serial.println("=======RAINBOW MARCH SPLIT========"); }
			Serial.print("|| (a) use_full_range:\t");
			Serial.print(leds.use_full_range);
			Serial.println("\t||");
			Serial.print("|| (b) split:\t\t");
			Serial.print(leds.rainbow_split);
			Serial.println("\t||");
			Serial.print("|| (c) diff:\t\t");
			Serial.print(leds.rainbow_diff);
			Serial.println("\t||");
			Serial.print("|| (d) rot:\t\t");
			Serial.print(leds.rainbow_rot);
			Serial.println("\t||");
			break;

		case FIRE:
			switch (leds.mode_name) {
				case TORCH:				Serial.println("==============TORCH==============="); break;
				case TORCH_SYNC:		Serial.println("============TORCH SYNC============"); break;
				case FIRE:				Serial.println("==============FIRE================"); break;
				case FIRE_SYNC:			Serial.println("============FIRE SYNC============="); break;
				case FIRE_MIRROR:		Serial.println("===========FIRE MIRROR============"); break;
				case FIRE_MIRROR_SYNC:	Serial.println("========FIRE MIRROR SYNC=========="); break;
				case FIRE_RANDOM:		Serial.println("===========FIRE RANDOM============"); break;
				default: break;

			}
			Serial.print("|| (a) sparking:\t");
			Serial.print(leds.fire_sparking);
			Serial.println("\t||");
			Serial.print("|| (b) cooling:\t\t");
			Serial.print(leds.fire_cooling);
			Serial.println("\t||");
			if (!leds.fire_sync) {
				Serial.print("|| (c) sparking2:\t");
				Serial.print(leds.fire_sparking2);
				Serial.println("\t||");
				Serial.print("|| (d) cooling2:\t");
				Serial.print(leds.fire_cooling2);
				Serial.println("\t||");
			}
			Serial.print("|| (e) sync:\t\t");
			Serial.print(leds.fire_sync);
			Serial.println("\t||");
			if (leds.mode_name == TORCH || leds.mode_name == TORCH_SYNC) {
				Serial.print("|| (f) torch_diff:\t");
				Serial.print(leds.torch_diff);
				Serial.println("\t||");
			}
			break;
		
		case COLORWAVE:
			Serial.println("============COLORWAVE=============");
			Serial.print("|| (a) use_full_range:\t");
			Serial.print(leds.use_full_range);
			Serial.println("\t||");
			break;

		case PRIDE:
			Serial.println("==============PRIDE===============");
			Serial.print("|| (a) use_full_range:\t");
			Serial.print(leds.use_full_range);
			Serial.println("\t||");
			break;

		case PACIFICA:
			Serial.println("=============PACIFCIA=============");
			Serial.print("|| (a) use_full_range:\t");
			Serial.print(leds.use_full_range);
			Serial.println("\t||");
			break;

		case CONFETTI:
			Serial.println("=============CONFETTI=============");
			Serial.print("|| (a) use_full_range:\t");
			Serial.print(leds.use_full_range);
			Serial.println("\t||");
			Serial.print("|| (b) confetti_fade:\t");
			Serial.print(leds.confetti_fade);
			Serial.println("\t||");
			break;

		case FIREWORKS:
			Serial.println("============FIREWORKS=============");
			Serial.print("|| Current Stage:\t");
			switch (leds.current_stage) {
				case WAITING:	Serial.print("WAITING"); Serial.println("\t||"); break;
				case FADEUP:	Serial.print("FADEUP");  Serial.println("\t||"); break;
				case EXPLOSION: Serial.println("EXPLOSION|"); break;
			}
			Serial.print("|| firework_position:\t");
			Serial.print(leds.firework_position);
			Serial.println("\t||");
			Serial.print("|| Number of sparks:\t");
			Serial.print(leds.number_of_sparks);
			Serial.println("\t||");
			Serial.print("|| Brightest spark:\t");
			Serial.print(leds.brightest_spark);
			Serial.println("\t||");
			Serial.print("|| Next explosion time:\t");
			Serial.print(leds.next_explosion_time);
			Serial.println("\t||");
			Serial.print("|| (a) use_overlay:\t");
			Serial.print(leds.use_overlay);
			Serial.println("\t||");
			break;

		case ONE_SIN:
			Serial.println("=============ONE SIN==============");
			Serial.print("|| (a) use_full_range:\t");
			Serial.print(leds.use_full_range);
			Serial.println("\t||");
			Serial.print("|| (b) sin_inc:\t\t");
			Serial.print(leds.sin_inc);
			Serial.println("\t||");
			Serial.print("|| (c) sin_speed:\t");
			Serial.print(leds.sin_speed);
			Serial.println("\t||");
			Serial.print("|| (d) sin_cutoff:\t");
			Serial.print(leds.sin_cutoff);
			Serial.println("\t||");
			Serial.print("|| (e) sin_rot:\t\t");
			Serial.print(leds.sin_rot);
			Serial.println("\t||");
			Serial.print("|| (f) sin_phase:\t");
			Serial.print(leds.sin_phase);
			Serial.println("\t||");
			Serial.print("|| (g) all_freq:\t");
			Serial.print(leds.sin_all_freq);
			Serial.println("\t||");
			Serial.print("|| (h) bg_clr:\t\t");
			Serial.print(leds.bg_clr);
			Serial.println("\t||");
			Serial.print("|| (i) bg_bri:\t\t");
			Serial.print(leds.bg_bri);
			Serial.println("\t||");
			break;

		case TWO_SIN:
			Serial.println("=============TWO SIN==============");
			Serial.print("|| (a) use_full_range:\t");
			Serial.print(leds.use_full_range);
			Serial.println("\t||");
			Serial.print("|| (b) sin_hue:\t\t");
			Serial.print(leds.sin_hue);
			Serial.println("\t||");
			Serial.print("|| (c) two_hue:\t\t");
			Serial.print(leds.two_hue);
			Serial.println("\t||");
			Serial.print("|| (d) sin_speed:\t");
			Serial.print(leds.sin_speed);
			Serial.println("\t||");
			Serial.print("|| (e) two_speed:\t");
			Serial.print(leds.two_speed);
			Serial.println("\t||");
			Serial.print("|| (f) sin_rot:\t\t");
			Serial.print(leds.sin_rot);
			Serial.println("\t||");
			Serial.print("|| (g) two_rot:\t\t");
			Serial.print(leds.two_rot);
			Serial.println("\t||");
			Serial.print("|| (h) sin_cutoff:\t");
			Serial.print(leds.sin_cutoff);
			Serial.println("\t||");
			Serial.print("|| (i) two_cutoff:\t");
			Serial.print(leds.two_cutoff);
			Serial.println("\t||");
			Serial.print("|| (j) sin_phase:\t");
			Serial.print(leds.sin_phase);
			Serial.println("\t||");
			Serial.print("|| (k) two_phase:\t");
			Serial.print(leds.two_phase);
			Serial.println("\t||");
			Serial.print("|| (l) all_freq:\t");
			Serial.print(leds.sin_all_freq);
			Serial.println("\t||");
			break;

		case SHOOTING_POLE:
			Serial.println("==========SHOOTING POLE===========");
			Serial.print("|| (a) strip_range:\t");
			Serial.print(leds.strip_range);
			Serial.println("\t||");
			Serial.print("|| (b) pole_diff:\t");
			Serial.print(leds.pole_diff);
			Serial.println("\t||");
			Serial.print("|| (c) juggle_fade:\t");
			Serial.print(leds.juggle_fade);
			Serial.println("\t||");
			Serial.print("|| (d) juggle_beat:\t");
			Serial.print(leds.juggle_beat);
			Serial.println("\t||");
			Serial.print("|| (e) juggle_diff:\t");
			Serial.print(leds.juggle_diff);
			Serial.println("\t||");
			break;

		case NOISE:
			Serial.println("===============NOISE==============");
			Serial.print("|| (a) use_full_range:\t");
			Serial.print(leds.use_full_range);
			Serial.println("\t||");
			Serial.print("|| (b) noise_scale:\t");
			Serial.print(leds.noise_scale);
			Serial.println("\t||");
			Serial.print("|| (c) noise_yscale:\t");
			Serial.print(leds.noise_yscale);
			Serial.println("\t||");
			Serial.print("|| (d) noise_dist:\t");
			Serial.print(leds.noise_dist);
			Serial.println("\t||");
			Serial.print("|| (e) noise_fade:\t");
			Serial.print(leds.noise_fade);
			Serial.println("\t||");
			break;

		case BOUNCE:
			Serial.println("==============BOUNCE==============");
			Serial.print("|| (a) juggle_fade:\t");
			Serial.print(leds.juggle_fade);
			Serial.println("\t||");
			Serial.print("|| (b) bounce_length:\t");
			Serial.print(leds.bounce_length);
			Serial.println("\t||");
			Serial.print("|| (c) juggle_beat:\t");
			Serial.print(leds.juggle_beat);
			Serial.println("\t||");
			Serial.print("|| (d) rainbow_diff:\t");
			Serial.print(leds.rainbow_diff);
			Serial.println("\t||");
			Serial.print("|| (e) start_beat:\t");
			Serial.print(leds.bounce_start_beat);
			Serial.println("\t||");
			Serial.print("|| (f) bounce_rainbow:\t");
			Serial.print(leds.bounce_rainbow);
			Serial.println("\t||");
			break;

		case BOUNCING_BALLS:
			Serial.println("==========BOUNCING BALLS==========");
			Serial.print("|| (a) fade:\t\t");
			Serial.print(leds.bouncing_fade);
			Serial.println("\t||");
			Serial.print("|| (b) number of balls:\t");
			Serial.print(leds.number_of_balls);
			Serial.println("\t||");
			Serial.print("|| (c) use_palette:\t");
			Serial.print(leds.use_palette);
			Serial.println("\t||");
			break;

		case LIGHTSABER:
			Serial.println("============LIGHTSABER============");
			Serial.print("|| (a) use_palette:\t");
			Serial.print(leds.use_palette);
			Serial.println("\t||");
			Serial.print("|| (b) blade_color:\t");
			Serial.print(leds.blade_color);
			Serial.println("\t||");
			Serial.print("|| (c) delta_bright:\t");
			Serial.print(leds.delta_bright);
			Serial.println("\t||");
			Serial.print("|| (d) hold_time:\t");
			Serial.print(leds.hold_time);
			Serial.println("\t||");
			break;

		default:
			Serial.println("");
			Serial.println("==========MODE TYPE ERROR=========");
			Serial.println("");
			break;
	}
	Serial.println("==================================\n");
}


#endif