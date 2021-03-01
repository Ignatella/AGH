#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LowerBound 1
#define UpperBound 100
#define ArraySize 4
#define PrintAfterSwap 1

float randV(float lowerBound, float upperBound) {
    return lowerBound + (rand() / (float) RAND_MAX) * (upperBound - lowerBound);
}

void fillArrWithRnd(int size, float *arr) {
    for (int i = 0; i < size; ++i)
        *(arr + i) = randV(LowerBound, UpperBound);
}

void printArray(int size, const float *arr) {
    for (int i = 0; i < size; ++i)
        printf("%f\t", *(arr + i));

    printf("\n");
}

void seedRnd() {
    srand(time(NULL));
}

float sum(int size, const float *arr, float *max, float *min, float *average, float *maxDis, float *minDis) {
    float sum = *arr;
    *max = *arr;
    *min = *arr;
    *average = *arr;

    for (int i = 1; i < size; ++i) {
        float el = *(arr + i);
        sum += el;

        if (el > *max)
            *max = el;
        if (el < *min)
            *min = el;
    }

    *average = sum / (float) size;

    if (*max - *average > *average - *min)
        *maxDis = *max - *average;
    else
        *maxDis = *average - *min;

    *minDis = fabsf(*arr - *average);

    for (int i = 0; i < size; ++i)
        if (fabsf(*(arr + i) - *average) < *minDis)
            *minDis = fabsf(*(arr + i) - *average);

    return sum;
}

void swap(float *first, float *second) {
    float tmp = *first;
    *first = *second;
    *second = tmp;
}


void revertBubbleSort(int size, float *arr, int print) {
    for (int i = size - 1; i > 0; --i)
        for (int j = size - 1; j > size - i - 1; --j)
            if (*(arr + j) < *(arr + j - 1)) {
                swap((arr + j), (arr + j - 1));
                if (print)
                    printArray(size, arr);
            }
}

int main() {
    seedRnd();

    float nums[ArraySize] = {0};
    fillArrWithRnd(ArraySize, nums);
    printArray(ArraySize, nums);

    float s, max, min, average, maxDis, minDis;

    s = sum(ArraySize, nums, &max, &min, &average, &maxDis, &minDis);

    printf("\n");
    printf("Results: \n");
    printf("Sum: %f\n", s);
    printf("Max: %f\n", max);
    printf("Min: %f\n", min);
    printf("Average: %f\n", average);
    printf("Max Dis: %f\n", maxDis);
    printf("Min Dis: %f\n", minDis);
    printf("\n");

    printf("Bubble sort: \n");
    revertBubbleSort(ArraySize, nums, PrintAfterSwap);

    printf("\n");
    printf("Final result: \n");
    printArray(ArraySize, nums);

    printf("The end.\n");
    return 0;
}
