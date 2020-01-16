#ifndef RIPPLE_H
#define RIPPLE_H

void ripple() {
	if (mode_change) {
		mode_change = 0;
		use_palette = 1;
		this_fade = random8(16, 96);
		rip_fade = random8(200, 255);
	}
	fadeToBlackBy(leds, NUM_LEDS, this_fade);                             // 8 bit, 1 = slow, 255 = fast

	switch (rip_step) {

	case -10:
		rip_pause++;
		if (rip_pause == 0) { rip_step = -1; rip_pause = random8(20) - 20; }
		break;

	case -1:                                                          // Initialize ripple variables.
		rip_center = random(NUM_LEDS);
		rip_color = random8();
		rip_step = 0;
		break;

	case 0:
		leds[rip_center] = ColorFromPalette(current_palette, rip_color, rip_fade, current_blending);
		rip_step++;
		break;

	case rip_maxSteps:                                                    // At the end of the ripples.
		rip_step = -10;
		break;

	default:                                                         
		leds[(rip_center + rip_step + NUM_LEDS) % NUM_LEDS] = ColorFromPalette(current_palette, rip_color, rip_fade / rip_step * 2, current_blending);       // Simple wrap from Marc Miller
		leds[(rip_center - rip_step + NUM_LEDS) % NUM_LEDS] = ColorFromPalette(current_palette, rip_color, rip_fade / rip_step * 2, current_blending);
		rip_step++;                                                         // Next step.
		break;
	} // switch step
}

#endif
