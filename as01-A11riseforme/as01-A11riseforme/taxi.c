/**
 * CS1010 Semester 1 AY18/19
 * Assignment 1: Taxi
 * Read the day, hour, and minute when a passenger board a taxi
 * and the distance in meter travelled from the standard input,
 * and print the taxi fare to the standard output.
 * @file: taxi.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include <stdbool.h>
#include "cs1010.h"
#include <math.h>

double surcharge_rate(long day, long time);
double metered_fare(long distance);

int main() {
	long day = cs1010_read_long();
	long hours = cs1010_read_long();
	long minutes = cs1010_read_long();
	long distance = cs1010_read_long();
	long time = hours*100 + minutes; // convert hours and minutes into mmss format.
	double rate = surcharge_rate(day, time);
	double fare = metered_fare(distance) * rate;
	cs1010_println_double(fare);
}

double surcharge_rate(long day, long time) { // calculate surcharge rate
	if ((0 <= time) && (time <= 559)) { // midnight peak hour
		return 1.50;
	} else if(((1800 <= time) && (time <= 2359)) || (day <= 5 && ((600 <= time) && (time <= 929)))) { // morning peak hour or evening peak hour
		return 1.25;
	} else {
		return 1.00;
	}
}

double metered_fare(long distance) {
	if (distance <= 1000) {
		return 3.40;
	} else if ((1000 < distance) && (distance <= 10200)) {
		return 3.40 + (ceil((distance - 1000) / 400.0)) * 0.22;
	} else {
		return 3.40 + (ceil((10200 - 1000) / 400.0))*0.22 + (ceil((distance - 10200) / 350.0)) * 0.22;
	}
}	

