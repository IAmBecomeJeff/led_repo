#ifndef COMET_H
#define COMET_H

uint16_t start_index = 0;
uint16_t step = 0;

void comet(){
	fadeall();
	uint16_t index = start_index + step;
	leds[index] = ColorFromPalette(current_palette, index);
	step = (step + 1) % NUM_LEDS;

#endif