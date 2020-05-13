#include <stdio.h>
#include "Menu/Menu.h"
#include "./Helpers/Helpers.h"
#include "./Tasks/Task1.h"
#include "./Tasks/Task2.h"


int main()
{
    printf("KM-92 Mykyta Maliarenko lab #7\n");
    struct MenuOption options[] = {
            {"Reworked lab 5", Trains},
            {"Ints", Integers},
    };
    Start(options, 2);
    printf("\nSee you next time =)");
}
