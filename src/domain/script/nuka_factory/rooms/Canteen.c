#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "Canteen.h"

#include "../Script.h"
#include "../Tools.h"
#include "../Data.h"

#include "../../../../commons/Type.h"
#include "../../../../commons/Strings.h"
#include "../../../Status.h"

boolean bagRegistered = false;

char** makeCanteenRoom(int cursor) {
    location = INSIDE_CANTEEN_ROOM;

    if(password == 0) {
        password = rand() % 9000 + 1000;
    }

    switch (cursor) {
        case 0:
            return _enter_makeCanteenRoom();
        case 1:
            return _to_hall_makeCanteenRoom();
        case 2:
            return _stole_bag_makeCanteenRoom();
        case 3:
            return _kick_ghoul_makeCanteenRoom();
        default:    
            return allocateStrings(0);
    }
}

char** _enter_makeCanteenRoom() {
    char** room = makeSelectorTemplate(4);
    
    if (ghoulWaked == false) {
        const char* description = 
            "Te acercas muy lentamente al cuerpo\n"
            "La luz no te deja distinguir muy bien los detalles pero a simple vista parece una persona enferma\n"
            "Viste con harapos y tiene una complexion excesivamente delgada. A su lado se puede distinguir una bolsa\n"
            "Tras pensar detenidamente te decides a actuar.\n";
        strcpy(room[0], description);

        strcpy(room[1], "Es probable que sea un necrofago y la mordedura del último hizo que el brazo me brillase en la oscuridad, doy la vuelta");
        strcpy(room[2], "Mi Pip-Boy dice que tengo el rango de sigilo alto, me voy a arriegar a quitarle la mochila");
        strcpy(room[3], "Los necrófagos son aberraciones, lo voy a patear");

        return room;
    }
    
    const char* description = 
            "El necrófago ya no se encuentra en la sala,\n"
            "pero la bolsa sigue en su sitio.\n";
    strcpy(room[0], description);

    strcpy(room[1], "Ya tengo todo lo que necesito, mejor me doy la vuelta");
    strcpy(room[2], "¿Qué habrá en la mochila?");
    strcpy(room[3], "Voy a volver a revisar el agujero de la pared");

    return room;
}

char** _to_hall_makeCanteenRoom() {
    location = INSIDE_HALL_ROOM;

    char* introduction = "Vuelves a la sala principal.\n\n";

    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);
}

char** _stole_bag_makeCanteenRoom() {
    location = INSIDE_HALL_ROOM;

    char* introduction = "La mochila no tiene nada de valor, solo la nota amarilla\n";

    if(bagRegistered == false) {
        bagRegistered = true;

        incrementExperience(2);
        caps = caps + 500;

        introduction = 
            "Consigues robar exitosamente la el petate y dentro te encuentras 500 chapas y una nota amarillenta\n";
    }

    char passwordResult[50];
    sprintf(passwordResult, "En la nota aparecen los siguientes números: %d\n", password);

    introduction = concatenate(introduction, 
        passwordResult
    );

    introduction = concatenate(introduction, 
        "Sales rápidamente antes de que el necrófago se de cuenta\n\n"
    );

    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);
}

char** _kick_ghoul_makeCanteenRoom() {
    if(ghoulWaked == false) {
        char* description = 
            "Pateas al monstuo.\n\n"
            "Pese a ser un alfeñique y estar en descomposición tiene mucha fuerza y agilidad.\n"
            "¡Es un necrófago segador!\n";

        if(secutityAlerted == true && poison == quantum_maniac) {
            incrementExperience(3);
            ghoulWaked = true;
            fatMan = true;

            description = concatenate(description,
                "\nEl zombie se levanta rápidamente\n"
                "Pero por alguna razón pasa de largo y no te ataca\n"
                "Te sobresaltas al ver tu reflejo en lo que queda de un espejo colgado en la pared\n"
                "¡Pareces un necrófago resplandeciente! El veneno ha debido reaccionar con la Nuka Cola.\n\n"
                "En la pared donde estaba recostado el necrófago encuentras un lanzagranadas fat-man con una cabeza nuclear\n"
                "Esto se va poner interesante.\n\n"
            );

            char** room = makeEnterRoom();
            return concatenateAuxIntroduction(description, room);
        }

        status = game_over;

        char** room = makeTemplate();

        description = concatenate(description, 
            "\nNo te da tiempo a desenfundar el arma antes de que la abominación te salte al cuello.\n"
        );

        strcpy(room[0], description);

        return room;
    }

    char* introduction = "No hay nada, solo escombros\n";

    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);
}