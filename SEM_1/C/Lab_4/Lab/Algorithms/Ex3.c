#include <stdio.h>

int bitCount(int number) {
    int count = 0;
    do {
        if ((number & 1) != 0)
            count++;

        number = (number >> 1);
    } while (number != 0);
    return count;
}

int main() {
    printf("%d\n", bitCount(154));
    return 0;
}
