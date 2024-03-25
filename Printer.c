#include <stdio.h>
#include <stdlib.h>

#include "Printer.h"

#define ANSI_COLOR_RESET   "\x1b[0m"
#define ANSI_BACKGROUND_WHITE   "\x1b[47m"

#define MAX_OUTPUT_LEN 100

void initilizeScreen() {
    system("chcp 65001");
}

char* inputMessage(const char* message) {
    printf(message);
    char* input = (char*) malloc(MAX_OUTPUT_LEN * sizeof(char));
    if (input == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    fgets(input, MAX_OUTPUT_LEN, stdin); 
    printf("\n");
    return input;
}

void writeMessage(const char* message) {
    printf(message);
}

void writeRoom(char** room, int length, int cursor) {
    printf("%s", room[0]);
    if(length > 1) {
        printf("\n¿Qué haces?\n\n");
    }
    for (size_t i = 1; i < length; i++) {
        if(i == cursor) {
            printf(ANSI_BACKGROUND_WHITE "%d.- %s.\n" ANSI_COLOR_RESET, i, room[i]);
            continue;
        }
        printf("%d.- %s\n", i, room[i]);
    }
    
}