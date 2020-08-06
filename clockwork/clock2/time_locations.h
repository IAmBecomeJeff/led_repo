#ifndef TIME_LOCATIONS_H
#define TIME_LOCATIONS_H


#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0])) // Probably move this to support functions
#define kMatrixWidth 8
#define kMatrixHeight 15


uint8_t XY(uint8_t x, uint8_t y) {
    if ((x >= kMatrixWidth) || (y >= kMatrixHeight)) {
        return (96);
    }

    const uint8_t XYTable[] = {
      96,  97,  98,   1,   0,  99, 100, 101,
     105, 104,   2,   3,   4,   5, 103, 102,
     106,  11,  10,   9,   8,   7,   6, 107,
      12,  13,  14,  15,  16,  17,  18,  19,
      27,  26,  25,  24,  23,  22,  21,  20,
      28,  29,  30,  31,  32,  33,  34,  35,
      43,  42,  41,  40,  39,  38,  37,  36,
      44,  45,  46,  47,  48,  49,  50,  51,
      59,  58,  57,  56,  55,  54,  53,  52,
      60,  61,  62,  63,  64,  65,  66,  67,
      75,  74,  73,  72,  71,  70,  69,  68,
      76,  77,  78,  79,  80,  81,  82,  83,
     108,  89,  88,  87,  86,  85,  84, 109,
     113, 112,  90,  91,  92,  93, 111, 110,
     114, 115, 116,  95,  94, 117, 118, 119
    };
    uint8_t i = (y * kMatrixWidth) + x;
    uint8_t j = XYTable[i];
    return j;

}

// allowed space for 0,2,3,5,6,7,8,9 to start:
// 0:  3
// 1:  2, 4
// 2:  1, 3, 5
// 3:  0, 2, 4, 6
// 4:  1, 3, 5
// 5:  0, 2, 4, 6
// 6:  1, 3, 5
// 7:  0, 2, 4, 6
// 8:  1, 3, 5
// 9:  2, 4 
// 10: 3
// 11:
// 12:
// 13:
// 14:

// allowed space for 4 to start:
// 0:  
// 1:  3
// 2:  2, 4
// 3:  1, 3, 5
// 4:  0, 2, 4, 6
// 5:  1, 3, 5
// 6:  0, 2, 4, 6
// 7:  1, 3, 5
// 8:  0, 2, 4, 6
// 9:  1, 3, 5
// 10: 2, 4
// 11: 3
// 12:
// 13:
// 14:

// allowed space for 1: 




void draw_zero(uint8_t x, uint8_t y) {
    for (uint8_t i = 0, i < 5; i++) {
        leds[XY(x,     y + i)] = CRGB(r, g, b);
        leds[XY(x + 1, y + i)] = CRGB(r, g, b);
    }
}

void draw_one(uint8_t x, uint8_t y) {
    for (uint8_t i = 0; i < 5; i++) {
        leds[XY(x, y + i)] = CRGB(r, g, b);
    }
}

void draw_two(uint8_t x, uint8_t y) {
    leds[XY(x    , y    )] = CRGB(r, g, b);
    leds[XY(x + 1, y    )] = CRGB(r, g, b);
    leds[XY(x + 1, y + 1)] = CRGB(r, g, b);
    leds[XY(x + 1, y + 2)] = CRGB(r, g, b);
    leds[XY(x    , y + 2)] = CRGB(r, g, b);
    leds[XY(x    , y + 3)] = CRGB(r, g, b);
    leds[XY(x    , y + 4)] = CRGB(r, g, b);
    leds[XY(x + 1, y + 4)] = CRGB(r, g, b);
}

void draw_three(uint8_t x, uint8_t y) {
    leds[XY(x    , y    )] = CRGB(r, g, b);
    leds[XY(x + 1, y    )] = CRGB(r, g, b);
    leds[XY(x + 1, y + 1)] = CRGB(r, g, b);
    leds[XY(x + 1, y + 2)] = CRGB(r, g, b);
    leds[XY(x    , y + 2)] = CRGB(r, g, b);
    leds[XY(x + 1, y + 3)] = CRGB(r, g, b);
    leds[XY(x    , y + 4)] = CRGB(r, g, b);
    leds[XY(x + 1, y + 4)] = CRGB(r, g, b);
}

void draw_four(uint8_t x, uint8_t y) {
    leds[XY(x    , y    )] = CRGB(r, g, b);
    leds[XY(x + 1, y    )] = CRGB(r, g, b);
    leds[XY(x    , y + 1)] = CRGB(r, g, b);
    leds[XY(x + 1, y + 1)] = CRGB(r, g, b);
    leds[XY(x + 1, y + 2)] = CRGB(r, g, b);
    leds[XY(x + 1, y + 3)] = CRGB(r, g, b);
}

void draw_five(uint8_t x, uint8_t y) {
    leds[XY(x + 1, y    )] = CRGB(r, g, b);
    leds[XY(x    , y    )] = CRGB(r, g, b);
    leds[XY(x    , y + 1)] = CRGB(r, g, b);
    leds[XY(x    , y + 2)] = CRGB(r, g, b);
    leds[XY(x + 1, y + 2)] = CRGB(r, g, b);
    leds[XY(x + 1, y + 3)] = CRGB(r, g, b);
    leds[XY(x + 1, y + 4)] = CRGB(r, g, b);
    leds[XY(x    , y + 4)] = CRGB(r, g, b);
}

void draw_six(uint8_t x, uint8_t y) {
    for (uint8_t i = 0; i < 5; i++) {
        if (i == 1) {
            leds[XY(x, y + 1)] + CRGB(r, g, b);
        }
        else {
            leds[XY(x, y + i)] = CRGB(r, g, b);
            leds[XY(x + 1, y + i)] = CRGB(r, g, b);
        }
    }
}

void draw_seven(uint8_t x, uint8_t y) {
    leds[XY(x    , y    )] = CRGB(r, g, b);
    leds[XY(x + 1, y    )] = CRGB(r, g, b);
    leds[XY(x    , y + 1)] = CRGB(r, g, b);
    leds[XY(x + 1, y + 1)] = CRGB(r, g, b);
    leds[XY(x + 1, y + 2)] = CRGB(r, g, b);
    leds[XY(x + 1, y + 3)] = CRGB(r, g, b);
    leds[XY(x + 1, y + 4)] = CRGB(r, g, b);
}

void draw_eight(uint8_t x, uint8_t y) {
    for (uint8_t i = 0; i < 5; i++) {
        leds[XY(x    , y + i)] = CRGB(r, g, b);
        leds[XY(x + 1, y + i)] = CRGB(r, g, b);
    }
}

void draw_nine(uint8_t x, uint8_t y) {
    for (uint8_t i = 0; i < 5; i++) {
        if (i == 3) {
            leds[XY(x + 1, y + i)] = CRGB(r, g, b);
        }
        else {
            leds[XY(x    , y + i)] = CRGB(r, g, b);
            leds[XY(x + 1, y + i)] = CRGB(r, g, b);
        }
    }
}



/*------------------------------------Hour LEDs------------------------------------*/

void hour12()
{
    draw_one(2, 1);
    draw_two(4, 1);
}
void hour1()
{
    draw_zero(2, 1);
    draw_one(5, 1);
}

void hour2()
{
    draw_zero(2, 1);
    draw_two(4, 1);
}
void hour3()
{
    draw_zero(2, 1);
    draw_three(4, 1);
}
void hour4()
{
    draw_zero(2, 1);
    draw_four(4, 2);
}
void hour5()
{
    draw_zero(2, 1);
    draw_five(4, 1);
}
void hour6()
{
    draw_zero(2, 1);
    draw_six(4, 1);
}
void hour7()
{
    draw_zero(2, 1);
    draw_seven(4, 1);
}
void hour8()
{
    draw_zero(2, 1);
    draw_eight(4, 1);
}
void hour9()
{
    draw_zero(2, 1);
    draw_nine(4, 1);
}
void hour10()
{
    draw_one(2, 1);
    draw_zero(4, 1);
}
void hour11()
{
    draw_one(2, 1);
    draw_one(4, 1);
}



/*----------------------------Minutes LEDs----------------------------*/
void min0()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min1()
{
    leds[56] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
}
void min2()
{
    leds[55] = CRGB(r, g, b);
    leds[56] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
}
void min3()
{
    leds[55] = CRGB(r, g, b);
    leds[56] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
}
void min4()
{
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
}
void min5()
{
    leds[55] = CRGB(r, g, b);
    leds[56] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
}
void min6()
{
    leds[55] = CRGB(r, g, b);
    leds[56] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
}
void min7()
{
    leds[55] = CRGB(r, g, b);
    leds[56] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
}
void min8()
{
    leds[55] = CRGB(r, g, b);
    leds[56] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
}
void min9()
{
    leds[55] = CRGB(r, g, b);
    leds[56] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
}
void min10()
{
    leds[62] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min11()
{
    leds[62] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
}
void min12()
{
    leds[62] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min13()
{
    leds[62] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min14()
{
    leds[62] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min15()
{
    leds[62] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min16()
{
    leds[62] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min17()
{
    leds[62] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min18()
{
    leds[62] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min19()
{
    leds[62] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min20()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min21()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min22()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min23()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min24()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min25()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min26()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min27()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min28()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min29()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min30()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min31()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min32()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min33()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min34()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min35()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min36()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min37()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min38()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min39()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min40()
{
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min41()
{
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min42()
{
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min43()
{
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min44()
{
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min45()
{
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min46()
{
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min47()
{
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min48()
{
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min49()
{
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[72] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min50()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min51()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min52()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min53()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min54()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min55()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min56()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min57()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min58()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min59()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[80] = CRGB(r, g, b);
    leds[81] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}
void min60()
{
    leds[62] = CRGB(r, g, b);
    leds[63] = CRGB(r, g, b);
    leds[64] = CRGB(r, g, b);
    leds[65] = CRGB(r, g, b);
    leds[70] = CRGB(r, g, b);
    leds[71] = CRGB(r, g, b);
    leds[73] = CRGB(r, g, b);
    leds[78] = CRGB(r, g, b);
    leds[79] = CRGB(r, g, b);
    leds[85] = CRGB(r, g, b);
    leds[86] = CRGB(r, g, b);
    leds[87] = CRGB(r, g, b);
    leds[88] = CRGB(r, g, b);
    leds[90] = CRGB(r, g, b);
    leds[91] = CRGB(r, g, b);
    leds[92] = CRGB(r, g, b);
    leds[93] = CRGB(r, g, b);
}



#endif

