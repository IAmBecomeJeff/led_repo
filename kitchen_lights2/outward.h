#ifndef OUTWARD_H
#define OUTWARD_H

void outward_init(LEDStruct& leds, uint8_t of = random8(2,32), uint8_t b1 = random8(4,11), uint8_t b2 = random8(4,11), uint8_t m1 = random8(0,200), uint8_t m2 = random8(0,200)) {
	leds.mode_initialized	= 1;
	leds.mode_type			= OUTWARD;
	leds.use_palette		= 1;
	leds.delay_time			= 15;

	leds.out_fade	= of;
	leds.out_beat1	= b1;
	leds.out_beat2	= b2;
	leds.out_min1	= m1;
	leds.out_min2	= m2;
}

void outward_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {
	case 0:		leds.out_fade	= (uint8_t)update_arg;	break;	//a
	case 1:		leds.out_beat1	= (uint8_t)update_arg;	break;	//b		
	case 2:		leds.out_beat2	= (uint8_t)update_arg;	break;	//c
	case 3:		leds.out_min1	= (uint8_t)update_arg;	break;	//d
	case 4:		leds.out_min2	= (uint8_t)update_arg;	break;  //e
	default:	break;
	}
	LEDDebug(leds);
}


void outward(LEDStruct& leds) {
	if (!leds.mode_initialized) { outward_init(leds); }
	if (keyboard_update) { outward_update(leds); }

	leds.led_data[ONE_SIDE / 2]		= ColorFromPalette(leds.current_palette, beatsin8(leds.out_beat2), beatsin8(leds.out_beat1, leds.out_min1, 255), leds.current_blending);
	leds.led_data[ONE_SIDE / 2 - 1] = ColorFromPalette(leds.current_palette, beatsin8(leds.out_beat1), beatsin8(leds.out_beat2, leds.out_min2, 255), leds.current_blending);

	for (int i = ONE_SIDE - 1; i > ONE_SIDE / 2; i--) {						// Move to the right.
		leds.led_data[i] = leds.led_data[i - 1];
		leds.led_data[NUM_LEDS - (i + 1)] = leds.led_data[NUM_LEDS - i];
	}
	for (int i = 0; i < ONE_SIDE / 2 - 1; i++) {							// Move to the left.
		leds.led_data[i] = leds.led_data[i + 1];
		leds.led_data[NUM_LEDS - 1 - i] = leds.led_data[NUM_LEDS - 1 - i - 1];
	}

	fadeToBlackBy(leds.led_data, NUM_LEDS, leds.out_fade);
}





#endif
