#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    double result;

    switch (*argv[3]) {
        case 42:
            result = a * b;
            break;
        case 47:
            result = a / (double) b;
            break;
        case 43:
            result = a + b;
            break;
        case 45:
            result = a - b;
            break;
        case 37:
            result = a % b;
            break;
        default: {
            printf("You have provided incorrect operation");
            exit(1);
        }
    }

    printf("%d %c %d = %.2f",a, *argv[3], b, result);
    return 0;
}