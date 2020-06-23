#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

// Unsigned subtraction magic
#define qsubd(x, b) ((x>b)?b:0)		// A digital unsigned subtraction macro. if result <0, then => 0. Otherwise, take on fixed value.
#define qsuba(x, b) ((x>b)?x-b:0)					// Unsigned subtraction macro. if result <0, then => 0.

void switch_mode(LEDStruct& leds); // Forward declaration

// Find index of current (target) palette
void updatePaletteIndex(LEDStruct& leds) {
	for (int i = 0; i < palette_count; i++) {
		if (leds.target_palette == palettes[i]) {
			leds.palette_index = i;
			break;
		}
	}
}


void find_mode_number(LEDStruct& leds) {
	for (uint8_t i = 0; i < ARRAY_SIZE(ModeList); i++){
		if (leds.mode_name == ModeList[i]) {
			leds.mode_number = i;
			break;
		}
	}
}

// Initialization function
void initialize() {
	// Initialize curr_leds
	fill_solid(curr_leds.led_data, NUM_LEDS, CRGB::Black);
	curr_leds.array_type		= CURRENT;
	curr_leds.current_palette	= rainbowsherbet_gp;
	curr_leds.target_palette	= Tropical_Colors_gp;
	updatePaletteIndex(curr_leds);
	curr_leds.mode_name			= start_mode;
	find_mode_number(curr_leds);

	// Initialize next_leds
	fill_solid(next_leds.led_data, NUM_LEDS, CRGB::Black);
	next_leds.array_type		= NEXT;
	next_leds.current_palette	= slope_gp;
	next_leds.target_palette	= rainbow_gp;
	next_leds.mode_number		= curr_leds.mode_number;			// Helps with sequential steps
	updatePaletteIndex(next_leds);

	// Initialize curr_over_leds
	fill_solid(curr_over_leds.led_data, NUM_LEDS, CRGB::Black);
	curr_over_leds.array_type		= CURR_OVERLAY;
	curr_over_leds.current_palette	= cequal_gp;
	curr_over_leds.target_palette	= cequal_gp;

	// Initialize next_over_leds
	fill_solid(next_over_leds.led_data, NUM_LEDS, CRGB::Black);
	next_over_leds.array_type = NEXT_OVERLAY;
	next_over_leds.current_palette = cequal_gp;
	next_over_leds.target_palette = cequal_gp;
}


void delay_check(LEDStruct& leds) {
	if (leds.delay_time < 5) { leds.delay_time = 5; }
	if (leds.delay_time > 20) { leds.delay_time = 20; }
}

void begin_transition(); // Forward declaration

// Change mode - consider how to handle this.  Random, specific path, etc.
void change_mode(uint8_t mn = 255) {
	if (DEBUG) {
		Serial.println("\n***************************************************"); 
		Serial.println("*******************Changing Mode*******************"); 
		Serial.println("***************************************************");
	}
	begin_transition();
	number_of_mode_changes++;

	// Next LED Variables
	next_leds.mode_initialized = 0;
	next_leds.this_dir = random8(2);
	if (mn == 255) {					// large number to avoid interfering with read_keyboard mode sends
		if (random_mode) { next_leds.mode_number = random8(ARRAY_SIZE(ModeList)); }
		else			 { next_leds.mode_number = (next_leds.mode_number + 1) % ARRAY_SIZE(ModeList); }
	}
	else { next_leds.mode_number = mn; }
	next_leds.mode_name = ModeList[next_leds.mode_number];
	switch_mode(next_leds);
}

// Change palette
void change_palette(LEDStruct& leds) {
	if (leds.use_palette) {
		if (DEBUG) {
			Serial.println("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
			Serial.println("^^^^^^^^^^^^^^^^^Changing Palette^^^^^^^^^^^^^^^^^^");
			Serial.println("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^");
		}
		leds.palette_index = random8(palette_count);
		leds.target_palette = palettes[leds.palette_index];
		if (DEBUG) { print_palette(leds.palette_index); }
	}
}


// Debug
void global_debug() {
	Serial.print("(S) Change modes:\t");
	Serial.println(mode_change);
	Serial.print("(R) Random Mode:\t");
	Serial.println(random_mode);
	Serial.print("(Q) Change Palettes:\t");
	Serial.println(random_palette);
	Serial.print("(T) Mode Timer:\t\t");
	Serial.println(mode_change_time);
	Serial.print("Mode change number:\t");
	Serial.println(number_of_mode_changes);
	Serial.print("Running time:\t\t");
	Serial.print(number_of_min_on);
	Serial.print("m ");
	Serial.print(number_of_sec_on);
	Serial.println("s");
	Serial.print("System time:\t\t");
	Serial.println(millis());
}

// Transition functions
void begin_transition() {
	in_transition = 1;
	if (random8(11) < 7) {				// ~70% chance of blending, also may blend from the random selection below
		transition_type = BLENDING;
	}
	else {
		transition_type = TransitionList[random8(ARRAY_SIZE(TransitionList))];
	}
	transition_speed = random8(3, 8);
	switch (transition_type) {
		case BLENDING:		transition_ratio = 0;		break;
		case WIPEDOWN:		wipe_pos = ONE_SIDE - 1;	break;
		case WIPEUP:		wipe_pos = 0;				break;
		//case COLORFADE:	color_up = 1; transition_ratio = 0; colorfade_hue = CHSV(random8(), 255, 255); hsv2rgb_rainbow(colorfade_hue, colorfade_rgb);  break;
	}
}

void finish_transition() {
	in_transition = 0;
	fill_solid(curr_leds.led_data, NUM_LEDS, CRGB::Black);
	curr_leds = next_leds;
	if (curr_leds.use_overlay) { curr_over_leds = next_over_leds; curr_over_leds.array_type = CURR_OVERLAY; }
	fill_solid(next_leds.led_data, NUM_LEDS, CRGB::Black);
	fill_solid(next_over_leds.led_data, NUM_LEDS, CRGB::Black);
	curr_leds.array_type = CURRENT;
}

void blending() {
	for (uint16_t i = 0; i < NUM_LEDS; i++) { master_leds[i] = blend(curr_leds.led_data[i], next_leds.led_data[i], transition_ratio); }
	EVERY_N_MILLIS(transition_speed * 4) { transition_ratio++;	}
	if (transition_ratio == 255) {
		finish_transition();
	}
}


void wipedown() {
	for (uint16_t i = 0; i < wipe_pos; i++) {
		master_leds[i]				  = curr_leds.led_data[i];
		master_leds[NUM_LEDS - 1 - i] = curr_leds.led_data[NUM_LEDS -1 - i];
	}
	for (uint16_t j = wipe_pos; j < ONE_SIDE; j++) {
		master_leds[j]				  = next_leds.led_data[j];
		master_leds[NUM_LEDS - 1 - j] = next_leds.led_data[NUM_LEDS -1 - j];
	}

	master_leds[wipe_pos - 1] = blend(master_leds[wipe_pos - 1], CRGB::Teal, 128);
	master_leds[NUM_LEDS - 1 - (wipe_pos - 1)] = blend(master_leds[NUM_LEDS - 1 - (wipe_pos - 1)], CRGB::Teal, 128);

	master_leds[wipe_pos]				 = CRGB::White;
	master_leds[NUM_LEDS - 1 - wipe_pos] = CRGB::White;

	if (wipe_pos < ONE_SIDE - 1) {
		master_leds[wipe_pos + 1] = blend(master_leds[wipe_pos + 1], CRGB::Teal, 128);
		master_leds[NUM_LEDS - 1 - (wipe_pos + 1)] = blend(master_leds[NUM_LEDS - 1 - (wipe_pos + 1)], CRGB::Teal, 128);
	}

	EVERY_N_MILLIS(transition_speed * 4) { wipe_pos--; }		// 1000 / 75
	if (wipe_pos == 0) {
		finish_transition();
	}
}

void wipeup() {
	for (uint16_t i = 0; i < wipe_pos; i++) {
		master_leds[i]				  = next_leds.led_data[i];
		master_leds[NUM_LEDS - 1 - i] = next_leds.led_data[NUM_LEDS -1 -i];
	}
	for (uint16_t j = wipe_pos; j < ONE_SIDE; j++) {
		master_leds[j]				  = curr_leds.led_data[j];
		master_leds[NUM_LEDS - 1 - j] = curr_leds.led_data[NUM_LEDS -1 -j];
	}

	if (wipe_pos > 0) {
		master_leds[wipe_pos - 1]				   = blend(master_leds[wipe_pos - 1], CRGB::Teal, 128);
		master_leds[NUM_LEDS - 1 - (wipe_pos - 1)] = blend(master_leds[NUM_LEDS - 1 - (wipe_pos - 1)], CRGB::Teal, 128);
	}

	master_leds[wipe_pos]				 = CRGB::White;
	master_leds[NUM_LEDS - 1 - wipe_pos] = CRGB::White;

	master_leds[wipe_pos + 1]				   = blend(master_leds[wipe_pos + 1], CRGB::Teal, 128);
	master_leds[NUM_LEDS - 1 - (wipe_pos + 1)] = blend(master_leds[NUM_LEDS - 1 - (wipe_pos + 1)], CRGB::Teal, 128);

	EVERY_N_MILLIS(transition_speed * 4) { wipe_pos++; }
	if (wipe_pos == ONE_SIDE - 1) {
		finish_transition();
	}
}
/*
void colorfade() {
	if (color_up) {
		for (uint16_t i = 0; i < NUM_LEDS; i++) { master_leds[i] = blend(curr_leds.led_data[i], colorfade_rgb, transition_ratio); }
		EVERY_N_MILLIS(transition_speed * 4) { if (transition_ratio++ == 255) { color_up = 0; transition_ratio = 0; } }
	}
	else {
		for (uint16_t i = 0; i < NUM_LEDS; i++) { master_leds[i] = blend(colorfade_rgb, next_leds.led_data[i], transition_ratio); }
		EVERY_N_MILLIS(transition_speed * 4) { if (transition_ratio++ == 0) { finish_transition(); } }
	}
}
*/
void switch_transition(TransitionType tt) {
	switch (tt) {
		case BLENDING:	blending();		break;
		case WIPEDOWN:	wipedown();		break;
		case WIPEUP:	wipeup();		break;
		//case COLORFADE: colorfade();	break;
		default:		blending();		break;
	}
}



// Print palettes
void print_palette(uint8_t pn) {
	Serial.print("|| (P) Palette (");
	Serial.print(pn);
	Serial.print(") ");
	switch (pn) {
		case 0:		Serial.println("ib_jul01_gp");					break;
		case 1:		Serial.println("rgi_15_gp");					break;
		case 2:		Serial.println("Analogous_1_gp");				break;
		case 3:		Serial.println("es_pinksplash_08_gp");			break;
		case 4:		Serial.println("es_pinksplash_07_gp");			break;
		case 5:		Serial.println("Coral_reef_gp");				break;
		case 6:		Serial.println("es_ocean_breeze_068_gp");		break;
		case 7:		Serial.println("es_ocean_breeze_036_gp");		break;
		case 8:		Serial.println("es_landscape_64_gp");			break;
		case 9:		Serial.println("es_landscape_33_gp");			break;
		case 10:	Serial.println("rainbowsherbet_gp");			break;
		case 11:	Serial.println("gr65_hult_gp");					break;
		case 12:	Serial.println("gr64_hult_gp");					break;
		case 13:	Serial.println("GMT_drywet_gp");				break;
		case 14:	Serial.println("ib15_gp");						break;
		case 15:	Serial.println("Fuschia_7_gp");					break;
		case 16:	Serial.println("es_emerald_dragon_08_gp");		break;
		case 17:	Serial.println("lava_gp");						break;
		case 18:	Serial.println("fire_gp");						break;
		case 19:	Serial.println("Colorfull_gp");					break;
		case 20:	Serial.println("Magenta_Evening_gp");			break;
		case 21:	Serial.println("Sunset_Real_gp");				break;
		case 22:	Serial.println("es_autumn_19_gp");				break;
		case 23:	Serial.println("BlacK_Blue_Magenta_White_gp");	break;
		case 24:	Serial.println("BlacK_Magenta_Red_gp");			break;
		case 25:	Serial.println("BlacK_Red_Magenta_Yellow_gp");	break;
		case 26:	Serial.println("Blue_Cyan_Yellow_gp");			break;
		case 27:	Serial.println("bhw1_greeny_gp");				break;
		case 28:	Serial.println("bhw1_26_gp");					break;
		case 29:	Serial.println("bhw1_28_gp");					break;
		case 30:	Serial.println("bhw2_23_gp");					break;
		case 31:	Serial.println("bhw2_22_gp");					break;
		case 32:	Serial.println("bhw2_49_gp");					break;
		case 33:	Serial.println("bhw2_10_gp");					break;
		case 34:	Serial.println("bhw2_14_gp");					break;
		case 35:	Serial.println("bhw3_21_gp");					break;
		case 36:	Serial.println("bhw3_30_gp");					break;
		case 37:	Serial.println("vibrant_gp");					break;
		case 38:	Serial.println("cw1_029_gp");					break;
		case 39:	Serial.println("alarm_p4_0_2_gp");				break;
		case 40:	Serial.println("Ribbon_Colors_gp");				break;
		case 41:	Serial.println("Orange_to_Purple_gp");			break;
		case 42:	Serial.println("Fire_1_gp");					break;
		case 43:	Serial.println("standard_gp");					break;
		case 44:	Serial.println("a_gp");							break;
		case 45:	Serial.println("b_gp");							break;
		case 46:	Serial.println("es_emerald_dragon_01_gp");		break;
		case 47:	Serial.println("froth316_gp");					break;
		case 48:	Serial.println("Skydye11_gp");					break;
		case 49:	Serial.println("Wizzl019_gp");					break;
		case 50:	Serial.println("Tropical_Colors_gp");			break;
		case 51:	Serial.println("slope_gp");						break;
		case 52:	Serial.println("ofaurora_gp");					break;
		case 53:	Serial.println("hallows_gp");					break;
		case 54:	Serial.println("sea_treasure_gp");				break;
		case 55:	Serial.println("Secondary_01a_gp");				break;
		case 56:	Serial.println("Split_03_gp");					break;
		case 57:	Serial.println("GMT_seafloor_gp");				break;
		case 58:	Serial.println("rainbow_gp");					break;
		case 59:	Serial.println("cloudcolors_gp");				break;
		case 60:	Serial.println("cequal_gp");					break;
		case 61:	Serial.println("purple_flower_gp");				break;
		case 62:	Serial.println("fierce_ice_gp");				break;
		case 63:	Serial.println("blueice_gp");					break;
		case 64:	Serial.println("twilight_gp");					break;
		case 65:	Serial.println("green_gp");						break;
		case 66:	Serial.println("ultraviolet_mold_gp");			break;
		case 67:	Serial.println("apple_green_gp");				break;
		case 68:	Serial.println("faint_rainbow_gp");				break;
		case 69:	Serial.println("otis_gp");						break;
		case 70:	Serial.println("parrot_gp");					break;
		case 71:	Serial.println("scoutie_gp");					break;
		case 72:	Serial.println("sunlitwave_gp");				break;
		case 73:	Serial.println("GMT_cool_gp");					break;
		case 74:	Serial.println("bhw1_sunconure_gp");			break;
		case 75:	Serial.println("bhw1_05_gp");					break;
		case 76:	Serial.println("bhw2_turq_gp");					break;
		case 77:	Serial.println("bhw3_13_gp");					break;
		case 78:	Serial.println("bhw3_61_gp");					break;
		case 79:	Serial.println("bhw4_009_gp");					break;
		case 80:	Serial.println("bhw3_34_gp");					break;
		case 81:	Serial.println("es_emerald_dragon_09_gp");		break;
		case 82:	Serial.println("xanidu_2_gp");					break;
		case 83:	Serial.println("water1_gp");					break;
		case 84:	Serial.println("stratosphere_sunset_gp");		break;
		case 85:	Serial.println("RedsandCyans_gp");				break;
		case 86:	Serial.println("Cyan_Magenta_Blue_gp");			break;
		case 87:	Serial.println("Complementary_01a_gp");			break;
		case 88:	Serial.println("cyberpunk_neon_gp");			break;
		case 89:	Serial.println("blue_fire_gp");					break;
		case 90:	Serial.println("purplefly_gp");					break;
		case 91:	Serial.println("rainbow2_gp");					break;
		case 92:	Serial.println("blade_runner_2049_gp");			break;
		default:	Serial.println("Not a gradient palette");		break;
	}
}

void palette_check(LEDStruct& leds) {
	for (uint8_t i = 0; i < ARRAY_SIZE(bad_juggle_palettes); i++) {
		if (leds.palette_index == bad_juggle_palettes[i]) {
			leds.juggle_index_reset = 0;
			leds.juggle_diff = leds.juggle_diff / 10 + 1;
			break;
		}
	}
}

LIB8STATIC uint16_t beatsin16_halfdown(accum88 beats_per_minute, uint16_t lowest = 0, uint16_t highest = 65535,
	uint32_t timebase = 0, uint16_t phase_offset = 0)
{
	uint16_t beat = beat16(beats_per_minute, timebase) % 32768 + 16384;     
	uint16_t beatsin = (sin16(beat + phase_offset) + 32768);
	uint16_t rangewidth = highest - lowest;
	uint16_t scaledbeat = scale16(beatsin, rangewidth);
	uint16_t result = lowest + scaledbeat;
	return result;
}

LIB8STATIC uint16_t beatsin16_halfup(accum88 beats_per_minute, uint16_t lowest = 0, uint16_t highest = 65535,
	uint32_t timebase = 0, uint16_t phase_offset = 0)
{
	uint16_t beat = beat16(beats_per_minute, timebase) % 32768 + 49152;     
	uint16_t beatsin = (sin16(beat + phase_offset) + 32768);
	uint16_t rangewidth = highest - lowest;
	uint16_t scaledbeat = scale16(beatsin, rangewidth);
	uint16_t result = lowest + scaledbeat;
	return result;
}