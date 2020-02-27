//
// Created by Mykyta Maliarenko on 14.02.2020.
//
#include <stdio.h>
#include <rpc.h>
#include <stdlib.h>
#include "string.h"

void InitConsole(int labNumber, char* labDescription)
{
    //setlocale(LC_ALL, "Rus");
    system("cls");
    //top border
    printf("%c", (char)218);
    for (int i = 0; i < 79; i++)
    {
        printf("%c", (char)196);
    }
    printf("%c\n", (char)191);

    for (int j = 0; j < 8; j++)
    {
        printf("%c", (char)179);
        for (int l = 0; l < 10; l++)
        {
            if (j == 0 && l == 3)
            {
                printf("Laboratorna rabota %d", labNumber);
                l += (strlen("Laboratorna rabota ") + 1) / 8;
                printf("\t");
            }
            else if (j == 2 && l == 0)
            {
                printf(labDescription);
                l += strlen(labDescription) / 8;
                printf("\t");
            }
            else if (j == 7 && l == 4)
            {
                printf(" 2020");
                l += strlen(" 2020") / 8;
                printf("\t");
            }
            else if (j == 5 && l == 0)
            {
                printf("Vukonav st. gr. KM-92");
                l += strlen("Vukonav st. gr. KM-92") / 8;
                printf("\t");
            }
            else if (j == 5 && l == 6)
            {
                printf("            Maliarenko Mykyta");
                l = 8;
            }
            else
            {
                printf("\t");
            }
        }
        printf("%c\n", (char)179);
    }

    //lower border
    printf("%c", (char)192);
    for (int m = 0; m < 79; m++)
    {
        printf("%c", (char)196);
    }
    printf("%c\n", (char)217);

    system("pause");
    system("cls");
}