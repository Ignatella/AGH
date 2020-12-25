#include <stdio.h>
#include <stdlib.h>


int find_longest_chain(int **array, int count) {
    int the_same_length = 0;
    int longest_chain_count = 0;
    int *longest_starts_from = NULL;
    int *current_address = *array;
    int current_chain_count = 1;

    for (int i = 1; i < count; ++i) {
        if (*(*array + i) == *current_address) {
            ++current_chain_count;

            if (current_chain_count == longest_chain_count) {
                the_same_length = 1;
                continue;
            }

            if (current_chain_count > longest_chain_count) {
                the_same_length = 0;
                longest_starts_from = current_address;
                longest_chain_count = current_chain_count;
            }
            continue;
        }

        current_chain_count = 1;
        current_address = *array + i;
    }


    if (!the_same_length) {
        int *res = (int *) calloc(count - longest_chain_count, sizeof(int));

        for (int i = 0; i < longest_starts_from - *array; ++i)
            res[i] = *(*array + i);

        for (long i = longest_starts_from - *array; i < count - longest_chain_count; ++i)
            res[i] = *(*array + i + longest_chain_count);

        *array = res;

        return longest_chain_count;
    }

    return 0;
}

int main() {
    int numbers[12] = {1, 2, 2, 2, 3, 4, 5, 5, 6, 7, 8, 10};
    int *arr = numbers;
    int deleted = find_longest_chain(&arr, 12);

    for (int i = 0; i < 12 - deleted; ++i) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
    return 0;
}
