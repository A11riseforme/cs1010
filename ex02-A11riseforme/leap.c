/**
 * Read in a year and prints out if the input year is a leap year.
 * @file: leap.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include <stdbool.h>
#include "cs1010.h"

bool is_leap_year(long year) {
    if((year%400==0)||((year%4)==0&&(year%100)!=0)) {
        return true;
    } else {
        return false;
    }
}

int main() {
    long year = cs1010_read_long();
    if (is_leap_year(year)) {
        cs1010_print_long(year);
        cs1010_print_string(" is a leap year\n");
    } else {
        cs1010_print_long(year);
        cs1010_print_string(" is not a leap year\n");
    }
}
