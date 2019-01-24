// NUS Students' Computing Club Academic Liaison Cell
// Mock Practical Exam (CS1010) AY 18/19 Sem 1
// Task 4
//
// Program Description:
// Given data in the form of an integer and a generator integer,
// calculate and output the CRCX checksum of the data.
//
// Author: Zachary Tang

#include "cs1010.h"
#include <math.h>

#define TEN 10

long compute_crcx(long, long);
int get_length(long);
long get_window(long, int, int);

int main() {

    long data = cs1010_read_long();
    long generator = cs1010_read_long();

    cs1010_println_long(compute_crcx(data, generator));
    return 0;
}

long compute_crcx(long data, long generator) {

    // Compute number of digits in both data and generator.
    int data_length = get_length(data);
    int generator_length = get_length(generator);

    // Use two index to create a window for computation.
    // Ones digit has lowest index
    int start_index = data_length;
    int end_index = data_length - generator_length;

    // Create checksum placeholder
    long checksum = generator;

    long window_value;

    // Generate new checksum until the window shifts all the way to the right.
    while (end_index >= 0) {

        // Get the window value
        window_value = get_window(data, start_index, end_index);

        // Create new intermediate value using XOR operation.
        checksum ^= window_value;

        // Remove overflow
        checksum = checksum % (long) pow(TEN, generator_length);

        // Decrement start and end index
        start_index -= 1;
        end_index -=1;
    }

    return checksum;
}

int get_length(long number) {

    // There are multiple alternatives that you can implement.
    // return (int) (Math.log10(data) + 1);

    // Initialize length.
    int length = 0;

    // Increment length by 1 when the last number can be removed.
    while (number > 0) {
        length += 1;
        number /= 10;
    }

    return length;
}

long get_window(long data, int start_index, int end_index) {

    // Initialize the window.
    long window = data;

    // Remove the numbers before the start index
    window %= (long) pow(TEN, start_index);

    // Remove the numbers after the end index
    window /= (long) pow(TEN, end_index);

    return window;
}
