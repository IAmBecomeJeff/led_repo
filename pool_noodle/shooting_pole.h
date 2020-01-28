#ifndef SHOOTING_POLE_H
#define SHOOTING_POLE_H


void shooting_pole_init(LEDStruct& leds, uint8_t sr = ONE_SIDE - random8(18, 31), uint8_t pd = random8(1, 6), uint8_t jf = random8(150, 220), uint8_t jb = random(50, 70), uint8_t jd = random8(1, 8)) {
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


void shooting_pole(LEDStruct& leds) {
	if (!leds.mode_initialized) { shooting_pole_init(leds); }

	// Add pole
	for (int i = 0; i < leds.strip_range; i++) {
		leds.led_data[i] = ColorFromPalette(leds.current_palette, leds.pole_index + i * 255 / leds.strip_range);
	}
	if (leds.this_dir) { leds.pole_index += leds.pole_diff; }
	else { leds.pole_index -= leds.pole_diff; }

	// Add juggle
	for (int i = leds.strip_range; i < ONE_SIDE; i++) { leds.led_data[i].fadeToBlackBy(leds.juggle_fade); }
	leds.led_data[beatsin16_halfup(leds.juggle_beat, leds.strip_range, ONE_SIDE - 1)] += ColorFromPalette(leds.current_palette, leds.juggle_index, leds.brightness, leds.current_blending);
	EVERY_N_MILLIS(50) { leds.juggle_index += leds.juggle_diff; }
	strip_sync(leds);
}


#endif
