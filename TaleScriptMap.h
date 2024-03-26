#ifndef TALES_SCRIPT_MAP_H
#define TALES_SCRIPT_MAP_H

char*  initialize(int cursor);
char*  ending();
int    getLength();
int    getStatus();
char** makeRoom(int cursor);


#define OUTSIDE_ROOM_ENTRANCE 0
char** makeOutsideRoom(int cursor);
char** _0_makeOutsideRoom();
char** _1_makeOutsideRoom();
char** _2_makeOutsideRoom();
char** _3_makeOutsideRoom();


#define INSIDE_HALL_ROOM 10
char** makeInsideHallRoom(int cursor);
char** _0_makeInsideHallRoom();
char** _1_makeInsideHallRoom();
char** _4_makeInsideHallRoom();


#define INSIDE_CANTEEN_ROOM 20
char** makeInsideCanteenRoom(int cursor);
char** _0_makeInsideCanteenRoom();
char** _1_makeInsideCanteenRoom();
char** _2_makeInsideCanteenRoom();
char** _3_makeInsideCanteenRoom();


char** concatenateAuxIntroduction(char* introduction, char** room);
char*  reloadFatMan();
char*  poisonCheck();
char** concatenateAuxMessages(char** room, int auxLength, char** auxMessages);

#endif /* TALES_SCRIPT_MAP_H */