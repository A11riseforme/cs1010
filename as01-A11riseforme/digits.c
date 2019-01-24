/**
 * CS1010 Semester 1 AY18/19
 * Assignment 1: Digits
 * Read an integer from the standard input and print 
 * the sum of the digits to the standard output.
 * @file: digits.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"

long sum_of_digits(long input);

int main()
{
    long input = cs1010_read_long();
    cs1010_println_long(sum_of_digits(input));
}

// This function calculates the sum of the digits of the number.
long sum_of_digits(long input) {
    if (input < 10) {
        return input;
    }
    else {
        return (input % 10) + sum_of_digits(input / 10);
    }
}


