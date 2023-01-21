#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _ALPHA_1 0

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_ALPHA_1] = LAYOUT(
  //         ┌────────┬────────┬────────┐                 ┌────────┬────────┬───────┐
              KC_L    ,KC_G    ,KC_D    ,                  KC_H    ,KC_U    ,KC_O   ,
  //┌────────┼────────┼────────┼────────┤                 ├────────┼────────┼───────┼────────┐
     KC_I    ,KC_S    ,KC_R    ,KC_T    ,                  KC_N    ,KC_E    ,KC_A   ,KC_C    ,
  //└────────┴────────┴────────┼────────┼────────┬────────┴────────┼────────┴───────┴────────┘
                                KC_SPC  ,QK_BOOT ,KC_K    ,KC_J
  //                           └────────┴────────┴────────┴────────┘
)

//   //         ┌────────┬────────┬────────┐                 ┌────────┬────────┬───────┐
//               GUI_L   ,ALT_G   ,CTL_D   ,                 ,CTL_H   ,ALT_U   ,GUI_O  ,
//   //┌────────┼────────┼────────┼────────┤                 ├────────┼────────┼───────┼────────┐
//      NUM_I   ,SYM2_S  ,SYM1_R  ,NAV_T   ,                 ,NAV_N   ,SYM1_E  ,SYM2_A ,NUM_C   ,
//   //└────────┴────────┴────────┼────────┼────────┬────────┴────────┼────────┴───────┴────────┘
//                                 KC_SPC  ,REPEAT  ,OK_SAL2 ,OK_ALP2 ,
//   //                           └────────┴────────┴────────┴────────┘
};
