#ifndef JUGGLE_H
#define JUGGLE_H

void juggle_init(LEDStruct& leds, bool jod = random8(2), bool jp = random8(2), bool td = random8(2), uint8_t jn = random8(1, 7), uint8_t jb = random8(8, 20), uint8_t jf = random8(140, 240), uint8_t jd = random8(1, 9), bool jir = random8(2), bool ufr = random8(2)) {
	leds.mode_initialized	= 1;
	leds.mode_type			= JUGGLE;
	leds.use_palette		= 1;
	leds.use_full_range		= ufr;

	leds.juggle_one_dir		 = jod;
	leds.juggle_phased		 = jp;
	leds.juggle_numdots 	 = jn;
	leds.juggle_beat		 = jb;
	leds.juggle_fade		 = jf;
	leds.juggle_diff		 = jd;
	leds.juggle_index_reset  = jir;
}

// TODO make a juggle where the colorfrompalette is scaled to the position

void juggle(LEDStruct& leds) {
	// If not yet iniatilized, call init function with random variables.
	if (!leds.mode_initialized) { juggle_init(leds); }

	// Keep the same color for each dot, or cycle through the palette
	if (leds.juggle_index_reset) { leds.juggle_index = 0; }

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



#endif