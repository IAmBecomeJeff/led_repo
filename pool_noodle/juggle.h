#ifndef JUGGLE_H
#define JUGGLE_H

void juggle_init(LEDStruct& leds, bool jod = random8(2), bool jp = random8(2), bool td = random8(2), uint8_t jn = random8(1, 6), uint8_t jb = random8(10, 20), 
					uint8_t jf = random8(32, 80), uint8_t jd = random8(1, 3), bool jir = random8(2), bool ufr = random8(2)) {
	leds.mode_initialized	= 1;
	leds.mode_type			= JUGGLE;
	leds.use_palette		= 1;
	leds.use_full_range		= ufr;
	leds.delay_time			= 15;

	leds.juggle_one_dir		 = jod;
	leds.juggle_phased		 = jp;
	leds.juggle_numdots 	 = jn;
	leds.juggle_beat		 = jb;
	leds.juggle_fade		 = jf;
	leds.juggle_diff		 = jd;
	leds.juggle_index_reset  = jir;
	if (leds.juggle_index_reset) { leds.juggle_diff *= 10; }
	if (leds.mode_name == MULTI_JUGGLE) { leds.juggle_numdots = 15; leds.juggle_beat += 55; }
	if (leds.mode_name == JUGGLE_HALF) { leds.juggle_beat += 4; leds.juggle_numdots += random8(6); }
}

void juggle_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {
			case 0:		leds.use_full_range		= (bool)update_arg;		break;	//a
			case 1:		leds.juggle_one_dir		= (bool)update_arg;		break;	//b		
			case 2:		leds.juggle_phased		= (bool)update_arg;		break;	//c
			case 3:		leds.juggle_numdots		= (uint8_t)update_arg;	break;	//d
			case 4:		leds.juggle_beat		= (uint8_t)update_arg;	break;	//e
			case 5:		leds.juggle_fade		= (uint8_t)update_arg;	break;	//f
			case 6:		leds.juggle_diff		= (uint8_t)update_arg;	break;	//g
			case 7:		leds.juggle_index_reset = (bool)update_arg;		break;	//h
			default:	break;
	}
	LEDDebug(leds);
}



// TODO make a juggle where the colorfrompalette is scaled to the position

void juggle(LEDStruct& leds) {
	// If not yet iniatilized, call init function with random variables.
	if (!leds.mode_initialized) { juggle_init(leds); }
	if (keyboard_update) { juggle_update(leds); }

	// Keep the same color for each dot, or cycle through the palette
	if (leds.juggle_index_reset) { 
		leds.juggle_index = 0; 
		palette_check(leds);
	}

	// Fade all LEDs
	fadeToBlackBy(leds.led_data, NUM_LEDS, leds.juggle_fade);

	// Cycle juggle routine
	if(!leds.juggle_one_dir){
		if (leds.juggle_phased) {
			for (uint8_t i = 0; i < leds.juggle_numdots; i++) {			// JUGGLE PHASED
				if (leds.use_full_range) { leds.led_data[beatsin16(leds.juggle_beat + i + leds.juggle_numdots, 0, NUM_LEDS - 1)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending); }
				else					 { leds.led_data[beatsin16(leds.juggle_beat + i + leds.juggle_numdots, 0, ONE_SIDE - 1)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending); strip_sync(leds); }
				leds.juggle_index += leds.juggle_diff;
			}
		}
		else {
			for (uint8_t i = 0; i < leds.juggle_numdots; i++) {			// JUGGLE OUT OF PHASE
				if (leds.use_full_range) { leds.led_data[beatsin16(leds.juggle_beat, 0, NUM_LEDS - 1, 0, 8192 * i)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending); }
				else					 { leds.led_data[beatsin16(leds.juggle_beat, 0, ONE_SIDE - 1, 0, 8192 * i)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending); strip_sync(leds); }
				leds.juggle_index += leds.juggle_diff;
			}
		}
	}
	else {
		if (leds.juggle_phased) {
			for (uint8_t i = 0; i < leds.juggle_numdots; i++) {
				if (leds.this_dir) {
					if (leds.use_full_range) { leds.led_data[beatsin16_halfdown(leds.juggle_beat, 0, NUM_LEDS - 1, 500 * i)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending); }
					else					 { leds.led_data[beatsin16_halfdown(leds.juggle_beat, 0, ONE_SIDE - 1, 500 * i)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending); strip_sync(leds); }
				}
				else {
					if (leds.use_full_range) { leds.led_data[beatsin16_halfup(leds.juggle_beat, 0, NUM_LEDS - 1, 500 * i)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending); }
					else					 { leds.led_data[beatsin16_halfup(leds.juggle_beat, 0, ONE_SIDE - 1, 500 * i)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending); strip_sync(leds); }
				}
				leds.juggle_index += leds.juggle_diff;
			}
		}
		else {
			for (uint8_t i = 0; i < leds.juggle_numdots; i++) {
				if (leds.this_dir) {
					if (leds.use_full_range) { leds.led_data[beatsin16_halfdown(leds.juggle_beat + i + leds.juggle_numdots, 0, NUM_LEDS - 1)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending); }
					else					 { leds.led_data[beatsin16_halfdown(leds.juggle_beat + i + leds.juggle_numdots, 0, ONE_SIDE - 1)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending); strip_sync(leds); }
				}
				else {
					if (leds.use_full_range) { leds.led_data[beatsin16_halfup(leds.juggle_beat + i + leds.juggle_numdots, 0, NUM_LEDS - 1)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending); }
					else					 { leds.led_data[beatsin16_halfup(leds.juggle_beat + i + leds.juggle_numdots, 0, ONE_SIDE - 1)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending); strip_sync(leds); }
				}
				leds.juggle_index += leds.juggle_diff;
			}
		}
	}
}



void juggle_half(LEDStruct& leds) {
	// If not yet iniatilized, call init function with random variables.
	if (!leds.mode_initialized) { juggle_init(leds); }
	if (keyboard_update) { juggle_update(leds); }

	// Keep the same color for each dot, or cycle through the palette
	if (leds.juggle_index_reset) { leds.juggle_index = 0; }

	// Fade all LEDs
	fadeToBlackBy(leds.led_data, NUM_LEDS, leds.juggle_fade);

	if (leds.this_dir) {
		for (uint8_t i = 0; i < leds.juggle_numdots; i++) {
			leds.led_data[beatsin16_halfdown(leds.juggle_beat + i + leds.juggle_numdots, ONE_SIDE / 2, ONE_SIDE - 1)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending);
			leds.led_data[beatsin16_halfup(leds.juggle_beat + i + leds.juggle_numdots, 0, ONE_SIDE / 2)]			  += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending);
			leds.juggle_index += leds.juggle_diff;
		}
	}
	else {
		for (uint8_t i = 0; i < leds.juggle_numdots; i++) {
			leds.led_data[beatsin16_halfup(leds.juggle_beat + i + leds.juggle_numdots, ONE_SIDE / 2, ONE_SIDE - 1)]	+= ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending);
			leds.led_data[beatsin16_halfdown(leds.juggle_beat + i + leds.juggle_numdots, 0, ONE_SIDE / 2)]			+= ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending);
			leds.juggle_index += leds.juggle_diff;
		}
	}

	if (leds.use_full_range) {
		if (leds.this_dir) {
			for (uint8_t i = 0; i < leds.juggle_numdots; i++) {
				leds.led_data[beatsin16_halfdown(leds.juggle_beat + i + leds.juggle_numdots + 1, ONE_SIDE + (ONE_SIDE / 2), NUM_LEDS - 1)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending);
				leds.led_data[beatsin16_halfup(leds.juggle_beat + i + leds.juggle_numdots + 1, ONE_SIDE, ONE_SIDE + (ONE_SIDE / 2) - 1)]   += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending);
				leds.juggle_index += leds.juggle_diff;
			}
		}
		else {
			for (uint8_t i = 0; i < leds.juggle_numdots; i++) {
				leds.led_data[beatsin16_halfup(leds.juggle_beat + i + leds.juggle_numdots + 1, ONE_SIDE + (ONE_SIDE / 2), NUM_LEDS - 1)]   += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending);
				leds.led_data[beatsin16_halfdown(leds.juggle_beat + i + leds.juggle_numdots + 1, ONE_SIDE, ONE_SIDE + (ONE_SIDE / 2) - 1)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending);
				leds.juggle_index += leds.juggle_diff;
			}
		}
	}
	else {
		strip_sync(leds);
	}
}


// TODO: halfdown/halfup, keep beat > 30, index reset off, diff low

void multi_juggle(LEDStruct& leds) {
	// If not yet iniatilized, call init function with random variables.
	if (!leds.mode_initialized) { juggle_init(leds); }
	if (keyboard_update) { juggle_update(leds); }

	//if (leds.juggle_index_reset) { leds.juggle_index = 0; }

	fadeToBlackBy(leds.led_data, NUM_LEDS, leds.juggle_fade);

	for (uint8_t i = 0; i < leds.juggle_numdots; i++) {
		leds.led_data[beatsin16(leds.juggle_beat + i, i * (ONE_SIDE / leds.juggle_numdots), (i + 1) * (ONE_SIDE / leds.juggle_numdots) - 1)] += ColorFromPalette(leds.current_palette, leds.juggle_index + leds.juggle_diff * i, leds.brightness, leds.current_blending);
		//leds.juggle_index += leds.juggle_diff;
	}
	strip_sync(leds);
	EVERY_N_MILLIS(500) { leds.juggle_index++; }
}





#endif