#ifndef TWO_SIN_H
#define TWO_SIN_H

void two_sin_init(LEDStruct& leds, bool ufr = random8(2), uint8_t sh = random8(), uint8_t th = random8(), 
	uint8_t ss = random8(253,260), uint8_t ts = random8(1, 5), uint8_t sr = random8(3), uint8_t tr = random8(3), 
	uint8_t sc = random8(32, 80), uint8_t tc = random8(32, 80), uint8_t saf = random8(12, 33)) {

	leds.mode_initialized = 1;
	leds.mode_type = TWO_SIN;
	leds.use_palette = 0;
	leds.use_full_range = ufr;
	if (leds.use_full_range) { leds.strip_range = NUM_LEDS; }
	else					 { leds.strip_range = ONE_SIDE; }

	leds.sin_hue	= sh;		// changes by rot
	leds.two_hue	= th;
	leds.sin_speed	= ss;		// changes the phase
	leds.two_speed	= ts;
	leds.sin_rot	= sr;		// changes the hue
	leds.two_rot	= tr;
	leds.sin_cutoff = sc;		// limits the brightness
	leds.two_cutoff = tc;
	leds.sin_phase = 0;			// changes by speed
	leds.two_phase = 0;
	leds.sin_all_freq = saf;	// number of repeats
}


void two_sin_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {
		case 0:															//a
			leds.use_full_range = (bool)update_arg;
			if (leds.use_full_range) { leds.strip_range = NUM_LEDS; }
			else					 { leds.strip_range = ONE_SIDE; }
			break;
		case 1:		leds.sin_hue		= (uint8_t)update_arg;	break;	//b		
		case 2:		leds.two_hue		= (uint8_t)update_arg;	break;	//c
		case 3:		leds.sin_speed		= (uint8_t)update_arg;	break;	//d
		case 4:		leds.two_speed		= (uint8_t)update_arg;	break;	//e
		case 5:		leds.sin_rot		= (uint8_t)update_arg;	break;	//f
		case 6:		leds.two_rot		= (uint8_t)update_arg;	break;	//g
		case 7:		leds.sin_cutoff		= (uint8_t)update_arg;	break;	//h
		case 8:		leds.two_cutoff		= (uint8_t)update_arg;	break;	//i
		case 9:		leds.sin_phase		= (uint8_t)update_arg;	break;	//j
		case 10:	leds.two_phase		= (uint8_t)update_arg;	break;	//k
		case 11:	leds.sin_all_freq	= (uint8_t)update_arg;	break;	//l
		default:	break;
	}
	LEDDebug(leds);
}


void two_sin(LEDStruct& leds) {
	if (!leds.mode_initialized) { two_sin_init(leds); }
	if (keyboard_update) { two_sin_update(leds); }
	
	if (!leds.this_dir) { leds.sin_phase += leds.sin_speed; leds.two_phase += leds.two_speed; }
	else				{ leds.sin_phase -= leds.sin_speed; leds.two_phase -= leds.two_speed; }

	leds.sin_hue += leds.sin_rot;                                                // Hue rotation is fun for this_wave.
	leds.two_hue += leds.two_rot;                                                // It's also fun for that_wave.

	for (int k = 0; k < leds.strip_range; k++) {
		leds.sin_bri = qsuba(cubicwave8((k * leds.sin_all_freq) + leds.sin_phase), leds.sin_cutoff);     // qsub sets a minimum value called this_cutoff. If < this_cutoff, then bright = 0. Otherwise, bright = 128 (as defined in qsub)..
		leds.two_bri = qsuba(cubicwave8((k * leds.sin_all_freq) + 128 + leds.two_phase), leds.two_cutoff); // This wave is 180 degrees out of phase (with the value of 128).

		leds.led_data[k] = CHSV(leds.sin_hue, 255, leds.sin_bri);                              // Assigning hues and brightness to the led array.
		leds.led_data[k] += CHSV(leds.two_hue, 255, leds.two_bri);

	}
	if (!leds.use_full_range) { strip_sync(leds); }
}

#endif
