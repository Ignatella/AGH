#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int facRec(int x) {
    int static depth = 0;

    for (int i = 0; i < depth; ++i)
        printf(".");

    printf("Value x = %d, address = %p\n", x, &x);

    if (x == 1)
        return 1;

    ++depth;
    int result = x * facRec(x - 1);
    --depth;

    for (int i = 0; i < depth; ++i)
        printf(".");

    printf("Value x = %d, address = %p, curr_res = %d, address = %p\n", x, &x, result, &result);
    return result;
}

int facIter(int x) {
    int result = 1;
    for (; x > 0; --x)
        result *= x;

    return result;
}

int main(int argc, char **argv) { // "recursive" is default way to calculate
    if (argc < 3) {
        printf("Incorrect input, please, provide [number] (way to calc)\n");
        exit(EXIT_FAILURE);
    }

    int x = atoi(argv[1]);

    int a = strcmp("iterative", argv[2]);

    if (a == 0) {
        int resIter = facIter(x);
        printf("Iterative; result = %d\n", resIter);
        exit(EXIT_SUCCESS);
    }

    int resRec = facRec(x);
    printf("Recursive; result = %d\n", resRec);

    printf("End of program.\n");
    return 0;
}
