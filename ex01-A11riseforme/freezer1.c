/*
 * CS1010 Semester 1 AY18/19
 * Exercise 1: Freezer
 * @file: freezer1.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include <math.h>
#include "cs1010.h"

/**
 * Read the number of hours since power failure and 
 * output the freezer temperature.
 */
float get_temperature(int time){
  return (4.0*pow(time,2))/(time+2.0)-20.0;
}

int main() 
{
  long time = cs1010_read_long();
  cs1010_print_double(get_temperature(time));
}
