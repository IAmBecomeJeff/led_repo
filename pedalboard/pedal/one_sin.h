#ifndef ONE_SIN_H
#define ONE_SIN_H


/*
 * Usage - one_sin_pal();
 * 
 * all_freq - What is the frequency
 * bg_bri - The background brightness
 * bg_clr - The background colour
 * start_index  - What foreground colour are we starting with?
 * this_bright - How bright is it?
 * this_cutoff - If the brightness is lower than this_, then brightness=0
 * this_inc - incrementer to change the starting colour after each pass
 * this_index - rotating colours down the strip counter
 * this_phase - the counter used in conjunction with the frequency to move down the strip
 * this_rot - How quickly to rotate those colours down the strip
 * this_speed  - How fast does it whip down the strand
 */


void one_sin_pal() { 
	start_index += this_inc;
	this_index = start_index;
	this_phase -= this_speed;                                                                     // You can change direction and speed individually.
	for (int k = 0; k<MAX_LEDS; k++) {                                                            // For each of the LED's in the strand, set a brightness based on a wave as follows:
		int this_bright = qsubd(cubicwave8((k*all_freq) + this_phase), this_cutoff);          // qsub sets a minimum value called this_cutoff. If < this_cutoff, then bright = 0. Otherwise, bright = 128 (as defined in qsub)..
		leds[k] = CHSV(bg_clr, 255, bg_bri);                                                        // First set a background colour, but fully saturated.
		leds[k] += ColorFromPalette(currentPalette, this_index + k * this_inc, this_bright, currentBlending);
		this_index += this_rot;
	}
}

void one_sin_center_pal() { 
	start_index += this_inc;
	this_index = start_index;
	this_phase -= this_speed;                                                                     // You can change direction and speed individually.
	for (int k = 0; k<STRAND_LENGTH; k++) {                                                            // For each of the LED's in the strand, set a brightness based on a wave as follows:
		int this_bright = qsubd(cubicwave8((k*all_freq) + this_phase), this_cutoff);          // qsub sets a minimum value called this_cutoff. If < this_cutoff, then bright = 0. Otherwise, bright = 128 (as defined in qsub)..
		leds[rightFromCenter[k]] = CHSV(bg_clr, 255, bg_bri);                                                        // First set a background colour, but fully saturated.
		leds[rightFromCenter[k]] += ColorFromPalette(currentPalette, this_index + k * this_inc, this_bright, currentBlending);
		leds[leftFromCenter[k]] = CHSV(bg_clr, 255, bg_bri);                                                        // First set a background colour, but fully saturated.
		leds[leftFromCenter[k]] += ColorFromPalette(currentPalette, this_index + k * this_inc, this_bright, currentBlending);
		this_index += this_rot;
	}
}


void matrix_ray(uint8_t colorIndex) {                                                 // Send a PWM'd sinewave instead of a random happening of LED's down the strand.

  //static uint8_t thisdir = 0;                                                         // We could change the direction if we want to. Static means to assign that value only once.
  //static int thisphase = 0;                                                           // Phase change value gets calculated. Static means to assign that value only once.
  //uint8_t thiscutoff;                                                                 // You can change the cutoff value to display this wave. Lower value = longer wave.

  this_phase += beatsin8(1,20, 50);                                                    // You can change direction and speed individually.
  this_cutoff = beatsin8(50,164,248);                                                  // This variable is used for the PWM of the lighting with the qsubd command below.
  
  this_bright = qsubd(cubicwave8(this_phase), this_cutoff);                          // It's PWM time. qsubd sets a minimum value called thiscutoff. If < thiscutoff, then thisbright = 0. Otherwise, thisbright = thiscutoff.
 
  if (this_dir == 0) {                                                                 // Depending on the direction, we'll put that brightness in one end of the array. Andrew Tuline wrote this.
    leds[0] = ColorFromPalette(currentPalette, colorIndex, this_bright, currentBlending); 
    memmove(leds+1, leds, (MAX_LEDS-1)*3);                                            // Oh look, the FastLED method of copying LED values up/down the strand.
  } else {
    leds[MAX_LEDS-1] = ColorFromPalette( currentPalette, colorIndex, this_bright, currentBlending);
    memmove(leds, leds+1, (MAX_LEDS-1)*3);    
  }

} // matrix_ray()


#endif
