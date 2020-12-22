#ifndef REDBLACKTREE_DELETE_H
#define REDBLACKTREE_DELETE_H

struct Node *find_by_val(struct Node *from, int val);

struct Node *find_biggest_in_lbr(struct Node *from_node, int is_first_call);

struct Node *get_brother(struct Node *me);

enum Side find_side_by_ref(struct Node *child, struct Node *parent);

void compress_chain(struct Node *node);

void swap_values(struct Node *node1, struct Node *node2);

void free_node(struct Node *node);

#endif //REDBLACKTREE_DELETE_H
