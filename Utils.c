#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Utils.h"

#define MAX_ROOM_OPTS_LEN 2040

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

char* concatenate(const char* str1, const char* str2) {
    size_t len1 = strlen(str1);
    size_t len2 = strlen(str2);
    char* result = (char*) malloc(len1 + len2 + 1);

    if (result == NULL) {
        perror("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}