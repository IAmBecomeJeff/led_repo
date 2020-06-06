#include "Solid.h"

Solid::Solid(uint8_t num_leds, CRGB color) : Animator(num_leds)
{
	_color = color;
}

void Solid::Update(int tick, unsigned long deltaT)
{
	Animator::Update(tick, deltaT);

	for (int i = 0; i < _num_leds; i++) {
		_leds[i] = _color;
	}
}
