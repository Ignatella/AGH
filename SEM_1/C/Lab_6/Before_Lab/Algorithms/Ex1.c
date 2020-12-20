#include <stdio.h>

int find(int *arr, int count, int x) {

    if (count == 1) {
        if (*arr == x)
            return 1;
        else return 0;
    }

    if (*(arr + count / 2) <= x)
        return find(arr + count / 2, count -  count / 2, x);
    else
        return find(arr, count / 2, x);
}

int main() {
    int array[] = {1, 3, 5, 6, 7, 9, 11, 13, 16, 22, 25, 34, 35, 36, 37, 45, 46, 47, 47, 47, 55, 56, 58, 59};

    printf("%d ", find(array, 24, 11));

    return 0;
}