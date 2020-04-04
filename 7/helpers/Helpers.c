//
// Created by Asus on 05.02.2020.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

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