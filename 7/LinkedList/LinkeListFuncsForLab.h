//
// Created by Mykyta Maliarenko on 26.04.2020.
//

#ifndef INC_7_LINKELISTFUNCSFORLAB_H
#define INC_7_LINKELISTFUNCSFORLAB_H

#include "LinkedList.h"

void addToBeginning(LinkedList* self, void* value);
void addAfterValue(LinkedList* self, void* value,
                   bool (*comparator)(void* current, void* toSearch), void* valueToSearch);

void deleteFirst(LinkedList* self);
void deleteLast(LinkedList* self);
void deleteByValue(LinkedList* self,
                   bool (*comparator)(void* current, void* toSearch), void* valueToSearch);

#endif //INC_7_LINKELISTFUNCSFORLAB_H
