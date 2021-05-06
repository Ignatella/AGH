#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    printf("Argument count: %d\n", argc);

    printf("Arguments:\n");
    for (int i = 0; i < argc; ++i)
        printf("%d: %s\n", i, argv[i]);

    int firstArg = atoi(argv[1]);
    float secondArg = atof(argv[2]);

    if (firstArg == 0 || secondArg == 0) {
        printf("Invalid arguments.");
        exit(EXIT_FAILURE);
    }

    printf("Integer: %d, Float: %0.2f\n", firstArg, secondArg);

    printf("End of program.\n");
    return 0;
}
