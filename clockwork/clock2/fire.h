#ifndef FIRE_H
#define FIRE_H

DEFINE_GRADIENT_PALETTE(firePal_gp) {
    0, 0, 0, 0,      //black
        100, 100, 0, 0,      //dark red
        128, 255, 0, 0,      //red
        220, 255, 255, 0,      //yellow
        255, 255, 255, 255
};  //white


uint8_t firePixels[NUM_LEDS];
CRGBPalette16 currentPalette = firePal_gp;



void fire() {
    for (uint16_t i = 0; i < kMatrixWidth; i++) {
        firePixels[(kMatrixHeight - 1) * kMatrixWidth + i] = ColorFromPalette(currentPalette, 255, 255, LINEARBLEND);
    }

    for (uint16_t x = 0; x < kMatrixWidth; x++) {   
        for (uint16_t y = 1; y < kMatrixHeight; y++) {
            uint16_t src = y * kMatrixWidth + x;
            if (firePixels[src] == 0) {
                firePixels[src - kMatrixWidth] = 0;
            }
            else {
                // Commented lines moves fire sideways as well as up, but doesn't look good on low res matrix:
                // int16_t dst = src - rand + 1;
                // firePixels[dst - kMatrixWidth] = firePixels[src] - random8(1);
                firePixels[src - kMatrixWidth] = firePixels[src] - random8(3);
            }
        }
    }

    for (int y = 0; y < kMatrixHeight; y++) {
        for (int x = 0; x < kMatrixWidth; x++) {
            int index = firePixels[kMatrixWidth * y + x];
            // Index goes from 0 -> kMatrixHeight, palette goes from 0 -> 255 so need to scale it
            uint8_t indexScale = 255 / kMatrixHeight;
            leds[XY(x, y)] = ColorFromPalette(_currentPalette, constrain(index * indexScale, 0, 255), 255, LINEARBLEND);
        }
    }
}

#endif