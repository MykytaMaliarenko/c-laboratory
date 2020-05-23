//
// Created by Mykyta Maliarenko on 22.05.2020.
//

#include "task_2.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../humans/humans.h"
#include "../helpers/helpers.h"
#include "../helpers/utils.h"
#include "../file_system/file_system.h"
#include "../file_system/file_system_structs.h"

char* TASK2_TEMP_FILE = "temp_structs";

char* task2RootFuncs[] = {
        "create file",
        "open file",
        "exit",
};

char* task2SubFuncs[] = {
        "view file",
        "add human",
        "remove human by index",
        "renew human by index",
        "save file",
        "save file as",
        "remove all humans by weight and height",
        "add human after human with last name",
        "close file",
};

char* task2ViewSubFuncs[] = {
        "show not deleted humans",
        "show delete humans",
};

char* currentFilePathTask2;


Humans getHumans();

void saveHumans(Humans humans);

void printHumans(Humans humans);

Human* inputHuman();

void inputStringAsArray(char array[], char* text);


void Task2()
{
    if (fileSystemFileExists(TASK2_TEMP_FILE))
        fileSystemDestroyFile(TASK2_TEMP_FILE);

    TerminalClear();
    while (1)
    {
        if (currentFilePathTask2 == NULL)
        {
            char* rootFuncToExecute = consolePeekFunc(task2RootFuncs, 3);
            if (strcmp(rootFuncToExecute, "exit") == 0)
            {
                TerminalClear();
                fileSystemDestroyFile(TASK2_TEMP_FILE);
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
            char* subFuncToExecute = consolePeekFunc(task2SubFuncs, 9);

            TerminalClear();
            if (strcmp(subFuncToExecute, "view file") == 0)
            {
                Humans humans = getHumans();
                char* rootFuncToExecute = consolePeekFunc(task2ViewSubFuncs, 2);
                if (strcmp(rootFuncToExecute, "show not deleted humans") == 0)
                    humans = listFilter(humans, humansFilterActiveOnly);
                else
                    humans = listFilter(humans, humansFiltersInactiveOnly);

                printHumans(humans);
                destroyListWithoutValues(humans);
                TerminalPause();
            }
            else if (strcmp(subFuncToExecute, "add human") == 0)
            {
                Human* human = inputHuman();

                if (!fileSystemFileExists(TASK2_TEMP_FILE))
                    fileSystemCreateFile(TASK2_TEMP_FILE);

                Humans humans = getHumans();
                listAdd(humans, human);
                saveHumans(humans);
            }
            else if (strcmp(subFuncToExecute, "remove human by index") == 0) {
                int index = IntInput("index: ");
                Humans humans = getHumans();

                if (index < 0 || index >= humans->size)
                {
                    TerminalPrintAndWait("index not found");
                }
                else
                {
                    Human* human = listGet(humans, index);
                    human->isActive = false;

                    if (!fileSystemFileExists(TASK2_TEMP_FILE))
                        fileSystemCreateFile(TASK2_TEMP_FILE);
                    saveHumans(humans);
                }
            }
            else if (strcmp(subFuncToExecute, "renew human by index") == 0) {
                int index = IntInput("index: ");
                Humans humans = getHumans();

                if (index < 0 || index >= humans->size)
                {
                    TerminalPrintAndWait("index not found");
                }
                else
                {
                    bool found = false;
                    int counter = 0;
                    for (int i = 0; i < humans->size; i++)
                    {
                        Human* current = listGet(humans, i);
                        if (current->isActive == false)
                        {
                            if (counter == index)
                            {
                                current->isActive = true;
                                found = true;
                                break;
                            }

                            counter++;
                        }
                    }

                    if (found)
                        saveHumans(humans);
                    else
                        TerminalPrintAndWait("not found");
                }
            }
            else if (strcmp(subFuncToExecute, "save file") == 0)
            {
                bool minimized = BoolInput("save with minimization(t/f) ?");
                if (fileSystemFileExists(TASK2_TEMP_FILE))
                {
                    fileSystemStructCopyFile(TASK2_TEMP_FILE, currentFilePathTask2);
                    fileSystemDestroyFile(TASK2_TEMP_FILE);
                }

                if (minimized)
                {
                    Humans humans = getHumans();
                    Humans newHumans = listFilter(humans, humansFilterActiveOnly);
                    destroyListWithoutValues(humans);
                    fileSystemStructsWrite(currentFilePathTask2, newHumans);
                }
            }
            else if (strcmp(subFuncToExecute, "save file as") == 0)
            {
                char* newPath = InputString("new file path: ");
                fileSystemCreateFile(newPath);
                fileSystemStructCopyFile(TASK2_TEMP_FILE, newPath);
                currentFilePathTask2 = NULL;
                fileSystemDestroyFile(TASK2_TEMP_FILE);
            }
            else if (strcmp(subFuncToExecute, "remove all humans by weight and height") == 0)
            {
                double weight = DoubletInput("weight:");
                double height = DoubletInput("height:");

                Humans humans = getHumans();
                humansDeleteAllBy(humans, weight, height);

                if (!fileSystemFileExists(TASK2_TEMP_FILE))
                    fileSystemCreateFile(TASK2_TEMP_FILE);

                saveHumans(humans);
            }
            else if (strcmp(subFuncToExecute, "add human after human with last name") == 0)
            {
                Human* human = inputHuman();
                char* lastName = InputString("last name to add after:");

                Humans humans = getHumans();
                humansAddAfter(humans, lastName, human);

                if (!fileSystemFileExists(TASK2_TEMP_FILE))
                    fileSystemCreateFile(TASK2_TEMP_FILE);

                saveHumans(humans);
            }
            else
            {
                if (fileSystemFileExists(TASK2_TEMP_FILE))
                    fileSystemDestroyFile(TASK2_TEMP_FILE);

                currentFilePathTask2 = NULL;
            }
        }

        exit:
        TerminalClear();
    }
}

Humans getHumans()
{
    Humans humans;
    if (fileSystemFileExists(TASK2_TEMP_FILE))
        humans = fileSystemStructsRead(TASK2_TEMP_FILE);
    else
        humans = fileSystemStructsRead(currentFilePathTask2);

    return humans;
}

void saveHumans(Humans humans)
{
    if (fileSystemFileExists(TASK2_TEMP_FILE))
        fileSystemStructsWrite(TASK2_TEMP_FILE, humans);
    else
        fileSystemStructsWrite(currentFilePathTask2, humans);
}

void printHumans(Humans humans)
{
    for (int i = 0; i < humans->size; i++)
    {
        Human* human = listGet(humans, i);

        printf("%d:", i);
        printf("\n\tfirst name: %s\n\tlast name: %s\n\tmiddle name: %s"
               "\n\tweight: %f\n\theight: %f\n\tbirth year: %d",
               human->fistName, human->lastName, human->middleName,
               human->weight, human->height, human->birthYear);
        printf("\n");
    }
}

Human* inputHuman()
{
    TerminalClear();
    Human* human = calloc(1, sizeof(Human));
    inputStringAsArray(human->fistName, "first name:");
    inputStringAsArray(human->lastName, "last name:");
    inputStringAsArray(human->middleName, "middle name:");
    human->birthYear = IntInputWithValidating("birth year:", PositiveInt);
    human->height = DoubleInputWithValidating("height: ", Positive);
    human->weight = DoubleInputWithValidating("weight: ", Positive);
    human->isActive = true;
    return human;
}

void inputStringAsArray(char array[], char* text)
{
    char* t = InputString(text);
    strcpy(array, t);
    free(t);
}