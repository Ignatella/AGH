#include <stdio.h>
#include <stdlib.h>

#define lifo_size 10

int lastElementAt = -1;

void push(int *lifo, int val) {
    if (lastElementAt == lifo_size - 1) {
        fprintf(stderr, "Lifo is full\n");
        return;
    }

    lifo[++lastElementAt] = val;
}

int pop(int *lifo) {
    if (lastElementAt == -1) {
        fprintf(stderr, "Lifo is empty\n");
        exit(1);
    }
    return lifo[lastElementAt--];
}

void show(int *lifo) { //
    if (lastElementAt < 0) {
        fprintf(stderr, "Lifo is empty.\n");
        return;
    }

    printf("Last element is: %d\n", lifo[lastElementAt]);
}

int main() {
    int lifo[lifo_size];
    push(lifo, 5);
    push(lifo, 10);
    show(lifo);
    pop(lifo);
    show(lifo);
    pop(lifo);
    show(lifo);
    return 0;
}
