/**
 * CS1010 Semester 1 AY18/19
 * Assignment 8: Maze
 *
 * This nicely 400-line programme will help Scully escape the maze if possible.
 * Or stop exploring the maze once find out he is trapped.
 *
 * @file: fill.c
 * @author: YANG CHENGLONG (Group 01)
 */
#include "cs1010.h"
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define UP 'u'
#define RIGHT 'r'
#define DOWN 'd'
#define LEFT 'l'

#define CLEAR_SCREEN()\
    do {\
        char clear_screen[] = { 27, '[', '2', 'J',27, '[', ';', 'H', '\0'};\
        cs1010_print_string(clear_screen);\
        usleep(250 * 1000);\
    } while (0)

#define CHECK_ALLOC(OBJ)\
    do {\
        if (OBJ == NULL) {\
            cs1010_println_string("Memory Allocation Error");\
            return 0;\
        }\
    } while(0)

void find_pos(char **maze, long *pos, long height, long width);
void print_maze(char **maze, long height, long width);
void explore(char **maze, long *init_pos, long *pos, char *path, long height, long width, long count);
bool can_visit(char **maze, long *pos, char direction);
bool have_not_visited(char **maze, long *pos, char direction);
bool not_wall(char **maze, long *pos, char direction);
bool is_at_border(long *pos, long height, long width);
void move(char **maze, long *pos, char direction);
void mark_visited(char **maze, long *pos);
void trace_back(char **maze, long *pos, char *path);
void update_path(char *path, char direction);
char get_last_direction(char *path);
void remove_last_direction(char *path);

int main() {
    long height = cs1010_read_long();
    long width = cs1010_read_long();

    char **maze = cs1010_read_line_array(height);
    CHECK_ALLOC(maze);

    //init_pos is for reference, see whether it goes back to origin.
    long *init_pos = calloc(2, sizeof(long));
    CHECK_ALLOC(init_pos);
    find_pos(maze, init_pos, height, width);

    // pos is to be modified, denote Scully's position.
    long *pos = calloc(2, sizeof(long));
    CHECK_ALLOC(pos);
    memcpy(pos, init_pos, 2 * sizeof(long));

    // path is used to store the path information that Scully has gone through.
    // in a m*n maze, maximum efficient move take to escape is (m-2)*(n-2), proof omitted.
    long path_length = (height - 2) * ( width - 2);
    char *path = calloc(path_length, sizeof(char));
    CHECK_ALLOC(path);

    long count = 0;

    explore(maze, init_pos, pos, path, height, width, count);

    for (long i = 0; i < height; i += 1) {
        free(*(maze + i));
    }
    free(maze);
    free(path);
    free(init_pos);
    free(pos);
}


/**
 * @brief This function finds the position of Scully in the maze.
 *
 * @param[in] maze The array storing maze.
 * @param[in] height The height of the maze.
 * @param[in] width The width of the maze.
 * @param[out] pos The array storing the position information of Scully. 
 */
void find_pos(char **maze, long *pos, long height, long width) {
    for (long i = 0; i < height; i += 1) {
        for (long j = 0; j < width; j += 1) {
            if (*(*(maze + i) + j) == '@') {
                *(pos + 0) = i;
                *(pos + 1) = j;
            }
        }
    }
}


/**
 * @brief This function prints out the maze, will replace the unit of '*' which was
 * marked as visited to '.'.
 *
 * param[in] maze The array storing maze.
 * param[in] height The height of the maze.
 * param[in] width The width of the maze.
 */
void print_maze(char **maze, long height, long width) {
    for (long i = 0; i < height; i += 1) {
        for (long j = 0; j < width; j += 1) {
            if (*(*(maze + i) + j) == '*') {
                putchar('.');
            } else {
                putchar(*(*(maze + i) + j));
            }
        }
        putchar('\n');
    }
}


/**
 * @brief This function will explore the maze using the strtegies given here:
 * https://nus-cs1010.github.io/1819-s1/as08/index.html#question-1-maze-15-marks
 *
 * @param[in,out] maze The array storing maze, will be modified when units are visited.
 * @param[in] init_pos The array storing information of initial position of Scully.
 * @param[in,out] pos The array storing information of position of Scully at all time.
 * @param[in,out] path The array storing information of the path that Scully has gone through.
 * @param[in] height The height of the maze.
 * @param[in] width The width of the maze.
 * @param[in] count The counter to keep track of how many moves has Scully taken.
 */
void explore(char **maze, long *init_pos, long *pos, char *path, long height, long width, long count) {
    CLEAR_SCREEN();
    print_maze(maze, height, width);
    cs1010_println_long(count);
    count += 1;
    // if at border, then Scully has escaped the maze.
    if (is_at_border(pos, height, width)) {
        return;
    }
    if (can_visit(maze, pos, UP)) {
        update_path(path, UP);
        move(maze, pos, UP);
        explore(maze, init_pos, pos, path, height, width, count);
    } else if (can_visit(maze, pos, RIGHT)) {
        update_path(path, RIGHT);
        move(maze, pos, RIGHT);
        explore(maze, init_pos, pos, path, height, width, count);
    } else if (can_visit(maze, pos, DOWN)) {
        update_path(path, DOWN);
        move(maze, pos, DOWN);
        explore(maze, init_pos, pos, path, height, width, count);
    } else if (can_visit(maze, pos, LEFT)) {
        update_path(path, LEFT);
        move(maze, pos, LEFT);
        explore(maze, init_pos, pos, path, height, width, count);
    // if Scully cannot move up or down or right of left, and has 
    // reached the initial position, he is trapped.
    } else if((*(pos + 0) == *(init_pos + 0)) && (*(pos + 1) == *(init_pos + 1))) {
        return;
    // if Scully cannot move up or down or right of left, but has not 
    // reached the initial position, he can trace back the way he came
    // from and find another way out.
    } else {
        trace_back(maze, pos, path);
        explore(maze, init_pos, pos, path, height, width, count);
    }
}


/**
 * @brief This function will determine whether Scully can move towards a certain direction.
 *
 * @param[in] maze The array storing maze.
 * @param[in] pos The array storing information of position of Scully. 
 * @param[in] direction The direction Scully tends to move towards.
 *
 * @return Return true if Scully can move towards that direction, false otherwise.
 */
bool can_visit(char **maze, long *pos, char direction) {
    if (not_wall(maze, pos, direction) && have_not_visited(maze, pos, direction)) {
        return true;
    }
    return false;
}


/**
 * @brief This function will determine whether a unit on Scully's certain direction has been visited before.
 *
 * @param[in] maze The array storing maze.
 * @param[in] pos The array storing information of position of Scully. 
 * @param[in] direction The direction Scully tends to move towards.
 *
 * @return Return true if Scully hasn't visited the unit on that direction, false otherwise.
 */
bool have_not_visited(char **maze, long *pos, char direction) {
    switch (direction) {
        case UP:
            if (*(*(maze + *(pos + 0) - 1) + * (pos + 1)) == '*') {
                return false;
            }
            return true;
        case RIGHT:
            if (*(*(maze + *(pos + 0)) + * (pos + 1) + 1) == '*') {
                return false;
            }
            return true;
        case DOWN:
            if (*(*(maze + *(pos + 0) + 1) + * (pos + 1)) == '*') {
                return false;
            }
            return true;
        case LEFT:
            if (*(*(maze + *(pos + 0)) + * (pos + 1) - 1) == '*') {
                return false;
            }
            return true;
    }
    return true;
}


/**
 * @brief This function will determine whether a unit on Scully's certain direction is a wall.
 *
 * @param[in] maze The array storing maze.
 * @param[in] pos The array storing information of position of Scully. 
 * @param[in] direction The direction Scully tends to move towards.
 *
 * @return Return true if the unit on that direction is not a wall, false otherwise.
 */
bool not_wall(char **maze, long *pos, char direction) {
    switch (direction) {
        case UP:
            if (*(*(maze + *(pos + 0) - 1) + * (pos + 1)) == '#') {
                return false;
            }
            return true;
        case RIGHT:
            if (*(*(maze + *(pos + 0)) + * (pos + 1) + 1) == '#') {
                return false;
            }
            return true;
        case DOWN:
            if (*(*(maze + *(pos + 0) + 1) + * (pos + 1)) == '#') {
                return false;
            }
            return true;
        case LEFT:
            if (*(*(maze + *(pos + 0)) + * (pos + 1) - 1) == '#') {
                return false;
            }
            return true;
    }
    return true;
}


/**
 * @brief This function will determine whether Scully has reached the border of the maze.
 *
 * @param[in] pos The array storing information of position of Scully.
 * @param[in] height The height of the maze.
 * @param[in] width The width of the maze.
 *
 * @return Return true if Scully has reached the border of the maze, false otherwise.
 */
bool is_at_border(long *pos, long height, long width) {
    if ((*(pos + 0) == 0) ||
        (*(pos + 0) == (height - 1)) ||
        (*(pos + 1) == 0) ||
        (*(pos + 1) == (width - 1))) {
        return true;
    }
    return false;
}


/**
 * @brief This function will move Scully towards a certain direction by one unit.
 *
 * @param[in,out] maze The array storing maze, will be modified when units are visited.
 * @param[in,out] pos The array storing information of position of Scully, to be modified here.
 * @param[in] direction The direction Scully tends to move towards.
 */
void move(char **maze, long *pos, char direction) {
    // mark the current unit as visited.
    mark_visited(maze, pos);
    switch (direction) {
        case UP:
            *(*(maze + * (pos + 0) - 1) + * (pos + 1)) = '@';
            *(pos + 0) -= 1;
            break;
        case RIGHT:
            *(*(maze + * (pos + 0)) + * (pos + 1) + 1) = '@';
            *(pos + 1) += 1;
            break;
        case DOWN:
            *(*(maze + * (pos + 0) + 1) + * (pos + 1)) = '@';
            *(pos + 0) += 1;
            break;
        case LEFT:
            *(*(maze + * (pos + 0)) + * (pos + 1) - 1) = '@';
            *(pos + 1) -= 1;
            break;
    }
}

/**
 * @brief This function will mark the unit that Scully currently at as visited by 
 * replacing '*' as '.'.
 *
 * @param[out] maze The array storing maze, to be modified here.
 * @param[in] pos The array storing information of position of Scully
 */
void mark_visited(char **maze, long *pos) {
    *(*(maze + *(pos + 0)) + * (pos + 1)) = '*';
}


/**
 * @brief This function will allow Scully to trace back along the path that he goes through.
 * 
 * @param[out] maze The array storing maze, to be modified by move() function.
 * @param[out] pos The array storing information of position of Scully, to be modified  be move() function.
 * @param[in,out] path The array storing information of the path that Scully has gone through.
 */ 
void trace_back(char **maze, long *pos, char *path) {
    char come_from = get_last_direction(path);
    switch (come_from) {
        case UP:
            move(maze, pos, DOWN);
            break;
        case RIGHT:
            move(maze, pos, LEFT);
            break;
        case DOWN:
            move(maze, pos, UP);
            break;
        case LEFT:
            move(maze, pos, RIGHT);
            break;
    }
    remove_last_direction(path);
}


/**
 * @brief This function will update the path that Scully goes through.
 * @param[in,out] path The array storing information of the path that Scully has gone through.
 * @param[in] direction The direction Scully tends to move towards.
 */
void update_path(char *path, char direction) {
    long path_length = strlen(path);
    for (long i = 0; i <= path_length; i += 1) {
        if (*(path + i) == '\0') {
            *(path + i) = direction;
            break;
        }
    }
}


/**
 * @brief This function will get the last direction from path that Scully took.
 * 
 * @param[in] path The array storing information of the path that Scully has gone through.
 *
 * @return Return the last direction from path that Scully took, return space if path is empty.
 */
char get_last_direction(char *path) {
    long path_length = strlen(path);
    if (path_length != 0) {
        return *(path + path_length - 1);
    }
    return ' ';
}


/**
 * @brief This function remove the last direction from path, when Scully traces back one unit.
 *
 * @param[in,out] path The array storing information of the path that Scully has gone through.
 */
void remove_last_direction(char *path) {
    long path_length = strlen(path);
    *(path + path_length - 1) = '\0';
}

