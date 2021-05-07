#define _GNU_SOURCE

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
    if (argc < 2)
        exit(EXIT_FAILURE);

    char *key = argv[1];

    char *line = NULL;
    int count = 0;
    size_t len = 0;

    while (getline(&line, &len, stdin) != -1) {
        int cur_c = 0;
        char *ptr = strcasestr(line, key);

        while (ptr != NULL) {
            cur_c++;
            ptr = strcasestr(ptr + 1, key);
        }

        if (cur_c > 0)
            printf("%s", line);

        count += cur_c;

        free(line);
        line = NULL;
    }

    printf("%d\n", count);
    free(line);
    line = NULL;

    printf("End of program.\n");
    return 0;
}
