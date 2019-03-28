#include "kb.h"

#define SFTENT KC_SFTENT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    KEYMAP( //  default layer
                 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_RBRC,
                 MT(MOD_LCTL,KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(2,KC_SCLN), MT(MOD_RCTL,KC_QUOT),
                 MT(MOD_LSFT,KC_LBRC), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, LT(1,KC_SLSH), SFTENT,
                 KC_NO,   KC_NO,   KC_LALT, KC_LGUI, OSM(MOD_LSFT), LT(3,KC_SPC), MO(4), KC_RGUI,KC_NO,KC_NO),
    // slash
    KEYMAP(
                 KC_TRNS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_NO  , KC_TRNS,
                 KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_F10 , KC_TRNS, KC_APP , KC_TRNS, KC_TRNS, KC_NO  , KC_TRNS,
                 KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_F11 , KC_F12 , KC_INS , KC_PSCR, KC_SLCK, KC_PAUS, KC_NO  , KC_TRNS,
                 KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_RALT, KC_RGUI, KC_NO  , KC_NO),
    // scolon
    KEYMAP(
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_DEL , KC_NO  , KC_NO  , KC_NO,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_NO  , KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_NO  , KC_TRNS,
                 KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_RALT, KC_RGUI, KC_NO  , KC_NO),
    // space
    KEYMAP(
                 KC_GRV , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
                 KC_TRNS, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS,
                 KC_TRNS, KC_TILD, KC_PIPE, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, KC_MINS, KC_EQL , KC_DOT , KC_SLSH, KC_TRNS,
                 KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_RALT, KC_RGUI, KC_NO  , KC_NO),
    // mouse
    KEYMAP(
                RGB_MOD ,RGB_RMOD,RGB_M_P ,RGB_M_B ,RGB_M_R ,RGB_M_SW,RGB_M_SN, KC_WH_D, KC_MS_U, KC_WH_U, KC_NO  , KC_NO  ,
                 KC_LCTL,RGB_M_K ,RGB_M_X ,RGB_M_G ,RGB_M_T ,RGB_TOG , KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_TRNS,
                 KC_TRNS,RGB_HUI ,RGB_HUD ,RGB_SAI ,RGB_SAD ,RGB_VAI ,RGB_VAD , KC_ACL0, KC_ACL1, KC_ACL2, KC_NO  , KC_TRNS,
                 KC_NO,   KC_NO,   KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_RALT, KC_RGUI, KC_NO  , KC_NO),
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {


	switch (id) {

	}
	return MACRO_NONE;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		DDRB |= (1 << 4); PORTB &= ~(1 << 4);
	} else {
		DDRB &= ~(1 << 4); PORTB &= ~(1 << 4);
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {
		
	} else {
		
	}

	if (usb_led & (1 << USB_LED_KANA)) {
		
	} else {
		
	}

}
