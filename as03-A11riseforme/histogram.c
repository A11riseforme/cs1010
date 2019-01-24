/**
 * CS1010 Semester 1 AY18/19
 * Assignment 3: Histogram
 *
 * Read in a positive integer n followed by n real numbers. 
 * Draw the histogram of the numbers on the stndard output.
 *
 * @file: histogram.c
 * @author: YANG CHENGLONG (Group 01)
 */

#include "cs1010.h"
#include <math.h>

#define NUM_OF_BUCKETS 10
#define MAX_SCORE 100
#define BLOCK "█"
#define HALF_BLOCK "▌"

void draw_histogram(double marks[], long num ) {
    char *axis_labels[NUM_OF_BUCKETS] = {
        "  0 - 10  ",
        " 10 - 20  ",
        " 20 - 30  ",
        " 30 - 40  ",
        " 40 - 50  ",
        " 50 - 60  ",
        " 60 - 70  ",
        " 70 - 80  ",
        " 80 - 90  ",
        " 90 - 100 ",
    };

    // store the marks divider, the last element set to MAX_SCORE+1 
    // since MAX_SCORE is included in the last range.
    long marks_range[NUM_OF_BUCKETS + 1] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, MAX_SCORE + 1};

    // store number of times where marks fall within respective range. 
    long frequences[NUM_OF_BUCKETS]= {0};
    
    // store scale of frequences in respective range.
    double length[NUM_OF_BUCKETS];

    for (long i = 0; i < NUM_OF_BUCKETS; i += 1) {
        for (long j = 0; j < num; j += 1) {
            if ((marks[j] >= marks_range[i])&&(marks[j] < marks_range[i+1])) {
                frequences[i] += 1;
            }
        }
    }

    for (long i = 0; i < NUM_OF_BUCKETS; i += 1) {
        length[i] = (double)frequences[i] / num * NUM_OF_BUCKETS;
    }
    
    cs1010_println_string("          ┴┴┴┴┴┴┴┴┴┴");

    for (long i = 0; i < NUM_OF_BUCKETS; i += 1) {
        cs1010_print_string(axis_labels[i]);
        long num_of_block = floor(length[i]);
        double remainder = length[i] - num_of_block;
        long num_of_half_block = ((remainder < 0.5) ? 1 : 0);
        for (long j = 1; j <= num_of_block; j += 1) {
            cs1010_print_string(BLOCK);
        }
        // check if the remainder is zero because scale is nicely integer.
        if ((num_of_half_block == 1) && (remainder - 0 > 1e-6)) {
            cs1010_print_string(HALF_BLOCK);
        } else if (num_of_half_block == 0) {
            cs1010_print_string(BLOCK);
        }
        cs1010_println_string("");
    }
}

int main() {
    long num = cs1010_read_long();
    double *marks = cs1010_read_double_array(num);
    draw_histogram(marks, num);
}
