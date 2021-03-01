#include <stdio.h>

int main() {
    double x, *px, *py;

    // region Block 1
    printf("Address x: %p, address px: %p, address py: %p\n", &x, &px, &py);
    printf("Val x: %f, val px: %p, val py: %p\n", x, px, py);
    printf("Val *px: %f\n", *px);
    printf("px != NULL : %d\n", px != NULL);
    printf("Val *py: %f\n", *py);
    printf("py != NULL : %d\n", py != NULL);
    // endregion

    printf("\n");

    printf("Provide x value: \n");
    scanf("%lf", &x);

    printf("\n");

    // region Block 2
    printf("Address x: %p, address px: %p, address py: %p\n", &x, &px, &py);
    printf("Val x: %f, val px: %p, val py: %p\n", x, px, py);
    printf("Val *px: %f\n", *px);
    printf("px != NULL : %d\n", px != NULL);
    printf("Val *py: %f\n", *py);
    printf("py != NULL : %d\n", py != NULL);
    // endregion

    px = &x;

    // region Block 2
    printf("Address x: %p, address px: %p, address py: %p\n", &x, &px, &py);
    printf("Val x: %f, val px: %p, val py: %p\n", x, px, py);
    printf("Val *px: %f\n", *px);
    printf("px != NULL : %d\n", px != NULL);
    printf("Val *py: %f\n", *py);
    printf("py != NULL : %d\n", py != NULL);
    // endregion

    py = px;

    // region Block 2
    printf("Address x: %p, address px: %p, address py: %p\n", &x, &px, &py);
    printf("Val x: %f, val px: %p, val py: %p\n", x, px, py);
    printf("Val *px: %f\n", *px);
    printf("px != NULL : %d\n", px != NULL);
    printf("Val *py: %f\n", *py);
    printf("py != NULL : %d\n", py != NULL);
    // endregion

    *py = 5;

    // region Block 2
    printf("Address x: %p, address px: %p, address py: %p\n", &x, &px, &py);
    printf("Val x: %f, val px: %p, val py: %p\n", x, px, py);
    printf("Val *px: %f\n", *px);
    printf("px != NULL : %d\n", px != NULL);
    printf("Val *py: %f\n", *py);
    printf("py != NULL : %d\n", py != NULL);
    // endregion

    return 0;
}
