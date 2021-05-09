#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

typedef struct client {
    char name[20];
    char surname[32];
    char index[20];
    int age;
} client;

client *createClientArr(int size) {
    client *res = calloc(size, sizeof(client));
    if (res == NULL)
        exit(EXIT_FAILURE);
    return res;
}

void printClient(client *cli) {
    printf("=== Client: ===\n");
    printf("Name = %s", cli->name);
    printf("Surname = %s", cli->surname);
    printf("Index = %s", cli->index);
    printf("Age = %d", cli->age);

    printf("\n");
}

void printClients(int size, client *clients) {
    for (int i = 0; i < size; ++i) {
        printClient(clients + i);
    }
}

void freeMem(int pointerCount, ...) {
    va_list params;
    va_start(params, pointerCount);
    for (int i = 0; i < pointerCount; i++) {
        void **res = va_arg(params,
                            void **);
        free(*res);
        *res = NULL;
    }
    va_end(params);
}

void getClient(client *target) {
    char *buffer = NULL;
    size_t len;

    getline(&buffer, &len, stdin);
    strcpy(target->name, buffer);

    getline(&buffer, &len, stdin);
    strcpy(target->surname, buffer);

    getline(&buffer, &len, stdin);
    strcpy(target->index, buffer);

    getline(&buffer, &len, stdin);
    target->age = atoi(buffer);

    getline(&buffer, &len, stdin);
    freeMem(1, &buffer);
}

int clientCmp(const void *first, const void *second) {
    client *f = (client *) first;
    client *s = (client *) second;

    int surCmp = strcmp(f->surname, s->surname);

    if (surCmp)
        return surCmp;

    return strcmp(f->name, s->name);
}


void sortClients(int size, client *clientArr) {
    qsort(clientArr, size, sizeof(client), clientCmp);
}

int main() {
    int clientCount = 5;
    client *clients = createClientArr(clientCount);

    for (int i = 0; i < clientCount; ++i)
        getClient(clients + i);

    sortClients(clientCount, clients);

    printf("After sort:\n\n");
    printClients(clientCount, clients);

    freeMem(1, &clients);

    printf("End of program.\n");
    return 0;
}
