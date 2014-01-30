
#ifndef PATTERNS_H
#define PATTERNS_H

#include "LEDFader.h"  // for rgb_t

struct patternline_t {
    rgb_t color;
    uint16_t dmillis; // hundreths of a sec
    uint8_t ledn;     // number of led, or 0 for all
};


// can't declare these statically because Arduino loader doesn't send eeprom
//pattern_t pattern_ee EEMEM; 
patternline_t patternlines_ee[patt_max] EEMEM;

patternline_t patternlines_default[] PROGMEM = {
    //    G     R     B    fade ledn
    { { 0x00, 0x11, 0x00 },  100, 1 }, // 0  red A
    { { 0x00, 0xff, 0x00 },  100, 2 }, // 1  red B
    { { 0x00, 0x00, 0x00 },  100, 0 }, // 2  off both
    { { 0xff, 0x00, 0x00 },  100, 1 }, // 3  grn A
    { { 0x11, 0x00, 0x00 },  100, 2 }, // 4  grn B
    { { 0x00, 0x00, 0x00 },  100, 0 }, // 5  off both
    { { 0x00, 0x00, 0xff },  100, 1 }, // 6  blu A
    { { 0x00, 0x00, 0xff },  100, 2 }, // 7  blu B
    { { 0x00, 0x00, 0x00 },  100, 0 }, // 8  off both
    { { 0x10, 0x10, 0x10 }, 100, 0 }, // 9  half-bright, both LEDs
    { { 0x00, 0x00, 0x00 }, 100, 0 }, // 10 off both
    { { 0x11, 0x11, 0x11 },  50, 1 }, // 11 white A
    { { 0x00, 0x00, 0x00 },  50, 1 }, // 12 off A
    { { 0xff, 0xff, 0xff },  50, 2 }, // 13 white B
    { { 0x00, 0x00, 0x00 }, 100, 2 }, // 14 off B
    { { 0x00, 0x00, 0x00 }, 100, 0 }, // 15 off everyone
};

patternline_t patternlines_rgb[] PROGMEM = {
    { { 0x00, 0x11, 0x00 },  50, 0 }, // 0  red all
    { { 0x11, 0x00, 0x00 },  50, 0 }, // 1  grn all
    { { 0x00, 0x00, 0x11 },  50, 0 }, // 2  blu all
};

patternline_t patternlines_blink_white[] PROGMEM = {
    { { 0x11, 0x11, 0x11 },  50, 0 }, // 0  white all
    { { 0x00, 0x00, 0x00 },  50, 0 }, // 1  off all
};

patternline_t patternlines_stoplight[] PROGMEM = {
    { { 0x00, 0x11, 0x00 },  50, 0 }, // 0  red
    { { 0xdd, 0x11, 0x00 },  50, 0 }, // 1  yellow
    { { 0x11, 0x00, 0x11 },  50, 0 }, // 1  greenblue
};

patternline_t** patterns[] PROGMEM = {
    (patternline_t**) &patternlines_default,
    (patternline_t**) &patternlines_rgb,
    (patternline_t**) &patternlines_blink_white,
    (patternline_t**) &patternlines_stoplight,
};

// this is so lame, but can't create a flexible array of patternlines in a struct
int pattern_lens[] PROGMEM = {
    16,
    3,
    2,
    3,
};


#endif

/*
// this does not work
struct pattern_t {
    uint8_t len;  // number of script lines, 0 == blank script, not playing
    patternline_t lines[];
};
static const pattern_t pattern_default PROGMEM  = { 
    3, 
    //(patternline_t[3])
    {
        { { 0x00, 0xff, 0x00 },  50, 0 }, // 0  red all
        { { 0xff, 0x00, 0x00 },  50, 0 }, // 1  grn all
        { { 0x00, 0x00, 0xff },  50, 0 }, // 2  blu all
    }
};
*/


/*
typedef struct {
    uint8_t len;  // number of script lines, 0 == blank script, not playing
    patternline_t lines[];
} pattern2_t;

pattern_t patterntoo PROGMEM = { 
    3, 
    (patternline_t[3]) 
    {
        { { 0x00, 0xff, 0x00 },  50, 0 }, // 0  red all
        { { 0xff, 0x00, 0x00 },  50, 0 }, // 1  grn all
        { { 0x00, 0x00, 0xff },  50, 0 }, // 2  blu all
    },
};
*/
