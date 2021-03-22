#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LowerBound 97
#define UpperBound 122


int rndInt(int lowerBound, int upperBound) {
    return lowerBound + rand() % (upperBound - lowerBound + 1);
}

void fillArray(int rows, int cols, char (*arr)[cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = (char) rndInt(LowerBound, UpperBound);
        }
    }
}

void move(int rows, int cols, char (*arr)[cols]) {
    char item = *(*(arr + rows - 1) + cols - 1);
    for (int i = rows * cols - 1; i > 0; --i)
        *(*(arr) + i) = *(*(arr) + i - 1);

    **arr = item;
}

void seedRnd() {
    srand(time(NULL));
}

void printArray(int rows, int cols, char (*arr)[cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%c  ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void *create2DArray(int rows, int cols) {
    char (*created)[cols] = calloc(rows * cols, sizeof(char));
    return created;
}

int main(int argc, char *argv[]) {
    if (argc < 4)
        exit(EXIT_FAILURE);
    seedRnd();
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    int moveCount = atoi(argv[3]);
    char (*created)[cols] = create2DArray(rows, cols);
    fillArray(rows, cols, created);
    printArray(rows, cols, created);
    for (int i = 0; i < moveCount; ++i)
        move(rows, cols, created);
    printArray(rows, cols, created);

    free(created);
    created = NULL;
    printf("End of program.\n");
    exit(EXIT_SUCCESS);
}
