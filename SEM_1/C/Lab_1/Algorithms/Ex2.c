#include <stdio.h>

int main() {
    int a = -5;
    int b = 98;
    int count = 0;
    for (int i = a; i < b + 1; ++i) {
        if(i % 4 == 0) {
            printf("%d \n", i);
            count++;
        }
    }

    printf("Total: %d", count);

    return 0;
}
