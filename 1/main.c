#include <stdio.h>
#include "tasks/Task1.h"
#include "menu/Menu.h"

int main() {
    struct MenuOption options[] = {
            {"Calculate prism area", CalculatePrismArea},
            {"Calculate parallelogram area", CalculateParallelogramArea}
    };
    Start(options, 2);
    printf("\nSee you next time =)");
    return 0;
}
