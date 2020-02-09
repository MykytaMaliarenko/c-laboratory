//
// Created by Asus on 05.02.2020.
//
#include <stdio.h>
#include <stdbool.h>

double DoubletInput(char* text) {
    double res;
    int error = 0;

    do {
        fflush(stdin);
        printf("%s", text);
        error = scanf("%lf", &res);
    } while(error != 1);

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