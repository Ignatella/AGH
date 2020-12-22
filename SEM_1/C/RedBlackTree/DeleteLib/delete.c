#include "stdlib.h"
#include "HelpersLib/deleteHelpers.h"
#include "../SharedLib/shared.h"

void delete_val(int val) {
    struct Node *to_be_replaced = find_by_val(root, val);
    if (to_be_replaced == NULL) return;

    struct Node *to_be_deleted = find_biggest_in_lbr(to_be_replaced, 1);

    swap_values(to_be_replaced, to_be_deleted);

    delete_node(to_be_deleted);
}

void delete_node(struct Node *to_be_deleted) {

    struct Node *left_child = to_be_deleted->left_child;
    struct Node *right_child = to_be_deleted->right_child;

    if (to_be_deleted->parent == NULL) {
        if (right_child != NULL) {
            update_root(right_child);
        } else root = NULL;
        return free_node(to_be_deleted);
    }

    if (right_child != NULL && right_child->color == Red) {
        right_child->color = Black;
        compress_chain(to_be_deleted);
        return free_node(to_be_deleted);
    }

    if (left_child != NULL && left_child->color == Red) {
        left_child->color = Black;
        compress_chain(to_be_deleted);
        return free_node(to_be_deleted);
    }

    if (to_be_deleted->color == Red) {
        compress_chain(to_be_deleted);
        return free_node(to_be_deleted);
    }


    balance_after_delete(left_child != NULL ? left_child
                                            : to_be_deleted);

    compress_chain(to_be_deleted);

    return free_node(to_be_deleted);
}

void balance_after_delete(struct Node *new) {

    struct Node *parent = new->parent;

    if (parent == NULL)
        return update_root(new);

    delete_case1(new);
}

void delete_case1(struct Node *new) {
    struct Node *parent = new->parent;
    struct Node *brother = get_brother(new);
    enum Side new_position = find_side_by_ref(new, parent);

    if (brother != NULL && brother->color == Red) {
        parent->color = Red;
        brother->color = Black;

        if (new_position == Left)
            rotate(brother, Left);
        else
            rotate(brother, Right);
    }

    return delete_case2(new);
}

void delete_case2(struct Node *new) {

    struct Node *parent = new->parent;
    struct Node *brother = get_brother(new);
    struct Node *sibling_left = brother->left_child;
    struct Node *sibling_right = brother->right_child;

    if (parent->color == Black
        && (brother == NULL || brother->color == Black)
        && (sibling_left == NULL || sibling_left->color == Black)
        && (sibling_right == NULL || sibling_right->color == Black)) {
        brother->color = Red;
        return balance_after_delete(parent);
    }

    return delete_case3(new);
}

void delete_case3(struct Node *new) {

    struct Node *parent = new->parent;
    struct Node *brother = get_brother(new);
    struct Node *sibling_left = brother->left_child;
    struct Node *sibling_right = brother->right_child;

    if (parent->color == Red
        && (brother == NULL || brother->color == Black)
        && (sibling_left == NULL || sibling_left->color == Black)
        && (sibling_right == NULL || sibling_right->color == Black)) {
        parent->color = Black;
        brother->color = Red;
        return;
    }

    return delete_case4(new);
}

void delete_case4(struct Node *new) {

    struct Node *parent = new->parent;
    struct Node *brother = get_brother(new);
    struct Node *sibling_left = brother->left_child;
    struct Node *sibling_right = brother->right_child;
    enum Side new_position = find_side_by_ref(new, parent);

    if (brother != NULL && brother->color == Black) { //5
        if (new_position == Left
            && (sibling_left != NULL && sibling_left->color == Red)
            && (sibling_right == NULL || sibling_right->color == Black)) {
            brother->color = Red;
            sibling_left->color = Black;
            rotate(sibling_left, Right);
        }

        if (new_position == Right
            && (sibling_right != NULL && sibling_right->color == Red)
            && (sibling_left == NULL || sibling_left->color == Black)) {
            sibling_right->color = Black;
            brother->color = Red;
            rotate(sibling_right, Left);
        }
    }

    return delete_case5(new);
}

void delete_case5(struct Node *new) {

    struct Node *parent = new->parent;
    struct Node *brother = get_brother(new);
    struct Node *sibling_left = brother->left_child;
    struct Node *sibling_right = brother->right_child;
    enum Side new_position = find_side_by_ref(new, parent);


    if (new_position == Left && brother != NULL
        && brother->color == Black && sibling_right != NULL
        && sibling_right->color == Red) {
        sibling_right->color = Black;
        rotate(brother, Left);
    }

    if (new_position == Right && brother != NULL
        && brother->color == Black && sibling_left != NULL
        && sibling_left->color == Red) {
        sibling_left->color = Black;
        rotate(brother, Right);
    }

    brother->color = parent->color;
    parent->color = Black;
}
