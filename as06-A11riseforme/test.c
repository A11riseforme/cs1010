/**
 * CS1010 Semester 1 AY18/19
 * Assignment 4: Permutation 3
 * 
 * This file contains a programme that determine if string S1 is the 
 * permutation of string S2, i.e. whether S2 contain all the elements of
 * string S1. The complexity for this programme is O(n+k)
 *
 * @file: permutation3.c
 * @author: Ye Guoquan (Group 01)
 */

#include "cs1010.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(){
  char* string_a = cs1010_read_word();
  char* string_b = cs1010_read_word();
  
  // array1 is used to store the number of occurence of 26 alphebet in string_a
  long array1[26] = {0};
  long k = strlen(string_a);

  // count the number of occurence of alphebets in string_a
  // complexity of the loop is k
  for (long i = 0; i < k; i += 1) {
    array1[(string_a[i] - 'a')] += 1;
  }

  long n = strlen(string_b);
  bool is_permutation = false;

  // record the number of alphebets in string_a that appear in string_b consecutively
  long count = 0;

  // complexity of this loop is n
  for (long i = 0; i < n; i += 1) {
    if (array1[string_b[i] - 'a'] > 0) {
      array1[string_b[i] - 'a'] -= 1;
      count += 1;
      if (count == k) {
        is_permutation = true;
        break; 
        }
    }
    else {
      if (count > 0) {
        array1[string_b[i - count] - 'a'] += 1;
        count -= 1;
        i -= 1;
      }
    }
  }

  // overall complexity is n + k + c, which is O(n+k)
  if (is_permutation) {
    cs1010_println_string("YES");
  }
  else {
    cs1010_println_string("NO");
  }

  return 0;
}

