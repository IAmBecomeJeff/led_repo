#ifndef ONE_SIN_H
#define ONE_SIN_H

void one_sin_init(LEDStruct& leds, uint8_t si = random8(1,4), uint8_t ss = random8(5,13), uint8_t sc = random8(100,200), 
								uint8_t sr = random8(1,5), uint8_t sp = random8(0,5), uint8_t saf = random8(20,40), uint8_t bc = random8(), uint8_t bb = random8(10)) {
	leds.mode_initialized	= 1;
	leds.mode_type			= ONE_SIN;
	leds.use_palette		= 1;
	leds.delay_time			= 15;

	leds.sin_inc		= si;
	leds.sin_speed		= ss + (saf/5);
	leds.sin_cutoff		= sc;
	leds.sin_rot		= sr;
	leds.sin_phase		= sp;
	leds.sin_all_freq	= saf;
	leds.bg_clr			= bc;
	leds.bg_bri			= bb;
	leds.sin_start		= 0;

}

void one_sin_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {
		case 1:		leds.sin_inc		= (uint8_t)update_arg;	break;	//b		
		case 2:		leds.sin_speed		= (uint8_t)update_arg;	break;	//c
		case 3:		leds.sin_cutoff		= (uint8_t)update_arg;	break;	//d
		case 4:		leds.sin_rot		= (uint8_t)update_arg;	break;	//e
		case 5:		leds.sin_phase		= (uint8_t)update_arg;	break;	//f
		case 6:		leds.sin_all_freq	= (uint8_t)update_arg;	break;	//g
		case 7:		leds.bg_clr			= (uint8_t)update_arg;	break;	//h
		case 8:		leds.bg_bri			= (uint8_t)update_arg;	break;	//i
		case 9:		leds.sin_start		= (uint8_t)update_arg;	break;	//j
		default:	break;
	}
	LEDDebug(leds);
}

void one_sin(LEDStruct& leds) {
	if (!leds.mode_initialized) { one_sin_init(leds); }
	if (keyboard_update) { one_sin_update(leds); }

	leds.sin_start += leds.sin_inc;
	leds.sin_index = leds.sin_start;
	if (leds.this_dir) {
		leds.sin_phase += leds.sin_speed;
	}
	else {
		leds.sin_phase -= leds.sin_speed;
	}
	for (int k = 0; k < NUM_LEDS; k++) {
		int sin_bright = qsuba(cubicwave8((k * leds.sin_all_freq) + leds.sin_phase), leds.sin_cutoff);
		leds.led_data[k] = CHSV(leds.bg_clr, 255, leds.bg_bri);
		leds.led_data[k] += ColorFromPalette(leds.current_palette, leds.sin_index + k * leds.sin_inc, sin_bright, leds. current_blending);
		leds.sin_index += leds.sin_rot;
	}
}


#endif
