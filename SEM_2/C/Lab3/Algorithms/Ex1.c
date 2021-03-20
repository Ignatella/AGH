#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Size 5
#define LowerBound 1
#define UpperBound 10

void printArrayPtrNot(int size, const int *arr) {
    for (int i = 0; i < size; ++i)
        printf("%2d   ", *(arr + i));
    printf("\n");
}

void printArrayIndexNot(int size, const int *arr) {
    for (int i = 0; i < size; ++i)
        printf("%2d   ", arr[i]);
    printf("\n");
}

void fillArray(int x, int y, int (*arr)[y], int lowerBound, int upperBound) {
    for (int i = 0; i < x; ++i)
        for (int j = 0; j < y; ++j)
            *(*(arr + i) + j) = lowerBound + rand() % (upperBound - lowerBound + 1);
}

void sum(int size, const int *arr1, const int *arr2, int (*arr3)[size]) {
    for (int i = 0; i < size; ++i) {
        *(*(arr3) + i) = *(arr1 + i);
        *(*(arr3 + 1) + i) = *(arr2 + i);
        *(*(arr3 + 2) + i) = *(arr1 + i) + *(arr2 + i);
    }
}

void seedRnd() {
    srand(time(NULL));
}

int main() {
    seedRnd();
    int array1[Size];
    int array2[Size];
    int array3[3][Size];

    fillArray(1, Size, &array1, LowerBound, UpperBound); // This way [][] array also can be filled.
    fillArray(1, Size, &array2, LowerBound, UpperBound);

    sum(Size, array1, array2, array3);

    printf("Result array [Ptr notation]:\n");
    for (int i = 0; i < 3; ++i)
        printArrayPtrNot(Size, *(array3 + i));

    printf("\n");

    printf("Result array [Index notation]:\n");
    for (int i = 0; i < 3; ++i)
        printArrayPtrNot(Size, array3[i]);

    printf("\n");

    printf("Printing by columns: \n");
    for (int i = 0; i < Size; ++i) {
        printf("Column #%d\n", i);
        for (int j = 0; j < 3; ++j) {
            printf("Array3[%d][%d] = *(*(array3 + %d) + %d) = %d\n", j, i, j, i, *(*(array3 + j) + i));
        }
        printf("\n");
    }

    printf("End of program.\n");
    return 0;
}
