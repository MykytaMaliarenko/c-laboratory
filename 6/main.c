#include <stdio.h>
#include "./helpers/ConsoleHelpers.h"
#include "./menu/Menu.h"
#include "./tasks/Task1.h"

int main() {
    //InitConsole(6, "Динамічни масиви");
    printf("KM-92 Mykyta Maliarenko lab #6\n");

    struct MenuOption options[] = {
            {"Matrix Multiplication", MatrixMultiplication},
    };
    Start(options, 1);
    printf("\nSee you next time =)");

    return 0;
}
