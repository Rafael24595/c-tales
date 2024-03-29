#include <stdio.h>
#include <string.h>

#include "Storage.h"

#include "../Script.h"
#include "../Tools.h"
#include "../Data.h"

#include "../../../../commons/Type.h"
#include "../../../../commons/Strings.h"
#include "../../../Status.h"

boolean mirelurksAlerted = false;

char** makeStorageRoom(int cursor) {
    location = INSIDE_STORAGE_ROOM;

    switch (cursor) {
        case 0:
            return _enter_makeStorageRoom();
        case 1:
            return _drink_quantum_makeStorageRoom();
        case 2:
            if(fatMan == true) {
                return _nuke_mirelurk_makeStorageRoom();
            }
            return _to_hall_makeStorageRoom();
        case 3:
            if(fatMan == true) {
                return _to_hall_makeStorageRoom();
            }
        default:    
            return allocateStrings(0);
    }
}

char** _enter_makeStorageRoom() {
    char** room = makeSelectorTemplate(4);

    const char* description = 
        "Según avanzas por el cavernoso corredor la luz se torna más intensa\n"
        "El pasillo desemboca en una sala enorme y luminosa inundada en su gran mayoría por un líquido azul.\n\n"
        "¡El dicho líquido es Nuka Cola Quantum! La joya de la corona de John C.Bradberton.\n"
        "El preciado trago esta custodiado por unos repugnantes hombres pinza resplandecientes.\n";
    strcpy(room[0], description);

    strcpy(room[1], "Arriesgarme a darle un trago");

    if(fatMan != true) {
        length = 3;
        strcpy(room[2], "Correr como alma que lleva al diablo, esos bichos son mortíferos");

        return room;
    }

    strcpy(room[2], "Con lo volatil que es la Quantum sería una locura usar aquí el fat-man... ¿No?");
    strcpy(room[3], "Correr como alma que lleva al diablo, esos bichos son mortíferos");

    return room;
}

char** _drink_quantum_makeStorageRoom() {
    if(mirelurksAlerted == false) {
        dry = false;
        mirelurksAlerted = true;

        location = INSIDE_HALL_ROOM;

        multiplier = 2;
        incrementExperience(3);

        if(poison >= 5) {
            poison = quantum_maniac_unnotified;
        }

        char* introduction = 
            "Con las manos formas un cuenco y le das un gran sorbo a la Nuka Cola\n"
            "Los hombres pinza te han visto, y te ves obligado a huir.\n\n"
            "Vuelves a la sala principal.\n\n";

        char** room = makeEnterRoom();
        return concatenateAuxIntroduction(introduction, room);
    }

    status = game_over;

    char** room = makeTemplate();

    char* description = "\nLos hombres pinza tienen buena memoria y no se puede razonar con ellos, tus restos acaban formando parte de sus gelatinosos nidos.\n";

    strcpy(room[0], description);
    
    return room;
}

char** _nuke_mirelurk_makeStorageRoom() {
    status = game_over;

    incrementExperience(23);

    char** room = makeTemplate();

    char* description = 
        "Decides hacer pastel de cangrejo a la Nuka Cola volando por los aires a los hipervitaminados crustáceos que han apoderado las catacumbas de la fábrica.\n\n";

    description = concatenate(description,
        reloadFatMan()
    );

    description = concatenate(description,
        "Nada más impactar la granada contra los hombres pinza la Nuka Cola Quantum reacciona a la radiación\n"
        "De una manera tan violenta que la explosión puede sentirse en el Jefferson Memorial.\n\n"
        "Jamás se volvió a saber del mensajero tras aquel desastre, apodado a día de hoy como 'El Segundo Megatón'\n"
    );

    strcpy(room[0], description);
    
    return room;
}

char** _to_hall_makeStorageRoom() {
    location = INSIDE_HALL_ROOM;

    char* introduction = 
        "Te das la vuelta y caminas sobre tus pasos.\n\n"
        "Vuelves a la sala principal.\n\n";

    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);
}