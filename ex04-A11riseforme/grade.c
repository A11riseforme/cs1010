/**
 * CS1010 Semester 1 AY18/19
 * Exercise 4: Grade
 *
 * TODO(by student) Describe what this program does.
 *
 * @file: grade.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <stdbool.h>

int main() {
    long marks_range[] = {100, 100, 99, 99, 98, 98, 97, 96, 95, 91, 90, 86, 85, 81, 80, 71, 70, 61, 60, 51, 50, 0};
    char *letter_grade[] = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "D+", "D", "F"};
    long mark = cs1010_read_long();
    for (long i = 0; i < 22; i += 2) {
        if ((marks_range[i + 1] <= mark) && (mark <= marks_range[i])) {
            cs1010_print_string(letter_grade[i / 2]);
            break;
        }
    }
}
