#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <FastLED.h>

#define BRIGHTNESS  128
#define NoiseFloor  0.005
#define TargetAVG   3.0               // Target avg for AGC
#define peakTargetAVG 0.4
#define GainAdjust  0.0001            // AGC uses this value to increase or decrease gain each loop, bigger values make AGC react faster
#define MAXGAIN     2.0              // AGC will not set the mixer gain higher than this
#define MINGAIN     0.01              // AGC will not set mixer gain lower than this
#define LogCurve    3        
#define MatrixHeight 16
#define MatrixWidth 16

#define DATA_PIN 11
#define CLOCK_PIN 13
#define COLOR_ORDER BGR
#define CHIPSET     APA102
#define UpdateFrequencyMHZ  12

#define MATRIX_CENTRE_Y 5
#define MATRIX_CENTRE_X 5

const bool  MatrixSerpentineLayout = true;

#define NUM_LEDS (MatrixWidth * MatrixHeight)
CRGB leds_plus_safety_pixel[NUM_LEDS + 1];
CRGB leds2_plus_safety_pixel[NUM_LEDS + 1];
CRGB* const leds(leds_plus_safety_pixel + 1);
CRGB* const leds2(leds_plus_safety_pixel + 1);

float mgain1 = 1.0;
float mgain2 = 1.0;


// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=115,244
//AudioOutputI2S           i2s2;
AudioMixer4              mixer;          //xy=400,248
AudioAnalyzeFFT1024      fft;            //xy=649,152
AudioAnalyzePeak         peak;           //xy=653,380
AudioConnection          patchCord1(i2s1, 0, mixer, 0);
AudioConnection          patchCord2(mixer, fft);
AudioConnection          patchCord3(mixer, peak);
//AudioConnection          patchCord4(i2s1, 0, i2s2, 0);
//AudioConnection          patchCord5(i2s1, 1, i2s2, 1);
AudioControlSGTL5000     sgtl5000;       //xy=335,609
// GUItool: end automatically generated code


float cVal(int start, int end) {
    double val = 0;                         // starting value
    double res = 0;

    val = fft.read(start, end);          // add 1 so that we get to the correct part of the log2 curve
    if (val > NoiseFloor) {
        res = ((log10(val) + 2) / 2);   // 0(Noisefloor) is at a value of approx 0.3
        return(res);
    }
    else {
        return((float)0.0);
    }
}

// This function will return the right 'led index number' for 
// a given set of X and Y coordinates on your matrix.  
// IT DOES NOT CHECK THE COORDINATE BOUNDARIES.  
// That's up to you.  Don't pass it bogus values.
//
uint16_t XY(uint8_t x, uint8_t y)
{
    uint16_t i;

    if (y & 0x01) {
        // Odd rows run backwards
        uint8_t reverseX = (MatrixWidth - 1) - x;
        i = (y * MatrixWidth) + reverseX;
    }
    else {
        // Even rows run forwards
        i = (y * MatrixWidth) + x;
    }

    return i;
}

uint16_t xySave(uint8_t x, uint8_t y)
{
    if (x >= MatrixWidth) return -1;
    if (y >= MatrixHeight) return -1;
    return XY(x, y);
}

void cLed(int band, int start, int end) {
    int displayVal = 0;
    float val = cVal(start, end);
    if (val > 1) val = 1;
    val = val * 100;                  // bring into usable are
    displayVal = map((long)val, 39, 100, 0, MatrixHeight);  // Number of LEDs  
    for (int i = 0; i < displayVal; i++) {
        int index = xySave(i, band);
        leds[index] = CHSV(100 - i * 10, 255, 200);
    }
}

void colorLed(int i, int start, int end) {
    int displayVal = 0;
    float val = fft.read(start, end);
    if (val > 1) val = 1;
    displayVal = (int)(val * 255);
    leds[i] = CHSV(255 - displayVal, 200, displayVal);
}




void setup() {
    Serial.begin(9600);
    //  while (!Serial);                    // wait for serial to start

    AudioMemory(10);
    sgtl5000.enable();
    sgtl5000.volume(0.9);
    sgtl5000.inputSelect(AUDIO_INPUT_MIC);
    sgtl5000.micGain(50);
    //sgtl5000.inputSelect(AUDIO_INPUT_LINEIN);
    //sgtl5000.lineInLevel(13);
    FastLED.addLeds<APA102, DATA_PIN, CLOCK_PIN, BGR, DATA_RATE_MHZ(UpdateFrequencyMHZ)>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);
    FastLED.setDither(0);
    FastLED.setMaxPowerInVoltsAndMilliamps(5, 2000);
    for (int i = 0; i < NUM_LEDS; i++)
        leds[i] = 0x000000;
    FastLED.show();
    fft.windowFunction(AudioWindowBartlett1024);
    mixer.gain(0, mgain1);

}


void loop() {
    if (fft.available()) {
        blur2d(leds, MatrixWidth, MatrixHeight, 3);
        fadeToBlackBy(leds, NUM_LEDS, 30);

        cLed(0, 1, 1);      // 43             
        cLed(1, 2, 3);      // 86
        cLed(2, 3, 4);      // 172
        cLed(3, 5, 8);      // 344  
        cLed(4, 9, 16);     // 688
        cLed(5, 17, 32);    // 1376
        cLed(6, 33, 64);    // 2752
        cLed(7, 65, 128);   // 5504
        cLed(8, 129, 255);  // 11008
        cLed(9, 256, 511);  // rest

    }
    FastLED.show();
}