//
// Created by nam62 on 04.02.2020.
//
#include "Menu.h"
#include <stdio.h>

void Start(struct MenuOption options[], int length) {
    do {
        int i, userInput;

        printf("\nChoose task to run:\n");
        for(i=0; i < length; i++) {
            printf("%d)", i+1);
            printf("%s\n", options[i].name);
        }

        printf("%d)", length + 1);
        printf("To exit\n");

        scanf("\n%d", &userInput);
        if (userInput == length + 1) {
            break;
        } else if (userInput > 0 && userInput <= length) {
            options[userInput - 1].execute();
        } else {
            printf("Wrong task number!\n");
            break;
        }

    } while(1);
}