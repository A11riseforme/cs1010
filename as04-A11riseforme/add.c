/**
 * CS1010 Semester 1 AY18/19
 * Assignment 4: Add
 *
 * @file: add.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <string.h>
#include <math.h>
#include <stdlib.h>

void add_num(char result[], char num1[], char num2[], long num1_length, long num2_length, long max);
void print_num(char result[]);

int main() {
    char *num1 = cs1010_read_word();
    char *num2 = cs1010_read_word();
    long num1_len = strlen(num1);
    long num2_len = strlen(num2);
    long max = (num1_len > num2_len) ? num1_len : num2_len;
    
    /**
     * result of the addition, the max POSSIBLE length of result
     * should be two char longer than the longest of the two numbers.
     * One is the end null char, the other is the start '1' or '0'.
     */
    char *result = calloc(max + 2, sizeof(char));
    
    // set the last char to null so as to terminate the string.
    result[max + 1] = '\0';

    add_num(result, num1, num2, num1_len, num2_len, max);
    print_num(result);
    free(num1);
    free(num2);
}

/**
 * @brief Perform 'char addition' from the end of two number string.
 * it will stop until any one number has reached to the start.
 * And the rest of the result comes from the rest of the longer number string.
 *
 * @param[in] result[] The array stores the final result, will be manipulated during operation.
 * @param[in] num1[] The number string to perform addition.
 * @param[in] num2[] The other number string to perform addition.
 * @param[in] num1_len The length of num1.
 * @param[in] num2_len The length of num2.
 * @param[in] max The max length of the two numbers.
 *
 * @param[out] result[] The addition result.
 */
void add_num(char result[], char num1[], char num2[], long num1_len, long num2_len, long max) {
    long i = num1_len - 1;
    long j = num2_len - 1;
    long diff = labs(num1_len - num2_len);
    long sum = 0;
    long tenth = 0;
    while (i >= 0 && j >= 0) {
        sum = ((num1[i] - '0') + (num2[j] - '0') + tenth) % 10 ;
        tenth =  ((num1[i] - '0') + (num2[j] - '0') + tenth) / 10;
        result[max] = sum + '0';
        max -= 1;
        i -= 1;
        j -= 1;
    }
    if (num1_len > num2_len) {
        for (long i = diff - 1; i >= 0; i -= 1) {
            sum = ((num1[i] - '0') + tenth) % 10 ;
            tenth = ((num1[i] - '0') + tenth) / 10 ;
            result[i + 1] = sum + '0';
        }
        result[0] = tenth + '0';
    } else {
        for (long i = diff - 1; i >= 0; i -= 1) {
            sum = ((num2[i] - '0') + tenth) % 10 ;
            tenth = ((num2[i] - '0') + tenth) / 10 ;
            result[i + 1] = sum + '0';
        }
        result[0] = tenth + '0';
    }
}

/**
 * @brief Print out the result number string.
 * if the first char is '0', start printing from the second char.
 *
 * @param[in] result[] The result number string to be printed.
 * @param[in] len The length of the result number string.
 */
void print_num(char result[]) {
    if (result[0] == '0') {
        cs1010_println_string(result + 1);
    } else {
        cs1010_println_string(result);
    }
}
