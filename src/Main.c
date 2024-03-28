#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <sys/types.h>

#include <ctype.h>
#include <locale.h>

#include "commons/Type.h"
#include "commons/Strings.h"
#include "io/Printer.h"
#include "domain/Status.h"
#include "domain/script/TaleScript.h"

#define ENTRANCE 0

#define ENTER 13
#define DOWN 72
#define UP 80
#define EXIT 27

int main() {
    initilizeScreen();
    clear_screen();

    writeInitialize(initialize());

    inputMessage("Pulsa cualquier tecla para empezar:\n\n");

    int cursor = 1;
    char** room = makeRoom(ENTRANCE);

    while (1) {
        hide_cursor();
        clear_screen();

        int status = getStatus();
        int length = getLength();
        boolean input = requireInput();

        writeHeader(header());

        if(input != true) {
            writeRoom(room, length, cursor);
        } else {
            show_cursor();
            char* value = inputMessage(room[0]);
            room = makeInputRoom(cursor, value);
            continue;
        }

        if(status == game_win) {
            char* message = ending();
            writeEnding(message);
            break;
        }
        if(status == game_over) {
            writeEnding("Has perdido.");
            break;
        }

        if(length == 1) {
            writeMessage("\nContinuar.\n\n");
            cursor = 0;
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
            cursor = 1;
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