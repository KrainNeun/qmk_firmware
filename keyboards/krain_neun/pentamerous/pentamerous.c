#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
    /* Layout
     *         0     16     32     48     64     80     96              128    144    160    176    192    208    224    
     *     +----------------------------------+                                     +----------------------------------+
     *   0 |  14  |  15  |  16  |  17  |  18  |                                     |  37  |  36  |  35  |  34  |  33  |
     *     +----------------------------------+                                     +----------------------------------+
     *  16 |  13  |  12  |  11  |  10  |   9  |                                     |  28  |  29  |  30  |  31  |  32  |
     *     +----------------------------------+                                     +----------------------------------+
     *  32 |   4  |   5  |   6  |   7  |   8  |                                     |  27  |  26  |  25  |  24  |  23  |
     *     +----------------------------------+                                     +----------------------------------+
     *            +-------------+      +--------------------+         +--------------------+      +-------------|
     *  48                             |   0  |   1  |   2  |         |  21  |  20  |  19  |
     *                                 +--------------------|         |--------------------+
     *  64                                           |   3  |         |  22  |
     *                                               -------+         +-------
     */
led_config_t g_led_config = {
    {
        // LED index to key matrix.
        // Left
        {       14,     15,     16,     17,     18},
        {       13,     12,     11,     10,      9},
        {        4,      5,      6,      7,      8},
        {        0,      1,      2,      3,     NO_LED},
        // Right
        {       37,     36,     35,     34,     33},
        {       28,     29,     30,     31,     32},
        {       27,     26,     25,     24,     23},
        {   NO_LED,     22,     21,     20,     19},
    }, 
    {
        // LED index to physical position.
        // Left
        // index: 0-2
        {  64,  48 }, {  80,  48 }, {  96,  48 },
        // index: 3-4
        {  96,  64 }, 
        // index: 5-9
        {   0,  32 }, {  16,  32 }, {  32,  32 }, {  48,  32 }, {  64,  32 },
        // index: 10-14
        {  64,  16 }, {  48,  16 }, {  32,  16 }, {  16,  16 }, {   0,  16 },
        // index: 15-19
        {   0,   0 }, {  16,   0 }, {  32,   0 }, {  48,   0 }, {  64,   0 },
        // Right
        // index: 22-24
        { 160,  48 }, { 144,  48 }, { 128,  48 },
        // index: 25-26
        { 128,  64 }, 
        // index: 27-31
        { 224,  32 }, { 208,  32 }, { 192,  32 }, { 176,  32 }, { 160,  32 },
        // index: 32-36
        { 160,  16 }, { 176,  16 }, { 192,  16 }, { 208,  16 }, { 224,  16 },
        // index: 37-41
        { 224,   0 }, { 208,   0 }, { 192,   0 }, { 176,   0 }, { 160,   0 },
    },
    {
        // Left
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_MODIFIER,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        // Right
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_MODIFIER,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    }
};
#endif
