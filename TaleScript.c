#include <string.h>

#include "TaleScript.h"
#include "Utils.h"

#define TALE_CODE "NukaFactory"

#define OUTSIDE_ROOM_ENTRANCE 0

int location = OUTSIDE_ROOM_ENTRANCE;

int status = 0;
int length = 0;

const char* initialize(int cursor) {
    const char* welcome = 
        "\n"
        "/----------------------------------------------------|\n"
        "| Wasteland Tales: La Siniestra Fábrica de Nuka-Cola |\n"
        "|----------------------------------------------------/\n"
        "\n";
    return welcome;
}

int getLength() {
    return length;
}

int getStatus() {
    return status;
}

char** makeOutsideRoom_0() {
    length = 4;
    char** strings = allocateStrings(length);

    // Description
    const char* description = 
        "Eres un mensajero del Mojave Express destinado a Yermo Capital\n"
        "Te encuentras fatigado y deshidratado tras tan largo viaje\n"
        "Ante ti yacen los restos de la antigua fábrica de Nuka Cola.\n";
    strcpy(strings[0], description);

    // Options
    strcpy(strings[1], "Sigues tu camino, parece un lugar peligroso, mejor no correr riesgos");
    strcpy(strings[2], "Entras, seguro que dentro hay ingentes cantidades de Nuka Cola");
    strcpy(strings[3], "Pateas una lata arrastrada por el viento");

    return strings;
}

char** makeOutsideRoom_1() {
    length = 1;
    status = -1;

    char** strings = allocateStrings(1);

    // Description
    const char* description = 
        "Sigues tu camino hasta La Ciudadela\n"
        "Pero acabas muriendo a causa de la deshidratación.\n";
    strcpy(strings[0], description);

    return strings;
}

char** makeOutsideRoom(int cursor) {
    switch (cursor) {
        case 0:
            return makeOutsideRoom_0();
        case 1:
            return makeOutsideRoom_1();
        default:    
            return allocateStrings(0);
    }

}

char** makeRoom(int cursor) {
    switch (location) {
        case OUTSIDE_ROOM_ENTRANCE:
            return makeOutsideRoom(cursor);
        default:    
            return allocateStrings(0);
    }
}