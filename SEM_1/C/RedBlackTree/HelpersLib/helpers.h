#include "../SharedLib/shared.h"

#ifndef REDBLACKTREE_HELPERS_H
#define REDBLACKTREE_HELPERS_H

int pow_c(int a, int b); //simple pow function (not full functional) for put code on repl.it
int get_height(struct Node *curr);
void get_layer(int layer, struct Node *curr, int curr_layer, struct Node **result, int insert_index);
void fill_with_nulls(struct Node **array, int size);
void print_tree();

#endif //REDBLACKTREE_HELPERS_H
