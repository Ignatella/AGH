#include <stdio.h>

int main() {

    char a = 'A';
    char letter = 'A';

    printf("Please, provide a letter:");
    scanf("%c",&letter);

    for (int i = (int)letter; i >= a; --i) {

        for (int j = i; j < letter; ++j)
            printf("  ");

        for (int j = a; j < i; ++j)
            printf("%c ", j);

        for (int j = i; j >= a; --j)
            printf("%c ", j);

        printf("\n");
    }

    return 0;
}
