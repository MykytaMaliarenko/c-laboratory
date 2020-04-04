//
// Created by Mykyta Maliarenko on 28.02.2020.
//

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include "Train.h"
#include "math.h"


char* trainToString(Train* val)
{
    char* departureTimeStr = departureTimeToString(val);

    char* trainNumberStr = malloc(5 * sizeof(char));
    itoa(val->trainNumber, trainNumberStr, 10);

    char* result = calloc(strlen(val->destination) + strlen(departureTimeStr) + 5 + 45 + 1,
            sizeof(char));
    strcat(result, "Train(number=");
    strcat(result, trainNumberStr);

    strcat(result, ", destination=");
    strcat(result, val->destination);

    strcat(result, ", departure time=");
    strcat(result, departureTimeStr);

    strcat(result, ")");

    free(departureTimeStr);
    free(trainNumberStr);

    return result;
}

char* trainToTableRow(Train* val)
{
    char* departureTimeStr = departureTimeToString(val);
    char* result = calloc(45, sizeof(char));
    sprintf(result, "#%-4d\t%-12s\t%-15s\n", val->trainNumber, departureTimeStr, val->destination);
    free(departureTimeStr);
    return result;
}

char* departureTimeToString(Train* val)
{
    int hours = (int) floor( ((double) val->departureTime) / 3600);
    int minutes = (val->departureTime - hours * 3600) / 60;
    char* str = calloc(6, sizeof(char));
    sprintf(str, "%.2i:%.2i", hours, minutes);
    return str;
}