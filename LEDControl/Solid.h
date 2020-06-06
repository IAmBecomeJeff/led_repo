#pragma once
#include "Animator.h"
class Solid :
	public Animator
{
private:
	CRGB _color;
public:
	Solid(uint8_t num_leds, CRGB color);
	void Update(int tick, unsigned long deltaT);
};

