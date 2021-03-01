#include <stdio.h>

int main() {
    char text[] = "Ile i ktore z samoglosek snajdziesz w tym zadaniu ?";

    char *ptr = text;
    char keys[6];
    keys[0] = 'a';
    keys[1] = 'e';
    keys[2] = 'i';
    keys[3] = 'o';
    keys[4] = 'u';
    keys[5] = 'y';

    int results[7] = {0};

    while (*ptr != '\0') {
        switch (*ptr) {
            case 'A':
            case 'a':
                results[0]++;
                break;
            case 'E':
            case 'e':
                results[1]++;
                break;
            case 'I':
            case 'i':
                results[2]++;
                break;
            case 'O':
            case 'o':
                results[3]++;
                break;
            case 'U':
            case 'u':
                results[4]++;
            case 'Y':
            case 'y':
                results[5]++;
                break;
            case ' ' :
                results[6]++;
                break;
        }
        ptr++;
    }

    for (int i = 0; i < 6; ++i)
        printf("%c ---> count: %d\n", keys[i], results[i]);

    printf("Vowels ---> count: %d\n", results[0] + results[1] + results[2] + results[3] + results[4] + results[5]);
    printf("Words ---> count: %d\n", results[6]); //Gdyby pytajnik "dotykal" slowa, musielibysmy odjac 1
    return 0;
}
