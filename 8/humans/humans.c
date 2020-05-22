//
// Created by Mykyta Maliarenko on 22.05.2020.
//

#include "humans.h"
#include <string.h>

bool humansFilterActiveOnly(void* val)
{
    return ((Human*) val)->isActive;
}

bool humansFiltersInactiveOnly(void* val)
{
    return !((Human*) val)->isActive;
}

void humansDeleteInactive(Humans self)
{
    for (int i = 0;i < self->size;)
    {
        Human* current = listGet(self, i);
        if (current->isActive == false)
        {
            free(current);
            listDelete(self, i);

        }
        else
            i++;
    }
}

void humansDeleteAllBy(Humans self, double height, double weight)
{
    for (int i = 0;i < self->size;)
    {
        Human* current = listGet(self, i);
        if (current->height == height && current->weight == weight)
        {
            free(current);
            listDelete(self, i);

        }
        else
            i++;
    }
}

void humansAddAfter(Humans self, char* lastName, Human* human)
{
    for (int i = 0; i < self->size; i++)
    {
        Human* current = listGet(self, i);
        if (strcmp(human->lastName, lastName) == 0)
        {
            listAddByIndex(self, i + 1, human);
            return;
        }
    }
}