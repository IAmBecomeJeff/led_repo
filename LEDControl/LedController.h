#pragma once
#include <FastLED.h>
#include "Animator.h"
#include "Fire.h"
#include "OneSin.h"
#include "RainbowMarch.h"
#include "Solid.h"
#include "StaticPalette.h"

#define DATA_PIN 15
#define CLOCK_PIN 27
#define LED_TYPE APA102

#define NUM_LEDS 60
#define COLOR_ORDER BGR

class LedController
{
private:
	uint8_t _max_bright = 255;
	CRGB *_leds = new CRGB[NUM_LEDS];
	bool _isOn = true;
	uint8_t _mode;
	uint8_t _ico_delay = 150;

	bool _inTransition = false;
	uint32_t _transitionLength;
	uint32_t _transitionRunning;

	uint32_t _tickCount = 0;
	uint32_t _lastMillis = 0;

	Animator *_animation = nullptr;
	Animator* _nextAnimation = nullptr;

	const TProgmemRGBGradientPalettePtr *_palettes;

	void _loop();
	void _modeSwitch(uint8_t mode);
public:
	LedController();
	~LedController();
	void loop();
	void setup();

	void setBrightness(uint8_t brightness);
	void setPower(bool isOn);
	void setDelay(uint8_t delay);
	void setMode(uint8_t mode, uint32_t length);
	void setPaletteLibrary(TProgmemRGBGradientPalettePtr *palettes);
	void setPalette(uint32_t index, uint32_t length);

};

