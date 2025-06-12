#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
};

// Define custom keycodes starting from SAFE_RANGE
// In QMK firmware, SAFE_RANGE is used to ensure that custom keycodes
// do not conflict with predefined keycodes.
enum custom_keycodes {
    CUSTOM_STRING_BASE = SAFE_RANGE, // Base value for custom keycodes
    CUSTOM_STRING_1,
    CUSTOM_STRING_2,
    // Open iTerm
    O_ITRM,
    // Open Visual Studio Code
    O_VSC,
    // Open Google Chrome
    O_CHRM,
    // Open Cursor
    O_CRSR,
    // Open IntelliJ IDEA
    O_INTLJ,
    // Open Slack
    O_SLCK,
    // Open ChatGPT
    O_GPT,
    // Open MindNode
    O_MNDN,


    // Combo 4 modifiers
    C4M_Q,
    C4M_W,
    C4M_E,
    C4M_R,
    C4M_T,

    C4M_A,
    C4M_S,
    C4M_F,
    C4M_D,
    C4M_G,

    C4M_Z,
    C4M_X,
    C4M_C,
    C4M_V,
    C4M_B,

    C4M_N,
    C4M_M,

    C4M_H,
    C4M_J,
    C4M_K,
    C4M_L,
    C4M_Y,
    C4M_U,
    C4M_I,
    C4M_O,
    C4M_P,


    // Combo 3 modifiers with option
    // one is actually used for another key; while C3MO_C has meaning to terminals
    // we want to have C3MO_C (Now C3MO_1 be able to be used as add selection
    // to context)
    C3MO_Z,
    C3MO_X,
    C3MO_V,
    C3MO_B,

    C3MO_1,

    C3MO_3,
    C3MO_4,
    C3MO_5,

    C3MO_A,
    C3MO_S,
    C3MO_D,
    C3MO_F,
    C3MO_G,

    C3MO_H,

    C3MO_C,



    C3MO_Q,
    C3MO_W,
    C3MO_E,
    C3MO_R,
    C3MO_T,
    C3MO_M,

    // C3MO_<
    // Key "," KC_COMM
    C3MO_LT,

    // C3MO_>
    // Key "." KC_DOT
    C3MO_GT,


    // Combo 3 modifiers with command
    C3MC_Q,
    C3MC_W,
    C3MC_R,

    C3MC_A,
    C3MC_S,
    C3MC_D,
    C3MC_F,
    C3MC_G,
    C3MC_H,
    C3MC_J,
    C3MC_K,
    C3MC_L,
    C3MC_M,
    C3MC_P,

    // ```
    CODE_BLOCK,
};

// Define an array of custom strings corresponding to custom keycodes
const char* custom_strings[] = {
    [CUSTOM_STRING_1 - CUSTOM_STRING_BASE] = "2>&1 | ",
    [CUSTOM_STRING_2 - CUSTOM_STRING_BASE] = "Another custom string",
    // Add more custom strings as needed
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ---------------------------------------------------------------------------------------------------------------
/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |LCTRL |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt | _RAISE| /Space  /       \Enter \  |LOWER | LAlt | LGUI |
 *                   |      |      |       |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_LCTL,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
                        KC_LGUI, KC_LALT, MO(_RAISE), KC_SPC, KC_ENT, MO(_LOWER), KC_LALT, KC_LGUI
),

// ---------------------------------------------------------------------------------------------------------------
/* LOWER/Right hand Activated by RIGHT HAND side activation
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | Delete|  F1  |  F2  |  F3  |  F4  |  F5  |                    | 2>&1 |  +   |  =   |  \   |  {   |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |C3MC_Q|C3MC_W|  Up  |C3MC_R|O_ITRM|                    |  |   |  '   |O_INTLJ|      |C3MC_P |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |C3MC_A|O_SLCK|C3MC_D|C3MC_F| O_GPT|-------.    ,-------|C3MC_H|C3MC_J|C3MC_K| "    | '    |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LSHIFT|      |O_CRSR|O_CHRM|      |      |-------|    |-------|O_VSC |C3MC_M|O_MNDN|      |      |LSHIFT|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI | LAlt |       | /       /       \     \  |      |      |      |
 *                   |      |      |       |/       /         \     \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  KC_DEL,  KC_F1,   KC_F2,   KC_F3,    KC_F4,   KC_F5,                CUSTOM_STRING_1, KC_PLUS, KC_EQL,  KC_BSLS, KC_LCBR, KC_TRNS,
  KC_TRNS,  C3MC_Q, C3MC_W,    KC_UP,  C3MC_R,  O_ITRM,                KC_PIPE,  KC_QUOT, O_INTLJ, KC_TRNS, C3MC_P, KC_EQL,
  KC_TRNS,  C3MC_A, O_SLCK,   C3MC_D,  C3MC_F,  O_GPT,                C3MC_H,   C3MC_J,  C3MC_K, KC_DQT,  KC_DQT, KC_TRNS,
  KC_LSFT, KC_TRNS, O_CRSR, O_CHRM,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, O_VSC, C3MC_M, O_MNDN, KC_TRNS, KC_TRNS, KC_LSFT,
                             KC_LGUI, KC_LALT, KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS
),

// ---------------------------------------------------------------------------------------------------------------
/* RAISE/LEFT hand Activated by LEFT HAND side activation
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ~   |  `   |  ~   |C3MO_3|C3MO_4|C3MO_5|                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |C3MO_Q|C3MO_W|C3MO_E|C3MO_R|C3MO_T|                    | F12  |  '   |  _   |  -   |  Up  | PgUp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |C3MO_A|C3MO_S|C3MO_D|C3MO_F|C3MO_G|-------.    ,-------|C3MO_H| Left |Right | Down |  Up  |PgDwn |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |C3MO_Z|C3MO_X|C3MO_1|C3MO_V|C3MO_B|-------|    |-------| Down |C3MO_M|C3MO_<|C3MO_>|      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |       | /       /       \     \  |      |      |      |
 *                   | LGUI | LAlt |       |/       /         \     \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_RAISE] = LAYOUT(
  KC_TILD, KC_GRV,  KC_TILD,  C3MO_3,  C3MO_4,  C3MO_5,                     KC_F6,   KC_F7,    KC_F8,   KC_F9, KC_F10,  KC_F11,
  KC_TRNS,  C3MO_Q,  C3MO_W,  C3MO_E,  C3MO_R,  C3MO_T,                   KC_F12,  KC_QUOT, KC_UNDS, KC_MINS, KC_UP,   KC_PGUP,
  KC_TRNS,  C3MO_A,  C3MO_S,  C3MO_D,  C3MO_F,  C3MO_G,                   C3MO_H, KC_LEFT, KC_RGHT, KC_DOWN, KC_UP,   KC_PGDN,
  KC_TRNS,  C3MO_Z,  C3MO_X,  C3MO_1,  C3MO_V,  C3MO_B, KC_TRNS, KC_TRNS, KC_DOWN,  C3MO_M,  C3MO_LT, C3MO_GT, KC_TRNS, KC_TRNS,
                             KC_LGUI, KC_LALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
),

// ---------------------------------------------------------------------------------------------------------------
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  QK_BOOT   | ```   |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |C4M_Q |C4M_W |C4M_E |C4M_R |C4M_T |                    |C4M_Y |C4M_U |C4M_I |C4M_O |C4M_P |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |C4M_A |C4M_S |C4M_D |C4M_F |C4M_G |-------.    ,-------| C4M_H|C4M_J |C4M_K |C4M_L |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |C4M_Z |C4M_X |C4M_C |C4M_V |C4M_B |-------|    |-------| C4M_N|C4M_M |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI | RAISE| /Space  /       \Enter \  |LOWER |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT(
  QK_BOOT, CODE_BLOCK, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, C4M_Q, C4M_W, C4M_E, C4M_R, C4M_T,                             C4M_Y, C4M_U, C4M_I, C4M_O, C4M_P, XXXXXXX,
  XXXXXXX, C4M_A, C4M_S, C4M_D, C4M_F, C4M_G,                             C4M_H, C4M_J, C4M_K, C4M_L, XXXXXXX, XXXXXXX,
  XXXXXXX, C4M_Z, C4M_X, C4M_C, C4M_V, C4M_B, XXXXXXX,           XXXXXXX,C4M_N, C4M_M, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             _______, _______, _______, _______, _______,  _______, _______, _______
  )
};

// ---------------------------------------------------------------------------------------------------------------
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE


void launch_app(const char* app_name) {
    // Cmd+Space, type 'app_name', Enter
    SEND_STRING(SS_LGUI(" "));
    wait_ms(200);
    send_string(app_name);
    SEND_STRING(SS_TAP(X_ENTER));
}

void send_4_mod_combo(uint16_t main_key) {
    // Register the 4 modifier keys
    register_code(KC_LSFT);  // Shift
    register_code(KC_LCTL);  // Ctrl
    register_code(KC_LGUI);  // Cmd
    register_code(KC_LALT);  // Option

    // Send the main key
    tap_code(main_key);

    // Unregister the modifier keys
    unregister_code(KC_LALT);
    unregister_code(KC_LGUI);
    unregister_code(KC_LCTL);
    unregister_code(KC_LSFT);
}

void send_3_mod_option_combo(uint16_t main_key) {
    // Register the 3 modifier keys (Shift, Ctrl, Option)
    register_code(KC_LSFT);  // Shift
    register_code(KC_LCTL);  // Ctrl
    register_code(KC_LALT);  // Option

    // Send the main key
    tap_code(main_key);

    // Unregister the modifier keys
    unregister_code(KC_LALT);
    unregister_code(KC_LCTL);
    unregister_code(KC_LSFT);
}

void send_3_mod_cmd_combo(uint16_t main_key) {
    // Register the 3 modifier keys (Shift, Ctrl, Command)
    register_code(KC_LSFT);  // Shift
    register_code(KC_LCTL);  // Ctrl
    register_code(KC_LGUI);  // Command (on macOS, LGUI is the Command key)

    // Send the main key
    tap_code(main_key);

    // Unregister the modifier keys
    unregister_code(KC_LGUI);
    unregister_code(KC_LCTL);
    unregister_code(KC_LSFT);
}

// Custom keycode processing
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        #ifdef OLED_ENABLE
            set_keylog(keycode, record);
        #endif

        size_t num_custom_strings = sizeof(custom_strings) / sizeof(custom_strings[0]);
        if (keycode >= CUSTOM_STRING_BASE && keycode < CUSTOM_STRING_BASE + num_custom_strings) {
            const char* custom_string = custom_strings[keycode - CUSTOM_STRING_BASE];

            if (custom_string) {
                send_string(custom_string);
                return false; // Skip further processing of this key
            }
        }

         switch (keycode) {
            case O_ITRM:
                launch_app("iTerm");
                return false;
            case O_VSC:
                launch_app("Visual Studio Code");
                return false;
            case O_CHRM:
                launch_app("Google Chrome");
                return false;
            case O_CRSR:
                launch_app("Cursor");
                return false;
            case O_INTLJ:
                launch_app("IntelliJ IDEA");
                return false;
            case O_SLCK:
                launch_app("Slack");
                return false;
            case O_GPT:
                launch_app("ChatGPT");
                return false;
            case O_MNDN:
                launch_app("MindNode");
                return false;
           case CODE_BLOCK:
               send_string("```");
               return false;
            //---------------------------------------------------------------------------------
            case C4M_Q:
                send_4_mod_combo(KC_Q);
                return false;
            case C4M_W:
                send_4_mod_combo(KC_W);
                return false;
            case C4M_E:
                send_4_mod_combo(KC_E);
                return false;
            case C4M_R:
                send_4_mod_combo(KC_R);
                return false;
            case C4M_T:
                send_4_mod_combo(KC_T);
                return false;
            case C4M_A:
                send_4_mod_combo(KC_A);
                return false;
            case C4M_S:
                send_4_mod_combo(KC_S);
                return false;
            case C4M_F:
                send_4_mod_combo(KC_F);
                return false;
            case C4M_D:
                send_4_mod_combo(KC_D);
                return false;
            case C4M_G:
                send_4_mod_combo(KC_G);
                return false;
            case C4M_Z:
                send_4_mod_combo(KC_Z);
                return false;
            case C4M_X:
                send_4_mod_combo(KC_X);
                return false;
            case C4M_C:
                send_4_mod_combo(KC_C);
                return false;
            case C4M_V:
                send_4_mod_combo(KC_V);
                return false;
            case C4M_B:
                send_4_mod_combo(KC_B);
                return false;
            case C4M_N:
                send_4_mod_combo(KC_N);
                return false;
            case C4M_M:
                send_4_mod_combo(KC_M);
                return false;
            case C4M_H:
                send_4_mod_combo(KC_H);
                return false;
            case C4M_J:
                send_4_mod_combo(KC_J);
                return false;
            case C4M_K:
                send_4_mod_combo(KC_K);
                return false;
            case C4M_L:
                send_4_mod_combo(KC_L);
                return false;
            case C4M_Y:
                send_4_mod_combo(KC_Y);
                return false;
            case C4M_U:
                send_4_mod_combo(KC_U);
                return false;
            case C4M_I:
                send_4_mod_combo(KC_I);
                return false;
            case C4M_O:
                send_4_mod_combo(KC_O);
                return false;
            case C4M_P:
                send_4_mod_combo(KC_P);
                return false;
            // --------------------------------------------------------------------------------
            case C3MO_A:
                send_3_mod_option_combo(KC_A);
                return false;
            case C3MO_S:
                send_3_mod_option_combo(KC_S);
                return false;
            case C3MO_D:
                send_3_mod_option_combo(KC_D);
                return false;
            case C3MO_F:
                send_3_mod_option_combo(KC_F);
                return false;
            case C3MO_G:
                send_3_mod_option_combo(KC_G);
                return false;
            case C3MO_H:
                send_3_mod_option_combo(KC_H);
                return false;
            case C3MO_C:
                send_3_mod_option_combo(KC_C);
                return false;
            case C3MO_Z:
                send_3_mod_option_combo(KC_Z);
                return false;
            case C3MO_X:
                send_3_mod_option_combo(KC_X);
                return false;
            case C3MO_V:
                send_3_mod_option_combo(KC_V);
                return false;
            case C3MO_B:
                send_3_mod_option_combo(KC_B);
                return false;
            case C3MO_1:
                send_3_mod_option_combo(KC_1);
                return false;
             case C3MO_3:
                 send_3_mod_option_combo(KC_3);
                 return false;
             case C3MO_4:
                 send_3_mod_option_combo(KC_4);
                 return false;
             case C3MO_5:
                 send_3_mod_option_combo(KC_5);
                 return false;
            case C3MO_LT:
                send_3_mod_option_combo(KC_COMM);
                return false;
            case C3MO_GT:
                send_3_mod_option_combo(KC_DOT);
                return false;
            case C3MO_Q:
                send_3_mod_option_combo(KC_Q);
                return false;
           case C3MO_W:
                send_3_mod_option_combo(KC_W);
                return false;
           case C3MO_E:
                send_3_mod_option_combo(KC_E);
                return false;
           case C3MO_R:
                send_3_mod_option_combo(KC_R);
                return false;
           case C3MO_T:
                send_3_mod_option_combo(KC_T);
                return false;
           case C3MO_M:
                send_3_mod_option_combo(KC_M);
                return false;
            // --------------------------------------------------------------------------------
            case C3MC_Q:
                send_3_mod_cmd_combo(KC_Q);
                return false;
            case C3MC_W:
                send_3_mod_cmd_combo(KC_W);
                return false;
            case C3MC_R:
                send_3_mod_cmd_combo(KC_R);
                return false;
            case C3MC_A:
                send_3_mod_cmd_combo(KC_A);
                return false;
            case C3MC_S:
                send_3_mod_cmd_combo(KC_S);
                return false;
            case C3MC_D:
                send_3_mod_cmd_combo(KC_D);
                return false;
            case C3MC_F:
                send_3_mod_cmd_combo(KC_F);
                return false;
            case C3MC_G:
                send_3_mod_cmd_combo(KC_G);
                return false;
           case C3MC_H:
                send_3_mod_cmd_combo(KC_H);
                return false;
            case C3MC_J:
                send_3_mod_cmd_combo(KC_J);
                return false;
            case C3MC_M:
                send_3_mod_cmd_combo(KC_M);
                return false;
            case C3MC_K:
                send_3_mod_cmd_combo(KC_K);
                return false;
            case C3MC_P:
                send_3_mod_cmd_combo(KC_P);
                return false;
            case C3MC_L:
                send_3_mod_cmd_combo(KC_L);
                return false;

        }
    }
    return true;
}
