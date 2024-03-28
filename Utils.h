#ifndef UTILS_H
#define UTILS_H

char** allocateStrings(int length);
void   freeStrings(char** strings, int length);
char*  concatenate(const char* str1, const char* str2);
char*  cloneString(char* string);

#endif /* UTILS_H */
