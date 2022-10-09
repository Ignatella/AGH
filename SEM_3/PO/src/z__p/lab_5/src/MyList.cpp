#include "MyList.h"
#include <cstring>
#include <iostream>

Node * create(const char data[50]) { 
    Node *node = new Node;
    strcpy(node->data, data);
    node->next = NULL;
    return node;
}

void prepare(MyList *list)
{
    list->head = NULL;
}

void add(MyList *list, const char buffer[50])
{
    Node *created = create(buffer);
    Node* lastNode = last(list);
    if (empty(list)) { 
        list -> head = created;
    }
    else { 
        lastNode -> next = created;
    }
}

void printNode(const Node *node) {
    std::cout << node->data << " ";
}

void print(const MyList *list)
{
    if (empty(list))
        return;
    
    Node *curr = list -> head;
    
    while (curr != NULL)
    {
        printNode(curr);
        curr = curr->next;
    }
}

bool empty(const MyList *list)
{
    return list -> head == NULL;
}

Node *last(const MyList *list)
{
    Node *curr = list->head;

    if (curr == NULL)
        return list->head;
    
    while(curr->next != NULL) { 
        curr = curr->next;
    }

    return curr;
}

Node *find(const MyList *list, const char *data)
{
    Node *curr = list->head;
    while (curr != NULL)
    {
        if (strcmp(curr->data, data) == 0) 
            break;
            
        curr = curr->next;
    }

    return curr;
}

void clear(MyList *list)
{
    Node *curr = list -> head;
    Node *next = list -> head;
    while (curr != NULL) { 
        next = curr -> next;
        delete curr;
        curr = next;
    }

    list->head = NULL;
}
