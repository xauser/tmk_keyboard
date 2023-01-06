/*
Copyright 2020 Ralf Schmitt <ralf@bunkertor.net>

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
    // Write the JTD bit twice in order to disable the JTAG port
    MCUCR |= (1 << JTD);
    MCUCR |= (1 << JTD);
    // D3 pin is connected to DIN of first RGB led
    DDRD  |=  0b00001000;

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
        _delay_us(3);
        uint16_t cols = read_cols();
        for (uint8_t col = 0; col < MATRIX_COLS; col++) {
            bool prev_bit = matrix_debouncing[row] & ((matrix_row_t) 1 << col);
            bool curr_bit = cols & (1 << col);
            if (prev_bit != curr_bit) {
                matrix_debouncing[row] ^= ((matrix_row_t) 1 << col);
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
    DDRF  &= ~0b11110011;
    PORTF |=  0b11110011;
    DDRC  &= ~0b11000000;
    PORTC |=  0b11000000;
    DDRD  &= ~0b00000100;
    PORTD |=  0b00000100;
}

static void init_rows(void)
{
    DDRB  &= ~0b01111111;
    PORTB &= ~0b01111111;
    DDRD  &= ~0b11010011;
    PORTD &= ~0b11010011;
}

static uint16_t read_cols(void)
{
    return (PINF & (1 << 0) ? 0 : (1 <<  0)) |
           (PINF & (1 << 1) ? 0 : (1 <<  1)) |
           (PINF & (1 << 4) ? 0 : (1 <<  2)) |
           (PINF & (1 << 5) ? 0 : (1 <<  3)) |
           (PINF & (1 << 6) ? 0 : (1 <<  4)) |
           (PINF & (1 << 7) ? 0 : (1 <<  5)) |
           (PINC & (1 << 7) ? 0 : (1 <<  6)) |
           (PINC & (1 << 6) ? 0 : (1 <<  7)) |
           (PIND & (1 << 2) ? 0 : (1 <<  8));
}

static void select_row(uint8_t row)
{
    switch (row)
    {
        case 0:
        {
            DDRB  |=  0b00000001;
            PORTB &= ~0b00000001;
        }
        break;
        case 1:
        {
            DDRB  |=  0b00000010;
            PORTB &= ~0b00000010;
        }
        break;
        case 2:
        {
            DDRB  |=  0b00000100;
            PORTB &= ~0b00000100;
        }
        break;
        case 3:
        {
            DDRB  |=  0b00001000;
            PORTB &= ~0b00001000;
        }
        break;
        case 4:
        {
            DDRD  |=  0b00000001;
            PORTD &= ~0b00000001;
        }
        break;
        case 5:
        {
            DDRD  |=  0b00000010;
            PORTD &= ~0b00000010;
        }
        break;
        case 6:
        {
            DDRB  |=  0b00100000;
            PORTB &= ~0b00100000;
        }
        break;
        case 7:
        {
            DDRB  |=  0b01000000;
            PORTB &= ~0b01000000;
        }
        break;
        case 8:
        {
            DDRD  |=  0b10000000;
            PORTD &= ~0b10000000;
        }
        break;
        case 9:
        {
            DDRB  |=  0b00010000;
            PORTB &= ~0b00010000;
        }
        break;
        case 10:
        {
            DDRD  |=  0b01000000;
            PORTD &= ~0b01000000;
        }
        break;
        case 11:
        {
            DDRD  |=  0b00010000;
            PORTD &= ~0b00010000;
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
            DDRB &= ~0b00000001;
        }
        break;
        case 1:
        {
            DDRB &= ~0b00000010;
        }
        break;
        case 2:
        {
            DDRB &= ~0b00000100;
        }
        break;
        case 3:
        {
            DDRB &= ~0b00001000;
        }
        break;
        case 4:
        {
            DDRD &= ~0b00000001;
        }
        break;
        case 5:
        {
            DDRD &= ~0b00000010;
        }
        break;
        case 6:
        {
            DDRB &= ~0b00100000;
        }
        break;
        case 7:
        {
            DDRB &= ~0b01000000;
        }
        break;
        case 8:
        {
            DDRD &= ~0b10000000;
        }
        break;
        case 9:
        {
            DDRB &= ~0b00010000;
        }
        break;
        case 10:
        {
            DDRD &= ~0b01000000;
        }
        break;
        case 11:
        {
            DDRD &= ~0b00010000;
        }
        break;
    }
}
