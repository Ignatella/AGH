#include <stdio.h>
#include <math.h>

double ff(double x) {
    return 1 + x * x;
}

double xx(double x) {
    return 1 / x / x;
}

int main(void) {
    double (*p[])(double) = {sin, cos, ff, xx, NULL};
    double (**q)(double) = p;
    for (int i = 0; i < 20; i += 2) {
        printf("Parameter: %d\n", i);
        while (*q) {
            printf("Function index: %d, result: %7.3f\n", (int) (q - p), (*(*q))(i));
            ++q;
        }
        q = p;
        printf("===== o =====\n");
    }

    printf("End of program.\n");
    return 0;
}
