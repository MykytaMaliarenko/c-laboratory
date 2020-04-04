#include <stdio.h>
#include "Train/Train.h"
#include <windows.h>
#include "LinkedList/LinkedList.h"
#include "./Tasks/Task2.h"

void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


int main()
{
    Integers();
}
