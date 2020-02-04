#ifndef RAINBOW_MARCH_H
#define RAINBOW_MARCH_H

void rainbow_init(LEDStruct& leds, bool rs = random8(2), uint8_t rd = random8(1, 20), uint8_t rr = random8(1, 4), bool ufr = random8(2)) {
    leds.mode_initialized = 1;
	leds.mode_type = RAINBOW_MARCH;
    leds.use_palette = 0;

	leds.use_full_range = ufr;

	leds.rainbow_split  = rs;
	if (rd == 1) { rr = 1; }
    leds.rainbow_diff   = rd;
    leds.rainbow_rot    = rr;
	

    if (DEBUG) { LEDDebug(leds); }
}

void rainbow_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {
		case 0:															//a
			leds.use_full_range = (bool)update_arg;
			if (leds.use_full_range) { leds.strip_range = NUM_LEDS; }
			else { leds.strip_range = ONE_SIDE; }
			break;
		case 1:		leds.rainbow_split	= (bool)update_arg;		break;	//b		
		case 2:		leds.rainbow_diff	= (uint8_t)update_arg;	break;	//c
		case 3:		leds.rainbow_rot	= (uint8_t)update_arg;	break;	//d
		default:	break;
	}
	LEDDebug(leds);
}



void rainbow_march(LEDStruct& leds) {
	// If not yet iniatilized, call init function with random variables.
	if (!leds.mode_initialized) { rainbow_init(leds, RAINBOW_MARCH); }
	if (keyboard_update) { rainbow_update(leds); }

	// Increase the start index by the rotation (essentially speed)
	if (leds.this_dir == 0) leds.rainbow_index += leds.rainbow_rot; else leds.rainbow_index -= leds.rainbow_rot;

	// Apply rainbow to LEDs
	if (!leds.rainbow_split) {
		if (leds.use_full_range) { fill_rainbow(leds.led_data, NUM_LEDS, leds.rainbow_index, leds.rainbow_diff); }
		else					 { fill_rainbow(leds.led_data, ONE_SIDE, leds.rainbow_index, leds.rainbow_diff); strip_sync(leds); }
	}
	else {
		// Apply rainbow to half of one side of the LEDs.  No use_full_range for this one
		fill_rainbow(leds.led_data, ONE_SIDE / 2, leds.rainbow_index, leds.rainbow_diff);

		// Copy those to the other half
		for (int i = 0; i < ONE_SIDE / 2; i++) { leds.led_data[ONE_SIDE - 1 - i] = leds.led_data[i]; }

		// Duplicate on the other side of the strip
		strip_sync(leds);
	}
}



#endif
