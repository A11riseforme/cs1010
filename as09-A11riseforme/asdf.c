/**
 * CS1010 Semester 1 AY18/19
 * Assignment 9: Digits
 *
 * This file contains a programme that recognize the digits in a set of 28 
 * by 28 images, using another input set as training data. The Complexity
 * is O(nm), n is the number of training data, m is the number of images to
 * be recognized.
 *
 * @file: digits.c
 * @author: Ye Guoquan (Group 01)
 */

#include "cs1010.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define NCOLS 28
#define NROWS 28
#define WHITE '.'
#define BLACK '#'
#define K 5
#define MAX_DIGIT 9

struct image_tag {
  long digit;
  char** image;
};
typedef struct image_tag image_t;

void read_data(image_t* array, long n);
void print(long n, image_t* samples_a, long m, image_t* test_a);
long train(image_t* test, image_t* samples_a, long n);
long get_distance(image_t* test, image_t* sample);
void get_smallest(long distance, long index, long* smallest, long* smallest_i);
void free_struct_array(image_t* array, long n);

int main(){
  // read in samples data
  long n_samples = cs1010_read_long();
  image_t* samples_a = malloc(n_samples * sizeof(*samples_a));
  read_data(samples_a, n_samples);

  // read in tests data
  long m_tests = cs1010_read_long();
  image_t* test_a = malloc(m_tests * sizeof(*test_a));
  read_data(test_a, m_tests);

  print(n_samples, samples_a, m_tests, test_a);

  free_struct_array(samples_a, n_samples);
  free_struct_array(test_a, m_tests);
  
  return 0;
}

/**
 * @brief This function reads in the input into a image_t array
 * @param[in] array The array of image_t
 * @param[in] n The number of elements in the array
 */
void read_data(image_t* array, long n) {
  for (long i = 0; i < n; i += 1) {
    array[i].digit = cs1010_read_long();
    array[i].image = cs1010_read_word_array(NROWS);
  }
}

/**
 * @brief This function prints out the output of comparing the
 * real number in the image and the recognition result from training.
 * Lastly it prints out the accuracy obtained
 *
 * @param[in] n The number of image_t object in samples_a
 * @param[in] samples_a The array of image_t objects as training samples
 * @param[in] m The number of image_t object in test_a
 * @param[in] test_a The array of image_t objects as tests cases
 */
void print(long n, image_t* samples_a, long m, image_t* test_a) {
  long correct = 0;
  long result;
  for (long i = 0; i < m; i += 1) {
    result = train(&test_a[i], samples_a, n);
    cs1010_print_long(test_a[i].digit);
    cs1010_print_string(" ");
    cs1010_println_long(result);
    if (result == test_a[i].digit) {
      correct += 1;
    }
  }
  double accuracy = correct * (100.0) / m;
  cs1010_println_double(accuracy);
}

/**
 * @brief This function test a image_t object against a set of training data,
 * and return the result of digit recognition obtained.
 *
 * @param[in] test The pointer to the image_t object to be tested
 * @param[in] samples_a The array of training data
 * @param[in] n The number of image_t object in samples_a
 * @return Return (long) the digit recognized by the training set
 */
long train(image_t* test, image_t* samples_a, long n) {
  // get a list of nearest neighbours
  long* smallest = malloc(K * sizeof(*smallest));
  memset(smallest, -1, K * sizeof(*smallest));
  long* smallest_i = malloc(K * sizeof(*smallest));
  long distance = 0;
  for (long i = 0; i < n; i += 1) {
    distance = get_distance(test, &samples_a[i]);
    get_smallest(distance, i, smallest, smallest_i);
  }

  // determine which in the nearest neighbours is the best
  long array[MAX_DIGIT + 1];
  memset(array, 0, sizeof(array));
  for (long i = 0; i < K; i += 1) {
    array[samples_a[smallest_i[i]].digit] += 1;
  }
  long result = 0;
  long max = 0;
  for (long i = 0; i < MAX_DIGIT + 1; i += 1) {
    if (array[i] > max) {
      max = array[i];
      result = i;
    }
  }
  free(smallest);
  free(smallest_i);
  return result;
}

/**
 * @brief This function calculates the distance(pixel difference) between two images
 * 
 * @param[in] test The pointer to the test image
 * @param[in] sample The pointer to the sample image
 * @return Return (long) the distance between two images
 */
long get_distance(image_t* test, image_t* sample) {
  long distance = 0;
  for (long i = 0; i < NROWS; i += 1) {
    for (long j = 0; j < NCOLS; j += 1) {
      if (test->image[i][j] != sample->image[i][j]) {
        distance += 1;
      }
    }
  }
  return distance;
}

/**
 * @brief This function determine if a certain distance (and its corresponding
 * index in the original array) should be put into an array containing the
 * smallest distance (and another for the index)
 *
 * @param[in] distance The distance between two images
 * @param[in] index The index indicating from which test data the distance is obtained
 * @param[in] smallest The array containing the smallest distance
 * @param[in] smallest_i The array containing the index from which the smallest
 * distance is obtained
 */
void get_smallest(long distance, long index, long* smallest, long* smallest_i) {
  long fathest = 0;
  long fathest_i = 0;

  // get the furthest distance in the array
  for (long i = 0; i < K; i += 1) {
    // since array was initialized to -1, -1 means no value input yet
    if (smallest[i] == -1) {
      smallest[i] = distance;
      smallest_i[i] = index;
      return;
    }
    // break-tie by taking the larger number as fathest
    if ((smallest[i] == fathest) && (smallest_i[i] > smallest_i[fathest_i])) {
      fathest_i = i;
    }
    if (smallest[i] > fathest) {
      fathest = smallest[i];
      fathest_i = i;
    }
  }
  if (distance < fathest) {
    smallest[fathest_i] = distance;
    smallest_i[fathest_i] = index;
  }
}

/**
 * @brief This function frees each element in the array of image_t as well as
 * the image in each image_t object
 *
 * @param[in] array The array of image_t objects to be freed
 * @param[in] n The number of image_t obejects in the array
 */
void free_struct_array(image_t* array, long n) {
  for (long i = 0; i < n; i += 1) {
    for (long j = 0; j < NROWS; j += 1) {
      free(array[i].image[j]);
    }
    free(array[i].image);
  }
  free(array);
}

