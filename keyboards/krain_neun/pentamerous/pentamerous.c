#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
    /* Layout
     *         0     16     32     48     64     80     96              128    144    160    176    192    208    224    
     *     +----------------------------------+                                     +----------------------------------+
     *   0 |  15  |  16  |  17  |  18  |  19  |                                     |  41  |  40  |  39  |  38  |  37  |
     *     +----------------------------------+                                     +----------------------------------+
     *  16 |  14  |  13  |  12  |  11  |  10  |                                     |  32  |  33  |  34  |  35  |  36  |
     *     +----------------------------------+                                     +----------------------------------+
     *  32 |   5  |   6  |   7  |   8  |   9  |                                     |  31  |  30  |  29  |  28  |  27  |
     *     +----------------------------------+                                     +----------------------------------+
     *  48        |  20  |  21  |                                                                 |  42  |  43  | 
     *            +-------------+      +--------------------+         +--------------------+      +-------------|
     *  48                             |   0  |   1  |   2  |         |  24  |  23  |  22  |
     *                                 +--------------------|         |--------------------+
     *  64                                    |   4  |   3  |         |  25  |  26  |
     *                                        +-------------+         +-------------+
     */
led_config_t g_led_config = {
    {
        // LED index to key matrix.
        // Left
        {       15,     16,     17,     18,     19},
        {       14,     13,     12,     11,     10},
        {        5,      6,      7,      8,      9},
        {        4,      3,      0,      1,      2},
        {   NO_LED,     20,      21, NO_LED, NO_LED},
        // Right
        {       41,     40,     39,     38,     37},
        {       32,     33,     34,     35,     36},
        {       31,     30,     29,     28,     27},
        {       24,     23,     22,     25,     26},
        {   NO_LED, NO_LED,     42, NO_LED,     43},
    }, 
    {
        // LED index to physical position.
        // Left
        // index: 0-2
        {  64,  48 }, {  80,  48 }, {  96,  48 },
        // index: 3-4
        {  96,  64 }, {  80,  64 },
        // index: 5-9
        {   0,  32 }, {  16,  32 }, {  32,  32 }, {  48,  32 }, {  64,  32 },
        // index: 10-14
        {  64,  16 }, {  48,  16 }, {  32,  16 }, {  16,  16 }, {   0,  16 },
        // index: 15-19
        {   0,   0 }, {  16,   0 }, {  32,   0 }, {  48,   0 }, {  64,   0 },
        // index: 20-21
        {  16,  48 }, {  32,  48 },
        // Right
        // index: 22-24
        { 160,  48 }, { 144,  48 }, { 128,  48 },
        // index: 25-26
        { 128,  64 }, { 144,  64 },
        // index: 27-31
        { 224,  32 }, { 208,  32 }, { 192,  32 }, { 176,  32 }, { 160,  32 },
        // index: 32-36
        { 160,  16 }, { 176,  16 }, { 192,  16 }, { 208,  16 }, { 224,  16 },
        // index: 37-41
        { 224,   0 }, { 208,   0 }, { 192,   0 }, { 176,   0 }, { 160,   0 },
        // index: 42-43
        { 192,  48 }, { 208,  48 },
    },
    {
        // Left
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        // Right
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
    }
};
#endif
