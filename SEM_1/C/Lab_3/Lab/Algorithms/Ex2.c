#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
    double numbers[10];
    double upperBound = 100;
    double lowerBound = -100;

    srand(time(NULL));

    for (int i = 0; i < 10; ++i) {
        double randDouble = (double) rand() / RAND_MAX;
        numbers[i] = lowerBound + randDouble * (upperBound - lowerBound);
        printf("element[%d]= %+6.2f \n", i, numbers[i]);
    }

    for (int i = 0; i < 5; ++i) {
        double tmp = numbers[i];
        numbers[i] = numbers[9 - i];
        numbers[9 - i] = tmp;
    }

    printf("\nAfter swap:\n\n");

    for (int i = 0; i < 10; ++i)
        printf("element[%d]= %-+6.2f \n", i, numbers[i]);

    return 0;
}
