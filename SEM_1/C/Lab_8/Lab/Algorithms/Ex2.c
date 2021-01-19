#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *remove_duplicates(char *source_string, char *target) {
    char *to_be_removed = NULL;
    char *copy_from = source_string;

    char *result = (char *) calloc(strlen(source_string), sizeof(char));

    do {
        to_be_removed = strstr(copy_from, target); // O(A*B) ???
        if (to_be_removed) {
            strncat(result, copy_from, to_be_removed - copy_from); // O(1)
            copy_from += to_be_removed - copy_from + strlen(target) + 1;
        }
    } while (to_be_removed != NULL);
    strncat(result, copy_from, to_be_removed - copy_from);
    return result;
}


int main() {
    //
    // Zlożoność: O(A^2*B)
    //
    char *string = "Jak sie nie ma, co sie lubi, to sie lubi, co sie ma."; // Niech len = A
    char *to_be_deleted = "sie"; // Niech len = B
    char *result = remove_duplicates(string, to_be_deleted);

    printf("Input: %s\n", string);
    printf("To be deleted: %s\n", to_be_deleted);
    printf("Ouput: %s\n", result);

    return 0;
}
