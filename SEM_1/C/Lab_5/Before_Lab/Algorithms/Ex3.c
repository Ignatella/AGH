#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#define lowerBound 97
#define upperBound 122
#define stringSize 10

char randLowerLetter() {
    return rand() % (upperBound - lowerBound + 1) + lowerBound;
}

int main() {
    srand(time(NULL));

    char letters[stringSize + 1];
    letters[stringSize] = '\0';

    char randLetter = randLowerLetter();

    for (int i = 0; i < stringSize; ++i)
        *(letters + i) = randLowerLetter();

    char *address;
    int firstAppearance = -1;
    int count = 0;
    int index = 0;

    do {
        address = strchr(letters + index, randLetter);
        if (address != NULL) {
            if (firstAppearance == -1)
                firstAppearance = address - letters;
            count++;
        }

        index = address - letters + 1;
    } while (address != NULL);


    if (count <= 0)
        printf("There is no letter %c in string: %s\n", randLetter, letters);
    else {
        printf("There is letter %c in string %s, Count %d, Index %d\n",
               randLetter, letters, count, firstAppearance);
    }
}
