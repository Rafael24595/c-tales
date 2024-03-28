#ifndef STRINGS_H
#define STRINGS_H

char** allocateStrings(int length);
void   freeStrings(char** strings, int length);
char*  concatenate(const char* str1, const char* str2);
char*  cloneString(char* string);

#endif /* STRINGS_H */
