#include <stdio.h>

int add(const int *a, const int *b) {
    return *a + *b;
}

int cmp(const int *a, const int *b) {
    if (*a <= *b)
        return *b;
    return *a;
}

int addOrCmp(int first, int second, int func(const int *a, const int *b)) {
    return func(&first, &second);
}
 

int main() {
    int a, b;

    printf("Please, provide value for first number:\n");
    scanf("%d", &a);
    printf("Please, provide value for second number:\n");
    scanf("%d", &b);

    int r1 = addOrCmp(a, b, add);

    printf("Sum of %d + %d = %d\n", a, b, r1);

    int r2 = addOrCmp(a, b, cmp);
    printf("Comparison between %d <> %d; result: %d is bigger\n", a, b, r2);
    printf("End of program.\n");
    return 0;
}
