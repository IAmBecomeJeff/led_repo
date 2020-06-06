#ifndef BOUNCING_BALLS_H
#define BOUNCING_BALLS_H


void bouncing_balls_init(LEDStruct& leds, bool up = random8(2), uint8_t bf = random8(1,30), uint8_t nob = random8(2, MAX_NUMBER_OF_BALLS + 1)) {
	leds.mode_initialized	= 1;
	leds.use_palette		= up;
	leds.mode_type			= BOUNCING_BALLS;
	leds.delay_time			= 15;

	leds.bouncing_fade		= bf;
	leds.number_of_balls	= nob;

	for (int i = 0; i < leds.number_of_balls; i++) {    // Initialize variables
		leds.bouncing_tLast[i]		= millis();
		leds.bouncing_heights[i]	= h0;
		leds.bouncing_pos[i]		= 0;                              // Balls start on the ground
		leds.bouncing_vImpact[i]	= bouncing_vImpact0;                   // And "pop" up at vImpact0
		leds.bouncing_tCycle[i]		= 0;
		leds.bouncing_COR[i]		= 0.90 - float(i) / pow(leds.number_of_balls, 2);
	}
}

void bouncing_balls_update(LEDStruct& leds) {
	keyboard_update = 0;
	switch (update_var) {
	case 0:		leds.bouncing_fade	 = (uint8_t)update_arg;	break;	//a
	case 1:		if (update_arg > MAX_NUMBER_OF_BALLS) { update_arg = MAX_NUMBER_OF_BALLS; } leds.number_of_balls = (uint8_t)update_arg;	break;	//b		
	case 2:		leds.use_palette	 = (bool)update_arg; break; //c
	default:	break;
	}
	LEDDebug(leds);
}

void bouncing_balls(LEDStruct& leds) {
	if (!leds.mode_initialized) { bouncing_balls_init(leds); }
	if (keyboard_update) { bouncing_balls_update(leds); }

	for (uint8_t i = 0; i < leds.number_of_balls; i++) {
		fadeToBlackBy(leds.led_data, NUM_LEDS, leds.bouncing_fade);
		leds.bouncing_tCycle[i] = millis() - leds.bouncing_tLast[i];
		leds.bouncing_heights[i] = 0.5 * GRAVITY * pow(leds.bouncing_tCycle[i] / 1000, 2.0) + leds.bouncing_vImpact[i] * leds.bouncing_tCycle[i] / 1000;

		if (leds.bouncing_heights[i] < 0) {
			leds.bouncing_heights[i] = 0;                            
			leds.bouncing_vImpact[i] = leds.bouncing_COR[i] * leds.bouncing_vImpact[i];   
			leds.bouncing_tLast[i] = millis();

			if (leds.bouncing_vImpact[i] < 0.01) { leds.bouncing_vImpact[i] = bouncing_vImpact0; }  
		}
		leds.bouncing_pos[i] = round(leds.bouncing_heights[i] * (NUM_LEDS - 1) / h0);       

		if (leds.use_palette) {
			leds.led_data[leds.bouncing_pos[i]] = ColorFromPalette(leds.current_palette, leds.bouncing_index + i * NUM_LEDS / leds.number_of_balls, 255, leds.current_blending);
			leds.bouncing_index++;
		}
		else {
			leds.led_data[leds.bouncing_pos[i]] = CHSV((i * 40), 255, 255);
		}
	}
}


#endif
