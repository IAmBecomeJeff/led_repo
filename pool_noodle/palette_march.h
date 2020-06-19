#ifndef PALETTE_MARCH_H
#define PALETTE_MARCH_H

// palette_march_split
// palette_march_diff
// palette_march_rot

void palette_init(LEDStruct& leds, bool ps = random8(2), uint8_t pd = random8(1, 20), uint8_t pr = random8(1, 4), bool ufr = random8(2), uint8_t jb = random8(3, 13)) {
	leds.mode_initialized	= 1;
	leds.mode_type			= PALETTE_MARCH;
	leds.use_palette		= 1;
	leds.delay_time			= 15;

	leds.use_full_range = ufr;

	leds.palette_march_split	= ps;
	if (pd == 1) { pr = 1; }
	leds.palette_march_diff	= pd;
	leds.palette_march_rot	= pr;

	leds.juggle_beat	= jb;
	if (DEBUG) { LEDDebug(leds); }
}

void palette_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {
	case 0:															//a
		leds.use_full_range = (bool)update_arg;
		if (leds.use_full_range) { leds.strip_range = NUM_LEDS; }
		else { leds.strip_range = ONE_SIDE; }
		break;
	case 1:		leds.palette_march_split = (bool)update_arg;		break;	//b		
	case 2:		leds.palette_march_diff = (uint8_t)update_arg;	break;	//c
	case 3:		leds.palette_march_rot = (uint8_t)update_arg;		break;	//d
	case 4:		leds.juggle_beat = (uint8_t)update_arg;		break;  //e
	default:	break;
	}
	LEDDebug(leds);
}



void palette_march(LEDStruct& leds) {
	if (!leds.mode_initialized) { palette_init(leds); }
	if (keyboard_update) { palette_update(leds); }

	if (leds.this_dir == 0) leds.palette_march_index += leds.palette_march_rot; else leds.palette_march_index -= leds.palette_march_rot;

	if (!leds.palette_march_split) {
		if (leds.use_full_range) {
			for (uint8_t i = 0; i < NUM_LEDS; i++) {
				leds.led_data[i] = ColorFromPalette(leds.current_palette, leds.palette_march_index + i * leds.palette_march_diff, 255, leds.current_blending);
			}
		}
		else { 
			for (uint8_t i = 0; i < ONE_SIDE; i++) {
				leds.led_data[i] = ColorFromPalette(leds.current_palette, leds.palette_march_index + i * leds.palette_march_diff, 255, leds.current_blending);
			}
			strip_sync(leds);
		}
	}
	else {
		for (uint8_t i = 0; i < ONE_SIDE / 2; i++) {
			leds.led_data[i] = ColorFromPalette(leds.current_palette, leds.palette_march_index + i * leds.palette_march_diff, 255, leds.current_blending);
		}
		for (uint8_t i = 0; i < ONE_SIDE / 2; i++) { 
			leds.led_data[ONE_SIDE - 1 - i] = leds.led_data[i]; 
		}
		strip_sync(leds);
	}
}

void palette_march_beat(LEDStruct& leds) {
	if (!leds.mode_initialized) { palette_init(leds); }
	if (keyboard_update) { palette_update(leds); }

	if (leds.this_dir == 0) leds.palette_march_index += leds.palette_march_rot; else leds.palette_march_index -= leds.palette_march_rot;

	if (!leds.palette_march_split) {
		if (leds.use_full_range) {
			for (uint8_t i = 0; i < NUM_LEDS; i++) {
				leds.led_data[i] = ColorFromPalette(leds.current_palette, leds.palette_march_index + i * beatsin8(leds.juggle_beat, 1, leds.palette_march_diff), 255, leds.current_blending);
			}
		}
		else {
			for (uint8_t i = 0; i < ONE_SIDE; i++) {
				leds.led_data[i] = ColorFromPalette(leds.current_palette, leds.palette_march_index + i * beatsin8(leds.juggle_beat, 1, leds.palette_march_diff), 255, leds.current_blending);
			}
			strip_sync(leds);
		}
	}
	else {
		for (uint8_t i = 0; i < ONE_SIDE / 2; i++) {
			leds.led_data[i] = ColorFromPalette(leds.current_palette, leds.palette_march_index + i * beatsin8(leds.juggle_beat, 1, leds.palette_march_diff), beatsin8(leds.juggle_beat + 4, 128, 255), leds.current_blending);
		}
		for (uint8_t i = 0; i < ONE_SIDE / 2; i++) {
			leds.led_data[ONE_SIDE - 1 - i] = leds.led_data[i];
		}
		strip_sync(leds);
	}
}


#endif