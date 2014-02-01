
#ifndef PATTERNS_H
#define PATTERNS_H

#include "LEDFader.h"  // for rgb_t

struct patt_line_t {
    rgb_t color;
    uint16_t dmillis; // hundreths of a sec
    uint16_t ledn;     // number of led, or 0 for all
};

struct patt_info_t { 
    uint8_t id;
    uint8_t reps;
    uint8_t start;
    uint8_t end;
    uint8_t count;
};

// can't declare these statically because Arduino loader doesn't send eeprom
//pattern_t pattern_ee EEMEM; 
uint8_t     ee_i2c_addr   EEMEM = 0x09; //I2C_ADDR;
uint8_t     ee_mode       EEMEM = 0x00; //BOOT_PLAY_SCRIPT;
patt_info_t ee_patt_info  EEMEM;
//uint8_t ee_patt_id    EEMEM = 0x00;
//uint8_t ee_reps       EEMEM = 0x00;
//uint8_t ee_playstart  EEMEM = 0x00;
//uint8_t ee_playend    EEMEM = 0x00;

patt_line_t ee_patt_lines[patt_max] EEMEM;

patt_line_t patt_lines_default[] PROGMEM  = {
    //    R     G     B    fade ledn
    { { 0x11, 0x00, 0x00 }, 50, 0 }, // 0  red A
    { { 0x73, 0x00, 0x00 }, 50, 0 }, // 1  red B
    { { 0x00, 0x00, 0x00 }, 50, 0 }, // 2  off both
    { { 0x00, 0x11, 0x00 }, 50, 0 }, // 3  grn A
    { { 0x00, 0x73, 0x00 }, 50, 0 }, // 4  grn B
    { { 0x00, 0x00, 0x00 }, 50, 0 }, // 5  off both
    { { 0x00, 0x00, 0x11 }, 50, 0 }, // 6  blu A
    { { 0x00, 0x00, 0x73 }, 50, 0 }, // 7  blu B
    { { 0x00, 0x00, 0x00 },100, 0 }, // 8  off both
    { { 0x10, 0x10, 0x10 }, 50, 0 }, // 9  half-bright, both LEDs
    { { 0x00, 0x00, 0x00 }, 50, 0 }, // 10 off both
    { { 0x11, 0x11, 0x11 }, 50, 0 }, // 11 white A
    { { 0x20, 0x20, 0x20 }, 50, 0 }, // 12 off A
    { { 0x30, 0x30, 0x30 }, 50, 0 }, // 13 white B
    { { 0x40, 0x40, 0x40 }, 50, 0 }, // 14 off B
    { { 0x00, 0x00, 0x00 }, 50, 0 }, // 15 off everyone
};

/*
patt_line_t patt_lines_default[] PROGMEM = {
    //    G     R     B    fade ledn
    { { 0x00, 0x11, 0x00 },  100, 0 }, // 0  red A
    { { 0x00, 0x11, 0x00 },  100, 0 }, // 1  red B
    { { 0x00, 0x00, 0x00 },  100, 0 }, // 2  off both
    { { 0x11, 0x00, 0x00 },  100, 0 }, // 3  grn A
    { { 0x11, 0x00, 0x00 },  100, 0 }, // 4  grn B
    { { 0x00, 0x00, 0x00 },  100, 0 }, // 5  off both
    { { 0x00, 0x00, 0x11 },  100, 0 }, // 6  blu A
    { { 0x00, 0x00, 0x11 },  100, 0 }, // 7  blu B
    { { 0x00, 0x00, 0x00 },  100, 0 }, // 8  off both
    { { 0x10, 0x10, 0x10 }, 100, 0 }, // 9  half-bright, both LEDs
    { { 0x00, 0x00, 0x00 }, 100, 0 }, // 10 off both
    { { 0x11, 0x11, 0x11 },  50, 0 }, // 11 white A
    { { 0x00, 0x00, 0x00 },  50, 0 }, // 12 off A
    { { 0x7f, 0x7f, 0x7f },  50, 0 }, // 13 white B
    { { 0x00, 0x00, 0x00 }, 100, 0 }, // 14 off B
    { { 0x00, 0x00, 0x00 }, 100, 0 }, // 15 off everyone
};
*/

#if 0
patt_line_t patt_lines_default[] PROGMEM = {
    //    G     R     B    fade ledn
    { { 0x00, 0x11, 0x00 },  100, 1 }, // 0  red A
    { { 0x00, 0x11, 0x00 },  100, 2 }, // 1  red B
    { { 0x00, 0x00, 0x00 },  100, 0 }, // 2  off both
    { { 0x11, 0x00, 0x00 },  100, 1 }, // 3  grn A
    { { 0x11, 0x00, 0x00 },  100, 2 }, // 4  grn B
    { { 0x00, 0x00, 0x00 },  100, 0 }, // 5  off both
    { { 0x00, 0x00, 0x11 },  100, 1 }, // 6  blu A
    { { 0x00, 0x00, 0x11 },  100, 2 }, // 7  blu B
    { { 0x00, 0x00, 0x00 },  100, 0 }, // 8  off both
    { { 0x10, 0x10, 0x10 }, 100, 0 }, // 9  half-bright, both LEDs
    { { 0x00, 0x00, 0x00 }, 100, 0 }, // 10 off both
    { { 0x11, 0x11, 0x11 },  50, 1 }, // 11 white A
    { { 0x00, 0x00, 0x00 },  50, 1 }, // 12 off A
    { { 0x7f, 0x7f, 0x7f },  50, 2 }, // 13 white B
    { { 0x00, 0x00, 0x00 }, 100, 2 }, // 14 off B
    { { 0x00, 0x00, 0x00 }, 100, 0 }, // 15 off everyone
};
#endif

patt_line_t patt_lines_rgb[] PROGMEM = {
    { { 0x33, 0x00, 0x00 },  50, 0b0110110110110110 }, // 0  red all
    { { 0x00, 0x33, 0x00 },  50, 0b1010101010101010 }, // 1  grn all
    { { 0x00, 0x00, 0x33 },  50, 0b0001000100010001 }, // 2  blu all
};

patt_line_t patt_lines_blink_white[] PROGMEM = {
    { { 0x33, 0x33, 0x33 },  50, 0 }, // 0  white all
    { { 0x00, 0x00, 0x00 },  50, 0 }, // 1  off all
};

patt_line_t patt_lines_stoplight[] PROGMEM = {
    { { 0x00, 0x33, 0x00 },  50, 0 }, // 0  red
    { { 0xdd, 0x11, 0x00 },  50, 0 }, // 1  yellow
    { { 0x00, 0x33, 0x11 },  50, 0 }, // 1  greenblue
};

patt_line_t* patterns[] PROGMEM = {
    (patt_line_t*) &patt_lines_default,
    (patt_line_t*) &patt_lines_rgb,
    (patt_line_t*) &patt_lines_blink_white,
    (patt_line_t*) &patt_lines_stoplight,
};

// this is so lame, but can't create a flexible array of patt_lines in a struct
int patt_lens[] PROGMEM = {
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
