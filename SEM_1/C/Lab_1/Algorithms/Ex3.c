#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int n = 20;
    int from = 118;
    int to = 286;
    int min = to + 1, max = from - 1;
    double arMean = 0;


    for (int i = 0; i < n; ++i) {

        int num = from + rand()%(to-from+1);

        if (num < min) {
            min = num;
        }

        if (num > max) {
            max = num;
        }

        arMean += num / n;
    }

    printf("Max: %d; Min: %d; Arithmetic mean: %.5f", max, min, arMean);
    
    return 0;
}
