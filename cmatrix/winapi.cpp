#include "winapi.h"
#include <Windows.h>

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO csbi;

int get_screen_width() {
    int screen_width;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    screen_width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    return screen_width;
}

int get_screen_height() {
    int screen_height;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    screen_height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    return screen_height;
}

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(hConsole, pos);
}

void hide_cursor() {
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(hConsole, &cci);
    cci.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &cci);
}
