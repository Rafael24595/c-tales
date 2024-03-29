#include <stdio.h>
#include <string.h>

#include "Hall.h"

#include "../Script.h"
#include "../Tools.h"
#include "../Data.h"

#include "../../../../commons/Type.h"
#include "../../../../commons/Strings.h"
#include "../../../Status.h"

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
    char** room = makeSelectorTemplate(5);

    const char* description = "Se escuchan unos quejidos sospechosos en la sala que se encuentra a tu izquierda\n";
    if(ghoulWaked == true) {
        description = "En la sala de la izquierda es donde reposaba el mutante\n";
    }

    description = concatenate(description, 
        "De la sala que tienes enfrente vienen unos ruidos ensordecedores de maquinaria\n"
        "Y por último el pasillo que tienes a tu derecha parece levemente iluminado por una luz azul celeste.\n"
    );

    strcpy(room[0], description);

    strcpy(room[1], "Puede que alguien esté herido y necesite ayuda... y también desvalido es una buena oportunidad para hacer algo de botín");
    strcpy(room[2], "¡Máquinas del demonio a mi!");
    strcpy(room[3], "Sientes como ese brillo azul te empieza a atraer poco a poco");
    strcpy(room[4], "Será mejor que me vaya, soy alergico al polvo..");

    return room;
}

char** _to_canteen_makeHallRoom() {
    location = INSIDE_CANTEEN_ROOM;

    char* introduction = 
        "Pese a que tu intuición te dice que no, acabas entrando a la sala de la izquierda\n"
        "Es la cafetería de la fábrica.\n"
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
        "Sigues el onírico destello por pasillo, aturdido, al igual que las tochomoscas a los generadores eléctricos RobCo.\n\n";

    char** room = makeEnterRoom();
    return concatenateAuxIntroduction(introduction, room);
}

char** _to_outside_makeHallRoom() {
    char** room = makeTemplate();

    char* description = 
            "Te das cuenta que no ha sido buena idea entrar y decides salir por donde has venido\n"
            "¡La puerta está atascada!, tiras del picaporte como si un yaoguai te estuviese intentando robar el almuerzo.\n";

    if(fatMan == false) {
        status = game_over;

        description = concatenate(description, 
            "La puerta se abre, pero el techo vence, dejando caer un buen puñado escombros y un viejo señor mañoso estropeado, los cuales te terminan aplastando.\n"
        );
        strcpy(room[0], description);

        return room;
    }

    status = game_win;
    range = RANGE_BIG_BOY;
    caps = caps + 5000;
    
    incrementExperience(10);

    description = concatenate(description,
        "La fuerza bruta nunca es la solución, así que decides volar en pedazos la puerta con tu reciente adquisición.\n"
    );
    description = concatenate(description,
        reloadFatMan()
    );
    description = concatenate(description,
        "La granada impacta en la desdichada lámina de contrachapado a una velocidad vertiginosa\n"
        "Pero esta, en vez de estallar, abre un boquete en la podrida madera dejando escapar al artefacto y provocando que el techo aledaño a la puerta se venga abajo.\n\n"
        "Escuchas una explosión seguida de unos gritos, parece que un simple pedazo de madera no bastaba para saciar la sed de caos del viejo proyectil.\n"
        "Trepas por los escombros de la entrada para contemplar a las víctimas de la insurrecta granada.\n"
        "¡El explosivo ha impactado de lleno contra una patrulla del Enclave!\n"
        "Registras los restos del 'accidente' y encuentras un jugoso botín: 5000 chapas y un rifle de plasma nuevecito con su correspondiente munición\n"
        "¡Resulta que una de las servoarmaduras sigue siendo funcional!¡Y el soldado que la portaba tiene encima un 'six pack' de Nuka Cola Quantum!\n\n"
        "Y así, pertrechado con las mejores armas que la ciencia puede proporcionar y con la certeza de que no vas a pasar sed durante una temporada\n"
        "Partes hacia La Ciudadela cual caballero de antaño con tu armadura resplandeciendo al marchito sol del yermo.\n"
    );
    strcpy(room[0], description);

    return room;
}