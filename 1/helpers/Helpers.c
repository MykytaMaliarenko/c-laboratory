//
// Created by Asus on 05.02.2020.
//
#include <stdio.h>
#include <stdbool.h>

int IntInput(char* text) {
    int res = 0;
    int error = 0;
    char term;

    do {
        printf("%s", text);
        error = scanf("%d%c", &res, &term);
        fflush(stdin);
    } while(error != 2 || term != '\n');

    return res;
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
        fflush(stdin);
    } while(1);

    return inp[0] == 't' ? true : false;
}

double DoubletInput(char* text) {
    double res;
    int error = 0;
    char term;

    do {
        printf("%s", text);
        error = scanf("%lf%c", &res, &term);
        fflush(stdin);
    } while(error != 2 || term != '\n');

    return res;
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

char CharInput(char* text) {
    char res;
    int error = 0;

    do {
        fflush(stdin);
        printf("%s", text);
        error = scanf("%c", &res);
    } while(error != 1);

    return res;
}

char CharInputWithValidating(char* text, bool (*validator)(char)) {
    char res;
    bool isValid = false;

    do {
        res = CharInput(text);
        isValid = validator(res);
        if (isValid == false)
            printf("Not Valid!\n");
    } while(isValid == false);

    return res;
}