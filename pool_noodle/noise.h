#ifndef NOISE_H
#define NOISE_H


void noise_init(LEDStruct& leds, bool ufr = random8(2), uint16_t s = random16(30,100), uint16_t d = random16(1000,50000)) {
	leds.mode_initialized = 1;
	leds.mode_type = NOISE;
	leds.use_palette = 1;
	leds.use_full_range = ufr;
	if (leds.use_full_range) { leds.strip_range = NUM_LEDS; }
	else				  	 { leds.strip_range = ONE_SIDE; }

	leds.noise_scale = s;
	leds.noise_dist = d;
}

void noise_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {
		case 0:															//a
			leds.use_full_range = (bool)update_arg;	
			if (leds.use_full_range) { leds.strip_range = NUM_LEDS; } 
			else { leds.strip_range = ONE_SIDE; } 
			break;	
		case 1:		leds.noise_scale	= (uint16_t)update_arg;	break;	//b		
		case 2:		leds.noise_dist		= (uint16_t)update_arg;	break;	//c
		default:	break;
	}
	LEDDebug(leds);
}

void noise(LEDStruct& leds) {
	if (!leds.mode_initialized) { noise_init(leds); }
	if (keyboard_update) { noise_update(leds); }

	for (int i = 0; i < leds.strip_range; i++) {
		leds.noise_index = inoise8(i * leds.noise_scale, leds.noise_dist + i * leds.noise_scale) % 255;
		leds.led_data[i] = ColorFromPalette(leds.current_palette, leds.noise_index, 255, LINEARBLEND);
	}
	leds.noise_dist += beatsin8(10, 1, 4);
}


#endif
