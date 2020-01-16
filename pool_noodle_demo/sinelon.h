#ifndef SINELON_H
#define SINELON_H

bool sinelon_color_change = 0;
void sinelon()
{
	if (mode_change) {
		mode_change = 0;
		use_palette = 1;
		this_fade = random8(16, 128);
		this_beat = random8(8, 18);
		sinelon_color_change = random8(1);
    this_delay = 10;
	}
	// a colored dot sweeping back and forth, with fading trails
	fadeToBlackBy(leds, NUM_LEDS, this_fade);
	int pos = beatsin16(this_beat, 0, NUM_LEDS - 1);
	if (sinelon_color_change) {
		leds[pos] += ColorFromPalette(current_palette, this_index++);
	}
	else {
		leds[pos] += ColorFromPalette(current_palette, this_index);
	}
	//leds[pos] += CHSV(this_hue++, 255, 192);
}

#endif
