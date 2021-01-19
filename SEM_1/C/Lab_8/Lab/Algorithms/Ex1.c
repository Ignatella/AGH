#include <stdio.h>

int *find(int *arr, int count, int x) {

    if (count == 1) {
        if (*arr == x)
            return arr;
        else return NULL;
    }

    if (*(arr + count / 2) <= x)
        return find(arr + count / 2, count - count / 2, x);
    else
        return find(arr, count / 2, x);
}

int count_values(int count, const int array[count], int *link) {
    int result = 0;

    for (int *i = link; i >= array && *i == *link; --i)
        result++;

    for (int *i = link; i < array + count && *i == *link; ++i) {
        if (i == link)
            continue;
        result++;
    }

    return result;
}

int main() {
    //
    // Zlożoność: O(logN + N)
    //
    int array[] = {1, 3, 5, 6, 7, 9, 11, 13, 16, 22, 22, 22, 22, 25, 34, 35, 36, 37, 45, 46, 47, 47, 47, 55, 56, 58,
                   59};

    int *result = find(array, 27, 22); // log N
    if (result == NULL) {
        printf("No such value in the array.");
        return 0;
    }

    int count = count_values(27, array, result); // N

    printf("There is %d in the array, index: %ld, count: %d", *result, result - array, count);

    return 0;
}
