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


#define INSIDE_HALL_ROOM 1
char** makeInsideHallRoom(int cursor);
char** _0_makeInsideHallRoom();
char** _4_makeInsideHallRoom();


char* reloadFatMan();
char* poisonCheck();
char** integrateAuxMessages(char** room, int auxLength, char** auxMessages);

#endif /* TALES_SCRIPT_MAP_H */