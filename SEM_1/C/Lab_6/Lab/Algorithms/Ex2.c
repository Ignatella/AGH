#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define arrayCount 3

#define numbers1Len 5
#define numbers2Len 10
#define numbers3Len 15

#define lowerBound -10 //-100 it's better to use 100 and -100
#define upperBound 10 //100

int *findMax(int *array, int length) {
    int *result = array;

    for (int i = 0; i < length; ++i) {
        if (*(array + i) % 2 == 0 && *(array + i) > *result)
            result = array + i;
    }

    return *result % 2 == 0 ? result : NULL;
}

void fillArray(int *array, int length) {
    for (int i = 0; i < length; ++i)
        array[i] = lowerBound + rand() % (upperBound - lowerBound + 1);
}

int main() {
    int lengths[arrayCount] = {numbers1Len, numbers2Len, numbers3Len};

    srand(time(NULL));

    int *numbers[arrayCount];
    int *max = NULL;

    for (int i = 0; i < arrayCount; ++i) {
        numbers[i] = (int *) calloc(lengths[i], sizeof(int));
        fillArray(numbers[i], lengths[i]);
        int *arrMax = findMax(numbers[i], lengths[i]);

        if (arrMax == NULL)
            continue;

        if (max == NULL || *arrMax >= *max)
            max = arrMax;
    }


    for (int i = arrayCount - 1; i >= 0; --i) { //looking for index of array where the biggest value is being stored
        if (max >= numbers[i]) {
            printf("Array number %d; Index: %ld; Address: %p; Value %d\n",
                   i, max - numbers[i], (void *) &max, *max);
            break;
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < lengths[i]; ++j) {
            printf("Index: %2d, Value: %3d\n", j, numbers[i][j]);
        }

        printf("This is end of array %d\n", i);
    }
}
