#ifndef CONFETTI_H
#define CONFETTI_H

void confetti()
{
	if (mode_change) {
		mode_change = 0;
		use_palette = 1;
		this_fade = random8(10, 48);
		this_delay = 20;
		use_all_shelves = 1;//random8(2);
		Serial.println("confetti");
	}
	// random colored speckles that blink in and fade smoothly
	fadeToBlackBy(leds, NUM_LEDS, this_fade);
	if (!use_all_shelves) {
		int pos = random16(NUM_LEDS);
		this_index = random8();
		leds[pos] += ColorFromPalette(current_palette, this_index);
	}
	else {
		uint8_t pos = random8();
		this_index = random8();
		for (uint8_t s = 0; s < 4; s++)	{
			uint8_t scale_pos = scale8(pos, shelf_num_leds[s]);
			leds[shelf[s][scale_pos]] += ColorFromPalette(current_palette, this_index);
		}
	}
}

#endif
