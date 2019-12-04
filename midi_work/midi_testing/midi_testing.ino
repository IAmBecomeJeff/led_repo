// Testing MIDI controls

#include <FastLED.h>
#include <MIDI.h>
//#include <SoftwareSerial.h>
#include <HardwareSerial.h>

// Variables
#include "vars.h"

// Master LED array
CRGBArray<NUM_LEDS> leds;
//CRGBSet leddata(leds(0, NUM_LEDS));

// MIDI Effect
#include "midi_effect.h"

// Teensy 3.2 MIDI Serial ports
//		Name	- RX, TX
//		Serial1	-  0,  1
//		Serial2 -  9, 10
//		Serial3 -  7,  8

// Forward Declarations
//void NoteOn(byte channel, byte pitch, byte velocity);
//void NoteOff(byte channel, byte pitch, byte velocity);



MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, MIDI); // Serial2 is pin 9 for RX

void setup() {
	// Pause
	delay(1000);

	// FastLED setup
	FastLED.addLeds < APA102, LED_PIN, CLOCK_PIN, BGR>(leds, NUM_LEDS);
	FastLED.setBrightness(MAX_BRIGHT);
	FastLED.setCorrection(TypicalLEDStrip);

	// MIDI Setup
	MIDI.begin(1);
	// MIDI.turnThruOff();  // Why??
	
	// Serial setup
	Serial.begin(57600);
	Serial.println("MIDI Input testing");
}

void loop() {

	EVERY_N_MILLIS(10) {
		leds.fadeToBlackBy(10);
		FastLED.show();
	}

	int type, note, velocity, channel, d1, d2;
	if (MIDI.read()) {

		type  = MIDI.getType();
		Serial.println(String("Type: ") + type);

		switch (type) {
			case midi::NoteOn:
				note	 = MIDI.getData1();
				velocity = MIDI.getData2();
				channel  = MIDI.getChannel();
				if (velocity > 0) {
					Serial.println(String("Note On:  ch=") + channel + ", note=" + note + ", velocity=" + velocity);
				}
				else {
					Serial.println(String("Note Off: ch=") + channel + ", note=" + note);
				}
				if (type == 144 && note >= 23 && note <= 73) {
					NoteLED(note, velocity);
				}
				break;
			
			case midi::NoteOff:
				note	 = MIDI.getData1();
				velocity = MIDI.getData2();
				channel  = MIDI.getChannel();
				Serial.println(String("Note Off: ch=") + channel + ", note=" + note + ", velocity=" + velocity);
				break;

			default:
				d1 = MIDI.getData1();
				d2 = MIDI.getData2();
				Serial.println(String("Message, type=") + type + ", data = " + d1 + " " + d2);
		}

	}
}
