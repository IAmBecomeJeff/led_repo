#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputAnalog         adc1;           //xy=181,127
AudioAnalyzeRMS          rms1;           //xy=431,168
AudioAnalyzePeak         peak1;          //xy=433,130
AudioAnalyzeFFT1024      fft1024_1;      //xy=439,211
AudioConnection          patchCord1(adc1, peak1);
AudioConnection          patchCord2(adc1, rms1);
AudioConnection          patchCord3(adc1, fft1024_1);
// GUItool: end automatically generated code

void setup() {
      Serial.begin(9600);
      delay(1000);
      Serial.println("Teensy Audio AudioMemory()");
      AudioMemory(10);
}

int pk = 1, rm = 1, ff = 1;
int delayValue = 100;
unsigned long loopCount = 0;

void loop() {
      Serial.printf("----%lu----\n", loopCount);
      if (peak1.available()) {
            pk = (int)(peak1.read() * 100);
            for (int i = 0; i < pk; i++) {
                Serial.print("p"); 
            }
            Serial.printf("\tPeak: %d\n", pk);
      } else {
            Serial.println("peak1 not available");
      }
      if (rms1.available()) {
            rm = (int)(rms1.read() * 100);
            for (int i = 0; i < rm; i++) {
                Serial.print("r"); 
            }
            Serial.printf("\tRMS: %d\n", rm);
      } else {
            Serial.println("rms1 not available"); 
      }
      if (fft1024_1.available()) {
            float fftAccumulator = 0;
            for (int i = 0; i < 512; i++) {
                  fftAccumulator += fft1024_1.read(i);
            }
            ff = (int)(fftAccumulator * 100);
            for (int i = 0; i < ff; i++) {
                  Serial.print("f"); 
            }
            Serial.printf("\tFFT: %d\n", ff);
      } else {
           Serial.println("fft1024_1 not available");
      }
      
      loopCount++;
      
      delay(delayValue); // Delay for a period of time (in milliseconds).

}
