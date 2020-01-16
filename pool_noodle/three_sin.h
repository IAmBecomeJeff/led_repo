#ifndef THREE_SIN_H
#define THREE_SIN_H

void three_sin() {
	wave1 += beatsin8(10, -4, 4);
	wave2 += beatsin8(15, -2, 2);
	wave3 += beatsin8(12, -3, 3);

	for (int k = 0; k < NUM_LEDS; k++) {
		uint8_t tmp = sin8(mul1 * k + wave1) + sin8(mul2 * k + wave2) + sin8(mul3 * k + wave3);
		leds[k] = ColorFromPalette(current_palette, tmp, 255);
	}
}


#endif
