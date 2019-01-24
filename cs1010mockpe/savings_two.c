// NUS Students' Computing Club Academic Liaison Cell
// Mock Practical Exam (CS1010) AY 18/19 Sem 1
// Task 2
//
// Program Description:
//
// Author:

#include "cs1010.h"

void final_amount(double principal_amount, double simple_rate, double compound_rate, long years);

int main() {
    double principal_amount = cs1010_read_double();
    double simple_interest_rate = cs1010_read_double();
    double compound_interest_rate = cs1010_read_double();
    long years = cs1010_read_long();
    final_amount(principal_amount, simple_interest_rate, compound_interest_rate, years);
    return 0;
}

void final_amount(double principal_amount, double simple_rate, double compound_rate, long years) {
    double simple_saving = principal_amount;
    double compound_saving = principal_amount;
    while (years  > 0) {
        simple_saving += principal_amount * (simple_rate / 100);
        compound_saving *= (1 + compound_rate / 100);
        years -= 1;
    }
    cs1010_println_double(simple_saving);
    cs1010_println_double(compound_saving);
}
