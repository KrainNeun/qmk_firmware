#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
    /* LED index
     *          0     16     32     48     64     80     96    112      128    144    160    176    192    208     224    240   
     *      +-----------------------------------------+                             +-----------------------------------------+
     *   0  |  21  |  22  |  23  |  24  |  25  |  26  |                             |  51  |  50  |  49  |  48  |  47  |  46  |
     *      |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     *  12  |  20  |  19  |  18  |  17  |  16  |  15  |                             |  40  |  41  |  42  |  43  |  44  |  45  |
     *      |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     *  24  |   9  |  10  |  11  |  12  |  13  |  14  |                             |  39  |  38  |  37  |  36  |  35  |  34  |
     *      +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *  36         |   8  |   7  |   6  |                                                                       |  33  |
     *             +------+-------------+-------------+                             +------+------+--------------------+
     *  48                              |   0  |   1  |                             |  28  |  27  |
     *                                  +-------------+                             +------+------+
     *                                                +-------------+ +-------------+
     *  56                                            |   2  |   3  | |  30  |  29  |
     *                                                |------+------| |------+------|
     *  64                                            |   5  |   4  | |  31  |  32  |
     *                                                +-------------+ +-------------+
     */
led_config_t g_led_config = {
    {
        // LED index to key matrix.
        // Left
        {       21,     22,     23,     24,     25,     26 },
        {       20,     19,     18,     17,     16,     15 },
        {        9,     10,     11,     12,     13,     14 },
        {   NO_LED,      8,      7,      6,      0,      1 },
        {   NO_LED, NO_LED,      5,      4,      3,      2 },
        // Right
        {       51,     50,     49,     48,     47,     46 },
        {       40,     41,     42,     43,     44,     45 },
        {       39,     38,     37,     36,     35,     34 },
        {       28,     27, NO_LED, NO_LED,     33, NO_LED },
        {       29,     30,     31,     32, NO_LED, NO_LED },
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
        // index: 6-8
        {  48,  36 }, {  32,  36 }, {  16,  36 },
        // index: 9-14
        {   0,  24 }, {  16,  24 }, {  32,  24 }, {  48,  24 }, {  64,  24 }, {  80,  24 },
        // index: 15-20
        {  80,  12 }, {  64,  12 }, {  48,  12 }, {  32,  12 }, {  16,  12 }, {   0,  12 },
        // index: 21-26
        {   0,   0 }, {  16,   0 }, {  32,   0 }, {  48,   0 }, {  64,   0 }, {  80,   0 },
        // Right
        // index: 27-28
        { 176,  48 }, { 160,  48 },
        // index: 29-30
        { 144,  56 }, { 128,  56 },
        // index: 31-32
        { 128,  64 }, { 144,  64 },
        // index: 33
        { 224,  36 },
        // index: 34-39
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
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        // Right
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
    }
};
#endif

void pointing_device_init_kb(void) {
    pointing_device_set_cpi(1250);
}

report_mouse_t pointing_device_task_kb(report_mouse_t mouse_report) {

    double rad = 30 * (M_PI / 180) * -1;
    int8_t x_rev =  + mouse_report.x * cos(rad) - mouse_report.y * sin(rad);
    int8_t y_rev =  + mouse_report.x * sin(rad) + mouse_report.y * cos(rad);

    mouse_report.x = x_rev;
    mouse_report.y = y_rev;
    
    return pointing_device_task_user(mouse_report);
}