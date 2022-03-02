#include "MyList.h"
#include <iostream>
#include <cstring>

Node *createNode(const char *buffer) { 
    Node *created = new Node;
    created->next = NULL;
    created->data = new char[strlen(buffer) + 1];
    strcpy(created->data, buffer);
    
    return created;
}

Node *find(MyList *list, const char *key) { 
    Node *current = list->head;

    while(current != NULL)  {
        if (strcmp(current->data, key) == 0)
            break;

        current = current->next;
    }

    return current;
}

Node * findPrevious(MyList *list, const char *key) { 
    Node *current = list->head;

    while (current != NULL)
    {   
        if (current->next == NULL)
            break;

        if (strcmp(current->next->data, key) == 0)
            return current;

        current = current->next;
    }

    return NULL;
}

void replace(MyList *list, const char *oldValue, const char *newValue) { 
    Node *foundNode = find(list, oldValue);
    if (foundNode == NULL)
        return;

    delete []foundNode->data;
    foundNode->data = new char[strlen(newValue) + 1];
    strcpy(foundNode->data, newValue);
}

void init(MyList *list, const char *data) { 
    list->head = NULL;
    list->name = new char[strlen(data) + 1];
    strcpy(list->name, data);
}


void append(MyList *list, const char *buffer) {
    Node *createdNode = createNode(buffer);
    createdNode->next = list->head;
    list->head = createdNode;
}

bool empty(const MyList *list) { 
    return list->head == NULL;
}


void print(const MyList *list) { 
    Node *current = list->head;

    if (list->head == NULL)
        return;

    std::cout << list->name << ": ";

    while(current != NULL) { 
        std::cout << current->data << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

void clearNode(Node *node) { 
    delete[]node->data;
    delete node;
}

void insertAfter(MyList *list, const char *key, const char *newValue) { 
    Node *foundNode = find(list, key);
    if (foundNode == NULL)
        return;

    Node *createdNode = createNode(newValue);
    createdNode->next = foundNode->next;
    foundNode->next = createdNode;
}

void removeAfter(MyList *list, const char *key) { 
    Node *foundNode = find(list, key);
    if (foundNode == NULL || foundNode->next == NULL)
        return;

    Node *toBeDeleted = foundNode->next;
    Node *nextNode = toBeDeleted->next;

    clearNode(toBeDeleted);
    foundNode->next = nextNode;
}

void remove(MyList *list, const char *key) { 
    Node *foundNode = find(list, key);
    if (foundNode == NULL)
        return;

    Node *previousNode = findPrevious(list, key);
    Node *nextNode = foundNode->next;

    clearNode(foundNode);

    if (previousNode == NULL) { 
        list->head = nextNode;
    }
    else { 
        previousNode->next = nextNode;
    }
}

void clear(MyList *list)
{
    if (!empty(list)) { 
        Node *curr = list -> head;
        Node *next = list -> head;
        while (curr != NULL) { 
            next = curr -> next;
            clearNode(curr);
            curr = next;
        }

        list->head = NULL;
    }

    if (list->name != NULL) { 
        delete[] list->name;
        list->name = NULL;
    }
}