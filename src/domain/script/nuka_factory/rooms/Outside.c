#include <stdio.h>
#include <string.h>

#include "Outside.h"

#include "../Script.h"
#include "../Tools.h"
#include "../Data.h"

#include "../../../../commons/Type.h"
#include "../../../../commons/Strings.h"
#include "../../../Status.h"

char** makeOutsideRoom(int cursor) {
    switch (cursor) {
        case 0:
            return _enter_makeOutsideRoom();
        case 1:
            return _leave_makeOutsideRoom();
        case 2:
            return _to_hall_makeOutsideRoom();
        case 3:
            return _kick_can_makeOutsideRoom();
        default:    
            return allocateStrings(0);
    }
}

char** _enter_makeOutsideRoom() {
    char** room = makeSelectorTemplate(4);

    const char* description = 
        "Eres un mensajero del Mojave Express destinado a Yermo Capital\n"
        "Te encuentras fatigado y deshidratado tras tan largo viaje\n"
        "Ante ti yacen los restos de la antigua fábrica de Nuka Cola.\n";
    strcpy(room[0], description);

    strcpy(room[1], "Sigues tu camino, parece un lugar peligroso, mejor no correr riesgos");
    strcpy(room[2], "Entras, seguro que dentro hay ingentes cantidades de Nuka Cola");
    strcpy(room[3], "Pateas una lata arrastrada por el viento");

    return room;
}

char** _leave_makeOutsideRoom() {
    status = game_over;
    incrementExperience(1);

    char** room = makeTemplate();

    if(poison == 0) {
        caps = caps + 250;
        const char* description = 
            "Sigues tu camino hasta La Ciudadela y completas el encargo\n"
            "Pero acabas muriendo a causa de la deshidratación.\n";
        strcpy(room[0], description);
        return room;
    }

    const char* description = 
        "Sigues tu camino hasta La Ciudadela\n"
        "El veneno acaba matandote antes de que puedas llegar a algún asentamiento cercano.\n";
    strcpy(room[0], description);

    return room;
}

char** _to_hall_makeOutsideRoom() {
    location = INSIDE_HALL_ROOM;

    incrementExperience(2);

    char* introduction =
        "Entras en el edificio\n"
        "Un pequeño foco de luz proviniente de un agujero en la pared ilumina la oscura habitación\n"
        "Huele a humedad y a cerrado, no ha pasado nadie por aquí en mucho tiempo.\n\n";


    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);;
}

char** _kick_can_makeOutsideRoom() {
    char* introduction = "Puede que no haya sido la decisión más brillante que has tomado en tu vida, si lo repitiese en qué me convertiría...\n";

    if(poison == 0) {
        decrementExperience(1);

        poison = 1;

        introduction = 
            "Dentro de la lata hay una cria de mutascorpius venenoso que te pica en la pierna al acercarte.\n"
            "¡Maldición! El veneno de estos insectos es de acción rápida, debo encontrar algo que neutralizarlo.\n\n";
    }

    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);;
}