#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
    /* LED index
     *          0     16     32     48     64     80     96    112      128    144    160    176    192    208     224    240   
     *      +-----------------------------------------+                             +-----------------------------------------+
     *   0  |  20  |  21  |  22  |  23  |  24  |  25  |                             |  48  |  47  |  46  |  45  |  44  |  43  |
     *      |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     *  12  |  19  |  18  |  17  |  16  |  15  |  14  |                             |  37  |  38  |  39  |  40  |  41  |  42  |
     *      |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     *  24  |   8  |   9  |  10  |  11  |  12  |  13  |                             |  36  |  35  |  34  |  33  |  32  |  31  |
     *      +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *  36                |   7  |   6  | 
     *                    +-------------+-------------+                             +------+
     *  48                              |   0  |   1  |                             |  26  |
     *                                  +-------------+                             +------+
     *                                                +-------------+ +-------------+
     *  56                                            |   2  |   3  | |  28  |  27  |
     *                                                |------+------| |------+------|
     *  64                                            |   5  |   4  | |  29  |  30  |
     *                                                +-------------+ +-------------+
     */
led_config_t g_led_config = {
    {
        // LED index to key matrix.
        // Left
        {       20,     21,     22,     23,     24,     25 },
        {       19,     18,     17,     16,     15,     14 },
        {        8,      9,     10,     11,     12,     13 },
        {   NO_LED, NO_LED,      7,      6,      0,      1 },
        {   NO_LED, NO_LED,      5,      4,      3,      2 },
        // Right
        {       48,     47,     46,     45,     44,     43 },
        {       37,     38,     39,     40,     41,     42 },
        {       36,     35,     34,     33,     32,     31 },
        {       26, NO_LED, NO_LED, NO_LED, NO_LED, NO_LED },
        {       27,     28,     29,     30, NO_LED, NO_LED },
    }, 
    {
        // LED index to physical position.
        // Left
        // index: 0-1
        {  64,  48 }, {  80,  48 },
        // index: 2-3
        {  96,  56 }, { 112,  56 }, 
        // index: 4-5
        { 112,  64 }, {  96,  64 },
        // index: 6-7
        {  48,  36 }, {  32,  36 },
        // index: 8-13
        {   0,  24 }, {  16,  24 }, {  32,  24 }, {  48,  24 }, {  64,  24 }, {  80,  24 },
        // index: 14-19
        {  80,  12 }, {  64,  12 }, {  48,  12 }, {  32,  12 }, {  16,  12 }, {   0,  12 },
        // index: 20-25
        {   0,   0 }, {  16,   0 }, {  32,   0 }, {  48,   0 }, {  64,   0 }, {  80,   0 },
        // Right
        // index: 26
        { 160,  48 },
        // index: 27-28
        { 144,  56 }, { 128,  56 },
        // index: 29-30
        { 128,  64 }, { 144,  64 },
        // index: 31-36
        { 240,  24 }, { 224,  24 }, { 208,  24 }, { 192,  24 }, { 176,  24 }, { 160,  24 },
        // index: 37-42
        { 160,  12 }, { 176,  12 }, { 192,  12 }, { 208,  12 }, { 224,  12 }, { 240,  12 },
        // index: 43-48
        { 240,   0 }, { 224,   0 }, { 208,   0 }, { 192,   0 }, { 176,   0 }, { 160,   0 },
    },
    {
        // Left
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        // Right
        LED_FLAG_MODIFIER,
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    }
};
#endif