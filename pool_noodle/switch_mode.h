#ifndef SWITCH_MODE_H
#define SWITCH_MODE_H

void switch_mode(LEDStruct& leds) {
	switch (leds.mode_name) {
		case JUGGLE:
			juggle(leds);
			break;

		case RAINBOW_MARCH:
			rainbow_march(leds);
			break;

		case RAINBOW_MARCH_SPLIT:
			rainbow_march_split(leds);
			break;
	}
}




#endif
