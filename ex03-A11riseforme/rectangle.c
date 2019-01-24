/**
 * CS1010 Semester 1 AY18/19
 * Exercise 3: Rectangle
 *
 * Read two integer numbers corresponding to the width and the 
 * height of a rectangle.   Draw the rectangle with the given
 * characters to the standard output.
 *
 * @file: rectangle.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"

#define TOP_LEFT "╔"
#define TOP_RIGHT "╗"
#define BOTTOM_RIGHT "╝"
#define BOTTOM_LEFT "╚"
#define HORIZONTAL "═"
#define VERTICAL "║"

int main() {
    long width = cs1010_read_long();
    long length = cs1010_read_long();
    // print the first line.
    cs1010_print_string(TOP_LEFT);
    for (int i = 0; i < width - 2; i++ ) {
        cs1010_print_string(HORIZONTAL);
    }
    cs1010_println_string(TOP_RIGHT);
    // print the center lines.
    for (int i = 0; i < length - 2; i++) {
        cs1010_print_string(VERTICAL);
        for (int n = 0; n< width - 2; n++ ) {
            cs1010_print_string(" ");
        }
        cs1010_println_string(VERTICAL);
    }
    // print the last line.
    cs1010_print_string(BOTTOM_LEFT);
    for (int i = 0; i < width - 2; i++ ) {
        cs1010_print_string(HORIZONTAL);
    }
    cs1010_print_string(BOTTOM_RIGHT);

}
