#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void remove_duplicates(char *source_string, char *target) {
    char *to_be_removed = NULL;
    char *copy_from = source_string;

    char *result = (char *) calloc(strlen(source_string), sizeof(char));

    do {
        to_be_removed = strstr(copy_from, target);
        if (to_be_removed) {
            strncat(result, copy_from, to_be_removed - copy_from);
            copy_from += to_be_removed - copy_from + strlen(target) + 1;
        }
    } while (to_be_removed != NULL);
    strncat(result, copy_from, to_be_removed - copy_from);
    printf("%s\n", result);
}


int main() {
    char *string = "Jak sie nie ma, co sie lubi, to sie lubi, co sie ma.";
    char *to_be_deleted = "sie";
    remove_duplicates(string, to_be_deleted);
    return 0;
}
