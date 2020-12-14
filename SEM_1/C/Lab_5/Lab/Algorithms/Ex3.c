#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define lowerBound 0
#define upperBound 15

#define countOfRes 3

void funnyFunc(const int *numbers, int length, double *result) {
    double sum = 0; //can be int
    double mult = 1; //can be int
    double arrMean = 0; //should be double

    for (int i = 0; i < length; ++i) {
        sum += *(numbers + i);
        mult *= *(numbers + i);
        arrMean  += *(numbers + i) / (double)length;
    }

    *result = sum;
    *(result + 1) = mult;
    *(result + 2) = arrMean;
}

void fillArray(int *array, int length) {
    for (int i = 0; i < length; ++i)
        array[i] = lowerBound + rand() % (upperBound - lowerBound + 1);
}

int main () {
    srand(time(NULL));
    int arrayLength = 3;

    printf("Please, provide array length:\n");
    scanf("%d", &arrayLength);

    int numbers[arrayLength];
    double result[countOfRes];

    fillArray(numbers, arrayLength);
    funnyFunc(numbers, arrayLength, result);

    printf("sum: %.0f, multiplication: %.0f, arithmetic mean: %.5f\n", *result, *(result + 1), *(result + 2));

    return 0;
}
