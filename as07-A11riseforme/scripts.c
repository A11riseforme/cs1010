/**
 * CS1010 Semester 1 AY18/19
 * Assignment 7: Scripts
 *
 * This program sort an array with increasing order first
 * followed by decreasing order into increasing order throughout
 * the whole array in time complexity of O(n).
 *
 * @file: scripts.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <stdlib.h>

#define PRINT_ARR(type, arr, num) {\
    for (type i = 0; i < num; i += 1) {\
        cs1010_print_##type(*(arr + i));\
        cs1010_print_string(" ");\
    }\
    cs1010_print_string("\n");\
}

void bisort(long *ids, long *sorted_ids, long num);

int main() {
    long num = cs1010_read_long();
    long *ids = cs1010_read_long_array(num);

    long *sorted_ids = calloc(num, sizeof(long));
    if (sorted_ids == NULL) {
        cs1010_println_string("Not enough memory");
        return 0;
    }

    bisort(ids, sorted_ids, num);

    PRINT_ARR(long, sorted_ids, num);

    free(sorted_ids);
    free(ids);
}

/**
 * This function will sort an array of numbers which ascend then descend.
 * By placing two pointers, one at the front, and one at the back,
 * compare the elements two pointers pointing at, push the smaller one into
 * the sorted_ids array, and the corresponding pointer move towards the other one,
 * all the way until two pointers meet.
 *
 * @param[in] ids The array of ids in terms of numbers.
 * @param[in] num The number of numbers in the ids array.
 * @param[out] sorted_ids The array of sorted ids.
 */
void bisort(long *ids, long *sorted_ids, long num) {
    long i = 0;
    long j = num - 1;
    long count = 0;
    while (i <= j) {
        if (*(ids + i) < *(ids + j)) {
            *(sorted_ids + count) = *(ids + i); 
            count += 1;
            i += 1;
        } else {
            *(sorted_ids + count) = *(ids + j);
            count += 1;
            j -= 1;
        }
    }
}

