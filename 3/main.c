#include <stdio.h>
#include "menu/Menu.h"
#include "tasks/Task1.h"

int main() {
    struct MenuOption options[] = {
            {"Find words which starts and ends with the same letter", FindWords},
    };
    Start(options, 1);
    printf("\nSee you next time =)");
    return 0;
}
