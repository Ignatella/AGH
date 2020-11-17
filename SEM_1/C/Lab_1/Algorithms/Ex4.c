#include <stdio.h>
#include <stdlib.h>


int main() {
    int val;
    int banknotes[2][3] = {20, 10, 5};
    int sum = 0;
    printf("Please provide price you wanna pay:\n");
    scanf_s("%d", &val);

    while (sum < val){
        for (int i = 0; i < 3; ++i) {
            if(val - sum >= banknotes[0][i]) {
                sum += banknotes[0][i];

                banknotes[1][i]++;
                break;
            }
            else {
                if(i == 2) {
                    for (int k = 0; k < 3; ++k) {
                        printf("You give %d banknotes with a value of %d \n", banknotes[1][k], banknotes[0][k]);
                    }
                    printf("And give more %d \n", abs(val - sum));
                    return 0;
                }
            }
        }
    }

    if(val == sum){
        for (int k = 0; k < 3; ++k) {
            printf("You give %d banknotes with a value of %d \n", banknotes[1][k], banknotes[0][k]);
        }
    }
    return 0;
}
