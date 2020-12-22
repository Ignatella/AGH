#include <stdio.h>
#include "add.h"
#include "HelpersLib/addHelpers.h"


void balance_tree(struct Node *new) {
    struct Node *parent = new->parent;
    struct Node *grand;
    struct Node *uncle;

    enum Side new_position;
    enum Side parent_position;

    if (parent == NULL) return update_root(new);
    if (parent->color == Black) return; //tree is balanced

    grand = parent->parent;

    new_position = find_side_by_val(new, parent);
    parent_position = find_side_by_val(parent, grand);

    if (parent_position == Left) //determine where uncle is
        uncle = grand->right_child;
    else uncle = grand->left_child;


    if (parent_position == Left) {
        if (uncle == NULL || uncle->color == Black) {
            if (new_position == Right) {
                rotate(new, Left);
                rotate(new, Right);
                new->color = Black;
                grand->color = Red;
                return;
            }

            if (new_position == Left){
                rotate(parent, Right);
                parent->color = Black;
                grand->color = Red;
                return;
            }
        } else {
            balance_most_lr_red_uncle(new);
            return;
        }
    }

    if (parent_position == Right) {
        if (uncle == NULL || uncle->color == Black) {
            if (new_position == Left) {
                rotate(new, Right);
                rotate(new, Left);
                new->color = Black;
                grand->color = Red;
                return;
            }

            if (new_position == Right){
                rotate(parent, Left);
                parent->color = Black;
                grand->color = Red;
                return;
            }
        } else {
            balance_most_lr_red_uncle(new);
            return;
        }
    }
}

void balance_most_lr_red_uncle(struct Node *new) {
    struct Node *grand = new->parent->parent;

    //no matter is it parent or uncle
    struct Node *a = grand->left_child;
    struct Node *b = grand->right_child;

    a->color = Black;
    b->color = Black;
    grand->color = Red;

    balance_tree(grand);
}
