#ifndef PRINTER_H
#define PRINTER_H

#define clear_screen() printf("\e[1;1H\e[2J")

#define hide_cursor() printf("\e[?25l")
#define show_cursor() printf("\e[?25h")

void  initilizeScreen();
char* inputMessage(const char* message);
void  writeMessage(const char* message);
void  writeRoom(char** room, int length, int cursor);

#endif /* PRINTER_H */
