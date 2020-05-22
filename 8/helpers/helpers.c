//
// Created by Asus on 05.02.2020.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "string.h"

//G.O.T.Z. charToReplace charToReplaceWith
char* replaceData = "o0";
int replaceDataLen = 2;


void DefaultReplace(char* str)
{
    for (int i=0; i < strlen(str); i++)
    {
        for (int j=0; j < replaceDataLen; j+=2)
        {
            if (str[i] == replaceData[j])
                str[i] = replaceData[j+1];
        }
    }
}

void CleanStdinBuffer()
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

void TerminalClear()
{
    #ifdef _WIN32 || _WIN64
    system("cls");
    #elif __linux__
    system("clear");
    #endif
}

void TerminalPause()
{
    printf("\n...");
    int c = getchar();
}

int IntInput(char* text) {
    int res = 0;
    int error = 0;
    char* temp = calloc(25, sizeof(char));
    char* end;

    do {
        printf("%s", text);

        error = scanf("%s", temp);
        CleanStdinBuffer();
        if (error != 1)
            continue;

        DefaultReplace(temp);

        res = strtol(temp, &end, 0);
        if (*end == '\0')
            return res;
    } while(1);
}

int* PtrIntInput(char* text)
{
    int* res = calloc(sizeof(int), 1);
    int error = 0;
    char* temp = calloc(25, sizeof(char));
    char* end;

    do {
        printf("%s", text);

        error = scanf("%s", temp);
        CleanStdinBuffer();
        if (error != 1)
            continue;

        DefaultReplace(temp);

        *res = strtol(temp, &end, 0);
        if (*end == '\0')
            return res;
    } while(1);
}

int IntInputWithValidating(char* text, bool (*validator)(int))
{
    int res;
    bool isValid = false;

    do {
        res = IntInput(text);
        isValid = validator(res);
        if (isValid == false)
            printf("Not Valid!\n");
    } while(isValid == false);

    return res;
}

bool BoolInput(char* text) {
    char inp[1];
    int error = 0;

    do {
        printf("%s", text);
        error = scanf("%s", inp);
        if (error == 1 && (inp[0] == 't' || inp[0] == 'f'))
            break;
        CleanStdinBuffer();
    } while(1);

    return inp[0] == 't' ? true : false;
}

double DoubletInput(char* text) {
    double res = 0;
    int error = 0;
    char* temp = calloc(25, sizeof(char));
    char* end;

    do {
        printf("%s", text);

        error = scanf("%s", temp);
        CleanStdinBuffer();
        if (error != 1)
            continue;

        DefaultReplace(temp);

        res = strtod(temp, &end);
        if (*end == '\0')
            return res;

    } while(1);
}

double DoubleInputWithValidating(char* text, bool (*validator)(double)) {
    double res;
    bool isValid = false;

    do {
        res = DoubletInput(text);
        isValid = validator(res);
        if (isValid == false)
            printf("Not Valid!\n");
    } while(isValid == false);

    return res;
}

bool Positive(double inp) {
    return inp > 0;
}

bool PositiveInt(int inp) {
    return inp > 0;
}

char* InputString(char* text)
{
    printf("%s", text);
    int c;
    char* string = malloc(sizeof(char));

    string[0]='\0';

    for(int i=0; i<100 && (c=getchar())!='\n' && c != EOF ; i++)
    {
        string = realloc(string, (i+2)*sizeof(char));
        string[i] = (char) c;
        string[i+1] = '\0';
    }

    return string;
}

char* InputMultilineString(char* text)
{
    printf("%s", text);
    int c;
    char* string = malloc(sizeof(char));

    string[0]='\0';

    for(int i=0; i<100 && ( (c = getchar())!='\t') && c != EOF ; i++)
    {
        string = realloc(string, (i+2)*sizeof(char));
        string[i] = (char) c;
        string[i+1] = '\0';
    }

    return string;
}