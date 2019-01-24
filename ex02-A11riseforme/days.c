/**
 * Read in a month and a day and prints the number of days since the beginning of the year.
 * @file: days.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"

void print_suffix(long n) {
    if (n % 10 == 1 && n % 100 != 11) {
            cs1010_print_string("st");
    } else if (n % 10 == 2 && n % 100 != 12) {
                cs1010_print_string("nd");                          
    } else if (n % 10 == 3 && n % 100 != 13) {
        cs1010_print_string("rd");
        } else {
                cs1010_print_string("th");
        }
}

int main() {
    long days = 0;
    long month = cs1010_read_long();
    long day = cs1010_read_long();
    long days_of_month[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i = 0 ; i < month ; i++) {
        days += days_of_month[i];
    }
    days += day;
    cs1010_print_long(days);
    print_suffix(days);
    cs1010_print_string("\n");
}
