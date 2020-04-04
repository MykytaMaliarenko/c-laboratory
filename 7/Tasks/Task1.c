//
// Created by Mykyta Maliarenko on 14.03.2020.
//

#include "Task1.h"

#include "../helpers/Helpers.h"
#include "../Train/Train.h"
#include "../LinkedList/LinkedList.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define n 3

void inputTrains(LinkedList* trains);

int sortByDepartureTime(LinkedListNode* a, LinkedListNode* b);

void printTrainsAsTable(LinkedList* self);

struct Train* findTrainByDestination(LinkedList* trains, char* destination);

unsigned int inputDepartureTime();


void Trains()
{
    LinkedList* trains = createList();
    inputTrains(trains);
    printTrainsAsTable(trains);

    printf("\nSorted trains by departure time: \n");
    sort(trains, sortByDepartureTime);
    printTrainsAsTable(trains);

    char* searchRequest = InputString("Place of Destination to Search:");
    struct Train* res = findTrainByDestination(trains, searchRequest);
    if (res != NULL)
        printf("Train Number: %d\n", res->trainNumber);
    else
        printf("Train Not Found!\n");
}

void inputTrains(LinkedList* trains)
{
    for (int i = 0; i < n; i++)
    {
        printf("\nTrain %d:\n", i + 1);
        Train* train = malloc(sizeof(Train));
        train->trainNumber = IntInput("Train Number:");
        train->destination = InputString("Train Place Of Destination:");
        train->departureTime = inputDepartureTime();
        add(trains, train);
    }
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

struct Train* findTrainByDestination(LinkedList* trains, char* destination)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(parseValueAsTrain(get(trains, i))->destination, destination) == 0)
            return parseValueAsTrain(get(trains, i));
    }

    return NULL;
}