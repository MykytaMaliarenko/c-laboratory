//
// Created by Mykyta Maliarenko on 21.05.2020.
//

#include "utils.h"
#include "stdio.h"
#include "helpers.h"


char* consolePeekFunc(char* funcs[], int len)
{
    for (int i = 0;i < len; i++)
        printf("%d) %s\n", i + 1, funcs[i]);

    int index = -1;
    while (1)
    {
        index = IntInput("\nFunc to execute:");
        index--;
        if (index >= 0 && index < len)
            break;
        else
            printf("Wrong index");
    }

    return funcs[index];
}