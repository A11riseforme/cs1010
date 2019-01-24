/**
 * CS1010 Semester 1 AY18/19
 * Assignment 1: Box
 * Read the dimensions of a rectangular 3D box from
 * the standard input and print the surface area and
 * the length of the diagonal to the standard output.
 * @file: box.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include <math.h>
#include "cs1010.h"

int area_of_rectangle(long width, long height);
double hypotenuse_of(long width, long length, long height);

int main() {
    long width = cs1010_read_long();
    long length = cs1010_read_long();
    long height = cs1010_read_long();
    long surface_area = (area_of_rectangle(width, length) + area_of_rectangle(width, height) + area_of_rectangle(length, height))*2;
    double hypotenuse = hypotenuse_of(width, length, height);
    cs1010_print_long(surface_area);
    cs1010_print_string(" ");
    cs1010_print_double(hypotenuse);
}

// This function calculates the area of the rectangle
// with the given width and height.
int area_of_rectangle(long width, long height) {
    return width * height;
}

// This function calculates the length of diagonal
// of the box with the given width, height and length
double hypotenuse_of(long width, long length, long height) {
    return sqrt(0.0 + pow(width, 2) + pow(length, 2) + pow(height,2));
}


