#ifndef RAINBOW_MARCH_H
#define RAINBOW_MARCH_H

/* Usage - rainbow_march();
 *  
 * this_index
 * this_diff
 * this_rot
 * this_dir
 */


void rainbow_march() {
	if (mode_change) {
		mode_change = 0;
		use_palette = 0;
		this_dir = random8(2);
		this_rot = random8(1, 5);
		this_diff = random8(1, 9);
		this_delay = 10;
		use_all_shelves = random8(2);
		Serial.println("rainbow_march");
	}
	if (this_dir == 0) this_index += this_rot; else this_index -= this_rot;
	if (!use_all_shelves) {
		fill_rainbow(leds, NUM_LEDS, this_index, this_diff);
	}
	else {
		for (uint8_t s = 0; s < 4; s++) {
			fill_rainbow(&(leds[shelf[s][0]]), shelf_num_leds[s], this_index, this_diff);
		}
	}
}

void rainbow_split(){
  if (mode_change){
    mode_change = 0;
    use_palette = 0;
    this_dir = random8(2);
    this_rot = random8(1,5);
    this_diff = random8(1,9);
    this_delay = 15;
    use_all_shelves = random8(2);
    Serial.println("rainbow_split");
  }
  if (this_dir == 0) this_index += this_rot; else this_index -= this_rot;
  if (!use_all_shelves) {
	  fill_rainbow(leds, NUM_LEDS / 2, this_index, this_diff); // 0 - 71
	  for (int i = 0; i < NUM_LEDS / 2; i++) {
		  leds[NUM_LEDS - 1 - i] = leds[i];
	  }
  }
  else {
	  for (uint8_t s = 0; s < 4; s++) {
		  fill_rainbow(&(leds[shelf[s][0]]), shelf_num_leds[s] / 2, this_index, this_diff); // 0 - 71
		  for (int i = 0; i < shelf_num_leds[s] / 2; i++) {
			  leds[shelf[s][shelf_num_leds[s] - 1 - i]] = leds[shelf[s][i]];
		  }
	  }
  }
    
}


#endif
