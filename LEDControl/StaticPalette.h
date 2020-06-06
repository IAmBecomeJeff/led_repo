#pragma once
#include "Animator.h"
class StaticPalette :
	public Animator
{
public:
	StaticPalette(uint8_t num_leds);
	void Update(int tick, unsigned long deltaT);
};

