#include <stdio.h>
#include "menu/Menu.h"
#include "tasks/Task1.h"
#include "helpers/ConsoleHelpers.h"

int main() {
    InitConsole(3, "Опрацювання символьних даних");

    struct MenuOption options[] = {
            {"Find words which starts and ends with the same letter", FindWords},
    };
    Start(options, 1);
    printf("\nSee you next time =)");
    return 0;
}
