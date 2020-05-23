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

char* TEMP_FILE = "temp";

char* rootFuncs[] = {
        "create file",
        "open file",
        "exit",
};

char* subFuncs[] = {
        "view file",
        "edit file",
        "save file",
        "save file as",
        "copy rows without numbers",
        "count rows that begins with \"A\"",
        "close file",
};

char* currentFilePathTask2;


void Task1()
{
    if (fileSystemFileExists(TEMP_FILE))
        fileSystemDestroyFile(TEMP_FILE);

    TerminalClear();
    while (1)
    {
        if (currentFilePathTask2 == NULL)
        {
            char* rootFuncToExecute = consolePeekFunc(rootFuncs, 3);
            if (strcmp(rootFuncToExecute, "exit") == 0)
            {
                TerminalClear();
                fileSystemDestroyFile(TEMP_FILE);
                break;
            }

            TerminalClear();
            currentFilePathTask2 = InputString("file path:");
            if (strcmp(rootFuncToExecute, "create file") == 0)
            {
                fileSystemCreateFile(currentFilePathTask2);
            }
            else if (strcmp(rootFuncToExecute, "open file") == 0)
            {
                if (fileSystemFileExists(currentFilePathTask2) == false)
                {
                    printf("File not found");
                    TerminalPrintAndWait("File not found");
                    currentFilePathTask2 = NULL;
                }
            }
        }
        else
        {
            char* subFuncToExecute = consolePeekFunc(subFuncs, 7);

            TerminalClear();
            if (strcmp(subFuncToExecute, "view file") == 0)
            {
                if (fileSystemFileExists(TEMP_FILE))
                    fileSystemPrintFile(TEMP_FILE);
                else
                    fileSystemPrintFile(currentFilePathTask2);
                TerminalPause();
            }
            else if (strcmp(subFuncToExecute, "edit file") == 0)
            {
                printf("Old content:");
                fileSystemPrintFile(currentFilePathTask2);

                char* newContent = InputMultilineString("\nNew content(tab + enter to finish): \n");
                fileSystemEditFile(TEMP_FILE, newContent);
            }
            else if (strcmp(subFuncToExecute, "save file") == 0)
            {
                if (fileSystemFileExists(TEMP_FILE))
                {
                    fileSystemCopyFile(TEMP_FILE, currentFilePathTask2);
                    fileSystemDestroyFile(TEMP_FILE);
                }
                else
                    TerminalPrintAndWait("No changes");
            }
            else if (strcmp(subFuncToExecute, "save file as") == 0)
            {
                if (fileSystemFileExists(TEMP_FILE))
                {
                    char* newPath = InputString("new file path: ");
                    fileSystemCreateFile(newPath);
                    fileSystemCopyFile(TEMP_FILE, newPath);
                    currentFilePathTask2 = NULL;
                    fileSystemDestroyFile(TEMP_FILE);
                }
                else
                    TerminalPrintAndWait("No changes");
            }
            else if (strcmp(subFuncToExecute, "copy rows without numbers") == 0)
            {
                char* copyFrom = currentFilePathTask2;
                if (fileSystemFileExists(TEMP_FILE))
                    copyFrom = TEMP_FILE;

                char* newPath = InputString("copy to: ");
                fileSystemCopyRowsWithoutNumber(newPath, copyFrom);
            }
            else if (strcmp(subFuncToExecute, "count rows that begins with \"A\"") == 0)
            {
                char* countFrom = currentFilePathTask2;
                if (fileSystemFileExists(TEMP_FILE))
                    countFrom = TEMP_FILE;

                int num = fileSystemCountRowsThatBeginsWith(countFrom, 'A');
                if (num == -1)
                {
                    TerminalPrintAndWait("couldn't open file");
                    goto exit;
                }

                char res[50];
                sprintf(res, "%d rows begins with \"A\"", num);
                TerminalPrintAndWait(res);
            }
            else
            {
                currentFilePathTask2 = NULL;
            }
        }

        exit:
        TerminalClear();
    }
}