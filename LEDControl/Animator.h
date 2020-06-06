#pragma once
#include <FastLED.h>

class Animator
{
private:
	CRGBPalette16 _hold_palette;
	CRGBPalette16 _transition_palette;
protected:
	struct CRGB *_leds;
	unsigned int _num_leds;
	TBlendType _blend_type = LINEARBLEND;
	
	bool _hasPalette;
	bool _inTransition;
	uint32_t _transitionRunning;
	uint32_t _transitionLength;
	CRGBPalette16 _current_palette;
public:
	Animator(uint8_t num_leds);
	~Animator();
	virtual void Update(int tick, unsigned long deltaT);

	void setPalette(CRGBPalette16 palette,uint32_t transitionLength);
	void setBlendType(TBlendType type);
	void setLeds(CRGB* leds);
	CRGB* getLeds();
};

