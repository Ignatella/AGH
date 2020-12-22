#include "../SharedLib/shared.h"

#ifndef REDBLACKTREE_DELETE_H
#define REDBLACKTREE_DELETE_H


void delete_val(int val);


void delete_node(struct Node *to_be_deleted);

void balance_after_delete(struct Node *new);

void delete_case1(struct Node *new);

void delete_case2(struct Node *new);

void delete_case3(struct Node *new);

void delete_case4(struct Node *new);

void delete_case5(struct Node *new);

#endif //REDBLACKTREE_DELETE_H
