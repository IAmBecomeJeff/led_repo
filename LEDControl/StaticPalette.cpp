#include "StaticPalette.h"

StaticPalette::StaticPalette(uint8_t num_leds) : Animator(num_leds)
{
}

void StaticPalette::Update(int tick, unsigned long deltaT)
{
	Animator::Update(tick, deltaT);

	if (_hasPalette) {
		uint8_t step = 256 / _num_leds;
		fill_palette(_leds, (uint16_t)_num_leds, (uint8_t)0, step, _current_palette, 255,_blend_type);
	}
}
