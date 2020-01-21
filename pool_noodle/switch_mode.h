#ifndef SWITCH_MODE_H
#define SWITCH_MODE_H

void switch_mode(LEDStruct& leds) {
	switch (leds.mode_name) {
		case JUGGLE:
			if (DEBUG) { Serial.println("IN SWITCH MODE JUGGLE"); }
			juggle(leds);
			break;
	}
}




#endif
