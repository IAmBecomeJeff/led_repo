#ifndef FIRE_H
#define FIRE_H



void fire() {
	if (mode_change) {
		mode_change = 0;
		sparking = random8(60, 90);
		cooling = random8(80, 120);
		use_palette = 0;
		this_delay = 15;
		use_all_shelves = 1;//random8(2);
		Serial.println("fire");
	}
		// Array of temperature readings at each simulation cell
		static byte heat[NUM_LEDS];

		// Step 1.  Cool down every cell a little
		for (int i = 0; i < NUM_LEDS; i++) {
			heat[i] = qsub8(heat[i], random8(0, ((cooling * 10) / NUM_LEDS) + 2));
		}

		// Step 2.  Heat from each cell drifts 'up' and diffuses a little
		for (int k = NUM_LEDS - 3; k >= 2; k--) {
			heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
		}

		// Step 3.  Randomly ignite new 'sparks' of heat near the bottom
		if (random8() < sparking) {
			int y = random8(7);
			heat[y] = qadd8(heat[y], random8(160, 255));
		}

		// Step 4.  Map from heat cells to LED colors
		for (int j = 0; j < NUM_LEDS; j++) {
			if (!use_all_shelves) {
				leds[j] = HeatColor(heat[j]);
			}
			else {
				for (int s = 0; s < 4; s++) {
					uint8_t pos = j * (shelf_num_leds[s] / NUM_LEDS);
					leds[shelf[s][pos]] += HeatColor(heat[j]);
				}
			}
		}
}


// fire with a palette
void fire_pal() {
	if (mode_change) {
		mode_change = 0;
		sparking = random8(50, 110);
		cooling = random8(50, 120);
		use_palette = 1;
		this_delay = 15;
     Serial.println("fire_pal");
	}
	static byte heat[NUM_LEDS];

	for (int i = 0; i < NUM_LEDS; i++) {
		heat[i] = qsub8(heat[i], random8(0, ((cooling * 10) / NUM_LEDS) + 2));
	}

	for (int k = NUM_LEDS - 1; k >= 2; k--) {
		heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
	}

	if (random8() < sparking) {
		int y = random8(7);
		heat[y] = qadd8(heat[y], random8(160, 255));
	}

	for (int j = 0; j < NUM_LEDS; j++) {
		byte colorindex = scale8(heat[j], 240);
		leds[pixelnumber] = ColorFromPalette(current_palette, colorindex);
	}
}



// fire mirrored from ends or center
void fire_mirror() {
	if (mode_change) {
		mode_change = 0;
		sparking = random8(50, 110);
		cooling = random8(50, 120);
		use_palette = 0;
		this_dir = random8(2);
		this_delay = 15;
		use_all_shelves = 1;// random8(2);
		Serial.println("fire_mirror");
	}
		static byte heat[NUM_LEDS / 2];
		for (int i = 0; i < NUM_LEDS / 2; i++) {
			heat[i] = qsub8(heat[i], random8(0, ((cooling * 10) / (NUM_LEDS / 2)) + 2));
		}
		for (int k = (NUM_LEDS / 2) - 1; k >= 2; k--) {
			heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
		}
		if (random8() < sparking) {
			int y = random8(7);
			heat[y] = qadd8(heat[y], random8(160, 255));
		}
		if (this_dir) {
			for (int j = 0; j < NUM_LEDS / 2; j++) {
				if (!use_all_shelves) {
					leds[j] = HeatColor(heat[j]);
					leds[NUM_LEDS - 1 - j] = HeatColor(heat[j]);
				}
				else {
					for (uint8_t s = 0; s < 4; s++) {
						int pos = j * (shelf_num_leds[s] / (NUM_LEDS / 2));
						leds[shelf[s][pos]] += HeatColor(heat[j]);
						leds[shelf[s][shelf_num_leds[s] - 1 - pos]] += HeatColor(heat[j]);
					}
				}
			}
		}
		else {
			for (int j = 0; j < NUM_LEDS / 2; j++) {
				if (!use_all_shelves) {
					leds[(NUM_LEDS / 2) - 1 - j] = HeatColor(heat[j]);
					leds[(NUM_LEDS / 2) + j] = HeatColor(heat[j]);
				}
				else {
					for (uint8_t s = 0; s < 4; s++) {
						uint8_t pos = j * ((shelf_num_leds[s]/2) / (NUM_LEDS / 2));
						leds[shelf[s][(shelf_num_leds[s] / 2) - 1 - pos]] = HeatColor(heat[j]);
						leds[shelf[s][(shelf_num_leds[s] / 2) + pos]] = HeatColor(heat[j]);
					}
				}
			}
		}
}



// fire mirrored from ends or center using palette
void fire_mirror_pal() {
	if (mode_change) {
		mode_change = 0;
		sparking = random8(50, 110);
		cooling = random8(50, 120);
		use_palette = 1;
		this_dir = random8(2);
		this_delay = 15;
		use_all_shelves = random8(2);
		Serial.println("fire_mirror_pal");	
	}
	if (!use_all_shelves) {
		static byte heat[NUM_LEDS / 2];
		for (int i = 0; i < NUM_LEDS / 2; i++) {
			heat[i] = qsub8(heat[i], random8(0, ((cooling * 10) / (NUM_LEDS / 2)) + 2));
		}
		for (int k = (NUM_LEDS / 2) - 1; k >= 2; k--) {
			heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
		}
		if (random8() < sparking) {
			int y = random8(7);
			heat[y] = qadd8(heat[y], random8(160, 255));
		}
		for (int j = 0; j < NUM_LEDS / 2; j++) {
			byte colorindex = scale8(heat[j], 240);
			if (this_dir) {
				leds[j] = ColorFromPalette(current_palette, colorindex);
				leds[NUM_LEDS - 1 - j] = ColorFromPalette(current_palette, colorindex);
			}
			else {
				leds[(NUM_LEDS / 2) - 1 - j] = ColorFromPalette(current_palette, colorindex);
				leds[(NUM_LEDS / 2) + j] = ColorFromPalette(current_palette, colorindex);
			}
		}
	}
	else {
		for (uint8_t s = 0; s < 4; s++) {
			static byte heat[NUM_LEDS / 2];
			for (int i = 0; i < shelf_num_leds[s] / 2; i++) {
				heat[i] = qsub8(heat[i], random8(0, ((cooling * 10) / (shelf_num_leds[s] / 2)) + 2));
			}
			for (int k = (shelf_num_leds[s] / 2) - 1; k >= 2; k--) {
				heat[k] = (heat[k - 1] + heat[k - 2] + heat[k - 2]) / 3;
			}
			if (random8() < sparking) {
				int y = random8(7);
				heat[y] = qadd8(heat[y], random8(160, 255));
			}
			for (int j = 0; j < shelf_num_leds[s] / 2; j++) {
				byte colorindex = scale8(heat[j], 240);
				if (this_dir) {
					leds[shelf[s][j]] = ColorFromPalette(current_palette, colorindex);
					leds[shelf[s][shelf_num_leds[s] - 1 - j]] = ColorFromPalette(current_palette, colorindex);
				}
				else {
					leds[shelf[s][(shelf_num_leds[s] / 2) - 1 - j]] = ColorFromPalette(current_palette, colorindex);
					leds[shelf[s][(shelf_num_leds[s] / 2) + j]] = ColorFromPalette(current_palette, colorindex);
				}
			}
		}
	}
}




#endif
