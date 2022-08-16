#include <stdint.h>
#include <stdbool.h>
#include <hal.h>
#include "timer.h"
#include "wait.h"
#include "print.h"
#include "matrix.h"
#include "debounce.h"

#include QMK_KEYBOARD_H

#ifndef DEBOUNCE
#define DEBOUNCE 10
#endif

volatile matrix_row_t matrix[MATRIX_COLS];
volatile matrix_row_t raw_matrix[MATRIX_COLS];
volatile uint8_t debounce_matrix[MATRIX_ROWS * MATRIX_COLS];


__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }

__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }

__attribute__((weak)) void matrix_init_user(void) {}

__attribute__((weak)) void matrix_scan_user(void) {}


matrix_row_t matrix_get_row(uint8_t row) {
    // TODO: return the requested row data
    return 0x0000000;
}

void matrix_print(void) {
    // TODO: use print() to dump the current matrix state to console
}

void matrix_init(void) {
    // TODO: initialize hardware and global matrix state here

    // // Unless hardware debouncing - Init the configured debounce routine
    debounce_init(MATRIX_COLS);

    // This *must* be called for correct keyboard behavior
    matrix_init_quantum();
}

uint8_t matrix_scan(void) {
    bool matrix_has_changed = false;

    // TODO: add matrix scanning routine here

    // Unless hardware debouncing - use the configured debounce routine
    // debounce(raw_matrix, matrix, MATRIX_ROWS, changed);

    // This *must* be called for correct keyboard behavior
    matrix_scan_quantum();

    return matrix_has_changed;
}
