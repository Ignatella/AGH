#include <stdio.h>
#include <memory.h>

int main() {
    char arr[80];
    printf("Please, provide string\n");

    //region ScanF
    printf("ScanF():\n");
    scanf("%s", arr);
    printf("String after scanF():\n");
    printf("%s\n", arr);
    //endregion

    int c;
    while ((c = getchar()) != '\n') {} // discard // have to do this only after scanf
    memset(arr, 0, 80 * sizeof(char));
    printf("\n");

    //region Gets
    printf("Gets():\n");
    int ch;
    int i;
    for (i = 0; i < 80 && (ch = getc(stdin)) != '\n'; ++i)
        arr[i] = (char) ch;
    arr[i] = '\0';
    printf("String after Gets():\n");
    printf("%s\n", arr);
    //endregion

    memset(arr, 0, 80 * sizeof(char));
    printf("\n");

    //region FGets
    printf("FGets():\n");
    fgets(arr, 80, stdin);
    printf("String after FGets():\n");
    printf("%s", arr);
    //endregion

    printf("\n");

    printf("End of program.\n");
    return 0;
}
