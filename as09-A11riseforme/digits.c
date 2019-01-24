/**
 * CS1010 Semester 1 AY18/19
 * Assignment 9: Digits
 *
 * This programme recognize the digits in a character image of 28*28
 * by training with some training data provided.
 *
 * @file: digits.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <stdlib.h>

#define NCOLS 28
#define NROWS 28
#define K 5

#define INSERT(source, target, pos) {\
    for (long x = K - 1; x > pos; x -= 1) {\
        source[x] = source[x - 1];\
    }\
    source[pos] = target;\
    break;\
}

/**
 * a handwritten digit.
 */
struct digit_info {
    // value of the digit.
    long label;
    // character image of the digit.
    char **image;
};

/**
 * recognization result against one training data.
 */
struct recognization_result {
    // value of the digit.
    long label;
    // distance between testing data and training data.
    long distance;
};

typedef struct digit_info digit_t;
typedef struct recognization_result result_t;

void read_digit(digit_t *info, long number);
void process(digit_t *training_data, digit_t *testing_sample, long training_number, long testing_number);
long recognize(digit_t *training_data, digit_t testing_sample, long training_number);
long find_distance(digit_t training_data, digit_t testing_sample, result_t *results);
void insert(result_t *results, result_t result);
long decide_digit(result_t *results);
void free_struct_mem(digit_t *info, long number);

int main() {
    long training_number = cs1010_read_long();
    digit_t *training_data = calloc(training_number, sizeof(digit_t));
    read_digit(training_data, training_number);

    long testing_number = cs1010_read_long();
    digit_t *testing_sample = calloc(testing_number, sizeof(digit_t));
    read_digit(testing_sample, testing_number);

    process(training_data, testing_sample, training_number, testing_number);
 
    free_struct_mem(training_data, training_number);
    free_struct_mem(testing_sample, testing_number);
}


/**
 * @brief This function reads the data of training data or 
 *  testing sample into an array of info.
 *
 * @param[out] info Array of digit info, containing labels and character images.
 * @param[in] number Number of digits in info array.
 */
void read_digit(digit_t *info, long number) {
    for (long i = 0; i < number; i += 1) {
        (*(info + i)).label = cs1010_read_long();
        (*(info + i)).image = cs1010_read_word_array(NROWS);
    }
}


/**
 * @brief This function process testing data by training against training data.
 *  Keep a track on success hit, and print out the accuracy in the end. 
 *
 * @param[in] training_data Array of training_data.
 * @param[in] testing_sample Array of testing_sample.
 * @param[in] training_number Number of digits in training_data array.
 * @param[in] testing_number Number of digits in testing_sample array.
 */
void process(digit_t *training_data, digit_t *testing_sample, long training_number, long testing_number) {
    long count = 0;
    for (long i = 0; i < testing_number; i += 1) {
        long actual_value = testing_sample[i].label;
        long recognized_value = recognize(training_data, testing_sample[i], training_number);
        cs1010_print_long(actual_value);
        cs1010_print_string(" ");
        cs1010_println_long(recognized_value);
        count += (actual_value == recognized_value ? 1 : 0);
    }
    double accuracy = count * 100.0 / testing_number;
    cs1010_println_double(accuracy);
}


/**
 * @brief This function try to recognize a digit in testing sample by comparing with
 * data in training_data, and choose the most common digit amongst first K smallest distance. 
 *
 * @param[in] training_data Array of training_data.
 * @param[in] testing_sample One testing sample containing value and the character image of the digit.
 * @param[in] training_number Number of training_samples in training_data.
 *
 * @return Return the recognization result of the testing_sample against all the training_data.
 */
long recognize(digit_t *training_data, digit_t testing_sample, long training_number) {
    // possible max_distance between sample and training image.
    long max_distance = NROWS * NCOLS;
    // we only interested in first K smallest distance.
    // initialize all distance to max_distance to facilitate insertion of real results.
    result_t results[K] = {
        [0 ... K-1] = {
            .label = 0,
            .distance = max_distance,
        }
    };
    for (long i = 0; i < training_number; i += 1) {
        result_t tmp_result;
        tmp_result.label = training_data[i].label;
        tmp_result.distance = find_distance(training_data[i], testing_sample, results);
        // we only considering the most common digit amongst first K smallest distance.
        // only if the result with distance less or equal to the Kth small distance in results
        // is worthy to be inserted in.
        if (tmp_result.distance <= results[K - 1].distance) {
            insert(results, tmp_result);
        }
    }
    long digit = decide_digit(results);
    return digit;
}


/**
 * @brief This function finds the distance between a training image and a testing image by
 * counting different pixels in their image. Stop counting when difference is greater than the Kth
 * small distance in results, since it won't take into consideration when diciding the final digit.
 *
 * @param[in] training_data One training sample consisting of value and character image of the digit.
 * @param[in] testing_sample One testing sample consisting of value and character image of the digit.
 * @param[in] results The processed training sample results so far, consisting of value and distance.
 *
 * @return Return the distance between the training image and testing image.
 */
long find_distance(digit_t training_data, digit_t testing_sample, result_t *results) {
    long distance = 0;
    for (long i = 0; i < NROWS; i += 1) {
        for (long j = 0; j < NCOLS; j += 1) {
            if (training_data.image[i][j] != testing_sample.image[i][j]) {
                distance += 1;
                if (distance > results[K - 1].distance) {
                    return distance;
                }
            }
        }
    }
    return distance;
}


/**
 * @brief This function tries to insert a result with distance less or equal to the Kth
 * small distance in results into results.
 *
 * @param[in,out] results The processed training sample results so far, consisting of value and distance.
 * @param[in] result The result to be inserted into results.
 */
void insert(result_t *results, result_t result) {
    for (long i = 0; i < K; i += 1) {
        if (result.distance == results[i].distance) {
            // break tie by inserting the result in front of the one with same distance but greater value.
            if (results[i].label > result.label) {
                INSERT(results, result, i);
            // if the one with same distance is of different distance with behind one, then insert after that one.
            // eg. insert 3 into 1 2 2 4 5, 3 should be inserted between 2 and 4, not between 2 and 2.
            } else if (results[i].distance != results[i + 1].distance) {
                INSERT(results, result, i + 1);
            }
        // insert in front of the one with greater distance.
        } else if (results[i].distance > result.distance) {
            INSERT(results,result, i);
        }
    }
}


/**
 * @brief This function will decide the recognization result based on the results
 * by choosing the most common digit amongst first K smallest distance.
 *
 * @param[in] results The processed training sample results, consisting values and distance. 
 *
 * @return Return the most common digit amongst first K smallest distance, break tie
 * by choosing the smaller one.
 */
long decide_digit(result_t *results) {
    long freq[10] = {0};
    // counting sort
    for (long i = 0; i < K; i += 1) {
        freq[results[i].label] += 1;
    }

    long digit = 0;
    long max_freq = freq[0];
    for (long i = 1; i < 10; i += 1) {
        if (freq[i] > max_freq) {
            digit = i;
            max_freq = freq[i];
        }
    }
    return digit;
}


/**
 * @brief This function will free the memory occupied by the struct allocated on heap.
 *
 * @param[in,out] info Array of info, containing info of a handwritten digit.
 * @param[in] number Number of digits in info array.
 */
void free_struct_mem(digit_t *info, long number) {
    for (long i = 0; i < number; i += 1) {
        for (long j = 0; j < NROWS; j += 1) {
            free(info[i].image[j]);
        }
        free(info[i].image);
    }
    free(info);
}
