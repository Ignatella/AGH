#pragma once

struct Node { 
    char *data;
    Node *next;
};

struct MyList {
    Node *head;
};

void init(MyList *list);

void append(MyList* list, const char *data);

bool isEmpty(const MyList *list);

void print(const MyList *list);

void clear(MyList *list);

void removeFirst(MyList *list);

Node *last(const MyList *list);

void clearNode(Node *node);