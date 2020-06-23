#ifndef NOISE_H
#define NOISE_H


void noise_init(LEDStruct& leds, bool ufr = random8(2), uint16_t s = random16(10,40), uint16_t y = random16(10,40), uint16_t d = random16(1000,50000), uint8_t nf = random8(32,60), uint8_t rr = random8(1,8), uint8_t rd = random8(1,6)) {
	leds.mode_initialized	= 1;
	leds.mode_type			= NOISE;
	leds.use_palette		= 1;
	leds.delay_time			= 5;

	leds.use_full_range		= ufr;
	if (leds.use_full_range) { leds.strip_range = NUM_LEDS; }
	else				  	 { leds.strip_range = ONE_SIDE; }

	leds.noise_scale	= s;
	leds.noise_yscale	= y;
	leds.noise_dist		= d;
	leds.noise_fade		= nf;

	leds.rainbow_rot	= rr;
	leds.rainbow_diff	= rr * 4 + random8(3);
	leds.rainbow_index	= 0;
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
		case 2:		leds.noise_yscale	= (uint16_t)update_arg;	break;	//c
		case 3:		leds.noise_dist		= (uint16_t)update_arg;	break;	//d
		case 4:		leds.noise_fade		= (uint8_t)update_arg;	break;	//e
		case 5:		leds.rainbow_rot	= (uint8_t)update_arg;	break;  //f
		case 6:		leds.rainbow_diff	= (uint8_t)update_arg;	break;  //g
		case 7:		leds.rainbow_index	= (uint8_t)update_arg;	break;	//h
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

	if (!leds.use_full_range) { strip_sync(leds); }
}


void noise_mover(LEDStruct& leds) {
	if (!leds.mode_initialized) { noise_init(leds); }
	if (keyboard_update) { noise_update(leds); }

	fadeToBlackBy(leds.led_data, NUM_LEDS, leds.noise_fade);
	uint8_t locn = inoise8(leds.noise_scale, leds.noise_dist + leds.noise_yscale) % 255;          
	uint8_t pixlen = map(locn, 0, 255, 0, leds.strip_range);     
	leds.led_data[pixlen] = ColorFromPalette(leds.current_palette, pixlen, 255, LINEARBLEND);   

	leds.noise_dist += beatsin8(10, 1, 4);

	if (!leds.use_full_range) { strip_sync(leds); }
}

void noise_mover_rainbow(LEDStruct& leds) {
	if (!leds.mode_initialized) { noise_init(leds); }
	if (keyboard_update) { noise_update(leds); }

	if (leds.this_dir == 0) leds.rainbow_index += leds.rainbow_rot; else leds.rainbow_index -= leds.rainbow_rot;
	fill_rainbow(leds.led_data, leds.strip_range, leds.rainbow_index, leds.rainbow_diff);

	uint8_t locn = inoise8(leds.noise_scale, leds.noise_dist + leds.noise_yscale) % 255;
	uint8_t pixlen = map(locn, 0, 255, 0, ONE_SIDE);
	for (uint16_t i = pixlen - 1; i < pixlen + 2; i++) {
		leds.led_data[i] = CRGB::Black;
	}
	leds.noise_dist += beatsin8(10, 1, 4);

	strip_sync(leds); 
}


#endif
