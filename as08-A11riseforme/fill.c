/**
 * CS1010 Semester 1 AY18/19
 * Assignment 8: Fill
 *
 * This programme helps Scully to repaint the drawing according to
 * the teacher's instruction.
 *
 * @file: fill.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define CHECK_ALLOC(OBJ)\
    do {\
        if (OBJ == NULL) {\
            cs1010_println_string("Memory Allocation Error");\
            return 0;\
        }\
    } while (0)\

void paint_unit(char **paint, long x, long y, char colour); 
void paint_region(char **paint, long x, long y, char original_colour, char colour, long height, long width);
void paint_drawing(char **paint, long **colours, long num, long height, long width);
bool is_same_colour(char **paint, long x, long y, char colour, long height, long width);

int main() {
    long height = cs1010_read_long();
    long width = cs1010_read_long();

    char **paint = cs1010_read_line_array(height);
    CHECK_ALLOC(paint);

    long num = cs1010_read_long();
    long **colours = calloc(num, sizeof(long *));
    CHECK_ALLOC(colours);
    for (long i = 0; i < num; i += 1) {
        *(colours + i) = cs1010_read_long_array(3);
        CHECK_ALLOC(*(colours + i));
    }

    paint_drawing(paint, colours, num, height, width);

    for (long i = 0; i < height; i += 1) {
        cs1010_print_string(*(paint + i));
    }

    for (long i = 0; i < height; i += 1) {
        free(*(paint + i));
    }
    free(paint);

    for (long i = 0; i < num; i += 1) {
        free(*(colours + i));
    }
    free(colours);    
}


/**
 * @brief This function will paint the unit at (x,y) to the specific colour.
 *
 * @param[out] paint The array storing Scully's drawing.
 * @param[in] x The x coordinate of the unit.
 * @param[in] y The y coordinate of the unit.
 * @param[in] colour The specific colour to be painted to.
 */
void paint_unit(char **paint, long x, long y, char colour) {
    *(*(paint + x) + y) = colour;
}


/**
 * @brief This function will paint the region where the unit (x,y) is at to the specific colour.
 * First to paint the the unit at (x,y) to the specific colour, then by checking its 
 * surrounding units' colour against the original colour to decide whether to paint those units
 * to the specific colour too.
 *
 * @param[in,out] paint The array storing Scully's drawing.
 * @param[in] x The x coordinate of the unit.
 * @param[in] y The y coordinate of the unit.
 * @param[in] original_colour The original colour of the unit.
 * @param[in] colour The target colour of the unit to be painted to.
 * @param[in] height The height of the Scully's drawing.
 * @param[in] width The width of the Scully's drawing.
 */
void paint_region(char **paint, long x, long y, char original_colour, char colour, long height, long width) {
    paint_unit(paint, x, y, colour);
    
    if (is_same_colour(paint, x - 1, y, original_colour, height, width)) {
        paint_region(paint, x - 1, y, original_colour, colour, height, width);
    }
    if (is_same_colour(paint, x, y + 1, original_colour, height, width)) {
        paint_region(paint, x, y + 1, original_colour, colour, height, width);
    }
    if (is_same_colour(paint, x + 1, y, original_colour, height, width)) {
        paint_region(paint, x + 1, y, original_colour, colour, height, width);
    }
    if (is_same_colour(paint, x, y - 1, original_colour, height, width)) {
        paint_region(paint, x, y - 1, original_colour, colour, height, width);
    } 
}


/**
 * @brief This function will paint Scully's drawing by iterating through the colours array.
 *
 * @param[in,out] paint The array storing Scully's drawing.
 * @param[in] colours The array storing the teacher's intruction on colour and coordinates.
 * @param[in] num The number of different region to be repainted.
 * @param[in] height The height of the Scully's drawing.
 * @param[in] width The width of the Scully's drawing.
 */
void paint_drawing(char **paint, long **colours, long num, long height, long width) {
    for (long i = 0; i < num; i += 1) {
        long x = *(*(colours + i) + 0);
        long y = *(*(colours + i) + 1);
        char colour = *(*(colours + i) + 2) + '0';
        char original_colour = *(*(paint + x) + y);
        if (colour != original_colour) {
            paint_region(paint, x, y, original_colour, colour, height, width);
        }
    }
}


/**
 * @brief This function will decide whether a specific unit is of the specific colour.
 *
 * @param[in] paint The array storing Scully's drawing.
 * @param[in] x The x coordinate of the unit.
 * @param[in] y The y coordinate of the unit.
 * @param[in] colour The target colour to compare against.
 * @param[in] height The height of the Scully's drawing.
 * @param[in] width The width of the Scully's drawing.
 *
 * @return Return true if the specific unit is the of the specific colour, return false otherwise.
 */
bool is_same_colour(char **paint, long x, long y, char colour, long height, long width) {
    if ((x < 0) || (x >= height) || (y < 0) || (y >= width)) {
        return false;
    }
    if (*(*(paint + x) + y) == colour) {
        return true;
    }
    return false;
}

