#include <stdio.h>
#include <stdlib.h>

struct domino {
    int head;
    int tail;
    struct domino *next;
};

//region Helpers
struct domino *create(int head, int tail, struct domino *next) {
    struct domino *result = (struct domino *) malloc(sizeof(struct domino));

    result->head = head;
    result->tail = tail;
    result->next = next;

    return result;
}

void print_chain(struct domino *from) {
    printf("[%d | %d] ", from->head, from->tail);

    if (from->next == NULL) {
        printf("\n");
        return;
    }

    print_chain(from->next);
}

void swap(struct domino *parent1, struct domino *parent2) {

    struct domino *next1 = parent1->next;
    struct domino *next2 = parent2->next;
    struct domino *next1_next = next1->next;

    if (parent1->next == parent2) {
        parent1->next = parent2->next;
        parent2->next = parent1->next->next;
        parent1->next->next = parent2;
        return;
    }

    parent1->next = parent2->next;
    parent2->next = next1;

    next1->next = next2->next;
    next2->next = next1_next;
}

struct domino *find_parent_by_target_tail(struct domino *from, struct domino *target, int entry) {
    if (from->next == NULL)
        return NULL;

    if (from->next->next == NULL && entry > 1) {
        if (target->tail == from->next->head)
            return from;
        return NULL;
    }

    if (target->tail == from->next->head) {
        if (entry == 0)
            return from;
        --entry;
    }

    return find_parent_by_target_tail(from->next, target, entry);
}
//endregion

int sort(struct domino *from, int entry, int is_first_call) {
    int result = 0;

    if (from->next == NULL)
        return 1;

    if (from->next->next == NULL && from->tail == from->next->head)
        return 2;

    if (from->next->next == NULL && from->tail != from->next->head)
        return 0;

    struct domino *to_be_swapped = find_parent_by_target_tail(from, from, entry);

    if (to_be_swapped == NULL) {
        return 0;
    }

    if (to_be_swapped == from) {
        result += sort(from->next, 0, 0);
    } else {
        swap(from, to_be_swapped);
        result += sort(from->next, 0, 0);
    }

    if (result) {
        ++result;
        return result;
    }

    result += sort(from, ++entry, 0);

    return result;
}

void insert_in_the_end(struct domino *from, struct domino *target) {
    if (from->next == NULL) {
        from->next = target;
        target->next = NULL;
        return;
    }

    insert_in_the_end(from->next, target);
}


void reset(struct domino **array, int count) {
    for (int i = 0; i < count; ++i) {
        if (i == count - 1) {
            array[i]->next = NULL;
            return;
        }

        (*(array + i))->next = (*(array + i + 1));
    }
}

struct domino *find_correct_root(struct domino **incorrect_root, int count) {
    reset(incorrect_root, count);
    for (int j = 0; j < count; ++j) {
        int res = sort(incorrect_root[j], 0, 0);
        if (res == count) {
            return incorrect_root[j];
        }

        reset(incorrect_root, count);
        for (int i = 0; i <= j; ++i) {
            insert_in_the_end(incorrect_root[j], incorrect_root[i]);
        }
    }

    return NULL;
}

int main() {
    struct domino *d10 = create(8, 8, NULL);
    struct domino *d9 = create(8, 1, NULL);
    struct domino *d8 = create(1, 8, NULL);
    struct domino *d7 = create(2, 7, NULL);
    struct domino *d6 = create(0, 7, NULL);
    struct domino *d5 = create(4, 8, NULL);
    struct domino *d4 = create(8, 8, NULL);
    struct domino *d3 = create(7, 4, NULL);
    struct domino *d2 = create(8, 0, NULL);
    struct domino *d1 = create(8, 2, NULL);

    struct domino *arr[10];
    arr[0] = d1;
    arr[1] = d2;
    arr[2] = d3;
    arr[3] = d4;
    arr[4] = d5;
    arr[5] = d6;
    arr[6] = d7;
    arr[7] = d8;
    arr[8] = d9;
    arr[9] = d10;

    struct domino *res = find_correct_root(arr, 10);
    print_chain(res);
    return 0;
}
