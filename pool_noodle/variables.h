// Variables

// Setup variables
#define NUM_LEDS	150
#define ONE_SIDE	75
#define DATA_PIN	14
#define CLOCK_PIN	7
#define COLOR_ORDER BGR
#define LED_TYPE	APA102	

// Master LED Array
struct CRGB master_leds[NUM_LEDS];

// Debug
#define DEBUG 1

// LED Variables
#define MAX_BRIGHT 255		// used in initial LEDS.set_brightness

// Array Variables
enum ArrayType { CURRENT, NEXT };

// Mode Variables
uint8_t current_mode_number = 0;
enum Mode { JUGGLE, RAINBOW_MARCH, RAINBOW_MARCH_SPLIT };
Mode ModeList[] = { JUGGLE, RAINBOW_MARCH, RAINBOW_MARCH_SPLIT };

// Delay Variables
uint8_t curr_delay;
uint8_t next_delay;

// Palette Variables
uint8_t palette_index;
uint8_t palette_count = sizeof(palettes) / sizeof(TProgmemRGBGradientPalettePtr);

// Transition Variables
enum TransitionType { BLENDING };
bool in_transition = 0;
TransitionType transition_type;
uint8_t transition_ratio;
uint8_t transition_speed; // seconds