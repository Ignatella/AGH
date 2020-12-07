#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define lowerBound -100
#define upperBound 100

void sortEvenAndOdds(int *numbers, int arrLength) {
    int *firstEl = numbers;
    int *lastEl = numbers + arrLength - 1;

    while (firstEl < lastEl) {
        int a = (abs(*firstEl % 2)) + ((abs(*lastEl % 2)) == 0 ? 0 : 2);
        //first- last- => 3 // first and last are odd
        //first+ last- => 2 // first is even and last is odd
        //first- last+ => 1 // first is odd and last is even
        //first+ last+ => 0 // first and last are even

        switch (a) {
            case 3:
                lastEl--;
                break;
            case 2:
                firstEl++;
                lastEl--;
                break;
            case 1: {
                int tmp = *lastEl;
                *lastEl = *firstEl;
                *firstEl = tmp;
                firstEl++;
                lastEl--;
                break;
            }
            case 0:
                firstEl++;
        }
    }
}

void fillArray(int *array, int length) {
    for (int i = 0; i < length; ++i)
        array[i] = lowerBound + rand() % (upperBound - lowerBound + 1);
}

void printArray(const int *array, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%2d", *(array + i));
    }
}

int main() {
    srand(time(NULL));

    int size = 10;
    printf("Please, provide size of the array:\n");
    scanf("%d", &size);

    int numbers[size];
    fillArray(numbers, size);

    printf("Before:\n");
    for (int i = 0; i < size; ++i) {
        printf("%3d\n", numbers[i]);
    }

    sortEvenAndOdds(numbers, size);

    printf("After:\n");
    for (int i = 0; i < size; ++i) {
        printf("%3d\n", numbers[i]);
    }
}
