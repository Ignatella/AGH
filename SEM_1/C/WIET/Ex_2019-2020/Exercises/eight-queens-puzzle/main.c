#include <stdio.h>

void print_array(int row_count, int col_count, int array[row_count][col_count]) {
    for (int i = 0; i < row_count; ++i) {
        for (int j = 0; j < col_count; ++j) {
            printf("%3d", array[i][j]);
        }
        printf("\n");
    }
}

void fill_with_zeroes(int row_count, int col_count, int array[row_count][col_count]) {
    for (int i = 0; i < row_count; ++i) {
        for (int j = 0; j < col_count; ++j) {
            *(*(array + i) + j) = 0;
        }
    }
}

int is_row_free(int row_n, int size, int chessboard[size][size]) {
    for (int i = 0; i < size; ++i) {
        if (chessboard[row_n][i] == 1)
            return 0;
    }

    return 1;
}

int is_col_free(int col_n, int size, int chessboard[size][size]) {
    for (int i = 0; i < size; ++i) {
        if (chessboard[i][col_n] == 1)
            return 0;
    }
    return 1;
}

int are_diagonals_free(int row_n, int col_n, int size, int chessboard[size][size]) {
    for (int i = row_n, j = col_n; i > -1 && j > -1; --i, --j) {
        if (chessboard[i][j] == 1)
            return 0;
    }

    for (int i = row_n, j = col_n; i > -1 && j < size; --i, ++j) {
        if (chessboard[i][j] == 1)
            return 0;
    }

    for (int i = row_n, j = col_n; i < size && j > -1; ++i, --j) {
        if (chessboard[i][j] == 1)
            return 0;
    }

    for (int i = row_n, j = col_n; i < size && j < size; ++i, ++j) {
        if (chessboard[i][j] == 1)
            return 0;
    }

    return 1;
}

int position_queens(int size, int chessboard[size][size], int remained_queens) {
    if (remained_queens == 0)
        return 1;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int row_free = is_row_free(i, size, chessboard);
            int col_free = is_col_free(j, size, chessboard);
            int diagonals_free = are_diagonals_free(i, j, size, chessboard);
            if (row_free && col_free && diagonals_free) {
                chessboard[i][j] = 1;
                int res = position_queens(size, chessboard, remained_queens - 1);

                if (res == 0)
                    chessboard[i][j] = 0;
                else return res;
            }
        }
    }

    return 0;
}

int main() {
    int n = 8;
    int chessboard[n][n];
    fill_with_zeroes(n, n, chessboard);
    if (n < 4) {
        printf("It is impossible for n < 4");
        return 1;
    }
    position_queens(n, chessboard, n);
    print_array(n, n, chessboard);
    return 0;
}
