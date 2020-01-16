#ifndef LED_CLASS_H
#define LED_CLASS_H

// LED class

class LedEffect {
	public:
		bool enabled;
		CRGBArray<NUM_LEDS> led_data;
		virtual void render() = 0;

		void enable() {
			enabled = true;
		}

		void disable() {
			enabled = false;
		}

		void toggle() {
			enabled = !enabled;
		}

		// Effects
		void juggle();

};

#endif