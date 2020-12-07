#include <stdio.h>
#include <memory.h>

int main() {
    char bin[] = "00001011";
    printf("Provide string of len 8.\n");
    scanf("%s", bin);
    printf("Yours string: %s\n", bin);

    if (strlen(bin) != 8) {
        printf("Wrong string provided.");
        return 1;
    }

    long number = 0;
    for (int i = 0; i < 8; ++i) {
        if (*(bin + i) != 48 && *(bin + i) != 49) {
            printf("Wrong binary number");
            return 1;
        }
        number |= ((*(bin + i) & (1u)) != 0) ? (1u << (8 - i - 1)) : 0;
    }
    printf("Yours number is: %ld", number);
    return 0;
}
