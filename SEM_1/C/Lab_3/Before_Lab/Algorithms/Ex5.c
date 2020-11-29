#include <stdio.h>

int bitCount(int number) {
    int count = 0;
    int k = 0;
    do {
        if ((number & (1u << k)) != 0)
            count++;

        k++;
    } while (k < sizeof(int) * 8);

    return count;
}

int main() {
    printf("%d\n", bitCount(7));
    return 0;
}