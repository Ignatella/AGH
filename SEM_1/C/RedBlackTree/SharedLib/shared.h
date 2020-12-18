#ifndef REDBLACKTREE_SHARED_H
#define REDBLACKTREE_SHARED_H

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

struct Node *root;


void rotate(struct Node *new, enum Side direction);

void update_root(struct Node *new);

#endif //REDBLACKTREE_SHARED_H
