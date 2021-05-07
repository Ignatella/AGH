#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int randChar() {
    int isBig = rand() % 2;

    if (isBig) {
        return 'a' + rand() % 26;
    }

    return 'A' + rand() % 26;
}

void fillArr(int rows, int cols, char (*arr)[cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            arr[i][j] = (char) randChar();
    }
}

void printArr(int rows, int cols, char (*arr)[cols]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            printf("%c ", arr[i][j]);

        printf("\n");
    }
    printf("\n");
}

void seedRnd() {
    srand(time(NULL));
}

int compare(const void *a, const void *b) {
    int equal = tolower(*(const char *) a) - tolower(*(const char *) b);
    if (equal == 0)
        equal = *(const char *) a - *(const char *) b;
    return equal;
}

void sort(int size, char *arr) {
    qsort(arr, size, sizeof(char), compare);
}

int main() {
    seedRnd();
    int rows = 10, cols = 15;
    char arr[rows][cols];
    fillArr(rows, cols, arr);
    printf("Initial:\n");
    printArr(rows, cols, arr);

    for (int i = 0; i < rows; ++i)
        sort(cols, *(arr + i));

    printf("After cols sort:\n");
    printArr(rows, cols, arr);

    sort(cols * rows, *arr);

    printf("After total sort:\n");
    printArr(rows, cols, arr);

    printf("End of program.\n");
    return 0;
}
