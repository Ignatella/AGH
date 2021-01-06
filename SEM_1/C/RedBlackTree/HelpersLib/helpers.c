#include <stdio.h>
#include "../SharedLib/shared.h"

int pow_c(int a, int b) { //simple pow function (not full functional) for put code on repl.it
    int result = a;

    if (b == 0)
        return 1;

    for (int i = 1; i < b; ++i) {
        result *= a;
    }

    return result;
}

int get_height(struct Node *curr) {
    if (curr == NULL) {
        return 0;
    }
    int result = 1;
    int r1 = get_height(curr->left_child);
    int r2 = get_height(curr->right_child);
    if (r1 > r2)
        result += r1;
    else result += r2;

    return result;
}

void get_layer(int layer, struct Node *curr, int curr_layer, struct Node **result, int insert_index) {
    if (curr == NULL) {
        int null_count = pow_c(2, (layer - curr_layer));
        int j = 0;
        do {
            result[insert_index + j] = NULL;
            ++j;
        } while (j < null_count);
        return;
    }

    if (layer != curr_layer) {
        int right_insert_index = pow_c(2, layer) / pow_c(2, curr_layer + 1) + insert_index;
        get_layer(layer, curr->left_child, curr_layer + 1, result, insert_index);
        get_layer(layer, curr->right_child, curr_layer + 1, result, right_insert_index);
        return;
    }

    result[insert_index] = curr;
}

void fill_with_nulls(struct Node **array, int size) {
    for (int i = 0; i < size; ++i) {
        array[i] = NULL;
    }
}

void print_tree() {
    int total_h = get_height(root);
    for (int i = 0; i < total_h; ++i) {
        int size = pow_c(2, i);
        struct Node *layer[size];
        fill_with_nulls(layer, size);
        get_layer(i, root, 0, layer, 0);

        int underscore_count = (total_h - i - 3) >= 0 ? (6 * pow_c(2, total_h - i - 3) - 2) : 0;
        int ll_count = pow_c(2, total_h - 1 - i);
        int left_indent = (ll_count * 2 + 4 * (ll_count - 1)) / 2 - 1 - underscore_count;
        int between_indent = 6 * pow_c(2, total_h - i - 1) - 2 - 2 * underscore_count;

        for (int j = 0; j < left_indent; ++j)
            printf(" ");

        for (int j = 0; j < size; ++j) {
            for (int k = 0; k < underscore_count; ++k)
                printf("_");

            if (layer[j] == NULL)
                printf("___");
            else {
                printf("%02d", layer[j]->value);
                if (layer[j]->color == Red)
                    printf("R");
                else
                    printf("B");
            }

            for (int k = 0; k < underscore_count - 1; ++k)
                printf("_");

            int b_indent = underscore_count > 0 ? between_indent : (between_indent - 1);
            for (int k = 0; k < b_indent; ++k)
                printf(" ");
        }

        printf("\n");

        if (i != total_h - 1) {
            for (int j = 0; j < left_indent - 1; ++j) {
                printf(" ");
            }

            for (int j = 0; j < size; ++j) {
                printf("/");

                for (int k = 0; k < 2 + underscore_count * 2; ++k)
                    printf(" ");

                printf("\\");

                for (int k = 0; k < between_indent - 2; ++k) {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
