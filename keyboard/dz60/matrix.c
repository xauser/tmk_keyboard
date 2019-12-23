/*
Copyright 2019 Ralf Schmitt <ralf@bunkertor.net>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <stdbool.h>
#include <avr/io.h>
#include <util/delay.h>
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"

static uint8_t debouncing = DEBOUNCE;

/* matrix state(1:on, 0:off) */
static matrix_row_t matrix[MATRIX_ROWS];
static matrix_row_t matrix_debouncing[MATRIX_ROWS];

static void init_cols(void);
static void init_rows(void);
static uint16_t read_cols(void);
static void select_row(uint8_t row);
static void unselect_row(uint8_t row);

inline
uint8_t matrix_rows(void)
{
    return MATRIX_ROWS;
}

inline
uint8_t matrix_cols(void)
{
    return MATRIX_COLS;
}

void matrix_init(void)
{
    // To use PORTF disable JTAG with writing JTD bit twice within four cycles.
    MCUCR |= (1<<JTD);
    MCUCR |= (1<<JTD);

    init_cols();
    init_rows();
    for (uint8_t i=0; i < MATRIX_ROWS; i++) {
        matrix[i] = 0;
        matrix_debouncing[i] = 0;
    }
}

uint8_t matrix_scan(void)
{
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
      select_row(row);
      uint16_t cols = read_cols();
      for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            bool prev_bit = matrix_debouncing[row] & ((matrix_row_t) 1<<col);
            bool curr_bit = cols & (1 << col);
            if (prev_bit != curr_bit) {
                matrix_debouncing[row] ^= ((matrix_row_t) 1<<col);
                debouncing = DEBOUNCE;
            }
      }
      unselect_row(row);
    }
    if (debouncing) {
        if (--debouncing) {
            _delay_ms(1);
        } else {
            for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
                matrix[i] = matrix_debouncing[i];
            }
        }
    }

    return 1;
}

bool matrix_is_modified(void)
{
    if (debouncing) return false;
    return true;
}

inline
bool matrix_is_on(uint8_t row, uint8_t col)
{
    return (matrix[row] & ((matrix_row_t)1<<col));
}

inline
matrix_row_t matrix_get_row(uint8_t row)
{
    return matrix[row];
}

void matrix_print(void)
{
    print("\nr/c 0123456789ABCDEF\n");
    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        phex(row); print(": ");
        pbin_reverse16(matrix_get_row(row));
        print("\n");
    }
}

uint8_t matrix_key_count(void)
{
    uint8_t count = 0;
    for (uint8_t i = 0; i < MATRIX_ROWS; i++) {
        count += bitpop16(matrix[i]);
    }
    return count;
}

static void init_cols(void)
{
    // pinput, pull up
    DDRF  &= ~0b00010011;
    PORTF |=  0b00010011;
    DDRE  &= ~0b01000000;
    PORTE |=  0b01000000;
    DDRC  &= ~0b11000000;
    PORTC |=  0b11000000;
    DDRB  &= ~0b10111011;
    PORTB |=  0b10111011;
    DDRD  &= ~0b11010000;
    PORTD |=  0b11010000;
}

static void init_rows(void)
{
    // output, low
    DDRD  |=  0b00101111;
    PORTD &= ~0b00101111;
}

static uint16_t read_cols(void)
{
    return (PINF & (1 << 0) ? 0 : (1 <<  0)) |
           (PINF & (1 << 1) ? 0 : (1 <<  1)) |
           (PINE & (1 << 6) ? 0 : (1 <<  2)) |
           (PINC & (1 << 7) ? 0 : (1 <<  3)) |
           (PINC & (1 << 6) ? 0 : (1 <<  4)) |
           (PINB & (1 << 7) ? 0 : (1 <<  5)) |
           (PIND & (1 << 4) ? 0 : (1 <<  6)) |
           (PINB & (1 << 1) ? 0 : (1 <<  7)) |
           (PINB & (1 << 0) ? 0 : (1 <<  8)) |
           (PINB & (1 << 5) ? 0 : (1 <<  9)) |
           (PINB & (1 << 4) ? 0 : (1 << 10)) |
           (PIND & (1 << 7) ? 0 : (1 << 11)) |
           (PIND & (1 << 6) ? 0 : (1 << 12)) |
           (PINB & (1 << 3) ? 0 : (1 << 13)) |
           (PINF & (1 << 4) ? 0 : (1 << 14));
}

static void select_row(uint8_t row)
{
    switch (row)
    {
        case 0:
        {
          DDRD  |=   0b00000001;
          PORTD &=  ~0b00000001;
        }
        break;
        case 1:
        {
          DDRD  |=   0b00000010;
          PORTD &=  ~0b00000010;
        }
        break;
        case 2:
        {
          DDRD  |=   0b00000100;
          PORTD &=  ~0b00000100;
        }
        break;
        case 3:
        {
          DDRD  |=   0b00001000;
          PORTD &=  ~0b00001000;
        }
        break;
        case 4:
        {
          DDRD  |=  0b00100000;
          PORTD &= ~0b00100000;
        }
        break;
    }
}

static void unselect_row(uint8_t row)
{
    switch (row)
    {
        case 0:
        {
          DDRD &= ~0b00000001;
        }
        break;
        case 1:
        {
          DDRD &= ~0b00000010;
        }
        break;
        case 2:
        {
          DDRD &= ~0b00000100;
        }
        break;
        case 3:
        {
          DDRD &= ~0b00001000;
        }
        break;
        case 4:
        {
          DDRD &= ~0b00100000;
        }
        break;
    }
}
