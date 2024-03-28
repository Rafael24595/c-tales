#ifndef TOOLS_H
#define TOOLS_H

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

#endif /* TOOLS_H */