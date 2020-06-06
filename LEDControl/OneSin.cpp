#include "OneSin.h"

OneSin::OneSin(uint8_t num_leds, uint8_t si, uint8_t ss, uint8_t sc, uint8_t sr, uint8_t sp, uint8_t saf, uint8_t bc, uint8_t bb) : Animator(num_leds)
{
	_sin_inc = si;
	_sin_speed = ss + (saf / 5);
	_sin_cutoff = sc;
	_sin_rot = sr;
	_sin_phase = sp;
	_sin_all_freq = saf;
	_bg_clr = bc;
	_bg_bri = bb;
}

void OneSin::Update(int tick, unsigned long deltaT)
{
	Animator::Update(tick, deltaT);

	_sin_start += _sin_inc;
	_sin_index = _sin_start;
	_sin_phase += _sin_speed;

	for (int i = 0; i < _num_leds; i++) {
		uint8_t sin_bright = qsub8(cubicwave8((i * _sin_all_freq) + _sin_phase), _sin_cutoff);
		_leds[i] = CHSV(_bg_clr, 255, _bg_bri);
		if (_hasPalette)
		{
			_leds[i] += ColorFromPalette(_current_palette, _sin_index + i * _sin_inc, sin_bright, _blend_type);
		}
		_sin_index += _sin_rot;
	}
}
