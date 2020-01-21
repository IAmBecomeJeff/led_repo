#ifndef ONE_SIN_H
#define ONE_SIN_H


void one_sin() {
	if (mode_change) {
    Serial.println("ONE_SIN");
		mode_change = 0;
		this_delay = 10;
		this_inc = random8(1, 10);
		this_speed = random8(1, 5);
		this_cutoff = random8(128, 240);
		this_rot = random8(1, 5);
		all_freq = random8(1, 9);
		bg_clr = random8();
		bg_bri = random8(10);
		if (bg_bri > 8) {
			bg_bri = 200;
		}
		else {
			bg_bri = 0;
		}
		use_palette = 1;
	}
	start_index += this_inc;
	this_index = start_index;
	if (this_dir) {
		this_phase += this_speed;                                                                   
	}
	else {
		this_phase -= this_speed;                                                                     
	}
	for (int k = 0; k < NUM_LEDS; k++) {                                                           
		int sin_bright = qsubd(cubicwave8((k * all_freq) + this_phase), this_cutoff);                    
		leds[k] = CHSV(bg_clr, 255, bg_bri);                                                        
		leds[k] += ColorFromPalette(current_palette, this_index + k * this_inc, sin_bright, current_blending);
		this_index += this_rot;
	}
}


#endif
