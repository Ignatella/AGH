#include <stdio.h>

int main() {
    char binaryNumber[9];
    binaryNumber[8] = '\0';

    unsigned int decimalNumber = 18;

    if ((decimalNumber & ~255u) != 0) {
        printf("The number %d can not be written in 8 bits", decimalNumber);
        return 0;
    }

    for (int i = 7; i >= 0; --i) {
        //binaryNumber[i] = (decimalNumber & (1u << (7u - i))) == 0 ? 48 : 49;

        if ((decimalNumber & (1u << (7u - i))) == 0) {
            binaryNumber[i] = 48;
        } else {
            binaryNumber[i] = 49;
        }
    }

    printf("number %d:  %s", decimalNumber, binaryNumber);

    return 0;
}
