/**
 * CS1010 Semester 1 AY18/19
 * Exercise 5: Square
 *
 * @file: square.c
 * @author: YANG CHENGLONG (Group 1)
 */
#include "cs1010.h"
#include <stdlib.h>

void fit_in_square(char **square, long x, long y,long side);
void update_square(char **square, long side);

int main() {
    long num = cs1010_read_long();
    char **square;
    square = calloc(num, sizeof(char *));
    for (long i = 0; i < num; i += 1) {
        square[i] = calloc(num + 1, sizeof(char));
    }
    for (long i = 0; i < num; i += 1) {
        for (long j = 0; j < num; j += 1) {
            *(*(square + i) + j) = ' ';
        }
        *(*(square + i) + num) = '\0';        
    }
    update_square(square, num); 
    for (long i = 0; i < num; i += 1) {
        cs1010_println_string(*(square + i));
    }

    for (long i = 0; i < num; i += 1) {
        free(square[i]);
    }
    free(square);
}

void fit_in_square(char **square, long x, long y, long side) {
   for (long i = y; i < y + side; i += 1) {
       if (i == y || i == y + side- 1) {
           for (long j = x; j < x + side; j += 1) {
               *(*(square + i) + j) = '#';
           }
       } else {
           *(*(square + i) + x) = '#';
           *(*(square + i) + x + side - 1) = '#';
       }
   }
}

void update_square(char **square, long side) {
    long i = side;
    long x = 0;
    long y = 0;
    while (i >= 1) {
        fit_in_square(square, x, y, i);
        i -= 4;
        x += 2;
        y += 2;
    }
}
