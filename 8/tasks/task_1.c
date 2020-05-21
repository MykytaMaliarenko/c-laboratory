//
// Created by Mykyta Maliarenko on 21.05.2020.
//

#include "task_1.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../helpers/helpers.h"
#include "../helpers/utils.h"
#include "../file_system/file_system.h"


char* rootFuncs[] = {
        "create file",
        "open file",
        "exit",
};

char* subFuncs[] = {
        "view file",
        "edit file",
        "save file as",
        "copy rows without numbers",
        "count rows that begins with \"A\"",
        "close file",
};

char* currentFilePath;


void Task1()
{
    while (1)
    {
        if (currentFilePath == NULL)
        {
            char* rootFuncToExecute = consolePeekFunc(rootFuncs, 3);
            if (strcmp(rootFuncToExecute, "exit") == 0)
            {
                TerminalClear();
                break;
            }

            currentFilePath = InputString("file path:");
            if (strcmp(rootFuncToExecute, "create file") == 0)
            {
                fileSystemCreateFile(currentFilePath);
            }
            else if (strcmp(rootFuncToExecute, "open file") == 0)
            {
                if (fileSystemFileExists(currentFilePath) == false)
                {
                    printf("File not found");
                    currentFilePath = NULL;
                }
            }
        }
        else
        {
            char* subFuncToExecute = consolePeekFunc(subFuncs, 6);
            if (strcmp(subFuncToExecute, "view file") == 0)
            {
                TerminalClear();
                fileSystemPrintFile(currentFilePath);
                TerminalPause();
            }
            else if (strcmp(subFuncToExecute, "edit file") == 0)
            {
                TerminalClear();
                printf("Old content:");
                fileSystemPrintFile(currentFilePath);

                char* newContent = InputMultilineString("\nNew content(tab + enter to finish): \n");
                fileSystemEditFile(currentFilePath, newContent);
            }
            else if (strcmp(subFuncToExecute, "save file as") == 0)
            {
                printf("save file as");;
            }
            else if (strcmp(subFuncToExecute, "copy rows without numbers") == 0)
            {
                printf("copy rows without numbers");
            }
            else if (strcmp(subFuncToExecute, "count rows that begins with \"A\"") == 0)
            {
                printf("count rows that begins with \"A\"");
            }
            else
            {
                currentFilePath = NULL;
            }

        }

        TerminalClear();
    }
}