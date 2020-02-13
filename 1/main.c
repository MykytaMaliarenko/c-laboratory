#include <stdio.h>
#include "tasks/Task1.h"
#include "tasks/Task2.h"
#include "menu/Menu.h"

int main() {
    struct MenuOption options[] = {
            {"Calculate prism area", CalculatePrismArea},
            {"Calculate parallelogram area", CalculateParallelogramArea},
            {"Input Structure", InputStruct},
            {"Get Data From HEX", InputStructAsHex}

    };
    Start(options, 4);
    printf("\nSee you next time =)");
    return 0;
}

int Input(int *num)
{
    char term;
    if(scanf("%d%c", num, &term) != 2 || term != '\n')
        printf("failure\n");
    else
        printf("valid integer followed by enter key\n");
}