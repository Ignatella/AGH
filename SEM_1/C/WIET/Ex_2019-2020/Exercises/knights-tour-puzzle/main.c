#include <stdio.h>
#include <stdlib.h>

struct cell {
    int row;
    int col;
};

struct cell *create_cell(int row, int col) {
    struct cell *result = calloc(1, sizeof(struct cell));
    result->row = row;
    result->col = col;
    return result;
}

void fill_array_with_zeroes(int row_count, int col_count, int array[row_count][col_count]) {
    for (int i = 0; i < row_count; ++i) {
        for (int j = 0; j < col_count; ++j) {
            *(*(array + i) + j) = 0;
        }
    }
}

void print_array(int row_count, int col_count, int array[row_count][col_count]) {
    for (int i = 0; i < row_count; ++i) {
        for (int j = 0; j < col_count; ++j) {
            printf("%3d", *(*(array + i) + j));
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    printf("\n");
}

struct cell *can_jump_be_done(int cur_row, int cur_col, int size, int chessboard[size][size], int entry) {
    int row = cur_row - 1;
    int col = cur_col + 2;
    if (row > -1 && col < size && chessboard[row][col] == 0) { // 1
        if (entry == 0)
            return create_cell(row, col);
        --entry;
    }

    row = cur_row - 2;
    col = cur_col + 1;
    if (row > -1 && col < size && chessboard[row][col] == 0) { // 2
        if (entry == 0)
            return create_cell(row, col);
        --entry;
    }

    row = cur_row - 2;
    col = cur_col - 1;
    if (row > -1 && col > -1 && chessboard[row][col] == 0) { // 3
        if (entry == 0)
            return create_cell(row, col);
        --entry;
    }

    row = cur_row - 1;
    col = cur_col - 2;
    if (row > -1 && col > -1 && chessboard[row][col] == 0) { // 4
        if (entry == 0)
            return create_cell(row, col);
        --entry;
    }

    row = cur_row + 1;
    col = cur_col - 2;
    if (row < size && col > -1 && chessboard[row][col] == 0) { // 5
        if (entry == 0)
            return create_cell(row, col);
        --entry;
    }

    row = cur_row + 2;
    col = cur_col - 1;
    if (row < size && col > -1 && chessboard[row][col] == 0) { // 6
        if (entry == 0)
            return create_cell(row, col);
        --entry;
    }

    row = cur_row + 2;
    col = cur_col + 1;
    if (row < size && col < size && chessboard[row][col] == 0) { // 7
        if (entry == 0)
            return create_cell(row, col);
        --entry;
    }

    row = cur_row + 1;
    col = cur_col + 2;
    if (row < size && col < size && chessboard[row][col] == 0) { // 8
        if (entry == 0)
            return create_cell(row, col);
        --entry;
    }

    return NULL;
}

int release_new_year_horse(int curr_row, int curr_col, int size, int chessboard[size][size], int call_count) {
    if (call_count == size * size)
        return 1;

    if (call_count == 0) {
        for (int i = 0; i < size; ++i) {
            for (int j = 0; j < size; ++j) {
                chessboard[i][j] = 1;
                for (int k = 0; k < 8; ++k) {
                    struct cell *where_to_jump = can_jump_be_done(i, j, size, chessboard, k);
                    if (where_to_jump != NULL) {
                        chessboard[where_to_jump->row][where_to_jump->col] = call_count + 2;
                        int res = release_new_year_horse(where_to_jump->row, where_to_jump->col, size, chessboard,
                                                         call_count + 2);
                        if (res != 0)
                            return res;

                        chessboard[where_to_jump->row][where_to_jump->col] = 0;
                    }
                    free(where_to_jump);
                }
                chessboard[i][j] = 0;
            }
        }
        return 0;
    }

    for (int k = 0; k < 8; ++k) {
        struct cell *where_to_jump = can_jump_be_done(curr_row, curr_col, size, chessboard, k);
        if (where_to_jump != NULL) {
            chessboard[where_to_jump->row][where_to_jump->col] = call_count + 1;
            int res = release_new_year_horse(where_to_jump->row, where_to_jump->col, size, chessboard,
                                             call_count + 1);
            if (res != 0)
                return res;

            chessboard[where_to_jump->row][where_to_jump->col] = 0;

        }
        free(where_to_jump);
    }

    return 0;
}

int main() {
    int size = 8;
    int chessboard[size][size];
    fill_array_with_zeroes(size, size, chessboard);
    print_array(size, size, chessboard);
    release_new_year_horse(0, 0, size, chessboard, 0);
    print_array(size, size, chessboard);
    printf("Hello, World!\n");
    return 0;
}
