#ifndef PRINTER_H
#define PRINTER_H

void  initilizeScreen();
void  writeInitialize(char* message);
void  writeEnding(char* message);
char* inputMessage(const char* message);
void  writeMessage(const char* message);
void  writeRoom(char** room, int length, int cursor);

void  clear_screen();
void  hide_cursor();
void  show_cursor();

#endif /* PRINTER_H */
