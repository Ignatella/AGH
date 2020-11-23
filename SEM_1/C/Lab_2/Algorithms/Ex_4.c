#include <stdio.h>

int main() {

    double eps = 0.00001;

    printf("Please, provide eps:");
    scanf("%lf",&eps);

    if(eps <= 0 || eps >= 1) {
        printf("Please, provide eps following such rule: 0 < eps < 1");
        return 1;
    }

    double sum = 0;
    double n = 1;

    while (1/n >= eps){
        sum+=1/n;
        n++;
    }

    printf("Sum is: %lf\n" , sum);

    return 0;
}
