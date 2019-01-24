/**
 * Read in a year and prints out if the input year is a leap year.
 * @file: suffix.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"

void  print_with_suffix(long n) {
    if (n % 10 == 1 && n % 100 != 11) {
        cs1010_print_long(n);
        cs1010_print_string("st");
    } else if (n % 10 == 2 && n % 100 != 12) {
        cs1010_print_long(n);
        cs1010_print_string("nd");
    } else if (n % 10 == 3 && n % 100 != 13) {
        cs1010_print_long(n);
        cs1010_print_string("rd");
    } else {
        cs1010_print_long(n);
        cs1010_print_string("th");
    }
}

int main() {
    long num = cs1010_read_long();
    print_with_suffix(num);
}
