#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Bottler.h"

#include "../Script.h"
#include "../Tools.h"
#include "../Data.h"

#include "../../../../commons/Type.h"
#include "../../../../commons/Strings.h"
#include "../../../Status.h"

#define terminal_locked 0
#define terminal_unlocked 1
#define terminal_destroyed 2

int terminalStatus = terminal_locked;
int attemps = 3;

char** makeBottlerRoom(int cursor) {
    location = INSIDE_BOTTLER_ROOM;

    int isFight = secutityAlerted == true && ghoulWaked == true;

    switch (cursor) {
        case 0:
            return _enter_makeBottlerRoom();
        case 1:
            if(isFight) {
                return _fight_makeBottlerRoom();
            }
            return _terminal_hack_makeBottlerRoom();
        case 2:
            if(isFight) {
                return _exit_makeBottlerRoom();
            }
            return _up_staris_makeBottlerRoom();
        case 3:
            return _terminal_crush_makeBottlerRoom();
        case 4:
            return _exit_makeBottlerRoom();
        default:    
            return allocateStrings(0);
    }
}

char** _enter_makeBottlerRoom() {
    int isFight = secutityAlerted == true && ghoulWaked == true;
    if(isFight) {
        return _enter_alerted_makeBottlerRoom();
    }
    return _enter_unalerted_makeBottlerRoom();
}

char** _enter_unalerted_makeBottlerRoom() {
    char** room = makeSelectorTemplate(5);

    const char* description = 
        "Te encuentras en una sala enorme llena de chatarra en la que se encuentra una máquina monstruosa\n"
        "La gigantesca mole de hierro es la embotelladora de Nuka Cola.\n";

    if(terminalStatus == terminal_locked) {
        description = concatenate(description,
            "Produce un ruido ensordecedor, pero no parece hacer nada.\n\n"
            "Parece que la máquina se puede apagar, hay un terminal en una de las columnas de la sala.\n\n"
        );
    }
    if(terminalStatus == terminal_unlocked) {
        description = concatenate(description, 
            "No hay energía, pero el terminal sigue encendido\n\n"
        );
    }
    if(terminalStatus == terminal_destroyed) {
        description = concatenate(description, 
            "El terminal es chatarra\n\n"
        );
    }

    description = concatenate(description, 
            "Cerca de la puerta hay unas escaleras que llevan al piso superior, parece una oficina.\n\n"
        );

    strcpy(room[0], description);

    strcpy(room[1], "Pirateo el terminal, mi padre me enseño a trabajar con lenguaje de programación RustCo");
    strcpy(room[2], "Subo al piso superior");
    strcpy(room[3], "Machaco el terminal, la programación es para empollones");
    strcpy(room[4], "Mejor regreso a la puerta de la entrada");

    return room;
}

char** _enter_alerted_makeBottlerRoom() {
    char** room = makeSelectorTemplate(3);

    const char* description = 
        "¡El necrofago se está enfrentando a dos señores mañosos!\n"
        "El duo de robots estan ganando terreno a la desdichada bestia, sería una pena que alguien interviniese...\n\n";

    strcpy(room[0], description);

    strcpy(room[1], "Intervenir, por supuesto ¡Esos tres van a sentir en sus carnes el poder del átomo!.");
    strcpy(room[2], "No me gustan los lios, mejor les dejo tranquilos...");

    return room;
}

char** _terminal_hack_makeBottlerRoom() {
    if(terminalStatus == terminal_locked) {
        return _terminal_lock_makeBottlerRoom();
    }
    return _terminal_unlock_makeBottlerRoom();
}

char** _terminal_lock_makeBottlerRoom() {
    char* bufferPassword = takeBuffer(buffer);

    if(strlen(bufferPassword) > 0) {
        int inputPassword = atoi(bufferPassword);
        free(bufferPassword);

        if(password == inputPassword) {
            terminalStatus = terminal_unlocked;
            incrementExperience(2);
            caps = caps +  1000;

            char* introduction = 
                "Contraseña aceptada\n\n"
                "El ruido cesa y vuelves a la entrada de la habitación, de vuelta te encuentras una caja mohosa llena de brillantes chapas nuevecitas.\n\n";

            char** room = makeEnterRoom();
            return concatenateAuxIntroduction(introduction, room);
        }

        attemps--;

        if(attemps == 1) {
            secutityAlerted = true;
        }

        if(attemps > 0) {
            char* introduction = 
                "Contraseña incorrecta\n"
                "Abandonas el terminal y vuelves a la entrada\n\n";

            char** room = makeEnterRoom();
            return concatenateAuxIntroduction(introduction, room);
        }

        status = game_over;

        char** room = makeTemplate();

        char* description = 
            "El terminal se bloquea y saltan las alarmas\n"
            "La computadora se empieza a calentar\n"
            "Comienza a desprender un brillo rojo de aspecto peligroso\n"
            "Tus reflejos de ratatopo de escayola se quedan cortos y el terminal te explota en las narices.\n\n";

        strcpy(room[0], description);
        
        return room;
    }

    input = true;

    char** room = makeTemplate();

    char* description =
        "La embotelladora no se puede apagar desdel terminal, pero puedes desviar la corriente que alimenta la sala\n"
        "¡Maldición! El terminal requiere contraseña numérica\n\n"
        "Introduce la contraseña\n\n";

    strcpy(room[0], description);
            
    return room;
}

char** _terminal_unlock_makeBottlerRoom() {
    char* introduction = "";
    if(terminalStatus == terminal_unlocked) {
        introduction = "El terminal está bloqueado\n\n";
    }
    if(terminalStatus == terminal_destroyed) {
        introduction = "Dificilmente...\n\n";
    }

    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);
}

char** _fight_makeBottlerRoom() {
    char** room = makeTemplate();
    
    status = game_win;
    range = RANGE_ATOM_CHILD;
    caps = caps + 3500;
    
    incrementExperience(5);

    char* description = reloadFatMan();

    description = concatenate(description,
        "\n\nAl impactar el proyectil se produce una explosión monumental que anula todos tus sentidos.\n\n"
        "Al recuperar la consciencia te das cuenta de que la explosión te ha sacado del edificio... Bueno, lo que queda de él\n"
        "De pie, a tu lado, se encuentran unos comerciantes de caravanas\n"
        "Observando como el humo que sale del crater donde antes estaba la fábrica se eleva hipnóticamente hasta los confines del ceniciento cielo del yermo.\n"
        "El lanzagranadas de poco te vale sin munición, así que se lo cambias a los comerciantes por tres Nuka Colas y Dos Nuka cola Quantum'\n"
        "Y así, magullado pero exitoso prosigues tu camino hacia La Ciudadela, brillante como una Nuka Cola Quartz y con el gaznate refrescado\n"
        "Esperemos que allí tengan rad-away grandes cantidades.\n"
    );
    
    strcpy(room[0], description);
}

char ** _up_staris_makeBottlerRoom() {
    char** room = makeTemplate();
    
    char* description = "";

    if(terminalStatus == terminal_locked) {
        status = game_over;

        description = 
            "Subes a la oficina por unas escaleras metálicas jerrumbrosas.\n"
            "¡Maldición! hay una torreta de seguridad y al detectarte se activan las alarmas\n"
            "Entre la torreta y los robots te hacen picadillo (literalmente).\n\n";
    }

    if(terminalStatus == terminal_unlocked) {
        status = game_win;
        dry = false;
        range = RANGE_QUANTUM;
        caps = caps + 2000 - 55;
        
        incrementExperience(5);

        description = 
            "Subes a la oficina por unas escaleras metálicas jerrumbrosas, que parecen retorcerse a cada paso que das, haciendo más ruido que la propia máquina.\n"
            "Te topas con un despacho muy bien equipado y bastante lujoso.\n"
            "En uno de los armarios encuentras un rifle laser de triple haz ¡Cómo los que llevan los caciques super mutantes! y un saco con 2000 chapas.\n\n"
            "El ruido de los escalones ha atraido a unos robots operarios del edificio\n"
            "Con tu nueva arma no te suponen el menor problema.\n\n"
            "Sales del edificio por una salida de incencios en el momento que pasa una caravana de suministros\n"
            "Cambias cincuenta y cinco chapas por una Nuka Cola Quantum y habiendo repuesto fuerzas y con una nueva historia que contar prosigues tu camino a la ciudadela\n\n";
    }
    if(terminalStatus == terminal_destroyed) {
        status = game_win;
        dry = false;
        range = RANGE_NUKA;
        caps = caps + 1000;
        
        incrementExperience(2);

        description = 
            "Subes a la oficina por unas escaleras metálicas jerrumbrosas de dudosa integridad.\n"
            "Te encuentras con el despacho de lo que en su día fuera un alto cargo de la fábrica, encima de la mesa hay una bolsa con chapas.\n"
            "Mientras las cuentas te ataca un operario robot que ha subido sigilosamente por las escaleras.\n\n"
            "El botin se desperdiga por todo el despacho.\n"
            "Recoges las pocas chapas que puedes, sales por una ventana y bajas por la escalera de incendios exterior\n"
            "El señor mañoso se escacharra golpeandose contra el suelo al vencer las escaleras, dejando caer una botella de Nuka Cola que portaba consigo.\n"
            "Y así con una historia nueva y la sed calmada continuas tu viaje a la ciudadela\n\n";
    }

    strcpy(room[0], description);
        
    return room;
}

char** _terminal_crush_makeBottlerRoom() {
    char* introduction = "";

    if(terminalStatus == terminal_destroyed) {
        introduction = "¡Unga unga!\n\n";
    }
    if(terminalStatus == terminal_unlocked) {
        introduction = "No parece necesario, mejor ahorrar fuerzas\n\n";
    }
    if(terminalStatus == terminal_locked) {
        terminalStatus = terminal_destroyed;
        incrementExperience(1);

        introduction = 
            "Alardeando de toda tu fuerza primigenia aplastas el teminal con un pedazo de escombro que encuentras en el suelo.\n\n"
            "Mil chispas revolotean por los alrededores\n"
            "Una alarma estridente suena por unos pocos segundos para quedarse todo en silencio\n"
            "No hay electricidad.\n\n"
            "Un señor mañoso aparece en escena destrozando todo a su paso\n"
            "Lo derrotas a duras penas con los restos del terminal, que ha pasado a mejor vida.\n\n";
    }

    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);
}

char** _exit_makeBottlerRoom() {
    location = INSIDE_HALL_ROOM;

    char* introduction = "Regresas a la entrada.\n\n";

    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);
}