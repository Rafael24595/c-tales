#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <ctype.h>
#include <locale.h>

#include "Utils.h"
#include "Printer.h"
#include "TaleScript.h"

#define ENTRANCE 0

#define ENTER 13
#define DOWN 72
#define UP 80
#define EXIT 27

int main() {
    initilizeScreen();
    clear_screen();

    const char* WELCOME_MESSAGE = initialize();                   
    writeMessage(WELCOME_MESSAGE);

    const char* START_INPUT_MESSAGE =
        "Pulsa cualquier tecla para empezar:\n"
        "\n";
    inputMessage(START_INPUT_MESSAGE);

    int cursor = 1;
    char** room = makeRoom(ENTRANCE);

    while (1) {
        hide_cursor();
        clear_screen();

        int length = getLength();
        writeRoom(room, length, cursor);

        int status = getStatus();
        if(status == -1) {
            writeMessage("\nHas perdido\n\n");
            break;
        }

        int key = getch();
        
        if(cursor > 1 && key == DOWN) {
            cursor--;
        }
        if(cursor < length - 1 && key == UP) {
            cursor++;
        }
        if(key == ENTER) {
            freeStrings(room, length);
            room = makeRoom(cursor);
        }
        if(key == EXIT) {
            show_cursor();
            char* input = inputMessage("\n¿Deseas salir? (Y/N)\n\n");
            if(tolower(*input) == *"y" || tolower(*input) == *"yes") {
                writeMessage("\nEl juego se está cerrando...\n\n");
                break;
            }
        }

        //printf("%d\n", key);
    }

    return 0;
}