//
// Created by Mykyta Maliarenko on 19.02.2020.
//
#include "../helpers/Helpers.h"
#include <stdio.h>


void printBinary(int n, int k);


void ToBinary()
{
    int n = IntInputWithValidating("Input your number:", PositiveInt);
    printBinary(n, 1 << 16);
}

void printBinary(int n, int k)
{
    if (k != 0)
    {
        if (n & k)
            printf("1");
        else
            printf("0");

        k >>= 1;
        printBinary(n, k);
    } else {
        printf("\n");
    }
}