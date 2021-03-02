#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define LowerBound 10
#define UpperBound 35

int randInt(int lowerBound, int upperBound);

int sum(const int *fromPtr, const int *toPtr);

void seedRand();

int main() {
    seedRand();
    int array[N];

    int *p = NULL;

    for (p = array; p < array + N; ++p) {
        *p = randInt(LowerBound, UpperBound);
        printf("p[%d]=%d\n", (int) (p - array), *p);
    }

    printf("\n");

    int s = sum(array, array + N / 2);

    printf("Sum (from 0 to n/2): %d\n", s);
    printf("End of program.\n");
    return 0;
}

void seedRand() {
    srand(time(NULL));
}

int randInt(int lowerBound, int upperBound) {
    return lowerBound + (rand() % (upperBound - lowerBound + 1));
}

int sum(const int *fromPtr, const int *toPtr) {
    int result = 0;
    do {
        result += *fromPtr;
        fromPtr++;
    } while (fromPtr < toPtr);

    return result;
}
