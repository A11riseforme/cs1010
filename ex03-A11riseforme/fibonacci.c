/**
 * CS1010 Semester 1 AY18/19
 * Exercise 3: Fibonacci
 *
 * Read an integer n from the standard input and print the nth 
 * fibonacci number to the standard output.
 *
 * @file: fibonacci.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <math.h>

long fibonacci(long n);

int main() {
    long n = cs1010_read_long();
    cs1010_print_long(fibonacci(n));
}

// This function calculates the nth term of fibonacci number.
long fibonacci(long n) {
    if (n == 1 || n == 2) {
        return 1;
    } else {
        long a = 1;
        long b = 1;
        long c;
        for (long i =3; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}

