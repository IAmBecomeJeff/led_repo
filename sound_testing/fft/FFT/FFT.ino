// FFT Test
//
// Compute a 1024 point Fast Fourier Transform (spectrum analysis)
// on audio connected to the Left Line-In pin.  By changing code,
// a synthetic sine wave can be input instead.
//
// The first 40 (of 512) frequency analysis bins are printed to
// the Arduino Serial Monitor.  Viewing the raw data can help you
// understand how the FFT works and what results to expect when
// using the data to control LEDs, motors, or other fun things!
//
// This example code is in the public domain.

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <FastLED.h>

#define DATA_PIN 11
#define CLOCK_PIN 13
#define NUM_LEDS 288
#define LED_TYPE APA102
#define COLOR_ORDER BGR
#define BRIGHTNESS 128

CRGB leds[NUM_LEDS];

DEFINE_GRADIENT_PALETTE(Orange_to_Purple_gp) {
    0, 208, 50, 1,
        127, 146, 27, 45,
        255, 97, 12, 178
};

CRGBPalette16 myPal = Orange_to_Purple_gp;


//const int myInput = AUDIO_INPUT_LINEIN;
const int myInput = AUDIO_INPUT_MIC;

// Create the Audio components.  These should be created in the
// order data flows, inputs/sources -> processing -> outputs
//
AudioInputI2S          audioInput;         // audio shield: mic or line-in
AudioAnalyzeFFT1024    myFFT;
AudioOutputI2S         audioOutput;        // audio shield: headphones & line-out

// Connect either the live input or synthesized sine wave
AudioConnection patchCord1(audioInput, 0, myFFT, 0);

AudioConnection          patchCord3(audioInput, 0, audioOutput, 0);
AudioConnection          patchCord4(audioInput, 1, audioOutput, 1);

AudioControlSGTL5000 audioControl;

void setup() {
    Serial.begin(115200);

    FastLED.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(BRIGHTNESS);
  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(12);

  // Enable the audio shield and set the output volume.
  audioControl.enable();
  audioControl.inputSelect(myInput);
  audioControl.volume(1);
  if (myInput == AUDIO_INPUT_MIC) {
      audioControl.micGain(40);
  }
  else if (myInput == AUDIO_INPUT_LINEIN) {
      audioControl.lineInLevel(15);
  }

  // Configure the window algorithm to use
  myFFT.windowFunction(AudioWindowBartlett1024);
  //myFFT.windowFunction(NULL);
}
elapsedMillis msecs;
uint8_t c_index = 0;

void loop() {
    if (msecs > 40) {
        float n;
        int i;
        //fadeToBlackBy(leds, NUM_LEDS, 32);
        if (myFFT.available()) {
            msecs = 0;
            // each time new FFT data is available
            // print it all to the Arduino Serial Monitor
            Serial.print("FFT: ");
            for (i = 0; i < 40; i++) {
                n = myFFT.read(i);
                if (n >= 0.01) {
                    Serial.print(n);
                    Serial.print(" ");
                    for (int j = 6 * i - random8(3); j < 6 * i + 6 + random8(3); j++) {
                        if (j > 0 && j < NUM_LEDS) {
                            leds[j] += ColorFromPalette(myPal, j + c_index, n*1000, LINEARBLEND);
                        }
                    }
                    c_index++;
                }
                else {
                    Serial.print("  -  "); // don't print "0.00"
                }
            }
            Serial.println();
           FastLED.show();
        }
    } 
    EVERY_N_MILLIS(20){
      fadeToBlackBy(leds, NUM_LEDS, 4);
      blur1d(leds,NUM_LEDS, 64);   
    }
}
