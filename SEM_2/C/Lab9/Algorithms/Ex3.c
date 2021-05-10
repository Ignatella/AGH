#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char letter;
    struct node *next;
} node;

node *createNode() {
    node *arr = calloc(1, sizeof(node));
    if (arr == NULL)
        exit(EXIT_FAILURE);

    return arr;
}

node *createNodeChain(int length) {
    if (length < 1)
        return NULL;

    node *head = createNode();

    node *curr = head;
    for (int i = 0; i < length - 1; ++i) {
        node *new = createNode();
        curr->next = new;
        curr = new;
    }

    curr->next = head;
    return head;
}

void setNodeChainLetters(node *head) {
    char letter = 'a';
    node *curr = head;
    do {
        curr->letter = letter++;
        curr = curr->next;
    } while (curr != head);
}

void freeNodeChain(node *head) {
    if (head->next == head) {
        free(head);
        head = NULL;
        return;
    }

    struct node *tmp = head->next;
    do {
        node *next = tmp->next;
        free(tmp);
        tmp = next;
    } while (tmp != head);
    free(head);
    head = NULL;
}

void nodeChainLetterToUpper(node *head) {
    node *curr = head;

    do {
        curr->letter -= 32;
        curr = curr->next;
    } while (curr != head);
}

void printNode(node *n) {
    printf("Node: %c\n", n->letter);
}

void printNodeChain(node *head) {
    node *curr = head;

    do {
        printNode(curr);
        curr = curr->next;
    } while (curr != head);
}

int main() {
    int length = 3;
    node *head = createNodeChain(length);

    printf("After creation:\n");
    setNodeChainLetters(head);
    printNodeChain(head->next); //with help of 'b'

    printf("After ToUpper():\n");
    nodeChainLetterToUpper(head->next->next); //with help of 'c'
    printNodeChain(head);

    freeNodeChain(head);

    printf("End of program.\n");
    return 0;
}
