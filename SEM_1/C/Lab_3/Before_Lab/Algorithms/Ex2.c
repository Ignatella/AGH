#include <stdio.h>
#include <memory.h>
#include <math.h>


int main() {
    char *bin = "00001010"; // "01001001";

    long number = 0;

    for (long i = (long) strlen(bin) - 1; i >= 0; --i)
        number += bin[i] == 48 ? 0 : (long) powl(2, (long) strlen(bin) - i - 1);

    printf("%ld", number);
    return 0;
}
