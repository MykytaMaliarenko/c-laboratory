//
// Created by nam62 on 04.02.2020.
//
#include <stdio.h>
#include <stdbool.h>
#include "../helpers/Helpers.h"

void binprintf(int v);

int GetBite(unsigned short int number, int pos)
{
    int k = number >> pos;
    return k & 1;
}

void InputStruct() {
    unsigned short int res = 0;
    int user_id;
    bool r, w, e, x;

    user_id = IntInput("\nInput user id:");
    while (user_id > 128 || user_id < 0)
    {
        printf("\nNot Valid!");
        user_id = IntInput("\nInput user id:");
    }

    r = BoolInput("R:");
    w = BoolInput("W:");
    e = BoolInput("E:");
    x = BoolInput("X:");

    res |= user_id << 8;
    res |= r << 7;
    res |= w << 6;
    res |= e << 5;
    res |= x;

    printf("\nRes in HEX: %X\n", res);
}

void InputStructAsHex() {
    unsigned int n;

    printf("HEX:");
    scanf("%X", &n);
    fflush(stdin);

    printf("user id:%d", n >> 8);
    printf("\nR:%s", GetBite(n, 7) ? "true" : "false");
    printf("\nW:%s", GetBite(n, 6) ? "true" : "false");
    printf("\nE:%s", GetBite(n, 5) ? "true" : "false");
    printf("\nX:%s", GetBite(n, 0) ? "true" : "false");
}

void binprintf(int v)
{
    unsigned int mask=1<<((sizeof(unsigned short int)<<3)-1);
    while(mask) {
        printf("%d", (v&mask ? 1 : 0));
        mask >>= 1;
    }
}