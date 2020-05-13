//
// Created by Mykyta Maliarenko on 14.03.2020.
//

#include "Task1.h"

#include "../Helpers/Helpers.h"
#include "../Train/Train.h"
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/LinkeListFuncsForLab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define n 2

char* trainFuncs[] = {
        //"addByIndex", "addToEnd", "addToBeginning", "addAfterValue",
        "add",
        //"deleteByIndex", "deleteFirst", "deleteLast", "deleteByValue",
        "delete",
        "print",
        "sort by departure time", "search train"
};

LinkedList* list;


void Lab5();

Train* inputTrain(char* text);

void trainListDestroyer(void* val)
{
    free(((Train*) val)->destination);
    free((Train*) val);
}

//all of this code is awful, sorry my lord
bool trainListIndexInputValidator(int inp)
{
    return inp <= (list->size) && inp > -1;
}

bool trainsComparator(void* current, void* toSearch)
{
    return ((Train*)current)->trainNumber == *((int*)toSearch);
}

int sortByDepartureTime(LinkedListNode* a, LinkedListNode* b);

void printTrainsAsTable(LinkedList* self);

Train* findTrainByDestination(LinkedList* trains, char* destination);

Train* findTrainByTrainNumber(LinkedList* trains, int trainNumber);

Train* findTrainByDepartureTime(LinkedList* trains, int departureTime);

unsigned int inputDepartureTime();

void Trains()
{
    list = createList();

    Lab5();

    int numOfFuncs = sizeof(trainFuncs) / sizeof(char*);
    while (1) {
        printf("\nAvailable trainFuncs:\n");
        for (int i = 0; i < numOfFuncs; i++)
            printf("%d)%s\n", i + 1, trainFuncs[i]);
        printf("%d)exit\n", numOfFuncs + 1);

        int funcToExecute = IntInput("func to run:");
        switch (funcToExecute - 1) {
            //add
            case 0:
            {
                char* availableSubFuncs[] = {
                        "addByIndex",
                        "addToEnd",
                        "addToBeginning",
                        "addAfterValue"
                };
                int numOfAvailableSubFuncs = sizeof(availableSubFuncs) / sizeof(char*);

                printf("\nAvailable Sub Funcs:\n");
                for (int i = 0; i < numOfAvailableSubFuncs; i++)
                    printf("\t%d)%s\n", i + 1, availableSubFuncs[i]);

                int subFuncToExecute = IntInput("sub func to run:");
                switch (subFuncToExecute - 1) {
                    //addByIndex
                    case 0:
                    {
                        int index = IntInputWithValidating("index: ", trainListIndexInputValidator);
                        addByIndex(list, index, inputTrain("element to add: "));

                        printf("%s", "\nResult\n");
                        printTrainsAsTable(list);
                        break;
                    }

                    //addToEnd
                    case 1:
                    {
                        add(list, inputTrain("element to add: "));

                        printf("%s", "\nResult\n");
                        printTrainsAsTable(list);
                        break;
                    }

                    //addToBeginning
                    case 2:
                    {
                        addToBeginning(list, inputTrain("element to add: "));

                        printf("%s", "\nResult\n");
                        printTrainsAsTable(list);
                        break;
                    }

                    //addAfterValue
                    case 3:
                    {
                        int* valueToSearch = PtrIntInput("train number to add after: ");
                        Train *value = inputTrain("value: ");
                        addAfterValue(list, value, trainsComparator, valueToSearch);

                        printf("%s", "\nResult\n");
                        printTrainsAsTable(list);
                        break;
                    }

                    default:
                        printf("sub func not found");
                }
                break;
            }

            //delete
            case 1:
            {
                char* availableSubFuncs[] = {
                        "deleteByIndex",
                        "deleteFirst",
                        "deleteLast",
                        "deleteByValue"
                };
                int numOfAvailableSubFuncs = sizeof(availableSubFuncs) / sizeof(char*);
                if (list->size == 0)
                {
                    printf("list is empty\n");
                    break;
                }

                printf("\nAvailable Sub Funcs:\n");
                for (int i = 0; i < numOfAvailableSubFuncs; i++)
                    printf("\t%d)%s\n", i + 1, availableSubFuncs[i]);

                int subFuncToExecute = IntInput("sub func to run:");
                switch (subFuncToExecute - 1) {
                    //deleteByIndex
                    case 0:
                    {
                        int index = IntInputWithValidating("index: ", trainListIndexInputValidator);
                        delete(list, index);

                        printf("%s", "\nResult\n");
                        printTrainsAsTable(list);
                        break;
                    }

                    //deleteFirst
                    case 1:
                    {
                        deleteFirst(list);

                        printf("%s", "\nResult\n");
                        printTrainsAsTable(list);
                        break;
                    }

                    //deleteLast
                    case 2:
                    {
                        deleteLast(list);

                        printf("%s", "\nResult\n");
                        printTrainsAsTable(list);
                        break;
                    }

                    //deleteByValue
                    case 3:
                    {
                        int* valueToSearch = PtrIntInput("train number to delete: ");
                        deleteByValue(list, trainsComparator, valueToSearch);

                        printf("%s", "\nResult\n");
                        printTrainsAsTable(list);
                        break;
                    }

                    default:
                        printf("sub func not found");
                }
                break;
            }

            //print
            case 2:
            {
                printf("%s", "\nResult\n");
                printTrainsAsTable(list);
                break;
            }

            //sort by place of destination
            case 3:
            {
                sort(list, sortByDepartureTime);

                printf("%s", "\nResult\n");
                printTrainsAsTable(list);
                break;
            }

            //search train
            case 4:
            {
                bool keyFound = false;
                char* key = InputString("Search by(destination, trainNumber, departureTime):");
                Train* res = NULL;
                if (strcmp(key, "destination") == 0)
                {
                    char* searchRequest = InputString("place of destination:");
                    res = findTrainByDestination(list, searchRequest);
                    keyFound = true;
                }
                else if (strcmp(key, "trainNumber") == 0)
                {
                    int searchRequest = IntInput("train number:");
                    res = findTrainByTrainNumber(list, searchRequest);
                    keyFound = true;
                }
                else if (strcmp(key, "departureTime") == 0)
                {
                    int searchRequest = inputDepartureTime();
                    res = findTrainByDepartureTime(list, searchRequest);
                    keyFound = true;
                }

                if (keyFound)
                {
                    if (res != NULL)
                        printf("Train Number: %d\n", res->trainNumber);
                    else
                        printf("Train Not Found!\n");
                }
                else
                    printf("key wasn't found");

                break;
            }

            case 5:
            {
                destroyList(list, trainListDestroyer);
                return;
            }

            default:
                printf("func not found");
        }
    }
}

void Lab5()
{
    for (int i = 0; i < n; i++)
    {
        printf("\nTrain %d:\n", i + 1);
        Train* train = malloc(sizeof(Train));
        train->trainNumber = IntInput("Train Number:");
        train->destination = InputString("Train Place Of Destination:");
        train->departureTime = inputDepartureTime();
        add(list, train);
    }

    printf("%s", "\nResult\n");
    printTrainsAsTable(list);

    printf("\nSorted trains by departure time: \n");
    sort(list, sortByDepartureTime);

    printf("%s", "\nResult\n");
    printTrainsAsTable(list);

    char* searchRequest = InputString("Place of Destination to Search:");
    Train* res = findTrainByDestination(list, searchRequest);
    if (res != NULL)
        printf("Train Number: %d\n", res->trainNumber);
    else
        printf("Train Not Found!\n");
}

Train* inputTrain(char* text)
{
    printf("%s\n", text);
    Train* train = calloc(1, sizeof(Train));
    train->trainNumber = IntInput("Train Number:");
    train->destination = InputString("Train Place Of Destination:");
    train->departureTime = inputDepartureTime();
    return train;
}

unsigned int inputDepartureTime()
{
    unsigned int hour, minute;
    int error;
    do {
        printf("%s", "Departure time(hh:mm):");
        error = scanf("%02d:%02d", &hour, &minute);
        fflush(stdin);
    } while(error != 2);

    return (unsigned int) hour * 3600 + minute * 60;
}

void printTrainsAsTable(LinkedList* self)
{
    printf("-----------------------------------\n");
    printf("ID\tDepart. Time\tDestination\n");
    printf("-----------------------------------\n");

    char* train;
    LinkedListNode* currentNode = self->firstNode;
    while(currentNode != NULL)
    {
        train = trainToTableRow(parseValueAsTrain(currentNode));
        printf("%s", train);
        free(train);
        currentNode = currentNode->nextNode;
    }

    printf("\n");
}

int sortByDepartureTime(LinkedListNode* a, LinkedListNode* b)
{
    return parseValueAsTrain(b)->departureTime - parseValueAsTrain(a)->departureTime;
}

Train* findTrainByDestination(LinkedList* trains, char* destination)
{
    for (int i = 0; i < trains->size; i++)
    {
        if (strcmp(parseValueAsTrain(get(trains, i))->destination, destination) == 0)
            return parseValueAsTrain(get(trains, i));
    }

    return NULL;
}

Train* findTrainByTrainNumber(LinkedList* trains, int trainNumber)
{
    for (int i = 0; i < trains->size; i++)
    {
        if (parseValueAsTrain(get(trains, i))->trainNumber == trainNumber)
            return parseValueAsTrain(get(trains, i));
    }

    return NULL;
}

Train* findTrainByDepartureTime(LinkedList* trains, int departureTime)
{
    for (int i = 0; i < trains->size; i++)
    {
        if (parseValueAsTrain(get(trains, i))->departureTime == departureTime)
            return parseValueAsTrain(get(trains, i));
    }

    return NULL;
}