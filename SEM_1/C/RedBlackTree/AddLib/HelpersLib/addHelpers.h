#ifndef REDBLACKTREE_ADDHELPERS_H
#define REDBLACKTREE_ADDHELPERS_H


void add_val(int val);


struct Node *find_node_to_insert_in(struct Node *from_node, int value);

struct Node *create_node(int value);

enum Side find_side_by_val(struct Node *child, struct Node *parent);

void insert_node(struct Node *new, struct Node *parent);

#endif //REDBLACKTREE_ADDHELPERS_H
