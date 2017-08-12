#ifndef FC660C_H
#define FC660C_H

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "timer.h"
#include "unimap.h"


// Timer resolution check
#if (1000000/TIMER_RAW_FREQ > 20)
#   error "Timer resolution(>20us) is not enough for HHKB matrix scan tweak on V-USB."
#endif


/*
 * Pin configuration for ATMega32U4
 *
 * Row:     PD4-6, 7(~EN)
 * Col:     PB0-2, 3(Z5 ~EN), 4(Z4 ~EN)
 * Key:     PC6(pull-uped)
 * Hys:     PC7
 */
static inline void KEY_ENABLE(void) { (PORTD &= ~(1<<7)); }
static inline void KEY_UNABLE(void) { (PORTD |=  (1<<7)); }
static inline bool KEY_STATE(void) { return (PINC & (1<<6)); }
static inline void KEY_HYS_ON(void) { (PORTC |=  (1<<7)); }
static inline void KEY_HYS_OFF(void) { (PORTC &= ~(1<<7)); }
static inline void KEY_INIT(void)
{
    /* Col */
    DDRB  |=  0x1F;
    /* Key: input with pull-up */
    DDRC  &= ~(1<<6);
    PORTC |=  (1<<6);
    /* Hys */
    DDRC  |=  (1<<7);
    /* Row */
    DDRD  |=  0xF0;

    KEY_UNABLE();
    KEY_HYS_OFF();
}
static inline void SET_ROW(uint8_t ROW)
{
    // set row with unabling key
    PORTD = (PORTD & 0x0F) | (1<<7) | ((ROW & 0x07) << 4);
}
static inline void SET_COL(uint8_t COL)
{
    //         |PB3(Z5 ~EN)|PB4(Z4 ~EN)
    // --------|-----------|-----------
    // Col:0-7 |high       |low
    // Col:8-F |low        |high
    PORTB = (PORTB & 0xE0) | ((COL & 0x08) ? 1<<4 : 1<<3) | (COL & 0x07);
}


#ifdef UNIMAP_ENABLE
/* unimap */
#define KMAP( \
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,K2A,    K49, \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,K31,    K4C, \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    K28,         \
    K79,K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,        K7D,K52,     \
    K78,K7B,K7A,            K2C,            K7E,K7C,K7F,K50,K51,K4F  \
) UNIMAP( \
            NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO,                                     \
    NO,     NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO, NO,       NO, NO, NO,       NO, NO, NO, \
    K35,K1E,K1F,K20,K21,K22,K23,K24,K25,K26,K27,K2D,K2E,NO, K2A,  K49,NO, NO,   NO, NO, NO, NO, \
    K2B,K14,K1A,K08,K15,K17,K1C,K18,K0C,K12,K13,K2F,K30,    K31,  K4C,NO, NO,   NO, NO, NO, NO, \
    K39,K04,K16,K07,K09,K0A,K0B,K0D,K0E,K0F,K33,K34,    NO, K28,                NO, NO, NO, NO, \
    K79,NO, K1D,K1B,K06,K19,K05,K11,K10,K36,K37,K38,    NO, K7D,      K52,      NO, NO, NO, NO, \
    K78,K7B,K7A,NO,         K2C,        NO, NO, K7E,K7F,NO, K7C,  K50,K51,K4F,  NO,     NO, NO  \
)
#else
/* actionmap */
#define KMAP( \
    K13, K10, K11, K12, K14, K16, K17, K15, K1B, K18, K19, K1A, K1C, K1E,      K1F, \
    K03, K00, K01, K02, K04, K06, K07, K05, K0B, K08, K09, K0A, K0C, K0E,      K0F, \
    K43, K40, K41, K42, K44, K46, K47, K45, K4B, K48, K49, K4A,      K4E,           \
    K33, K31, K32, K34, K36, K37, K35, K3B, K38, K39, K3A,           K3C, K3D,      \
    K23, K21, K22,                K27,                K28, K2A, K2C, K2E, K2D, K2F  \
) { \
    { KC_##K00, KC_##K01, KC_##K02, KC_##K03, KC_##K04, KC_##K05, KC_##K06, KC_##K07,   \
      KC_##K08, KC_##K09, KC_##K0A, KC_##K0B, KC_##K0C, KC_NO,    KC_##K0E, KC_##K0F }, \
    { KC_##K10, KC_##K11, KC_##K12, KC_##K13, KC_##K14, KC_##K15, KC_##K16, KC_##K17,   \
      KC_##K18, KC_##K19, KC_##K1A, KC_##K1B, KC_##K1C, KC_NO,    KC_##K1E, KC_##K1F }, \
    { KC_NO,    KC_##K21, KC_##K22, KC_##K23, KC_NO,    KC_NO,    KC_NO,    KC_##K27,   \
      KC_##K28, KC_NO,    KC_##K2A, KC_NO,    KC_##K2C, KC_##K2D, KC_##K2E, KC_##K2F }, \
    { KC_NO,    KC_##K31, KC_##K32, KC_##K33, KC_##K34, KC_##K35, KC_##K36, KC_##K37,   \
      KC_##K38, KC_##K39, KC_##K3A, KC_##K3B, KC_##K3C, KC_##K3D, KC_NO,    KC_NO    }, \
    { KC_##K40, KC_##K41, KC_##K42, KC_##K43, KC_##K44, KC_##K45, KC_##K46, KC_##K47,   \
      KC_##K48, KC_##K49, KC_##K4A, KC_##K4B, KC_NO,    KC_NO,    KC_##K4E, KC_NO    }, \
    { KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      \
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO    }, \
    { KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      \
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO    }, \
    { KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,      \
      KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO    }  \
}
#endif

#endif
