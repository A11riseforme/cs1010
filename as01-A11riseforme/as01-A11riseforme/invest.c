/**
 * CS1010 Semester 1 AY18/19
 * Assignment 1: Invest
 * Read the dollar amount of initial investment, the annual interest rate, 
 * and the number of years k from the standard input, and print the amount 
 * of money in the investment after k years to the standard output.
 * @file: invest.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include <math.h>
#include "cs1010.h"

int main() {
	long m = cs1010_read_long(); // read m as principal
	long r = cs1010_read_long(); // read r as interest rate
	long n = cs1010_read_long(); // read n as number of years
	double money = (m*(1-pow(r/100.0,n+1)))/(1-r/100.0); //calculate the money after n years
	cs1010_println_double(money);
}
