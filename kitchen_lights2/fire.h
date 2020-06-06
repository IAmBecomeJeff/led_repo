#ifndef FIRE_H
#define FIRE_H

void fire_init(LEDStruct& leds, uint8_t hl = random8(20, 31), uint8_t fs = random8(50, 110), uint8_t fc = random8(60, 120)) {
	leds.mode_initialized	= 1;
	leds.mode_type			= FIRE;
	leds.delay_time			= 15;
	leds.use_palette		= 0; 

	leds.fire_sparking		= fs;
	leds.fire_cooling		= fc;
}


void fire_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {
		case 0:		leds.fire_sparking	= (uint8_t)update_arg;	break;	//a
		case 1:		leds.fire_cooling	= (uint8_t)update_arg;	break;	//b	
		default:	break;
	}
	LEDDebug(leds);
}

void fire(LEDStruct& leds) {
	if (!leds.mode_initialized) { fire_init(leds); }
	if (keyboard_update) { fire_update(leds); }
	// heat[] array defined in LEDStruct

	// Step 1.  Cool down every cell a little
	for (int i = 0; i < NUM_LEDS; i++) {
		leds.heat[i] = qsub8(leds.heat[i], random8(0, ((leds.fire_cooling * 10) / NUM_LEDS) + 2));
	}

	// Step 2.  Heat from each cell drifts 'up' and diffuses a little
	for (int k = NUM_LEDS - 3; k >= 2; k--) {
		leds.heat[k] = (leds.heat[k - 1] + leds.heat[k - 2] + leds.heat[k - 2]) / 3;
	}

	// Step 3.  Randomly ignite new 'sparks' of heat near the bottom
	if (random8() < leds.fire_sparking) {
		uint8_t y = random8(7);
		leds.heat[y] = qadd8(leds.heat[y], random8(160, 255));
	}

	// Step 4.  Map from heat cells to LED colors
	if (leds.this_dir) {
		for (int j = 0; j < NUM_LEDS; j++) {
			leds.led_data[j] = HeatColor(leds.heat[j]);
		}
	}
	else {
		for (int j = 0; j < NUM_LEDS; j++) {
			leds.led_data[NUM_LEDS - 1 - j] = HeatColor(leds.heat[j]);
		}
	}
}




void fire_mirror(LEDStruct& leds) {
	if (!leds.mode_initialized) { fire_init(leds); }
	if (keyboard_update) { fire_update(leds); }

	for (int i = 0; i < NUM_LEDS / 2; i++) {
		leds.heat[i] = qsub8(leds.heat[i], random8(0, ((leds.fire_cooling * 10) / NUM_LEDS / 2) + 2));
	}

	for (int k = NUM_LEDS / 2 - 3; k >= 2; k--) {
		leds.heat[k] = (leds.heat[k - 1] + leds.heat[k - 2] + leds.heat[k - 2]) / 3;
	}

	if (random8() < leds.fire_sparking) {
		uint8_t y = random8(7);
		leds.heat[y] = qadd8(leds.heat[y], random8(160, 255));
	}

	if (leds.this_dir) {
		for (int j = 0; j < NUM_LEDS / 2; j++) {
			leds.led_data[j] = HeatColor(leds.heat[j]);
			leds.led_data[NUM_LEDS - 1 - j] = HeatColor(leds.heat[j]);
		}
	}
	else {
		for (int j = 0; j < NUM_LEDS / 2; j++) {
			leds.led_data[NUM_LEDS / 2 - 1 - j] = HeatColor(leds.heat[j]);
			leds.led_data[NUM_LEDS / 2 + j] = HeatColor(leds.heat[j]);
		}
	}
}




/*
void torch(LEDStruct& leds) {
	if (!leds.mode_initialized) { fire_init(leds); }
	if (keyboard_update) { fire_update(leds); }
	// Step 1
	for (int i = 0; i < leds.heat_length; i++) {
		leds.heat[i] = qsub8(leds.heat[i], random8(0, ((leds.fire_cooling * 10) / leds.heat_length) + 2));
	}
	if (!leds.fire_sync) {
		for (int i = 0; i < leds.heat_length; i++) {
			leds.heat2[i] = qsub8(leds.heat2[i], random8(0, ((leds.fire_cooling2 * 10) / leds.heat_length) + 2));
		}
	}

	// Step 2
	for (int k = leds.heat_length - 3; k >= 2; k--) {
		leds.heat[k] = (leds.heat[k - 1] + leds.heat[k - 2] + leds.heat[k - 2]) / 3;
	}
	if (!leds.fire_sync) {
		for (int k = leds.heat_length - 3; k >= 2; k--) {
			leds.heat2[k] = (leds.heat2[k - 1] + leds.heat2[k - 2] + leds.heat2[k - 2]) / 3;
		}
	}

	// Step 3
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

	// Step 4
	for (int j = 0; j < leds.heat_length; j++) {
		leds.led_data[NUM_LEDS - leds.heat_length + j] = HeatColor(leds.heat[j]);
	}

	else {
		for (int j = 0; j < leds.heat_length; j++) {
			leds.led_data[NUM_LEDS - 1 + leds.heat_length - j] = HeatColor(leds.heat2[j]);
		}
	}

	// Add pole to torch
	for (int i = 0; i < NUM_LEDS - leds.heat_length; i++) {
		leds.led_data[i] = ColorFromPalette(leds.current_palette, leds.torch_index + i * 255/leds.heat_length);
		leds.led_data[NUM_LEDS - 1 - i] = ColorFromPalette(leds.current_palette, leds.torch_index + i * 255/leds.heat_length);
	}
	if (leds.this_dir) { leds.torch_index += leds.torch_diff; }
	else			   { leds.torch_index -= leds.torch_diff; }
}


*/



#endif
