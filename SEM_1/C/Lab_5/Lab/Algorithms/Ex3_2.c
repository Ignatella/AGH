#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define lowerBound 0
#define upperBound 15

void funnyFunc(const int *numbers, int length, int *sum, int *mult, double *arrMean) {
    for (int i = 0; i < length; ++i) {
        *sum += *(numbers + i);
        *mult *= *(numbers + i);
        *arrMean += *(numbers + i) / (double) length;
    }
}

void fillArray(int *array, int length) {
    for (int i = 0; i < length; ++i)
        array[i] = lowerBound + rand() % (upperBound - lowerBound + 1);
}

int main() {
    srand(time(NULL));
    int arrayLength = 3;

    printf("Please, provide array length:\n");
    scanf("%d", &arrayLength);

    int numbers[arrayLength];
    fillArray(numbers, arrayLength);

    int sum = 0;
    int mult = 1;
    double arrMean = 0;

    int *sumAdr = &sum;
    int *multAdr = &mult;
    double *arrMeanAdr = &arrMean;

    funnyFunc(numbers, arrayLength, sumAdr, multAdr, arrMeanAdr);

    printf("sum: %d, multiplication: %d, arithmetic mean: %.5f\n", sum, mult, arrMean);

    return 0;
}
