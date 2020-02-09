//
// Created by Asus on 05.02.2020.
//

#ifndef INC_1_HELPERS_H
#define INC_1_HELPERS_H
#include <stdbool.h>

double DoubletInput(char* text);

double DoubleInputWithValidating(char* text, bool (*validator)(double));

bool Positive(double inp);

char CharInput(char* text);

char CharInputWithValidating(char* text, bool (*validator)(char));

char CharIn(char* text);

#endif //INC_1_HELPERS_H