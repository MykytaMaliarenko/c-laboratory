#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tasks/task_1.h"
#include "tasks/task_2.h"
#include "helpers/helpers.h"
#include "helpers/utils.h"

char* tasks[] = {
        "text files",
        "structs",
        "exit"
};

int main()
{
    while (1)
    {
        char* taskToExecute = consolePeekFunc(tasks, 3);
        if (strcmp(taskToExecute, "text files") == 0)
            Task1();
        else if(strcmp(taskToExecute, "structs") == 0)
            Task2();
        else
        {
            break;
        }

        TerminalClear();
    }

    return 0;
}