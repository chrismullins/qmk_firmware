#include QMK_KEYBOARD_H

#define _BL 0
#define _AL 1
#define _FL 2
#define _UL 3

#define TAB_ESC ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC)
//Tap Dance Declarations
enum {
  TD_TAB_ESC = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_TAB_ESC]  = ACTION_TAP_DANCE_DOUBLE(KC_TAB, KC_ESC)
// Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BL] = LAYOUT(
        TD(TD_TAB_ESC),  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_LCTL,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_RSFT,
        MO(_AL), KC_LALT, KC_LALT, KC_LGUI, KC_SPC,  _______,  KC_SPC, KC_DOWN, KC_UP, MO(_AL)
    ),

    [_AL] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,   KC_6,   KC_7,    KC_8,   KC_9,   KC_0,  KC_BSLASH,
        KC_TAB,  _______, _______, _______, _______, _______,KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_SCLN,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_QUOT, KC_MINS, KC_SLSH,
        _______, _______, _______, _______, TG(_UL), TG(_UL), _______, KC_LBRC, KC_RBRC, MO(_FL)
    ),

    [_FL] = LAYOUT(
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10, KC_F11,
        KC_F12,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_UL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_TOG, RGB_MOD, RGB_VAD, RGB_VAI, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};

void matrix_scan_user(void) {
  // Layer LED indicators
  // ESC led on when in function layer, WASD cluster leds enabled when on arrow cluster
  uint32_t layer = layer_state;
  if (layer & (1 << 1)) {
      //gh60_wasd_leds_on();
  } else {
      //gh60_wasd_leds_off();
  }

  if (layer & (1 << 2)) {
      //gh60_esc_led_on();
  } else {
      //gh60_esc_led_off();
  }
};
