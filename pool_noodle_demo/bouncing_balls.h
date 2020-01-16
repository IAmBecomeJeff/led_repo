#ifndef BOUNCING_BALLS_H
#define BOUNCING_BALLS_H



void bouncing_balls() {
	for (uint8_t i = 0; i < NUM_BALLS; i++) {
		fadeToBlackBy(leds, NUM_LEDS, this_fade);
		tCycle[i] = millis() - tLast[i];    
		h[i] = 0.5 * GRAVITY * pow(tCycle[i] / 1000, 2.0) + vImpact[i] * tCycle[i] / 1000;

		if (h[i] < 0) {
			h[i] = 0;                            // If the ball crossed the threshold of the "ground," put it back on the ground
			vImpact[i] = COR[i] * vImpact[i];   // and recalculate its new upward velocity as it's old velocity * COR
			tLast[i] = millis();

			if (vImpact[i] < 0.01) { vImpact[i] = vImpact0; }  // If the ball is barely moving, "pop" it back up at vImpact0
		}
		pos[i] = round(h[i] * (NUM_LEDS - 1) / h0);       // Map "h" to a "pos" integer index position on the LED strip

		leds[pos[i]] = CHSV((i * 40), 255, 255);
	}
}


void bouncing_balls2() {
		for (uint8_t i = 0; i < NUM_BALLS; i++) {
			fadeToBlackBy(leds, NUM_LEDS, this_fade);
			tCycle[i] = millis() - tLast[i]; 
			h[i] = 0.5 * GRAVITY * pow(tCycle[i] / 1000, 2.0) + vImpact[i] * tCycle[i] / 1000;

			if (h[i] < 0) {
				h[i] = 0;                            // If the ball crossed the threshold of the "ground," put it back on the ground
				vImpact[i] = COR[i] * vImpact[i];   // and recalculate its new upward velocity as it's old velocity * COR
				tLast[i] = millis();

				if (vImpact[i] < 0.01) { vImpact[i] = vImpact0; }  // If the ball is barely moving, "pop" it back up at vImpact0
			}
			pos[i] = round(h[i] * (NUM_LEDS - 1) / h0);  
			leds[pos[i]] = ColorFromPalette(current_palette, ball_hue + i * NUM_LEDS / NUM_BALLS, 255, current_blending);
			ball_hue++;
		}
}


#endif
