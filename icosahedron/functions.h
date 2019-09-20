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
			leds[icosahedron[i][j]] = ColorFromPalette(current_palette, palette_index + i * delta, 255);
		}
	}
	palette_index += increment;
}

void spin() {
	fadeall();
	leds[spin_order[ico_index][0]] = CHSV(hue, 255, 255);
	leds[spin_order[ico_index][1]] = CHSV(hue, 255, 255);
	hue++;
	ico_index = (ico_index + 1) % (NUM_LEDS / 2);
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
		leds[spiral_order[juggle_position]] += ColorFromPalette(current_palette, palette_index++, max_bright, LINEARBLEND);
	}
}

void juggle_up_and_down() {
	fadeall();
	for (uint8_t dot = 0; dot < numdots; dot++) {
		juggle_position = beatsin16(beat + dot + numdots, 0, 3);
		for (int row = 0; row < 5; row++) {
			leds[icosahedron[juggle_position][row]] += CHSV(hue++, 255, 255);
		}
	}
}

void confetti() {
	fadeall();
	confetti_position = random8(NUM_LEDS);
	leds[confetti_position] += CHSV(random8(), 200, 255);
}

void confetti_palette(){
  fadeall();
  confetti_position = random8(NUM_LEDS);
  leds[confetti_position] += ColorFromPalette(current_palette, random8(), max_bright);
}


#endif
