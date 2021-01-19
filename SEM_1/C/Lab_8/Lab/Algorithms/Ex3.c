#include <string.h>
#include <stdio.h>

int main(int argc, char **argv) {
    //
    // Zlożoność: O(13 + 3A) =... O(3A) =... O(A)
    //
    char *str1 = argv[1]; // O(3) // Niech len = A
    char *str2 = argv[2]; // O(3) // Niech len = B

    printf("Before str1: %s, str2: %s\n", str1, str2); // O(1)

    char tmp[strlen(argv[1])]; // 2 + A
    strcpy(tmp, argv[1]); // A

    str1 = str2; // O(1)
    str2 = tmp; // O(1)

    printf("After str1: %s, str2: %s\n", str1, str2); // O(1)
    return 0; // O(1)
}
