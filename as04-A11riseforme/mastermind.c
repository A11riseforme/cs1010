/**
 * CS1010 Semester 1 AY18/19
 * Assignment 4: Mastermind
 *
 * @file: mastermind.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <string.h>
#include <stdlib.h>

long* check(char guess[], char truth[]);

int main() {
    char *truth = cs1010_read_word();
    long *result; // a pointer pointing to the array consisting of two numbers.
    long a; // first number;
    long b; // second number;
    char *guess;
    do {
        //free(result);
        guess = cs1010_read_word();
        result = check(guess, truth);
        a = *result;
        b = *(result + 1);
        free(guess);
        free(result);
        cs1010_print_long(a);
        cs1010_print_string(" ");
        cs1010_println_long(b);
    // stopping condition is 4&&0, continuing condition is just the negation of 4&&0.
    } while (a != 4 || b != 0);
    free(truth);
}

/**
 * @brief Check the guessing against the correct answer.
 * count numbers of correct color and position first.
 * then count total correct colors regardless of position
 * once a char from guess is found in correct answer,
 * reset that char to '0' to avoid double counting.
 *
 * @param[in] guess[] The guessing from user's input.
 * @param[in] truth[] The correct answer.
 *
 * @return result[2] A array of 2, first number refers to 
 * the number of chars guessing appear in the correct position 
 * and correct color.
 * The second number refers to the number of chars guessing appear
 * in the correct color but wrong position.
 */
long* check(char guess[], char truth[]) {
    //static long result[2];
    long *result = calloc(2, sizeof(long));
    long c_and_p_count = 0;
    long appear_count = 0;
    
    for (long i = 0; i < 4; i += 1) {
        if (truth[i] == guess[i] ) {
            c_and_p_count += 1;
        }
    }
    
    for (long i = 0; i < 4; i += 1) {
        for (long j = 0; j < 4; j += 1) {
            if (guess[j] == truth[i]) {
                appear_count += 1;
                guess[j] = '0';
                break;
            }
        }
    }
    
    result[0] = c_and_p_count;
    result[1] = appear_count - c_and_p_count;
    return result;
}

