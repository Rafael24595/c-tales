#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "../../../commons/Type.h"
#include "../../../commons/Strings.h"
#include "../../Status.h"
#include "../TaleScript.h"
#include "Script.h"

#define TALE_CODE "NukaFactory"

#define RANGE_ATOM_CHILD "AtomChild"
#define RANGE_NUKA "Nuka"
#define RANGE_QUANTUM "Quantum"
#define RANGE_BIG_BOY "BigBoy"

int location = OUTSIDE_ROOM_ENTRANCE;

int status = game_continue;
int length = 0;
boolean input = false;
char* buffer = "";

int experience = 0;
int multiplier = 1;
char* range = RANGE_NUKA;

int poison = 0;
boolean dry = true;

int caps = 0;
boolean fatMan = false;

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
    buffer = input;
    return makeRoom(cursor);
}

char** makeEnterRoom() {
    return makeRoom(0);
}

char** makeRoom(int cursor) {
    input = false;

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


/****************************/
/*                          */
/*     Outside Building     */
/*                          */
/****************************/

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
    char** strings = makeSelectorTemplate(4);

    const char* description = 
        "Eres un mensajero del Mojave Express destinado a Yermo Capital\n"
        "Te encuentras fatigado y deshidratado tras tan largo viaje\n"
        "Ante ti yacen los restos de la antigua fábrica de Nuka Cola.\n";
    strcpy(strings[0], description);

    strcpy(strings[1], "Sigues tu camino, parece un lugar peligroso, mejor no correr riesgos");
    strcpy(strings[2], "Entras, seguro que dentro hay ingentes cantidades de Nuka Cola");
    strcpy(strings[3], "Pateas una lata arrastrada por el viento");

    return strings;
}

char** _leave_makeOutsideRoom() {
    status = game_over;
    incrementExperience(1);

    char** strings = makeTemplate();

    if(poison == 0) {
        caps = caps + 250;
        const char* description = 
            "Sigues tu camino hasta La Ciudadela y completas el encargo\n"
            "Pero acabas muriendo a causa de la deshidratación.\n";
        strcpy(strings[0], description);
        return strings;
    }

    const char* description = 
        "Sigues tu camino hasta La Ciudadela\n"
        "El veneno acaba matandote antes de que puedas llegar a algún asentamiento cercano.\n";
    strcpy(strings[0], description);

    return strings;
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
    char* introduction = "Hacerlo una vez ya fue estúpido, si volviese a patear la lata en que me convertiría...\n";

    if(poison == 0) {
        decrementExperience(3);

        poison = 1;

        introduction = 
            "Dentro de la lata hay un mutascorpius venenoso que te pica en la pierna al acercarte\n"
            "El veneno de estos insectos es de acción rápida, debo encontrar algo que neutralizarlo.\n\n";
    }

    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);;
}


/****************************/
/*                          */
/*      Building  Hall      */
/*                          */
/****************************/

char** makeHallRoom(int cursor) {
    location = INSIDE_HALL_ROOM;

    switch (cursor) {
        case 0:
            return _enter_makeHallRoom();
        case 1:
            return _to_canteen_makeHallRoom();
        case 2:
            return _to_bottler_makeHallRoom();
        case 3:
            return _to_storage_makeHallRoom();
        case 4:
            return _to_outside_makeHallRoom();
        default:    
            return allocateStrings(0);
    }
}

char** _enter_makeHallRoom() {
    char** strings = makeSelectorTemplate(5);

    const char* description = 
        "Se escuchan unos quejidos sospechosos en la sala que se encuentra a tu izquierda\n"
        "De la sala que tienes enfrente vienen unos ruidos ensordecedores de maquinaria\n"
        "Y por último el pasillo que tienes a tu derecha parece levemente iluminado por una luz azul celeste.\n";
    strcpy(strings[0], description);

    strcpy(strings[1], "Puede que alguien esté herido y necesite ayuda, y también desvalido es una buena oportunidad para hacer botín");
    strcpy(strings[2], "¡Máquinas monstruo a mi!");
    strcpy(strings[3], "Sientes como ese brillo azul te empieza a atraer poco a poco");
    strcpy(strings[4], "Mejor será que me vaya, soy alergico al polvo...");

    return strings;
}

char** _to_canteen_makeHallRoom() {
    location = INSIDE_CANTEEN_ROOM;

    char* introduction = 
        "Pese a que tu intuición te dice que no, acabas entrando a la sala de la izquierda\n"
        "Es la cafetería de la fábrica\n"
        "Recostado en una de las paredes se deja ver un bulto.\n\n";

    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);
}

char** _to_bottler_makeHallRoom() {
    location = INSIDE_BOTTLER_ROOM;

    char* introduction = 
        "Demostrando una carencia total de capacidad de autopreservación\n"
        "Te decides a entrar en la boca del lobo, pese a no saber si te vas a encontrar con algún peligro incierto\n"
        "Es posible que este estruendo lo produzca de uno de esos gorilas de hierro que fabricó RobCo antes de la guerra.\n\n";

    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);
}

char** _to_storage_makeHallRoom() {
    location = INSIDE_STORAGE_ROOM;

    char* introduction = 
        "Sigues el destello del pasillo como aturdido, al igual que las tochomoscas a los generadores eléctricos RobCo\n\n";

    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);
}

char** _to_outside_makeHallRoom() {
    char** strings = makeTemplate();

    char* description = 
            "Te das cuenta que no ha sido buena idea entrar y decides salir por donde has venido\n"
            "La puerta está atascada, tiras del pomo como si un yaoguai te estuviese intentando robar el almuerzo\n";

    if(fatMan == false) {
        status = game_over;

        description = concatenate(description, 
            "La puerta se abre, pero el techo vence, dejando caer un buen puñado escombros y un viejo señor mañoso estropeado que te terminan aplastando.\n"
        );
        strcpy(strings[0], description);

        return strings;
    }

    status = game_win;
    range = RANGE_BIG_BOY;
    caps = caps + 5000;
    
    incrementExperience(10);

    description = concatenate(description,
        "La fuerza bruta nunca es la solución, así que decides volar la puerta en pedazos con tu reciente adquisición\n"
    );
    description = concatenate(description,
        reloadFatMan()
    );
    description = concatenate(description,
        "La granada impacta en la puerta a una velocidad vertiginosa\n"
        "Pero esta en vez de estallar abre un boquete en la podrida madera dejando escapar al artefacto y provocando que el techo aledaño a la puerta se venga abajo\n"
        "Escuchas una explosión seguida de gritos, parece que al viejo proyectil no le bastaba con un simple pedazo de madera\n"
        "Trepas por los escombros de la entrada para contemplar a las víctimas de la insurrecta granada\n"
        "¡El explosivo ha impactado de lleno en una patrulla del Enclave!\n"
        "Registras los restos del 'accidente' y encuentras un jugoso botín: 5000 chapas y un rifle de plasma nuevecito con su correspondiente munición\n"
        "¡Resulta que una de las servoarmaduras sigue siendo funcional!¡Y el soldado que la portaba tiene encima un 'six pack' de Nuka Cola Quantum!\n"
        "\nY así, pertrechado con las mejores armas que la cienda puede proporcionar y con la certeza de que no vas a pasar sed durante una temporada\n"
        "Partes hacia La Ciudadela cual caballero de antaño con tu armadura resplandeciendo al sol\n"
    );
    strcpy(strings[0], description);

    return strings;
}


/****************************/
/*                          */
/*     Building Canteen     */
/*                          */
/****************************/

boolean ghoulWaked = false;
boolean bagRegistered = false;
int password = 0;

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
    char** strings = makeSelectorTemplate(4);
    
    if (ghoulWaked == false) {
        const char* description = 
            "Te acercas muy lentamente al cuerpo\n"
            "La luz no te deja distinguir muy bien los detalles pero a simple vista parece una persona enferma\n"
            "Viste con harapos y tiene una complexion excesivamente delgada. A su lado se puede distinguir una bolsa\n"
            "Tras pensar detenidamente te decides a actuar.\n";
        strcpy(strings[0], description);

        strcpy(strings[1], "Es probable que sea un necrofago y la mordedura del último hizo que el brazo me brillase en la oscuridad, doy la vuelta");
        strcpy(strings[2], "Mi Pip-Boy dice que tengo el rango de sigilo alto, me voy a arriegar a quitarle la mochila");
        strcpy(strings[3], "Los necrófagos son aberraciones, lo voy a patear");

        return strings;
    }
    
    const char* description = 
            "El necrófago ya no se encuentra en la sala,\n"
            "pero la bolsa sigue en su sitio.\n";
    strcpy(strings[0], description);

    strcpy(strings[1], "Ya tengo todo lo que necesito, mejor me doy la vuelta");
    strcpy(strings[2], "¿Qué habrá en la mochila?");
    strcpy(strings[3], "Voy a volver a revisar el agujero de la pared");

    return strings;
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

        char** strings = makeTemplate();

        description = concatenate(description, 
            "\nNo te da tiempo a desenfundar el arma antes de que la abominación te salte al cuello.\n"
        );

        strcpy(strings[0], description);

        return strings;
    }

    char* introduction = "No hay nada, solo escombros\n";

    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);
}


/****************************/
/*                          */
/*     Building Bottler     */
/*                          */
/****************************/

#define terminal_locked 0
#define terminal_unlocked 1
#define terminal_destroyed 2

boolean secutityAlerted = false;
int terminalStatus = terminal_locked;
int attemps = 3;

char** makeBottlerRoom(int cursor) {
    location = INSIDE_BOTTLER_ROOM;

    int isFight = secutityAlerted == true && ghoulWaked == true;

    switch (cursor) {
        case 0:
            if(isFight) {
                return _enter_alerted_makeBottlerRoom();
            }
            return _enter_unalerted_makeBottlerRoom();
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

char** _enter_unalerted_makeBottlerRoom() {
    char** strings = makeSelectorTemplate(5);

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

    strcpy(strings[0], description);

    strcpy(strings[1], "Pirateo el terminal, mi padre me enseño a trabajar con lenguaje de programación RustCo");
    strcpy(strings[2], "Subo al piso superior");
    strcpy(strings[3], "Machaco el terminal, la programación es para empollones");
    strcpy(strings[4], "Mejor regreso a la puerta de la entrada");

    return strings;
}

char** _enter_alerted_makeBottlerRoom() {
    char** strings = makeSelectorTemplate(3);

    const char* description = 
        "¡El necrofago se está enfrentando a dos señores mañosos!\n"
        "El duo de robots estan ganando terreno a la desdichada bestia, sería una pena que alguien interviniese...\n\n";

    strcpy(strings[0], description);

    strcpy(strings[1], "Intervenir, por supuesto ¡Esos tres van a sentir en sus carnes el poder del átomo!.");
    strcpy(strings[2], "No me gustan los lios, mejor les dejo tranquilos...");

    return strings;
}

char** _terminal_hack_makeBottlerRoom() {
    if(terminalStatus == terminal_locked) {
        return _terminal_lock_makeBottlerRoom();
    }

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
    char** strings = makeTemplate();
    
    status = game_win;
    range = RANGE_ATOM_CHILD;
    caps = caps + 3500;
    
    incrementExperience(5);

    char* description = reloadFatMan();

    description = concatenate(description,
        "\n\nAl impactar el proyectil se produce una explosión monumental que anula todos tus sentidos\n\n"
        "Al recuperar la consciencia te das cuenta de que la explosión te ha sacado del edificio... Bueno, lo que queda de él\n"
        "De pie, a tu lado, se encuentran unos comerciantes de caravanas\n"
        "Observando como el humo que sale del crater donde antes estaba la fábrica se eleva hipnóticamente\n"
        "El lanzagranadas de poco te vale sin munición, así que se lo cambias a los comerciantes por tres una Nuka Cola y Dos Nuka cola Quantum'\n"
        "Y así, magullado pero exitoso prosigues tu camino a La Ciudadela, brillante como una Nuka Cola Quartz y con el gaznate refrescado\n"
        "Esperemos que allí tengan gran cantidad rad-away\n"
    );
    
    strcpy(strings[0], description);
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

        char** strings = makeTemplate();

        char* description = 
            "El terminal se bloquea y saltan las alarmas\n"
            "La computadora se empieza a calentar\n"
            "Comienza a desprender un brillo rojo de aspecto peligroso\n"
            "Tus reflejos de ratatopo de escayola se quedan cortos y el terminal te explota en las narices.\n\n";

        strcpy(strings[0], description);
        
        return strings;
    }

    input = true;

    char** strings = makeTemplate();

    char* description =
        "La embotelladora no se puede apagar desdel terminal, pero puedes desviar la corriente que alimenta la sala\n"
        "¡Maldición! El terminal requiere contraseña numérica\n\n"
        "Introduce la contraseña\n\n";

    strcpy(strings[0], description);
            
    return strings;
}

char ** _up_staris_makeBottlerRoom() {
    char** strings = makeTemplate();
    
    char* description = "";

    if(terminalStatus == terminal_locked) {
        status = game_over;

        description = 
            "Subes a la oficina por unas escaleras metálicas jerrumbrosas.\n"
            "¡Maldición! hay una torreta de seguridad y al detectarte se activan las alarmas\n"
            "Entre la torreta y los robots te hacen picadillo (literalmente)\n\n";
    }

    if(terminalStatus == terminal_unlocked) {
        status = game_win;
        dry = false;
        range = RANGE_QUANTUM;
        caps = caps + 2000 - 55;
        
        incrementExperience(5);

        description = 
            "Subes a la oficina por unas escaleras metálicas jerrumbrosas, que parecen retorcerse a cada paso haciendo más ruido que la propia máquina\n"
            "Te topas con un despacho muy bien equipado y bastante lujoso.\n"
            "Encuentras un rifle laser de triple haz ¡Cómo los que llevan los caciques super mutantes! y un saco con 2000 chapas\n"
            "El ruido de los escalones ha atraido a unos robots operarios del edificio\n"
            "Con tu nueva arma no te suponen el menor problema.\n\n"
            "Sales del edificio en el momento que pasa una caravana de suministros\n"
            "Cambias cincuenta y cinco chapas por una Nuka Cola Quantum y habiendo repuesto fuerzas y con una nueva historia que contar prosigues tu camino a la ciudadela\n\n";
    }
    if(terminalStatus == terminal_destroyed) {
        status = game_win;
        dry = false;
        range = RANGE_NUKA;
        caps = caps + 1000;
        
        incrementExperience(2);

        description = 
            "Subes a la oficina por unas escaleras metálicas jerrumbrosas.\n"
            "Te encuentras con un despacho muy bien equipado, encima de la mesa hay una bolsa con chapas.\n"
            "Mientras las cuentas te ataca un operario robot que ha subido sigilosamente por las escaleras.\n\n"
            "El botin se desperdiga por todo el despacho.\n"
            "Recoges las pocas chapas que puedes, sales por una ventana y bajas por la escalera de incendios exterior\n"
            "El señor mañoso se escacharra golpeandose contra el suelo al vencer las escaleras, dejando caer una botella de Nuka Cola\n"
            "Y así con una historia nueva y la sed calmada continuas tu viaje a la ciudadela\n\n";
    }

    strcpy(strings[0], description);
        
    return strings;
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
            "Alardeando de toda tu fuerza primitiva plastas el teminal con un pedazo de escombro que encuentras en el suelo.\n\n"
            "Mil chispas revolotean por los alrededores\n"
            "Una alarma estridente suena por unos pocos segundos para quedarse todo en silencio\n"
            "No hay electricidad\n\n"
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


/****************************/
/*                          */
/*     Building Storage     */
/*                          */
/****************************/

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
    char** strings = makeSelectorTemplate(4);

    const char* description = 
        "Según avanzas por el cavernoso corredor la luz se torna más intensa\n"
        "El pasillo desemboca en una sala enorme y luminosa inundada en su gran mayoría por un líquido azul.\n\n"
        "¡El liquido azul es Nuka Cola Quantum! La joya de la corona de John C.Bradberton\n"
        "El preciado trago esta custodiado por unos repugnantes hombres pinza resplandecientes.\n";
    strcpy(strings[0], description);

    strcpy(strings[1], "Arriesgarme a darle un trago");

    if(fatMan != true) {
        length = 3;
        strcpy(strings[2], "Correr como alma que lleva al diablo, esos bichos son mortíferos");

        return strings;
    }

    strcpy(strings[2], "Con lo volatil que es la Quantum sería una locura usar aquí el fat-man... ¿No?");
    strcpy(strings[3], "Correr como alma que lleva al diablo, esos bichos son mortíferos");

    return strings;
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

    char** strings = makeTemplate();

    char* description = "\nLos hombres pinza tienen buena memoria y no se puede razonar con ellos, tus restos acaban formando parte de sus nidos.\n";

    strcpy(strings[0], description);
    
    return strings;
}

char** _to_hall_makeStorageRoom() {
    location = INSIDE_HALL_ROOM;

    char* introduction = 
        "Te das la vuelta y caminas sobre tus pasos.\n\n"
        "Vuelves a la sala principal.\n\n";

    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);
}

char** _nuke_mirelurk_makeStorageRoom() {
    status = game_over;

    incrementExperience(23);

    char** strings = makeTemplate();

    char* description = 
        "Decides hacer pastel de cangrejo a la Nuka Cola volando por los aires a los crustáceos inquilinos de la fábrica\n\n";

    description = concatenate(description,
        reloadFatMan()
    );

    description = concatenate(description,
        "Nada más impactar la granada contra los hombres pinza la Nuka Cola Quantum reacciona a la radiación\n"
        "De una manera tan violenta que la explosión puede sentirse en el Jefferson Memorial\n\n"
        "Jamás se volvió a saber del mensajero tras el desastre apodado como 'Segundo Megatón'\n"
    );

    strcpy(strings[0], description);
    
    return strings;
}


/****************************/
/*                          */
/*           MISC           */
/*                          */
/****************************/

void updateBuffer(char * input) {
    buffer = input;
}

char* takeBuffer() {
    char* bufferAux = cloneString(buffer);
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