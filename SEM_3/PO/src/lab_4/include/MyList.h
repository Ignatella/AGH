#pragma once

struct Node {
    char* data;
    Node *next;
};

struct MyList {
    char *name;
    Node *head;
};


// Create node with specified data
Node *createNode(const char *buffer);

// Find node by key
Node *find(MyList *list, const char *key);

// Find previous node of the node with key
Node * findPrevious(MyList *list, const char *key);

// Replace node data
void replace(MyList *list, const char *oldValue, const char *newValue);

// Clear node from memory
void clearNode(Node *node);

// Initialize list
void init(MyList *list, const char *data);

// Add node on beggining
void append(MyList *list, const char *buffer);

// Check if list is empty
bool empty(const MyList *list);

// Append node after the node with specified key
void insertAfter(MyList *list, const char *key, const char *newValue); 

// Remove next node after node with specified key
void removeAfter(MyList *list, const char *key);

// Remove node with the key from memory
void remove(MyList *list, const char *key);

// Print list
void print(const MyList *list);

// Remove list & all nodes from memory
void clear(MyList *list);