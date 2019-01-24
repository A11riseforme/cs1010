/**
 * CS1010 Semester 1 AY18/19
 * Assignment 6: Permutation 1
 *
 * This programme determines whether a list L2 is
 * the permutation of another list L1.
 *
 * @file: permutation1.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <stdlib.h>
#include <stdbool.h>

long *find_max_and_min(long *list, long num);
void fsort(long *list, long *list_frequency, long num, long min);
bool is_same_frequency(long *list1_frequency, long *list2_frequency, long num);

int main() {
    long num = cs1010_read_long();
    long *list1 = cs1010_read_long_array(num);
    long *list2 = cs1010_read_long_array(num);

    long *list1_max_and_min = find_max_and_min(list1, num);
    if (list1_max_and_min == NULL) {
        return 0;
    }
    
    long *list2_max_and_min = find_max_and_min(list2, num);
    if (list2_max_and_min == NULL) {
        return 0;
    }

    long list1_max = *list1_max_and_min;
    long list1_min = *(list1_max_and_min + 1);
    free(list1_max_and_min);

    long list2_max = *list2_max_and_min;
    long list2_min = *(list2_max_and_min + 1);
    free(list2_max_and_min);

    // if their max or min are not equal, then not the same permutation.
    if (list1_max != list2_max || list1_min != list2_min) {
        cs1010_println_string("NO");
        free(list1);
        free(list2);
        return 0;
    }

    long list_range = list1_max - list1_min + 1;

    long *list1_frequency = calloc(list_range, sizeof(long));
    if (list1_frequency == NULL) {
        cs1010_println_string("Not enough memory");
        return 0;
    }

    long *list2_frequency = calloc(list_range, sizeof(long));
    if (list2_frequency == NULL) {
        cs1010_println_string("Not enough memory");
        return 0;
    }

    fsort(list1, list1_frequency, num, list1_min);
    fsort(list2, list2_frequency, num, list2_min);
    free(list1);
    free(list2);

    if (is_same_frequency(list1_frequency, list2_frequency, list_range)) {
        cs1010_println_string("YES");
    } else {
        cs1010_println_string("NO");
    }

    free(list1_frequency);
    free(list2_frequency);
}

/**
 * @brief This function will find the maximum and minimum
 * element of the number list.
 *
 * @param[in] list The number list to be find the min and max.
 * @param[in] num The number of elements of the list.
 *
 * @return the array of two numbers. The first number is the maximum
 * element and the second is the minimum element in the list. The caller
 * is responsible for freeing the memory allocated to the array.
 * Return NULL if error occured.
 */
long *find_max_and_min(long *list, long num) {
    long max = *list;
    long min = *list;

    long *max_and_min = calloc(2, sizeof(long));
    if (max_and_min == NULL) {
        cs1010_println_string("Not enough memory");
        return NULL;
    }

    for (long i = 1; i < num; i += 1) {
        max = (*(list + i) > max ? *(list + i) : max);
        min = (*(list + i) < min ? *(list + i) : min);
    }

    *max_and_min = max;
    *(max_and_min + 1) = min;

    return max_and_min;
}

/**
 * @brief This function will sort the number list into an array
 * of frequency, where the value of the first element is the frequency
 * of the minimum number of the number list. and the value of the last
 * element is the frequency of the maximum number of the number list.
 * Just like the algorithm of countingsort.
 *
 * @param[in] list The number list to be sorted.
 * @param[in] num The number of elements in the number list.
 * @param[in] min The minimum number in the number list.
 *
 * @param[in,out] list_frequency The array of frequency of the number list.
 */
void fsort(long *list, long *list_frequency, long num, long min) {
    for (long i = 0; i < num; i += 1) {
        *(list_frequency + *(list + i) - min) += 1;
    }
}

/**
 * @brief This function will determin whether the arrays of frequency of two
 * number lists are the same, if the same, then the combination of these two
 * number list is the same.
 *
 * @param[in] list1_frequency The array of frequency of the list1.
 * @param[in] list2_frequency The array of frequency of the list2.
 * @param[in] num The number of elements in the number list.
 *
 * @return true if two arrays of frequency are the same, return false otherwise.
 */
bool is_same_frequency(long *list1_frequency, long *list2_frequency, long num) {
    if (memcmp(list1_frequency, list2_frequency, num * sizeof(long)) == 0) {
        return true;
    }
    return false;
}
