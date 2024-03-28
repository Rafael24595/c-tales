#ifndef SCRIPT_MAP_H
#define SCRIPT_MAP_H

char*  initialize(int cursor);
char*  ending();
int    getLength();
int    getStatus();
char** makeInputRoom(int cursor, char* input);
char** makeEnterRoom();
char** makeRoom(int cursor);

#endif /* SCRIPT_MAP_H */