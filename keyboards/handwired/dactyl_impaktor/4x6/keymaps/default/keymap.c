#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Automatic Layer ID:
enum layer_names {
                  _QWERTY,
                  /* _DANISH, */
                  _NUMBERS,
                  _FUNC,
                  _NUMPAD,
                  _MOUSE,
                  /* _APL, */
                  /* _GREEK, */
                  /* _RUNES, */
                  _BLANK,
};

/* Layer switching keys (MO, LT, LM, TO, TG, TT, OSL, ) */
#define NUM_TAB LT(_NUMBERS, KC_TAB)   /* when held: numbers key, or use LT(layer, kc)  for hold,tap function */
#define NSHIFT LM(_NUMBERS, MOD_LSFT) /* when held: numbers keys shifted */

#define NUMP TT(_NUMPAD)        /* tap-toggle, hold down for layer, or tap TAPPING_TOGGLE times to toggle */
#define MOUSE TT(_MOUSE)        /* tap-toggle, hold down for layer, or tap TAPPING_TOGGLE times to toggle */
#define FUN  OSL(_FUNC)         /* one shot layer, press key, only next press is from other layer */
#define BASE TO(_QWERTY)        /* activate layer, deactivate all others except default */


// Fillers to make layering more clear

#define ____ KC_TRNS

/* Mode tap keys, convenience functions to MT(mod, kc) */
#define CTL_ESC  LCTL_T(KC_ESC)   /* left CTRL when held, else ESC when taped... */
#define SFT_FUN  LSFT_T(FUN)      /* left shift when held, else FUNC modifyer switch when taped... */

#define SFT_ESC  LSFT_T(KC_ESC)  /* left shift when held, else X when taped... */
#define SFT_ENT  RSFT_T(KC_ENT)   /*  */
#define ALT_SPC  LALT_T(KC_SPC)   /* left ALT when held, else X when taped... */


/* Mouse movement */
#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN2       /* middle mouse? */
#define KC_MB3 KC_MS_BTN3
#define KC_MWU KC_MS_WH_UP
#define KC_MWD KC_MS_WH_DOWN
#define KC_MWL KC_MS_WH_LEFT
#define KC_MWR KC_MS_WH_RIGHT

 /* Terminal-compatible paste. */
#define PASTE LSFT(KC_INS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Base (qwerty)
 * +-----------------------------------------+                             +-----------------------------------------+
 * |*NTAB |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |  [ { |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * |*LCTRL|   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |  : ; | ' "  |
 * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
 * |*LSHFT|   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |  , < |  . > | / ?  | MOUSE|
 * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
 *               |  [   |   ]  |                                                         | FUN  | NUMP |
 *               +-------------+   +-----+-----+                         +-----------+   +-------------+
 *                                 |BKSP |LALT |                         | RET | SPC |
 *                                 |     |     |                         |     |     |
 *                                 +-----+-----+                         +-----+-----+
 *                                      +-------------+           +-------------+
 *                                      | HOME | WIN  |           | PGUP | rALT |
 *                                      |------+------|           |------+------|
 *                                      | END  | ` ~  |           | PGDN |RCTRL |
 *                                      +-------------+           +-------------+
 */

[_QWERTY] = LAYOUT( \
    NUM_TAB,  KC_Q,  KC_W,   KC_E,   KC_R,   KC_T,               KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC,   \
    CTL_ESC,  KC_A,  KC_S,   KC_D,   KC_F,   KC_G,               KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,   \
    SFT_FUN,  KC_Z,  KC_X,   KC_C,   KC_V,   KC_B,               KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,MOUSE,     \
                     KC_LBRC,KC_RBRC,                                            FUN,    NUMP,                      \
                                    KC_BSPC, KC_LALT,          KC_ENT,  KC_SPC,                                     \
                                    KC_HOME, KC_LGUI,          KC_PGUP, KC_RALT,                                    \
                                    KC_END,  KC_GRV,           KC_PGDN, KC_RCTRL                                    \
),

/* Numbers and arrows */
[_NUMBERS] = LAYOUT( \
    KC_INS, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,               KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MUTE,   \
    _______,_______,KC_UP,  _______,_______,_______,            _______,_______,_______,_______,_______,KC_VOLU,   \
    _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,            _______,_______,_______,_______,_______,KC_VOLD,   \
                    _______,_______,                                            KC_MPRV,KC_MNXT,                   \
                                        _______,_______,    _______,_______,                                       \
                                        _______,_______,    _______,_______,                                       \
                                        _______,_______,    _______,BASE                                           \
),

/* Numpad layer */
[_NUMPAD] = LAYOUT( \
    RESET,  KC_DEL, KC_HOME,KC_PGUP,_______,KC_LBRC,            KC_RBRC, KC_P7, KC_P8,  KC_P9,  KC_PLUS, KC_ASTR,  \
    _______,KC_INS, KC_END, KC_PGDN,_______,KC_LPRN,            KC_RPRN, KC_P4, KC_P5,  KC_P6,  KC_MINS, KC_SLSH,  \
    _______,_______,_______,KC_SLCK,_______,_______,            _______, KC_P1, KC_P2,  KC_P3,  KC_UNDS, KC_EQL,   \
                    KC_NLCK,KC_PSCR,                                           _______, KC_P0,                     \
                                        _______,_______,    _______,_______,                                       \
                                        _______,_______,    _______,_______,                                       \
                                        _______,_______,    _______,BASE                                           \
),


/*left over: RESET */

/* Mouse movement on left, scroll wheel on right */
[_MOUSE] = LAYOUT( \
    _______,_______,KC_MU,  _______,_______,_______,            KC_ACL0,_______,_______,KC_MWU ,_______,_______,   \
    _______,KC_ML,  KC_MD,  KC_MR,  _______,_______,            KC_ACL1,_______,KC_MWL, KC_MWD, KC_MWR, _______,   \
    _______,_______,_______,_______,_______,_______,            KC_ACL2,_______,_______,_______,_______,_______,   \
                    _______,_______,                                           _______,_______,                    \
                                         KC_MB1, KC_MB2,     KC_MB3, _______,                                      \
                                         _______,_______,    _______,_______,                                      \
                                         _______,_______,    _______,BASE                                          \
),

/* Function keys (maybe holding TAB key moves to this?)*/
[_FUNC] = LAYOUT( \
    _______,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,              KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, _______,   \
    _______,KC_F11, KC_F12, _______,_______,_______,            _______,_______,_______,_______,_______,_______,   \
    _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,   \
                    _______,_______,                                            _______,_______,                   \
                                        _______,_______,    _______,_______,                                       \
                                        _______,_______,    _______,_______,                                       \
                                        _______,_______,    _______,BASE                                           \
),

/* Tabula rasa */
[_BLANK] = LAYOUT( \
    _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,   \
    _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,   \
    _______,_______,_______,_______,_______,_______,            _______,_______,_______,_______,_______,_______,   \
                    _______,_______,                                            _______,_______,                   \
                                        _______,_______,    _______,_______,                                       \
                                        _______,_______,    _______,_______,                                       \
                                        _______,_______,    _______,BASE                                           \
)

};


void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

/* Simultaneous pressing A+S -> ESC */
const uint16_t PROGMEM AS_combo[] = {KC_A, KC_S, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {COMBO(AS_combo, KC_ESC)};
