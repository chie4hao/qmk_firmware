#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( //  default layer
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_NO, KC_NO,
        MT(MOD_LCTL,KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(2,KC_SCLN), MT(MOD_RCTL,KC_QUOT), KC_NO,
        OSM(MOD_LSFT), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, LT(1,KC_SLSH), KC_SFTENT, KC_NO,
        KC_LGUI, KC_LALT, /*        */ LT(3,KC_SPC), MO(4), KC_RGUI),
    /*
    [1] = LAYOUT(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_CAPS, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, KC_NO, KC_NO,
        KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END, KC_PGDN, KC_DOWN, KC_TRNS, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    */
    // slash
    [1] = LAYOUT(
                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                 KC_TAB , KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP, KC_NO, KC_NO,
                 KC_LCTL, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, KC_NO,
                 KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PSCR, KC_SLCK, KC_PAUS, KC_NO  , KC_RSFT, KC_NO,
                 KC_LGUI, KC_LALT, KC_SPC , KC_RALT, KC_RGUI),
    // scolon
    [2] = LAYOUT(
                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                 KC_GRV , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_NO  , KC_NO  , KC_BSPC, KC_DEL , KC_NO  , KC_NO  , KC_NO  , KC_NO, KC_NO,
                 KC_LCTL, KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_NO  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_NO  , KC_NO  , KC_NO,
                 KC_LSFT, KC_F9  , KC_F10 , KC_F11 , KC_F12 , KC_NO  , KC_HOME, KC_PGUP, KC_PGDN, KC_END , KC_NO  , KC_RSFT, KC_NO,
                 KC_LGUI, KC_LALT, KC_SPC , KC_RALT, KC_RGUI),
    // space
    [3] = LAYOUT(
                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                 KC_GRV , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_PAST, KC_LPRN, KC_RPRN, KC_BSPC, KC_NO, KC_NO,
                 KC_LCTL, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS, KC_NO,
                 KC_LSFT, KC_TILD, KC_PIPE, KC_LBRC, KC_RBRC, KC_UNDS, KC_PLUS, KC_MINS, KC_EQL , KC_DOT , KC_SLSH, KC_RSFT, KC_NO,
                 KC_LGUI, KC_LALT, KC_SPC , KC_RALT, KC_RGUI),
    // mouse
    [4] = LAYOUT(
                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                 KC_GRV , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_WH_D, KC_MS_U, KC_WH_U, KC_NO, KC_NO,
                 KC_LCTL, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1,
                 KC_LSFT, KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_NO  , KC_ACL0, KC_ACL1, KC_ACL2, KC_NO,
                 KC_LGUI, KC_LALT, KC_SPC , KC_RALT, KC_RGUI),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch (id)
    {
    case 0:
      if (record->event.pressed)
        {
          register_code(KC_RSFT);
        }
      else
        {
          unregister_code(KC_RSFT);
        }
      break;
    }
  return MACRO_NONE;
};
