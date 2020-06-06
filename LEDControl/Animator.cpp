#include "Animator.h"

Animator::Animator(uint8_t num_leds)
{
	_leds = new CRGB[num_leds];
	_num_leds = num_leds;
}

Animator::~Animator()
{
	delete _leds;
}

void Animator::Update(int tick, unsigned long deltaT)
{
	if (_inTransition)
	{
		_transitionRunning += deltaT;
		if (_transitionRunning >= _transitionLength) {
			_inTransition = false;
			_transitionRunning = 0;

			_current_palette = _transition_palette;
		}
		else {
			uint8_t step = ((float)_transitionRunning / (float)_transitionLength) * 255;
			blend(_hold_palette, 
				_transition_palette, 
				_current_palette, 
				sizeof(_current_palette) / sizeof(_current_palette[0]), 
				step);
		}
	}
}

void Animator::setPalette(CRGBPalette16 palette, uint32_t transitionLength)
{
	_inTransition = true;
	_hold_palette = _current_palette;
	_transition_palette = palette;
	_transitionRunning = 0;
	_transitionLength = transitionLength;

	_hasPalette = true;
}

void Animator::setBlendType(TBlendType type)
{
	_blend_type = type;
}

void Animator::setLeds(CRGB* leds)
{
	_leds = leds;
}

CRGB* Animator::getLeds()
{
	return _leds;
}
