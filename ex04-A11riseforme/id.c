/**
 * CS1010 Semester 1 AY18/19
 * Exercise 4: ID
 *
 * TODO(by student) Describe what this program does.
 *
 * @file: id.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"

long sum_of_digits(long number);

int main() {
    long number;
    scanf("%ld", &number);
    char *check_code[13]={"Y","X","W","U","R","N","M","L","J","H","E","A","B"};
    long sum = sum_of_digits(number);
    long remainder = sum % 13;
    cs1010_print_string(check_code[remainder]);
}

long sum_of_digits(long number) {
    long sum = 0;
    long remainder = 0;
    while (number != 0) {
        remainder = number % 10;
        sum += remainder;
        number /= 10;
    }
    return sum;
}

