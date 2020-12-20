#include <stdio.h>

int find_fibonacci_number(int number, int depth, int *callC) {
    ++*callC;

    printf("%d", depth);
    for (int i = 0; i < depth; ++i) {
        printf(".");
    }
    printf(", ");

    if (number == 1 || number == 0) {
        printf("Return f(%d), l = %d\n", number, *callC); // Zwracam f(%d), l = %d

        if (number == 0)
            return 0;

        return 1;
    }

    printf("Count f(%d) + f(%d), l = %d\n", number, number - 1, *callC); //Obliczam f(%d) + f(%d), l = %d
    int a = find_fibonacci_number(number - 1, ++depth, callC);
    int b = find_fibonacci_number(number - 2, depth, callC);

    return a + b;
}


int main() {
    int num = 6;
    int callCount = 0;
    int *callC = &callCount;

    int result = find_fibonacci_number(num, 0, callC);


    printf("Fibonacci(%d) = %d\n", num, result);
    return 0;
}