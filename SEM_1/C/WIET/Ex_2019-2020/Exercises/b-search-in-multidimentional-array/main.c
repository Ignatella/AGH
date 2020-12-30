#include <stdio.h>

//region Helpers
void fill_array(int row_count, int col_count, int array[row_count][col_count]) {
    int curr = -6;
    for (int i = 0; i < row_count; ++i) {
        for (int j = 0; j < col_count; ++j) {
            *(*(array + i) + j) = curr;
            if (j != 0)
                curr++;
        }
    }
}

void print_array(int row_count, int col_count, int array[row_count][col_count]) {
    for (int i = 0; i < row_count; ++i) {
        for (int j = 0; j < col_count; ++j) {
            printf("%3d ", *(*(array + i) + j));
        }
        printf("\n");
    }
}
//endregion

int count_greater_than_zero(int row_count, int col_count, int array[row_count][col_count]) {
    int lower_bound = 0;
    int upper_bound = row_count * col_count;

    if (array[0][0] > 0)
        return row_count * col_count;
    if (array[row_count - 1][col_count - 1] < 0)
        return 0;

    while (lower_bound != upper_bound) {
        int i = (int) ((lower_bound + upper_bound) / 2);
        int row = i / col_count;
        int col = i % col_count;

        int el = array[row][col];

        if (el == 0) {
            for (int j = row; j < row_count; ++j) {
                for (int k = j == row ? col : 0; k < col_count; ++k) {
                    if (array[j][k] > 0)
                        return (row_count - j) * col_count - (k);
                }
            }
            break;
        }

        if (el < 0) {
            lower_bound = i;
        }

        if (el > 0) {
            upper_bound = i;
        }
    }

    return 0;
}

int main() {
    int size = 4;
    int array[size][size];
    fill_array(size, size, array);
    print_array(size, size, array);

    int result = count_greater_than_zero(size, size, array);
    printf("Result: %d\n", result);
    return 0;
}
