#include <stdio.h>

int main() {
    char binaryNumber[9];
    binaryNumber[8] = '\0';

    int decimalNumber = 10;

    do {
        printf("Provide correct number:\n");
        scanf("%d", &decimalNumber);
    } while (decimalNumber >= 128 || decimalNumber < -128);

    for (int i = 7; i >= 0; --i)
        binaryNumber[i] = (decimalNumber & (1u << (7u - i))) == 0 ? 48 : 49;

    printf("number  %d:  %s", decimalNumber, binaryNumber);
    return 0;
}
