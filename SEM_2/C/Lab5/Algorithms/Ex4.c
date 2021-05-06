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
