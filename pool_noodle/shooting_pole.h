#ifndef SHOOTING_POLE_H
#define SHOOTING_POLE_H


void shooting_pole_init(LEDStruct& leds, uint8_t sr = ONE_SIDE - random8(18, 31), uint8_t pd = random8(1, 6), uint8_t jf = random8(50, 120), uint8_t jb = random(50, 70), uint8_t jd = random8(1, 8)) {
	leds.mode_initialized = 1;
	leds.use_palette = 1;
	leds.mode_type = SHOOTING_POLE;
	leds.use_full_range = 0;

	leds.strip_range = sr;
	leds.pole_diff   = pd;
	leds.juggle_fade = jf;
	leds.juggle_beat = jb;
	leds.juggle_diff = jd;
}

void shooting_pole_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {

		case 0:															//a
			leds.strip_range	= (uint8_t)update_arg;	
			leds.strip_range	= constrain(leds.strip_range, 10, ONE_SIDE - 10);
			break;	
		case 1:		leds.pole_diff		= (uint8_t)update_arg;	break;	//b
		case 2:		leds.juggle_fade	= (uint8_t)update_arg;	break;	//c
		case 3:		leds.juggle_beat	= (uint8_t)update_arg;	break;	//d
		case 4:		leds.juggle_diff	= (uint8_t)update_arg;	break;	//e
		default:	break;
	}
	LEDDebug(leds);
}

void shooting_pole(LEDStruct& leds) {
	if (!leds.mode_initialized) { shooting_pole_init(leds); }
	if (keyboard_update) { shooting_pole_update(leds); }

	// Add pole
	for (int i = 0; i < leds.strip_range; i++) {
		leds.led_data[i] = ColorFromPalette(leds.current_palette, leds.pole_index + i * 255 / leds.strip_range);
	}
	if (leds.this_dir) { leds.pole_index += leds.pole_diff; }
	else { leds.pole_index -= leds.pole_diff; }

	// Fade juggle LEDs
	for (int i = leds.strip_range; i < ONE_SIDE; i++) { leds.led_data[i].fadeToBlackBy(leds.juggle_fade); }

	// Add juggle LEDs
	leds.led_data[beatsin16_halfup(leds.juggle_beat, leds.strip_range, ONE_SIDE - 1)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending);

	// Change juggle color
	EVERY_N_MILLIS(50) { leds.juggle_index += leds.juggle_diff; }

	strip_sync(leds);
}


#endif
