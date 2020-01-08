#ifndef CONFETTI_H
#define CONFETTI_H

void confetti()
{
	if (mode_change) {
		mode_change = 0;
		use_palette = 1;
		this_fade = random8(10, 48);
		this_delay = 20;
	}
	// random colored speckles that blink in and fade smoothly
	fadeToBlackBy(leds, NUM_LEDS, this_fade);
	int pos = random16(NUM_LEDS);
	this_index = random8();
	leds[pos] += ColorFromPalette(current_palette, this_index);
}

#endif
