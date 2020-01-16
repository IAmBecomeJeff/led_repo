// Variables

// Setup variables
#define NUM_LEDS	150
#define DATA_PIN	7
#define CLOCK_PIN	14
#define COLOR_ORDER BGR
#define LED_TYPE	APA102	

// Master LED Array
CRGBArray<NUM_LEDS> leds;
CRGBSet led_data(leds(0, NUM_LEDS));

// Debug
#define DEBUG 0

// LED Variables
#define MAX_BRIGHT 255
