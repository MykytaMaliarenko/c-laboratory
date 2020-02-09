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
