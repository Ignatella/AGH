#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define upperBound 10
#define lowerBound 0


void fill_array(int row_count, int col_count, int arr[row_count][col_count]) {
    for (int i = 0; i < row_count; ++i) {
        for (int j = 0; j < col_count; ++j) {
            arr[i][j] = rand() % (upperBound - lowerBound + 1) + lowerBound;
        }
    }
}

void print_array(int row_count, int col_count, int arr[row_count][col_count]) {
    int col_sum[col_count];

    for (int i = 0; i < col_count; ++i)
        col_sum[i] = 0;

    for (int i = 0; i < row_count; ++i) {
        int row_sum = 0;
        for (int j = 0; j < col_count; ++j) {
            col_sum[j] += arr[i][j];
            row_sum += arr[i][j];
            printf("%4d", arr[i][j]);
        }
        printf("  | %d \n", row_sum);
    }

    printf("-------------------------------------------\n");

    for (int i = 0; i < col_count; ++i)
        printf("%4d", col_sum[i]);

    printf("\n");
}

void find_max(int *indexes, const int *values, int indexes_count, int value_count) {
    for (int j = 0; j < indexes_count; ++j)
        indexes[j] = -1;

    for (int i = 0; i < value_count; ++i) {
        if (indexes[indexes_count - 1] == -1 || values[i] > values[indexes[indexes_count - 1]]) {
            indexes[indexes_count - 1] = i;
            for (int j = indexes_count - 1; j > 0; --j) {
                if (indexes[j - 1] == -1 || values[indexes[j]] >= values[indexes[j - 1]]) {
                    int tmp = indexes[j];
                    indexes[j] = indexes[j - 1];
                    indexes[j - 1] = tmp;
                }
            }
        }
    }
}

int *remove_2_rooks(int N, int chessboard[N][N], const int *rook_position, int remove_count) {
    int sums[N];
    int *result = calloc(remove_count, sizeof(int));

    for (int i = 0; i < N; ++i)
        sums[i] = 0;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (*(rook_position + j) == i)
                sums[j] -= 2 * chessboard[i][j];
            sums[i] += chessboard[*(rook_position + i)][j];
            sums[j] += chessboard[i][j];
        }
    }

    //for debug purposes
    for (int i = 0; i < N; ++i) {
        printf("%d\n", sums[i]);
    }

    find_max(result, sums, remove_count, N);

    return result;
}

int main() {
    srand(time(NULL));

    int N = 10;
    int chessboard[N][N];
    int rookPositions[] = {1, 9, 2, 3, 4, 5, 6, 7, 8, 0,}; // row number
    int remove_count = 10;
    fill_array(N, N, chessboard);
    print_array(N, N, chessboard);

    int *res = remove_2_rooks(N, chessboard, rookPositions, remove_count);

    printf("----------------------------------\n");

    for (int i = 0; i < remove_count; ++i)
        printf("%d\n", res[i]);

    return 0;
}
