#define _GNU_SOURCE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int isContained(char **arr, int size, char *str) {
    int found = 0;
    for (int i = 0; i < size; ++i) {
        char *p = strcasestr(arr[i], str);
        if (p != NULL)
            found = 1;
    }

    return found;
}

char **words(char *str, int *resSize) {
    char delimiters[6] = {',', ' ', '.', '-', ':', '\0'};
    char **result = NULL;

    int size = 0, capacity = 0;

    char *ptr = strpbrk(str, delimiters);
    char *prev = str;

    while (ptr != NULL) {
        int word_size = (int) (ptr - prev);
        if (word_size < 1) {
            prev = ptr + 1;
            ptr = strpbrk(ptr + 1, delimiters);
            continue;
        }

        if (size == capacity) {
            capacity = (capacity ? 2 * capacity : 1);
            void *tmp = realloc(result, capacity * sizeof *result);
            if (tmp == NULL) {
                perror("Failed to expand lines buffer.");
                exit(EXIT_FAILURE);
            }
            result = tmp;
        }

        char *word = calloc(word_size + 1, sizeof(char));
        strncpy(word, prev, word_size);
        word[word_size] = '\0';
        if (isContained(result, size, word) == 0)
            result[size++] = word;
        else free(word);

        prev = ptr + 1;
        ptr = strpbrk(ptr + 1, delimiters);
    }

    *resSize = size;

    result = realloc(result, size * sizeof *result);
    return result;
}

void printArr(char **arr, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%s\n", arr[i]);
    }
}

void clearArr(char **arr, int size) {
    for (int i = 0; i < size; ++i) {
        free(arr[i]);
    }
    free(arr);
    arr = NULL;
}

int compare(const void *a, const void *b) {
    return strcmp(*(const char **) a, *(const char **) b);
}

void sort(char **arr, int size) {
    qsort(arr, size, sizeof(char *), compare);
}

int main(int argc, char **argv) {
    if (argc < 2)
        exit(EXIT_FAILURE);

    int size = 0;

    char **arr = words(argv[1], &size);

    sort(arr, size);

    printArr(arr, size);

    clearArr(arr, size);
    printf("End of program.\n");
    return 0;
}
