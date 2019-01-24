/**
 * CS1010 Semester 1 AY18/19
 * Exercise 1: Freezer
 * @file: freezer2.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include <math.h>
#include "cs1010.h"

/**
 * Read the number of hours and minutes since power 
 * failure and output the freezer temperature.
 */

float get_temperature(float time){
  return (4.0*pow(time,2))/(time+2.0)-20.0;
}

float get_time(int hours,int minutes){
  return hours+minutes/60.0;
}

int main() 
{
  long *time_sets = cs1010_read_long_array(2);
  float time = get_time(time_sets[0],time_sets[1]);
  cs1010_print_double(get_temperature(time));
}
