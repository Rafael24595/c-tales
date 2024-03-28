#ifndef DATA_H
#define DATA_H

#include "../../../commons/Type.h"

#define RANGE_ATOM_CHILD "AtomChild"
#define RANGE_NUKA "Nuka"
#define RANGE_QUANTUM "Quantum"
#define RANGE_BIG_BOY "BigBoy"

#define OUTSIDE_ROOM_ENTRANCE 0
#define INSIDE_HALL_ROOM 10
#define INSIDE_CANTEEN_ROOM 20
#define INSIDE_BOTTLER_ROOM 30
#define INSIDE_STORAGE_ROOM 40

int location;

int status;
int length;
boolean input;
char* buffer;

int experience;
int multiplier;
char* range;

int poison;
boolean dry;

int caps;
boolean fatMan;

boolean ghoulWaked;
int password;
boolean secutityAlerted;

#endif /* DATA_H */