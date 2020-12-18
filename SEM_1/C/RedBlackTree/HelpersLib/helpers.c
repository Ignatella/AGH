#include <stdio.h>
#include "helpers.h"
#include "../AddLib/add.h"


void add_val(int val) {
    struct Node *created = create_node(val);
    struct Node *parent = find_node_to_insert_in(root, val);

    insert_node(created, parent);

    return balance_tree(created);
}

enum Side find_side(struct Node *child, struct Node *parent) {
    if (child->value > parent->value)
        return Right;

    return Left;
}

struct Node *find_node_to_insert_in(struct Node *from_node, int value) {
    if (from_node == NULL) return NULL;

    if (value < from_node->value) {
        if (from_node->left_child != NULL)
            return find_node_to_insert_in(from_node->left_child, value);
        else return from_node;
    }

    if (value > from_node->value) {
        if (from_node->right_child != NULL)
            return find_node_to_insert_in(from_node->right_child, value);
        else return from_node;
    }

    return NULL;
}

struct Node *create_node(int val) {
    struct Node *result = (struct Node *) malloc(sizeof(struct Node));
    result->value = val;
    result->color = Red;

    return result;
}

void insert_node(struct Node *new, struct Node *parent) {
    if (parent == NULL) return;

    enum Side side_for_insertion = find_side(new, parent);

    if (side_for_insertion == Left)
        parent->left_child = new;
    else
        parent->right_child = new;

    new->parent = parent;
}
