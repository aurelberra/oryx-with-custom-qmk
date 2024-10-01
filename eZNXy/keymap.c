#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_11,
  DANCE_12,
  DANCE_13,
  DANCE_14,
  DANCE_15,
  DANCE_16,
  DANCE_17,
  DANCE_18,
  DANCE_19,
  DANCE_20,
  DANCE_21,
  DANCE_22,
  DANCE_23,
  DANCE_24,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_GRAVE,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TRANSPARENT, TD(DANCE_0),    TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    KC_T,                                           TD(DANCE_10),   TD(DANCE_11),   TD(DANCE_12),   TD(DANCE_13),   KC_P,           KC_LBRC,        
    KC_TRANSPARENT, TD(DANCE_4),    MT(MOD_LALT, KC_S),MT(MOD_LGUI, KC_D),MT(MOD_LCTL, KC_F),TD(DANCE_5),                                    TD(DANCE_14),   TD(DANCE_15),   TD(DANCE_16),   TD(DANCE_17),   TD(DANCE_18),   KC_QUOTE,       
    KC_TRANSPARENT, MT(MOD_LSFT | MOD_LGUI, KC_Z),MT(MOD_LALT | MOD_LGUI, KC_X),TD(DANCE_6),    TD(DANCE_7),    TD(DANCE_8),                                    TD(DANCE_19),   MT(MOD_LALT | MOD_LGUI | MOD_LCTL, KC_M),TD(DANCE_20),   TD(DANCE_21),   TD(DANCE_22),   KC_RBRC,        
                                                    TD(DANCE_9),    LT(1,KC_ESCAPE),                                MT(MOD_RSFT, KC_ENTER),TD(DANCE_23)
  ),
  [1] = LAYOUT_voyager(
    KC_BRIGHTNESS_UP,KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_TRANSPARENT, 
    KC_BRIGHTNESS_DOWN,RGB_TOG,        KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,LALT(LGUI(LCTL(LSFT(BP_K)))),                                KC_TRANSPARENT, KC_F1,          LALT(KC_F6),    LCTL(KC_F6),    KC_F11,         KC_TRANSPARENT, 
    CW_TOGG,        KC_MEDIA_STOP,  KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,LGUI(KC_Y),                                     LGUI(LSFT(KC_Y)),LGUI(LCTL(KC_LEFT)),LGUI(LCTL(KC_UP)),LGUI(LCTL(KC_RIGHT)),KC_F12,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, LALT(KC_TAB),   LGUI(KC_TAB),   KC_TAB,         LGUI(LSFT(KC_SPACE)),                                KC_TRANSPARENT, KC_DELETE,      LGUI(LCTL(KC_DOWN)),KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    LSFT(KC_TAB),   KC_TRANSPARENT,                                 TD(DANCE_24),   KC_F6
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           BP_PERC,                                        KC_KP_ASTERISK, LSFT(BP_7),     BP_AGRV,        KC_KP_SLASH,    KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_0,           KC_1,           KC_2,           KC_3,           BP_EQL,                                         KC_ENTER,       KC_LEFT,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_SPACE,       KC_7,           KC_8,           KC_9,           BP_COMM,                                        KC_BSPC,        LCTL(KC_LEFT),  KC_DOWN,        LCTL(KC_RIGHT), KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TAB,                                         TO(0),          KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_MS_BTN1),KC_TRANSPARENT, LSFT(KC_MS_BTN2),KC_TRANSPARENT,                                 KC_NO,          KC_TRANSPARENT, KC_NO,          KC_TRANSPARENT, KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_MS_ACCEL1,   LSFT(KC_MS_LEFT),LSFT(KC_MS_UP), LSFT(KC_MS_RIGHT),KC_TRANSPARENT,                                 KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_UP,       KC_MS_RIGHT,    KC_NO,          KC_NO,          
    KC_TRANSPARENT, KC_MS_ACCEL2,   KC_MS_WH_RIGHT, LSFT(KC_MS_DOWN),KC_MS_WH_LEFT,  KC_TRANSPARENT,                                 KC_MS_WH_UP,    KC_MS_BTN1,     KC_MS_DOWN,     KC_MS_BTN2,     KC_NO,          KC_NO,          
                                                    KC_MS_BTN1,     TO(0),                                          TO(0),          KC_MS_BTN1
  ),
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(DANCE_9):
            return TAPPING_TERM -25;
        case LT(1,KC_ESCAPE):
            return TAPPING_TERM -25;
        case MT(MOD_RSFT, KC_ENTER):
            return TAPPING_TERM -25;
        case TD(DANCE_23):
            return TAPPING_TERM -25;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {172,255,255}, {15,255,255}, {15,255,255}, {15,255,255}, {15,255,255}, {15,255,255}, {142,255,255}, {32,255,255}, {0,254,255}, {142,255,255}, {172,255,255}, {91,255,255}, {0,0,0}, {0,254,255}, {91,255,255}, {142,255,255}, {172,255,255}, {239,255,166}, {0,0,0}, {0,0,0}, {102,218,204}, {102,218,204}, {102,218,204}, {32,255,255}, {102,218,204}, {0,0,0}, {15,255,255}, {15,255,255}, {15,255,255}, {15,255,255}, {15,255,255}, {0,0,0}, {0,0,0}, {15,255,255}, {15,255,255}, {15,255,255}, {15,255,255}, {0,0,0}, {239,255,166}, {172,255,255}, {172,255,255}, {172,255,255}, {15,255,255}, {0,0,0}, {0,0,0}, {102,218,204}, {172,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {15,255,255}, {142,255,255} },

    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {136,218,204}, {136,218,204}, {136,218,204}, {238,218,204}, {0,0,0}, {91,255,255}, {102,218,204}, {102,218,204}, {102,218,204}, {238,218,204}, {0,0,0}, {238,218,204}, {188,218,204}, {188,218,204}, {188,218,204}, {238,218,204}, {0,0,0}, {102,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {238,218,204}, {238,218,204}, {238,218,204}, {238,218,204}, {0,0,0}, {0,0,0}, {238,218,204}, {142,255,255}, {142,255,255}, {142,255,255}, {0,0,0}, {0,0,0}, {238,218,204}, {91,255,255}, {142,255,255}, {91,255,255}, {0,0,0}, {0,0,0}, {0,255,204}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,218,204}, {0,0,0}, {188,218,204}, {0,0,0}, {0,0,0}, {172,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {0,0,0}, {0,0,0}, {188,218,204}, {142,255,255}, {142,255,255}, {142,255,255}, {0,0,0}, {172,255,255}, {0,254,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {142,255,255}, {142,255,255}, {142,255,255}, {142,255,255}, {0,0,0}, {0,0,0}, {142,255,255}, {172,255,255}, {142,255,255}, {172,255,255}, {0,0,0}, {0,0,0}, {0,254,255}, {172,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 1:
      set_layer_color(1);
      break;
    case 2:
      set_layer_color(2);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[25];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_Q);
        tap_code16(KC_Q);
        tap_code16(KC_Q);
    }
    if(state->count > 3) {
        tap_code16(KC_Q);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_Q); break;
        case SINGLE_HOLD: register_code16(LCTL(BP_K)); break;
        case DOUBLE_TAP: register_code16(KC_Q); register_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Q); register_code16(KC_Q);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_Q); break;
        case SINGLE_HOLD: unregister_code16(LCTL(BP_K)); break;
        case DOUBLE_TAP: unregister_code16(KC_Q); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Q); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_W);
        tap_code16(KC_W);
        tap_code16(KC_W);
    }
    if(state->count > 3) {
        tap_code16(KC_W);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_W); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_1)); break;
        case DOUBLE_TAP: register_code16(KC_W); register_code16(KC_W); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_W); register_code16(KC_W);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_W); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_1)); break;
        case DOUBLE_TAP: unregister_code16(KC_W); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_W); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_E);
        tap_code16(KC_E);
        tap_code16(KC_E);
    }
    if(state->count > 3) {
        tap_code16(KC_E);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_E); break;
        case SINGLE_HOLD: register_code16(LGUI(LSFT(BP_P))); break;
        case DOUBLE_TAP: register_code16(KC_E); register_code16(KC_E); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_E); register_code16(KC_E);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_E); break;
        case SINGLE_HOLD: unregister_code16(LGUI(LSFT(BP_P))); break;
        case DOUBLE_TAP: unregister_code16(KC_E); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_E); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_R);
        tap_code16(KC_R);
        tap_code16(KC_R);
    }
    if(state->count > 3) {
        tap_code16(KC_R);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_R); break;
        case SINGLE_HOLD: register_code16(LSFT(KC_0)); break;
        case DOUBLE_TAP: register_code16(KC_R); register_code16(KC_R); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_R); register_code16(KC_R);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_R); break;
        case SINGLE_HOLD: unregister_code16(LSFT(KC_0)); break;
        case DOUBLE_TAP: unregister_code16(KC_R); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_R); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_A);
        tap_code16(KC_A);
        tap_code16(KC_A);
    }
    if(state->count > 3) {
        tap_code16(KC_A);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_A); break;
        case SINGLE_HOLD: layer_move(3); break;
        case DOUBLE_TAP: register_code16(KC_A); register_code16(KC_A); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_A); register_code16(KC_A);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_A); break;
        case DOUBLE_TAP: unregister_code16(KC_A); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_A); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_G);
        tap_code16(KC_G);
        tap_code16(KC_G);
    }
    if(state->count > 3) {
        tap_code16(KC_G);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_G); break;
        case SINGLE_HOLD: register_code16(KC_PAGE_UP); break;
        case DOUBLE_TAP: register_code16(KC_G); register_code16(KC_G); break;
        case DOUBLE_HOLD: register_code16(KC_HOME); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_G); register_code16(KC_G);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_G); break;
        case SINGLE_HOLD: unregister_code16(KC_PAGE_UP); break;
        case DOUBLE_TAP: unregister_code16(KC_G); break;
        case DOUBLE_HOLD: unregister_code16(KC_HOME); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_G); break;
    }
    dance_state[5].step = 0;
}
void on_dance_6(tap_dance_state_t *state, void *user_data);
void dance_6_finished(tap_dance_state_t *state, void *user_data);
void dance_6_reset(tap_dance_state_t *state, void *user_data);

void on_dance_6(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_C);
        tap_code16(KC_C);
        tap_code16(KC_C);
    }
    if(state->count > 3) {
        tap_code16(KC_C);
    }
}

void dance_6_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[6].step = dance_step(state);
    switch (dance_state[6].step) {
        case SINGLE_TAP: register_code16(KC_C); break;
        case SINGLE_HOLD: register_code16(BP_COLN); break;
        case DOUBLE_TAP: register_code16(KC_C); register_code16(KC_C); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_C); register_code16(KC_C);
    }
}

void dance_6_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[6].step) {
        case SINGLE_TAP: unregister_code16(KC_C); break;
        case SINGLE_HOLD: unregister_code16(BP_COLN); break;
        case DOUBLE_TAP: unregister_code16(KC_C); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_C); break;
    }
    dance_state[6].step = 0;
}
void on_dance_7(tap_dance_state_t *state, void *user_data);
void dance_7_finished(tap_dance_state_t *state, void *user_data);
void dance_7_reset(tap_dance_state_t *state, void *user_data);

void on_dance_7(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_V);
        tap_code16(KC_V);
        tap_code16(KC_V);
    }
    if(state->count > 3) {
        tap_code16(KC_V);
    }
}

void dance_7_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[7].step = dance_step(state);
    switch (dance_state[7].step) {
        case SINGLE_TAP: register_code16(KC_V); break;
        case SINGLE_HOLD: register_code16(KC_F3); break;
        case DOUBLE_TAP: register_code16(KC_V); register_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_V); register_code16(KC_V);
    }
}

void dance_7_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[7].step) {
        case SINGLE_TAP: unregister_code16(KC_V); break;
        case SINGLE_HOLD: unregister_code16(KC_F3); break;
        case DOUBLE_TAP: unregister_code16(KC_V); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_V); break;
    }
    dance_state[7].step = 0;
}
void on_dance_8(tap_dance_state_t *state, void *user_data);
void dance_8_finished(tap_dance_state_t *state, void *user_data);
void dance_8_reset(tap_dance_state_t *state, void *user_data);

void on_dance_8(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_B);
        tap_code16(KC_B);
        tap_code16(KC_B);
    }
    if(state->count > 3) {
        tap_code16(KC_B);
    }
}

void dance_8_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[8].step = dance_step(state);
    switch (dance_state[8].step) {
        case SINGLE_TAP: register_code16(KC_B); break;
        case SINGLE_HOLD: register_code16(KC_PGDN); break;
        case DOUBLE_TAP: register_code16(KC_B); register_code16(KC_B); break;
        case DOUBLE_HOLD: register_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_B); register_code16(KC_B);
    }
}

void dance_8_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[8].step) {
        case SINGLE_TAP: unregister_code16(KC_B); break;
        case SINGLE_HOLD: unregister_code16(KC_PGDN); break;
        case DOUBLE_TAP: unregister_code16(KC_B); break;
        case DOUBLE_HOLD: unregister_code16(KC_END); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_B); break;
    }
    dance_state[8].step = 0;
}
void on_dance_9(tap_dance_state_t *state, void *user_data);
void dance_9_finished(tap_dance_state_t *state, void *user_data);
void dance_9_reset(tap_dance_state_t *state, void *user_data);

void on_dance_9(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
        tap_code16(KC_BSPC);
    }
    if(state->count > 3) {
        tap_code16(KC_BSPC);
    }
}

void dance_9_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[9].step = dance_step(state);
    switch (dance_state[9].step) {
        case SINGLE_TAP: register_code16(KC_BSPC); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_TAP: register_code16(KC_TAB); break;
        case DOUBLE_HOLD: register_code16(LALT(KC_BSPC)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_BSPC); register_code16(KC_BSPC);
    }
}

void dance_9_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[9].step) {
        case SINGLE_TAP: unregister_code16(KC_BSPC); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_TAP: unregister_code16(KC_TAB); break;
        case DOUBLE_HOLD: unregister_code16(LALT(KC_BSPC)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_BSPC); break;
    }
    dance_state[9].step = 0;
}
void on_dance_10(tap_dance_state_t *state, void *user_data);
void dance_10_finished(tap_dance_state_t *state, void *user_data);
void dance_10_reset(tap_dance_state_t *state, void *user_data);

void on_dance_10(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_Y);
        tap_code16(KC_Y);
        tap_code16(KC_Y);
    }
    if(state->count > 3) {
        tap_code16(KC_Y);
    }
}

void dance_10_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[10].step = dance_step(state);
    switch (dance_state[10].step) {
        case SINGLE_TAP: register_code16(KC_Y); break;
        case SINGLE_HOLD: register_code16(LGUI(BP_A)); break;
        case DOUBLE_TAP: register_code16(KC_Y); register_code16(KC_Y); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_Y); register_code16(KC_Y);
    }
}

void dance_10_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[10].step) {
        case SINGLE_TAP: unregister_code16(KC_Y); break;
        case SINGLE_HOLD: unregister_code16(LGUI(BP_A)); break;
        case DOUBLE_TAP: unregister_code16(KC_Y); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_Y); break;
    }
    dance_state[10].step = 0;
}
void on_dance_11(tap_dance_state_t *state, void *user_data);
void dance_11_finished(tap_dance_state_t *state, void *user_data);
void dance_11_reset(tap_dance_state_t *state, void *user_data);

void on_dance_11(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_U);
        tap_code16(KC_U);
        tap_code16(KC_U);
    }
    if(state->count > 3) {
        tap_code16(KC_U);
    }
}

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[11].step = dance_step(state);
    switch (dance_state[11].step) {
        case SINGLE_TAP: register_code16(KC_U); break;
        case SINGLE_HOLD: register_code16(LGUI(BP_V)); break;
        case DOUBLE_TAP: register_code16(KC_U); register_code16(KC_U); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_U); register_code16(KC_U);
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[11].step) {
        case SINGLE_TAP: unregister_code16(KC_U); break;
        case SINGLE_HOLD: unregister_code16(LGUI(BP_V)); break;
        case DOUBLE_TAP: unregister_code16(KC_U); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_U); break;
    }
    dance_state[11].step = 0;
}
void on_dance_12(tap_dance_state_t *state, void *user_data);
void dance_12_finished(tap_dance_state_t *state, void *user_data);
void dance_12_reset(tap_dance_state_t *state, void *user_data);

void on_dance_12(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_I);
        tap_code16(KC_I);
        tap_code16(KC_I);
    }
    if(state->count > 3) {
        tap_code16(KC_I);
    }
}

void dance_12_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[12].step = dance_step(state);
    switch (dance_state[12].step) {
        case SINGLE_TAP: register_code16(KC_I); break;
        case SINGLE_HOLD: register_code16(LGUI(BP_D)); break;
        case DOUBLE_TAP: register_code16(KC_I); register_code16(KC_I); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_I); register_code16(KC_I);
    }
}

void dance_12_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[12].step) {
        case SINGLE_TAP: unregister_code16(KC_I); break;
        case SINGLE_HOLD: unregister_code16(LGUI(BP_D)); break;
        case DOUBLE_TAP: unregister_code16(KC_I); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_I); break;
    }
    dance_state[12].step = 0;
}
void on_dance_13(tap_dance_state_t *state, void *user_data);
void dance_13_finished(tap_dance_state_t *state, void *user_data);
void dance_13_reset(tap_dance_state_t *state, void *user_data);

void on_dance_13(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_O);
        tap_code16(KC_O);
        tap_code16(KC_O);
    }
    if(state->count > 3) {
        tap_code16(KC_O);
    }
}

void dance_13_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[13].step = dance_step(state);
    switch (dance_state[13].step) {
        case SINGLE_TAP: register_code16(KC_O); break;
        case SINGLE_HOLD: register_code16(LGUI(BP_L)); break;
        case DOUBLE_TAP: register_code16(KC_O); register_code16(KC_O); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_O); register_code16(KC_O);
    }
}

void dance_13_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[13].step) {
        case SINGLE_TAP: unregister_code16(KC_O); break;
        case SINGLE_HOLD: unregister_code16(LGUI(BP_L)); break;
        case DOUBLE_TAP: unregister_code16(KC_O); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_O); break;
    }
    dance_state[13].step = 0;
}
void on_dance_14(tap_dance_state_t *state, void *user_data);
void dance_14_finished(tap_dance_state_t *state, void *user_data);
void dance_14_reset(tap_dance_state_t *state, void *user_data);

void on_dance_14(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_H);
        tap_code16(KC_H);
        tap_code16(KC_H);
    }
    if(state->count > 3) {
        tap_code16(KC_H);
    }
}

void dance_14_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[14].step = dance_step(state);
    switch (dance_state[14].step) {
        case SINGLE_TAP: register_code16(KC_H); break;
        case SINGLE_HOLD: register_code16(LGUI(BP_C)); break;
        case DOUBLE_TAP: register_code16(KC_H); register_code16(KC_H); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_H); register_code16(KC_H);
    }
}

void dance_14_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[14].step) {
        case SINGLE_TAP: unregister_code16(KC_H); break;
        case SINGLE_HOLD: unregister_code16(LGUI(BP_C)); break;
        case DOUBLE_TAP: unregister_code16(KC_H); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_H); break;
    }
    dance_state[14].step = 0;
}
void on_dance_15(tap_dance_state_t *state, void *user_data);
void dance_15_finished(tap_dance_state_t *state, void *user_data);
void dance_15_reset(tap_dance_state_t *state, void *user_data);

void on_dance_15(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_J);
        tap_code16(KC_J);
        tap_code16(KC_J);
    }
    if(state->count > 3) {
        tap_code16(KC_J);
    }
}

void dance_15_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[15].step = dance_step(state);
    switch (dance_state[15].step) {
        case SINGLE_TAP: register_code16(KC_J); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: register_code16(KC_J); register_code16(KC_J); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_J); register_code16(KC_J);
    }
}

void dance_15_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[15].step) {
        case SINGLE_TAP: unregister_code16(KC_J); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_CTRL); break;
        case DOUBLE_TAP: unregister_code16(KC_J); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_J); break;
    }
    dance_state[15].step = 0;
}
void on_dance_16(tap_dance_state_t *state, void *user_data);
void dance_16_finished(tap_dance_state_t *state, void *user_data);
void dance_16_reset(tap_dance_state_t *state, void *user_data);

void on_dance_16(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_K);
        tap_code16(KC_K);
        tap_code16(KC_K);
    }
    if(state->count > 3) {
        tap_code16(KC_K);
    }
}

void dance_16_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[16].step = dance_step(state);
    switch (dance_state[16].step) {
        case SINGLE_TAP: register_code16(KC_K); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: register_code16(KC_K); register_code16(KC_K); break;
        case DOUBLE_HOLD: register_code16(KC_UP); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_K); register_code16(KC_K);
    }
}

void dance_16_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[16].step) {
        case SINGLE_TAP: unregister_code16(KC_K); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_GUI); break;
        case DOUBLE_TAP: unregister_code16(KC_K); break;
        case DOUBLE_HOLD: unregister_code16(KC_UP); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_K); break;
    }
    dance_state[16].step = 0;
}
void on_dance_17(tap_dance_state_t *state, void *user_data);
void dance_17_finished(tap_dance_state_t *state, void *user_data);
void dance_17_reset(tap_dance_state_t *state, void *user_data);

void on_dance_17(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_L);
        tap_code16(KC_L);
        tap_code16(KC_L);
    }
    if(state->count > 3) {
        tap_code16(KC_L);
    }
}

void dance_17_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[17].step = dance_step(state);
    switch (dance_state[17].step) {
        case SINGLE_TAP: register_code16(KC_L); break;
        case SINGLE_HOLD: register_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: register_code16(KC_L); register_code16(KC_L); break;
        case DOUBLE_HOLD: register_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_L); register_code16(KC_L);
    }
}

void dance_17_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[17].step) {
        case SINGLE_TAP: unregister_code16(KC_L); break;
        case SINGLE_HOLD: unregister_code16(KC_RIGHT_ALT); break;
        case DOUBLE_TAP: unregister_code16(KC_L); break;
        case DOUBLE_HOLD: unregister_code16(KC_RIGHT); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_L); break;
    }
    dance_state[17].step = 0;
}
void on_dance_18(tap_dance_state_t *state, void *user_data);
void dance_18_finished(tap_dance_state_t *state, void *user_data);
void dance_18_reset(tap_dance_state_t *state, void *user_data);

void on_dance_18(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SCLN);
        tap_code16(KC_SCLN);
        tap_code16(KC_SCLN);
    }
    if(state->count > 3) {
        tap_code16(KC_SCLN);
    }
}

void dance_18_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[18].step = dance_step(state);
    switch (dance_state[18].step) {
        case SINGLE_TAP: register_code16(KC_SCLN); break;
        case SINGLE_HOLD: register_code16(LALT(LCTL(LGUI(BP_F)))); break;
        case DOUBLE_TAP: register_code16(KC_SCLN); register_code16(KC_SCLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SCLN); register_code16(KC_SCLN);
    }
}

void dance_18_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[18].step) {
        case SINGLE_TAP: unregister_code16(KC_SCLN); break;
        case SINGLE_HOLD: unregister_code16(LALT(LCTL(LGUI(BP_F)))); break;
        case DOUBLE_TAP: unregister_code16(KC_SCLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SCLN); break;
    }
    dance_state[18].step = 0;
}
void on_dance_19(tap_dance_state_t *state, void *user_data);
void dance_19_finished(tap_dance_state_t *state, void *user_data);
void dance_19_reset(tap_dance_state_t *state, void *user_data);

void on_dance_19(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_N);
        tap_code16(KC_N);
        tap_code16(KC_N);
    }
    if(state->count > 3) {
        tap_code16(KC_N);
    }
}

void dance_19_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[19].step = dance_step(state);
    switch (dance_state[19].step) {
        case SINGLE_TAP: register_code16(KC_N); break;
        case SINGLE_HOLD: register_code16(LGUI(BP_X)); break;
        case DOUBLE_TAP: register_code16(KC_N); register_code16(KC_N); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_N); register_code16(KC_N);
    }
}

void dance_19_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[19].step) {
        case SINGLE_TAP: unregister_code16(KC_N); break;
        case SINGLE_HOLD: unregister_code16(LGUI(BP_X)); break;
        case DOUBLE_TAP: unregister_code16(KC_N); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_N); break;
    }
    dance_state[19].step = 0;
}
void on_dance_20(tap_dance_state_t *state, void *user_data);
void dance_20_finished(tap_dance_state_t *state, void *user_data);
void dance_20_reset(tap_dance_state_t *state, void *user_data);

void on_dance_20(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
        tap_code16(KC_COMMA);
    }
    if(state->count > 3) {
        tap_code16(KC_COMMA);
    }
}

void dance_20_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[20].step = dance_step(state);
    switch (dance_state[20].step) {
        case SINGLE_TAP: register_code16(KC_COMMA); break;
        case SINGLE_HOLD: register_code16(LGUI(BP_G)); break;
        case DOUBLE_TAP: register_code16(KC_COMMA); register_code16(KC_COMMA); break;
        case DOUBLE_HOLD: register_code16(KC_DOWN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_COMMA); register_code16(KC_COMMA);
    }
}

void dance_20_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[20].step) {
        case SINGLE_TAP: unregister_code16(KC_COMMA); break;
        case SINGLE_HOLD: unregister_code16(LGUI(BP_G)); break;
        case DOUBLE_TAP: unregister_code16(KC_COMMA); break;
        case DOUBLE_HOLD: unregister_code16(KC_DOWN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_COMMA); break;
    }
    dance_state[20].step = 0;
}
void on_dance_21(tap_dance_state_t *state, void *user_data);
void dance_21_finished(tap_dance_state_t *state, void *user_data);
void dance_21_reset(tap_dance_state_t *state, void *user_data);

void on_dance_21(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_21_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[21].step = dance_step(state);
    switch (dance_state[21].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case SINGLE_HOLD: register_code16(LCTL(LGUI(BP_G))); break;
        case DOUBLE_TAP: register_code16(KC_DOT); register_code16(KC_DOT); break;
        case DOUBLE_HOLD: register_code16(LGUI(BP_E)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_21_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[21].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case SINGLE_HOLD: unregister_code16(LCTL(LGUI(BP_G))); break;
        case DOUBLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_HOLD: unregister_code16(LGUI(BP_E)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[21].step = 0;
}
void on_dance_22(tap_dance_state_t *state, void *user_data);
void dance_22_finished(tap_dance_state_t *state, void *user_data);
void dance_22_reset(tap_dance_state_t *state, void *user_data);

void on_dance_22(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
        tap_code16(KC_SLASH);
    }
    if(state->count > 3) {
        tap_code16(KC_SLASH);
    }
}

void dance_22_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[22].step = dance_step(state);
    switch (dance_state[22].step) {
        case SINGLE_TAP: register_code16(KC_SLASH); break;
        case SINGLE_HOLD: register_code16(LGUI(BP_F)); break;
        case DOUBLE_TAP: register_code16(KC_SLASH); register_code16(KC_SLASH); break;
        case DOUBLE_HOLD: register_code16(LALT(LGUI(BP_F))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SLASH); register_code16(KC_SLASH);
    }
}

void dance_22_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[22].step) {
        case SINGLE_TAP: unregister_code16(KC_SLASH); break;
        case SINGLE_HOLD: unregister_code16(LGUI(BP_F)); break;
        case DOUBLE_TAP: unregister_code16(KC_SLASH); break;
        case DOUBLE_HOLD: unregister_code16(LALT(LGUI(BP_F))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SLASH); break;
    }
    dance_state[22].step = 0;
}
void on_dance_23(tap_dance_state_t *state, void *user_data);
void dance_23_finished(tap_dance_state_t *state, void *user_data);
void dance_23_reset(tap_dance_state_t *state, void *user_data);

void on_dance_23(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
        tap_code16(KC_SPACE);
    }
    if(state->count > 3) {
        tap_code16(KC_SPACE);
    }
}

void dance_23_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[23].step = dance_step(state);
    switch (dance_state[23].step) {
        case SINGLE_TAP: register_code16(KC_SPACE); break;
        case SINGLE_HOLD: layer_on(2); break;
        case DOUBLE_TAP: register_code16(LALT(LSFT(KC_SPACE))); break;
        case DOUBLE_HOLD: layer_move(2); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_SPACE); register_code16(KC_SPACE);
    }
}

void dance_23_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[23].step) {
        case SINGLE_TAP: unregister_code16(KC_SPACE); break;
        case SINGLE_HOLD:
          layer_off(2);
        break;
        case DOUBLE_TAP: unregister_code16(LALT(LSFT(KC_SPACE))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_SPACE); break;
    }
    dance_state[23].step = 0;
}
void on_dance_24(tap_dance_state_t *state, void *user_data);
void dance_24_finished(tap_dance_state_t *state, void *user_data);
void dance_24_reset(tap_dance_state_t *state, void *user_data);

void on_dance_24(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(LGUI(KC_DOWN));
        tap_code16(LGUI(KC_DOWN));
        tap_code16(LGUI(KC_DOWN));
    }
    if(state->count > 3) {
        tap_code16(LGUI(KC_DOWN));
    }
}

void dance_24_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[24].step = dance_step(state);
    switch (dance_state[24].step) {
        case SINGLE_TAP: register_code16(LGUI(KC_DOWN)); break;
        case DOUBLE_TAP: register_code16(LGUI(KC_UP)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(LGUI(KC_DOWN)); register_code16(LGUI(KC_DOWN));
    }
}

void dance_24_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[24].step) {
        case SINGLE_TAP: unregister_code16(LGUI(KC_DOWN)); break;
        case DOUBLE_TAP: unregister_code16(LGUI(KC_UP)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(LGUI(KC_DOWN)); break;
    }
    dance_state[24].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
        [DANCE_6] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_6, dance_6_finished, dance_6_reset),
        [DANCE_7] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_7, dance_7_finished, dance_7_reset),
        [DANCE_8] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_8, dance_8_finished, dance_8_reset),
        [DANCE_9] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_9, dance_9_finished, dance_9_reset),
        [DANCE_10] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_10, dance_10_finished, dance_10_reset),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_11, dance_11_finished, dance_11_reset),
        [DANCE_12] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_12, dance_12_finished, dance_12_reset),
        [DANCE_13] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_13, dance_13_finished, dance_13_reset),
        [DANCE_14] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_14, dance_14_finished, dance_14_reset),
        [DANCE_15] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_15, dance_15_finished, dance_15_reset),
        [DANCE_16] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_16, dance_16_finished, dance_16_reset),
        [DANCE_17] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_17, dance_17_finished, dance_17_reset),
        [DANCE_18] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_18, dance_18_finished, dance_18_reset),
        [DANCE_19] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_19, dance_19_finished, dance_19_reset),
        [DANCE_20] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_20, dance_20_finished, dance_20_reset),
        [DANCE_21] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_21, dance_21_finished, dance_21_reset),
        [DANCE_22] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_22, dance_22_finished, dance_22_reset),
        [DANCE_23] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_23, dance_23_finished, dance_23_reset),
        [DANCE_24] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_24, dance_24_finished, dance_24_reset),
};
