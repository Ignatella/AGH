#include <stdio.h>

int main() {
    unsigned number = 29;

    unsigned int from = 2;
    int count = 3;

    unsigned result = 0;
    for (unsigned int i = 0; i < count; ++i)
        result |= (number & (1u << (from + i))) >> from;

    printf("%d", result);

    return 0;
}
