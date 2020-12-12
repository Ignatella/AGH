#include <stdio.h>

char toLower(char);

int main() {
    char str[] = "Hello Beautiful WORLD";
    printf("Before: %s\n", str);

    int i = 0;
    while (*(str + i) != '\0') {
        if (*(str + i) > 64 && *(str + i) < 91)
            *(str + i) = toLower(*(str + i));

        i++;
    }

    printf("After: %s\n", str);
    return 0;
}

char toLower(char letter) {
    return letter + 32;
}
