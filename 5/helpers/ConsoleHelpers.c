//
// Created by Mykyta Maliarenko on 14.02.2020.
//
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <windows.h>

#define MAX_ROWS 40

static int cols = -1;
static int rows = -1;


void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

unsigned long int count_utf8_code_points(const char *s) {
    unsigned long int count = 0;
    while (*s) {
        count += (*s++ & 0xC0) != 0x80;
    }
    return count;
}

void getSizes()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    cols = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    system("cls");

    cols = cols > 2 ? cols - 2 : cols;
    rows = rows > 2 ? rows - 2 : rows;
}

void drawBorder()
{
    //top corners
    gotoxy(1, 0);
    printf("%c", (char)218);

    gotoxy(cols, 0);
    printf("%c", (char)191);

    //top border
    gotoxy(2, 0);
    for (int i=0; i < cols - 2; i++)
        printf("%c", (char) 196);
    printf("\n");

    //right and left border
    for (int i=0; i < rows; i++)
    {
        gotoxy(1, i+1);
        printf("%c", (char)179);
        gotoxy(cols, i+1);
        printf("%c", (char)179);
    }

    //bottom corners
    gotoxy(1, rows);
    printf("%c", (char)192);

    gotoxy(cols, rows);
    printf("%c", (char)217);

    //bottom border
    gotoxy(2, rows);
    for (int i=0; i < cols - 2; i++)
        printf("%c", (char) 196);
    printf("\n");
}

unsigned int calculateOffsetForXCenter(char* text)
{
    return llround( ((double) (cols - count_utf8_code_points(text))) / 2);
}

unsigned int calculateOffsetForYCenter()
{
    return llround(((double)rows) / 2);
}

void InitConsole(int labNumber, char* labDescription)
{
    getSizes();
    drawBorder();

    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    //Лабораторная работа #
    char* t = calloc(100, sizeof(char));
    sprintf(t, "Лабораторная работа #%d", labNumber);

    gotoxy(calculateOffsetForXCenter(t), 1);
    printf("%s", t);

    t = calloc(100, sizeof(char));
    sprintf(t, "Тема: '%s'", labDescription);

    gotoxy(2, calculateOffsetForYCenter());
    printf("%s", t);

    gotoxy(2, rows-2);
    printf("Виконав ст. гр. КМ-92");

    gotoxy(cols - 13, rows - 2);
    printf("Маляренко М.А");

    gotoxy(calculateOffsetForXCenter("2020"), rows - 1);
    printf("2020");

    //end
    gotoxy(0, rows + 1);

    system("pause");
    system("cls");
}