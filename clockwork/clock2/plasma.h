#ifndef PLASM_H
#define PLASMA_H



uint16_t plasmaTime = 0;
uint16_t plasmaShift = (random8(0, 5) * 32) + 64;
uint8_t plasmaXfactor = 8;
uint8_t plasmaYfactor = 8;

void plasma() {
    for (uint8_t x = 0; x < kMatrixWidth; x++) {
        for (uint8_t y = 0; y < kMatrixHeight; y++) {
            int16_t r = sin16(plasmaTime) / 256;
            int16_t h = sin16(x * r * plasmaXfactor + plasmaTime) + cos16(y * (-r) * plasmaYfactor + plasmaTime) + sin16(y * x * (cos16(-plasmaTime) / 256) / 2);
            leds[XY(x, y)] = CHSV((uint8_t)((h / 256) + 128), 255, 255);
        }
    }
    uint16_t oldPlasmaTime = plasmaTime;
    plasmaTime += plasmaShift;
    if (oldPlasmaTime > plasmaTime) {
        plasmaShift = (random8(0, 5) * 32) + 64;
    }
}

#endif