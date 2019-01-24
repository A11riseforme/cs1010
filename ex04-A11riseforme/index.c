/**
 * CS1010 Semester 1 AY18/19
 * Exercise 4: Index
 *
 * TODO(by student) Describe what this program does.
 *
 * @file: grade.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"

void search(long *search_list, long num_of_search_list, long query_num);

int main() {
    long num_of_search_list = cs1010_read_long();
    long *search_list = cs1010_read_long_array(num_of_search_list);
    long num_of_query_list = cs1010_read_long();
    long *query_list = cs1010_read_long_array(num_of_query_list);
    for (long m = 1; m <= num_of_query_list; m += 1) {
        search(search_list, num_of_search_list, query_list[m-1]);
    }
}

void search(long *search_list, long num_of_search_list, long query_num) {
    for (long i = 0; i < num_of_search_list; i += 1) {
        if (query_num == search_list[i]) {
            cs1010_println_long(i);
            return;
        }
    }
    cs1010_print_string("not found\n");
}
