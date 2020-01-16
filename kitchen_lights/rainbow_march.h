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
		this_diff = random8(1, 5);
		this_delay = 10;
	}
	if (this_dir == 0) this_index += this_rot; else this_index -= this_rot;  // I could use signed math, but 'this_dir' works with other routines.
	fill_rainbow(leds, NUM_LEDS, this_index, this_diff);               // I don't change deltahue on the fly as it's too fast near the end of the strip.
}

void rainbow_split(){
  if (mode_change){
    mode_change = 0;
    use_palette = 0;
    this_dir = random8(2);
    this_rot = random8(1,5);
    this_diff = random8(1,5);
    this_delay = 15;
  }
  if (this_dir == 0) this_index += this_rot; else this_index -= this_rot;
  fill_rainbow(leds, NUM_LEDS/2, this_index, this_diff); // 0 - 71
  for (int i = 0; i < NUM_LEDS/2; i++){
    leds[NUM_LEDS - 1 - i] = leds[i];
  }
    
}


#endif
