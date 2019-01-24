/**
 * CS1010 Semester 1 AY18/19
 * Assignment 7: Peak
 *
 * This programme finds the 'peak' in a array if possible,
 * returns "no peak" if no peak exists in the array.
 *
 * @file: peak.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <stdbool.h>
#include <stdlib.h>

#define IS_ASC(x, y, z)\
    ((x < y && y <= z) ||\
    (x <= y && y < z))

#define IS_DESC(x, y, z)\
    ((x > y && y >= z) ||\
    (x >= y && y > z))

#define CONTAINS_PEAK(x, y, z) ((x < y) && (y > z))

bool contains_peak(long *elevations, long i, long j, long *peak);

int main() {
    long num = cs1010_read_long();
    long *elevations = cs1010_read_long_array(num);
    long peak_index;

    if (contains_peak(elevations, 0, num - 1, &peak_index)) {
        cs1010_println_long(peak_index);
    } else {
        cs1010_println_string("no peak");
    }
    free(elevations);
}

/**
 * This function determines whether the range of the array of elevations contains a peak.
 * And update the peak_index if contains a peak.
 * The function start to look from the middle three elevations, eg, a,b,c
 * If a < b > c, then b is the peak.
 * If a < b <= c or a <=b < c, then peak will be on the right side of b if exists.
 * If a > b >= c or a >= b > c, then peak will be on the left side of b if exists.
 * If a = b = c, then peak might be on either side of b if exists.
 *
 * @param[in] elevations The array of elevations.
 * @param[in] i The start of the array to be checked.
 * @param[in] j The end of the array to be checked.
 * @param[out] peak_index The index of peak to be updated if exists.
 *
 * @return true if contains peak, false otherwise.
 */
bool contains_peak(long *elevations, long i, long j, long *peak_index) {
    long middle = (i + j) / 2;
    // if i to j contains less than three elevations, no peak.
    if (j - i < 2) {
        return false;
    } else {
        long left = *(elevations + middle - 1);
        long mid = *(elevations + middle);
        long right = *(elevations + middle + 1);

        if (CONTAINS_PEAK(left, mid, right)) {
            *peak_index = middle;
            return true;
        } else if (IS_ASC(left, mid, right)) {
            return contains_peak(elevations, middle, j, peak_index);
        } else if (IS_DESC(left, mid, right)) {
            return contains_peak(elevations, i, middle, peak_index);
        } else {
            return (contains_peak(elevations, i, middle, peak_index) ||
                    contains_peak(elevations, middle, j, peak_index));
        }
    }
}
