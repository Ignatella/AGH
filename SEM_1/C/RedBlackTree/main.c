#include <stdio.h>
#include <stdlib.h>

//region Structures
enum Side {
    Left,
    Right
};

enum Color {
    Red,
    Black
};

struct Node {
    int value;
    struct Node *parent;
    struct Node *left_child;
    struct Node *right_child;
    enum Color color;
};
//endregion

//region Prototypes
//region Helpers
void Add_val(int val);

struct Node *find_node_to_insert_in(struct Node *from_node, int value);
struct Node *create_node(int value);
enum Side find_side(struct Node *child, struct Node *parent);
void insert_node(struct Node *new, struct Node *parent);
//endregion

//region Balancing
void balance_tree(struct Node *new);

//region Helpers
void update_root(struct Node *new);
void balance_most_lr_red_uncle(struct Node *new);
void rotate(struct Node *new, enum Side direction);
//endregion
//endregion

//endregion

struct Node *root = NULL;

int main() {
    Add_val(10);
    Add_val(9);
    Add_val(5);
    Add_val(69);
    Add_val(32);
    Add_val(8);
    Add_val(7);
    Add_val(12);
    Add_val(81);
    Add_val(6);
    Add_val(4);
    Add_val(3);
    Add_val(2);
    Add_val(1);
}

//region AddImplementation
void balance_tree(struct Node *new) {
    struct Node *parent = new->parent;
    struct Node *grand;
    struct Node *uncle;

    enum Side new_position;
    enum Side parent_position;

    if (parent == NULL) return update_root(new);
    if (parent->color == Black) return; //tree is balanced

    grand = parent->parent;

    new_position = find_side(new, parent);
    parent_position = find_side(parent, grand);

    if (parent_position == Left) //determine where uncle is
        uncle = grand->right_child;
    else uncle = grand->left_child;


    if (parent_position == Left) {
        if (uncle == NULL || uncle->color == Black) {
            if (new_position == Left) {
                rotate(parent, Right);
                return;
            } else {
                rotate(new, Left);
                return;
            }
        } else {
            balance_most_lr_red_uncle(new);
            return;
        }
    }

    if (parent_position == Right) {
        if (uncle == NULL || uncle->color == Black) {
            if (new_position == Right) {
                rotate(parent, Left);
                return;
            } else {
                rotate(new, Right);
            }
        } else {
            balance_most_lr_red_uncle(new);
            return;
        }
    }
}

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

        if (parent->color == Red)
            rotate(new, Right);
    }

    if (direction == Right) {
        parent->left_child = new->right_child;

        new->right_child = parent;

        if (parent->color == Red)
            rotate(new, Left);
    }

    if (parent->color == Black) {
        parent->color = Red;
        new->color = Black;
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

void update_root(struct Node *new) {
    root = new;
    root->color = Black;
}
//endregion

//region HelpersImplementations

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

void Add_val(int val) {
    struct Node *created = create_node(val);
    struct Node *parent = find_node_to_insert_in(root, val);

    insert_node(created, parent);

    return balance_tree(created);
}
//endregion
