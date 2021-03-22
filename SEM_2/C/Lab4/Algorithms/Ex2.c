#include <stdio.h>

#define Rows 4
#define Cols 2

void fillArray(int x, int y, int (*arr)[y]) {
    int curr = 4;
    for (int i = 0; i < x * y; ++i) {
        *(*(arr) + i) = curr;
        curr += 2;
    }
}

void printArrayPtrsNot(int x, int y, int (*arr)[y]) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j)
            printf("x: %d, y: %d, addr: %p, value: %2d     ", i, j, *(arr + i) + j, *(*(arr + i) + j));
        printf("\n");
    }
    printf("\n");
}

void printArrayBracketNot(int x, int y, int (*arr)[y]) {
    for (int i = 0; i < x; ++i) {
        for (int j = 0; j < y; ++j)
            printf("x: %d, y: %d, addr: %p, value: %2d     ", i, j, arr[i] + j, *(arr[i] + j));
        printf("\n");
    }
    printf("\n");
}

void printArrayInLine(int x, int y, int (*arr)[y]) {
    for (int i = 0; i < x * y; ++i) {
        printf("x: %d,  addr: %p, value: %2d\n", i, *arr + i, *(*arr + i));
    }
    printf("\n");
}


int main() {
    int arr[Rows][Cols];

    fillArray(Rows, Cols, arr);

    // region Printings
    printf("1) arr[0]. Value is a pointer to the first element in first row.\n");
    printf("arr[0]: value = %p, address = %p\n", arr[0], &arr[0]);
    printf("2) arr[0] + 1. Value is a pointer to the second element in first row.\n");
    printf("arr[0] + 1: value = %p, address = CAN NOT BE WRITTEN\n", arr[0] + 1);
    printf("3) arr. Value is a pointer to the 'array head' the first row.\n");
    printf("arr. value = %p, address = %p\n", arr, &arr);
    printf("4) arr + 1. Value is a pointer to second row\n");
    printf("arr + 1: value = %p, address = CAN NOT BE WRITTEN\n", arr + 1);
    printf("5) *arr. Value is a pointer to the first element in first row. "
           "[the first column] [equal to arr[0]]\n");
    printf("*arr: value: %p, address: %p\n", *arr, arr);
    printf("6) *arr + 1. Value is a pointer to the second element in first row. "
           "[the second column] [equal to arr[0] + 1]\n");
    printf("*arr + 1: value = %p, address = CAN NOT BE WRITTEN\n", *arr + 1);
    printf("7) *(arr + 1). Value is a pointer to first column of second row.\n");
    printf("*(arr + 1): value = %p, address = %p\n", *(arr + 1), arr + 1);

    printf("\n");
    // endregion

    // region All known printings [wsk_2D ptr region]
    int (*wsk_2D)[] = arr;

    printf("TUTAJ 3 WARIANTY WYPISANIA, BO MOZNA ROZNIE TRAKTOWAC: *(arr + i) + j");
    printf("Print array *(*(arr + i) + j) notation:\n");
    printArrayPtrsNot(Rows, Cols, wsk_2D);

    printf("Print array *(arr[i] + j) notation:\n");
    printArrayBracketNot(Rows, Cols, wsk_2D);

    printf("Print in line *(*arr + i) notation:\n");
    printArrayInLine(Rows, Cols, wsk_2D);

    // endregion

    // region ws_T_2D ptr
    int (*ws_T_2D)[] = arr;
    printf("ws_T_2D ptr: \n");
    printArrayPtrsNot(Rows, Cols, ws_T_2D);
    printf("Address ws_T_2D = %p, size: %lu\n", ws_T_2D, sizeof(ws_T_2D));
    printf("\n");
    // endregion

    // region ws_T_1D

    int *ws_T_1D = *(arr + 2);
    printf("ws_T_1D ptr: \n");
    printf("Address ws_T_1D = %p, size: %lu\n", ws_T_1D, sizeof(ws_T_1D));
    printf("\n");

    printf("Row 2: \n");
    for (int i = 0; i < Cols; ++i)
        printf("x = 2, y = %d, address = %p, value = %d     ", i, ws_T_1D + i, *(ws_T_1D + i));
    printf("\n\n");

    printf("ws_T_1D ptr. All Rows: \n");
    for (int i = 0; i < Rows; ++i) {
        ws_T_1D = *(arr + i);
        for (int j = 0; j < Cols; ++j)
            printf("x = %d, y = %d, address = %p, value = %d     ", i, j, ws_T_1D + j, *(ws_T_1D + j));
        printf("\n");
    }

    // endregion

    printf("End of program.\n");
    return 0;
}
