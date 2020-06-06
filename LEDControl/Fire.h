#pragma once
#include "Animator.h"
#include <FastLED.h>

class Fire :
	public Animator
{
private:
	uint8_t _delay_time = 15;
	uint8_t _fire_sparking;
	uint8_t _fire_cooling;

	byte* _heat;
public:
	Fire(uint8_t num_leds,uint8_t fs, uint8_t fc);
	~Fire();
	void Update(int tick, unsigned long deltaT);
};

