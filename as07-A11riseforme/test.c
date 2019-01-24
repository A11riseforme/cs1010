/**
 * CS1010 Semester 1 AY18/19
 * Assignment 7: Inversion
 *
 * This files contain the imeplementation that count the number of disordered
 * pair(inversion) in a partially ordered list where the first few increasing
 * and the last few decreasing. The method used is to compare the number in
 * front with the number from the back. Each time the number from the back is
 * smaller than number in front, the inversion pair + 1. Since the number
 * fron the back may cause multiple inversion, we add the (last_index - 
 * back_index) number of inversion when current back_index > front_index.
 * Lastly, the decreasing part cause k*(k-1)/2 number of inversion. We can
 * add them up to get total number of inversion. At worst case, each element
 * in the list run through 2 times. Complexity = 2n = O(n);
 *
 * @file: inversion.c
 * @author: Ye Guoquan (Group 01)
 */

#include "cs1010.h"
#include <stdlib.h>
#include <stdbool.h>

int main(){
  long n = cs1010_read_long();
  long* a = cs1010_read_long_array(n);

  long inver = 0;

  // i is the index of number from front, j is index from the back
  long i = 0;
  long j = n - 1;

  while (true) {
    if (a[j] < a[i]) {
      j -= 1;
    }
    else if (a[i] < a[j]) {
      // all the number from the back until j (exclusive) is smaller than a[i]
      inver += n - 1 - j;
      i += 1;
    }
    else {
      // assert: i == j
      // all the number from the back until j (exclusive) is smaller than a[i]
      inver += n - 1 - j;
      break;
    }
  }

  // decre is the number of elements in decreasing order (apart from the peak)
  long decre = n - 1 - j;
  // for k number in decreasing order, inversion = k*(k-1)/2
  inver += decre * (decre - 1) / 2;

  cs1010_println_long(inver);

  return 0;
}
