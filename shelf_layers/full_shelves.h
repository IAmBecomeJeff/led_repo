#ifndef FULL_SHELVES_H
#define FULL_SHELVES_H




void full_shelves() {
	if (mode_change) {
		mode_change = 0;
		use_palette = 1;
		this_delay = 10;
		current_shelf = random8(4);
		stay_on_shelf = 0;
		stay_on_shelf_time = random16(50, 500);
		this_index = random8();
		change_index = random8(2);
    Serial.println("full_shelves");
	}

	fill_solid(leds, NUM_LEDS, CRGB::Black);

	for (uint8_t i = shelf[current_shelf][0]; i < shelf[current_shelf][0] + shelf_num_leds[current_shelf]; i++) {
		leds[i] = ColorFromPalette(current_palette, this_index);
	}

	if (change_index) {
		this_index += random8(4, 32);
	}

	if (stay_on_shelf++ == stay_on_shelf_time) {
		stay_on_shelf = 0;
		current_shelf = random8(4);
		this_index = random8();
	}
}


void full_shelves_fading() {
	if (mode_change) {
		mode_change = 0;
		use_palette = 1;
		this_delay = 10;
		current_shelf = random8(4);
		stay_on_shelf = 0;
		stay_on_shelf_time = random16(50, 500);
		this_index = random8();
		Serial.println("full_shelves_fading");
	}

	fill_solid(leds, NUM_LEDS, CRGB::Black);

	if (stay_on_shelf <= stay_on_shelf_time / 2) {
		this_bright = 255 * stay_on_shelf / (stay_on_shelf_time / 2);
	}
	else {
		this_bright = (255 * 2) * (1 - (float)stay_on_shelf / stay_on_shelf_time);
	}

	for (uint8_t i = 0; i < shelf_num_leds[current_shelf]; i++){
		leds[shelf[current_shelf][i]] = ColorFromPalette(current_palette, this_index, this_bright);
	}

	if (change_index) {
		this_index += random8(4, 32);
	}

	if (stay_on_shelf++ == stay_on_shelf_time) {
		stay_on_shelf = 0;
		current_shelf = random8(4);
		this_index = random8();
	}
}

void full_shelves_palette() {
	if (mode_change) {
		mode_change = 0;
		this_delay = 10;
		use_palette = 1;
		current_shelf = random8(4);
		stay_on_shelf = 0;
		stay_on_shelf_time = random16(50, 1000);
		Serial.println("full_shelves_palette");
	}
	fill_solid(leds, NUM_LEDS, CRGB::Black);

	if (stay_on_shelf <= stay_on_shelf_time / 2) {
		this_bright = 255 * stay_on_shelf / (stay_on_shelf_time / 2);
	}
	else {
		this_bright = (255 * 2) * (1 - (float)stay_on_shelf / stay_on_shelf_time);
	}

	for (uint8_t i = 0; i < shelf_num_leds[current_shelf]; i++) {
		leds[shelf[current_shelf][i]] = ColorFromPalette(current_palette, i * 255 / shelf_num_leds[current_shelf], this_bright);
	}

	if (stay_on_shelf++ == stay_on_shelf_time) {
		stay_on_shelf = 0;
		current_shelf = random8(4);
	}
}

void all_shelves() {
	if (mode_change) {
		mode_change = 0;
		this_delay = 10;
		use_palette = 0;
		this_index = random8();
		stay_on_shelf = 0;
		stay_on_shelf_time = random16(100, 1000);
		fade_in = random8(2);
		Serial.println("all_shelves");
	}

	if (fade_in) {
		if (stay_on_shelf <= stay_on_shelf_time / 2) {
			this_bright = 255 * stay_on_shelf / (stay_on_shelf_time / 2);
		}
		else {
			this_bright = (255 * 2) * (1 - (float)stay_on_shelf / stay_on_shelf_time);
		}
	}
	else { this_bright = 255; }

	for (int i = 0; i < NUM_LEDS; i++) {
		leds[i] = CHSV(this_index, 255, this_bright);
	}

	if (stay_on_shelf++ == stay_on_shelf_time) {
		stay_on_shelf = 0;
		this_index = random8();
	}
}


uint8_t PixelState[NUM_LEDS];
uint8_t chance_of_brighten;
uint8_t delta_bright;
uint8_t PixelBright[NUM_LEDS];
uint8_t PixelColorIndex[NUM_LEDS];
uint8_t full_count;
uint16_t hold_time;
uint16_t hold_counter;

void brighten_randomly() {
	if (mode_change) {
		mode_change = 0;
		this_delay = 10;
		use_palette = 1;
		for (uint8_t i = 0; i < NUM_LEDS; i++) {
			PixelState[i] = 0;
			PixelBright[i] = 0;
			PixelColorIndex[i] = random8();
		}
		chance_of_brighten = 1;// random8(2,20);
		delta_bright = random8(1, 3);
		full_count = 0;
		hold_counter = 0;
		hold_time = random16(10, 1000);
	}
	
	if (full_count < NUM_LEDS) {
		for (uint16_t i = 0; i < NUM_LEDS; i++) {
			if (PixelState[i] == 0) {						// 0 means dark, so maybe get brighter
				if (random8() < chance_of_brighten) {
					PixelState[i] = 1;
				}
			}
			else if (PixelState[i] == 1) {					// 1 means we're brightening
				if (PixelBright[i] >= 255 - delta_bright - 1) {
					PixelBright[i] = 255;
					PixelState[i] = 2;
					full_count++;
				}
				else {
					PixelBright[i] += delta_bright;
					leds[i] = ColorFromPalette(current_palette, PixelColorIndex[i], PixelBright[i]);
				}
			}
			else if (PixelState[i] == 2) {					// 2 means at full brightness
				leds[i] = ColorFromPalette(current_palette, PixelColorIndex[i], PixelBright[i]);
			}
		}
	}
	else {
		for (uint16_t i = 0; i < NUM_LEDS; i++) {
			leds[i] = ColorFromPalette(current_palette, PixelColorIndex[i], PixelBright[i]);
		}
		if (hold_counter++ == hold_time) {
			mode_change = 1;
		}
	}
	leds[0] = CRGB::Black;


}

#endif
