/**
 * CS1010 Semester 1 AY18/19
 * Exercise 5: Magicsquare
 *
 * @file: magicsquare.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <stdlib.h>

void fit_in_number(long i, long side, long **square, long *pos);

int main() {
    long side = cs1010_read_long();
    long *pos = calloc(2, sizeof(long));
    *(pos + 0) = 0;
    *(pos + 1) = (side - 1) / 2;
    long **square = calloc(side, sizeof(long *));
    for (long i = 0; i < side; i += 1) {
        *(square + i) = calloc(side, sizeof(long));
    }

    long num = side * side;
    for (long i = 1; i < num + 1; i += 1) {
        fit_in_number(i, side, square, pos);
    }

    for (long i = 0; i < side; i += 1) {
        for (long j = 0; j < side; j += 1) {
            cs1010_print_long(*(*(square + i) + j));
            cs1010_print_string(" ");
        }
        cs1010_println_string("");
    }
    for (long i = 0; i < side; i += 1) {
        free(*(square + i));
    }
    free(square);
    free(pos);
}

void fit_in_number(long i, long side, long **square, long *pos) {
    if (*(pos + 0) < 0 && *(pos + 1) >= side) {
        *(pos + 0) += 2;
        *(pos +1 ) -= 1;
        fit_in_number(i, side, square, pos);
    } else if(*(pos + 0) < 0) {
        *(pos + 0) = side - 1;
        fit_in_number(i, side, square, pos);
    } else if (*(pos + 1) >= side) {
        *(pos + 1) = 0;
        fit_in_number(i, side, square, pos);
    } else if (*(*(square + *(pos + 0)) + *(pos + 1)) != '\0') {
        *(pos + 0) += 2;
        *(pos + 1) -= 1;
        fit_in_number(i, side, square, pos);
    } else {
        *(*(square + *(pos + 0)) + *(pos + 1)) = i;
        *(pos + 0) -= 1;
        *(pos + 1) += 1;
    }
}
