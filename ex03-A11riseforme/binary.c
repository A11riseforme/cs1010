/**
 * CS1010 Semester 1 AY18/19
 * Exercise 3: Binary
 *
 * Read a number containing only digits 0 and 1, interpret 
 * it as a binary number, and print the corresponding decimal
 * number to the standard output.
 *
 * @file: binary.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <math.h>

long bin_to_dec(long bin_num);

long length_of_bin(long bin_num);

int main() {
    long bin_num = cs1010_read_long();
    long dec_num = bin_to_dec(bin_num);
    cs1010_print_long(dec_num);
}

//This function gets the length of the binary number.
long length_of_bin(long bin_num) { 
    int count = 0;
    while (bin_num != 0) {
        bin_num /= 10;
        count++;
    }
    return count;
}

//This function converts binary number to decimal number
long bin_to_dec(long bin_num) { 
    int length = length_of_bin(bin_num);
    long dec_num = 0;
    for (int i = 0; i < length; i++) {
        int last_digit = bin_num % 10;
        dec_num += last_digit * pow(2, i);
        bin_num /= 10;
    }
    return dec_num;
}
