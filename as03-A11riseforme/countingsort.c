/**
 * CS1010 Semester 1 AY18/19
 * Assignment 3: CountingSort
 *
 * Read in a positive integer n and a max value k, followed by
 * a list of n numbers between 1 to k.  Print the numbers in
 * increasing order.
 *
 * @file: countingsort.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"

int main() {
    long num = cs1010_read_long();
    long max = cs1010_read_long();
    long *list = cs1010_read_long_array(num);

    // frequences is an array whose index is the value of element in list,
    // and value is the number of times its index appears in list.
    long frequences[max + 1];
    
    // initialize the frequences array.
    for (long i = 0; i < max + 1; i += 1) {
        frequences[i] = 0;
    }

    for (long i = 0; i < num; i += 1) {
        // input validation, make sure the numbers which are 
        // less than 1 or greater than the max in the list will be omitted.
        if ((list[i] <= max) && (list[i] >= 1)) {
            frequences[list[i]] += 1;
        }
    }

    for (long i = 1; i < max + 1; i += 1) {
        if (frequences[i] != 0) {
            for (long j = 0; j < frequences[i]; j += 1) {
                cs1010_println_long(i);
            }
        }
    }
}
