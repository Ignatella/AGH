#include <stdlib.h>
#include "AddLib/add.h"
#include "HelpersLib/helpers.h"

void delete_val(int val);

void swap_values(struct Node *node1, struct Node *node2);

struct Node *find_by_val(struct Node *from, int val);

struct Node *find_biggest_in_lbr(struct Node *from_node, int is_first_call);

struct Node *get_brother(struct Node *me);

void delete_node(struct Node *to_be_deleted);

void balance_after_delete(struct Node *new);

void free_node(struct Node *node);

void compress_chain(struct Node *node);

void delete_case1(struct Node *new);

void delete_case2(struct Node *new);

void delete_case3(struct Node *new);

void delete_case4(struct Node *new);

void delete_case5(struct Node *new);

enum Side find_side_by_ref(struct Node *child, struct Node *parent) {
    if (parent->right_child == child) {
        return Right;
    }

    return Left;
}

int main() {
    struct Node *r = root;
    add_val(10);
    add_val(9);
    add_val(5);
    add_val(69);
    add_val(32);
    add_val(8);
    add_val(7);
    add_val(12);
    add_val(81);
    add_val(6);
    add_val(4);
    add_val(3);
    add_val(2);
    add_val(1);
    //CORRECT
    add_val(123);
    add_val(54);
    add_val(13);
    add_val(15);


    delete_val( 12);
    delete_val( 9);
    delete_val( 5);
    delete_val( 4);
    delete_val( 8);
    delete_val(1);
    delete_val( 2);
    delete_val( 123);
    delete_val( 69); //3 rotation

    delete_val(32);
    delete_val(54);
    delete_val(10);
    delete_val(81);
    delete_val(15);
    delete_val(7);
    delete_val(3);
    delete_val(6);
    delete_val(13);

//    delete_val( 12);
//    delete_val(7);
//    delete_val(9);
//    delete_val(8);
//    delete_val(69);
//    delete_val(5);
//    delete_val(10);
//
//    delete_val(32);
//    delete_val(81);
//    delete_val(6);
//    delete_val(4);
//    delete_val(3);
//    //CORRECT
//    delete_val(2);
//    delete_val(1);

}

void delete_case1(struct Node *new) {
    struct Node *parent = new->parent;
    struct Node *brother = get_brother(new);
    // enum Side new_position = find_side(new, parent);
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

    if (parent->color == Red //4
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
    // enum Side new_position = find_side(new, parent);

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
    //enum Side new_position = find_side(new, parent);
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

void balance_after_delete(struct Node *new) {
    struct Node *parent = new->parent;

    if (parent == NULL)
        return update_root(new);

    delete_case1(new);
}

void delete_node(struct Node *to_be_deleted) { //ToDo: need to be updated

    struct Node *left_child = to_be_deleted->left_child;
    struct Node *right_child = to_be_deleted->right_child;

    if (to_be_deleted->parent == NULL) {
        if (right_child != NULL){
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

void free_node(struct Node *node) {
    free(node);
}

struct Node *find_by_val(struct Node *from, int value) {
    if (from == NULL || from->value == value) return from;

    if (from->value > value && from->left_child != NULL)
        return find_by_val(from->left_child, value);

    if (from->value < value && from->right_child != NULL)
        return find_by_val(from->right_child, value);

    return NULL;
}

void swap_values(struct Node *node1, struct Node *node2) {
    int temp = node1->value;
    node1->value = node2->value;
    node2->value = temp;
}

void delete_val(int val) {
    struct Node *to_be_replaced = find_by_val(root, val);
    if (to_be_replaced == NULL) return;

    struct Node *to_be_deleted = find_biggest_in_lbr(to_be_replaced, 1);

    swap_values(to_be_replaced, to_be_deleted);

    delete_node(to_be_deleted);
}
