#pragma once
#include "Animator.h"
class RainbowMarch :
	public Animator
{
private:
	uint8_t _rainbow_diff;
	uint8_t _rainbow_rot;
	uint8_t _juggle_beat;
	uint8_t _rainbow_index;
public:
	RainbowMarch(uint8_t num_leds, uint8_t rd, uint8_t rr, uint8_t jb);
	void Update(int tick, unsigned long deltaT);
};

