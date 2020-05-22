//
// Created by Mykyta Maliarenko on 22.05.2020.
//

#ifndef INC_8_HUMANS_H
#define INC_8_HUMANS_H

#include <stdbool.h>
#include "../linked_list/linked_list.h"

#define NAME_MAX_SIZE 100

typedef struct HumanStruct Human;
struct HumanStruct
{
    char fistName[NAME_MAX_SIZE];
    char lastName[NAME_MAX_SIZE];
    char middleName[NAME_MAX_SIZE];

    int birthYear;
    double height;
    double weight;

    //a.k.a is deleted
    bool isActive;
};

typedef LinkedList* Humans;


bool humansFilterActiveOnly(void* val);

bool humansFiltersInactiveOnly(void* val);

void humansDeleteInactive(Humans self);

void humansDeleteAllBy(Humans self, double height, double weight);

void humansAddAfter(Humans self, char* lastName, Human* human);

#endif //INC_8_HUMANS_H
