#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "TaleScriptMap.h"
#include "TaleScript.h"
#include "Utils.h"
#include "Status.h"
#include "Printer.h"

#define TALE_CODE "NukaFactory"

#define RANGE_ATOM_CHILD "AtomChild"
#define RANGE_NUKA "Nuka"
#define RANGE_QUANTUM "Quantum"
#define RANGE_BIG_BOY "BigBoy"

int location = OUTSIDE_ROOM_ENTRANCE;

int status = game_continue;
int length = 0;

int experience = 0;
double multiplier = 1.0;
char* range = RANGE_NUKA;
int poison = 0;

int caps = 0;
int fatMan = false;

char* initialize(int cursor) {
    srand(time(NULL));

    char* welcome = 
        "/----------------------------------------------------|\n"
        "| Wasteland Tales: La Siniestra Fábrica de Nuka-Cola |\n"
        "|----------------------------------------------------/\n";
    return welcome;
}

int getLength() {
    return length;
}

int getStatus() {
    return status;
}

char** makeRoom(int cursor) {
    char** room;
    
    switch (location) {
        case OUTSIDE_ROOM_ENTRANCE:
            room = makeOutsideRoom(cursor);
            break;
        case INSIDE_HALL_ROOM:
            room = makeInsideHallRoom(cursor);
            break;
        case INSIDE_CANTEEN_ROOM:
            room = makeInsideCanteenRoom(cursor);
            break;
        default:    
            return allocateStrings(0);
    }

    if(status == game_over) {
        poison = 0;
    }

    int auxLength = 1;
    char** auxMessages = allocateStrings(auxLength);
    auxMessages[0] = poisonCheck();

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
            return _0_makeOutsideRoom();
        case 1:
            return _1_makeOutsideRoom();
        case 2:
            return _2_makeOutsideRoom();
        case 3:
            return _3_makeOutsideRoom();
        default:    
            return allocateStrings(0);
    }
}

char** _0_makeOutsideRoom() {
    length = 4;
    char** strings = allocateStrings(length);

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

char** _1_makeOutsideRoom() {
    status = game_over;
    experience = experience + 1;

    length = 1;
    char** strings = allocateStrings(1);

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

char** _2_makeOutsideRoom() {
    location = INSIDE_HALL_ROOM;

    experience = experience + 2;
    char* introduction =
        "Entras en el edificio\n"
        "Un pequeño foco de luz proviniente de un agujero en la pared ilumina la oscura habitación\n"
        "Huele a humedad y a cerrado, no ha pasado nadie por aquí en mucho tiempo.\n\n";


    char** room = makeRoom(0);
    return concatenateAuxIntroduction(introduction, room);;
}

char** _3_makeOutsideRoom() {
    experience = experience - 3;

    char* introduction = "Hacerlo una vez ya fue estúpido, si volviese a patear la lata en que me convertiría...\n";

    if(poison == 0) {
        poison = 1;

        introduction = 
            "Dentro de la lata hay un mutascorpius venenoso que te pica en la pierna al acercarte\n"
            "El veneno de estos insectos es de acción rápida, debo encontrar algo que neutralizarlo.\n\n";
    }

    char** room = makeRoom(0);
    return concatenateAuxIntroduction(introduction, room);;
}


/****************************/
/*                          */
/*      Building  Hall      */
/*                          */
/****************************/

char** makeInsideHallRoom(int cursor) {
    location = INSIDE_HALL_ROOM;

    switch (cursor) {
        case 0:
            return _0_makeInsideHallRoom();
        case 1:
            return _1_makeInsideHallRoom();
        case 4:
            return _4_makeInsideHallRoom();
        default:    
            return allocateStrings(0);
    }
}

char** _0_makeInsideHallRoom() {
    length = 5;
    char** strings = allocateStrings(length);

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

char** _1_makeInsideHallRoom() {
    location = INSIDE_CANTEEN_ROOM;

    char* introduction = 
        "Pese a que tu intuición te dice que no, acabas entrando a la sala de la izquierda\n"
        "Es la cafetería de la fábrica\n"
        "Recostado en una de las paredes se deja ver un bulto.\n\n";

    char** room = makeRoom(0);
    return concatenateAuxIntroduction(introduction, room);
}

char** _4_makeInsideHallRoom() {
    length = 1;
    char** strings = allocateStrings(length);

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
    experience = multiplier * 10 + experience;

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

int ghoulWaked = false;
int bagRegistered = false;
int password = 0;

char** makeInsideCanteenRoom(int cursor) {
    location = INSIDE_CANTEEN_ROOM;

    if(password == 0) {
        password = rand() % 9000 + 1000;
    }

    switch (cursor) {
        case 0:
            return _0_makeInsideCanteenRoom();
        case 1:
            return _1_makeInsideCanteenRoom();
        case 2:
            return _2_makeInsideCanteenRoom();
        case 3:
            return _3_makeInsideCanteenRoom();
        default:    
            return allocateStrings(0);
    }
}

char** _0_makeInsideCanteenRoom() {
    length = 4;
    char** strings = allocateStrings(length);
    
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
            "El necrófago ya no se encuentra en la sala\n"
            "Pero la bolsa sigue en su sitio.\n";
    strcpy(strings[0], description);

    strcpy(strings[1], "Ya tengo todo lo que necesito, mejor me doy la vuelta");
    strcpy(strings[2], "¿Qué habrá en la mochila?");
    strcpy(strings[3], "Voy a volver a revisar el agujero de la pared");

    return strings;
}

char** _1_makeInsideCanteenRoom() {
    location = INSIDE_HALL_ROOM;

    char* introduction = "Vuelves a la sala principal.\n\n";

    char** room = makeRoom(0);
    return concatenateAuxIntroduction(introduction, room);
}

char** _2_makeInsideCanteenRoom() {
    location = INSIDE_HALL_ROOM;

    char* introduction = "La mochila no tiene nada de valor, solo la nota amarilla\n";

    if(bagRegistered == false) {
        bagRegistered = true;

        experience = experience + 2;
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

    char** room = makeRoom(0);
    return concatenateAuxIntroduction(introduction, room);
}

char** _3_makeInsideCanteenRoom() {
    if(ghoulWaked == false) {
        char* description = 
            "Pateas al monstuo\n"
            "Pese a ser un alfeñique y estar en descomposición tiene mucha fuerza y agilidad\n"
            "¡Es una necrófago segador!\n";

        if(1 == 0) {
            //TODO
        }

        status = game_over;

        length = 1;
        char** strings = allocateStrings(length);

        description = concatenate(description, 
            "\nNo te da tiempo a desenfundar el arma antes de que la abominación te salte al cuello.\n"
        );

        strcpy(strings[0], description);

        return strings;
    }

    char* introduction = "No hay nada, solo escombros\n";

    char** room = makeRoom(0);
    return concatenateAuxIntroduction(introduction, room);
}

/****************************/
/*                          */
/*           MISC           */
/*                          */
/****************************/

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

char* poisonCheck() {
    if(poison >= 1) { 
        poison++;
        experience--;
    }

    if(poison == 3) {
        return "Sientes un ligero hormigueo en los dedos";
    }  
    if(poison == 5) {
        return "Te sientes mareado";
    }  
    if(poison >= 7) { 
        status = game_over;
        return "El veneno te deja sin fuerzas y te desvaneces";
    }

    if(poison == -7) {
        poison = 0;
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