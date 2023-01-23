#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _ALPHA_1 0
#define _ALPHA_2 1
#define _SAFE 2
#define _LHAND 3
#define _SFT_ALPHA_2 4
#define _NAV 5
#define _NUM 6
#define _SYM_1 7
#define _SYM_2 8
#define _FUN 9
#define _RHAND 10
#define _RNAV 11
#define _RNUM 12


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
  S_ENAV,
  OK_SAL2,
  OK_ALP2,
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
// #define ALPHA_2 OSL(_ALPHA_2)
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
// Layer taps
#define NUM_I   LT(_NUM, KC_I)
#define SYM2_S  LT(_SYM_2, KC_S)
#define SYM1_R  LT(_SYM_1, KC_R)
#define NAV_T   LT(_NAV, KC_T)
#define NAV_K   LT(_NAV, KC_K)
#define NAV_N   LT(_NAV, KC_N)
#define SYM1_E  LT(_SYM_1, KC_E)
#define SYM2_A  LT(_SYM_2, KC_A)
#define NUM_C   LT(_NUM, KC_C)
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


enum {
  U_SP = 0,
  DOT,
  CLN
};
qk_tap_dance_action_t tap_dance_actions[] = {
  [U_SP] = ACTION_TAP_DANCE_DOUBLE(KC_UNDS, KC_SPC),
  [DOT] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COMM),
  [CLN] = ACTION_TAP_DANCE_DOUBLE(KC_COLON, KC_SEMICOLON)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ALPHA_1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_TAB  ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,KC_ENT  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,SFT_Z   ,GUI_L   ,ALT_G   ,CTL_D   ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,CTL_H   ,ALT_U   ,GUI_O   ,KC_BSPC ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,NUM_I   ,SYM2_S  ,SYM1_R  ,NAV_T   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,NAV_N   ,SYM1_E  ,SYM2_A  ,NUM_C   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    KC_SPC  ,REPEAT  ,        OK_SAL2 ,OK_ALP2 ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
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
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    OS_SFT  ,DM_REC1 ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SAFE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,                          _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,        _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     _______ ,    _______ ,_______ ,        _______ ,_______ ,    _______ ,     _______ ,_______ ,_______ ,_______
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
     XXXXXXX ,XXXXXXX ,SFT_V   ,SFT_W   ,SFT_M   ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,SFT_F   ,KC_QUOT ,SFT_Z   ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,SFT_Q   ,SFT_J   ,SFT_P   ,SFT_K   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,SFT_B   ,KC_COMM ,SFT_X   ,SFT_Y   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    KC_UNDS ,XXXXXXX ,        REPEAT  ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NUM] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_DOT  ,KC_0    ,KC_1    ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,KC_4    ,KC_5    ,KC_6    ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MINS ,KC_PPLS ,KC_2    ,KC_3    ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_7    ,KC_8    ,KC_9    ,KC_EQL  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    KC_SPC  ,OS_SFT  ,        TO_ALP1 ,KC_LCTL ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
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
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    KC_SPC  ,OS_SFT  ,        REPEAT  ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYM_2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_ATS  ,KC_EXLM ,XXXXXXX ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,KC_LPRN ,KC_RPRN ,KC_SCLN ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_ASTR ,KC_PERC ,KC_QST  ,KC_DQOT ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_LCBR ,KC_RCBR ,KC_AMPR ,KC_CLN  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    KC_SPC  ,OS_SFT  ,        REPEAT  ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_ESC  ,TH_COPY ,KC_T    ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,KC_DEL  ,TH_UP   ,TH_BSPC ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_TAB  ,KC_DEL  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,TH_LEFT ,TH_DOWN ,TH_RGHT ,KC_ENT  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    S_ENAV  ,KC_LALT ,        TO_ALP1 ,KC_LCTL ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_FUN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,KC_F11  ,KC_F10  ,KC_F1   ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,KC_F4   ,KC_F5   ,KC_F6   ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,QK_BOOT ,KC_F12  ,KC_F2   ,KC_F3   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_F7   ,KC_F8   ,KC_F9   ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    DM_PLY1 ,DM_REC1 ,        DM_PLY2 ,DM_REC2 ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
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

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GUI_O:
        case GUI_L:
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

enum combo_events {
  CAPS_COMBO,
  TOGGLE_NAV,
  FUNCTION_LAYER,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM caps_word[] = {NAV_N   ,SYM1_E  ,SYM2_A, COMBO_END};
const uint16_t PROGMEM toggle_nav[] = {CTL_H   ,ALT_U   ,GUI_O, COMBO_END};
const uint16_t PROGMEM function_layer[] = {NAV_N   ,SYM1_E  ,SYM2_A, NUM_C, COMBO_END};
combo_t key_combos[] = {
    [CAPS_COMBO] = COMBO_ACTION(caps_word),
    COMBO(toggle_nav, TO(_NAV)),
    [FUNCTION_LAYER] = COMBO_ACTION(function_layer),
};

uint8_t function_mods;
void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case CAPS_COMBO:
      if (pressed) {
        caps_word_toggle();  // Activate Caps Word!
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
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case REPEAT:
        case OK_SAL2:
        case OK_ALP2:
        case LSFT(KC_A) ... LSFT(KC_Z):
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF
uint16_t last_keycode = KC_NO;
uint8_t last_modifier = 0;
uint16_t pressed_keycode = KC_NO;

void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
  if (keycode != REPEAT) {
    // Early return when holding down a pure layer key
    // to retain modifiers
    switch (keycode) {
      case QK_MODS ... QK_MODS_MAX:
        if (GET_TAP_KC(keycode)) break; // if keycode is modified in keymap treat as a normal keycode
      case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
      case QK_MOMENTARY ... QK_MOMENTARY_MAX:
      case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
      case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
      case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
      case QK_TO ... QK_TO_MAX:
      case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
        return;
    }
    if (record->event.pressed) {
      if(is_caps_word_on()){
        last_modifier = get_mods() | get_oneshot_mods() | MOD_BIT(KC_LSFT);
      } else {
        last_modifier = get_mods() | get_oneshot_mods();
      }
      switch (keycode) {
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
          last_keycode = GET_TAP_KC(keycode);
          break;
        default:
          last_keycode = keycode;
          break;
        }
    }
  } else { // keycode == REPEAT
    if (record->event.pressed) {
      pressed_keycode = last_keycode;
      register_mods(last_modifier);
      register_code16(pressed_keycode);
      unregister_mods(last_modifier);
    } else {
      unregister_code16(pressed_keycode);
    }
  }
}


void app_switch(uint16_t keycode, const keyrecord_t *record) {
    if (record->event.pressed) {
      register_code(KC_LGUI);
      tap_code(keycode);
      // Ensures repeat key only sends the relevant number
      last_keycode = keycode;
      last_modifier = 0;
    } else {
      unregister_code(KC_LGUI);
    }
}

uint8_t mod_state;
bool alpha_2_active = false;
bool sft_alpha_2_active = false;
bool deactivate_alpha_2 = false;
bool deactivate_sft_alpha_2 = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t fnx_layer_timer;
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    if (record->event.pressed){
        if (sft_alpha_2_active)
        {
        sft_alpha_2_active = false;
        // layer_off(_ALPHA_2);
        deactivate_sft_alpha_2 = true;
        }
        if (alpha_2_active)
        {
        alpha_2_active = false;
        // layer_off(_ALPHA_2);
        deactivate_alpha_2 = true;
        }
    }

    switch (keycode) {
        case OK_SAL2:
            if(record->event.pressed)
            {
                layer_on(_SFT_ALPHA_2);
                sft_alpha_2_active = true;
                // return false;
            }
            break;
        case OK_ALP2:
            if(record->event.pressed)
            {
                layer_on(_ALPHA_2);
                alpha_2_active = true;
                // return false;
            }
            break;
        case TH_LEFT:
            if (record->tap.count && record->event.pressed) {
                process_repeat_key(keycode, record);
            } else if (record->event.pressed) {
                process_repeat_key(KC_HOME, record);
                tap_code16(KC_HOME);
                return false;
            }
            break;
        case TH_RGHT:
            if (record->tap.count && record->event.pressed) {
                process_repeat_key(keycode, record);
            } else if (record->event.pressed) {
                process_repeat_key(KC_END, record);
                tap_code16(KC_END);
                return false;
            }
            break;
        case TH_DOWN:
            if (record->tap.count && record->event.pressed) {
                process_repeat_key(keycode, record);
            } else if (record->event.pressed) {
                process_repeat_key(KC_PGDN, record);
                tap_code16(KC_PGDN);
                return false;
            }
            break;
        case TH_UP:
            if (record->tap.count && record->event.pressed) {
                process_repeat_key(keycode, record);
            } else if (record->event.pressed) {
                process_repeat_key(KC_PGUP, record);
                tap_code16(KC_PGUP);
                return false;
            }
            break;
        case TH_BSPC:
            if (record->tap.count && record->event.pressed) {
                process_repeat_key(keycode, record);
            } else if (record->event.pressed) {
                process_repeat_key(LCTL(KC_BSPC), record);
                tap_code16(LCTL(KC_BSPC));
                return false;
            }
            break;
        case TH_COPY:
            if (record->tap.count && record->event.pressed) {
                process_repeat_key(COPY, record);
                tap_code16(COPY);
                return false;
            } else if (record->event.pressed) {
                process_repeat_key(PASTE, record);
                tap_code16(PASTE);
                return false;
            }
            break;
        case S_ENAV:
            if(record->event.pressed){
                fnx_layer_timer = timer_read();
                register_mods(MOD_LSFT);
            } else {
                unregister_mods(MOD_LSFT);
                if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM) {
                    layer_invert(_NAV);
                }
            }
            return false;
        case KC_F1 ... KC_F12:
            if(record->event.pressed){
                register_mods(function_mods);
                register_code16(keycode);
                unregister_mods(function_mods);
                register_mods(mod_state);
                last_modifier = function_mods;
                last_keycode = keycode;
                return false;
            }
            break;
        // case APP_1:
        //   app_switch(KC_1, record);
        //   break;
        // case APP_2:
        //   app_switch(KC_2, record);
        //   break;
        // case APP_3:
        //   app_switch(KC_3, record);
        //   break;
        // case APP_4:
        //   app_switch(KC_4, record);
        //   break;
        // case APP_5:
        //   app_switch(KC_5, record);
        //   break;
        // case APP_6:
        //   app_switch(KC_6, record);
        //   break;
        // case APP_7:
        //   app_switch(KC_7, record);
        //   break;
        // case APP_8:
        //   app_switch(KC_8, record);
        //   break;
        // case APP_9:
        //   app_switch(KC_9, record);
        //   break;
        // case APP_0:
        //   app_switch(KC_0, record);
        //   break;
        default:
          process_repeat_key(keycode, record);
    }
    return true;

};
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
}
