//
// Created by Asus on 05.02.2020.
//

#ifndef INC_1_HELPERS_H
#define INC_1_HELPERS_H
#include <stdbool.h>

int IntInput(char* text);

int IntInputWithValidating(char* text, bool (*validator)(int));

bool BoolInput(char* text);

double DoubletInput(char* text);

double DoubleInputWithValidating(char* text, bool (*validator)(double));

bool Positive(double inp);

char CharInput(char* text);

char CharInputWithValidating(char* text, bool (*validator)(char));

#endif //INC_1_HELPERS_H