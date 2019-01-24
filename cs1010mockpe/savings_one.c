// NUS Students' Computing Club Academic Liaison Cell
// Mock Practical Exam (CS1010) AY 18/19 Sem 1
// Task 1
//
// Program Description:
//
// Author:

#include "cs1010.h"
#include <math.h>

double final_amount_a(double principal_amount, double interest_rate, long years);
double final_amount_b(double principal_amount, double interest_rate, long years);

int main() {
    double principal_amount = cs1010_read_double();
    double simple_interest_rate = cs1010_read_double();
    double compound_interest_rate = cs1010_read_double();
    long years = cs1010_read_long();
    cs1010_println_double(final_amount_a(principal_amount, simple_interest_rate, years));
    cs1010_println_double(final_amount_b(principal_amount, compound_interest_rate, years));
    return 0;
}

double final_amount_a(double principal_amount, double interest_rate, long years) {
    return (1 + interest_rate * years / 100) * principal_amount;
}

double final_amount_b(double principal_amount, double interest_rate, long years) {
    return pow((1 + interest_rate / 100) , years) * principal_amount;
}
