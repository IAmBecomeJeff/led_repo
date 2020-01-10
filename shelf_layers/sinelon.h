#ifndef SINELON_H
#define SINELON_H

bool sinelon_color_change = 0;
uint8_t prev_pos = 0;

void sinelon(){
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
	if (!use_all_shelves) {
		int pos = beatsin16(this_beat, 0, NUM_LEDS - 1);
		if (sinelon_color_change) {
			if (pos > prev_pos) {
				for (uint8_t j = prev_pos; j < pos + 1; j++) {
					leds[j] += ColorFromPalette(current_palette, this_index++);
				}
			}
			else if (prev_pos > pos) {
				for (uint8_t j = pos; j < prev_pos + 1; j++) {
					leds[j] = ColorFromPalette(current_palette, this_index++);
				}
			}
			else {
				leds[pos] += ColorFromPalette(current_palette, this_index++);
			}
		}
		else {
			if (pos > prev_pos) {
				for (uint8_t j = prev_pos; j < pos + 1; j++) {
					leds[j] += ColorFromPalette(current_palette, this_index);
				}
			}
			else if (prev_pos > pos) {
				for (uint8_t j = pos; j < prev_pos + 1; j++) {
					leds[j] = ColorFromPalette(current_palette, this_index);
				}
			}
			else {
				leds[pos] += ColorFromPalette(current_palette, this_index);
			}
		}
		prev_pos = pos;
	}
	else {
		int pos = beatsin16(this_beat, 0, shelf_num_leds[0] - 1);
		if (sinelon_color_change) {
			if (pos > prev_pos) {
				for (uint8_t j = prev_pos; j < pos + 1; j++) {
					leds[shelf[0][j]] += ColorFromPalette(current_palette, this_index++);
				}
			}
			else if (prev_pos > pos) {
				for (uint8_t j = pos; j < prev_pos + 1; j++) {
					leds[shelf[0][j]] += ColorFromPalette(current_palette, this_index++);
				}
			}
			else {
				leds[shelf[0][pos]] += ColorFromPalette(current_palette, this_index++);
			}
		}
		else {
			if (pos > prev_pos) {
				for (uint8_t j = prev_pos; j < pos + 1; j++) {
					leds[shelf[0][j]] += ColorFromPalette(current_palette, this_index);
				}
			}
			else if (prev_pos > pos) {
				for (uint8_t j = pos; j < prev_pos + 1; j++) {
					leds[shelf[0][j]] += ColorFromPalette(current_palette, this_index);
				}
			}
			else {
				leds[shelf[0][pos]] += ColorFromPalette(current_palette, this_index);
			}
		}
		prev_pos = pos;
		shelf_copy();
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
	if (!use_all_shelves) {
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
		int pos  = beatsin16(this_beat, 0, shelf_num_leds[0] - 1);
		int pos2 = beatsin16(that_beat, 0, shelf_num_leds[0] - 1);
		if (sinelon_color_change) {
			leds[shelf[0][(pos+pos2)/2]] += ColorFromPalette(current_palette, this_index++);
		}
		else {
			leds[shelf[0][(pos+pos2)/2]] += ColorFromPalette(current_palette, this_index);
		}
		shelf_copy();
	}
}



#define bounce_max 20
CRGB bounce_pos[bounce_max];
uint8_t bounce_length;
uint8_t bounce_start;
bool bounce_dir;
//uint8_t bounce_start_pos;
uint8_t bounce_start_beat;

void sinelon_bouncing() {
	if (mode_change) {
		mode_change = 0;
		this_delay = 10;
		use_palette = 1;
		this_beat = 80;// random8(4, 10);
		bounce_length = 16;// random8(10, bounce_max);
		bounce_start = 0;
		current_shelf = 0;
		this_diff = random8(1, 9);
		this_index = random8();
		this_fade = 100;// random8(128, 220);
		bounce_dir = 1;
		bounce_start_beat = random8(6, 16);
		Serial.println("sinelon_bouncing");
		use_all_shelves = random8(2);
	}

	fill_rainbow(&(leds[shelf[current_shelf][0]]), shelf_num_leds[current_shelf], this_index++, this_diff);

	fadeToBlackBy(bounce_pos, bounce_max, this_fade);
	int pos = beatsin16(this_beat, 0, bounce_length);
	bounce_pos[pos] += ColorFromPalette(current_palette, this_index);

	for (uint8_t i = 0; i < bounce_length; i++) {
		leds[shelf[current_shelf][bounce_start + i]] = CRGB::Black;
		nblend(leds[shelf[current_shelf][bounce_start + i]], bounce_pos[i], 255);
	}

	EVERY_N_MILLIS(25) {
		bounce_start = beatsin16(bounce_start_beat, 0, shelf_num_leds[0] - bounce_length - 1);
	}

	if (use_all_shelves) {
		shelf_copy();
	}
	
}



#endif
