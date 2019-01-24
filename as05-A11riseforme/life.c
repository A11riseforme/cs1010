/**
 * CS1010 Semester 1 AY18/19
 * Assignment 4: Life
 *
 * simulate 'Game of Life' for a certain number of iterations.
 * 
 *
 * @file: life.c
 * @author: YANG CHENGLONG (Group 01)
 */

#include "cs1010.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LIVE '#'
#define DEAD '.'
#define SLEEP_INTERVAL 250000

void draw_result(char **result, long row);
void update_cell_status(char **result, char **result_copy,  long i, long j);
void update_result(char **result, char **result_copy,  long row, long column);
bool is_live(char **result, long i, long j);
bool remain_live(char **result, long i, long j);
bool becomes_live(char **result, long i, long j);
long calc_live_cells(char **result, long i, long j);

int main() {
    char clear_screen[] = { 27, '[', '2', 'J',27, '[', ';', 'H'};
    long row = cs1010_read_long();
    long column = cs1010_read_long();
    long iteration = cs1010_read_long();
    char **result;
    result = cs1010_read_line_array(row);
    for (long k = 0; k < iteration; k += 1) {
        char **result_copy;
        result_copy = calloc(row, sizeof(char *));
        for (long i = 0; i < row; i += 1) {
                result_copy[i] = calloc(column, sizeof(char));
        }
        
        // make a copy of result, to be manipulated later.
        for (long i = 0; i < row; i += 1) {
            // beware of the last char of '\n' so use <=
            for (long j = 0; j <= column; j += 1) {
                result_copy[i][j] = result[i][j];
            }
        }
        
        update_result(result, result_copy, row, column);
        cs1010_print_string(clear_screen);
        draw_result(result_copy, row);
        
        // copy the content from result_copy to result for next round.
        for (long i = 0; i < row; i += 1) {
            // beware of the last char of '\n' so use <=
            for (long j = 0; j <= column; j += 1) {
                result[i][j] = result_copy[i][j];
            }
        }

        // free the memory allocated to result_copy.
        for (long i = 0; i < row; i += 1) {
            free(result_copy[i]);
        }
        free(result_copy);
        
        // wait for a specific period of time.
        usleep(SLEEP_INTERVAL);
    }

    // finally, free the memory allocated to result.
    for (long i = 0; i < row; i += 1) {
        free(result[i]);
    }
    free(result);
}

/**
 * draw the result.
 *
 * @param[in] result Arrray of the result.
 * @param[in] row Number of row of the result array.
 */
void draw_result(char **result, long row) {
    for (long i = 0; i < row; i += 1) {
        cs1010_print_string(*(result + i));
    }
}

/**
 * update the result of one round. the outer cell will remain unchanged
 * so start from 1, 1 and end at row -1, column -1. update every cell.
 *
 * @param[in] result Array of the original result.
 * @param[in] row Number of row of the result array.
 * @param[in] column Number of column of the result array.
 *
 * @param[in,out] result_copy Array of the result to be manipulated and printed.
 */
void update_result(char **result, char **result_copy, long row, long column) {
    for (long i = 1; i < row - 1; i += 1) {
        for (long j = 1; j < column - 1; j += 1) {
            update_cell_status(result, result_copy,  i, j);
        }
    }
}

/**
 * update one specific cell in ith row and jth column.
 *
 * @param[in] result Array of the original result, for reference.
 * @param[in] i Row number of the cell.
 * @param[in] j Column number of the cell.
 * 
 * @param[in, out] result_copy Array of result to be manipulated.
 */
void update_cell_status(char **result, char **result_copy,  long i, long j) {
    if (is_live(result, i, j)) {
        if (!remain_live(result, i, j)) {
            *(*(result_copy + i) + j) = DEAD;
        }
    } else {
        if (becomes_live(result, i, j)) {
            *(*(result_copy + i) + j) = LIVE;
        }
    }
}

/**
 * chech whether a specific cell is live.
 *
 * @param[in] result Array of the original result.
 * @param[in] i Row number of the cell.
 * @param[in] j Column number of the cell.
 *
 * return true if that cell is live, return false otherwise.
 */
bool is_live(char **result, long i, long j) {
    if (*(*(result + i) + j) == LIVE) {
        return true;
    } else {
        return false;
    }
}

/**
 * decide whether a specific live cell should remain live.
 *
 * @param[in] result Array of the original result.
 * @param[in] i Row number of the cell.
 * @param[in] j Column number of the cell.
 *
 * return true if that cell should remain live, return false otherwise.
 */

bool remain_live(char **result, long i, long j) {
    long live_count = calc_live_cells(result, i, j);
    if (live_count == 2 || live_count == 3) {
        return true;
    } else {
        return false;
    }
}

/**
 * decide whether a specific dead cell should become live.
 *
 * @param[in] result Array of the original result.
 * @param[in] i Row number of the cell.
 * @param[in] j Column number of the cell.
 *
 * return true if that cell should become live, return false otherwise.
 */
bool becomes_live(char **result, long i, long j) {
    long live_count = calc_live_cells(result, i, j);
    if (live_count == 3) {
        return true;
    } else {
        return false;
    }
}

/**
 * calculate the number of live cells around a specific cell.
 *
 * @param[in] result Array of the original result.
 * @param[in] i Row number of the cell.
 * @param[in] j Column number of the cell.
 *
 * return the number of live cells around that specific cell.
 */
long calc_live_cells(char **result, long i, long j) {
    long count = 0;
    if (*(*(result + (i - 1)) + (j - 1)) == LIVE) {
        count += 1;
    }
    if (*(*(result + (i - 1)) + j) == LIVE) {
        count += 1;
    }
    if (*(*(result + (i - 1)) + (j + 1)) == LIVE) {
        count += 1;
    }
    if (*(*(result + i) + (j - 1)) == LIVE) {
        count += 1;
    }
    if (*(*(result + i) + (j + 1)) == LIVE) {
        count += 1;
    }
    if (*(*(result + (i + 1)) + (j - 1)) == LIVE) {
        count += 1;
    }
    if (*(*(result + (i + 1)) + j) == LIVE) {
        count += 1;
    }
    if (*(*(result + (i + 1)) + (j + 1)) == LIVE) {
        count += 1;
    }
    return count;
}
