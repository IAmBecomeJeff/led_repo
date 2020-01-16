#ifndef TWO_SIN_H
#define TWO_SIN_H


bool hue_change;

void two_sin() {
	if (mode_change) {
		mode_change = 0;
		this_delay = 10;
		use_palette = 0;
		this_speed = random8(5);
		that_speed = random8(1, 5);
		this_rot = random8(10);
		that_rot = random8(3);
		this_cutoff = random8();
		that_cutoff = random8(128, 240);
		all_freq = random8(1, 9);
		this_hue = random8();
		that_hue = random8();
	}
	if (this_dir == 0) { this_phase += this_speed; that_phase += that_speed; }
	else { this_phase -= this_speed; that_phase -= that_speed; }

	this_hue += this_rot;                                                // Hue rotation is fun for this_wave.
	that_hue += that_rot;                                                // It's also fun for that_wave.

	for (int k = 0; k < NUM_LEDS - 1; k++) {
		int this_bright = qsuba(cubicwave8((k * all_freq) + this_phase), this_cutoff);     // qsub sets a minimum value called this_cutoff. If < this_cutoff, then bright = 0. Otherwise, bright = 128 (as defined in qsub)..
		int that_bright = qsuba(cubicwave8((k * all_freq) + 128 + that_phase), that_cutoff); // This wave is 180 degrees out of phase (with the value of 128).

		leds[k] = CHSV(this_hue, this_sat, this_bright);                              // Assigning hues and brightness to the led array.
		leds[k] += CHSV(that_hue, this_sat, that_bright);

	}
}

#endif
