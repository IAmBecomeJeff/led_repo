#ifndef JUGGLE_H
#define JUGGLE_H

/* This is adapted from a routine created by Mark Kriegsman */

/*  Usage - juggle_pal();
 *  
 *  this_hue
 *  this_fade
 *  numdots
 *  this_beat
 *  this_bright
 *  this_diff
 */
// use beatsin16_halfup and beatsin16_halfdown to make it go one way

bool reset_juggle_index = 0;

void juggle_pal() {
	if (mode_change) {
		mode_change = 0;
		numdots = random8(2, 6);
		use_palette = 1;
		reset_juggle_index = random8(2);
		this_fade = random8(16, 64);
		this_beat = random8(4, 20);
		this_diff = random8(0, 255/numdots);
		this_delay = 10;
		use_all_shelves = random8(2);
		Serial.println("juggle_pal");
	}
	if (reset_juggle_index) {
		this_index = 0;
	}
	fadeToBlackBy(leds, NUM_LEDS, this_fade);

	if (!use_all_shelves) {
		for (int i = 0; i < numdots; i++) {
			leds[beatsin16(this_beat + i + numdots, 0, NUM_LEDS)] += ColorFromPalette(current_palette, this_index, 255, current_blending);
			this_index += this_diff;
		}
	}else {
		for (uint8_t s = 0; s < 4; s++) {
			for (uint8_t i = 0; i < numdots; i++) {
				leds[shelf[s][beatsin16(this_beat + i + numdots, 0, shelf_num_leds[s])]] += ColorFromPalette(current_palette, this_index, 255, current_blending);
				this_index += this_diff;
			}
		}
	}

} // juggle_pal()



void juggle_pal_onedir() {
	if (mode_change) {
		mode_change = 0;
		numdots = random8(2, 6);
		use_palette = 1;
		reset_juggle_index = random8(1);
		this_fade = random8(16, 64);
		this_beat = random8(4, 20);
		this_diff = random8(0, 255 / numdots);
		this_dir = random8(2);
		this_delay =10; 
		use_all_shelves = random8(2);
		Serial.println("juggle_pal_ondeir");
	}

	if (reset_juggle_index) {
		this_index = 0;
	}

	fadeToBlackBy(leds, NUM_LEDS, this_fade);

	if (!use_all_shelves) {
		for (int i = 0; i < numdots; i++) {
			if (!this_dir) {
				leds[beatsin16_halfdown(this_beat + 2 * i + numdots, 0, NUM_LEDS - 1)] += ColorFromPalette(current_palette, this_index, this_bright, current_blending);
			}
			else {
				leds[beatsin16_halfup(this_beat + 2 * i + numdots, 0, NUM_LEDS - 1)] += ColorFromPalette(current_palette, this_index, this_bright, current_blending);
			}
			this_index += this_diff;
		}
	}else {
		for (uint8_t s = 0; s < 4; s++) {
			for (int i = 0; i < numdots; i++) {
				if (!this_dir) {
					leds[shelf[s][beatsin16_halfdown(this_beat + 2 * i + numdots, 0, shelf_num_leds[s] - 1)]] += ColorFromPalette(current_palette, this_index, this_bright, current_blending);
				}
				else {
					leds[shelf[s][beatsin16_halfup(this_beat + 2 * i + numdots, 0, shelf_num_leds[s] - 1)]] += ColorFromPalette(current_palette, this_index, this_bright, current_blending);
				}
				this_index += this_diff;
			}
		}
	}
} // 


#endif
