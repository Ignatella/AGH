#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
    int n = 10;
    int limitCounts[10] = { 0 };
    double upperBound = 9.9999;

    printf("Please, provide number of loops: ");
    scanf("%d", &n);

    srand(time(NULL));

    for (int i = 0; i < n ; ++i)
        limitCounts[(int)(upperBound * (double) rand() / RAND_MAX)]++;

    for (int i = 0; i < 10; ++i)
        printf("Limit [%d, %2d): %d\n", i, i + 1, limitCounts[i]);

    return 0;
}
