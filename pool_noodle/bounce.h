#ifndef BOUNCE_H
#define BOUNCE_H

void bounce_init(LEDStruct& leds, uint8_t jf = random8(32, 80), bool br = random8(2), uint8_t bl = random8(12, 21), uint8_t bsb = random8(16, 40), uint8_t jb = random8(80, 120), uint8_t rd = random8(1, 16)) {
	leds.mode_initialized = 1;
	leds.use_palette = 1;
	leds.mode_type = BOUNCE;
	leds.use_full_range = 0;
	fill_solid(leds.bounce, 20, CRGB::Black);

	leds.juggle_fade = jf;
	leds.bounce_length = bl;
	leds.juggle_beat = jb;
	leds.rainbow_diff = rd;
	leds.bounce_start_beat = bsb;
	leds.bounce_rainbow = br;
}


void bounce_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {
		case 0:		leds.juggle_fade		= (uint8_t)update_arg;	break;	//a
		case 1:		leds.bounce_length		= (uint8_t)update_arg;	leds.bounce_length = constrain(leds.bounce_length,10,BOUNCE_MAX_LENGTH);	//b		
		case 2:		leds.juggle_beat		= (uint8_t)update_arg;	break;	//c
		case 3:		leds.rainbow_diff		= (uint8_t)update_arg;	break;	//d
		case 4:		leds.bounce_start_beat	= (uint8_t)update_arg;	break;	//e
		case 5:		leds.bounce_rainbow		= (bool)update_arg;		break;	//f
		default:	break;
	}
	LEDDebug(leds);
}


void bounce(LEDStruct& leds) {
	if (!leds.mode_initialized) { bounce_init(leds); }
	if (keyboard_update) { bounce_update(leds); }

	if (leds.bounce_rainbow) { fill_rainbow(leds.led_data, ONE_SIDE, leds.rainbow_index++, leds.rainbow_diff); }
	else { fill_palette(leds.led_data, ONE_SIDE, leds.rainbow_index++, leds.rainbow_diff, leds.current_palette, 255, LINEARBLEND); }

	fadeToBlackBy(leds.bounce, 20, leds.juggle_fade);

	leds.bounce_pos = beatsin8(leds.juggle_beat, 0, leds.bounce_length - 1);
	leds.bounce[leds.bounce_pos] += ColorFromPalette(leds.current_palette, leds.juggle_index);

	for (uint8_t i = 0; i < leds.bounce_length; i++) {
		leds.led_data[leds.bounce_start + i] = CRGB::Black;
		nblend(leds.led_data[leds.bounce_start + i], leds.bounce[i], 255);
	}

	EVERY_N_MILLIS(25) { leds.bounce_start = beatsin8(leds.bounce_start_beat, 0, ONE_SIDE - leds.bounce_length - 1); }

	strip_sync(leds);
}


#endif