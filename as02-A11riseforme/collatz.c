/**
 * CS1010 Semester 1 AY18/19
 * Assignment 2: Collatz
 *
 * @file: collatz.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"

long collatz_step(long num);

int main() {
    long num = cs1010_read_long();
    long longest_steps = 0;
    long num_with_largest_steps = 1;
    for (long k = 2; k <= num; k += 1) {
        long current_steps = collatz_step(k);
        if (current_steps >= longest_steps) {
            num_with_largest_steps = k;
            longest_steps = current_steps;
        }
    }
    cs1010_println_long(num_with_largest_steps);
    cs1010_print_long(longest_steps);
}

// This function finds the least steps taken by collatz process
// for the given number to reach 1
long collatz_step(long num) {
    long steps = 0;
    for (long i = 0; num != 1; i += 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        steps += 1;
    }
    return steps;
}
