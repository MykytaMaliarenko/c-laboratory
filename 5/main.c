#include <stdio.h>
#include "menu/Menu.h"
#include "tasks/Task1.h"
#include "helpers/ConsoleHelpers.h"

int main() {
    //InitConsole(5, "Типи даних, вказаних користувачем");
    printf("KM-92 Mykyta Maliarenko lab #5\n");

    struct MenuOption options[] = {
            {"Working with Structs", WorkingWithStructs},
    };
    Start(options, 1);
    printf("\nSee you next time =)");
    return 0;
}
