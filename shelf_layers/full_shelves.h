#ifndef FULL_SHELVES_H
#define FULL_SHELVES_H


uint8_t current_shelf = 0;
uint16_t stay_on_shelf;
uint16_t stay_on_shelf_time;
bool change_index;

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
		this_bright = (255 * 2) * (1 - stay_on_shelf / stay_on_shelf_time);
	}

	for (uint8_t i = shelf[current_shelf][0]; i < shelf[current_shelf][0] + shelf_num_leds[current_shelf]; i++) {
		leds[i] = ColorFromPalette(current_palette, this_index, this_bright);
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




#endif
