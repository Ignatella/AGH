#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int **mergeArrs(int pointerCount, ...) {
    int **result = calloc(pointerCount, sizeof(int *));
    if (result == NULL)
        exit(EXIT_FAILURE);

    va_list params;
    va_start(params, pointerCount);
    for (int i = 0; i < pointerCount; i++) {
        *(result + i) = va_arg(params, int *);
    }
    va_end(params);

    return result;
}

void printArr(int size, int *arr) {
    for (int i = 0; i < size; ++i)
        printf("%d  ", arr[i]);

    printf("\n");
}

int main() {
    int tab_A[] = {3, 2, 5, 4};
    int tab_B[] = {12, 10, 13, 12, 18, 7};
    int tab_C[] = {22, 20};

    int **arr = mergeArrs(3, tab_A, tab_B, tab_C);

    printArr(4, arr[0]);
    printArr(6, arr[1]);
    printArr(2, arr[2]);

    free(arr);
    arr = NULL;
}
