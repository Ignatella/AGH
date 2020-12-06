#include <stdio.h>

#define arrLength 14

void sortEvenAndOds(int *numbers){
    int *firstEl = numbers;
    int *lastEl = numbers + arrLength - 1;

    while (firstEl < lastEl) {

        int a = (*firstEl % 2) + (*lastEl % 2 == 0 ? 0 : 2);
        //first- last- => 3 // first and last are odd
        //first+ last- => 2 // first is even and last is odd
        //first- last+ => 1 // first is odd and last is even
        //first+ last+ => 0 // first and last are even

        switch (a) {
            case 3:
                lastEl--;
                break;
            case 2:
                firstEl++;
                lastEl--;
                break;
            case 1: {
                int tmp = *lastEl;
                *lastEl = *firstEl;
                *firstEl = tmp;
                firstEl++;
                lastEl--;
                break;
            }
            case 0:
                firstEl++;
        }
    }
}

int main() {
    int numbers[arrLength] = {8, 10, 1, 3, 5, 2, 3, 4, 5, 9, 24, 5, 6, 2};

    sortEvenAndOds(numbers);

    for (int i = 0; i < arrLength; ++i) {
        printf("%d\n", numbers[i]);
    }
}
