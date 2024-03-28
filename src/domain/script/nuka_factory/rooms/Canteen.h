#ifndef CANTEEN_H
#define CANTEEN_H

#include "../../../../commons/Type.h"

boolean bagRegistered;

char** makeCanteenRoom(int cursor);
char** _enter_makeCanteenRoom();
char** _to_hall_makeCanteenRoom();
char** _stole_bag_makeCanteenRoom();
char** _kick_ghoul_makeCanteenRoom();

#endif /* CANTEEN_H */