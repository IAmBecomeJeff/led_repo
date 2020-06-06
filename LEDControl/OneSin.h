#pragma once
#include "Animator.h"
class OneSin :
	public Animator
{
private:
	uint8_t _sin_inc;
	uint8_t _sin_speed;
	uint8_t _sin_cutoff;
	uint8_t _sin_rot;
	uint8_t _sin_phase;
	uint8_t _sin_all_freq;
	uint8_t _bg_clr;
	uint8_t _bg_bri;
	uint8_t _sin_start = 0;
	uint8_t _sin_index;

public:
	OneSin(uint8_t num_leds, uint8_t si, uint8_t ss, uint8_t sc,
		uint8_t sr, uint8_t sp, uint8_t saf, uint8_t bc, uint8_t bb);

	void Update(int tick, unsigned long deltaT);
};

