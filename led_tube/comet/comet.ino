#include "FastLED.h"
#include <queue>

// Fixed definitions cannot change on the fly.
#define LED_DT 7                                                                // Serial data pin for all strands
#define LED_CK 14                                                               // Serial clock pin for WS2801 or APA102
#define COLOR_ORDER BGR                                                         // It's GRB for WS2812
#define LED_TYPE APA102                                                         // Alternatively WS2801, or WS2812
#define NUM_LEDS 300                                                            // Maximum number of LED's defined (at compile time).

uint8_t max_bright = 255;                                                       // Overall brightness definition. It can be changed on the fly.

struct CRGB leds[NUM_LEDS];                                                     // Initialize our LED array. We'll be using less in operation.

CRGBPalette16 currentPalette = OceanColors_p;                                   // Use palettes instead of direct CHSV or CRGB assignments
CRGBPalette16 targetPalette = OceanColors_p;
uint16_t start_position = 0;

struct comet {
	uint8_t		_color;
	uint16_t	_position;
	uint8_t		_velocity;
	uint8_t		_fade;
	bool		_exist;
	int			_birthTime;
	int			_lastUpdate;

	void Init(uint8_t Color, uint8_t Velocity, uint8_t Fade) {
		_color = Color; 
		_position	= 0;
		_velocity	= Velocity;
		_fade		= Fade;
		_exist		= true;
		_birthTime	= millis() / 1000;
		_lastUpdate = millis() / 1000;
	}

	void Move() {
		int deltaTime = millis() / 1000 - _lastUpdate;
		_position += _velocity * deltaTime;
		_lastUpdate = millis() / 1000;
	}
}

Queue<comet> comet_queue = Queue<comet>(NUM_LEDS / 10);



void setup() {

	Serial.begin(115200);                                                            // Setup serial baud rate
	delay(1000);                                                                    // Slow startup so we can re-upload in the case of errors.
	LEDS.setBrightness(max_bright);                                                 // Set the generic maximum brightness value.
	LEDS.addLeds<LED_TYPE, LED_DT, LED_CK, COLOR_ORDER >(leds, NUM_LEDS);           // APA102 or WS2801 definition
  //  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER >(leds, NUM_LEDS);                 // WS2812 definition

	set_max_power_in_volts_and_milliamps(5, 1000);                                  // 5V, 1A

} // setup()



void loop() {

	EVERY_N_MILLISECONDS(50) {                                                      // Smooth palette transitioning runs continuously.
		uint8_t maxChanges = 24;
		nblendPaletteTowardPalette(currentPalette, targetPalette, maxChanges);
	}

	EVERY_N_MILLIS(50) {                                                            // Sets the original delay time.
		comet();                                                                   // Run the ripple routine.
	}

	FastLED.show();                                                                 // Power managed display of LED's.

} // loop()







void comet(){
	fadeall();
	uint16_t index = start_index + step;
	leds[index] = ColorFromPalette(current_palette, index);
	step = (step + 1) % NUM_LEDS;

#endif