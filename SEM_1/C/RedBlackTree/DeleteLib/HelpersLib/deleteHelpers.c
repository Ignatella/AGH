#include "stdlib.h"
#include "../../SharedLib/shared.h"


struct Node *find_by_val(struct Node *from, int value) {
    if (from == NULL || from->value == value) return from;

    if (from->value > value && from->left_child != NULL)
        return find_by_val(from->left_child, value);

    if (from->value < value && from->right_child != NULL)
        return find_by_val(from->right_child, value);

    return NULL;
}

struct Node *find_biggest_in_lbr(struct Node *from_node, int is_first_call) {

    if (is_first_call) {
        if (from_node->left_child == NULL)
            return from_node;

        return find_biggest_in_lbr(from_node->left_child, 0);
    }

    if (from_node->right_child == NULL)
        return from_node;

    return find_biggest_in_lbr(from_node->right_child, 0);
}


struct Node *get_brother(struct Node *me) {
    if (me->parent->left_child == me) {
        return me->parent->right_child;
    } else return me->parent->left_child;
}

enum Side find_side_by_ref(struct Node *child, struct Node *parent) {
    if (parent->right_child == child) {
        return Right;
    }

    return Left;
}

void compress_chain(struct Node *node) {
    struct Node *parent = node->parent;
    struct Node *left_child = node->left_child;
    struct Node *right_child = node->right_child;
    struct Node *existing_child = left_child == NULL ? right_child : left_child;

    if (parent->left_child == node)
        parent->left_child = existing_child;
    else if (parent->right_child == node)
        parent->right_child = existing_child;

    if (existing_child != NULL)
        existing_child->parent = parent;
}

void swap_values(struct Node *node1, struct Node *node2) {
    int temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}

void free_node(struct Node *node) {
    free(node);
}
