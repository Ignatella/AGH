#include <stdio.h>
#include <stdlib.h>

#define lifo_size 10

void push(const int *lifo, int **lastElementAt, int val) { //OK
    if (*lastElementAt - lifo >= lifo_size - 1) {
        fprintf(stderr, "Lifo is full\n");
        return;
    }

    *(++(*lastElementAt)) = val;
}

int pop(const int *lifo, int **lastElementAt) {
    if (*lastElementAt < lifo) {
        fprintf(stderr, "Lifo is empty\n");
        exit(1);
    }

    return *(*lastElementAt)--;
}

void show(const int *lifo, const int *lastElementAt, int *val) { //Ok
    if (lastElementAt < lifo) {
        fprintf(stderr, "Lifo is empty.\n");
        return;
    }

    *val = *lastElementAt;
}

int main() {
    int lifo[lifo_size];
    int *lastElementAt = lifo - 1;

    int val = 0;
    int *valP = &val;

    push(lifo, &lastElementAt, 10);
    pop(lifo, &lastElementAt);
    show(lifo, lastElementAt, valP);
    return 0;
}
