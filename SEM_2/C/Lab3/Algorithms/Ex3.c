#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LowerBound -5
#define UpperBound 5

void fillArray(int x, int y, int (*arr)[y], int lowerBound, int upperBound) {
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j)
            *(*(arr + i) + j) = lowerBound + rand() % (upperBound - lowerBound + 1);
}

void fillArrayWithZeroes(int x, int y, int (*arr)[y]) {
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j)
            *(*(arr + i) + j) = 0;
}

void printArrayMultiplication(int x1, int a, int y2, const int arr1[x1][a], const int arr2[a][y2], int res[x1][y2]) {
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < a; ++j)
            printf("       ");

        for (int j = 0; j < y2; ++j)
            printf("%3d   ", arr2[i][j]);

        printf("\n");
    }

    printf("\n");

    for (int i = 0; i < x1; ++i) {
        for (int j = 0; j < a; ++j)
            printf("%3d   ", arr1[i][j]);

        printf("    ");

        for (int j = 0; j < y2; ++j)
            printf("%3d   ", res[i][j]);

        printf("\n");
    }
    printf("\n");
}

void multiply(int x1, int a, int y2, const int arr1[x1][a], const int arr2[a][y2], int res[x1][y2]) {
    for (int i = 0; i < x1; ++i) {
        for (int j = 0; j < y2; ++j) {
            for (int k = 0; k < a; ++k) {
                res[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

void seedRnd() {
    srand(time(NULL));
}

int main(int argc, char *argv[]) {
    seedRnd();

    if (argc != 4)
        exit(EXIT_FAILURE);

    int x1 = atoi(argv[1]), a = atoi(argv[2]), y2 = atoi(argv[3]);

    int arr1[x1][a];
    int arr2[a][y2];
    int res[x1][y2];

    fillArray(x1, a, arr1, LowerBound, UpperBound);
    fillArray(a, y2, arr2, LowerBound, UpperBound);
    fillArrayWithZeroes(x1, y2, res);

    multiply(x1, a, y2, arr1, arr2, res);

    printArrayMultiplication(x1, a, y2, arr1, arr2, res);

    printf("End of program.\n");
    exit(EXIT_SUCCESS);
}
