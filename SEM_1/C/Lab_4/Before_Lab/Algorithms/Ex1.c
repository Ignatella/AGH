#include <stdio.h>

#define lifo_size 10

int lifo[lifo_size] = {0};
int lastElementAt = -1;

void push(int *position, int val) {
    if (lastElementAt == lifo_size - 1) {
        fprintf(stderr, "Lifo is full\n");
        return;
    }
    lifo[++lastElementAt] = val;
    *position = lastElementAt;
}

void pop(int *val) {
    if (lastElementAt == -1) {
        fprintf(stderr, "Lifo is empty\n");
        return;
    }
    *val = lifo[lastElementAt--];
}

void show(int *val) { //Ok
    if (lastElementAt < 0) {
        fprintf(stderr, "Lifo is empty.\n");
        return;
    }

    *val = lifo[lastElementAt];
}

int main() {
    int pos = 0;
    int val = 0;
    int *position = &pos;
    int *valP = &val;
    push(position, 5);
    show(valP);
    push(position, 10);
    pop(valP);
    return 0;
}
