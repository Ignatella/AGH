#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LowerBound -100
#define UpperBound 100
#define TableSize 1000

int randInt(int lowerBound, int upperBound) {
    return lowerBound + rand() % (upperBound - lowerBound + 1);
}

void seedRnd() {
    srand(time(NULL));
}

int *createArr(int size) {
    int *res = calloc(size, sizeof(int));
    if (res == NULL)
        exit(EXIT_FAILURE);
    return res;
}

void fillArr(int size, int *arr) {
    for (int i = 0; i < size; ++i)
        arr[i] = randInt(LowerBound, UpperBound);
}

void printArr(int size, const int *arr) {
    for (int i = 0; i < size; ++i)
        printf("%d  ", *(arr + i));

    printf("\n");
}

int intCmp(const void *a, const void *b) {
    return *(int *) a - *(int *) b;
}

void sortArr(int size, int *arr) {
    qsort(arr, size, sizeof(int), intCmp);
}

int countEntries(int s, int e, int *val, const int *arr) {
    int result = 0;

    int *p = bsearch(val, arr + s, e - s, sizeof(int), intCmp);

    if (p == NULL)
        return 0;

    result++;
    result += countEntries(s, (int) (p - arr), val, arr);
    result += countEntries((int) (p - arr + 1), e, val, arr);

    return result;
}

int main(int argc, char **argv) {
    if (argc < 2)
        exit(EXIT_FAILURE);

    seedRnd();

    int *arr = createArr(TableSize);
    fillArr(TableSize, arr);

    printf("After creation:\n");
    printArr(TableSize, arr);

    sortArr(TableSize, arr);

    printf("After sort:\n");
    printArr(TableSize, arr);

    for (int i = 1; i < argc; ++i) {
        int val = atoi(argv[i]);
        int res = countEntries(0, TableSize, &val, arr);
        printf("%d has %d entries in array\n", val, res);
    }

    free(arr);
    arr = NULL;

    printf("End of program.\n");
    return 0;
}
