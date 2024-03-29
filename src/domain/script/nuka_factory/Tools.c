#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "Tools.h"

#include "Data.h"

#include "../../../commons/Type.h"
#include "../../../commons/Strings.h"
#include "../../Status.h"

void updateBuffer(char * input) {
    buffer = input;
}

char* takeBuffer() {
    char* bufferAux = cloneString(buffer);
    free(buffer);
    buffer = "";
    return bufferAux;
}

char** makeTemplate() {
    return makeSelectorTemplate(1);
}

char** makeSelectorTemplate(int size) {
    length = size;
    return allocateStrings(length);
}

char** cleanSelectors(char** room) {
    char** roomAux = allocateStrings(1);
    strcpy(roomAux[0], room[0]);
    freeStrings(room, length);
    length = 1;
    return roomAux;
}

char** concatenateAuxIntroduction(char* introduction, char** room) {
    if(length > 0) {
        room[0] = concatenate(introduction, room[0]);
    }
    return room;
}

char* reloadFatMan() {
    return
        " \nCargas cuidadosamente el proyectil en el fat-man\n"
        "Un silbido agudo suena indicandote que esta listo para disparar\n"
        "Te colocas a una distancia segura y accionas el gatillo.\n\n";
}

void incrementExperience(int exp) {
    experience = multiplier * exp + experience;
}

void decrementExperience(int exp) {
    experience = experience - exp;
}

char* poisonCheck() {
    if(poison >= 1) { 
        poison++;
        experience--;
    }

    if(poison == 3) {
        return "Sientes un ligero hormigueo en los dedos.";
    }  
    if(poison == 5) {
        return "Te sientes mareado.";
    }  
    if(poison > 7) { 
        status = game_over;
        return "El veneno te deja sin fuerzas y te desvaneces.";
    }

    if(poison == quantum_maniac_unnotified) {
        poison = quantum_maniac;
        return "Parece que la radiación de la Nuka Cola Quantum ha contrarrestado el efecto del veneno";
    }

    return "";
}

char** concatenateAuxMessages(char** room, int auxLength, char** auxMessages) {
    if(length == 0) {
        return room;
    }

    for (size_t i = 0; i < auxLength; i++) {
        if(strlen(auxMessages[i]) == 0) {
            continue;
        }
        char* auxMessage = concatenate("\n", auxMessages[i]);
        auxMessage = concatenate(auxMessage, "\n");
        room[0] = concatenate(room[0], auxMessage);
    }

    freeStrings(auxMessages, auxLength);

    return room;
}