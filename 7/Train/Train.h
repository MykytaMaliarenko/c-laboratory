//
// Created by Mykyta Maliarenko on 28.02.2020.
//

#ifndef INC_7_TRAIN_H
#define INC_7_TRAIN_H

typedef struct Train {
    char *destination;
    int trainNumber;
    int departureTime;
} Train;

char* trainToString(Train* val);

char* trainToTableRow(Train* val);

char* departureTimeToString(Train* val);

#endif //INC_7_TRAIN_H
