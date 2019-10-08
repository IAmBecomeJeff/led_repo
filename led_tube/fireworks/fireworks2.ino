/*

Fireworks

*/

#include "FastLED.h"
#include <queue>

#define LED_DT		7
#define LED_CK		14
#define COLOR_ORDER BGR
#define LED_TYPE	APA102
#define MAX_LEDS	300

uint8_t max_bright = 255;

struct CRGB leds[NUM_LEDS];

struct FireworksEffec {

	struct Particle {

		// Variables
		CRGB _star_color;
		unsigned long _birthTime;
		unsigned long _lastUpdate;
		int8_t _velocity;
		int16_t	_position;

		void Init(CRGB Star_Color, int16_t Position, int8_t maxSpeed) {
			_position = Position;
			_velocity = 2 * random16(maxSpeed) - maxSpeed;
			_star_color = Star_Color;
			_birthTime = millis() / 1000;
			_lastUpdate = millis() / 1000;
		}

		unsigned long Age() {
			return millis() / 1000 - _birthTime;
		}

		void Update() {
			unsigned long deltaTime = millis() / 1000 - _lastUpdate;
			_position += _velocity * deltaTime;
			_lastUpdate = millis() / 1000;
			_velocity -= (2 * _velocity * deltaTime);
			_star_color = _star_color.fadeToBlackBy(random8(32, 128));
		}

	}

	CRGBPalette16 _Palette = OceanColors_p;

	bool	Blend = true;
	double	MaxSpeed = 375.0;
	double	NewParticleProbability = 0.01;
	double	ParticlePreignitionTime = 0.0;
	double	ParticleIgnition = 0.2;
	double  ParticleHoldTime = 0.00;
	double	ParticleFadeTime = 2.0;
	double	ParticleSize = 0.00;

	Queue <Particle> _Particles = new Queue <Particle>;

	void Render() {

		for (int iPass = 0; iPass < NUM_LEDS / 50; iPass++) {
			if (random8() < NewParticleProbability) {
				uint16_t iStartPos = random16(NUM_LEDS);
				CRGB color = ColorFromPalette(_Palette, random8());
				int c = random8(10, 50);

				for (int i = 1; i < c; i++) {
					Particle particle = {};
					particle.Init(color, iStartPos, MaxSpeed / random8(1, 4));
					_Particles.Enqueue(particle);
				}
			}
		}

		while (_Particles.Count > NUM_LEDS) {
			_Particles.Dequeue();
		}

		fill_solid(leds, NUM_LEDS, CRGB::Black);

		for (Particle star : _Particles) {
			star.Update();
			CRGB c = star._star_color;

			uint8_t fade = 0;
			if (star.Age > ParticlePreignitionTime && star.Age < ParticleIgnition + ParticlePreignitionTime) {
				c = CRGB::White;
			}
			else {
				unsigned long age = star.Age();
				if (age < ParticlePreignitionTime) {
					fade = 255 - (255 * age / ParticlePreignitionTime); // UPDATE
				}
				else {
					age -= ParticlePreignitionTime;

					if (age < ParticleHoldTime + ParticleIgnition){
						fade = 0;
					}
					else if (age > ParticleHoldTime + ParticleIgnition + ParticleFadeTime) {
						fade = 255;
					}
					else {
						age -= (ParticleHoldTime + ParticleIgnition);
						fade = (age / ParticleFadeTime) * 255;
					}
				}
				c = c.fadeToBlackBy(fade);
			}
			ParticleSize = (1 - fade) * 5;
			leds[]// UPDATE with draw function
		}



	}

}