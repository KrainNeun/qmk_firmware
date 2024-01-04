#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE
    /* Layout
     *         0     16     32     48     64     80     96              128    144    160    176    192    208    224    
     *     +----------------------------------+                                     +----------------------------------+
     *   0 |  15  |  16  |  17  |  18  |  19  |                                     |  39  |  38  |  37  |  36  |  35  |
     *     |------+------+------+------+------|                                     |------+------+------+------+------|
     *  16 |  14  |  13  |  12  |  11  |  10  |                                     |  30  |  31  |  32  |  33  |  34  |
     *     |------+------+------+------+------|                                     |------+------+------+------+------|
     *  32 |   5  |   6  |   7  |   8  |   9  |                                     |  29  |  28  |  27  |  26  |  25  |
     *     +----------------------------------+                                     +----------------------------------+
     *                                 +--------------------+         +--------------------+
     *  48                             |   0  |   1  |   2  |         |  22  |  21  |  20  |
     *                                 +------+------+------|         |------+------+------|
     *  64                                    |   4  |   3  |         |  23  |  24  |
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
        // Righ
        {       39,     38,     37,     36,     35},
        {       30,     31,     32,     33,     34},
        {       29,     28,     27,     26,     25},
        {       22,     21,     20,     23,     24},
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
        // Right
        // index: 20-22
        { 160,  48 }, { 144,  48 }, { 128,  48 },
        // index: 23-24
        { 128,  64 }, { 144,  64 },
        // index: 25-29
        { 224,  32 }, { 208,  32 }, { 192,  32 }, { 176,  32 }, { 160,  32 },
        // index: 30-34
        { 160,  16 }, { 176,  16 }, { 192,  16 }, { 208,  16 }, { 224,  16 },
        // index: 35-39
        { 224,   0 }, { 208,   0 }, { 192,   0 }, { 176,   0 }, { 160,   0 },
    },
    {
        // Left
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        // Right
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_MODIFIER, LED_FLAG_MODIFIER,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
        LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT, LED_FLAG_KEYLIGHT,
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