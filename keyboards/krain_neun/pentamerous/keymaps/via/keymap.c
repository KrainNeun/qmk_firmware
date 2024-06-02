#include QMK_KEYBOARD_H

enum layers {
    _BASE = 0,
    _LAYER1 = 1,
    _LAYER2 = 2,
    _LAYER3 = 3,
    _LAYER4 = 4,
    _HUB = 5,
};

#define BASE   MO(_BASE)
#define LAYER1 MO(_LAYER1)
#define LAYER2 MO(_LAYER2)
#define LAYER3 MO(_LAYER3)
#define LAYER4 MO(_LAYER4)
#define HUB MO(_HUB)
#define ST_LBRC S(KC_LBRC)
#define ST_RBRC S(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layout
     *         0     16     32     48     64     80     96              128    144    160    176    192    208    224    
     *     +----------------------------------+                                     +----------------------------------+
     *   0 |      |      |      |      |      |                                     |      |      |      |      |      |
     *     +----------------------------------+                                     +----------------------------------+
     *  16 |      |      |      |      |      |                                     |      |      |      |      |      |
     *     +----------------------------------+                                     +----------------------------------+
     *  32 |      |      |      |      |      |                                     |      |      |      |      |      |
     *     +----------------------------------+                                     +----------------------------------+
     *                                 +--------------------+         +--------------------+ 
     *  48                             |      |      |      |         |      |      |      |
     *                                 +--------------------|         |--------------------+
     *  64                                           |      |         |      | 
     *                                               -------+         +-------
     */
    [_BASE] = LAYOUT(
           KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                                   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
           KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                                   KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,
           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                                   KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,
                                             KC_SPC, KC_LCMD, KC_LSFT,             KC_BSPC,  KC_ENT, HUB, 
                                                               LAYER1,             LAYER1
    ),

    [_LAYER1] = LAYOUT(
           KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                                   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
         KC_GRV, ST_LBRC, ST_RBRC, KC_LBRC, KC_RBRC,                                                KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______,
        _______, _______, _______, S(KC_9), S(KC_0),                                                KC_MINS,  KC_EQL, _______, _______, _______,
                                             KC_TAB, _______, _______,            _______, KC_BSPC,  _______,
                                                              _______,            _______
    ),

    [_LAYER2] = LAYOUT(
        _______, _______, _______, _______, _______,                                                _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                _______, _______, _______, _______, _______,
                                            _______, _______, _______,            _______, _______, _______,
                                                              _______,            _______
    ),

    [_LAYER3] = LAYOUT(
        _______, _______, _______, _______, _______,                                                _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                _______, _______, _______, _______, _______,
                                            _______, _______, _______,            _______, _______, _______,
                                                              _______,            _______
    ),

    [_LAYER4] = LAYOUT(
        _______, _______, _______, _______, _______,                                                _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                _______, _______, _______, _______, _______,
                                            _______, _______, _______,            _______, _______, _______,
                                                              _______,            _______
    ),

    [_HUB] = LAYOUT(
        _______, _______, _______, _______, _______,                                                _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,                                                _______, _______, _______, _______, _______,
                                            _______, _______, _______,            _______, _______, _______,
                                                              _______,            _______
    )
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _LAYER1:
            rgb_matrix_sethsv_noeeprom(HSV_BLUE);
            break;

        case _LAYER2:
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
            break;

        case _LAYER3:
            rgb_matrix_sethsv_noeeprom(HSV_ORANGE);
            break;

        case _LAYER4:
            rgb_matrix_sethsv_noeeprom(HSV_RED);
            break;

        case _HUB:
            rgb_matrix_sethsv_noeeprom(HSV_CORAL);
            break; 

        default:
            rgb_matrix_sethsv_noeeprom(HSV_MAGENTA);
            break;
    }
  return state;
};

void keyboard_post_init_user(void) {
    pointing_device_set_cpi_on_side(true, 1000); //Set cpi on left side to a low value for slower scrolling.
    pointing_device_set_cpi_on_side(false, 2500); //Set cpi on right side to a reasonable value for mousing.
}

report_mouse_t pointing_device_task_combined_user(report_mouse_t left_report, report_mouse_t right_report) {
    left_report.h = left_report.x;
    left_report.v = left_report.y;
    left_report.x = 0;
    left_report.y = 0;
    return pointing_device_combine_reports(left_report, right_report);
}