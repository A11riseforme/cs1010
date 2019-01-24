/**
 * CS1010 Semester 1 AY18/19
 * Exercise 4: Max
 *
 * TODO(by student) Describe what this program does.
 *
 * @file: max.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"

long max(const long list[], long start, long end);

int main() {
    long num = cs1010_read_long();
    long *list = cs1010_read_long_array(num);
    cs1010_print_long(max(list, 0, num - 1));
}

long max(const long list[], long start, long end) {
    if (start == end) {
        long maximum = list[start];
        return maximum;
    } else {
        long middle = (start + end) / 2;
        long leftMax = max(list, start, middle);
        long rightMax = max(list, middle+1, end);
        long maximum = (leftMax > rightMax ? leftMax : rightMax);
        return maximum;
    }
}

