/**
 * CS1010 Semester 1 AY18/19
 * Exercise 3: Prime
 *
 * Read an integer n from standard input and print "prime" 
 * or "not prime" to the the standard output depending on 
 * whether n is a prime number or not.
 *
 * @file: prime.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <math.h>
#include <time.h>

int main() {
    long num = cs1010_read_long();
    //clock_t start, finish;
    //double duration;
    //start = clock();
    if (num == 1) {
        cs1010_print_string("not prime");
        return 0;
    }
    // testing if num is the only even prime number.
    if (num == 2 || num == 3) {
        cs1010_print_string("prime");
        return 0;
    }
    // if num is not in the form of 6n+1 or 6n+5, then it is not prime.
    // because 6n+2=2*(3n+1); 6n+3=3*(2n+1); 6n+4=2*(3n+2)
    if ((num % 6 != 1) && (num % 6 != 5)) { 
        cs1010_print_string("not prime");
        return 0;
    }
    // even if the num is in the form of 6n+1 or 6n+5, it may not be prime.
    // then we test for all possible-prime factor in the form of 6i+1 and 6n+5.
    for (long i = 5; i <= sqrt(num); i += 6) { 
        if (num % i == 0) {
            cs1010_print_string("not prime");
            return 0;
        }
        else if (num % (i + 2) == 0) {
            cs1010_print_string("not prime");
            return 0;
        }
    }
    cs1010_print_string("prime");
    //finish = clock();
    //duration = (double)(finish - start)/CLOCKS_PER_SEC;
    //printf("%f", duration);
}
