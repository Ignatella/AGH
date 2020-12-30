#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct node {
    char *value;
    struct node *next;
};

void print_chain(struct node *from) {
    struct node *curr = from;
    printf("-------->");
    do {
        printf("%s", curr->value);
        printf("-------->");
        curr = curr->next;
    } while (curr != from);
    printf("\n");
}

char get_fist_letter(char *n) {
    return n[0];
}

char get_last_letter(char *n) {
    return n[strlen(n) - 1];
}

struct node *create_node(char *value, struct node *next) {
    struct node *result = calloc(1, sizeof(struct node));
    result->value = value;
    result->next = next;
    return result;
}

int insert_value(struct node **root, char *value) {
    struct node *curr = *root;
    do {
        char curr_last = get_last_letter(curr->value);
        char next_first = get_fist_letter(curr->next->value);
        char val_first = get_fist_letter(value);
        char val_last = get_last_letter(value);

        if (curr_last < val_first && val_last < next_first) {
            struct node *new = create_node(value, curr->next);
            curr->next = new;
            *root = new;
            return 1;
        }

        curr = curr->next;
    } while (curr != *root);


    return 0;
}

int main() {
    struct node *a5 = create_node("zia", NULL);
    struct node *a4 = create_node("ola", a5);
    struct node *a3 = create_node("marek", a4);
    struct node *a2 = create_node("leszek", a3);
    struct node *root = create_node("bartek", a2);
    a5->next = root;
    print_chain(root);
    int res = insert_value(&root, "lm");
    print_chain(root);
    int r1 = insert_value(&root, "bj");
    print_chain(root);
    return 0;
}
