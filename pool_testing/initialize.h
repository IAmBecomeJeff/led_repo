#ifndef INITIALIZE_H
#define INITIALIZE_H

void initialize() {
	// Initialize curr_leds
	curr_leds.array_type = CURRENT;
	curr_leds.current_palette = Colorfull_gp;
	curr_leds.target_palette = Magenta_Evening_gp;
	curr_leds.mode_name = JUGGLE;

	// Initialize next_leds
	next_leds.array_type = NEXT;

}

#endif