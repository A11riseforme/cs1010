/**
 * CS1010 Semester 1 AY18/19
 * Assignment 2: Pattern
 *
 * @file: pattern.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include <stdbool.h>
#include <math.h>
#include "cs1010.h"

bool contains_prime_or_one(long start_num, long increment, long interval);
bool is_prime(long num);
void print_space(long row, long height);
void print_triangle_row(long row, long interval);

int main() {
    long interval = cs1010_read_long();
    long height = cs1010_read_long();
    for (int row = 1; row < height + 1; row += 1) {
        print_space(row, height);
        print_triangle_row(row, interval);
        print_space(row, height);
        cs1010_print_string("\n");
    }
}

// This function will determine
// whether the given number is a prime number.
// prime number after 3 can all be written in the form of
// 6n-1 or 6n+5 where n is a positive integer
bool is_prime(long num) {
    if (num == 1) {
        return false;
    }
    // testing if num is the only even prime number.
    if (num == 2 || num == 3) {
        return true;
    }
    // if num is not in the form of 6n+1 or 6n+5, then it is not prime.
    // because 6n+2=2*(3n+1); 6n+3=3*(2n+1); 6n+4=2*(3n+2)
    if ((num % 6 != 1) && (num % 6 != 5)) {
        return false;
    }
    // even if the num is in the form of 6n+1 or 6n+5, it may not be prime.
    // then we test for all possible-prime factor in the form of 6i+1 and 6i+5.
    for (long i = 5; i <= sqrt(num); i += 6) {
        if ((num % i == 0) || (num % (i + 2) == 0)) {
            return false;
        }
    }
    return true;
}

// This function will determine
// whether a specific cell contains oen or any prime number.
bool contains_prime_or_one(long start_num, long increment, long interval) {
    long end_num = start_num + increment * (interval - 1);
    while (start_num <= end_num) {
        if (is_prime(start_num) || start_num == 1) {
            return true;
        }
        start_num += increment;
    }
    return false;
}

// This function will determine how many spaces should be printed
// before and after the triangle charaters at the given line.
void print_space(long row, long height) {
    for (long i = 1; i <= height - row; i += 1) {
        cs1010_print_string(" ");
    }
}

// This function will determine whether to print '#' or ' '
// for all cells in any specific line.
void print_triangle_row(long row, long interval) {
    long start_num = (((row - 1) * row) / 2) * interval + 1;
    for (long i = 1; i <= row * 2 - 1; i += 1, start_num += 1) {
        if (contains_prime_or_one(start_num, row, interval)) {
            cs1010_print_string("#");
        } else {
            cs1010_print_string(" ");
        }
    }
}
