/**
 * CS1010 Semester 1 AY18/19
 * Assignment 4: Social
 *
 * Apply the theorem of six degrees of separation,
 * using a jagged array to represent the relationship between n people,
 * check if under degree of k, are all n people connected.
 *
 * @file: social.c
 * @author: YANG CHENGLONG (Group 01)
 */

#include "cs1010.h"
#include <stdbool.h>
#include <stdlib.h>

bool is_friend(char **relationship, long i, long j);
bool is_connected(char **relationship, long i, long j, long num, long degree);
void update_relationship(char **relationship, long num, long degree);
bool is_all_connected(char **relationship, long num);
void print_relationship(char **relationship, long num);

int main() {
    long num = cs1010_read_long();
    long degree = cs1010_read_long();
    char **relationship;
    relationship = cs1010_read_line_array(num);

    update_relationship(relationship, num, degree);
    print_relationship(relationship, num);

    if (is_all_connected(relationship, num)) {
        cs1010_print_string("YES\n");
    } else {
        cs1010_print_string("NO\n");
    }

    // free the memory allocated to relationship
    for (long i = 0; i < num; i += 1) {
        free(relationship[i]);
    }
    free(relationship);
}

/**
 * Update relationship under degree n.
 * We go through a thorough check for any pairs to see if they are connected.
 * Except for the pairs of the person and himself, as he is his own friend.
 *
 * @param[in,out] relationship Jagged array containing relationship between n people under degree of 'degree'.
 * 
 * @param[in] degree The degree of relationship
 * @param[in] num Number of people
 */
void update_relationship(char **relationship, long num, long degree) {
    // make a copy of relationship for reference.
    char **relationship_copy;
    relationship_copy= calloc(num, sizeof(char *));
    for (long i = 0; i < num; i += 1) {
        relationship_copy[i] = calloc(i + 1, sizeof(char));
    }

    // copy the content of relationship to relationship_copy.
    for (long i = 0; i < num; i += 1) {
        for (long j = 0; j < i + 1; j += 1) {
            relationship_copy[i][j] = relationship[i][j];
        }
    }
    // the last pair we check is the (num-1)th person and the (num)th person.    
    for (long i = 0; i < num - 1; i += 1) {
        for (long j = i + 1; j < num; j += 1) {
            // if i and j are not friends
            if (*(*(relationship + j) + i) == '0'){
                // check if they are connected under degree of 'degree'.
                if (is_connected(relationship_copy, i, j, num, degree)) {
                    *(*(relationship + j) + i) = '1';
                }
            }
        }
    }

    // free the memory allocated to relatinship_copy.
    for (long i = 0; i < num; i += 1) {
        free(relationship_copy[i]);
    }
    free(relationship_copy);
}

/**
 * Check if the (i+1)th people and (j+1)th people are firends.(assuming i > j)
 * we are checking relationship[i][j] whether it is '1'
 * 
 * @param[in] relatinship Jagged array containing relationship between n people
 * @param[in] i The 'i+1'th people
 * @param[in] j The 'j+1'the people
 *
 * return true if they are friends, false otherwise.
 */
bool is_friend(char **relationship, long i, long j) {
    long m = (i > j ? i : j);
    long n = (i > j ? j : i);
    if (*(*(relationship + m ) + n) == '1') {
        return true;
    }
    return false;
}

/**
 * Check if ith people and jth people are connected under degree of n.
 * if degree is 1, simply check if i and j are friends.
 * if degree is more than 1 and i and j are not friends, we are checking
 * if there exists a third people k, who is a friend of i and connected with j
 * under degree of n - 1.
 *
 * @param[in,out] relationship Jagged array containing relationship between n people.
 *
 * @param[in] i The 'i+1'th people.
 * @param[in] j The 'j+1'th people.
 * @param[in] num The number of people.
 * @param[in] degree The degree of relationship.
 *
 * return true if they are connected, false otherwise.
 */
bool is_connected(char **relationship, long i, long j, long num, long degree) {
    if (degree == 1) {
        if (is_friend(relationship, i, j)) {
            return true;
        } else {
            return false;
        }
    } else {
        for (long k = 0; k < num; k += 1) {
            if (is_friend(relationship, i, k) && i != k) {
                if (is_connected(relationship, k, j, num, degree - 1)) {
                    return true;
                }
            }
        }
        return false;
    }
}

/**
 * Check if all the people in the relationship are connected,
 * by checking all the element to see if they are all '1'
 * 
 * @param[in] relationship Jagged array containing relationship between n people
 * @param[in] num The number of people in the relationship
 *
 * return true if all the people are connected, false otherwise.
 */
bool is_all_connected(char **relationship, long num) {
    for (long i = 0; i < num; i += 1) {
        for (long j = 0; j <= i; j += 1) {
            if (*(*(relationship + i) + j) != '1') {
                return false;
            }
        }
    }
    return true;
}

/**
 * Print out the jagged array of relationship
 * 
 * @param[in] relationship Jagged array containing relationship between n people
 * @param[in] num The number of people in the relationship
 */
void print_relationship(char **relationship, long num) {
    for (long i = 0; i < num; i += 1) {
        cs1010_print_string(*(relationship + i));
    }
}

