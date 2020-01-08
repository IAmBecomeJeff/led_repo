#ifndef SINELON_H
#define SINELON_H

bool sinelon_color_change = 0;

void sinelon(){
	if (mode_change) {
		mode_change = 0;
		use_palette = 1;
		this_fade = random8(16, 128);
		this_beat = random8(4, 18);
		sinelon_color_change = random8(2);
		this_delay = 10;
		use_all_shelves = 1;//random8(2);
		Serial.println("sinelon");
	}
	fadeToBlackBy(leds, NUM_LEDS, this_fade);
	if (!use_all_shelves) {
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
		use_all_shelves = 1;//random8(2);
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
		for (uint8_t s = 0; s < 4; s++) {
			int pos  = beatsin16(this_beat, 0, shelf_num_leds[s] - 1);
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


void sinelon_timing() {
	if (mode_change) {
		mode_change = 0;
		use_palette = 1;
		this_fade = random8(16, 128);
		this_beat = random8(4, 18);
		sinelon_color_change = random8(2);
		this_delay = 10;
		use_all_shelves = 1;//random8(2);
		Serial.println("sinelon");
	}
	fadeToBlackBy(leds, NUM_LEDS, this_fade);
	if (!use_all_shelves) {
		int pos = beatsin16(this_beat, 0, NUM_LEDS - 1);
		if (sinelon_color_change) {
			leds[pos] += ColorFromPalette(current_palette, this_index++);
		}
		else {
			leds[pos] += ColorFromPalette(current_palette, this_index);
		}
	}
	else {
		int pos = beatsin16(this_beat, 0, 255);
		for (uint8_t s = 0; s < 4; s++) {
			int scaled_pos = scale8(pos, shelf_num_leds[s]);
			if (sinelon_color_change) {
				leds[shelf[s][scaled_pos]] += ColorFromPalette(current_palette, this_index++);
			}
			else {
				leds[shelf[s][scaled_pos]] += ColorFromPalette(current_palette, this_index);
			}
		}
	}
}


void sinelon_squiggle_timing() {
	if (mode_change) {
		mode_change = 0;
		use_palette = 1;
		this_fade = random8(16, 128);
		this_beat = random8(4, 18);
		sinelon_color_change = random8(2);
		this_delay = 10;
		that_beat = random8(3, 10);
		use_all_shelves = 1;//random8(2);
		Serial.println("sinelon_squiggle");
	}
	// a colored dot sweeping back and forth, with fading trails
	fadeToBlackBy(leds, NUM_LEDS, this_fade);
	if (!use_all_shelves) {
		int pos = beatsin16(this_beat, 0, NUM_LEDS - 1);
		int pos2 = beatsin16(that_beat, 0, NUM_LEDS - 1);
		if (sinelon_color_change) {
			leds[(pos + pos2) / 2] += ColorFromPalette(current_palette, this_index++);
		}
		else {
			leds[(pos + pos2) / 2] += ColorFromPalette(current_palette, this_index);
		}
	}
	else {
		int pos = beatsin8(this_beat);
		int pos2 = beatsin8(that_beat);
		int pos_avg = (pos + pos2) / 2;
		for (uint8_t s = 0; s < 4; s++) {
			int scaled_pos = scale8(pos_avg, shelf_num_leds[s]);
			if (sinelon_color_change) {
				leds[shelf[s][scaled_pos]] += ColorFromPalette(current_palette, this_index++);
			}
			else {
				leds[shelf[s][scaled_pos]] += ColorFromPalette(current_palette, this_index);
			}
		}
	}
}

#define bounce_max 20
CRGB bounce_pos[bounce_max];
uint8_t bounce_length;
uint8_t bounce_start;
bool bounce_dir;

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
		Serial.println("sinelon_bouncing");
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
		if (bounce_dir && bounce_start + bounce_length < shelf_num_leds[current_shelf]) {
			bounce_start++;
		}
		else if (!bounce_dir && bounce_start > 0) {
			bounce_start--;
		}
		else {
			bounce_dir = !bounce_dir;
		}
	}
	
}



#endif
