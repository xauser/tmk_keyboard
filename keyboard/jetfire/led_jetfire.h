#ifndef LED_JETFIRE_H
#define LED_JETFIRE_H

#include <stdbool.h>
#include <stdint.h>

enum backlight_level {
    BACKLIGHT_LEVEL_ALPHA    = 0b0000001,
    BACKLIGHT_LEVEL_MOD      = 0b0000010,
    BACKLIGHT_LEVEL_FROW     = 0b0000100,
    BACKLIGHT_LEVEL_NUMBLOCK = 0b0001000,
    BACKLIGHT_LEVEL_RGB      = 0b0010000,
    BACKLIGHT_LEVEL_SWITCH   = 0b0001111
};

enum backlight_step {
    BACKLIGHT_STEP_RED,
    BACKLIGHT_STEP_GREEN,
    BACKLIGHT_STEP_BLUE,
    BACKLIGHT_STEP_RESET
};

enum state_led {
    STATE_LED_SCROLL_LOCK,
    STATE_LED_CAPS_LOCK,
    STATE_LED_NUM_LOCK,
    STATE_LED_LAYER_0,
    STATE_LED_LAYER_1,
    STATE_LED_LAYER_2,
    STATE_LED_LAYER_3,
    STATE_LED_LAYER_4
};

void led_init(void);
void backlight_set_state(bool cfg[7]);
void backlight_update_state_led(void);
void backlight_toggle_rgb(bool enabled);
void backlight_set_rgb(uint8_t cfg[17][3]);
void backlight_set(uint8_t level);
void backlight_set_step(uint8_t step);

#endif // LED_JETFIRE_H
