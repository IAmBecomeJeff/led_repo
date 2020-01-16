#ifndef ONE_SIN_H
#define ONE_SIN_H


void one_sin_pal() {
	start_index += this_inc;
	this_index = start_index;
	if (this_dir) {
		this_phase += this_speed;                                                                   
	}
	else {
		this_phase -= this_speed;                                                                     
	}
	for (int k = 0; k < NUM_LEDS; k++) {                                                           
		int this_bright = qsubd(cubicwave8((k * all_freq) + this_phase), this_cutoff);                    
		leds[k] = CHSV(bg_clr, 255, bg_bri);                                                        
		leds[k] += ColorFromPalette(current_palette, this_index + k * this_inc, this_bright, current_blending);
		this_index += this_rot;
	}
}


#endif
