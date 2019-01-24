/**
 * CS1010 Semester 1 AY18/19
 * Assignment 7: Inversion
 *
 * This programme find the total number of pairs of inversion in
 * an array with elements ascend then descend.
 *
 * @file: inversion.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <stdbool.h>
#include <stdlib.h>

void walk_through(long *ids, long num, long *inversions);

int main() {
    long num = cs1010_read_long();
    long *ids = cs1010_read_long_array(num);
    long inversions = 0;

    walk_through(ids, num, &inversions);

    cs1010_println_long(inversions);

    free(ids);
}

/**
 * This function will walk through an array of numbers which ascend then descend.
 * By placing two pointers, one at the front, and one at the back, compare the
 * numbers two pointers pointing at, and  update inversions based on previous
 * four different occations.
 * 1. previously the front pointer moves to the right, and now the front pointer number is
 * greater than the end pointer number, all the numbers on the right of
 * the end pointer is also less than the front pointer number, all should be added to
 * inversions, and then end pointer moves to the left.
 * 2. previously the front pointer moves to the right, and now the front pointer number is
 * still less than the end pointer number, all the numbers on the right of the end
 * pointer is less than the front pointer number, all these numbers should be added to
 * inversions, and then front pointer moves to the right.
 * 3. previously the end pointer moves to the left, and now the front pointer number is
 * still greater than the end pointer number, then end pointer number should be added to inversions,
 * and end pointer moves to the left.
 * 4. previously the end pointer moves to the left, and now the front pointer number is
 * less than the end pointer number, then inversions remains the same, and front pointer
 * moves to the right.
 * When two pointers meet,they are pointing to the maximum number of the array,
 * the numbers on the right of the pointer(exclusive) is is descending order,
 * any pair of two is inversion, so add nC2 to inversions.
 *
 * @param[in] ids The array of ids in terms of numbers.
 * @param[in] num The number of numbers in the ids array.
 * @param[out] inversions The number of inversed pair in ids.
 */
void walk_through(long *ids, long num, long *inversions) {
    long start = 0;
    long end = num - 1;
    long move_right = 0;
    long move_left = 0;
    while (end != start) {
        if (*(ids + start) > *(ids + end)) {
            // case 3
            if (move_left == 1) {
                *inversions += 1;
                end -= 1;
                move_right = 0;
                move_left = 1;
            // case 1
            } else {
                *inversions += (num - end);
                end -= 1;
                move_right = 0;
                move_left = 1;
            }
        } else {
            // case 2 
            if (move_right == 1) {
                *inversions += (num - end - 1);
                start += 1;
                move_right = 1;
                move_left = 0;
            // case 4
            } else {
                start += 1;
                move_right = 1;
                move_left = 0;
            }
        }
    }

    /**
     * If the last movement is the front pointer moves to the right,
     * all the numbers on the right of the front pointer is less than
     * the the front pointer number, all these numbers should be added
     * to the inversions.
     */
    if (move_right == 1) {
        *inversions += (num - end - 1);
    }

    // desc_num is the number of descending numbers on the right of the maximum number.
    long desc_num = num - end - 1;
    *inversions += desc_num * (desc_num - 1) / 2;
}

