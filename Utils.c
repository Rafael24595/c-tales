#include <stdio.h>
#include <stdlib.h>

#include "Utils.h"

#define MAX_ROOM_OPTS_LEN 510

char** allocateStrings(int length) {
    char** strings = (char**) malloc(length * sizeof(char*));
    if (strings == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < length; i++) {
        strings[i] = (char*) malloc((MAX_ROOM_OPTS_LEN + 1) * sizeof(char));
        if (strings[i] == NULL) {
            fprintf(stderr, "Memory allocation failed.\n");
            exit(EXIT_FAILURE);
        }
    }

    return strings;
}

void freeStrings(char** strings, int length) {
    if (strings == NULL) {
        return;
    }

    for (int i = 0; i < length; i++) {
        free(strings[i]);
    }

    free(strings);
}