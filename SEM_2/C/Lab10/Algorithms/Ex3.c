#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArr(size_t size, const int arr[size]) {
    for (int i = 0; i < size; ++i)
        printf("%d", arr[i]);
}

int *extendArr(size_t len, size_t curLen, const int *arr) {
    int *result = calloc(len, sizeof(int));
    for (int i = 0; i < curLen; ++i)
        result[len - 1 - i] = arr[curLen - 1 - i];

    for (int i = 0; i < len - curLen; ++i)
        result[i] = 0;

    return result;
}

int *add(size_t len1, const int *num1, size_t len2, const int *num2, size_t *resultLen) {
    size_t biggest = len1 > len2 ? len1 : len2;
    int *n1 = extendArr(biggest, len1, num1);
    int *n2 = extendArr(biggest, len2, num2);

    int *result = calloc(biggest + 1, sizeof(int));

    int extra = 0;
    for (int i = 0; i < biggest; ++i) {
        int cur = n1[biggest - 1 - i] + n2[biggest - 1 - i] + extra;
        extra = cur / 10;
        result[biggest - i] = cur % 10;
    }

    result[0] = extra;
    *resultLen = biggest + 1;

    free(n1);
    free(n2);
    return result;
}

int *sub(size_t len1, const int *num1, size_t len2, const int *num2, size_t *resultLen) {
    size_t biggest = len1 > len2 ? len1 : len2;
    int *n1 = extendArr(biggest, len1, num1);
    int *n2 = extendArr(biggest, len2, num2);

    int *result = calloc(biggest, sizeof(int));

    int extra = 0;
    for (int i = 0; i < biggest; ++i) {
        int cur = n1[biggest - 1 - i] - n2[biggest - 1 - i] - extra;
        extra = 0;
        if (cur < 0) {
            extra++;
            cur += 10;
        }

        result[biggest - 1 - i] = cur;
    }
    *resultLen = biggest;

    free(n1);
    free(n2);
    return result;
}

int main() {
    size_t resLen;

    // region 1
    size_t size1 = 3;
    int num1[3] = {1, 9, 7};
    size_t size2 = 3;
    int num2[3] = {1, 8, 2};

    int *res = add(size1, num1, size2, num2, &resLen);
    printArr(size1, num1);
    printf("+");
    printArr(size2, num2);
    printf("=");
    printArr(resLen, res);
    printf("\n");

    free(res);
    // endregion

    // region 2
    size_t size3 = 3;
    int num3[3] = {2, 8, 7};
    size_t size4 = 3;
    int num4[3] = {1, 9, 9};

    res = sub(size3, num3, size4, num4, &resLen);
    printArr(size3, num3);
    printf("-");
    printArr(size4, num4);
    printf("=");
    printArr(resLen, res);
    printf("\n");

    free(res);
    // endregion

    res = NULL;

    printf("End of program!\n");
    return 0;
}
