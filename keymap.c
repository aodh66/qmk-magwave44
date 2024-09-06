/*
 * Copyright 2024 @DreaM117er
 * Copyright 2024 QMK
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "features/achordion.h"
// #include "os_detection.h"
// #include "unicode.h"

// * -----------------------------
// * -- Home row mods (Recurva) --
// * -----------------------------
// Left-hand
#define HOME_S LGUI_T(KC_S)
#define HOME_N LALT_T(KC_N)
#define HOME_T LSFT_T(KC_T)
#define HOME_C LCTL_T(KC_C)

#define HOME_Z LGUI_T(KC_Z)
#define HOME_X LALT_T(KC_X)
#define HOME_K LSFT_T(KC_K)
#define HOME_G LCTL_T(KC_G)

// Right-hand
#define HOME_H RCTL_T(KC_H)
#define HOME_E RSFT_T(KC_E)
#define HOME_A LALT_T(KC_A)
#define HOME_I RGUI_T(KC_I)

#define HOME_L RCTL_T(KC_L)
#define HOME_SLSH RSFT_T(KC_SLSH)
#define HOME_QUOT LALT_T(KC_QUOT)
#define HOME_COMM RGUI_T(KC_COMM)

#define MAGIC QK_AREP
#define OSS OSM(MOD_LSFT)

// * ------------------------
// * -- Macro Declarations --
// * ------------------------
enum custom_keycodes {
    // EMAIL = SAFE_RANGE,
    SS_QU = SAFE_RANGE,
    LINE_SELECT,
    LINE_COPY,
    BRACES,
    // MAGIC,
    ONE_SHOT_SHIFT,
};

// Tap Dance declarations
enum {
    MAGIC_REP,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // * Base (Recurva Colstag)
    [0] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_ESC,   KC_F,   KC_R,     KC_D,   KC_P,   KC_V,                           SS_QU,   KC_M,   KC_U,     KC_O,   KC_Y,   KC_DEL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            // KC_TAB,  HOME_S,  HOME_N,  HOME_T,  HOME_C,   KC_B,                         KC_DOT, HOME_H,  HOME_E,  HOME_A,  HOME_I,  KC_ENT,
        // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        //     KC_LCTL,  KC_Z,    KC_X,    KC_K,    KC_G,    KC_W,                          KC_J,   KC_L,  KC_SLSH, KC_QUOT, KC_COMM, KC_DEL,
            KC_TAB,  KC_S,  KC_N,  KC_T,  KC_C,   KC_B,                         KC_DOT, KC_H,  KC_E,  KC_A,  KC_I,  KC_ENT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_NO,  HOME_Z,    HOME_X,    HOME_K,    HOME_G,    KC_W,                          KC_J,   HOME_L,  HOME_SLSH, HOME_QUOT, HOME_COMM, LINE_SELECT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    KC_MUTE, MO(1), LT(3, KC_SPC), LCTL(KC_BSPC), TD(MAGIC_REP), OSM(MOD_LSFT), MO(2), LSG(KC_S) //snipping tool on press
        //`--------------------------'  `--------------------------'
        ),

    // * Nav/Ext
    [1] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_ESC,  KC_TAB,  KC_TAB, KC_HYPR, CW_TOGG, KC_CAPS,                      KC_PGUP, KC_HOME,  BRACES,  KC_END,  KC_BSPC, KC_DEL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_MEH,                      KC_PGDN, KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT,  KC_ENT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
        KC_NO, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_F),      KC_DEL,  LCTL(KC_TAB),  RCS(KC_TAB),   LALT(KC_TAB),  LCA(KC_TAB), LINE_COPY,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_TRNS, KC_TRNS, KC_NO, KC_NO, QK_REP, CW_TOGG, MO(4), TO(0) //moba
        //`--------------------------'  `--------------------------'
        ),

    // * Symbol
    [2] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_ESC, KC_EXLM,  KC_AT,  KC_HASH,  KC_DLR, KC_PERC,                        KC_CIRC, KC_AMPR, KC_ASTR, KC_UNDS, KC_PIPE, KC_DEL,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TAB,  KC_GRV,   KC_LT,  KC_LCBR, KC_LPRN, KC_LBRC,                      KC_EQL, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, KC_ENT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LCTL, KC_TILD, KC_GT,  KC_RCBR, KC_RPRN, KC_RBRC,                      KC_PLUS, KC_MINS, KC_COLN, KC_SCLN, KC_BSLS, LINE_SELECT,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_TRNS, MO(4), KC_ENT, KC_BSPC, KC_NO, KC_NO, KC_TRNS, TO(0)
        //`--------------------------'  `--------------------------'
        ),

    // * Numpad
    [3] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_ESC,  KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,                        KC_MINS,  KC_7,   KC_8,     KC_9,  KC_ASTR, KC_SLSH,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_TAB, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL,  KC_NO,                        KC_DOT,   KC_4,   KC_5,     KC_6,    KC_0,  KC_ENT,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_LCTL, KC_NO,   KC_NO,  KC_BSPC,  KC_DEL,  KC_NO,                        KC_PLUS,  KC_1,   KC_2,     KC_3,  KC_SLSH, KC_BSLS,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_TRNS, KC_NO, KC_TRNS, KC_NO, KC_BSPC, KC_SPC, KC_DEL, TO(0) //moba
        //`--------------------------'  `--------------------------'
        ),

    // * Function
    [4] = LAYOUT(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
            KC_NO,   LALT(KC_F4),   KC_NO,  QK_BOOT,  KC_NO,  KC_VOLU,                       KC_NO,    KC_F7,  KC_F8,   KC_F9,   KC_NO,  KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
            KC_NO,  KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_VOLD,                       KC_F12,   KC_F4,  KC_F5,   KC_F6,   KC_F10, KC_NO,
        //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
          KC_NO, KC_NO, KC_NO, KC_NO,  KC_MPLY,  KC_NO,                        KC_F11,   KC_F1,  KC_F2,   KC_F3,   KC_NO,  TO(4),
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
        KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, TO(0)
        //`--------------------------'  `--------------------------'
        )

// ! add a comma above if you're going to use these
    // // * Game (MOBA)
    // [5] = LAYOUT(
    //     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    //         KC_LSFT,   KC_F,    KC_R,    KC_D,    KC_P,   KC_V,                           SS_QU,   KC_M,   KC_U,     KC_O,   KC_Y,   KC_BSPC,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //         KC_TAB,   KC_S,    KC_N,    KC_T,    KC_C,   KC_B,                         KC_DOT, HOME_H,  HOME_E,  HOME_A,  HOME_I,  KC_ENT,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //         KC_LCTL,  KC_Z,    KC_X,    KC_K,    KC_G,   KC_W,                          KC_J,   KC_L,  KC_SLSH, KC_QUOT, KC_COMM, TO(0),
    //     //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    //     KC_MUTE, KC_LCTL, KC_SPC, KC_BSPC, QK_REP, KC_LSFT, MO(2), TO(0)
    //     //`--------------------------'  `--------------------------'
    //     )

    // // * Game (MOBA) Alt
    // [6] = LAYOUT(
    //     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    //         KC_ESC,   KC_5,    KC_6,    KC_7,    KC_8,   KC_9,                           SS_QU,   KC_M,   KC_U,     KC_O,   KC_Y,   KC_BSPC,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //         KC_LSFT,  KC_1,    KC_2,    KC_3,    KC_4,   KC_H,                         KC_DOT, HOME_H,  HOME_E,  HOME_A,  HOME_I,  KC_ENT,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //         KC_LALT,  KC_E,    KC_A,    KC_I,    KC_J,   KC_L,                          KC_J,   KC_L,  KC_SLSH, KC_QUOT, KC_COMM, KC_DEL,
    //     //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    //     KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, QK_REP, KC_LSFT, MO(2), TO(0)
    //     //`--------------------------'  `--------------------------'
    //     )
    // // * Game (FPS)
    // [7] = LAYOUT(
    //     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    //         KC_ESC,   KC_F,    KC_R,    KC_D,    KC_P,   KC_V,                           SS_QU,   KC_M,   KC_U,     KC_O,   KC_Y,   KC_BSPC,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //         KC_TAB,   KC_S,    KC_N,    KC_T,    KC_C,   KC_B,                         KC_DOT, HOME_H,  HOME_E,  HOME_A,  HOME_I,  KC_ENT,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //         KC_LCTL,  KC_Z,    KC_X,    KC_K,    KC_G,   KC_W,                          KC_J,   KC_L,  KC_SLSH, KC_QUOT, KC_COMM, KC_DEL,
    //     //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    //     KC_MUTE, MO(8), KC_SPC, KC_U, QK_REP, KC_LSFT, MO(2), TO(0)
    //     //`--------------------------'  `--------------------------'
    //     ),

    // // * Game (FPS) Alt
    // [8] = LAYOUT(
    //     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    //         KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,   KC_5,                           SS_QU,   KC_M,   KC_U,     KC_O,   KC_Y,   KC_BSPC,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //         KC_LSFT,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_H,                         KC_DOT, HOME_H,  HOME_E,  HOME_A,  HOME_I,  KC_ENT,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //         KC_LALT,  KC_E,    KC_A,  KC_TRNS,   KC_J,   KC_L,                          KC_J,   KC_L,  KC_SLSH, KC_QUOT, KC_COMM, KC_DEL,
    //     //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    //     KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, QK_REP, KC_LSFT, MO(2), TO(0)
    //     //`--------------------------'  `--------------------------'
    //     ),

    // // * Game (CLEAN)
    // [9] = LAYOUT(
    //     //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    //         KC_ESC,   KC_F,    KC_R,    KC_D,    KC_P,   KC_V,                           SS_QU,   KC_M,   KC_U,     KC_O,   KC_Y,   KC_BSPC,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //         KC_TAB,   KC_S,    KC_N,    KC_T,    KC_C,   KC_B,                         KC_DOT, HOME_H,  HOME_E,  HOME_A,  HOME_I,  KC_ENT,
    //     //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
    //         KC_LCTL,  KC_Z,    KC_X,    KC_K,    KC_G,   KC_W,                          KC_J,   KC_L,  KC_SLSH, KC_QUOT, KC_COMM, KC_DEL,
    //     //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
    //     KC_MUTE, KC_LALT, KC_SPC, KC_LCTL, QK_REP, KC_LSFT, MO(2), TO(0)
    //     //`--------------------------'  `--------------------------'
    //     )
};
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_VOLD, KC_VOLU),
            //Encoder 2
            ENCODER_CCW_CW(LCTL(KC_TAB), RCS(KC_TAB))
            },
    [1] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(LALT(KC_TAB), LSA(KC_TAB))
            },
    [2] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
            },
    [3] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(KC_MS_WH_DOWN, KC_MS_WH_UP)
            },
    [4] =   {
            //Encoder 1
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
            //Encoder 2
            ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
            },
    // [5] =   {
    //         //Encoder 1
    //         ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
    //         //Encoder 2
    //         ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    //         },
    // [6] =   {
    //         //Encoder 1
    //         ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
    //         //Encoder 2
    //         ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    //         },
    // [7] =   {
    //         //Encoder 1
    //         ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
    //         //Encoder 2
    //         ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    //         },
    // [8] =   {
    //         //Encoder 1
    //         ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
    //         //Encoder 2
    //         ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    //         },
    // [9] =   {
    //         //Encoder 1
    //         ENCODER_CCW_CW(KC_TRNS, KC_TRNS),
    //         //Encoder 2
    //         ENCODER_CCW_CW(KC_TRNS, KC_TRNS)
    //         },
};
#endif

// * -------------------------------------------
// * -- Combos (Currently set up for Recurva) --
// * -------------------------------------------
// Key Definitions
// Left Hand
const uint16_t PROGMEM combo1[] = {SS_QU, KC_U, COMBO_END}; // Q+U -> Q
const uint16_t PROGMEM combo17[] = {SS_QU, KC_M, COMBO_END}; // Q+M -> Q

// const uint16_t PROGMEM combo4[] = {KC_F, HOME_S, COMBO_END}; // F+S -> Grave `
// const uint16_t PROGMEM combo5[] = {KC_R, HOME_N, COMBO_END}; // R+N -> Less than <
// const uint16_t PROGMEM combo6[] = {KC_D, HOME_T, COMBO_END}; // D+T -> Left Curly Brace {
// const uint16_t PROGMEM combo7[] = {KC_P, HOME_C, COMBO_END}; // P+C -> Left Parenthesis (
// const uint16_t PROGMEM combo8[] = {KC_V, KC_B, COMBO_END};   // V+B -> Left Brace [

// Right Hand
// const uint16_t PROGMEM combo10[] = {KC_G, KC_L, COMBO_END}.;     // G+L -> Caps Word
const uint16_t PROGMEM combo10[] = {KC_B, KC_DOT, COMBO_END};     // B+. -> Caps Word

// const uint16_t PROGMEM combo12[] = {SS_QU, KC_DOT, COMBO_END}; // Q+. -> Right Brace ]
// const uint16_t PROGMEM combo13[] = {KC_M, HOME_H, COMBO_END};  // M+H -> Right Parenthesis )
// const uint16_t PROGMEM combo14[] = {KC_U, HOME_E, COMBO_END};  // U+E -> Right Curly Brace }
// const uint16_t PROGMEM combo15[] = {KC_O, HOME_A, COMBO_END};  // O+A -> Greater than >
// const uint16_t PROGMEM combo16[] = {KC_Y, HOME_I, COMBO_END};  // Y+I -> Semicolon ;

// Outcome Definitions
combo_t key_combos[COMBO_COUNT] = {
    // Left Hand
    COMBO(combo1, KC_Q), // Q+U -> Q
    COMBO(combo17, KC_Q), // Q+M -> Q

    // COMBO(combo4, KC_GRV),  // F+S -> Grave `
    // COMBO(combo5, KC_LT),   // R+N -> Less than <
    // COMBO(combo6, KC_LCBR), // D+T -> Left Curly Brace {
    // COMBO(combo7, KC_LPRN), // P+C -> Left Parenthesis (
    // COMBO(combo8, KC_LBRC), // V+B -> Left Brace [

    // Right Hand
    COMBO(combo10, CW_TOGG), // G+L or B+. -> Caps Word

    // COMBO(combo12, KC_RBRC), // Q+. -> Right Brace ]
    // COMBO(combo13, KC_RPRN), // M+H -> Right Parenthesis )
    // COMBO(combo14, KC_RCBR), // U+E -> Right Curly Brace }
    // COMBO(combo15, KC_GT),   // O+A -> Greater than >
    // COMBO(combo16, KC_SCLN), // Y+I -> Semicolon ;
};

// * ------------------
// * -- Tapping Term --
// * ------------------
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    // Increase the tapping term a little for slower ring and pinky fingers.
    case HOME_S:
    case HOME_N:
    case HOME_A:
    case HOME_I:
      return TAPPING_TERM + 15;

    default:
      return TAPPING_TERM;
  }
}

// * ---------------
// * -- Accordion --
// * ---------------
bool achordion_eager_mod(uint8_t mod) {
    switch (mod) {
        case MOD_LSFT:
        case MOD_RSFT:
        case MOD_LCTL:
        case MOD_RCTL:
            return true; // Eagerly apply Shift and Ctrl mods.

        default:
            return false;
    }
}

// bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
//                      uint16_t other_keycode, keyrecord_t* other_record) {
//     // Otherwise, follow the opposite hands rule.
//     return achordion_opposite_hands(tap_hold_record, other_record);
// }

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
    return 800; // Use a timeout of 800 ms.
}

// Typing Streak
uint16_t achordion_streak_timeout(uint16_t tap_hold_keycode) {
    if (IS_QK_LAYER_TAP(tap_hold_keycode)) {
        return 0; // Disable streak detection on layer-tap keys.
    }

    // Otherwise, tap_hold_keycode is a mod-tap key.
    uint8_t mod = mod_config(QK_MOD_TAP_GET_MODS(tap_hold_keycode));
    if ((mod & MOD_LSFT) != 0) {
    return 0;  // Disable for Shift mod-tap keys.
  } else {
    return 100;
  }
}

// * -----------
// * -- Magic --
// * -----------
// ! PGetreuer
bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
  // Unpack tapping keycode for tap-hold keys.
  switch (keycode) {
#ifndef NO_ACTION_TAPPING
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
      keycode = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
      break;
#ifndef NO_ACTION_LAYER
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      keycode = QK_LAYER_TAP_GET_TAP_KEYCODE(keycode);
      break;
#endif  // NO_ACTION_LAYER
#endif  // NO_ACTION_TAPPING
  }

  // Forget Shift on most letters when Shift or AltGr are the only mods. Some
  // letters are excluded, e.g. for "NN" and "ZZ" in Vim.
  switch (keycode) {
    case KC_A ... KC_Z:
      if ((*remembered_mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
        *remembered_mods &= ~MOD_MASK_SHIFT;
      }
      break;
  }

  return true;
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
if ((mods & ~MOD_MASK_SHIFT) == 0) {
    // This is where most of the "magic" for the MAGIC key is implemented.
    switch (keycode) {
      case KC_SPC:
      case LT(3, KC_SPC):
      case KC_ENT:
      case KC_TAB:
        return ONE_SHOT_SHIFT;

      // Fix SFBs and awkward strokes.
        case KC_F: return KC_F;
        case KC_R: return KC_R;
        case KC_D: return KC_D;
        case KC_P: return KC_P;
        case KC_S: return KC_S;
        case KC_N: return KC_N;
        case KC_T: return KC_T;
        case KC_C: return KC_C;
        case KC_B: return KC_B;
        case HOME_Z: return KC_Z;
        case HOME_G: return KC_G;
        case KC_M: return KC_M;
        case KC_O: return KC_O;
        case KC_E: return KC_E;
        case HOME_L: return KC_L;
        case KC_A: SEND_STRING("nd"); return false;

        case LCTL(KC_BSPC): return C(KC_Z);

        // case KC_SPC: return OSS;
        // case KC_ENT: return OSS;
        // case KC_DOT: return OSS;
        
        case KC_1 ... KC_0: return KC_DOT;
    }
  }
  return KC_TRNS;
//   return KC_LSFT;
//   return ONE_SHOT_SHIFT;
}


// ! Ikcelaks
// bool get_repeat_key_eligible_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
//     switch (keycode) {
//         // Ignore Custom Magic Keys
//         case MAGIC:
//             return false;
//         case KC_A ... KC_Z:
//             if ((*remembered_mods & ~(MOD_MASK_SHIFT)) == 0) {
//                 *remembered_mods &= ~MOD_MASK_SHIFT;
//             }
//             break;
//     }

//     return true;
// }

// * Alternate Repeat Key
// uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
//     switch (keycode) {
//         case KC_F: return KC_F;
//         case KC_R: return KC_R;
//         case KC_D: return KC_D;
//         case KC_P: return KC_P;
//         case KC_V:
//         case KC_S: return KC_S;
//         case KC_N: return KC_N;
//         case KC_T: return KC_T;
//         case KC_C: return KC_C;
//         case KC_B: return KC_B;
//         case KC_Z: return KC_Z;
//         case KC_X:
//         case KC_K:
//         case KC_G: return KC_G;
//         case KC_W:
//         case KC_Q:
//         case KC_M: return KC_M;
//         case KC_U:
//         case KC_O: return KC_O;
//         case KC_Y:
//         case KC_H:
//         case KC_E: return KC_E;
//         case KC_A:
//         case KC_I:
//         case KC_J:
//         case KC_L: return KC_L;

//         case KC_SPC: return OSS;
//         case KC_ENT: return OSS;
//         case KC_DOT: return OSS;
        
//         case KC_1 ... KC_0: return KC_DOT;
//     }

//     return OSS;
// }

// * Full Magic
// bool process_magic_key(uint16_t prev_keycode, uint8_t prev_mods) {
//     switch (prev_keycode) {
//         case KC_B:
//             SEND_STRING("ecome");
//             return false;
//         case KC_F:
//             SEND_STRING("ollow");
//             return false;
//         case KC_N:
//             SEND_STRING("eighbor");
//             return false;
//         case KC_H:
//             SEND_STRING("owever");
//             return false;
//         case KC_U:
//             SEND_STRING("pgrade");
//             return false;
//         case KC_O:
//             SEND_STRING("ther");
//             return false;
//         case KC_A:
//             SEND_STRING("lready");
//             return false;
//         case KC_P:
//             SEND_STRING("sych");
//             return false;
//         case KC_I:
//             SEND_STRING("'ll");
//             return false;
//         case KC_K:
//             SEND_STRING("now");
//             return false;
//         case KC_T:
//             SEND_STRING("hough");
//             return false;
//         case KC_L:
//             SEND_STRING("ittle");
//             return false;
//         case KC_M:
//         case KC_R:
//             SEND_STRING("ight");
//             return false;
//         case KC_J:
//             SEND_STRING("udge");
//             return false;
//         case KC_C:
//             SEND_STRING("ould");
//             return false;
//         case KC_D:
//             SEND_STRING("evelop");
//             return false;
//         case KC_G:
//             SEND_STRING("eneral");
//             return false;
//         case KC_W:
//             SEND_STRING("here");
//             return false;
//         case KC_S:
//             SEND_STRING("hould");
//             return false;
//         case KC_DOT:
//             SEND_STRING("org");
//             return false;
//         case KC_COMM:
//             SEND_STRING(" however");
//             return false;
//         default:
//             SEND_STRING("'ll");
//             return false;
//     }
// }

// * Remember last key
// ! empressabyss
// bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
//                             uint8_t* remembered_mods) {
//     switch (keycode) {
//         case CW_TOGG:
//         case KC_ESC:
//         case KC_BSPC:
//         case KC_DEL:
 
//         case MAGIC:
//             return false;  // Magic keys will ignore the above keycodes.
//     }
//     return true;  // Other keys can be repeated.
// }

// // An enhanced version of SEND_STRING: if Caps Word is active, the Shift key is
// // held while sending the string. Additionally, the last key is set such that if
// // the Repeat Key is pressed next, it produces `repeat_keycode`.
// #define MAGIC_STRING(str, repeat_keycode) \
//         magic_send_string_P(PSTR(str), (repeat_keycode))
 
// static void magic_send_string_P(const char* str, uint16_t repeat_keycode) {
//     uint8_t saved_mods = 0;
 
//   if (is_caps_word_on()) { // If Caps Word is on, save the mods and hold Shift.
//     saved_mods = get_mods();
//     register_mods(MOD_BIT(KC_LSFT));
//   }
 
//   send_string_with_delay_P(str, TAP_CODE_DELAY);  // Send the string.
//   set_last_keycode(repeat_keycode); // 2024-03-09 Disabled sending of string for mag-rep / rep-mag consistency.
 
//   // If Caps Word is on, restore the mods.
//   if (is_caps_word_on()) {
//     set_mods(saved_mods);
//   }
// }

// static void process_magic_key(uint16_t keycode, uint8_t mods) { // LMAGIC definitions
//     switch (keycode) {
//         case HRL_A: { MAGIC_STRING("a",         KC_SPC); } break;
//         case  KC_B: { MAGIC_STRING("ecause",    KC_NO); } break;
//         case  KC_C: { MAGIC_STRING("an",        KC_NO); } break;
//       //case HRL_D: { MAGIC_STRING("d",         KC_NO); } break;
//         case HRM_E: { MAGIC_STRING("e",         KC_NO); } break;
//       //case  KC_F: { MAGIC_STRING("f",         KC_NO); } break;
//         case  KC_G: { MAGIC_STRING("eneral",    KC_NO); } break;
//         case HRM_H: { MAGIC_STRING("h",         KC_NO); } break;
//         case HRM_I: { MAGIC_STRING("i",         KC_NO); } break;
//         case  KC_J: { MAGIC_STRING("ust",       KC_NO); } break;
//       //case  KC_K: { MAGIC_STRING("k",         KC_NO); } break;
//       //case HRM_L: { MAGIC_STRING("l",         KC_NO); } break;
//         case  KC_M: { MAGIC_STRING("ent",       KC_NO); } break;
//         case  KC_N: { MAGIC_STRING("ion",       KC_NO); } break;
//         case  KC_O: { MAGIC_STRING("o",         KC_NO); } break;
//         case  KC_P: { MAGIC_STRING("retty",     KC_NO); } break;
//         case  KC_Q: { MAGIC_STRING("q",         KC_NO); } break;
//       //case HRM_R: { MAGIC_STRING("r",         KC_NO); } break;
//       //case HRM_S: { MAGIC_STRING("s",         KC_NO); } break;
//         case  KC_T: { MAGIC_STRING("t",         KC_NO); } break;
//         case  KC_U: { MAGIC_STRING("u",         KC_NO); } break;
//         case HRM_V: { MAGIC_STRING("azjorfia",  KC_NO); } break;
//         case  KC_W: { MAGIC_STRING("hich",      KC_NO); } break;
//         case HRM_X: { MAGIC_STRING("x",         KC_NO); } break;
//         case  KC_Y: { MAGIC_STRING("y",         KC_NO); } break;
//         case  KC_Z: { MAGIC_STRING("z",         KC_NO); } break;
 
//         case KC_COMM: { MAGIC_STRING(" and",    KC_NO); } break;
//     }
// }

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

// * ------------
// * -- Macros --
// * ------------
// ! bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     tap_dance_action_t *action;

//     switch (keycode) {
//         case TD(MAGIC_REP):  // list all tap dance keycodes with tap-hold configurations
//             action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
//             if (!record->event.pressed && action->state.count && !action->state.finished) {
//                 tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
//                 tap_code16(tap_hold->tap);
//             }
//     }
//     return true;
// }


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    // ! Might be in wrong place
    const uint8_t mods         = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

        tap_dance_action_t *action;

    switch (keycode) {
            // * Macros
            // case EMAIL:
            // if (record->event.pressed) {
            //     SEND_STRING("aodhan66@gmail.com");
            // }
            // break;

    // ! Ikcelaks
            // case MAGIC:
            //    return process_magic_key(get_repeat_key_keycode(), get_repeat_key_mods());

    // ! empressabyss
            // case MAGIC: { 
            //     process_magic_key(get_last_keycode(), get_last_mods()); 
            //     set_last_keycode(KC_SPC); 
            //     } 
            // break;

        case SS_QU:
            if (record->event.pressed) {
                SEND_STRING("qu");
            }
            break;

        case LINE_SELECT:
            if (record->event.pressed) {
                clear_oneshot_mods(); // Temporarily disable mods.
                tap_code(KC_HOME);   // Move cursor to start of line.
                register_code(KC_LSFT);// Hold Shift to select.
                tap_code(KC_END);   // Move cursor to end of line.
                unregister_code(KC_LSFT); // Stops holding Shift.
            }
            break;

        case LINE_COPY:
            if (record->event.pressed) {
                clear_oneshot_mods(); // Temporarily disable mods.
                tap_code(KC_HOME);   // Move cursor to start of line.
                register_code(KC_LSFT);// Hold Shift to select.
                tap_code(KC_END);   // Move cursor to end of line.
                unregister_code(KC_LSFT); // Stops holding Shift.
                register_code(KC_LCTL);// Hold Ctrl to copy.
                tap_code(KC_C);   // Copy selection.
                unregister_code(KC_LCTL); // Stops holding Ctrl.
            }
            break;

        case ONE_SHOT_SHIFT:
            if (record->event.pressed) {
                // clear_oneshot_mods(); // Temporarily disable mods.
                set_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            break;

            case LSFT_T(QK_AREP):
            if (record->tap.count && record->event.pressed) {
                tap_code16(QK_AREP); // Send KC_DQUO on tap
                return false;        // Return false to ignore further processing of key
            }
            break;

        case BRACES: // Types [], {}, or <> and puts cursor between braces.
            if (record->event.pressed) {
                clear_oneshot_mods(); // Temporarily disable mods.
                unregister_mods(MOD_MASK_CSAG);
                if ((mods | oneshot_mods) & MOD_MASK_SHIFT) {
                    SEND_STRING("{}");
                } else if ((mods | oneshot_mods) & MOD_MASK_ALT) {
                    SEND_STRING("<>");
                } else if ((mods | oneshot_mods) & MOD_MASK_CTRL) {
                    SEND_STRING("[]");
                } else {
                    SEND_STRING("()");
                }
                tap_code(KC_LEFT);   // Move cursor between braces.
                register_mods(mods); // Restore mods.
            }
            return false;
    }

    // ! CURRENTLY UNUSED
    // ! ======================================================================================
    // * Tap-Hold Configuration
    // uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
    //   // If you quickly hold a tap-hold key after tapping it, the tap action is
    //   // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
    //   // lead to missed triggers in fast typing. Here, returning 0 means we
    //   // instead want to "force hold" and disable key repeating.
    //   switch (keycode) {
    //     case HOME_N:
    //     // Repeating is useful for Vim navigation keys.
    //     case QHOME_J:
    //     case QHOME_K:
    //     case QHOME_L:
    //       return QUICK_TAP_TERM;  // Enable key repeating.
    //     default:
    //       return 0;  // Otherwise, force hold and disable key repeating.
    //   }
    // }
    // ! ======================================================================================

switch (keycode) {
        case TD(MAGIC_REP):  // list all tap dance keycodes with tap-hold configurations
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }

    return true;
};

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

tap_dance_action_t tap_dance_actions[] = {
    [MAGIC_REP] = ACTION_TAP_DANCE_TAP_HOLD(QK_AREP, KC_LSFT),
};


void matrix_scan_user(void) {
    achordion_task();
}

// * Determine OS and send appropriate unicode characters
// bool process_detected_host_os_kb(os_variant_t detected_os) {
//     if (!process_detected_host_os_user(detected_os)) {
//         return false;
//     }
//     switch (detected_os) {
//         case OS_MACOS:
//         case OS_IOS:
//             set_unicode_input_mode(UNICODE_MODE_MACOS);
//             break;
//         case OS_WINDOWS:
//             set_unicode_input_mode(UNICODE_MODE_WINCOMPOSE);
//             break;
//         case OS_LINUX:
//             set_unicode_input_mode(UNICODE_MODE_LINUX);
//             break;
//         case OS_UNSURE:
//             break;
//     }
    
//     return true;
// }