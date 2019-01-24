/**
 * CS1010 Semester 1 AY18/19
 * Exercise 5: Escape
 *
 * @file: escape.c
 * @author: XXX (Group YYY)
 */
#include "cs1010.h"
#include <stdlib.h>
#include <string.h>

void follow_instructions(char **maze, long height, long width, char *instructions, long length, long trap_pos[], long pos[]);
void move(char **maze, long pos[], char direction);

int main() {
    long height = cs1010_read_long();
    long width = cs1010_read_long();
    char **maze = cs1010_read_line_array(height);
    char *instructions = cs1010_read_line();
    long length = strlen(instructions);
    long pos[2];
    long trap_pos[2];
    for (long i = 0; i < height; i += 1) {
        for (long j = 0; j < width; j += 1) {
            if (*(*(maze + i) + j) == 'A') {
                pos[0] = i;
                pos[1] = j;
            }
        }
    }
    follow_instructions(maze, height, width, instructions, length, trap_pos, pos);
}

void follow_instructions(char **maze, long height, long width, char *instructions, long length, long trap_pos[], long pos[]) {
    //cs1010_println_long(length);
    for (long i = 0; i < length; i += 1) {
        move(maze, pos, *(instructions + i));
        //printf("previous direction %c, current position at %ld %ld\n", *(instructions + i), pos[0], pos[1]);
        if (*(*(maze + pos[0]) + pos[1]) == '*') {
            cs1010_println_string("IT'S A TRAP!");
            return;
        } else if ((pos[0] == 0) || (pos[0] == height - 1) || (pos[1] == 0) || (pos[1] == width - 1)) {
            cs1010_println_string("ESCAPED!");
            return;
        }
    }
    cs1010_print_long(pos[0]);
    cs1010_print_string(" ");
    cs1010_println_long(pos[1]);
}

void move(char **maze, long pos[], char direction) {
    //putchar(*(*(maze + pos[0]) + pos[1] - 1));
    /*
    switch (direction) {
        case 'L':
            if (*(*(maze + pos[0]) + pos[1] - 1) != '#') {
                pos[1] -= 1;
            }
            break;
        case 'R':
            if (*(*(maze + pos[0]) + pos[1] + 1) != '#') {
                pos[1] += 1;
            }
            break;
        case 'U':
            if (*(*(maze + pos[0] - 1) + pos[1]) != '#') {
                pos[0] -= 1;
            }
            break;
        case 'D':
            if (*(*(maze + pos[0] + 1) + pos[1]) != '#') {
                pos[0] += 1;
            }
            break;
    }
    */
    if (direction == 'L') {
        if (*(*(maze + pos[0]) + pos[1] - 1) != '#') {
            pos[1] -= 1;
        }
    } else if (direction == 'R') {
        if (*(*(maze + pos[0]) + pos[1] + 1) != '#') {
            pos[1] += 1;
        }
    } else if (direction == 'U') {
        if (*(*(maze + pos[0] - 1) + pos[1]) != '#') {
            pos[0] -= 1;
        }
    } else {
        if (*(*(maze + pos[0] + 1) + pos[1]) != '#') {
            pos[0] += 1;
        }
    }
}
