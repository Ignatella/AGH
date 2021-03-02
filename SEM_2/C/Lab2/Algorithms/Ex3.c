#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LowerBound 0
#define UpperBound 100
#define GuessCount 1000

int randInt(int lowerBound, int upperBound) {
    return lowerBound + (rand() % (upperBound - lowerBound + 1));
}

void seedRnd() {
    srand(time(NULL));
}

int guessTheValue() {
    int i = 1;
    for (
            int lb = LowerBound,
                    up = UpperBound,
                    rnd = randInt(lb, up),
                    cur = randInt(lb, up);
            cur != rnd; ++i) {

        if (cur < rnd)
            lb = cur;
        if (cur > rnd)
            up = cur;

        cur = randInt(lb, up);
    }

    return i;
}

int main() {
    seedRnd();
    int res = 0;
    for (int i = 0; i < GuessCount; ++i) {
        res += guessTheValue();
    }
    printf("Result:\n");
    printf("%f\n", (float) res / (float) GuessCount);

    printf("End of program.\n");
    return 0;
}
