#include <stdio.h>
#include "tasks/Task1.h"
#include "tasks/Task2.h"
#include "menu/Menu.h"
#include <stdbool.h>

int main() {
    struct MenuOption options[] = {
            {"Calculate prism area", CalculatePrismArea},
            {"Calculate parallelogram area", CalculateParallelogramArea},
            {"Input Structure", InputStruct},
            {"Get Data From HEX", InputStructAsHex}

    };
    Start(options, 4);
    printf("\nSee you next time =)");

    /*
     *
     *
    int c, k;
    unsigned int n = 0;
    n |= 2 << 0;
    n |= 3 << 2;

    for (c = 31; c >= 0; c--)
    {
        k = n >> c;

        if (k & 1)
            printf("1");
        else
            printf("0");
    }*/

    return 0;
}
