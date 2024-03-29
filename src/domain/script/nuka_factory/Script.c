#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "Data.h"

#include "Tools.h"

#include "rooms/Outside.h"
#include "rooms/Hall.h"
#include "rooms/Canteen.h"
#include "rooms/Bottler.h"
#include "rooms/Storage.h"

#include "../../../commons/Type.h"
#include "../../../commons/Strings.h"
#include "../../Status.h"
#include "../TaleScript.h"
#include "Script.h"

#define TALE_CODE "NukaFactory"

char* initialize(int cursor) {
    srand(time(NULL));

    char* welcome = 
        "/----------------------------------------------------|\n"
        "| Wasteland Tales: La Siniestra Fábrica de Nuka-Cola |\n"
        "|----------------------------------------------------/\n";
    return welcome;
}

char* header() {
    char resultExperience[50];
    sprintf(resultExperience, "Lvl: %d   ", experience);
    char resultCaps[15];
    sprintf(resultCaps, "Caps: %d   ", caps);
    char resultFatman[15];
    sprintf(resultFatman, "Nuke: %d   ", fatMan);
    char resultDry[15];
    sprintf(resultDry, "Dry: %d   ", dry);
    char resultPoison[15];
    sprintf(resultPoison, "Poison: %d   ", poison / 2);
    char resultPassword[15];
    sprintf(resultPassword, "Note: %d   ", password);
    
    char* header = resultExperience;
    header = concatenate(header, resultCaps);
    if(fatMan == true) {
        header = concatenate(header, resultFatman);
    }
    if(poison > 0) {
        header = concatenate(header, resultPoison);
    }
    header = concatenate(header, resultDry);
    if(bagRegistered == true) {
        header = concatenate(header, resultPassword);
    }

    return header;
}

int getLength() {
    return length;
}

int getStatus() {
    return status;
}

boolean requireInput() {
    return input;
}

char** makeInputRoom(int cursor, char* input) {
    updateBuffer(input);
    return makeRoom(cursor);
}

char** makeEnterRoom() {
    return makeRoom(0);
}

char** makeRoom(int cursor) {
    input = false;

    if(password == 0) {
        password = rand() % 9000 + 1000;
    }

    char** room;
    switch (location) {
        case OUTSIDE_ROOM_ENTRANCE:
            room = makeOutsideRoom(cursor);
            break;
        case INSIDE_HALL_ROOM:
            room = makeHallRoom(cursor);
            break;
        case INSIDE_CANTEEN_ROOM:
            room = makeCanteenRoom(cursor);
            break;
        case INSIDE_BOTTLER_ROOM:
            room = makeBottlerRoom(cursor);
            break;
        case INSIDE_STORAGE_ROOM:
            room = makeStorageRoom(cursor);
            break;
        default:    
            return allocateStrings(0);
    }

    int auxLength = 1;
    char** auxMessages = allocateStrings(auxLength);
    auxMessages[0] = poisonCheck();

    if(status == game_over) {
        poison = 0;
        room = cleanSelectors(room);
    }

    return concatenateAuxMessages(room, auxLength, auxMessages);
}

char* ending() {
    char resultCaps[50];
    sprintf(resultCaps, "Chapas en posesión: %d\n", caps);
    char resultExperience[50];
    sprintf(resultExperience, "Nivel conseguido: %d\n", experience);
    char resultRange[50];
    sprintf(resultRange, "Rango: %s\n", range);
    
    char* ending = resultCaps;
    ending = concatenate(ending, resultExperience);
    ending = concatenate(ending, resultRange);
    ending = concatenate(ending, 
        "\n/-----------------------------------------------------------------------------------------------|"
        "\n|                                                                                               |"
        "\n|  !Felicidades! has completado el capítulo Wasteland Tales: La Siniestra Fábrica de Nuka-Cola  |"
        "\n|                                                                                               |"
        "\n|                                      Producido por ELB24                                      |"
        "\n|                                                                                               |"
        "\n|-----------------------------------------------------------------------------------------------/"
    );

    return ending;
}