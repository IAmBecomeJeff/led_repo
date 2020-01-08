#ifndef CONFETTI_H
#define CONFETTI_H

void confetti()
{
	if (mode_change) {
		mode_change = 0;
		use_palette = 1;
		this_fade = random8(10, 48);
		this_delay = 20;
		use_all_shelves = random8(2);
	}
	// random colored speckles that blink in and fade smoothly
	fadeToBlackBy(leds, NUM_LEDS, this_fade);
	if (use_all_shelves) {
		int pos = random16(NUM_LEDS);
		this_index = random8();
		leds[pos] += ColorFromPalette(current_palette, this_index);
	}
	else {
		for (uint8_t s = 0; s < 4; s++)	{
			int pos = random8(shelf_num_leds[s]);
			this_index = random8();
			leds[shelf[s][pos]] += ColorFromPalette(current_palette, this_index);
		}
	}
}

#endif
