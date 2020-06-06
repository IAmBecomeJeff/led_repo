#include "RainbowMarch.h"

RainbowMarch::RainbowMarch(uint8_t num_leds, uint8_t rd, uint8_t rr, uint8_t jb) : Animator(num_leds)
{
	if (rd == 1) {
		rr = 1;
	}

	_rainbow_diff = rd;
	_rainbow_rot = rr;
	_juggle_beat = jb;
}

void RainbowMarch::Update(int tick, unsigned long deltaT)
{
	Animator::Update(tick, deltaT);

	_rainbow_index += _rainbow_rot;

	fill_rainbow(_leds, _num_leds, _rainbow_index, _rainbow_diff);
}
