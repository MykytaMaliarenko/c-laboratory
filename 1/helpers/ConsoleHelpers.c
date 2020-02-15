//
// Created by Mykyta Maliarenko on 14.02.2020.
//
#include <stdio.h>
#include <rpc.h>

void InitConsole(int labNumber, char* labDescription)
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    printf("----Лабораторна работа #%d---\n", labNumber);
    printf("Тема: '%s'\n", labDescription);
    printf("Виконав ст. гр. КМ-92 Маляренко М.А\n");
}