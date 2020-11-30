#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printArray(int *array, int length) {
    for (int i = 0; i < length; ++i) {
        printf("%d", array[i]);
    }
    printf("\n");
}

void addTwoNumbers(int *num1, int *num2, int length) {
    int extra = 0;
    for (int i = length - 1; i >= 0; --i) {
        extra = extra + num1[i] + num2[i];
        num2[i] = extra % 10;
        extra = extra / 10;
    }

    for (int i = 0; i < length; ++i) {
        if (i == 0 && extra > 0)
            printf("%d", extra);
        printf("%d", num2[i]);
    }
}

void fillArrayWIthRandomValues(int *array, int length) {
    for (int i = 0; i < length; ++i) {
        array[i] = rand() % 10;
    }
}

int main() {
    int length = 40;
    int num1[length];
    int num2[length];

    printf("Provide length of number: ");
    scanf("%d", &length);

    if (length < 40 || length > 90) {
        printf("40 < length < 90");
        return 0;
    }

    srand(time(NULL));

    fillArrayWIthRandomValues(num1, length);
    fillArrayWIthRandomValues(num2, length);

    printArray(num1, length);
    printArray(num2, length);

    addTwoNumbers(num1, num2, length);

    return 0;
}
