#ifndef ONE_SIN_H
#define ONE_SIN_H

void one_sin_init(LEDStruct& leds, uint8_t si = random8(1,6), uint8_t ss = random8(1,5), uint8_t sc = random8(128,240), uint8_t sr = random8(1,5), uint8_t sp = random8(0,5), uint8_t saf = random8(1,9), uint8_t bc = random8(), uint8_t bb = random8(10)) {
	leds.mode_initialized = 1;
	leds.mode_type = ONE_SIN;
	leds.use_palette = 1;

	leds.sin_inc		= si;
	leds.sin_speed		= ss;
	leds.sin_cutoff		= sc;
	leds.sin_rot		= sr;
	leds.sin_phase		= sp;
	leds.sin_all_freq	= saf;
	leds.bg_clr			= bc;
	leds.bg_bri			= bb;
	leds.sin_start		= 0;

}



void one_sin(LEDStruct& leds) {
	if (!leds.mode_initialized) { one_sin_init(leds); }

	leds.sin_start += leds.sin_inc;
	leds.sin_index = leds.sin_start;
	if (leds.this_dir) {
		leds.sin_phase += leds.sin_speed;
	}
	else {
		leds.sin_phase -= leds.sin_speed;
	}
	for (int k = 0; k < NUM_LEDS; k++) {
		int sin_bright = qsubd(cubicwave8((k * leds.sin_all_freq) + leds.sin_phase), leds.sin_cutoff);
		leds.led_data[k] = CHSV(leds.bg_clr, 255, leds.bg_bri);
		leds.led_data[k] += ColorFromPalette(leds.current_palette, leds.sin_index + k * leds.sin_inc, sin_bright, leds. current_blending);
		leds.sin_index += leds.sin_rot;
	}
}


#endif
