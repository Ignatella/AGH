#include <stdio.h>
#include <math.h>

int main() {

    int number;

    printf("Please, provide number:");
    scanf("%d",&number);

    double bound = sqrt(number);

    int dividersFound = 0;

    for (int i = 2; i <= bound; ++i) {
        if(number % i == 0){
            dividersFound = 1;
            printf("%d is divider of %d\n", i, number);
            printf("%d is divider of %d\n", number / i, number);
        }
    }

    if (dividersFound > 0) {
        printf("1 is divider of %d\n", number);
        printf("%d is divider of %d\n",number, number);
    }
    else  {
        printf("%d - number is first\n", number);
    }

    return 0;
}
