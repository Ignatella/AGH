#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <math.h>

#define LowerBound 0
#define UpperBound 10

typedef struct vector {
    double x;
    double y;
    double z;
} vector;

typedef struct vectorWrapper {
    vector *vec;
    double length;
    double delta;
} vectorWrapper;


void freeMem(int pointerCount, ...) {
    va_list params;
    va_start(params, pointerCount);
    for (int i = 0; i < pointerCount; i++) {
        void **res = va_arg(params,
                            void **);
        free(*res);
        *res = NULL;
    }
    va_end(params);
}

double randDouble(double lowerBound, double upperBound) {
    return lowerBound + rand() / (double) RAND_MAX * (upperBound - lowerBound);
}

vector *createVector(int size) {
    vector *res = calloc(size, sizeof(vector));
    if (res == NULL)
        exit(EXIT_FAILURE);
    return res;
}

vectorWrapper *createVectorWrapper(int size) {
    vectorWrapper *res = calloc(size, sizeof(vectorWrapper));
    if (res == NULL)
        exit(EXIT_FAILURE);
    return res;
}

vectorWrapper *createWrappersWithVectors(int size) {
    vectorWrapper *wrappers = createVectorWrapper(size);
    for (int i = 0; i < size; ++i)
        wrappers[i].vec = createVector(1);

    return wrappers;
}

double getVectorLen(vector *vec) {
    return sqrt(pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2));
}

void initializeVectorWrappers(int size, double delta, vectorWrapper *arr) {
    for (int i = 0; i < size; ++i) {
        (arr + i)->vec->x = randDouble(LowerBound, UpperBound);
        (arr + i)->vec->y = randDouble(LowerBound, UpperBound);
        (arr + i)->vec->z = randDouble(LowerBound, UpperBound);
        (arr + i)->length = getVectorLen((arr + i)->vec);
        (arr + i)->delta = delta;
    }
}

void printVectorWrapper(vectorWrapper *wrapper) {
    printf("=== Vector Wrapper ===\n");
    printf("Vector:\n");
    printf("   X = %f\n", wrapper->vec->x);
    printf("   Y = %f\n", wrapper->vec->y);
    printf("   Z = %f\n", wrapper->vec->z);
    printf("Length = %f\n", wrapper->length);
    printf("Delta = %f\n", wrapper->delta);

    printf("\n");
}

void printVectorWrappersArr(int size, vectorWrapper *arr) {
    for (int i = 0; i < size; ++i)
        printVectorWrapper(arr + i);
}

void seedRnd() {
    srand(time(NULL));
}

int vectorWrapperCmp(const void *first, const void *second) {
    vectorWrapper *f = (vectorWrapper *) first;
    vectorWrapper *s = (vectorWrapper *) second;
    if (f->length > s->length)
        return 1;

    if (f->length == s->length)
        return 0;

    return -1;
}

void sortVectorWrapperArr(int size, vectorWrapper *arr) {
    qsort(arr, size, sizeof(vectorWrapper), vectorWrapperCmp);
}


int vectorWrapperCmpForSearch(const void *num, const void *first) {
    double length = *(double *) num;
    vectorWrapper *f = (vectorWrapper *) first;
    double delta = f->delta;

    if (length > f->length && delta < 1 - f->length / length)
        return 1;

    if (length < f->length && delta < 1 - length / f->length)
        return -1;

    return 0;
}

vectorWrapper **lookForVectorWrapper(int fromI, int toI, double length, vectorWrapper *arr, int *resSize) {
    vectorWrapper **result = NULL;
    int resS = 0;

    vectorWrapper *p = bsearch(&length, arr + fromI,
                               toI - fromI, sizeof(vectorWrapper), vectorWrapperCmpForSearch);

    if (p == NULL) {
        *resSize = 0;
        return NULL;
    }

    int rLL, rLR;
    vectorWrapper **l = lookForVectorWrapper(fromI, (int) (p - arr), length, arr, &rLL);
    vectorWrapper **r = lookForVectorWrapper((int) (p - arr) + 1, toI, length, arr, &rLR);
    resS++;
    resS += rLL;
    resS += rLR;

    result = calloc(resS, sizeof(vectorWrapper *));
    if (result == NULL)
        exit(EXIT_FAILURE);

    for (int i = 0; i < rLL; ++i)
        result[i] = l[i];

    result[rLL] = p;

    for (int i = 0; i < rLR; ++i)
        result[rLL + 1 + i] = r[i];

    freeMem(2, &l, &r);

    *resSize = resS;
    return result;
}

int main(int argc, char **argv) {
    seedRnd();
    int size = 10;

    if (argc != 3)
        exit(EXIT_FAILURE);

    double len = atof(argv[1]);
    double delta = atof(argv[2]);

    vectorWrapper *arr = createWrappersWithVectors(size);
    initializeVectorWrappers(size, delta, arr);

    printf("BEFORE SORT:\n\n");
    printVectorWrappersArr(size, arr);

    sortVectorWrapperArr(size, arr);
    printf("\nAFTER SORT:\n\n");
    printVectorWrappersArr(size, arr);

    printf("\nRESULT:\n\n");

    int resLen = 0;
    vectorWrapper **res = lookForVectorWrapper(0, size, len, arr, &resLen);

    printVectorWrappersArr(resLen, *res);


    freeMem(1, &res);

    for (int i = 0; i < size; ++i)
        freeMem(1, &(arr + i)->vec);

    freeMem(1, &arr);

    printf("End of program.\n");
    return 0;
}
