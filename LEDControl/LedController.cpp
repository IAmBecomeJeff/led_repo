#include "LedController.h"

void LedController::setBrightness(uint8_t brightness)
{
	this->_max_bright = brightness;
	FastLED.setBrightness(_max_bright);
}

void LedController::setPower(bool isOn)
{
	this->_isOn = isOn;
}

void LedController::setMode(uint8_t mode,uint32_t length)
{
	this->_mode = mode;
	_inTransition = true;
	_transitionLength = length;
	_transitionRunning = 0;
}

void LedController::setPaletteLibrary(TProgmemRGBGradientPalettePtr *palettes)
{
	_palettes = palettes;
}

void LedController::setPalette(uint32_t index, uint32_t length)
{
	if (_animation != nullptr)
	{
		_animation->setPalette(_palettes[index], length);
	}
}

void LedController::setDelay(uint8_t delay)
{
	this->_ico_delay = delay;
}

void LedController::setup()
{
	LEDS.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(_leds, NUM_LEDS);

	FastLED.setBrightness(_max_bright);
	set_max_power_in_volts_and_milliamps(5, 1000);
}

void LedController::loop() 
{
	EVERY_N_MILLIS_I(this_timer, _ico_delay) {
		this_timer.setPeriod(_ico_delay);
		if (_isOn) {
			_loop();
		}
	}
}

void LedController::_loop() {
	uint32_t t = millis();
	uint32_t deltaT = t - _lastMillis;

	if (deltaT < 0) {
		// Clock has overflown since last update, sit this one out
		return;
	}
	++_tickCount;
	_modeSwitch(_mode);


	if (_animation != nullptr)
	{
		_animation->Update(_tickCount, deltaT);
	}
	if (_nextAnimation != nullptr)
	{
		_nextAnimation->Update(_tickCount, deltaT);
	}
	
	if (_inTransition)
	{
		_transitionRunning += deltaT;

		if (_transitionRunning >= _transitionLength)
		{
			_inTransition = false;
			_transitionRunning = 0;

			// Swap the next animation over to current and cleanup
			delete _animation;
			_animation = _nextAnimation;
			_nextAnimation = nullptr;
		}
	}

	if (_inTransition) 
	{
		uint8_t step = ((float)((float)_transitionRunning / (float)_transitionLength)) * 255;
		for (int i = 0; i < NUM_LEDS; i++) {
			_leds[i] = blend(_animation->getLeds()[i], _nextAnimation->getLeds()[i], step);
		}
	}
	else
	{
		memcpy(_leds, _animation->getLeds(), sizeof(CRGB) * NUM_LEDS);
	}
	FastLED.show();

	
	_lastMillis = t;
}

void LedController::_modeSwitch(uint8_t mode)
{
	if (_inTransition) {
		if (_transitionRunning == 0) {
			switch (mode) {
			case 0:
				_nextAnimation = new Fire(NUM_LEDS, random8(50, 110), random8(60, 120));
				break;
			case 1:
				_nextAnimation = new OneSin(NUM_LEDS, random8(1, 4), random8(5, 13),
					random8(100, 200), random8(1, 5), random8(0, 5), random8(20, 40), random8(), random8(10));
				break;
			case 2:
				_nextAnimation = new RainbowMarch(NUM_LEDS, random8(1, 20), random8(1, 4), random8(3, 13));
				break;
			case 3:
				_nextAnimation = new Solid(NUM_LEDS, CRGB(random8(), random8(), random8()));
				break;
			case 4:
				_nextAnimation = new StaticPalette(NUM_LEDS);
				break;
			default:
				_nextAnimation = new Fire(NUM_LEDS, random8(50, 110), random8(60, 120));
				break;
			}
		}
	}
}
LedController::LedController()
{
	_animation = new Solid(NUM_LEDS, CRGB(255,255,255));
}

LedController::~LedController()
{
	delete _animation;
	delete _nextAnimation;
}
