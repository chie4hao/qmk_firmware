#include QMK_KEYBOARD_H
//#include "bootloader.h"
#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

#include "quantum.h"

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  BACKLIT,
  RGBRST,
};

enum macro_keycodes {
  KC_SAMPLEMACRO,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( //  default layer
                 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_RCBR,
                 MT(MOD_LCTL,KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(3,KC_SCLN), MT(MOD_RCTL,KC_QUOT),
                 CHIEL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, LT(2,KC_SLSH), KC_SFTENT,
                 KC_LALT, KC_LGUI, OSM(MOD_RSFT), LT(4,KC_SPC), MO(5),  TG(1)),
    [1] = LAYOUT( //  default layer
                 KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_RCBR,
                 MT(MOD_LCTL,KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(3,KC_SCLN), MT(MOD_RCTL,KC_QUOT),
                 KC_LCBR, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, LT(2,KC_SLSH), KC_SFTENT,
                 KC_LSFT, KC_SPC, LT(4,KC_SPC), KC_LALT, MO(5), TG(1)),
    // slash
    [2] = LAYOUT(
                 KC_TRNS, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_NO  , KC_TRNS,
                 KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, KC_F10 , KC_TRNS, KC_APP , KC_TRNS, KC_TRNS, KC_NO  , KC_TRNS,
                 KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_F11 , KC_F12 , KC_INS , KC_PSCR, KC_SLCK, KC_PAUS, KC_NO  , KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS),
    // scolon
    [3] = LAYOUT(
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_DEL , KC_NO  , KC_NO  , KC_NO,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_NO  , KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_NO  , KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS),
    // space
    [4] = LAYOUT(
                 KC_GRV , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
                 KC_TRNS, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSLS,
                 KC_TRNS, KC_TILD, KC_PIPE, KC_LBRC, KC_RBRC, KC_UNDS, KC_PLUS, KC_MINS, KC_EQL , KC_DOT , KC_SLSH, KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS),
    // mouse
    [5] = LAYOUT(
                 RGB_MOD,RGB_RMOD,RGB_M_P ,RGB_M_B ,RGB_M_R ,RGB_M_SW,RGB_M_SN, KC_WH_D, KC_MS_U, KC_WH_U, KC_NO  , KC_NO  ,
                 KC_LCTL,RGB_M_K ,RGB_M_X ,RGB_M_G ,RGB_M_T ,RGB_TOG , KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_TRNS,
                 KC_TRNS,RGB_HUI ,RGB_HUD ,RGB_SAI ,RGB_SAD ,RGB_VAI ,RGB_VAD , KC_ACL0, KC_ACL1, KC_ACL2, KC_NO  , KC_TRNS,
                 KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS,          KC_TRNS, KC_TRNS),
};

int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
      RGB_current_mode = rgblight_config.mode;
    #endif
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        iota_gfx_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

char keylog_str[24] = {};
char keylogs_str[21] = {};
int keylogs_str_idx = 0;
char layer_state_str[24];
char rbf_info_str[24];

// const char *read_mode_icon(bool swap);
// void set_timelog(void);
// const char *read_timelog(void);

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  //if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) || (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }
  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);

  // update keylogs
  if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
    keylogs_str_idx = 0;
    for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
      keylogs_str[i] = ' ';
    }
  }

  keylogs_str[keylogs_str_idx] = name;
  keylogs_str_idx++;
}

const char *read_keylog(void) {
  return keylog_str;
}

const char *read_keylogs(void) {
  return keylogs_str;
}

const char* read_layer_state(void) {
  switch (biton32(layer_state)) {
  case 0:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
    /* rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); */
    /* rgblight_setrgb(0,0,0); */
    break;
  case 1:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Game");
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 2);
    break;
  case 2:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Slash");
    /* rgblight_sethsv_noeeprom_coral(); */
    break;
  case 3:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Scolon");
    /* rgblight_sethsv_noeeprom_cyan(); */
    break;
  case 4:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Space");
    /* rgblight_sethsv_noeeprom_pink(); */
    break;
  case 5:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Mouse");
    //rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL + 2);
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }
  return layer_state_str;
}

const char *read_logo(void) {
  static char logo[] = {
                        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
                        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
                        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
                        0};

  return logo;
}

const char *read_rgb_info(void) {
  snprintf(rbf_info_str, sizeof(rbf_info_str), "%s %2d h%3d s%3d v%3d",
           rgblight_config.enable ? "on" : "- ", rgblight_config.mode,
           rgblight_config.hue, rgblight_config.sat, rgblight_config.val);
  return rbf_info_str;
}

// When add source files to SRC in rules.mk, you can use functions.

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void matrix_scan_user(void) {
   iota_gfx_task();
}

void matrix_render_user(struct CharacterMatrix *matrix) {
  if (is_master) {
    // If you want to change the display of OLED, you need to change here
    matrix_write_ln(matrix, read_layer_state());
    matrix_write_ln(matrix, read_keylog());
    matrix_write_ln(matrix, read_keylogs());
    //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
    //matrix_write_ln(matrix, read_host_led_state());
    //matrix_write_ln(matrix, read_timelog());
  } else {
    /* matrix_write_ln(matrix, read_layer_state()); */
    /* matrix_write_ln(matrix, read_keylog()); */
    /* matrix_write_ln(matrix, read_keylogs()); */
    matrix_write(matrix, read_logo());
  }
}

void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
  if (memcmp(dest->display, source->display, sizeof(dest->display))) {
    memcpy(dest->display, source->display, sizeof(dest->display));
    dest->dirty = true;
  }
}

void iota_gfx_task_user(void) {
  struct CharacterMatrix matrix;
  matrix_clear(&matrix);
  matrix_render_user(&matrix);
  matrix_update(&display, &matrix);
}
#endif//SSD1306OLED

// Setting ADJUST layer RGB back to default
/* void update_tri_layer_RGB() { */
/*   if (IS_LAYER_ON(0)) { */
/*     rgblight_setrgb(0,0,0); */
/*   } else if (IS_LAYER_ON(1)) { */
/*     rgblight_setrgb(255,0,0); */
/*   } else if (IS_LAYER_ON(2)) { */
/*     rgblight_setrgb(0,255,0); */
/*   } else { */
/*     rgblight_setrgb(0,0,255); */
/*   } */
/*   /\* if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) { *\/ */
/*   /\*   layer_on(layer3); *\/ */
/*   /\* } else { *\/ */
/*   /\*   layer_off(layer3); *\/ */
/*   /\* } *\/ */
/* } */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  /* switch (keycode) { */
  /* case CHIEL: { */
  /*   if (record->event.pressed) { */
  /*     shift_interrupted[0] = false; */
  /*     scs_timer[0] = timer_read (); */
  /*     register_mods(MOD_BIT(KC_LSFT)); */
  /*   } */
  /*   else { */
  /*     if (!shift_interrupted[0] && timer_elapsed(scs_timer[0]) < TAPPING_TERM) { */
  /*       register_code(KC_LBRC); */
  /*       unregister_code(KC_LBRC); */
  /*     } */
  /*     unregister_mods(MOD_BIT(KC_LSFT)); */
  /*   } */
  /*   return false; */
  /* } */
  /* } */

  /* switch (keycode) { */
  /* case LT(1,KC_SLSH): */
  /*   if (record->event.pressed) { */
  /*     /\* rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 2); *\/ */
  /*     /\* rgblight_enable(); *\/ */
  /*     update_tri_layer_RGB(); */
  /*   } else { */
  /*     /\* rgblight_disable(); *\/ */
  /*     update_tri_layer_RGB(); */
  /*   } */
  /*   return true; */
  /* case LT(2, KC_SCLN): */
  /*   if (record->event.pressed) { */
  /*     /\* rgblight_setrgb(0,255,0); *\/ */
  /*     /\* rgblight_enable(); *\/ */
  /*     update_tri_layer_RGB(); */
  /*   } else { */
  /*     /\* rgblight_disable(); *\/ */
  /*     update_tri_layer_RGB(); */
  /*   } */
  /*   return true; */
  /* case LT(3, KC_SPC): */
  /*   return true; */
  /* case MO(4): */
  /*   return true; */
  /* case RGB_MOD: */
  /*   #ifdef RGBLIGHT_ENABLE */
  /*     if (record->event.pressed) { */
  /*       rgblight_mode(RGB_current_mode); */
  /*       rgblight_step(); */
  /*       RGB_current_mode = rgblight_config.mode; */
  /*     } */
  /*   #endif */
  /*   return false; */
  /* case KC_RGUI: */
  /*   #ifdef RGBLIGHT_ENABLE */
  /*     if (record->event.pressed) { */
  /*       eeconfig_update_rgblight_default(); */
  /*       rgblight_enable(); */
  /*       RGB_current_mode = rgblight_config.mode; */
  /*     } */
  /*   #endif */
  /*   return true; */
  /* } */
  return true;
}

uint32_t layer_state_set_user(uint32_t state) {
  #ifdef RGBLIGHT_ENABLE
  /* uint8_t default_layer = eeconfig_read_default_layer(); */
  /* if (userspace_config.rgb_layer_change) { */
    switch (biton32(state)) {
    case 0:
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
      rgblight_sethsv_noeeprom(0,0,0);
      break;
    /* case 0: */
    /*   rgblight_sethsv_noeeprom_blue(); */
    /*   /\* rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); *\/ */
    /*   rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+2); */
    /*   break; */
    case 2:
      rgblight_sethsv_noeeprom_chartreuse();
      rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING+2);
      break;
    case 3:
      rgblight_mode_noeeprom(36);
      rgblight_sethsv_noeeprom_blue();
      break;
    case 4:
      rgblight_sethsv_noeeprom_blue();
      rgblight_mode_noeeprom(RGBLIGHT_MODE_RAINBOW_SWIRL+2);
      break;
    case 5:
      rgblight_sethsv_noeeprom_springgreen();
      rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_GRADIENT+4);
      break;
    }
  #endif
    return state;
}
