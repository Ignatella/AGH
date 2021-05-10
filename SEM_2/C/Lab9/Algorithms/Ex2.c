#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LowerBound -5
#define UpperBound 5

typedef struct num {
    char type;
    union {
        double numDouble;
        int numInt;
    };
} num;

int rndInt(int lowerBound, int upperBound) {
    return lowerBound + rand() % (upperBound - lowerBound + 1);
}

double randDouble(double lowerBound, double upperBound) {
    return lowerBound + rand() / (float) RAND_MAX * (upperBound - lowerBound);
}

num *createNum(int count) {
    num *node = calloc(count, sizeof(num));
    if (node == NULL)
        exit(EXIT_FAILURE);
    return node;
}

void seedArr(int size, num *arr) {
    for (int i = 0; i < size; ++i) {
        int iOrD = rndInt(0, 1);
        if (iOrD == 1) {
            arr[i].type = 'd';
            arr[i].numDouble = randDouble(LowerBound, UpperBound);
            continue;
        }

        arr[i].type = 'i';
        arr[i].numInt = rndInt(LowerBound, UpperBound);
    }
}

double avg(int size, num *arr) {
    double result = 0;
    for (int i = 0; i < size; ++i)
        result += arr[i].type == 'i' ? arr[i].numInt : arr[i].numDouble;
    return result / (double) size;
}

void printNum(num *st) {
    printf("Struct: \n");
    printf("Type: %c\n", st->type);

    if (st->type == 'i')
        printf("Number: %d\n", st->numInt);
    else
        printf("Number: %f\n", st->numDouble);
    printf("\n");
}

void printNumArray(int size, num *arr) {
    for (int i = 0; i < size; ++i)
        printNum(&arr[i]);
}

void seedRand() {
    srand(time(NULL));
}

int numCmp(const void *first, const void *second) {
    num *f = (num *) first;
    num *s = (num *) second;

    if (f->type != s->type) {
        if (f->type == 'i')
            return -1;
        return 1;
    }

    if (f->type == 'i')
        return f->numInt - s->numInt;

    if (f->numDouble > s->numDouble)
        return -1;

    return 1;
}

void sortNumArr(int size, num *arr) {
    qsort(arr, size, sizeof(num), numCmp);
}

int main() {
    seedRand();

    int size = 100;

    num *arr = createNum(size);
    seedArr(size, arr);
//    printf("Before:\n\n");
//    printNumArray(size, arr); // commented because of huge number of output


    printf("\n\n\nAfter:\n\n\n");
    sortNumArr(size, arr);
    printNumArray(size, arr);

    printf("Average: %f\n", avg(size, arr));

    free(arr);
    arr = NULL;

    printf("End of program.\n");
    return 0;
}
