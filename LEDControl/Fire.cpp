#include "Fire.h"

Fire::Fire(uint8_t num_leds,uint8_t fs = random8(50, 110), uint8_t fc = random8(60, 120)) : Animator(num_leds)
{
	_fire_sparking = fs;
	_fire_cooling = fc;

	_heat = new byte[num_leds];
}

Fire::~Fire()
{
	delete _heat;
}

void Fire::Update(int tick, unsigned long deltaT)
{
	Animator::Update(tick, deltaT);

	// 1. Cool cells down a lil
	for (int i = 0; i < _num_leds; i++)
	{
		_heat[i] = qsub8(_heat[i], random8(0, ((_fire_cooling * 10) / _num_leds) + 2));
	}

	// 2. Heat from cells drifts up and diffuses a lil
	for(int i = _num_leds - 3; i >= 2; i--) 
	{
		_heat[i] = (_heat[i - 1] + _heat[i - 2] + _heat[i - 2]) / 3;
	}

	// 3. Randomly ignite new sparks
	if (random8() < _fire_sparking) {
		uint8_t y = random8(7);
		_heat[y] = qadd8(_heat[y], random8(160, 255));
	}

	// 4. Convert heat to COLOR!!!
	for (int i = 0; i < _num_leds; i++) 
	{
		_leds[i] = HeatColor(_heat[i]);
	}
}
