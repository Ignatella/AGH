#include <stdio.h>

int main() {

    int num1[3] = {9, 9, 9};
    int num2[3] = {9, 1, 1};

    int extra = 0;
    for (int i = 2; i >= 0; --i) {
        extra = extra + num1[i] + num2[i];
        num2[i] = extra % 10;
        extra = extra / 10;
    }


    for (int i = 0; i < 3; ++i) {
        if (i == 0 && extra > 0) {
            printf("%d", extra);
        }
        printf("%d", num2[i]);
    }

    return 0;
}
