#include <stdio.h>

int main () {
    unsigned int number = 1234567890;
    printf("Please, provide some unsigned int:\n");
    scanf("%u", &number);

    for (int i = 0; i < sizeof(number) * 8 / 2; ++i)
        number ^= (1 << (sizeof(number) * 8 - 1 - i));

    printf("Converted one: %u", number);
    return 0;
}