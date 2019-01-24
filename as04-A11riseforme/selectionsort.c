/**
 * CS1010 Semester 1 AY18/19
 * Assignment 4: SelectionSort
 *
 * @file: selectionsort.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <stdlib.h>

void print_array(long nums[], long length);
void swap(long nums[], long i, long j);

int main() {
    // length is the number of numbers to be sorted
    long length = cs1010_read_long();
    // nums is the array containing numbers to be sorted
    long *nums = cs1010_read_long_array(length);
    // assign length to a new variable len
    // because later we are going to manipulate length.
    long len = length;
    /**
     * After checking from the first to the last
     * the maximum is at the last position,
     * then we are checking from the first to the second last,
     * so length -= 1, and it goes on.
     * for n numbers, we need to check n-1 times, so set i = 1.
     */
    for (long i = 1; i < length; length -= 1) {
        // last is the index of the last number to be checked
        long last = length - i;
        // assume that the last number is the maximum number
        long max = last;
        for (long j = 0; j < last; j += 1) {
            if (nums[max] < nums[j]) {
                max = j;
            }
        }
        swap(nums,last,max);
        print_array(nums, len);
        cs1010_print_string("\n");
    }
    free(nums);
}

/**
 * @brief Print out all the numbers in an array, seperated by a space.
 *
 * @param[in] nums[] The array to be printed.
 * @param[in] length Number of elements in nums.
 *
 * @return Print out all the numbers in nums, seperated by a space.
 */
void print_array(long nums[], long length) {
    for (long i = 0; i < length; i += 1) {
        cs1010_print_long(nums[i]);
        cs1010_print_string(" ");
    }
}

/**
 * @brief Swap the element in position of i and j.
 *
 * @param[in] num[] The array to be manipulated.
 * @param[in] i position of the element to be swapped.
 * @param[in] j position of the element to be swapped.
 *
 * @return Swap the element of nums[] in position of i and j.
 */
void swap(long nums[], long i, long j) {
    long temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}
