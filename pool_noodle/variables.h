// Variables

// Setup variables
#define NUM_LEDS	150
#define STRIP_LENGTH 75
#define DATA_PIN	14
#define CLOCK_PIN	7
#define COLOR_ORDER BGR
#define LED_TYPE	APA102	

// Master LED Array
struct CRGB master_leds[NUM_LEDS];

// Debug
#define DEBUG 1

// LED Variables
#define MAX_BRIGHT 255

// Mode Variables
uint8_t current_mode_number = 0;
enum Mode { JUGGLE };
Mode Modelist[] = { JUGGLE };

// Delay Variables
uint8_t current_delay;
uint8_t next_delay;

// Palette Variables
uint8_t palette_index;

// Transition Variables
enum TransitionType { BLENDING };
bool in_transition = 0;
TransitionType transition_type;
uint8_t blending_ratio;