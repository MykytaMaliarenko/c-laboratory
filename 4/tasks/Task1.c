//
// Created by Mykyta Maliarenko on 17.02.2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char SYMBOLS_TO_REMOVE[] = {',', ';', ':', '!', ' ', '?'};

char* inputStr(char* string);

char* removeSymbols(char* string, char* symbolsToRemove);

bool contains(char a, char* string);


void RemoveSymbols()
{
    char* string;
    for (int i = 0; i < 3; i++)
    {
        printf("Input %d-st string:\n", i + 1);
        string = inputStr("");
        printf("%s\n\n", removeSymbols(string, SYMBOLS_TO_REMOVE));
        free(string);
    }
}

char* inputStr(char *string)
{
    int c;
    string = malloc(sizeof(char));

    string[0]='\0';

    for(int i=0; i<100 && (c=getchar())!='\n' && c != EOF ; i++)
    {
        string = realloc(string, (i+2)*sizeof(char));
        string[i] = (char) c;
        string[i+1] = '\0';
    }

    return string;
}

char* removeSymbols(char* string, char* symbolsToRemove)
{
    unsigned int len = strlen(string);
    unsigned int pointer = 0;
    char* res = (char*) calloc(len, sizeof(float));

    for (int i = 0; i < len; i++)
    {
        if (!contains(string[i], symbolsToRemove))
        {
            res[pointer] = string[i];
            pointer++;
        }
    }

    return res;
}

bool contains(char a, char* string)
{
    unsigned int len = strlen(string);
    for (int i = 0; i < len; i++)
    {
        if (string[i] == a)
            return true;
    }

    return false;
}