/**
 * CS1010 Semester 1 AY18/19
 * Assignment 6: Permutation 3
 *
 * This programme determines whether a string S1
 * is the permutation of the substring of a string S2.
 * There is an alternative implementation named permutation4.c
 * which is seemingly a bit less efficient but much more intuitive.
 * Though algorithms are similar, and both should be O(k+n).
 * More interestingly, permutation4.c is actually a bit faster than
 * permutation3.c when gauging time using 'time'.
 *
 * @file: permutation3.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <string.h>
#include <stdlib.h>

long fsort(char *string, long *letter_frequency, long length);

int main() {
    char *string1 = cs1010_read_word();
    char *string2 = cs1010_read_word();
    long string1_length = strlen(string1);
    long string2_length = strlen(string2);

    /**
     * letter_frequency is an array whose value is the
     * frequency of index as letter appears in string.
     */
    long *letter_frequency = calloc(26, sizeof(long));
    if (letter_frequency == NULL) {
        cs1010_println_string("Not enough memeroy");
        return 0;
    }

    /**
     * distance is the deviation in letters to be traced down,
     * regardless of duplicate, from string1 to string2.
     * Initially, it is just the number of different letters in string1.
     */
    long distance = fsort(string1, letter_frequency, string1_length);

    /**
     * Traced down string2 by restricting a WINDOW of string2
     * with the same length as string1, when distance becomes 0,
     * it means no deviation in letters from string1 to that WINDOW.
     * Which means string1 is a permutation of that WINDOW, which is
     * a substring of string2.
     */
    for (long i = 0; i < string2_length; i += 1) {
        // if never appears before.
        if (*(letter_frequency + (*(string2 + i) - 'a')) == 0) {
            distance += 1;
        // if the same letter appears in WINDOW.
        } else if (*(letter_frequency + (*(string2 + i) - 'a')) == 1) {
            distance -= 1;
        }
        // Cancel out the letter frequency from string1.
        *(letter_frequency + (*(string2 + i) - 'a')) -= 1;

        // update letter_frequency as WINDOWS goes down string2.
        if (i >= string1_length) {
            /**
             * if the letter before the WINDOW appears in string1, and distance
             * get deducted when the letter is in the WINDOW, need to add back,
             * because that letter is no longer in the WINDOW.
             */
            if (*(letter_frequency + (*(string2 + i - string1_length) - 'a')) == 0) {
                distance += 1;
            /**
             * if the letter before the WINDOW never appears in string1, and distance
             * get added when the letter is in the WINDOW, need to subtract back,
             * because that letter is no longer in the WINDOW.
             */
            } else if (*(letter_frequency + (*(string2 + i - string1_length) - 'a')) == -1) {
                distance -= 1;
            }
            // get rid of letters before WINDOW as WINDOW goes down string2.
            *(letter_frequency + (*(string2 + i - string1_length) - 'a')) += 1;
        }

        if (distance == 0) {
            cs1010_println_string("YES");
            free(letter_frequency);
            return 0;
        }
    }

    cs1010_println_string("NO");
    free(letter_frequency);
}

/**
 * @brief This function will sort the string into to an array
 * whose value is the frequency of index as letter appears in the string.
 * eg, the first value of the array is the frequency of 'a' appears in
 * the string, and the last value of the array is the frequency of 'z'
 * appears in the string. This function will also return the number of
 * different letters in the string.
 *
 * @param[in] string The string to be sorted.
 * @param[in] length The length of the string.
 *
 * @param[in,out] letter_frequency The array whose value
 * is the frequency of index as letter appears in the string.
 *
 * @return distance Number of different letters in the string.
 */
long fsort(char *string, long *letter_frequency, long length) {
    long distance = 0;
    for (long i = 0; i < length; i += 1) {
        // if never appears before.
        if(*(letter_frequency + (string[i] - 'a')) == 0) {
            distance += 1;
        }
        // update letter_frequency.
        *(letter_frequency + (string[i] - 'a')) += 1;
    }
    return distance;
}
