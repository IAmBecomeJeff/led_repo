

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
CRGBPalette16 currentPalette;
TBlendType currentBlending;
uint8_t color_left;
uint8_t color_right;

int halfway = NUM_LEDS / 2;

AudioInputI2S            audioInput;         // audio shield: mic or line-in
AudioAnalyzeFFT1024      myFFT;
AudioOutputI2S           audioOutput;        // audio shield: headphones & line-out
AudioAnalyzePeak         peak1;          //xy=331,86
AudioAnalyzePeak         peak2;          //xy=361,174
AudioConnection          patchCord1(audioInput, 0, peak1, 0);
AudioConnection          patchCord2(audioInput, 1, peak2, 0);
AudioConnection          patchCord3(audioInput, 0, audioOutput, 0);
AudioConnection          patchCord4(audioInput, 1, audioOutput, 1);
AudioControlSGTL5000     audioControl;     //xy=250,358



void setup() {
  Serial.begin(9600);

  FastLED.addLeds<LED_TYPE, DATA_PIN, CLOCK_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(BRIGHTNESS);

  currentPalette = RainbowColors_p;
  currentBlending = LINEARBLEND;

  AudioMemory(10);
  audioControl.enable();
  audioControl.volume(0.8);
  //audioControl.inputSelect(AUDIO_INPUT_MIC);
  //audioControl.micGain(30);
  audioControl.inputSelect(AUDIO_INPUT_LINEIN);
  audioControl.lineInLevel(15);

  delay(1000);
}

// for best effect make your terminal/monitor a minimum of 62 chars wide and as high as you can.

elapsedMillis msecs;

void loop() {
  
  if (msecs > 40) {
    if (peak1.available() && peak2.available()) {
      msecs = 0;
      float leftNumber = peak1.read();
      float rightNumber = peak2.read();
      int leftPeak = leftNumber * halfway;
      int rightPeak = rightNumber * halfway;
      /*
      int count;
      for (count=0; count < halfway-leftPeak; count++) {
        Serial.print(" ");
      }
      while (count++ < halfway) {
        Serial.print("<");
      }
      Serial.print("||");
      for (count=0; count < rightPeak; count++) {
        Serial.print(">");
      }
      while (count++ < halfway) {
        Serial.print(" ");
      }
      Serial.print(leftPeak);
      Serial.print(", ");
      Serial.print(rightPeak);
      Serial.println();
      */
      color_left = 0;
      color_right = 0;
      for (int i = halfway - leftPeak; i < halfway; i++) {
          leds[i] = CRGB::Red;
      }
      for (int i = halfway; i < halfway + rightPeak; i++) {
          leds[i] = CRGB::Blue;
      }
      FastLED.show();
      fadeToBlackBy(leds, NUM_LEDS, 64);
    }
  }
}
