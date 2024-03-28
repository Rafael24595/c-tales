#ifndef TALE_SCRIPT_H
#define TALE_SCRIPT_H

char*  initialize();
char*  header();
char*  ending();
int    getLength();
int    getStatus();
boolean requireInput();
char** makeInputRoom(int cursor, char* input);
char** makeRoom(int cursor);

#endif /* TALE_SCRIPT_H */