/**
 * CS1010 Semester 1 AY18/19
 * Assignment 6: Permutation 2
 * 
 * This programme determines whether a string S1 is 
 * the permutation of another string S2.
 *
 * @file: permutation2.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool is_same_frequency(long *string1_frequency, long *string2_frequency, long length);
void fsort(char *string, long *string_frequency, long length);

int main() {
    char *string1 = cs1010_read_word();
    char *string2 = cs1010_read_word();
    long length = strlen(string1);

    // we need a array with length of 26 to store freqency of letters.
    long *string1_frequency = calloc(26, sizeof(long));
    if (string1_frequency == NULL) {
        cs1010_println_string("Not enough memory");
        return 0;
    }

    long *string2_frequency = calloc(26, sizeof(long));
    if (string2_frequency == NULL) {
        cs1010_println_string("Not enought memory");
        return 0;
    }

    fsort(string1, string1_frequency, length);
    fsort(string2, string2_frequency, length);
    free(string2);
    free(string1);

    if (is_same_frequency(string1_frequency, string2_frequency, 26)) {
        cs1010_println_string("YES");
    } else {
        cs1010_println_string("NO");
    }
    free(string1_frequency);
    free(string2_frequency);
}

/**
 * @brief This function will determin whether the arrays of frequency of two 
 * strings are the same, if the same, then the combination of letters in these two 
 * string is the same.
 *
 * @param[in] string1_frequency The array of frequency of the string1.
 * @param[in] string2_frequency The array of frequency of the string2.
 * @param[in] length The length of the string.
 *
 * @return true if two arrays of frequency are the same, return false otherwise.
 */
bool is_same_frequency(long *string1_frequency, long * string2_frequency, long length) {
    if (memcmp(string1_frequency, string2_frequency, length * sizeof(long)) == 0) {
        return true;
    }
    return false;
}

/**
 * @brief This function will sort the string into to an array of 
 * frequency, where the value of the first element is the frequency
 * of 'a' in the string, and the value of the last element is the
 * frequency of 'z' in the string.
 *
 * @param[in] string The string to be sorted.k
 * @param[in] length The length of the string.
 *
 * @param[in,out] string_frequency The array of frequency of the string.
 */
void fsort(char *string, long *string_frequency, long length) {
    for (long i = 0; i < length; i += 1) {
        *(string_frequency + (*(string + i) - 'a')) += 1;
    }
}

