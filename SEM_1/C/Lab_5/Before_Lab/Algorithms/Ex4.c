#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {
    char *str1 = argv[1];
    char *str2 = argv[2];

    printf("Before str1: %s, str2: %s\n", str1, str2);

    char tmp[strlen(argv[1])];
    strcpy(tmp, argv[1]);

    str1 = str2;
    str2 = tmp;

    printf("Before str1: %s, str2: %s\n", str1, str2);
    return 0;
}
