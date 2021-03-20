#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LowerBound 1
#define UpperBound 10

void printArrayPtrsNotation(int x, int y, int (*arr)[y]) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j)
            printf("%2d   ", *(*(arr + i) + j));
        printf("\n");
    }
    printf("\n");
}

void fillArray(int x, int y, int (*arr)[y], int lowerBound, int upperBound) {
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j)
            *(*(arr + i) + j) = lowerBound + rand() % (upperBound - lowerBound + 1);
}

void sumsPtr(int size, int (*arr)[size], int *all, int *upper, int *on, int *under) {
    *all = *(*arr);
    *upper = *(*arr + 1);
    *under = *(*(arr + 1));
    *on = *(*arr);

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            if (!(i == 0 && j == 0))
                *all += *(*(arr + i) + j);

            if (i < j && !(i == 0 && j == 1))
                *upper += *(*(arr + i) + j);

            if (i > j && !(i == 1 && j == 0))
                *under += *(*(arr + i) + j);

            if (i == j && !(i == 0 && j == 0))
                *on += *(*(arr + i) + j);
        }
}

void sumsIndex(int size, int (*arr)[size], int *all, int *upper, int *on, int *under) {
    *all = arr[0][0];
    *upper = arr[0][1];
    *under = arr[1][0];
    *on = arr[0][0];

    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size; ++j) {
            if (!(i == 0 && j == 0))
                *all += arr[i][j];

            if (i < j && !(i == 0 && j == 1))
                *upper += arr[i][j];

            if (i > j && !(i == 1 && j == 0))
                *under += arr[i][j];

            if (i == j && !(i == 0 && j == 0))
                *on += arr[i][j];
        }
}

void seedRnd() {
    srand(time(NULL));
}

int main(int argc, char *argv[]) {
    seedRnd();

    if (argc != 2)
        exit(EXIT_FAILURE);

    int size = atoi(argv[1]);

    int array[size][size];
    int sum, upper, under, on;

    fillArray(size, size, array, LowerBound, UpperBound);
    printArrayPtrsNotation(size, size, array);


    sumsPtr(size, array, &sum, &upper, &on, &under);

    printf("After sumsPtr() call:\n");
    printf("Sum: %d\n", sum);
    printf("Upper: %d\n", upper);
    printf("On: %d\n", on);
    printf("Under: %d\n", under);

    printf("\n");

    printf("After sumsIndex() call:\n");
    printf("Sum: %d\n", sum);
    printf("Upper: %d\n", upper);
    printf("On: %d\n", on);
    printf("Under: %d\n", under);


    printf("End of program.\n");
    exit(EXIT_SUCCESS);
}
