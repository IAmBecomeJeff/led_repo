#ifndef SINELON_H
#define SINELON_H

bool sinelon_color_change = 0;
void sinelon()
{
	if (mode_change) {
		mode_change = 0;
		use_palette = 1;
		this_fade = random8(16, 128);
		this_beat = random8(4, 18);
		sinelon_color_change = random8(2);
		this_delay = 10;
		use_all_shelves = random8(2);
	  Serial.println("sinelon");
	}
	fadeToBlackBy(leds, NUM_LEDS, this_fade);
	if (use_all_shelves) {
		int pos = beatsin16(this_beat, 0, NUM_LEDS - 1);
		if (sinelon_color_change) {
			leds[pos] += ColorFromPalette(current_palette, this_index++);
		}
		else {
			leds[pos] += ColorFromPalette(current_palette, this_index);
		}
	}
	else {
		for (uint8_t s = 0; s < 4; s++) {
			int pos = beatsin16(this_beat, 0, shelf_num_leds[s] - 1);
			if (sinelon_color_change) {
				leds[shelf[s][pos]] += ColorFromPalette(current_palette, this_index++);
			}
			else {
				leds[shelf[s][pos]] += ColorFromPalette(current_palette, this_index);
			}
		}
	}
}

void sinelon_squiggle(){
	if (mode_change) {
		mode_change = 0;
		use_palette = 1;
		this_fade = random8(16, 128);
		this_beat = random8(4, 18);
		sinelon_color_change = random8(2);
		this_delay = 10;
		that_beat = random8(3, 10);
		use_all_shelves = random8(2);
   Serial.println("sinelon_squiggle");
	}
	// a colored dot sweeping back and forth, with fading trails
	fadeToBlackBy(leds, NUM_LEDS, this_fade);
	if (use_all_shelves) {
		int pos = beatsin16(this_beat, 0, NUM_LEDS - 1);
		int pos2 = beatsin16(that_beat, 0, NUM_LEDS - 1);
		if (sinelon_color_change) {
			leds[(pos+pos2)/2] += ColorFromPalette(current_palette, this_index++);
		}
		else {
			leds[(pos+pos2)/2] += ColorFromPalette(current_palette, this_index);
		}
	}
	else {
		for (uint8_t s = 0; s < 4; s++) {
			int pos = beatsin16(this_beat, 0, shelf_num_leds[s] - 1);
			int pos2 = beatsin16(that_beat, 0, shelf_num_leds[s] - 1);
			if (sinelon_color_change) {
				leds[shelf[s][(pos+pos2)/2]] += ColorFromPalette(current_palette, this_index++);
			}
			else {
				leds[shelf[s][(pos+pos2)/2]] += ColorFromPalette(current_palette, this_index);
			}
		}
	}
}


#endif
