#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
    if(argc != 4)
    {
        printf("Please, provide full arguments list");
        exit(1);
    }

    for (int i = 0; i < strlen(argv[1]); ++i) {
        if(argv[1][i] < 48 || argv[1][i] > 57) {
            printf("Please, provide integers as arguments.\n");
            exit(1);
        }
    }

    for (int i = 0; i < strlen(argv[2]); ++i) {
        if(argv[2][i] < 48 || argv[2][i] > 57) {
            printf("Please, provide integers as arguments.\n");
            exit(1);
        }
    }
    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    double result;

    switch (*argv[3]) {
        case 42:
            result = a * b;
            break;
        case 47: {
            if(b == 0) {
                printf("Division by 0 is not allowed.");
                exit(1);
            }
            result = a / (double) b;
            break;
        }
        case 43:
            result = a + b;
            break;
        case 45:
            result = a - b;
            break;
        case 37: {
            if(b == 0) {
                printf("Division by 0 is not allowed.");
                exit(1);
            }
            result = a % b;
            break;
        }
        default: {
            printf("You have provided incorrect operation");
            exit(1);
        }
    }

    printf("%d %c %d = %.2f",a, *argv[3], b, result);
    return 0;
}
