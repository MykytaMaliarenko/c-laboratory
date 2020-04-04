//
// Created by Mykyta Maliarenko on 17.03.2020.
//

#include "Task2.h"
#include "../LinkedList/LinkedList.h"
#include "../helpers/Helpers.h"

void printList(LinkedListNode* node, int index);

int* intInput(char* text);

void Integers()
{
    LinkedList* list = createList();

    int n = IntInputWithValidating("n:", PositiveInt);
    for (int i=0; i < n; i++)
    {
        add(list, intInput(""));
    }

    printf("list=");
    iterate(list, printList);

    LinkedList* paired = createList();
    int removed = 0;
    for (int i=0; i < n - removed;)
    {
        LinkedListNode* node = get(list, i);
        int v = parseValueAsInt(node);

        if (v%2 == 0)
            add(paired, node->value);

        if (v < 0)
        {
            delete(list, i);
            removed += 1;
        }
        else i++;
    }

    printf("\nlist after deleting=");
    iterate(list, printList);

    printf("\npaired=");
    iterate(paired, printList);
}

void printList(LinkedListNode* node, int index)
{
    if (index == 0)
        printf("[");

    if (node->nextNode == NULL)
        printf("%d]", parseValueAsInt(node));
    else
        printf("%d,", parseValueAsInt(node));
}

int* intInput(char* text) {
    int* res = calloc(sizeof(int), 1);
    int error = 0;
    char term;

    do {
        printf("%s", text);
        error = scanf("%d%c", res, &term);
        fflush(stdin);
    } while(error != 2 || term != '\n');

    return res;
}