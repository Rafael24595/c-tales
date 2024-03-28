#ifndef TALES_SCRIPT_MAP_H
#define TALES_SCRIPT_MAP_H

char*  initialize(int cursor);
char*  ending();
int    getLength();
int    getStatus();
char** makeRoom(int cursor);


#define OUTSIDE_ROOM_ENTRANCE 0
char** makeOutsideRoom(int cursor);
char** _enter_makeOutsideRoom();
char** _leave_makeOutsideRoom();
char** _to_hall_makeOutsideRoom();
char** _kick_can_makeOutsideRoom();


#define INSIDE_HALL_ROOM 10
char** makeHallRoom(int cursor);
char** _enter_makeHallRoom();
char** _to_canteen_makeHallRoom();
char** _to_bottler_makeHallRoom();
char** _to_storage_makeHallRoom();
char** _to_outside_makeHallRoom();


#define INSIDE_CANTEEN_ROOM 20

boolean bagRegistered;
int password;

char** makeCanteenRoom(int cursor);
char** _enter_makeCanteenRoom();
char** _to_hall_makeCanteenRoom();
char** _stole_bag_makeCanteenRoom();
char** _kick_ghoul_makeCanteenRoom();


#define INSIDE_BOTTLER_ROOM 30

boolean secutityAlerted;

char** makeBottlerRoom(int cursor);

char** _enter_alerted_makeBottlerRoom();
char** _enter_unalerted_makeBottlerRoom();

char** _fight_makeBottlerRoom();
char** _terminal_hack_makeBottlerRoom();
char** _terminal_lock_makeBottlerRoom();

char** _up_staris_makeBottlerRoom();

char** _terminal_crush_makeBottlerRoom();

char** _exit_makeBottlerRoom();


#define INSIDE_STORAGE_ROOM 40
char** makeStorageRoom(int cursor);
char** _enter_makeStorageRoom();
char** _drink_quantum_makeStorageRoom();
char** _to_hall_makeStorageRoom();
char** _nuke_mirelurk_makeStorageRoom();


void   updateBuffer(char * input);
char*  takeBuffer();
char** makeTemplate();
char** makeSelectorTemplate(int size);
char** cleanSelectors(char** room);
char** concatenateAuxIntroduction(char* introduction, char** room);
char*  reloadFatMan();
void   incrementExperience(int exp);
void   decrementExperience(int exp);
char*  poisonCheck();
char** concatenateAuxMessages(char** room, int auxLength, char** auxMessages);

#endif /* TALES_SCRIPT_MAP_H */