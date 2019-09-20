#ifndef FUNCTIONS_H
#define FUNCTIONS_H

void fadeall() { for (int i = 0; i < NUM_LEDS; i++) { leds[i].nscale8(fade_val); } }

void ico_fill_rainbow() {
	hue = ico_index;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			leds[icosahedron[i][j]] = CHSV(hue, 255, 240);
		}
		hue -= delta;
	}
	ico_index += increment;
}

void ico_palette() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 5; j++) {
			leds[icosahedron[i][j]] = ColorFromPalette(current_palette, pal_index + i * delta, 255);
		}
	}
	pal_index += increment;
}

void spin() {
	fadeall();
	leds[spin_order[this_index][0]] = CHSV(hue, 255, 255);
	leds[spin_order[this_index][1]] = CHSV(hue, 255, 255);
	hue++;
	this_index = (this_index + 1) % (NUM_LEDS / 2);
}

void juggle() {
	fadeall();
	for (uint8_t dot = 0; dot < numdots; dot++) {
		juggle_position = beatsin16(beat + dot + numdots, 0, NUM_LEDS - 1);
		leds[spiral_order[juggle_position]] += CHSV(hue++, 255, 255);
	}
}

void juggle_palette() {
	fadeall();
	for (uint8_t dot = 0; dot < numdots; dot++) {
		juggle_position = beatsin16(beat + dot + numdots, 0, NUM_LEDS - 1);
		leds[spiral_order[juggle_position]] += ColorFromPalette(current_palette, palette_index++, max_bright, LINEARBLENDING);
	}
}

void juggle_up_and_down() {
	fadeall();
	for (uint8_t dot = 0; dot < numdots; dot++) {
		juggle_position = beatsin16(beat + dot + numdots, 0, NUM_LEDS - 1);
		leds[icosahedron[juggle_position]] += CHSV(hue++, 255, 255);
	}
}




#endif