//
// Created by nam62 on 04.02.2020.
//
#include <stdio.h>
#include "../helpers/Helpers.h"

void binprintf(int v);


void InputStruct() {
    int res = 0, c;//создаем 2 перм типа инт
    printf("Input data:\n");

    for(c = 0; c < 6; c++) {
        printf("%d user access:\n", c + 1);
        char userInput = CharInput("");//пользователь вводит данные(одно из 4-х букв)
        // Я решил кодировать буквы так: R-00 W-01 E-10 X-11
        switch (userInput) {
            case 'R':
                res |= 0 << c * 2;
                break;

            case 'W':
                res |= 1 << c * 2;
                break;

            case 'E':
                res |= 2 << c * 2;
                break;

            case 'X':
                res |= 3 << c * 2;
                break;

            default:
                c--;
                printf("Not valid\n");
        }
    }

    printf("Res in HEX: %X\n", res);
}

void InputStructAsHex() {
    unsigned int n;
    int c, k;
    fflush(stdin);

    scanf("%X", &n);

    for (c = 0; c < 6; c++)
    {
        k = (n & (1 << (c * 2))) >> (c * 2);//the first bite
        k |= ((n & (1 << ((c * 2) + 1))) >> (c * 2));// the second bite leftshifted on 1

        if (k == 3)
            printf("\n%d: X", c);
        else if (k == 2)
            printf("\n%d: E", c);
        else if (k == 1)
            printf("\n%d: W", c);
        else
            printf("\n%d: R", c);
    }

}

void binprintf(int v)
{
    unsigned int mask=1<<((sizeof(int)<<3)-1);
    while(mask) {
        printf("%d", (v&mask ? 1 : 0));
        mask >>= 1;
    }
}