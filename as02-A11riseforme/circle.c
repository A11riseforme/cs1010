/**
 * CS1010 Semester 1 AY18/19
 * Assignment 2: Circle
 *
 * @file: circle.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include <math.h>
#include "cs1010.h"

double distance(long x, long y, long r);
void print_char(long x, long y, long r);

int main() {
    long r = cs1010_read_long();
    for (long y = 0; y <= 2 * r; y += 1) {
        for (long x = 0; x <= 2 * r; x += 1) {
            print_char(x, y, r);
        }
        cs1010_print_string("\n");
    }
}

// This function will calculate the distance
// from the give point to the center of circle.
double distance(long x, long y, long r) {
    return sqrt(pow(x - r, 2) + pow(y - r, 2));
}

// This function will decide what character
// should be printed at the given point
void print_char(long x, long y, long r) {
    double difference = fabs(distance(x, y, r) - r);
    if (difference < 0.1) {
        cs1010_print_string("@");
    } else if (difference < 0.3) {
        cs1010_print_string("O");
    } else if (difference < 0.5) {
        cs1010_print_string("*");
    } else if (difference < 0.7) {
        cs1010_print_string("+");
    } else {
        cs1010_print_string(" ");
    }
}
