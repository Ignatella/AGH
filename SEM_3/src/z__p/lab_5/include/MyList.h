#pragma once

struct Node
{
    char data[50];
    Node *next;
};

struct MyList
{
    Node *head;
};

void prepare(MyList *);
void add(MyList *, const char buffer[50]);
void clear(MyList *);
void print(const MyList *);
bool empty(const MyList *);
Node *last(const MyList *);
Node *find(const MyList *, const char *);