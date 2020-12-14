#include <stdio.h>

#define arraySize 100

float sum(const float *numbers, int count) {
    float result = 0;
    for (int i = 0; i < count; ++i)
        result += *(numbers + i);

    return result;
}

float multiplication(const float *first, const float *last) {
    float result = 1;
    for (int i = 0; i < (last - first + 1); ++i)
        result *= *(first + i);

    return result;
}

void fillArray(float *numbers, int length) {
    for (int i = 0; i < length; ++i)
        *(numbers + i) = -3.0 + 0.07 * i;
}

int main() {
    float numbers[arraySize];

    fillArray(numbers, arraySize);

    printf("sum = %.2f, multiplication = %.9f\n",
           sum(numbers, arraySize), multiplication(numbers, numbers + arraySize - 1));

    for (int i = 0; i < arraySize; i += 10) {
        printf("elements from %d to %d, sum: %.2f, multiplication: %.9f\n",
               i, i + 9, sum(numbers + i, 10), multiplication(numbers + i, numbers + i + 9));
    }

    return 0;
}
