#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int is_first_num(int num) {
    num = abs(num); // not 100% right, first num can not be negative
    if (num < 2)
        return 0;

    int divider = 1;
    for (int i = 2; i < (int) sqrt(num); ++i) {
        if (num % i == 0)
            divider = i;
    }

    if (divider == 1)
        return 1;

    return 0;
}

int has_only_one_first_entry(int num) {
    num = abs(num);

    if (num < 2)
        return 0;

    for (int i = 2; i <= (int) sqrt(num); ++i) {
        if (num % i == 0) {
            if (is_first_num(i) && (num / i) % i == 0)
                return 0;
        }
    }

    return 1;
}

int find_longest_chain(const int *numbers, int count) {
    int result = 0;

    for (int i = 0; i < count; ++i) {
        int product = 1;
        int tmp_res = 0;
        for (int j = i; j < count; ++j) {
            product *= *(numbers + j);
            if (has_only_one_first_entry(product))
                ++tmp_res;
            else break;
        }

        if (tmp_res > result)
            result = tmp_res;
    }

    return result;
}

int main() {
    int numbers[12] = {2, 0, 33, 35, 7, 4, 12, 7, 5, 11, 13, 22};
    int res = find_longest_chain(numbers, 12);
    printf("%d\n", res);
    return 0;
}
