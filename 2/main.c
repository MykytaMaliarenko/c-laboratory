#include <stdio.h>
#include "menu/Menu.h"
#include "helpers/ConsoleHelpers.h"
#include "tasks/Task1.h"
#include "tasks/Task2.h"

int main() {
    InitConsole(2, "Одновимірні й двовимірні масиви");

    struct MenuOption options[] = {
            {"Get Average Of Smallest Items In Two Arrays", GetAverageOfSmallest},
            {"Shuttle Sort", ShuttleSort},
            {"Saddle Points", SaddlePoint}
    };
    Start(options, 3);
    printf("\nSee you next time =)");

    return 0;
}