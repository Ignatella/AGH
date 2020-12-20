#include <stdio.h>

int main() {
    int num = 17;
    printf("Please, ordinal number of the fibonacci number:\n");
    scanf("%d", &num);

    int prev = 1;
    int before_prev = 1;

    if (num == 1 || num == 2) {
        return prev;
    }

    for (int i = 0; i < num - 2; ++i) {
        int tmp = prev;
        prev = before_prev + prev;
        before_prev = tmp;
    }

    printf("%d", prev);
}


//region version 2; without additional variables))))
//int main() {
//    int num = 17;
//
//    int prev = 1;
//    int before_prev = 1;
//
//    if (num == 1 || num == 2) {
//        return prev;
//    }
//
//    for (int i = 0; i < num - 2; ++i) {
//        if (i % 2 == 0)
//            before_prev = prev + before_prev;
//        else prev = prev + before_prev;
//    }
//
//
//    if((num - 1 ) % 2 == 1) before_prev = prev;
//    printf("%d", before_prev);
//
//    return 0;
//}
//endregion