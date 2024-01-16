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

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
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
//  QWERTY = SAFE_RANGE,
//  LHAND,
//  MEDIA,
//  NAV,
//  MOUSE,
//  SYM,
//  NUM,
//  FUN,`
//  RHAND,
//  RNAV
  REPEAT = SAFE_RANGE,
  REV_REP,
  RESET,
  S_E_NAV,
  OK_SAL2,
  OK_ALP2,
  COM_SPC,
  SCROL,
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
// Shortcut to make keymap more readable
#define OS_ALP2 OSL(_ALPHA_2)
#define OS_RAL2 OSL(_RALPHA_2)
#define A_SFT_2 OSL(_SFT_ALPHA_2)
#define OS_SFT  OSM(MOD_LSFT)

// Mod taps
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

// Layer taps
#define NUM_MIN LT(_NUM, KC_MINS)
#define NUM_I   LT(_NUM, KC_I)
#define SYM2_S  LT(_SYM_2, KC_S)
#define SYM1_R  LT(_SYM_1, KC_R)
#define NAV_T   LT(_NAV, KC_T)
#define NAV_K   LT(_NAV, KC_K)
#define NAV_N   LT(_NAV, KC_N)
#define SYM1_E  LT(_SYM_1, KC_E)
#define SYM2_A  LT(_SYM_2, KC_A)
#define NUM_C   LT(_NUM, KC_C)
#define NUM_EQL LT(_NUM, KC_EQL)

#define SYM_1   LT(_SYM_2, KC_1)
#define SYM_2   LT(_SYM_1, KC_2)
#define NAV_3   LT(_NAV, KC_3)
#define NAV_4   LT(_NAV, KC_4)
#define SYM_5   LT(_SYM_1, KC_5)
#define SYM_6   LT(_SYM_2, KC_6)

// Layer toggles
#define TO_ALP1 TO(_ALPHA_1)

// Symbols
#define KC_DQOT LSFT(KC_2)
#define KC_PND  LSFT(KC_3)
#define KC_LTHN LSFT(KC_COMM)
#define KC_GTHN LSFT(KC_DOT)
#define KC_CLN  LSFT(KC_SCLN)
#define KC_QST  LSFT(KC_SLSH)
#define KC_PPE  LSFT(KC_NUBS)
#define KC_ATS  LSFT(KC_QUOT)

// Actions
#define PASTE   LCTL(KC_V)
#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
#define UNDO    LCTL(KC_Z)
#define REDO    LCTL(KC_Y)
#define CTL_LFT LCTL(KC_LEFT)
#define CTL_RGT LCTL(KC_RGHT)
#define SRN_SHT LGUI(LSFT(KC_S))

// Shifted letters
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

// Tap-hold keys
#define TH_RGHT LT(0, KC_RGHT)
#define TH_LEFT LT(0, KC_LEFT)
#define TH_DOWN LT(0, KC_DOWN)
#define TH_UP   LT(0, KC_UP)
#define TH_COPY LT(0, KC_C)
#define TH_BSPC LT(0, KC_BSPC)

//#define APP_1 LGUI(KC_1)
//#define APP_2 LGUI(KC_2)
//#define APP_3 LGUI(KC_3)
//#define APP_4 LGUI(KC_4)
//#define APP_5 LGUI(KC_5)
//#define APP_6 LGUI(KC_6)
//#define APP_7 LGUI(KC_7)
//#define APP_8 LGUI(KC_8)
//#define APP_9 LGUI(KC_9)
//#define APP_0 LGUI(KC_0)


// enum {
//   U_SP = 0,
//   DOT,
//   CLN
// };
// qk_tap_dance_action_t tap_dance_actions[] = {
//   [U_SP] = ACTION_TAP_DANCE_DOUBLE(KC_UNDS, KC_SPC),
//   [DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMM),
//   [CLN] = ACTION_TAP_DANCE_DOUBLE(KC_COLON, KC_SEMICOLON)
// };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ALPHA_1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,SFT_Z   ,GUI_L   ,ALT_G   ,CTL_D   ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,CTL_H   ,ALT_U   ,GUI_O   ,KC_BSPC ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,NUM_I   ,SYM2_S  ,SYM1_R  ,NAV_T   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,NAV_N   ,SYM1_E  ,SYM2_A  ,NUM_C   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    SPC_SFT ,REPEAT  ,        OK_SAL2 ,OK_ALP2 ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_BUTTON] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_ESC  ,KC_DEL  ,KC_APP  ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,KC_DEL  ,TH_UP   ,TH_BSPC ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_TAB  ,C(KC_Z) ,TH_COPY ,KC_BTN1 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,TH_LEFT ,TH_DOWN ,TH_RGHT ,KC_ENT  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    S_E_NAV ,SCROL  ,        OK_SAL2 ,KC_LCTL ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ONE_HAND] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,GUI_O   ,ALT_U   ,CTL_H   ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,CTL_H   ,ALT_U   ,GUI_O   ,KC_BSPC ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,NUM_C   ,SYM2_A  ,SYM1_E  ,NAV_N   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,NAV_N   ,SYM1_E  ,SYM2_A  ,NUM_C   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    OS_ALP2 ,OS_RAL2 ,        OK_SAL2 ,OK_ALP2 ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NUMWORD] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,GUI_PLS ,ALT_DOT ,CTL_0   ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,CTL_7   ,ALT_8   ,GUI_9   ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,NUM_MIN ,SYM_1   ,SYM_2   ,NAV_3   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,NAV_4   ,SYM_5   ,SYM_6   ,NUM_EQL ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    SPC_SFT ,REPEAT  ,        OK_SAL2 ,OK_ALP2 ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ALPHA_2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,GUI_V   ,ALT_W   ,CTL_M   ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,CTL_F   ,ALT_QOT ,GUI_Z   ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_Q    ,KC_J    ,KC_P    ,NAV_K   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_B    ,KC_DOT  ,KC_X    ,KC_Y    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    OS_SFT  ,REV_REP ,        OK_SAL2 ,TO_ALP1 ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_RALPHA_2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,GUI_Z   ,ALT_QOT ,CTL_F   ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,CTL_F   ,ALT_QOT ,GUI_Z   ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_Y    ,KC_X    ,KC_DOT  ,KC_B    ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_B    ,KC_DOT  ,KC_X    ,KC_Y    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    TO_ALP1 ,REV_REP ,        OK_SAL2 ,TO_ALP1 ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),
//  [_LHAND] = LAYOUT(
//  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
//     KC_ESC  ,APP_1   ,APP_2   ,APP_3   ,APP_4   ,APP_5   ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//     KC_BSPC ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//     KC_ENT  ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,KC_SPC  ,TG(_RNAV)       ,TO_BASE ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
//     _______ ,KC_LGUI ,KC_LALT ,FUN_DEL ,     RNM_ESC ,    OS_RHND ,SYM_TAB ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
//  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
//  ),


  [_SFT_ALPHA_2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,SFT_V   ,SFT_W   ,SFT_M   ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,SFT_F   ,COM_SPC ,SFT_Z   ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,SFT_Q   ,SFT_J   ,SFT_P   ,SFT_K   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,SFT_B   ,KC_COMM ,SFT_X   ,SFT_Y   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    KC_UNDS ,RESET   ,        REPEAT  ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,GUI_PLS ,ALT_DOT ,CTL_0   ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,CTL_7   ,ALT_8   ,GUI_9   ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,NUM_MIN ,SYM_1   ,SYM_2   ,NAV_3   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,NAV_4   ,SYM_5   ,SYM_6   ,NUM_EQL ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    SPC_SFT ,OS_SFT  ,        OK_SAL2 ,KC_LCTL ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYM_1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_PND  ,KC_NUHS ,KC_DLR  ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,KC_LTHN ,KC_GTHN ,KC_CIRC ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_GRV  ,KC_PIPE ,KC_MINS ,KC_NUBS ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_LBRC ,KC_RBRC ,KC_PPE  ,KC_SLSH ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    SPC_SFT ,OS_SFT  ,        OK_SAL2 ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYM_2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_ATS  ,KC_EXLM ,SRN_SHT ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,KC_LPRN ,KC_RPRN ,KC_SCLN ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_ASTR ,KC_PERC ,KC_QST  ,KC_DQOT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_LCBR ,KC_RCBR ,KC_AMPR ,KC_CLN  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    SPC_SFT ,OS_SFT  ,        REPEAT  ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_ESC  ,KC_DEL  ,KC_APP  ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,KC_DEL  ,TH_UP   ,TH_BSPC ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_TAB  ,C(KC_Z) ,TH_COPY ,SRN_SHT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,TH_LEFT ,TH_DOWN ,TH_RGHT ,KC_ENT  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    S_E_NAV ,KC_LALT ,        OK_SAL2 ,KC_LCTL ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_FUN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_F10  ,KC_F11  ,KC_F12  ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,KC_F7   ,KC_F8   ,KC_F9   ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,QK_BOOT ,KC_F1   ,KC_F2   ,KC_F3   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_F4   ,KC_F5   ,KC_F6   ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    DM_PLY1 ,DM_REC1 ,        DM_REC2 ,DM_PLY2 ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  )

//    [_RHAND] = LAYOUT(
//  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
//     KC_DEL  ,APP_0   ,APP_9   ,APP_8   ,APP_7   ,APP_6   ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//     KC_BSPC ,TD(CLN) ,KC_Y    ,KC_U    ,KC_L    ,KC_J    ,DM_REC2 ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//     KC_ENT  ,RGUI_O  ,LALT_I  ,RCTL_E  ,RSFT_N  ,KC_M    ,DM_PLY2 ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//     _______ ,KC_SLSH ,KC_DOT  ,KC_COMM ,KC_H    ,KC_K    ,_______ ,_______ ,        TO_BASE ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
//     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
//  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
//  ),
//
//      [_RNAV] = LAYOUT(
//  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
//     _______ ,APP_0   ,APP_9   ,APP_8   ,APP_7   ,APP_6   ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//     KC_BSPC ,UNDO    ,CUT    ,COPY    ,PASTE   ,REDO    ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//     KC_ENT  ,CTL_LFT ,KC_LEFT ,KC_UP   ,KC_DOWN ,KC_RGHT ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//     _______ ,KC_INS  ,KC_HOME ,KC_PGUP ,KC_PGDN ,KC_END  ,TO_LHND ,TG(_RNUM),      TO_BASE ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
//  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
//     _______ ,_______ ,_______ ,_______ ,     KC_ESC  ,    KC_SPC  ,KC_TAB  ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
//  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
//  ),
//
//    [_RNUM] = LAYOUT(
//  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
//     _______ ,APP_1   ,APP_2   ,APP_3   ,APP_4   ,APP_5   ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//     KC_BSPC ,KC_ASTR ,KC_7    ,KC_8    ,KC_9    ,KC_PLUS ,_______ ,                          _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
//  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//     KC_ENT  ,KC_SLSH ,KC_4    ,KC_5    ,KC_6    ,KC_MINS ,_______ ,                          _______ ,XXXXXXX ,KC_RSFT ,KC_RCTL ,KC_LALT ,KC_RGUI ,XXXXXXX ,
//  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
//     _______ ,KC_CIRC ,KC_1    ,KC_2    ,KC_3    ,KC_EQL  ,TO_LHND ,_______ ,        TO_BASE ,TO_BASE ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_RALT ,XXXXXXX ,XXXXXXX ,
//  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
//     _______ ,_______ ,KC_0    ,KC_UNDS ,     TD(DOT) ,    TD(U_SP),KC_0    ,        KC_ENT  ,KC_BSPC ,    KC_DEL  ,     _______ ,_______ ,_______ ,_______
//  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
//  ),

};
bool set_scrolling = false;

#if defined(POINTING_DEVICE_DRIVER_pimoroni_trackball)

bool set_scroll = false;

typedef enum {
    BASE_COL,
    NUM_COL,
    CAPS_COL,
    RECORD_COL
} color;

#ifdef POINTING_DEVICE_DRIVER_pimoroni_trackball
void set_trackball_color(color col) {
    switch (col) {
        case BASE_COL:
            pimoroni_trackball_set_rgbw(0, 0, 0, 255);
            break;
        case RECORD_COL:
            pimoroni_trackball_set_rgbw(255, 0, 0, 0);
            break;
        case NUM_COL:
            pimoroni_trackball_set_rgbw(0, 255, 0, 0);
            break;
        case CAPS_COL:
            pimoroni_trackball_set_rgbw(0, 0, 255, 0);
            break;
    }
}
#endif

// in keymap.c:
void pointing_device_init_user(void) {
    #ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
    #endif
    #ifdef POINTING_DEVICE_DRIVER_pimoroni_trackball
    set_trackball_color(BASE_COL);
    #endif
}

bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch(keycode) {
        case SCROL:
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

        // mouse_report.x = mouse_report.x * mouse_report.x * mouse_report.x ;
        // mouse_report.y = mouse_report.y * mouse_report.y * mouse_report.y ;
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
    #ifdef POINTING_DEVICE_DRIVER_pimoroni_trackball
    set_trackball_color(NUM_COL);
    #endif
}

void deactivate_num_word(void) {
    _num_word_enabled = false;
    layer_off(_NUMWORD);
    #ifdef POINTING_DEVICE_DRIVER_pimoroni_trackball
    set_trackball_color(BASE_COL);
    #endif
}

enum combo_events {
  CAPS_COMBO_1,
  CAPS_COMBO_2,
  NUM_WORD_ON_1,
  NUM_WORD_ON_2,
//   TOGGLE_NAV,
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

const uint16_t PROGMEM caps_word_1[] = {NAV_N   ,SYM1_E  ,SYM2_A, COMBO_END};
const uint16_t PROGMEM caps_word_2[] = {NAV_4   ,SYM_5   ,SYM_6  , COMBO_END};
const uint16_t PROGMEM num_word_on_1[] = {NAV_T   ,SYM1_R  ,SYM2_S, COMBO_END};
const uint16_t PROGMEM num_word_on_2[] = {SYM_1 ,SYM_2 ,NAV_3, COMBO_END};
// const uint16_t PROGMEM toggle_nav[] = {CTL_H   ,ALT_U   ,GUI_O, COMBO_END};
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
const uint16_t PROGMEM double_arrow[] = {NUM_EQL, SYM_6, COMBO_END};

combo_t key_combos[] = {
    [CAPS_COMBO_1] = COMBO_ACTION(caps_word_1),
    [CAPS_COMBO_2] = COMBO_ACTION(caps_word_2),
    // COMBO(toggle_nav, TO(_NAV)),
    [NUM_WORD_ON_1] = COMBO_ACTION(num_word_on_1),
    [NUM_WORD_ON_2] = COMBO_ACTION(num_word_on_2),
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
    case CAPS_COMBO_1:
    case CAPS_COMBO_2:
      if (pressed) {
        deactivate_num_word();
        caps_word_on();  // Activate Caps Word!
        #ifdef POINTING_DEVICE_DRIVER_pimoroni_trackball
        set_trackball_color(CAPS_COL);
        #endif
      }
      break;
    case NUM_WORD_ON_1:
    case NUM_WORD_ON_2:
        if (pressed) {
            caps_word_off();
            activate_num_word();
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
            #ifdef POINTING_DEVICE_DRIVER_pimoroni_trackball
            set_trackball_color(BASE_COL);
            #endif
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
            // key held
                // SEND_STRING("key held");
                return true;
            } else if (record->event.pressed) {
                // SEND_STRING("tap pressed");
                return true;
            } else {
                // SEND_STRING("tap released");
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
        // case KC_UNDS:
        case KC_BSPC:
        case KC_X:
        case REPEAT:
        case REV_REP:
        // case KC_ENT:
        case COM_SPC:
        case OK_ALP2:
        case OK_SAL2:
        case TO_ALP1:
        case XXXXXXX:
            // Don't disable for above keycodes
            break;
        default:
            // if (record->event.pressed) {
                deactivate_num_word();
            // }
    }
    return true;
}



// void process_repeat_key(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode)
//     {
//     case REPEAT:
//         update_repeat_key(record);
//         break;
//     case REV_REP:
//         update_reverse_repeat_key(record);
//         break;
//     default:
//         if (record->event.pressed){
//             register_key_to_repeat(keycode);
//         }
//     }
// }
void register_dm_play_to_repeat(int8_t direction) {
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

void dynamic_macro_play_user(int8_t direction) {
    /* Sets the last_keycode_j to DM_PLYX after the dynamic macro has finished playing*/
    // send_string(" PLAY_RECORDING_SET_LAST_TO_PLAY ");
    register_dm_play_to_repeat(direction);
}

void dynamic_macro_record_start_user(void) {
    #ifdef POINTING_DEVICE_DRIVER_pimoroni_trackball
    set_trackball_color(RECORD_COL);
    #endif
    // send_string(" START_RECORDING_SET_LAST_TO_STP ");
    register_key_to_repeat(DM_RSTP);
}

void dynamic_macro_record_end_user(int8_t direction) {
    #ifdef POINTING_DEVICE_DRIVER_pimoroni_trackball
    set_trackball_color(BASE_COL);
    #endif
    // send_string(" END_RECORDING_SET_LAST_TO_PLAY");
    register_dm_play_to_repeat(direction);
}

// void app_switch(uint16_t keycode, const keyrecord_t *record) {
//     if (record->event.pressed) {
//       register_code(KC_LGUI);
//       tap_code(keycode);
//       last_keycode_j = keycode;
//       last_modifier = 0;
//     } else {
//       unregister_code(KC_LGUI);
//     }
// }

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
        case RESET:
            if(record->event.pressed){
                layer_clear();
                return true;
            } else {
                return true;
            }
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
            return register_tap_hold(LCTL(KC_BSPC), keycode, record);
        case TH_COPY:
            return register_tap_hold(COPY, PASTE, record);
        case COM_SPC:
            if (record->event.pressed) {
                SEND_STRING(", ");
            }
            return true;
        // case SPC_SFT:
        //     if (record->tap.count && record->event.pressed) {
        //         // Space has been sent
        //         if (IS_LAYER_ON(_NUMWORD)){
        //             layer_invert(_NUMWORD);
        //         }
        //     }
        //     return true;
        case S_E_NAV:
            if(record->event.pressed){
                enav_timer = timer_read();
                register_mods(MOD_LSFT);
            } else {
                unregister_mods(MOD_LSFT);
                if (timer_elapsed(enav_timer) < TAPPING_TERM) {
                    layer_off(_NAV);
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
        case DM_REC1:
        case DM_REC2:
            // send_string(" CASE_REC_PROCESS_USER ");
        case DM_PLY1:
        case DM_PLY2:
            // send_string(" CASE_PLAY_PROCESS_USER ");
        /* Releases DM keys on the one shot layer so they are only sent to process_dynamic_macro() once */
            unregister_code16(keycode);
            /* Registering repeat for play is done in *dynamic_macro_play_user()*/
            return false;
        case REPEAT:
            /* When pressed with a modifier REPEAT acts as a oneshot swap hands layer which also turns the modifiers to one shot mods */
            if (record->event.pressed){
                if (!mod_state) {
                    modified_repeat = false;
                    // #ifdef POINTING_DEVICE_DRIVER_pimoroni_trackball
                    // if (set_scroll) {
                    //     if (record->event.pressed) {
                    //         set_scrolling = true;
                    //     } else {
                    //         set_scrolling = false;
                    //     }
                    //     return false;
                    // }
                    // #endif
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
        case SCROL:
            if (record->event.pressed) {
                set_scrolling = true;
            } else {
                set_scrolling = false;
            }
            return false;
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

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _BUTTON:
        #ifdef POINTING_DEVICE_DRIVER_pimoroni_trackball
        set_scroll = true;
        #endif
        break;
    }
    return state;
}
