//
// Created by Mykyta Maliarenko on 22.05.2020.
//

#ifndef INC_8_TASK_2_H
#define INC_8_TASK_2_H

#include <stdbool.h>

typedef struct HumanStruct Human;
struct HumanStruct
{
    char* fistName;
    char* lastLame;
    char* middleName;

    int birthYear;
    float height;
    float weight;

    bool isDeleted;
};

void Task2();

#endif //INC_8_TASK_2_H
