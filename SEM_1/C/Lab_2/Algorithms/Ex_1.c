#include <stdio.h>

int main() {

    int number = 0;

    printf("Please, provide number:");
    scanf("%d",&number);

    for (int i = 0; i <= number; ++i) {
        for (int j = i; j < number - 1; ++j) {
            printf(" ");
        }

        for (int j = number; j >-1; --j) {
            if(i == j && i != number) {
                printf(" ");
            }
            printf("%d", j);
        }
        printf("\n");
    }
    
    return 0;
}
