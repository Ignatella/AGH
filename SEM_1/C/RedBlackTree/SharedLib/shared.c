#include <stdio.h>
#include "shared.h"

struct Node *root = NULL;

void rotate(struct Node *new, enum Side direction) {
    struct Node *parent = new->parent;
    struct Node *grand = parent->parent;

    if (grand == NULL)
        update_root(new);
    else if (grand->left_child == parent)
        grand->left_child = new;
    else if (grand->right_child == parent)
        grand->right_child = new;


    parent->parent = new;
    new->parent = grand;

    if (direction == Left) {
        parent->right_child = new->left_child;

        new->left_child = parent;
    }

    if (direction == Right) {
        parent->left_child = new->right_child;

        new->right_child = parent;
    }
}

void update_root(struct Node *new) {
    root = new;
    root->color = Black;
}
