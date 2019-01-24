/**
 * CS1010 Semester 1 AY18/19
 * Assignment 2: Weekday
 *
 * @file: weekday.c
 * @author: YANG CHENGLONG (Group 01)
 */

#include <stdbool.h>
#include "cs1010.h"

bool is_leap_year(long year);
long calc_days(long year, long month, long day);

int main() {
    long year = cs1010_read_long();
    long month = cs1010_read_long();
    long day = cs1010_read_long();
    char *days[] = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };
    long total_days = calc_days(year, month, day);
    long remainder = total_days % 7;
    cs1010_print_string(days[remainder]);
}

// This function will determine whether the given year is a leap year.
bool is_leap_year(long year) {
    if ((year % 400 == 0) || ((year % 4) == 0 && (year % 100) != 0)) {
        return true;
    } else {
        return false;
    }
}

// This function will calculate the number of days
// from the given date to 01/01/1900
long calc_days(long year, long month, long day) {
    long days_of_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    long days = 0;
    for (long init_year = 1900; init_year < year; init_year += 1) {
        days += (is_leap_year(init_year) ? 366 : 365);
    }
    for (long init_month = 0; init_month < month; init_month += 1) {
        days += days_of_month[init_month];
    }
    if (month > 2 && is_leap_year(year)) {
        days += 1;
    }
    days += (day - 1);
    return days;
}
