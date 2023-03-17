#include QMK_KEYBOARD_H
#include "repeat.h"

#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode_j = KC_NO;
uint8_t last_modifier = 0;
uint16_t pressed_keycode = KC_NO;
uint16_t post_process_keycode = KC_NO;

uint8_t function_mods;

uint8_t mod_state;
bool alpha_2_active = false;
bool sft_alpha_2_active = false;
bool deactivate_alpha_2 = false;
bool deactivate_sft_alpha_2 = false;

#define _ALPHA_1        0
#define _BUTTON         3
#define _ONE_HAND       1
#define _NUMWORD        2
#define _ALPHA_2        4
#define _RALPHA_2       5
#define _LHAND          6
#define _SFT_ALPHA_2    7
#define _NUM            8
#define _SYM_1          9
#define _SYM_2          10
#define _NAV            11
#define _FUN            12
#define _RHAND          13
#define _RNAV           14
#define _RNUM           15


enum custom_keycodes {
  REPEAT = SAFE_RANGE,
  REV_REP,
  S_E_NAV,
  OK_SAL2,
  OK_ALP2,
  COM_SPC,
  SCROLL,
  APP_1,
  APP_2,
  APP_3,
  APP_4,
  APP_5,
  APP_6,
  APP_7,
  APP_8,
  APP_9,
  APP_0
};
#define OS_ALP2 OSL(_ALPHA_2)
#define OS_RAL2 OSL(_RALPHA_2)
#define A_SFT_2 OSL(_SFT_ALPHA_2)
#define OS_SFT  OSM(MOD_LSFT)

#define CTL_D   LCTL_T(KC_D)
#define CTL_H   RCTL_T(KC_H)
#define ALT_G   LALT_T(KC_G)
#define ALT_U   LALT_T(KC_U)
#define GUI_L   LGUI_T(KC_L)
#define GUI_O   RGUI_T(KC_O)
#define CTL_M   LCTL_T(KC_M)
#define CTL_F   RCTL_T(KC_F)
#define ALT_W   LALT_T(KC_W)
#define ALT_QOT LALT_T(KC_QUOT)
#define GUI_V   LGUI_T(KC_V)
#define GUI_Z   RGUI_T(KC_Z)
#define SPC_SFT LSFT_T(KC_SPC)
#define GUI_PLS LGUI_T(KC_PPLS)
#define ALT_DOT LALT_T(KC_DOT)
#define CTL_0   LCTL_T(KC_0)
#define CTL_7   RCTL_T(KC_7)
#define ALT_8   LALT_T(KC_8)
#define GUI_9   RGUI_T(KC_9)

#define NUM_I   LT(_NUM, KC_I)
#define SYM2_S  LT(_SYM_2, KC_S)
#define SYM1_R  LT(_SYM_1, KC_R)
#define NAV_T   LT(_NAV, KC_T)
#define NAV_K   LT(_NAV, KC_K)
#define NAV_N   LT(_NAV, KC_N)
#define SYM1_E  LT(_SYM_1, KC_E)
#define SYM2_A  LT(_SYM_2, KC_A)
#define NUM_C   LT(_NUM, KC_C)

#define SYM_1   LT(_SYM_2, KC_1)
#define SYM_2   LT(_SYM_1, KC_2)
#define NAV_3   LT(_NAV, KC_3)
#define NAV_4   LT(_NAV, KC_4)
#define SYM_5   LT(_SYM_1, KC_5)
#define SYM_6   LT(_SYM_2, KC_6)

#define TO_ALP1 TO(_ALPHA_1)

#define KC_DQOT LSFT(KC_2)
#define KC_PND  LSFT(KC_3)
#define KC_LTHN LSFT(KC_COMM)
#define KC_GTHN LSFT(KC_DOT)
#define KC_CLN  LSFT(KC_SCLN)
#define KC_QST  LSFT(KC_SLSH)
#define KC_PPE  LSFT(KC_NUBS)
#define KC_ATS  LSFT(KC_QUOT)

#define PASTE   LCTL(KC_V)
#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
#define UNDO    LCTL(KC_Z)
#define REDO    LCTL(KC_Y)
#define CTL_LFT LCTL(KC_LEFT)
#define CTL_RGT LCTL(KC_RGHT)
#define SRN_SHT LGUI(LSFT(KC_S))

#define SFT_V   LSFT(KC_V)
#define SFT_W   LSFT(KC_W)
#define SFT_M   LSFT(KC_M)
#define SFT_F   LSFT(KC_F)
#define SFT_Z   LSFT(KC_Z)
#define SFT_Q   LSFT(KC_Q)
#define SFT_J   LSFT(KC_J)
#define SFT_P   LSFT(KC_P)
#define SFT_K   LSFT(KC_K)
#define SFT_B   LSFT(KC_B)
#define SFT_X   LSFT(KC_X)
#define SFT_Y   LSFT(KC_Y)

#define TH_RGHT LT(0, KC_RGHT)
#define TH_LEFT LT(0, KC_LEFT)
#define TH_DOWN LT(0, KC_DOWN)
#define TH_UP   LT(0, KC_UP)
#define TH_COPY LT(0, KC_C)
#define TH_BSPC LT(0, KC_BSPC)




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_ALPHA_1] = LAYOUT(
  //         ┌────────┬────────┬────────┐                         ┌────────┬────────┬────────┐
              GUI_L   ,ALT_G   ,CTL_D   ,                          CTL_H   ,ALT_U   ,GUI_O   ,
  //┌────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┐
     NUM_I   ,SYM2_S  ,SYM1_R  ,NAV_T   ,                          NAV_N   ,SYM1_E  ,SYM2_A  ,NUM_C   ,
  //└────────┴────────┴────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┘
                                KC_SPC  ,REPEAT  ,        OK_SAL2 ,OK_ALP2 
  //                           └────────┴────────┘       └────────┴────────┘
  ),

  [_BUTTON] = LAYOUT(
  //         ┌────────┬────────┬────────┐                         ┌────────┬────────┬────────┐
              KC_ESC  ,KC_DEL  ,KC_APP  ,                          KC_DEL  ,TH_UP   ,TH_BSPC ,
  //┌────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┐
     KC_TAB  ,C(KC_Z) ,TH_COPY ,KC_BTN1 ,                          TH_LEFT ,TH_DOWN ,TH_RGHT ,KC_ENT  ,
  //└────────┴────────┴────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┘
                                S_E_NAV ,SCROLL  ,        TO_ALP1 ,KC_LCTL 
  //                           └────────┴────────┘       └────────┴────────┘
  ),

  [_ONE_HAND] = LAYOUT(
  //         ┌────────┬────────┬────────┐                         ┌────────┬────────┬────────┐
              GUI_O   ,ALT_U   ,CTL_H   ,                          CTL_H   ,ALT_U   ,GUI_O   ,
  //┌────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┐
     NUM_C   ,SYM2_A  ,SYM1_E  ,NAV_N   ,                          NAV_N   ,SYM1_E  ,SYM2_A  ,NUM_C   ,
  //└────────┴────────┴────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┘
                                OS_ALP2 ,OS_RAL2 ,        OK_SAL2 ,OK_ALP2 
  //                           └────────┴────────┘       └────────┴────────┘
  ),

  [_NUMWORD] = LAYOUT(
  //         ┌────────┬────────┬────────┐                         ┌────────┬────────┬────────┐
              GUI_PLS ,ALT_DOT ,CTL_0   ,                          CTL_7   ,ALT_8   ,GUI_9   ,
  //┌────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┐
     KC_MINS ,SYM_1   ,SYM_2   ,NAV_3   ,                          NAV_4   ,SYM_5   ,SYM_6   ,KC_EQL  ,
  //└────────┴────────┴────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┘
                                SPC_SFT ,REPEAT  ,        OK_SAL2 ,OK_ALP2 
  //                           └────────┴────────┘       └────────┴────────┘
  ),

  [_ALPHA_2] = LAYOUT(
  //         ┌────────┬────────┬────────┐                         ┌────────┬────────┬────────┐
              GUI_V   ,ALT_W   ,CTL_M   ,                          CTL_F   ,ALT_QOT ,GUI_Z   ,
  //┌────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┐
     KC_Q    ,KC_J    ,KC_P    ,NAV_K   ,                          KC_B    ,KC_DOT  ,KC_X    ,KC_Y    ,
  //└────────┴────────┴────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┘
                                OS_SFT  ,REV_REP ,        XXXXXXX ,TO_ALP1 
  //                           └────────┴────────┘       └────────┴────────┘
  ),

  [_RALPHA_2] = LAYOUT(
  //         ┌────────┬────────┬────────┐                         ┌────────┬────────┬────────┐
              GUI_Z   ,ALT_QOT ,CTL_F   ,                          CTL_F   ,ALT_QOT ,GUI_Z   ,
  //┌────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┐
     KC_Y    ,KC_X    ,KC_DOT  ,KC_B    ,                          KC_B    ,KC_DOT  ,KC_X    ,KC_Y    ,
  //└────────┴────────┴────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┘
                                TO_ALP1 ,REV_REP ,        XXXXXXX ,TO_ALP1 
  //                           └────────┴────────┘       └────────┴────────┘
  ),

  [_SFT_ALPHA_2] = LAYOUT(
  //         ┌────────┬────────┬────────┐                         ┌────────┬────────┬────────┐
              SFT_V   ,SFT_W   ,SFT_M   ,                          SFT_F   ,COM_SPC ,SFT_Z   ,
  //┌────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┐
     SFT_Q   ,SFT_J   ,SFT_P   ,SFT_K   ,                          SFT_B   ,KC_COMM ,SFT_X   ,SFT_Y   ,
  //└────────┴────────┴────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┘
                                KC_UNDS ,XXXXXXX ,        REPEAT  ,XXXXXXX 
  //                           └────────┴────────┘       └────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //         ┌────────┬────────┬────────┐                         ┌────────┬────────┬────────┐
              GUI_PLS ,ALT_DOT ,CTL_0   ,                          CTL_7   ,ALT_8   ,GUI_9   ,
  //┌────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┐
     KC_MINS ,SYM_1   ,SYM_2   ,NAV_3   ,                          NAV_4   ,SYM_5   ,SYM_6   ,KC_EQL  ,
  //└────────┴────────┴────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┘
                                SPC_SFT ,OS_SFT  ,        TO_ALP1 ,KC_LCTL 
  //                           └────────┴────────┘       └────────┴────────┘
  ),

  [_SYM_1] = LAYOUT(
  //         ┌────────┬────────┬────────┐                         ┌────────┬────────┬────────┐
              KC_PND  ,KC_NUHS ,KC_DLR  ,                          KC_LTHN ,KC_GTHN ,KC_CIRC ,
  //┌────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┐
     KC_GRV  ,KC_PIPE ,KC_MINS ,KC_NUBS ,                          KC_LBRC ,KC_RBRC ,KC_PPE  ,KC_SLSH ,
  //└────────┴────────┴────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┘
                                SPC_SFT ,OS_SFT  ,        REPEAT  ,XXXXXXX 
  //                           └────────┴────────┘       └────────┴────────┘
  ),

  [_SYM_2] = LAYOUT(
  //         ┌────────┬────────┬────────┐                         ┌────────┬────────┬────────┐
              KC_ATS  ,KC_EXLM ,KC_P3   ,                          KC_LPRN ,KC_RPRN ,KC_SCLN ,
  //┌────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┐
     KC_ASTR ,KC_PERC ,KC_QST  ,KC_DQOT ,                          KC_LCBR ,KC_RCBR ,KC_AMPR ,KC_CLN  ,
  //└────────┴────────┴────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┘
                                SPC_SFT ,OS_SFT  ,        REPEAT  ,XXXXXXX 
  //                           └────────┴────────┘       └────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //         ┌────────┬────────┬────────┐                         ┌────────┬────────┬────────┐
              KC_ESC  ,KC_DEL  ,KC_APP  ,                          KC_DEL  ,TH_UP   ,TH_BSPC ,
  //┌────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┐
     KC_TAB  ,C(KC_Z) ,TH_COPY ,SRN_SHT ,                          TH_LEFT ,TH_DOWN ,TH_RGHT ,KC_ENT  ,
  //└────────┴────────┴────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┘
                                S_E_NAV ,KC_LALT ,        TO_ALP1 ,KC_LCTL 
  //                           └────────┴────────┘       └────────┴────────┘
  ),

  [_FUN] = LAYOUT(
  //         ┌────────┬────────┬────────┐                         ┌────────┬────────┬────────┐
              KC_F10  ,KC_F11  ,KC_F12  ,                          KC_F7   ,KC_F8   ,KC_F9   ,
  //┌────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┐
     QK_BOOT ,KC_F1   ,KC_F2   ,KC_F3   ,                          KC_F4   ,KC_F5   ,KC_F6   ,XXXXXXX ,
  //└────────┴────────┴────────┼────────┼────────┐       ┌────────┼────────┼────────┴────────┴────────┘
                                DM_PLY1 ,DM_REC1 ,        DM_REC2 ,DM_PLY2 
  //                           └────────┴────────┘       └────────┴────────┘
  )

};
bool set_scrolling = false;

#if defined(POINTING_DEVICE_DRIVER_pimoroni_trackball)

void pointing_device_init_user(void) {
    #ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
    #endif
    #ifdef POINTING_DEVICE_DRIVER_pimoroni_trackball
    pimoroni_trackball_set_rgbw(50, 50, 0, 25);
    #endif
}

bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case SCROLL:
            return true;
        default:
            return false;
    }
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (set_scrolling) {
        mouse_report.h = mouse_report.x;
        mouse_report.v = mouse_report.y;
        mouse_report.x = 0;
        mouse_report.y = 0;
    } else {
        if (abs(mouse_report.x) > 1)
        {
            mouse_report.x *= 5;
        }

        if (abs(mouse_report.y) > 1)
        {
            mouse_report.y *= 5;
        }

    }
    return mouse_report;
}
#endif

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_O:
        case GUI_L:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

bool _num_word_enabled = false;

void activate_num_word(void) {
    _num_word_enabled = true;
    layer_on(_NUMWORD);
}

void deactivate_num_word(void) {
    _num_word_enabled = false;
    layer_off(_NUMWORD);
}

enum combo_events {
  CAPS_COMBO,
  NUM_WORD_ON,
  NUM_WORD_OFF,
  TOGGLE_NAV,
  RIGHT_HAND,
  FUNCTION_LAYER,
  GREATER_EQUAL,
  LESS_EQUAL,
  NOT_EQUAL,
  APPROX_EQUAL,
  PLUS_EQUAL,
  MINUS_EQUAL,
  AST_EQUAL,
  ARROW,
  DOUBLE_ARROW,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM caps_word[] = {NAV_N   ,SYM1_E  ,SYM2_A, COMBO_END};
const uint16_t PROGMEM num_word_on[] = {NAV_T   ,SYM1_R  ,SYM2_S, COMBO_END};
const uint16_t PROGMEM num_word_off[] = {SYM_1 ,SYM_2 ,NAV_3, COMBO_END};
const uint16_t PROGMEM toggle_nav[] = {CTL_H   ,ALT_U   ,GUI_O, COMBO_END};
const uint16_t PROGMEM right_hand[] = {REPEAT, KC_SPC, COMBO_END};
const uint16_t PROGMEM function_layer[] = {NAV_N   ,SYM1_E  ,SYM2_A, NUM_C, COMBO_END};
const uint16_t PROGMEM greater_equal[] = {KC_GTHN, KC_RBRC, COMBO_END};
const uint16_t PROGMEM less_equal[] = {KC_LTHN, KC_LBRC, COMBO_END};
const uint16_t PROGMEM not_equal[] = {KC_EXLM, KC_QST, COMBO_END};
const uint16_t PROGMEM approx_equal[] = {KC_PIPE, KC_PND, COMBO_END};
const uint16_t PROGMEM plus_equal[] = {SYM_1, GUI_PLS, COMBO_END};
const uint16_t PROGMEM minus_equal[] = {KC_MINS, KC_NUHS, COMBO_END};
const uint16_t PROGMEM ast_equal[] = {KC_ASTR, KC_ATS, COMBO_END};
const uint16_t PROGMEM arrow[] = {KC_MINS, KC_NUBS, COMBO_END};
const uint16_t PROGMEM double_arrow[] = {KC_EQL, SYM_6, COMBO_END};

combo_t key_combos[] = {
    [CAPS_COMBO] = COMBO_ACTION(caps_word),
    COMBO(toggle_nav, TO(_NAV)),
    [NUM_WORD_ON] = COMBO_ACTION(num_word_on),
    [NUM_WORD_OFF] = COMBO_ACTION(num_word_off),
    COMBO(right_hand, OSL(_ONE_HAND)),
    [FUNCTION_LAYER] = COMBO_ACTION(function_layer),
    [GREATER_EQUAL] = COMBO_ACTION(greater_equal),
    [LESS_EQUAL] = COMBO_ACTION(less_equal),
    [NOT_EQUAL] = COMBO_ACTION(not_equal),
    [APPROX_EQUAL] = COMBO_ACTION(approx_equal),
    [PLUS_EQUAL] = COMBO_ACTION(plus_equal),
    [MINUS_EQUAL] = COMBO_ACTION(minus_equal),
    [AST_EQUAL] = COMBO_ACTION(ast_equal),
    [ARROW] = COMBO_ACTION(arrow),
    [DOUBLE_ARROW] = COMBO_ACTION(double_arrow),
};



void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case GREATER_EQUAL:
      if (pressed) {
        tap_code16(KC_GTHN);
        tap_code16(KC_EQL);
      }
      break;
    case LESS_EQUAL:
      if (pressed) {
        tap_code16(KC_LTHN);
        tap_code16(KC_EQL);
      }
      break;
    case NOT_EQUAL:
      if (pressed) {
        tap_code16(KC_EXLM);
        tap_code16(KC_EQL);
      }
      break;
    case APPROX_EQUAL:
      if (pressed) {
        tap_code16(KC_PIPE);
        tap_code16(KC_EQL);
      }
      break;
    case PLUS_EQUAL:
      if (pressed) {
        tap_code16(KC_PLUS);
        tap_code16(KC_EQL);
      }
      break;
    case AST_EQUAL:
      if (pressed) {
        tap_code16(KC_ASTR);
        tap_code16(KC_EQL);
      }
      break;
    case MINUS_EQUAL:
      if (pressed) {
        tap_code16(KC_MINS);
        tap_code16(KC_EQL);
      }
      break;
    case ARROW:
      if (pressed) {
        tap_code16(KC_MINS);
        tap_code16(KC_GTHN);
      }
      break;
    case DOUBLE_ARROW:
      if (pressed) {
        tap_code16(KC_EQL);
        tap_code16(KC_GTHN);
      }
      break;
    case CAPS_COMBO:
      if (pressed) {
        caps_word_toggle();  // Activate Caps Word!
      }
      break;
    case NUM_WORD_ON:
        if (pressed) {
            activate_num_word();
        }
        break;
    case NUM_WORD_OFF:
        if (pressed) {
            deactivate_num_word();
        }
        break;
    case FUNCTION_LAYER:
      if (pressed) {
        function_mods = get_mods();
      } else {
        set_oneshot_layer(_FUN, ONESHOT_START);
        clear_oneshot_layer_state(ONESHOT_PRESSED);
      }
  }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            register_key_to_repeat(LSFT(keycode));  // Updates repeat key to include LSFT
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
        case REPEAT:
        case OK_SAL2:
        case OK_ALP2:
        case LSFT(KC_A) ... LSFT(KC_Z):
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

bool process_num_word(uint16_t keycode, const keyrecord_t *record) {
    if (!_num_word_enabled) return true;

    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            if (record->tap.count == 0) {
                return true;
            } else if (record->event.pressed) {
                return true;
            } else {
                keycode = keycode & 0xFF;
            }
    }
    switch (keycode) {
        case KC_1 ... KC_0:
        case KC_PERC:
        case KC_COMM:
        case KC_DOT:
        case KC_SLSH:
        case KC_MINS:
        case KC_ASTR:
        case KC_PPLS:
        case KC_CIRC:
        case KC_COLN:
        case KC_EQL:
        case KC_BSPC:
        case KC_X:
        case REPEAT:
        case REV_REP:
        case COM_SPC:
        case OK_ALP2:
        case OK_SAL2:
        case TO_ALP1:
        case XXXXXXX:
            break;
        default:
                deactivate_num_word();
    }
    return true;
}





void dynamic_macro_play_user(int8_t direction) {
    /* Sets the last_keycode_j to DM_PLYX after the dynamic macro has finished playing*/
    switch (direction)
    {
    case +1:
        register_key_to_repeat(DM_PLY1);
        return;
    case -1:
        register_key_to_repeat(DM_PLY2);
        return;
    }
}



bool register_tap_hold(uint16_t tap_keycode, uint16_t hold_keycode, keyrecord_t *record) {
    if (record->tap.count && record->event.pressed) {
        register_key_to_repeat(tap_keycode);
        tap_code16(tap_keycode);
        return false;
    } else if (record->event.pressed) {
        register_key_to_repeat(hold_keycode);
        tap_code16(hold_keycode);
        return false;
    } else {
        return true;
    }
}


void update_one_key_layer_flags(keyrecord_t *record) {
    if (record->event.pressed){
        if (sft_alpha_2_active) {
            sft_alpha_2_active = false;
            deactivate_sft_alpha_2 = true;
        }
        if (alpha_2_active) {
            alpha_2_active = false;
            deactivate_alpha_2 = true;
        }
    }
}

bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t enav_timer;
    static bool modified_repeat;

    if (!process_num_word(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case OK_SAL2:
            if(record->event.pressed) {
                layer_on(_SFT_ALPHA_2);
                sft_alpha_2_active = true;
                return false;
            } else {
                return true;
            }
        case OK_ALP2:
            if(record->event.pressed) {
                layer_on(_ALPHA_2);
                alpha_2_active = true;
                return false;
            } else {
                return true;
            }
        case TH_LEFT:
            return register_tap_hold(keycode, KC_HOME, record);
        case TH_RGHT:
            return register_tap_hold(keycode, KC_END, record);
        case TH_DOWN:
            return register_tap_hold(keycode, KC_PGDN, record);
        case TH_UP:
            return register_tap_hold(keycode, KC_PGUP, record);
        case TH_BSPC:
            return register_tap_hold(keycode, LCTL(KC_BSPC), record);
        case TH_COPY:
            return register_tap_hold(COPY, PASTE, record);
        case COM_SPC:
            if (record->event.pressed) {
                SEND_STRING(", ");
            }
            return true;
        case S_E_NAV:
            if(record->event.pressed){
                enav_timer = timer_read();
                register_mods(MOD_LSFT);
            } else {
                unregister_mods(MOD_LSFT);
                if (timer_elapsed(enav_timer) < TAPPING_TERM) {
                    layer_invert(_NAV);
                }
            }
            return false;
        case KC_F1 ... KC_F12:
            if(record->event.pressed){
                register_mods(function_mods);
                register_code16(keycode);
                register_key_to_repeat(keycode);
                unregister_mods(function_mods);
                register_mods(mod_state);
                return false;
            } else {
                return true;
            }
        case DM_PLY1:
        case DM_PLY2:
        case DM_REC1:
        case DM_REC2:
        /* Releases DM keys on the one shot layer so they are only sent to process_dynamic_macro() once */
            unregister_code16(keycode);
            /* Registering repeat for play is done in */
            return false;
        case REPEAT:
            /* When pressed with a modifier REPEAT acts as a oneshot swap hands layer which also turns the modifiers to one shot mods */
            if (record->event.pressed){
                if (!mod_state) {
                    modified_repeat = false;
                    update_repeat_key(record);
                    post_process_record_user(keycode, record);
                    return false;
                } else {
                    modified_repeat = true;
                    post_process_keycode = REPEAT;
                    /* One shot layer is done in post_process_record_user to avoid process action deactiviting the one shot layer
                       on the press on the REPEAT key */
                    return true;
                }
            } else {
                if (modified_repeat) {
                    clear_oneshot_layer_state(ONESHOT_PRESSED);
                    modified_repeat = false;
                    return true;
                } else {
                    update_repeat_key(record);
                    post_process_record_user(keycode, record);
                    return false;
                }
            }
            return false;
        case REV_REP:
            update_reverse_repeat_key(record);
            post_process_record_user(keycode, record);
            return false;
        case SCROLL:
            if (record->event.pressed) {
                set_scrolling = true;
            } else {
                set_scrolling = false;
            }
            return true;
        default:
            return true;
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    mod_state = get_mods() | get_oneshot_mods();
    update_one_key_layer_flags(record);

    bool res = _process_record_user(keycode, record);

    if (res && record->event.pressed) {
        register_key_to_repeat(keycode);
    }

    return res;

}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed){
        if (deactivate_sft_alpha_2){
        layer_off(_SFT_ALPHA_2);
        deactivate_sft_alpha_2 = false;
        }
        if (deactivate_alpha_2){
        layer_off(_ALPHA_2);
        deactivate_alpha_2 = false;
        }
    }
    switch (post_process_keycode) {
        case REPEAT:
            if (record->event.pressed) {
                set_oneshot_layer(_ONE_HAND, ONESHOT_START);
                add_oneshot_mods(mod_state);
            }
            break;
        default:
            break;
    }
    post_process_keycode = KC_NO;
}
