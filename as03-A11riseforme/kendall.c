/**
 * CS1010 Semester 1 AY18/19
 * Assignment 3: Kendall
 *
 * Read in a positive integer n and a permutation of numbers 
 * 1..n.  Print the normalized Kendall tau distance.
 *
 * @file: kendall.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"

int main() {
    long len = cs1010_read_long();
    long *rank = cs1010_read_long_array(len);
    long count = 0;

    // count the number of pairs where the left element
    // is greater than the right element.
    for (long i = 0; i < len - 1; i += 1) {
        for (long l = i + 1; l < len; l += 1 ) {
            if (rank[i] > rank[l]) {
                count += 1;
            }
        }
    }

    // number of possible pairs in the rank.
    long combination = len * (len - 1) / 2;
    double kendall_tau_distance = (double)count / combination;
    cs1010_print_double(kendall_tau_distance);
}
