//
// Created by Mykyta Maliarenko on 26.04.2020.
//

#include "LinkeListFuncsForLab.h"

void addToBeginning(LinkedList* self, void* value)
{
    addByIndex(self, 0, value);
}

void addAfterValue(LinkedList* self, void* value,
                   bool (*comparator)(void* current, void* toSearch), void* valueToSearch)
{
    for (int i=0; i < self->size; i++)
    {
        LinkedListNode* currentNode = get(self, i);
        if (comparator(currentNode->value, valueToSearch))
        {
            addByIndex(self, i + 1, value);
            return;
        }
    }
}

void deleteFirst(LinkedList* self)
{
    delete(self, 0);
}

void deleteLast(LinkedList* self)
{
    delete(self, self->size - 1);
}
void deleteByValue(LinkedList* self, bool (*comparator)(void* current, void* toSearch),
                   void* valueToSearch)
{
    for (int i=0; i < self->size; i++)
    {
        LinkedListNode* currentNode = get(self, i);
        if (comparator(currentNode->value, valueToSearch))
        {
            delete(self, i);
            return;
        }
    }
}