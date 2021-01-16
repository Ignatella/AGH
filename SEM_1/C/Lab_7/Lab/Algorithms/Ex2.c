#include <stdio.h>
#include <stdlib.h>

void fill_with_zeroes(int size, int array[size]) {
    for (int i = 0; i < size; ++i)
        array[i] = 0;
}

int *trim_array(int trim_count, int size, int array[size]) {
    int *result = (int *) calloc(size - trim_count, sizeof(int));

    for (int i = trim_count; i < size; ++i) {
        result[i - trim_count] = array[i];
    }

    return result;
}

int *unite(int size1, int size2, const int array1[size1], const int array2[size2]) {
    int *result = calloc(size1 + size2, sizeof(int));
    fill_with_zeroes(size1 + size2, result);
    int trim_count = 0;

    for (int i = size1 - 1, j = size2 - 1, k = size1 + size2 - 1; i > -1 && j > -1; --k) {
        if (array1[i] > array2[j]) {
            result[k] = array1[i];
            i--;
            continue;
        }

        if (array1[i] < array2[j]) {
            result[k] = array2[j];
            j--;
            continue;
        }

        if (array1[i] == array2[j]) {
            result[k] = array2[j];
            i--;
            j--;
            trim_count++;
        }
    }

    return trim_array(trim_count, size1 + size2, result);
}


int main() {
    int a[10] = {1, 5, 8, 9, 10, 11, 19, 21, 23, 45};
    int b[15] = {1, 4, 7, 11, 12, 15, 16, 18, 20, 58, 60, 71, 75, 81, 83};

    int *res = unite(10, 15, a, b);
    for (int i = 0; i < 23; ++i) {
        printf("%d\n", res[i]);
    }
    return 0;
}
