#include <stdio.h>
#include "menu/Menu.h"
#include "tasks/Task1.h"
#include "tasks/Task2.h"
#include "helpers/ConsoleHelpers.h"

int main() {
    InitConsole(4, "Tema: UKAZIVNYKY, FUNKTSIYI, REKURSIYA");

    struct MenuOption options[] = {
            {"Remove Symbols from string", RemoveSymbols},
            {"To Binary", ToBinary}
    };
    Start(options, 2);
    return 0;
}
