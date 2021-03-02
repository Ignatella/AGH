#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Size1 5
#define Size2 5


void swap(float *f, float *s) {
    float tmp = *f;
    *f = *s;
    *s = tmp;
}

void printArray(int size, const float *arr) {
    for (int i = 0; i < size; ++i)
        printf("%7.3f", *(arr + i));

    printf("\n");
}

float randFloat() {
    return rand() / (float) RAND_MAX;
}

void seedRand() {
    srand(time(NULL));
}

void fillArrayWithRands(int size, float *arr) {
    for (int i = 0; i < size; ++i) {
        *(arr + i) = randFloat();
    }
}

void revert(int size, float *arr) {
    float *s = arr;
    float *e = arr + size - 1;

    for (; s < e; ++s, --e)
        swap(s, e);
}

void swapArrays(int size, float *arr1, float *arr2) {
    for (int i = 0; i < size; ++i)
        swap(arr1 + i, arr2 + i);
}

void mergeSortedArrays
        (int size1, const float *arr1, int size2, float const *arr2, float *result) {

    int i = 0, j = 0, k = 0;
    for (; i < size1 && j < size2; ++k) {
        if (*(arr1 + i) <= *(arr2 + j)) {
            *(result + k) = *(arr1 + i);
            i++;
            continue;
        }

        *(result + k) = *(arr2 + j);
        j++;
    }

    if (i <= size1)
        for (; i < size1; ++i, ++k)
            *(result + k) = *(arr1 + i);


    if (j <= size2)
        for (; j < size2; ++j, ++k)
            *(result + k) = *(arr2 + j);
}

// region Sortings

// region Bubble Sort O(n*n)

void revertBubbleSort(int size, float *arr) {
    for (int i = size - 1; i > 0; --i)
        for (int j = size - 1; j > size - i - 1; --j)
            if (*(arr + j) < *(arr + j - 1))
                swap(arr + j, arr + j - 1);
}

void bubbleSort(int size, float *arr) {
    for (int i = 0; i < size; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (*(arr + j) > *(arr + j + 1))
                swap(arr + j, arr + j + 1);
}

// endregion

// region Insertion Sort O(n*n)

void insertionSort(int size, float *arr) {
    for (int i = 1; i < size; ++i) {
        float key = *(arr + i);
        int j = i - 1;

        while (j > -1 && *(arr + j) > key) {
            swap(arr + j, arr + j + 1);
            --j;
        }

        *(arr + j + 1) = key;
    }
}

// endregion

// region Selection Sort O(n*n)

void selectionSort(int size, float *arr) {
    for (int i = 0; i < size - 1; ++i) {
        int m = i;
        for (int j = i + 1; j < size; ++j) {
            if (*(arr + j) < *(arr + m))
                m = j;
        }

        swap(arr + m, arr + i);
    }
}

// endregion

// endregion

int main() {
    seedRand();

    float array1[Size1];
    float array2[Size2];
    float array3[Size1 + Size2];


    // region Sort Arrays
    printf("===== Sorting =====\n");

    printf("Array #1:\n");
    fillArrayWithRands(Size1, array1);
    printArray(Size1, array1);
    printf("After sort:\n");
    revertBubbleSort(Size1, array1);
    printArray(Size1, array1);

    printf("Array #2\n");
    fillArrayWithRands(Size2, array2);
    printArray(Size2, array2);
    printf("After sort:\n");
    revertBubbleSort(Size2, array2);
    printArray(Size2, array2);

    // endregion

    printf("\n");

    //region Merge Arrays
    printf("===== Merge Sorted Arrays =====\n");

    mergeSortedArrays(Size1, array1, Size2, array2, array3);

    printArray(Size1 + Size2, array3);

    //endregion

    printf("\n");

    // region Swap
    printf("====== Swap =====\n");

    float a = 10;
    float b = 20;

    printf("Before:\n");
    printf("First: %f; Second: %f\n", a, b);
    swap(&a, &b);
    printf("After:\n");
    printf("First: %f; Second: %f\n", a, b);

    // endregion

    printf("\n");

    // region Swap Arrays
    printf("===== Swap Arrays ===== \n");


    printf("Before:\n");
    printf("Array #1\n");
    printArray(Size1, array1);
    printf("Array #2\n");
    printArray(Size2, array2);

    swapArrays(Size1, array1, array2);

    printf("After:\n");
    printf("Array #1\n");
    printArray(Size1, array1);
    printf("Array #2\n");
    printArray(Size2, array2);

    // endregion

    printf("\n");

    // region Revert Array
    printf("===== Revert Array #2 =====\n");

    printf("Second array before revert:\n");
    printArray(Size2, array2);

    revert(Size2, array2);

    printf("Second array after revert:\n");
    printArray(Size2, array2);

    // endregion

    printf("\n");

    printf("End of program.\n");
    return 0;
}
