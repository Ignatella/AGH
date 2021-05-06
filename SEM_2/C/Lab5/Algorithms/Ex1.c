#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int *createArray(int size, int value) {
    int *result = calloc(size, sizeof(int));
    for (int i = 0; i < size; ++i)
        memset(result + i, 1, 1 * sizeof(int));
    return result;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; ++i)
        printf("%2d  ", arr[i]);
    printf("\n");
}

int *compress(int *arr, int *size) {
    int i = 0, j = 0;
    for (; j < *size; ++j)
        if (arr[j] > 0)
            arr[i++] = arr[j];

    arr = realloc(arr, i * sizeof(int));
    *size = i;

    return arr;
}

int *strainer(int size, int *resultLen) {
    int *result = createArray(size, 1);
    *resultLen = size;

    result[0] = 0;
    for (int i = 2; i * i <= size; ++i) {
        if (result[i - 1] == 0)
            continue;

        for (int j = i * i; j <= size; j += i)
            if (j % i == 0)
                result[j - 1] = 0;
    }

    for (int i = 0; i < size; ++i) {
        if (result[i] != 0)
            result[i] = i + 1;
    }

    printArray(result, size);

    return compress(result, resultLen);
}

int main(int argc, char *argv[]) {
    if (argc < 2)
        exit(EXIT_FAILURE);

    int n = atoi(argv[1]), resLen = n;
    if (n < 1)
        exit(EXIT_FAILURE);

    int *r = strainer(n, &resLen);

    printArray(r, resLen);
    printf("Count of first numbers: %d\n", resLen);

    free(r);
    r = NULL;

    printf("End of program.\n");
    return 0;
}
