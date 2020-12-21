#include <stdio.h>
#include <stdlib.h>

#define lifo_size 10

void push(int *lifo, int **lastElementAt, int val) {
    if(*lastElementAt == NULL)
        *lastElementAt = lifo;

    if (*lastElementAt - lifo >= lifo_size) {
        fprintf(stderr, "Lifo is full.\n");
        return;
    }

    *((*lastElementAt)++) = val;
}

int pop(const int *lifo, int **lastElementAt) {
    if (*lastElementAt == NULL) {
        fprintf(stderr, "Lifo is empty.\n");
        exit(1);
    }

    int result = *(--*lastElementAt);

    if(*lastElementAt == lifo)
        *lastElementAt = NULL;

    return result;
}

void show(const int *lifo, const int *lastElementAt) {
    if (lastElementAt == NULL) {
        fprintf(stderr, "Lifo is empty.\n");
        return;
    }

    printf("Last element is: %d\n", *--lastElementAt);
}

int main() {
    int lifo[lifo_size];
    int *lastElementAt = NULL;

    show(lifo, lastElementAt);
    push(lifo, &lastElementAt, 10);
    show(lifo, lastElementAt);
    int res = pop(lifo, &lastElementAt);
    printf("%d\n", res);
    show(lifo, lastElementAt);

    return 0;
}
