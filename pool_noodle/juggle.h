#ifndef JUGGLE_H
#define JUGGLE_H

void juggle_init(LEDStruct& leds, uint8_t ji = 0, uint8_t jn = random8(1,7), uint8_t jb = random8(8,20), uint8_t jf = random8(140,240), uint8_t jd = random8(1,9), bool jir = random8(2)) {
	if (DEBUG) { Serial.println("JUGGLE INIT BEGIN"); }
	leds.mode_initialized	= 1;
	leds.mode_name			= JUGGLE;
	leds.use_palette		= 1;

	leds.juggle_index		= ji;
	leds.juggle_numdots		= jn;
	leds.juggle_beat		= jb;
	leds.juggle_fade		= jf;
	leds.juggle_diff		= jd;
	leds.juggle_index_reset = jir;
	if (DEBUG) { Serial.println("JUGGLE INIT COMPLETE"); }
}



void juggle(LEDStruct& leds) {
	if (DEBUG) { Serial.println("JUGGLING"); }
	// If not yet iniatilized, call init function with random variables.
	if (!leds.mode_initialized) { juggle_init(leds); }

	// Keep the same color for each dot, or cycle through the palette
	if (leds.juggle_index_reset) { leds.juggle_index = 0; }

	// Fade all LEDs
	fadeToBlackBy(leds.led_data, NUM_LEDS, leds.juggle_fade);

	// Cycle juggle routine
	for (uint8_t i = 0; i < leds.juggle_numdots; i++) {
		if (leds.use_full_range) { leds.led_data[beatsin16(leds.juggle_beat + i + leds.juggle_numdots, 0, NUM_LEDS)]	 += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending); }
		else					 { leds.led_data[beatsin16(leds.juggle_beat + i + leds.juggle_numdots, 0, STRIP_LENGTH)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending); strip_sync(leds); }
		leds.juggle_index += leds.juggle_diff;
	}
}


#endif