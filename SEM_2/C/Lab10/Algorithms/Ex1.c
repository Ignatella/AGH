#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define LowerBound -5
#define UpperBound 5

typedef struct complex {
    float real;
    float imaginary;

    void (*printComplex)(struct complex *cmx, struct _IO_FILE *stream);
} complex;

typedef struct complexWrapper {
    complex num;
    float mod;

    void (*printWrapper)(struct complexWrapper *wr, struct _IO_FILE *stream);
} complexWrapper;

float rndFloat(float lowerBound, float upperBound) {
    return lowerBound + (float) rand() / (float) RAND_MAX * (upperBound - lowerBound);
}

float findComplexMod(complex *cmx) {
    return sqrtf(powf(cmx->real, 2) + powf(cmx->imaginary, 2));
}

void printComplex(complex *cmx, struct _IO_FILE *stream) {
    fprintf(stream, "%.3f%+.3fi", cmx->real, cmx->imaginary);
}

void printWrapper(complexWrapper *wrapper, struct _IO_FILE *stream) {
    fprintf(stream, "|(");
    wrapper->num.printComplex(&wrapper->num, stream);
    fprintf(stream, ")| = %f\n", wrapper->mod);
}

void printWrapperArr(size_t size, complexWrapper arr[size], struct _IO_FILE *stream) {
    for (int i = 0; i < size; ++i)
        (arr + i)->printWrapper(arr + i, stream);
}

complexWrapper *createWrapperArr(size_t length) {
    complexWrapper *result = calloc(length, sizeof(complexWrapper));
    if (result == NULL)
        exit(EXIT_FAILURE);

    return result;
}

void seedWrapper(complexWrapper *target) {
    target->num.real = rndFloat(LowerBound, UpperBound);
    target->num.imaginary = rndFloat(LowerBound, UpperBound);
    target->num.printComplex = printComplex;
    target->mod = findComplexMod(&target->num);
    target->printWrapper = printWrapper;
}

void seedWrapperArr(size_t size, complexWrapper arr[size]) {
    for (int i = 0; i < size; ++i)
        seedWrapper(arr + i);
}

void seedRnd() {
    srand(time(NULL));
}

// region B

int cmpMod(const void *f, const void *s) {
    complexWrapper *fw = (complexWrapper *) f;
    complexWrapper *sw = (complexWrapper *) s;
    if (fw->mod > sw->mod)
        return 1;

    if (fw->mod < sw->mod)
        return -1;

    return 0;
}

void sortWrapperArr(size_t size, complexWrapper arr[size]) {
    return qsort(arr, size, sizeof(complexWrapper), cmpMod);
}
// endregion

int main(int argc, char *argv[]) {
    seedRnd();
    if (argc != 2)
        exit(EXIT_FAILURE);

    size_t size = atoi(argv[1]);
    if (size < 1)
        exit(EXIT_FAILURE);

    complexWrapper *arr = createWrapperArr(size);

    FILE *fp = fopen("/home/stud2020/0yermakovich/Downloads/what.txt", "w");

    seedWrapperArr(size, arr);
    fprintf(fp, "Before Sort:\n");
    fprintf(stdout, "Before Sort:\n");
    printWrapperArr(size, arr, fp);
    printWrapperArr(size, arr, stdout);

    fprintf(fp, "\n\nAfter sort by MOD\n");
    fprintf(stdout, "\n\nAfter sort by MOD\n");
    sortWrapperArr(size, arr);
    printWrapperArr(size, arr, fp);
    printWrapperArr(size, arr, stdout);

    fclose(fp);

    free(arr);
    arr = NULL;

    return 0;
}
