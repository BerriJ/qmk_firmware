#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "sendstring_german.h"

enum custom_keycodes {
  PIPE = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case PIPE:
      if (record->event.pressed) {
        // when keycode PIPE is pressed
        SEND_STRING("%>%"SS_TAP(X_ENT));
      } else {
        // when keycode PIPE is released
      }
      break;

  }
  return true;
};

// Tap dance action on escape key
enum {
 CT_CLN
};

void dance_cln_finished (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
		if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
			register_code (KC_LSFT);
  		register_code (DE_CIRC);
			} else {
			register_code (KC_ESCAPE);
			}
  } else if (state->count == 2) {
    register_code (DE_CIRC);
		unregister_code (DE_CIRC);
  }
}

void dance_cln_reset (tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
		if (keyboard_report->mods & MOD_BIT(KC_LSFT)) {
			unregister_code (KC_LSFT);
			unregister_code (DE_CIRC);
			} else {
			unregister_code (KC_ESCAPE);
			}
  } else if (state->count == 2) {
		register_code (DE_CIRC);
    unregister_code (DE_CIRC);
  }
}

//All tap dance functions would go here. Only showing this one.
tap_dance_action_t tap_dance_actions[] = {
 [CT_CLN] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_cln_finished, dance_cln_reset)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  LAYOUT(
    TD(CT_CLN), KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_NO, KC_BSPC,
    LT(2, KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    MO(1), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_NUHS, KC_ENT,
    QK_SPACE_CADET_LEFT_SHIFT_PARENTHESIS_OPEN, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(DE_LABK), KC_NO,
    KC_LCTL, KC_LGUI, KC_LALT,                        KC_SPC,                          KC_NO,KC_RALT, KC_AUDIO_MUTE, KC_RCTL),

  LAYOUT(
    KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_AUDIO_VOL_UP,
    QK_BOOTLOADER, LSFT(KC_9), RALT(KC_9), RALT(KC_0), LCA(KC_R), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, PIPE, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, LSFT(KC_8), RALT(KC_8), RALT(KC_7), LCTL(KC_F), KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_NO, KC_TRNS, KC_MEDIA_PLAY_PAUSE,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_AUDIO_VOL_DOWN, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, MEH(KC_C), KC_MEDIA_PREV_TRACK, KC_NO, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK),

  LAYOUT(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_HOME, KC_PAGE_DOWN, KC_PAGE_UP, KC_END, KC_NO, KC_TRNS, KC_NO, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_NO,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_TRNS, KC_TRNS),
};

