#ifndef RIPPLES_H
#define RIPPLES_H

void rippling() {

	for (int i = 0; i < MAX_RIPPLES; i += 2) {                                       
		if (random8() > 224 && !ripples[i].exist) {                                   
			ripples[i].Init(192, 10);                                                   
			ripples[i + 1] = ripples[i];                                                
			ripples[i + 1].velocity *= -1;                                              
		}
	}

	for (int i = 0; i < MAX_RIPPLES; i++) {                                          
		if (ripples[i].exist) {
			leds[ripples[i].pos] = ColorFromPalette(current_palette, ripples[i].color, ripples[i].brightness, LINEARBLEND);
			ripples[i].Move();
		}
	}

	fadeToBlackBy(leds, NUM_LEDS, 160);

} 



#endif
