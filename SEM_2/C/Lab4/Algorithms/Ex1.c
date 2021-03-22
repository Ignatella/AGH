#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LowerBoundSize 5
#define UpperBoundSize 20
#define LowerBound 0
#define UpperBound 10


int rndInt(int lowerBound, int upperBound) {
    return lowerBound + rand() % (upperBound - lowerBound + 1);
}

void seedRnd() {
    srand(time(NULL));
}

void printArray(int size, const int arr[size]) {
    for (int i = 0; i < size; ++i)
        printf("%d ", *(arr + i));
    printf("\n");
}

void fillArrSorted(int size, int *arr) {
    for (int i = 0, l = LowerBound, u = UpperBound; i < size; ++i) {
        int rnd = rndInt(l, u);
        if (rnd > l)
            l = rnd;

        *(arr + i) = rnd;
    }
}

int *merge(int s1, int s2, const int arr1[s1], const int arr2[s2], int *resLen) {
    int *res = calloc(s1 + s2, sizeof(int));
    int i = 0;
    for (int j = 0, k = 0; j < s1 || k < s2;) {
        if ((j < s1) && (k > s2 - 1 || arr1[j] <= arr2[k])) {
            if ((i == 0) || (i > 0 && res[i - 1] != arr1[j])) {
                res[i] = arr1[j];
                i++;
            }

            j++;
            continue;
        }

        if ((k < s2) && (j > s1 - 1 || arr2[k] < arr1[j])) {
            if ((i == 0) || (i > 0 && res[i - 1] != arr2[k])) {
                res[i] = arr2[k];
                i++;
            }

            k++;
            continue;
        }
    }
    res = realloc(res, sizeof(int) * (i));
    *resLen = i;
    return res;
}

int main() {
    seedRnd();
    int s1 = rndInt(LowerBoundSize, UpperBoundSize), s2 = rndInt(LowerBoundSize, UpperBoundSize), resLen = 0;
    int *arr1 = calloc(s1, sizeof(int));
    int *arr2 = calloc(s2, sizeof(int));
    fillArrSorted(s1, arr1);
    fillArrSorted(s2, arr2);

    int *res = merge(s1, s2, arr1, arr2, &resLen);

    int *arr[3];
    arr[0] = arr1;
    arr[1] = arr2;
    arr[2] = res;

    printArray(s1, *arr);
    printArray(s2, *(arr + 1));
    printArray(resLen, *(arr + 2));

    free(res);
    free(arr1);
    free(arr2);
    printf("End of program.\n");
    return 0;
}
