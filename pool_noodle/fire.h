#ifndef FIRE_H
#define FIRE_H

void fire_init(LEDStruct& leds, bool fy = random8(2), bool fm = random8(2), uint8_t fs = random8(50, 110), uint8_t fc = random8(60, 120)) {
	leds.mode_initialized	= 1;
	leds.mode_type			= FIRE;
	leds.use_palette		= 0;

	leds.fire_sparking		= fs;
	leds.fire_cooling		= fc;
	leds.fire_sync			= fy;
	leds.fire_mirror		= fm;
	
	if (leds.fire_mirror) { leds.heat_length = ONE_SIDE / 2; leds.fire_offset = leds.heat_length; }
	else				  { leds.heat_length = ONE_SIDE;	 leds.fire_offset = 0; }

	if (!leds.fire_sync) {
		leds.fire_sparking2 = fs - 10 + random8(21);
		leds.fire_cooling2	= fc - 10 + random8(21);
	}
}


void fire(LEDStruct& leds) {
	// heat[] array defined in LEDStruct

	// Step 1.  Cool down every cell a little
	for (int i = 0; i < leds.heat_length; i++) {
		leds.heat[i] = qsub8(leds.heat[i], random8(0, ((leds.fire_cooling * 10) / leds.heat_length) + 2));
	}

	if (!leds.fire_sync) {
		for (int i = 0; i < leds.heat_length; i++) {
			leds.heat2[i] = qsub8(leds.heat2[i], random8(0, ((leds.fire_cooling2 * 10) / leds.heat_length) + 2));
		}
	}

	// Step 2.  Heat from each cell drifts 'up' and diffuses a little
	for (int k = leds.heat_length - 3; k >= 2; k--) {
		leds.heat[k] = (leds.heat[k - 1] + leds.heat[k - 2] + leds.heat[k - 2]) / 3;
	}

	if (!leds.fire_sync) {
		for (int k = leds.heat_length - 3; k >= 2; k--) {
			leds.heat2[k] = (leds.heat2[k - 1] + leds.heat2[k - 2] + leds.heat2[k - 2]) / 3;
		}
	}

	// Step 3.  Randomly ignite new 'sparks' of heat near the bottom
	if (random8() < leds.fire_sparking) {
		uint8_t y = random8(7);
		leds.heat[y] = qadd8(leds.heat[y], random8(160, 255));
	}

	if (!leds.fire_sync) {
		if (random8() < leds.fire_sparking2) {
			int y = random8(7);
			leds.heat2[y] = qadd8(leds.heat2[y], random8(160, 255));
		}
	}
	// Step 4.  Map from heat cells to LED colors
	if (leds.this_dir) {
		for (int j = 0; j < leds.heat_length; j++) {
			leds.led_data[j] = HeatColor(leds.heat[j]);
		}
	}
	else {
		for (int j = 0; j < leds.heat_length; j++) {
			leds.led_data[leds.heat_length - leds.fire_offset - 1 - j] = HeatColor(leds.heat[j]);
		}
	}

	if (leds.fire_mirror) {
		if (leds.this_dir) {
			for (int j = 0; j < leds.heat_length; j++) {
				leds.led_data[ONE_SIDE - 1 - j] = HeatColor(leds.heat[j]);
			}
		}
		else {
			for (int j = 0; j < leds.heat_length; j++) {
				leds.led_data[leds.heat_length / 2 + j] = HeatColor(leds.heat[j]);
			}
		}
	}

	if (leds.fire_sync) { strip_sync(leds); }
	else {
		if (leds.this_dir) {
			for (int j = 0; j < leds.heat_length; j++) {
				leds.led_data[NUM_LEDS - 1 - j] = HeatColor(leds.heat2[j]);
			}
		}
		else {
			for (int j = 0; j < leds.heat_length; j++) {
				leds.led_data[ONE_SIDE + leds.fire_offset + j] = HeatColor(leds.heat2[j]);
			}
		}
		if (leds.fire_mirror) {
			if (leds.this_dir) {
				for (int j = 0; j < leds.heat_length; j++) {
					leds.led_data[ONE_SIDE + j] = HeatColor(leds.heat2[j]);
				}
			}
			else {
				for (int j = 0; j < leds.heat_length; j++) {
					leds.led_data[ONE_SIDE + leds.heat_length - j] = HeatColor(leds.heat2[j]);
				}
			}
		}
	}
}

/*
// fire with a palette
void fire_pal() {
	if (mode_change) {
		mode_change = 0;
		sparking = random8(50, 110);
		cooling = random8(50, 120);
		use_palette = 1;
		this_delay = 15;
	}
	static byte heat[NUM_LEDS];

	// Step 1.  Cool down every cell a little
	for (int i = 0; i < NUM_LEDS; i++) {
		heat[i] = qsub8(heat[i], random8(0, ((cooling * 10) / NUM_LEDS) + 2));
	}

	// Step 2.  Heat from each cell drifts 'up' and diffuses a little
	for (int k = NUM_LEDS - 1; k >= 2; k--) {
		heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
	}

	// Step 3.  Randomly ignite new 'sparks' of heat near the bottom
	if (random8() < sparking) {
		int y = random8(7);
		heat[y] = qadd8(heat[y], random8(160, 255));
	}

	// Step 4.  Map from heat cells to LED colors
	for (int j = 0; j < NUM_LEDS; j++) {
		// Scale the heat value from 0-255 down to 0-240 for best results with color palettes.
		byte colorindex = scale8(heat[j], 240);
		leds[pixelnumber] = ColorFromPalette(current_palette, colorindex);
	}
}



// fire mirrored from ends or center
void fire_mirror() {
	if (mode_change) {
		mode_change = 0;
		sparking = random8(50, 110);
		cooling = random8(50, 120);
		use_palette = 0;
		this_dir = random8(2);
		this_delay = 15;
	}
		static byte heat[NUM_LEDS / 2];
		for (int i = 0; i < NUM_LEDS / 2; i++) {
			heat[i] = qsub8(heat[i], random8(0, ((cooling * 10) / (NUM_LEDS / 2)) + 2));
		}
		for (int k = (NUM_LEDS / 2) - 1; k >= 2; k--) {
			heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
		}
		if (random8() < sparking) {
			int y = random8(7);
			heat[y] = qadd8(heat[y], random8(160, 255));
		}
		if (this_dir) {
			for (int j = 0; j < NUM_LEDS / 2; j++) {
				leds[j] = HeatColor(heat[j]);
				leds[NUM_LEDS - 1 - j] = HeatColor(heat[j]);
			}
		}
		else {
			for (int j = 0; j < NUM_LEDS / 2; j++) {
				leds[(NUM_LEDS / 2) - 1 - j] = HeatColor(heat[j]);
				leds[(NUM_LEDS / 2) + j]	 = HeatColor(heat[j]);
			}
		}
}



// fire mirrored from ends or center using palette
void fire_mirror_pal() {
	if (mode_change) {
		mode_change = 0;
		sparking = random8(50, 110);
		cooling = random8(50, 120);
		use_palette = 1;
		this_dir = random8(2);
		this_delay = 15;
	}
	static byte heat[NUM_LEDS / 2];
	for (int i = 0; i < NUM_LEDS / 2; i++) {
		heat[i] = qsub8(heat[i], random8(0, ((cooling * 10) / (NUM_LEDS / 2)) + 2));
	}
	for (int k = (NUM_LEDS / 2) - 1; k >= 2; k--) {
		heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
	}
	if (random8() < sparking) {
		int y = random8(7);
		heat[y] = qadd8(heat[y], random8(160, 255));
	}
	for (int j = 0; j < NUM_LEDS / 2; j++) {
		byte colorindex = scale8(heat[j], 240);
		if (this_dir) {
			leds[j]					= ColorFromPalette(current_palette, colorindex);
			leds[NUM_LEDS - 1 - j]  = ColorFromPalette(current_palette, colorindex);
		}
		else {
			leds[(NUM_LEDS / 2) - 1 - j] = ColorFromPalette(current_palette, colorindex);
			leds[(NUM_LEDS / 2) + j]	 = ColorFromPalette(current_palette, colorindex);
		}
	}
}

*/


#endif
