#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>

#include "commons/Type.h"
#include "commons/Strings.h"
#include "io/Printer.h"
#include "domain/Status.h"
#include "domain/script/TaleScript.h"

#define ENTER 13
#define DOWN 72
#define UP 80
#define EXIT 27

char * controls() {
    char* resultControls = (char*) malloc(255 * sizeof(char));
    char* header = 
        "/-----------------------|\n"
        "|  Controles del juego  |\n"
        "|-----------------------/\n\n";
    sprintf(resultControls, "%sSalir: %s  -  Arriba: %s  -  Abajo: %s  -  Aceptar: %s", header, "Esc", "⇧", "⇩", "Enter");
    return resultControls;
}

int main() {
    initilizeScreen();
    clear_screen();

    char* legend = controls();
    writeHeader(legend);
    free(legend);

    char* understand = inputMessage("Pulsa cualquier tecla para continuar:\n\n");
    free(understand);

    clear_screen();

    writeInitialize(initialize());

    char* start = inputMessage("Pulsa cualquier tecla para empezar:\n\n");
    free(start);

    int cursor = 1;
    char** room = makeEnterRoom();

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
    }

    return 0;
}