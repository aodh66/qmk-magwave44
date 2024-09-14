/*
 * Copyright 2024 @DreaM117er
 * Copyright 2024 QMK
 */

#include QMK_KEYBOARD_H
// ? Achordion
#include "features/achordion.h"

// * -----------------------------
// * -- Home row mods (Recurva) --
// * -----------------------------
// ? Achordion
// Left-hand
    // Default Home Row
#define HOME_S LGUI_T(KC_S)
#define HOME_N LALT_T(KC_N)
#define HOME_T LSFT_T(KC_T)
#define HOME_C LCTL_T(KC_C)

    // Bottom Home Row
#define HOME_Z LGUI_T(KC_Z)
#define HOME_X LALT_T(KC_X)
#define HOME_K LSFT_T(KC_K)
#define HOME_G LCTL_T(KC_G)

// Right-hand
    // Default Home Row
#define HOME_H RCTL_T(KC_H)
#define HOME_E RSFT_T(KC_E)
#define HOME_A LALT_T(KC_A)
#define HOME_I RGUI_T(KC_I)

    // Bottom Home Row
#define HOME_L RCTL_T(KC_L)
#define HOME_SL RSFT_T(KC_SLSH)
#define HOME_QT LALT_T(KC_QUOT)
#define HOME_CM RGUI_T(KC_COMM)

// Layers
#define UNDO LCTL(KC_Z)
#define COPY LCTL(KC_C)
#define CUT LCTL(KC_X)
#define PASTE LCTL(KC_V)
#define FIND LCTL(KC_F)

#define NXT_TAB LCTL(KC_TAB)
#define PRE_TAB RCS(KC_TAB)
#define NXT_WIN LALT(KC_TAB)
#define PRE_WIN LCA(KC_TAB)

#define ALT_F4 LALT(KC_F4)
#define OS_SFT OSM(MOD_LSFT)
#define CTL_BSPC LCTL(KC_BSPC)

// * ------------------------
// * -- Macro Declarations --
// * ------------------------
enum custom_keycodes {
    SS_QU = SAFE_RANGE,
    LINE_SELECT,
    LINE_COPY,
    BRACES,
    RESIZE,
    LARCANE,
    RARCANE,
    // MAGIC,
    // ONE_SHOT_SHIFT,

    // SM-Tap Dance Home Row Mods
    SMTD_KEYCODES_BEGIN,
    // Default Home Row
    // HOME_H,
    // HOME_E,
    // HOME_A,
    // HOME_I,
    // HOME_S,
    // HOME_N,
    // HOME_T,
    // HOME_C,

    // Bottom Home Row
    // HOME_Z,
    // HOME_X,
    // HOME_K,
    // HOME_G,
    // HOME_L,
    // HOME_SL,
    // HOME_QT,
    // HOME_CM,

    // Layers
    LSYM_BKSPC,
    RSYM_BKSPC,
    SMTD_KEYCODES_END,
};
#include "sm_td/sm_td.h"

// * -------------------------------------------
// * -- Combos (Currently set up for Recurva) --
// * -------------------------------------------
#include "g/keymap_combo.h"

// Tap Dance declarations
// enum {
// };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // * Base (Recurva Colstag)
    [0] = LAYOUT(
        //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐         ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
            KC_ESC,    KC_F,    KC_R,     KC_D,     KC_P,    KC_V,               SS_QU,    KC_M,    KC_U,     KC_O,    KC_Y,    KC_DEL,
        //└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘         └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
        // Default Home Row
        // //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐         ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
        //     KC_TAB,   HOME_S,  HOME_N,   HOME_T,   HOME_C,   KC_B,              KC_DOT,   HOME_H,  HOME_E,   HOME_A,   HOME_I,  KC_ENT,
        // //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
        //     KC_NO,     KC_Z,    KC_X,     KC_K,     KC_G,    KC_W,               KC_J,     KC_L,   KC_SLSH,  KC_QUOT, KC_COMM, LINE_SELECT,
        // //└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘         └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
        // Bottom Home Row
        //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐         ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
            KC_TAB,    KC_S,    KC_N,     KC_T,     KC_C,    KC_B,              KC_DOT,    KC_H,    KC_E,     KC_A,    KC_I,    KC_ENT,
        //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            QK_BOOT,    HOME_Z,  HOME_X,   HOME_K,   HOME_G,   KC_W,               KC_J,    HOME_L,  HOME_SL,  HOME_QT, HOME_CM,LINE_SELECT,
        //└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘         └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
        // SM_Tap Dance Layer Taps
        //             ┌──────────┐┌────────────┬──────────┬──────────┐         ┌──────────┬──────────┬────────────┐┌───────────┐
                         KC_MUTE,   LSYM_BKSPC,   KC_SPC,   LARCANE,             RARCANE,  OS_SFT,   RSYM_BKSPC,   LSG(KC_S)        //snipping tool on press
        //             └──────────┘└────────────┴──────────┴──────────┘         └──────────┴──────────┴────────────┘└───────────┘
        // Default/Achordion Layer Taps // ! Only sends BKSPC, not CTRL_BKSPC
        // //             ┌──────────┐┌────────────┬──────────┬──────────┐         ┌──────────┬──────────┬────────────┐┌───────────┐
        //                  KC_MUTE,   LT(1, LCTL(KC_BSPC)),   KC_SPC,   LARCANE,             RARCANE,  OS_SFT,   LT(2, LCTL(KC_BSPC)),   LSG(KC_S)        //snipping tool on press
        // //             └──────────┘└────────────┴──────────┴──────────┘         └──────────┴──────────┴────────────┘└───────────┘
        ),

    // * Nav/Ext
    [1] = LAYOUT(
        //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐         ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
            KC_ESC,   ALT_F4,  KC_TAB,   KC_MEH,  KC_HYPR,  KC_CAPS,            KC_PGUP, KC_HOME,  BRACES,   KC_END,  KC_BSPC,  KC_DEL,
        //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_NO,   KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL, RESIZE,             KC_PGDN, KC_LEFT,  KC_DOWN,  KC_UP,   KC_RGHT,  KC_ENT,
        //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_NO,     UNDO,     CUT,     COPY,    PASTE,    FIND,              KC_DEL,  NXT_TAB,  PRE_TAB,  NXT_WIN, PRE_WIN, LINE_COPY,
        //└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘         └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
        //              ┌──────────┐┌─────────┬──────────┬────────────┐         ┌──────────┬───────────┬─────────┐┌───────────┐
                          KC_TRNS,   KC_TRNS,   KC_NO,      KC_NO,                MO(4),   CW_TOGG,    MO(3),      TO(0)       //moba
        //              └──────────┘└─────────┴──────────┴────────────┘         └──────────┴───────────┴─────────┘└───────────┘
        ),

    // * Symbol
    [2] = LAYOUT(
        //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐         ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
            KC_ESC,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,  KC_PERC,            KC_CIRC, KC_AMPR,  KC_ASTR,  KC_UNDS, KC_PIPE,  KC_DEL,
        //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_TAB,  KC_GRV,   KC_LT,    KC_LCBR, KC_LPRN,  KC_LBRC,            KC_EQL,  KC_RCTL,  KC_RSFT,  KC_RALT, KC_RGUI,  KC_ENT,
        //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_LCTL, KC_TILD,  KC_GT,    KC_RCBR, KC_RPRN,  KC_RBRC,            KC_PLUS, KC_MINS,  KC_COLN,  KC_SCLN, KC_BSLS, LINE_SELECT,
        //└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘         └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
        //              ┌──────────┐┌─────────┬──────────┬────────────┐         ┌──────────┬───────────┬─────────┐┌───────────┐
                          KC_TRNS,    MO(3),    KC_ENT,    KC_BSPC,              KC_NO,      KC_NO,   KC_TRNS,     TO(0)
        //              └──────────┘└─────────┴──────────┴────────────┘         └──────────┴───────────┴─────────┘└───────────┘
        ),

    // * Numpad
    [3] = LAYOUT(
        //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐         ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
            KC_ESC,   KC_NO,    KC_NO,   QK_BOOT,  KC_NO,   KC_VOLU,            KC_MINS,  KC_7,     KC_8,     KC_9,    KC_ASTR, KC_SLSH,
        //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_TAB,  KC_LGUI,  KC_LALT,  KC_LSFT,  KC_LCTL, KC_VOLD,            KC_DOT,   KC_4,     KC_5,     KC_6,    KC_0,    KC_ENT,
        //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_LCTL,  KC_NO,    KC_NO,   KC_BSPC,  KC_DEL,  KC_MPLY,            KC_PLUS,  KC_1,     KC_2,     KC_3,    KC_SLSH, KC_BSLS,
        //└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘         └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
        //              ┌──────────┐┌─────────┬──────────┬────────────┐         ┌──────────┬───────────┬─────────┐┌───────────┐
                          KC_TRNS,   KC_TRNS,   KC_NO,      KC_NO,               KC_NO,     KC_NO,    KC_TRNS,     TO(0)      //moba
        //              └──────────┘└─────────┴──────────┴────────────┘         └──────────┴───────────┴─────────┘└───────────┘
        ),

    // * Function
    [4] = LAYOUT(
        //┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐         ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
            KC_NO,    ALT_F4,   KC_NO,   QK_BOOT,  KC_NO,   KC_VOLU,            KC_NO,    KC_F7,    KC_F8,    KC_F9,   KC_NO,    KC_NO,
        //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_NO,   KC_LGUI,  KC_LALT,  KC_LSFT, KC_LCTL,  KC_VOLD,            KC_F12,   KC_F4,    KC_F5,    KC_F6,   KC_F10,   KC_NO,
        //├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤         ├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤
            KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_MPLY,   KC_NO,             KC_F11,   KC_F1,    KC_F2,    KC_F3,   KC_NO,    TO(4),
        //└─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘         └─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
        //              ┌──────────┐┌─────────┬──────────┬────────────┐         ┌──────────┬───────────┬─────────┐┌───────────┐
                          KC_TRNS,    KC_NO,    ALT_F4,      KC_NO,               KC_TRNS,    KC_NO,    KC_NO,     TO(0)
        //              └──────────┘└─────────┴──────────┴────────────┘         └──────────┴───────────┴─────────┘└───────────┘
        )

    // * Unused Layers
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

    // // * Game (CLEAN)
    // [7] = LAYOUT(
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

// * Encoder Map
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
};
#endif

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
    case HOME_Z:
    case HOME_X:
    case HOME_QT:
    case HOME_CM:
      return TAPPING_TERM + 15;

    default:
      return TAPPING_TERM;
  }
}

// * ------------------
// * -- SM-Tap Dance --
// * ------------------
void on_smtd_action(uint16_t keycode, smtd_action action, uint8_t tap_count) {
    switch (keycode) {
// Left-hand
    // // Default Home Row
    //     SMTD_MTE(HOME_H, KC_H, KC_RIGHT_CTRL)
    //     SMTD_MTE(HOME_E, KC_E, KC_RSFT)
    //     SMTD_MT(HOME_A, KC_A, KC_RIGHT_ALT)
    //     SMTD_MT(HOME_I, KC_I, KC_RIGHT_GUI)

    // Bottom Row
        // SMTD_MTE(HOME_G, KC_G, KC_RIGHT_CTRL)
        // SMTD_MTE(HOME_K, KC_K, KC_RSFT)
        // SMTD_MT(HOME_X, KC_X, KC_RIGHT_ALT)
        // SMTD_MT(HOME_Z, KC_Z, KC_RIGHT_GUI)

        // Layer Tap
        SMTD_LT(LSYM_BKSPC, CTL_BSPC, 1)


// Right-hand
    // // Default Home Row
    //     SMTD_MTE(HOME_C, KC_C, KC_LEFT_CTRL)
    //     SMTD_MTE(HOME_T, KC_T, KC_LSFT)
    //     SMTD_MT(HOME_N, KC_N, KC_LEFT_ALT)
    //     SMTD_MT(HOME_S, KC_S, KC_LEFT_GUI)

    // Bottom Row
        // SMTD_MTE(HOME_L, KC_L, KC_LEFT_CTRL)
        // SMTD_MTE(HOME_SL, KC_SLSH, KC_LSFT)
        // SMTD_MT(HOME_QT, KC_QUOT, KC_LEFT_ALT)
        // SMTD_MT(HOME_CM, KC_COMM, KC_LEFT_GUI)

        // Layer Tap
        SMTD_LT(RSYM_BKSPC, CTL_BSPC, 2)
    }
}

uint32_t get_smtd_timeout(uint16_t keycode, smtd_timeout timeout) {
    // Increase to get stuck on key presses less
    switch (keycode) {
        // case HOME_I:
        // case HOME_S:
        // case HOME_Z:
        // case HOME_CM:
            if (timeout == SMTD_TIMEOUT_TAP) return 200; // 200 (Tapping term default)
    }

    // Decrease to stop false hold interpretations
    switch (keycode) {
        // case HOME_I:
        // case HOME_S:
        // case HOME_C:
        // case HOME_H:
        // case HOME_T:
        // case HOME_E:
        // case HOME_N:
        // case HOME_A:
        // case HOME_G:
        // case HOME_L:

        // case HOME_Z:
        // case HOME_X:
        // case HOME_K:
        // case HOME_G:
        // case HOME_L:
        // case HOME_SL:
        // case HOME_QT:
        // case HOME_CM:
            if (timeout == SMTD_TIMEOUT_RELEASE) return 5; // 200/4 (50 default)

        // case HOME_Z:
        // case HOME_CM:
        case LSYM_BKSPC:
        case RSYM_BKSPC:
            if (timeout == SMTD_TIMEOUT_RELEASE) return 50; // 200/4 (50 default)
    }
    // Increase to give yourself more time for a tap sequence
    // switch (keycode) {
    //         if (timeout == SMTD_TIMEOUT_SEQUENCE) return 100; // 200/2 (100 default)
    // }

    return get_smtd_timeout_default(timeout);
}

// * ---------------
// * -- Accordion --
// * ---------------
// ? Achordion
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

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
    // Otherwise, follow the opposite hands rule.
    return achordion_opposite_hands(tap_hold_record, other_record);
}

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

// * ----------------------------
// * -- Magic/Alternate Repeat --
// * ----------------------------
    // ! Arcane Keys based on Empressabyss' setup
    // Function with caps word, ditched one shot shift
    bool remember_last_key_user(uint16_t keycode, keyrecord_t* record,
                            uint8_t* remembered_mods) {
    switch (keycode) {
        case CW_TOGG:
        case KC_ESC:
        case KC_BSPC:
        case KC_DEL:
 
        case LARCANE:
        case RARCANE:
            return false;  // Magic keys will ignore the above keycodes.
    }
    return true;  // Other keys can be repeated.
}
 
//  ! tap for number hold for F-key
// static bool process_tap_or_long_press_key( // Tap for number, hold for F-key
//     keyrecord_t* record, uint16_t long_press_keycode) {
//   if (record->tap.count == 0) {  // Key is being held.
//     if (record->event.pressed) {
//       tap_code16(long_press_keycode);
//     }
//     return false;  // Skip default handling.
//   }
//   return true;  // Continue default handling.
// }
 
// An enhanced version of SEND_STRING: if Caps Word is active, the Shift key is
// held while sending the string. Additionally, the last key is set such that if
// the Repeat Key is pressed next, it produces `repeat_keycode`.
#define MAGIC_STRING(str, repeat_keycode) \
        magic_send_string_P(PSTR(str), (repeat_keycode))
 
static void magic_send_string_P(const char* str, uint16_t repeat_keycode) {
    uint8_t saved_mods = 0;
 
  if (is_caps_word_on()) { // If Caps Word is on, save the mods and hold Shift.
    saved_mods = get_mods();
    register_mods(MOD_BIT(KC_LSFT));
  }
 
  send_string_with_delay_P(str, TAP_CODE_DELAY);  // Send the string.
  set_last_keycode(repeat_keycode); // 2024-03-09 Disabled sending of string for mag-rep / rep-mag consistency.
 
  // If Caps Word is on, restore the mods.
  if (is_caps_word_on()) {
    set_mods(saved_mods);
  }
}
 
 // LMAGIC definitions
static void process_left_magic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
        // Universal
        case  KC_B: { MAGIC_STRING("b",    KC_F24); } break;
        case KC_D: { MAGIC_STRING("d",         KC_F24); } break;
        case  KC_F: { MAGIC_STRING("f",         KC_F24); } break;
        case  KC_J: { MAGIC_STRING("ust",       KC_F24); } break;
        case  KC_M: { MAGIC_STRING("ent",       KC_F24); } break;
        case  KC_O: { MAGIC_STRING("a",         KC_F24); } break;
        case  KC_P: { MAGIC_STRING("p",     KC_F24); } break;
        case  SS_QU: { MAGIC_STRING("estion",         KC_F24); } break;
        case KC_R: { MAGIC_STRING("r",         KC_F24); } break;
        case  KC_U: { MAGIC_STRING("e",         KC_F24); } break;
        case KC_V: { MAGIC_STRING("v",  KC_F24); } break;
        case  KC_W: { MAGIC_STRING("w",      KC_F24); } break;
        case  KC_Y: { MAGIC_STRING("ou",         KC_F24); } break;

        case  KC_DOT: { MAGIC_STRING("./",         KC_F24); } break;

        case  KC_SPC: { MAGIC_STRING("the ",     KC_F24); } break;
        case  KC_F21: { MAGIC_STRING("",     KC_SPC); } break;

        case  KC_F23: { MAGIC_STRING(" ",     KC_F21); } break;

        // Default Home Row
        case HOME_A: { MAGIC_STRING("nd",         KC_F24); } break;
        case  HOME_C: { MAGIC_STRING("c",        KC_F24); } break;
        case HOME_E: { MAGIC_STRING("",         KC_F24); } break;
        case  KC_G: { MAGIC_STRING("g",    KC_F24); } break;
        case HOME_H: { MAGIC_STRING("",         KC_F24); } break;
        case HOME_I: { MAGIC_STRING("ng",         KC_F24); } break;
        case  KC_K: { MAGIC_STRING("k",         KC_F24); } break;
        case KC_L: { MAGIC_STRING("",         KC_F24); } break;
        case  HOME_N: { MAGIC_STRING("n",       KC_F24); } break;
        case HOME_S: { MAGIC_STRING("s",         KC_F24); } break;
        case  HOME_T: { MAGIC_STRING("t",         KC_F24); } break;
        case KC_X: { MAGIC_STRING("x",         KC_F24); } break;
        case  KC_Z: { MAGIC_STRING("z",         KC_F24); } break;

        case KC_COMM: { MAGIC_STRING(" and ",    KC_F21); } break;

        // Bottom Home Row
        case KC_A: { MAGIC_STRING("nd",         KC_F24); } break;
        case  KC_C: { MAGIC_STRING("c",        KC_F24); } break;
        case KC_E: { MAGIC_STRING("",         KC_F24); } break;
        case  HOME_G: { MAGIC_STRING("g",    KC_F24); } break;
        case KC_H: { MAGIC_STRING("",         KC_F24); } break;
        case KC_I: { MAGIC_STRING("ng",         KC_F24); } break;
        case  HOME_K: { MAGIC_STRING("k",         KC_F24); } break;
        case HOME_L: { MAGIC_STRING("",         KC_F24); } break;
        case  KC_N: { MAGIC_STRING("n",       KC_F24); } break;
        case KC_S: { MAGIC_STRING("s",         KC_F24); } break;
        case  KC_T: { MAGIC_STRING("t",         KC_F24); } break;
        case HOME_X: { MAGIC_STRING("x",         KC_F24); } break;
        case  HOME_Z: { MAGIC_STRING("z",         KC_F24); } break;

        case HOME_CM: { MAGIC_STRING(" and ",    KC_F21); } break;
    }
}
 
 // RMAGIC definitions
static void process_right_magic(uint16_t keycode, uint8_t mods) {
    switch (keycode) {
                // Universal
        case  KC_B: { MAGIC_STRING("ecause",         KC_F23); } break;
        case KC_D: { MAGIC_STRING("t",         KC_F23); } break;
        case  KC_F: { MAGIC_STRING("or",         KC_F23); } break;
        case  KC_J: { MAGIC_STRING("j",         KC_F23); } break;
        case  KC_M: { MAGIC_STRING("m",         KC_F23); } break;
        case  KC_O: { MAGIC_STRING("o",         KC_F23); } break;
        case  KC_P: { MAGIC_STRING("",         KC_F23); } break;
        case  SS_QU: { MAGIC_STRING("",      KC_F23); } break;
        case KC_R: { MAGIC_STRING("n",         KC_F23); } break;
        case  KC_U: { MAGIC_STRING("u",         KC_F23); } break;
        case KC_V: { MAGIC_STRING("",         KC_F23); } break;
        case  KC_W: { MAGIC_STRING("hich",         KC_F23); } break;
        case  KC_Y: { MAGIC_STRING("y",       KC_F23); } break;

        case  KC_SPC: { MAGIC_STRING("the ",     KC_F23); } break;
        case  KC_F22: { MAGIC_STRING("",     KC_SPC); } break;

        case  KC_F24: { MAGIC_STRING(" ",     KC_F22); } break;

        // Default Home Row
        case HOME_A: { MAGIC_STRING("a",        KC_F23); } break;
        case  HOME_C: { MAGIC_STRING("",         KC_F23); } break;
        case HOME_E: { MAGIC_STRING("e",         KC_F23); } break;
        case  KC_G: { MAGIC_STRING("",         KC_F23); } break;
        case HOME_H: { MAGIC_STRING("h",         KC_F23); } break;
        case HOME_I: { MAGIC_STRING("i",        KC_F23); } break;
        case  KC_K: { MAGIC_STRING("",         KC_F23); } break;
        case KC_L: { MAGIC_STRING("l",         KC_F23); } break;
        case  HOME_N: { MAGIC_STRING("",         KC_F23); } break;
        case HOME_S: { MAGIC_STRING("",         KC_F23); } break;
        case  HOME_T: { MAGIC_STRING("ion",         KC_F23); } break;
        case KC_X: { MAGIC_STRING("",        KC_F23); } break;
        case  KC_Z: { MAGIC_STRING("",         KC_F23); } break;

        case KC_COMM: { MAGIC_STRING(" but ",    KC_F22); } break;
        case KC_QUOT: { MAGIC_STRING("ll ",    KC_F22); } break;

        // Bottom Home Row
        case KC_A: { MAGIC_STRING("a",        KC_F23); } break;
        case  KC_C: { MAGIC_STRING("",         KC_F23); } break;
        case KC_E: { MAGIC_STRING("e",         KC_F23); } break;
        case  HOME_G: { MAGIC_STRING("",         KC_F23); } break;
        case KC_H: { MAGIC_STRING("h",         KC_F23); } break;
        case KC_I: { MAGIC_STRING("i",        KC_F23); } break;
        case  HOME_K: { MAGIC_STRING("",         KC_F23); } break;
        case HOME_L: { MAGIC_STRING("l",         KC_F23); } break;
        case  KC_N: { MAGIC_STRING("",         KC_F23); } break;
        case KC_S: { MAGIC_STRING("",         KC_F23); } break;
        case  KC_T: { MAGIC_STRING("ion",         KC_F23); } break;
        case HOME_X: { MAGIC_STRING("",        KC_F23); } break;
        case  HOME_Z: { MAGIC_STRING("",         KC_F23); } break;

        case HOME_CM: { MAGIC_STRING(" but ",    KC_F22); } break;
        case HOME_QT: { MAGIC_STRING("ll ",    KC_F22); } break;
    }
}

// bool caps_word_press_user(uint16_t keycode) {
//     switch (keycode) {
//         // Keycodes that continue Caps Word, with shift applied.
//         case KC_A ... KC_Z:
//         case KC_MINS:
//             add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
//             return true;
 
//         // Keycodes that continue Caps Word, without shifting.
//         case KC_1 ... KC_0:
//         case KC_BSPC:
//         case KC_DEL:
//         case KC_QUOT:
//         case KC_SLSH:
//         case KC_UNDS:
//         case KC_SPC:
//             return true;
 
//         default:
//             return false;  // Deactivate Caps Word.
//     }
// }

// * ------------
// * -- Macros --
// * ------------
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_smtd(keycode, record)) {
        return false;
    }

    // ? Achordion
    if (!process_achordion(keycode, record)) {
        return false;
    }

    // ! Might be in wrong place
    const uint8_t mods         = get_mods();
    const uint8_t oneshot_mods = get_oneshot_mods();

    switch (keycode) {
            // * Macros
            // ! New Arcane Keys Empressabyss
        case LARCANE: { 
            process_left_magic(get_last_keycode(), get_last_mods()); 
            } 
            return false;
        case RARCANE: { 
            process_right_magic(get_last_keycode(), get_last_mods()); 
            } 
            return false;

case RESIZE:
            if (record->event.pressed) {
                set_mods(MOD_MASK_CSAG);
                register_code(KC_X);
            } else {
                clear_mods();
                unregister_code(KC_X);
            }
            // Do not let QMK process the keycode further
            return false;

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

        // case ONE_SHOT_SHIFT:
        //     if (record->event.pressed) {
        //         set_oneshot_mods(MOD_BIT(KC_LSFT));

        //     }
        //     break;

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

    return true;
};

// ? Achordion
void matrix_scan_user(void) {
    achordion_task();
}