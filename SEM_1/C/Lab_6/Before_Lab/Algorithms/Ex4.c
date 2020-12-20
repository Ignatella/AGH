#include <stdio.h>

int find_fibonacci_number(int number, int depth, int *callC, int *fibonacci_nums) {
    ++*callC;
    if(*callC == 1) {
        fibonacci_nums[0] = 0;
        fibonacci_nums[1] = 1;
    }

    printf("%d", depth);
    for (int i = 0; i < depth; ++i) {
        printf(".");
    }
    printf(", ");

    if (fibonacci_nums[number] > -1) {
        printf("Return f(%d), l = %d\n", number, *callC); //Zwracam
        return fibonacci_nums[number];
    }

    printf("Count f(%d) + f(%d), l = %d\n", number, number - 1, *callC); //Obliczam

    int a = find_fibonacci_number(number - 1, ++depth, callC, fibonacci_nums);
    int b = find_fibonacci_number(number - 2, depth, callC, fibonacci_nums);

    fibonacci_nums[number] = a + b;

    return a + b;
}


int main() {
    int num = 6;
    int callCount = 0;
    int *callC = &callCount;
    int fibonacci_nums[num + 1];
    for (int i = 0; i < num + 1; ++i)
        fibonacci_nums[i] = -1;

    int result = find_fibonacci_number(num, 0, callC, fibonacci_nums);
    printf("Fibonacci(%d) = %d\n", num, result);

    return 0;
}
