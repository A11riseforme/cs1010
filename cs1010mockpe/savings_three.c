// NUS Students' Computing Club Academic Liaison Cell
// Mock Practical Exam (CS1010) AY 18/19 Sem 1
// Task 3
//
// Program Description:
//
// Author:

#include "cs1010.h"
#include <math.h>

long calc_years(double principal_amount, double simple_rate, double compound_rate);

int main() {
    double principal_amount = cs1010_read_double();
    double simple_rate = cs1010_read_double();
    double compound_rate = cs1010_read_double();
    long years = calc_years(principal_amount, simple_rate, compound_rate);
    cs1010_print_long(years);
    return 0;
}

long calc_years(double principal_amount, double simple_rate, double compound_rate) {
    double simple_saving = principal_amount * (1 + simple_rate / 100);
    double compound_saving = principal_amount * (1 + compound_rate / 100);
    long years = 1;
    while (simple_saving > compound_saving) {
        simple_saving += principal_amount * (simple_rate / 100);
        compound_saving *= (1 + compound_rate / 100);
        years += 1;
    }
    return years;
}
