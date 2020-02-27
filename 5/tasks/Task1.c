//
// Created by Mykyta Maliarenko on 19.02.2020.
//
#include "../helpers/Helpers.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "math.h"

#define n 5

struct Train {
    char *destination;
    int trainNumber;
    int departureTime;
};

void inputTrains(struct Train *trains[]);

char* departureTimeToString(int time);

void sortTrainsByDepartureTime(struct Train *arr[]);

struct Train* findTrainByDestination(struct Train *trains[], char* destination);

unsigned int inputDepartureTime();

//45 000
void WorkingWithStructs()
{
    struct Train *trains[n];
    inputTrains(trains);

    printf("\nSorted trains by departure time: \n");
    sortTrainsByDepartureTime(trains);
    for (int i = 0; i < n; i++)
        printf("\t#%d: %s\n", trains[i]->trainNumber, departureTimeToString(trains[i]->departureTime));

    char* searchRequest = InputString("Place of Destination to Search:");
    struct Train* res = findTrainByDestination(trains, searchRequest);
    if (res != NULL)
        printf("Train Number: %d\n", res->trainNumber);
    else
        printf("Train Not Found!\n");
}

void inputTrains(struct Train *trains[])
{
    for (int i = 0; i < n; i++)
    {
        printf("\nTrain %d:\n", i + 1);
        trains[i] = malloc(sizeof(struct Train));
        trains[i]->trainNumber = IntInput("Train Number:");
        trains[i]->destination = InputString("Train Place Of Destination:");
        trains[i]->departureTime = inputDepartureTime();
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

char* departureTimeToString(int time) {
    int hours = (int) floor( ((double) time) / 3600);
    int minutes = (time - hours * 3600) / 60;
    char* str = malloc(6 * sizeof(char));
    sprintf(str, "%.2i:%.2i", hours, minutes);
    return str;
}

void swap(struct Train* xp, struct Train* yp)
{
    struct Train temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortTrainsByDepartureTime(struct Train *arr[])
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j]->departureTime < arr[min_idx]->departureTime)
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(arr[min_idx], arr[i]);
    }
}

struct Train* findTrainByDestination(struct Train *trains[], char* destination)
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(trains[i]->destination, destination) == 0)
            return trains[i];
    }

    return NULL;
}