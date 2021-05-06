#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randInt(int lowerBound, int upperBound) {
    return lowerBound + rand() % (upperBound - lowerBound + 1);
}

void seedRnd() {
    srand(time(NULL));
}

float (*create2DArray(int x, int y))[] {
    float (*created)[] = calloc(x * y, sizeof(float));
    if (created == NULL)
        exit(EXIT_FAILURE);
    return created;
}

void fillArray(int lowerBound, int upperBound, int size, float *arr) {
    for (int i = 0; i < size; ++i)
        arr[i] = (float) randInt(lowerBound, upperBound);
}

void printArray(int x, int y, float (*arr)[y]) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j)
            printf("%7.3f  ", arr[i][j]);
        printf("\n");
    }
}

void swap(float *a, float *b) {
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

int partition(int start, int end, float *arr) {
    float x = arr[end];
    int i = start - 1;
    for (int j = start; j < end; ++j) {
        if (arr[j] <= x) {
            i++;
            swap(arr + i, arr + j);
        }
    }

    swap(arr + i + 1, arr + end);
    return i + 1;
}

void quickSort(int start, int end, float *arr) {
    if (start < end) {
        int q = partition(start, end, arr);
        quickSort(start, q - 1, arr);
        quickSort(q + 1, end, arr);
    }
}

float sum(int size, const float *arr) {
    float res = 0;
    for (int i = 0; i < size; ++i)
        res += arr[i];

    return res;
}

void normalize(int size, float *arr) {
    float s = sum(size, arr);

    for (int i = 0; i < size; ++i)
        arr[i] /= s;
}

int main(int argc, char *argv[]) {
    seedRnd();
    if (argc < 5)
        exit(EXIT_FAILURE);

    int a = atoi(argv[1]), b = atoi(argv[2]);
    int lowerBound = atoi(argv[3]), upperBound = atoi(argv[4]);

    if (a == 0 || b == 0)
        exit(EXIT_FAILURE);

    float (*array)[] = create2DArray(a, b);

    printf("Initial state:\n");
    fillArray(lowerBound, upperBound, a * b, *array);
    printArray(a, b, array);

    printf("\nAfter sort:\n");

    quickSort(0, a * b - 1, *array);
    printArray(a, b, array);

    printf("\nAfter normalization:\n");

    normalize(a * b, *array);
    printArray(a, b, array);

    printf("\nSum of table: %f\n", sum(a * b, *array));

    free(array);
    array = NULL;

    printf("\nEnd of program.\n");
    return 0;
}
