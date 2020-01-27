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
enum ArrayType { CURRENT, NEXT, OVERLAY };
uint8_t curr_delay;
uint8_t next_delay;


// Mode Variables
uint8_t current_mode_number = 0;
bool	random_mode			= 0;		// Determines if we change randomly or in the order of ModeList

enum Mode	  	  { JUGGLE, JUGGLE_ONE_DIR, JUGGLE_PHASED, JUGGLE_PHASED_ONE_DIR, JUGGLE_RANDOM, 
					RAINBOW_MARCH, RAINBOW_MARCH_SPLIT, RAINBOW_MARCH_RANDOM,
					FIRE, FIRE_SYNC, FIRE_MIRROR, FIRE_MIRROR_SYNC, FIRE_RANDOM, TORCH, TORCH_SYNC,
					COLORWAVE, PRIDE,
					CONFETTI,
					ONE_SIN,
					FIREWORKS
				  };

Mode ModeList[] = { JUGGLE, JUGGLE_ONE_DIR, JUGGLE_PHASED, JUGGLE_PHASED_ONE_DIR, JUGGLE_RANDOM, 
					RAINBOW_MARCH, RAINBOW_MARCH_SPLIT, RAINBOW_MARCH_RANDOM,
					FIRE, FIRE_SYNC, FIRE_MIRROR, FIRE_MIRROR_SYNC, FIRE_RANDOM, TORCH, TORCH_SYNC,
					COLORWAVE, PRIDE,
					CONFETTI,
					ONE_SIN,					
					FIREWORKS
				  };

extern Mode start_mode;
uint16_t number_of_mode_changes;
uint16_t number_of_min_on;


// Palette Variables
uint8_t palette_index;
uint8_t palette_count = sizeof(palettes) / sizeof(TProgmemRGBGradientPalettePtr);


// Transition Variables
enum TransitionType { BLENDING };
bool in_transition = 0;
TransitionType transition_type;
uint8_t transition_ratio;
uint8_t transition_speed; // seconds


// Fireworks Variables
#define MAX_NUMBER_OF_SPARKS 60
#define MIN_NUMBER_OF_SPARKS 20
enum stage { FADEUP, EXPLOSION, WAITING };
uint16_t max_wait = 1000;
uint16_t min_wait = 500;
float gravity = 0.97;
uint8_t firework_bg_fade = 128;