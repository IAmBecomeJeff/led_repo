// Palette Motion

void palette_motion() {
	if (this_dir) { color_index += color_speed; }
	else { color_index -= color_speed; }
	for (int i = 0; i < NUM_LEDS; i++) {
		leds[i] = ColorFromPalette(currentPalette, color_index+i, this_bright, currentBlending);
	}
}

void center_matrix_motion() {
	this_index++;

	if (random8(90) > 80) {
		leds[rightFromCenter[0]] = ColorFromPalette(currentPalette, this_index, this_bright, currentBlending);
		leds[leftFromCenter[0]] = ColorFromPalette(currentPalette, this_index, this_bright, currentBlending);
		//fromCenterPal(0, currentPalette, this_index, this_bright, currentBlending);
	}
	else {
		leds[rightFromCenter[0]] = CRGB(0, 0, 0);
		leds[leftFromCenter[0]] = CRGB(0, 0, 0);
		//fromCenterCRGB(0, 0, 0, 0);
	}
	for (int i = 97; i > 0; i--) {
		leds[rightFromCenter[i]] = leds[rightFromCenter[i - 1]];
		leds[leftFromCenter[i]] = leds[leftFromCenter[i - 1]];

		//leds[centerRight[i]] = leds[centerRight[i - 1]];
		//leds[centerLeft[i]] = leds[centerLeft[i - 1]];
	}
}
