#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _ISRT 0
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
#define ALPHA_2 OSL(_ALPHA_2)
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
#define ALT_COM LALT_T(KC_COMM)
#define GUI_V   LGUI_T(KC_V)
#define GUI_DOT RGUI_T(KC_DOT)
// Layer taps
#define NUM_I   LT(_NUM. KC_I)
#define SYM2_S  LT(_SYM_2, KC_S)
#define SYM1_R  LT(_SYM_1, KC_R)
#define NAV_T   LT(_NAV, KC_T)
#define NAV_N   LT(_NAV, KC_N)
#define SYM1_E  LT(_SYM_1, KC_E)
#define SYM2_A  LT(_SYM_2, KC_A)
#define NUM_C   LT(_NUM, KC_C)
// Layer toggles
#define TO_ALP1

#define KC_DQOT LSFT(KC_2)
#define KC_PND  LSFT(KC_3)
#define PASTE   LCTL(KC_V)
#define COPY    LCTL(KC_C)
#define CUT     LCTL(KC_X)
#define UNDO    LCTL(KC_Z)
#define REDO    LCTL(KC_Y)
#define CTL_LFT LCTL(KC_LEFT)
#define CTL_RGT LCTL(KC_RGHT)

#define SFT_V   LSFT(KC_V)
#define SFT_W   LSFT(KC_W)
#define SFT_M   LSFT(KC_M)
#define SFT_F   LSFT(KC_F)
#define SFT_Q   LSFT(KC_Q)
#define SFT_J   LSFT(KC_J)
#define SFT_P   LSFT(KC_P)
#define SFT_K   LSFT(KC_K)
#define SFT_B   LSFT(KC_B)
#define SFT_Z   LSFT(KC_Z)
#define SFT_X   LSFT(KC_X)
#define SFT_Y   LSFT(KC_Y)


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

  [_ISRT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_TAB  ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,KC_ENT  ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_ESC  ,GUI_L   ,ALT_G   ,CTL_D   ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,CTL_H   ,ALT_U   ,GUI_O   ,KC_BSPC ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,NUM_I   ,SYM2_S  ,SYM1_R  ,NAV_T   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,NAV_N   ,SYM1_E  ,SYM2_A  ,NUM_C   ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    KC_SPC  ,REPEAT  ,        A_SFT_2 ,ALPHA_2 ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_ALPHA_2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,GUI_V   ,ALT_W   ,CTL_M   ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,CTL_F   ,ALT_COM ,GUI_DOT ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_Q    ,KC_J    ,KC_P    ,KC_K    ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_B    ,KC_Z    ,KC_X    ,KC_Y    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    OS_SFT  ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
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
     _______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______         ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,_______ ,
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
     XXXXXXX ,XXXXXXX ,SFT_V   ,SFT_W   ,SFT_M   ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,SFT_F   ,KC_QUOT ,KC_DQOT ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,SFT_Q   ,SFT_J   ,SFT_P   ,SFT_K   ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,SFT_B   ,SFT_Z   ,SFT_X   ,SFT_Y   ,XXXXXXX ,
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
     XXXXXXX ,KC_I    ,KC_S    ,KC_R    ,KC_T    ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,KC_N    ,KC_E    ,KC_A    ,KC_C    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    KC_SPC  ,OS_SFT  ,        REPEAT  ,ALPHA_2 ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYM_1] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_I    ,KC_S    ,KC_R    ,KC_T    ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,KC_N    ,KC_E    ,KC_A    ,KC_C    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    KC_SPC  ,OS_SFT  ,        REPEAT  ,ALPHA_2 ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_SYM_2] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_I    ,KC_S    ,KC_R    ,KC_T    ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,KC_N    ,KC_E    ,KC_A    ,KC_C    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    KC_SPC  ,OS_SFT  ,        REPEAT  ,ALPHA_2 ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_NAV] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_I    ,KC_S    ,KC_R    ,KC_T    ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,KC_N    ,KC_UP   ,KC_A    ,KC_C    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_ENT  ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    KC_SPC  ,REPEAT  ,        REPEAT  ,KC_LCTL ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
  ),

  [_FUN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,                                            XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,DM_REC1 ,                          DM_REC2 ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_I    ,KC_S    ,KC_R    ,KC_T    ,XXXXXXX ,DM_PLY1 ,                          DM_PLY2 ,XXXXXXX ,KC_N    ,KC_E    ,KC_A    ,KC_C    ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,        XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,KC_APP  ,     XXXXXXX ,    KC_SPC  ,OS_SFT  ,        REPEAT  ,ALPHA_2 ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX
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
      case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
      case QK_MOMENTARY ... QK_MOMENTARY_MAX:
      case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
      case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
      case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
      case QK_TO ... QK_TO_MAX:
      case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
      case QK_MODS ... QK_MODS_MAX:
        return;
    }
    if (record->event.pressed) {
      last_modifier = get_mods() | get_oneshot_mods();
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
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t fnx_layer_timer;
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {
        case S_ENAV:
            if(record->event.pressed){
                fnx_layer_timer = timer_read();
                register_mod(MOD_LSFT);
            } else {
                unregister_mod(MOD_LSFT);
                if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM) {
                    layer_invert(_NAV);
                }
            }
            return false;
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
