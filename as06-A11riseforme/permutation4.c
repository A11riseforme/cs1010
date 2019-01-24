/**
 * CS1010 Semester 1 AY18/19
 * Assignment 4: Permutation 3
 *
 * This programme is an alternative implementation of
 * permutation3.c, running on similar algorithm,
 * seemingly less efficient but more intuitive.
 * But when gauging time with 'time', it is actually faster. 
 *
 * @file: permutation4.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void fsort(char *string, long *string_frequency, long length);
bool is_same_frequency(long *string1_frequency, long *string2_frequency, long length);

int main() {
    char *string1 = cs1010_read_word();
    char *string2 = cs1010_read_word();
    long string1_length = strlen(string1);
    long string2_length = strlen(string2);

    long *string1_frequency = calloc(26, sizeof(long));
    if (string1_frequency == NULL) {
        cs1010_println_string("Not enough memeroy");
        return 0; 
    }
 
    long *string2_frequency = calloc(26, sizeof(long));
    if (string2_frequency == NULL) {
        cs1010_println_string("Not enough memory");
        return 0;
    }

    fsort(string1, string1_frequency, string1_length);
    fsort(string2, string2_frequency, string1_length);

    /**
     * Restrict a WINDOW of string2 with same length as string1,
     * Move along the string2, see if the the WINDOW of the string2
     * is the permutation of string1, if not, move one char to the right,
     * update the string2_frequency and compare again.
     * For string1 of length n and string2 of length m, need to compare n-m+1 times.
     */
    for (int i = 0; i <= string2_length - string1_length; i += 1) {
        if (is_same_frequency(string1_frequency, string2_frequency, 26)) {
            cs1010_println_string("YES");
            return 0;
        }
        /**
         * Update the string2_frequency by reduce the frequency of the first char of 
         * the WINDOWS of the string2, and add on the next char of the current
         * WINDOW of the string2.
         */ 
        *(string2_frequency + (*(string2 + i ) - 'a')) -= 1;
        *(string2_frequency + (*(string2 + i + string1_length) - 'a')) += 1;
    }
    cs1010_println_string("NO");
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

