//
// Created by Mykyta Maliarenko on 17.03.2020.
//

#include "Task2.h"
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/LinkeListFuncsForLab.h"
#include "../Helpers/Helpers.h"

char* funcs[] = {
        "addByIndex", "addToEnd", "addToBeginning", "addAfterValue",
        "deleteByIndex", "deleteFirst", "deleteLast", "deleteByValue",
        "print",
        "input n elements",
        "remove negative numbers", "create list from not even numbers"
};

LinkedList* list;


void printList(LinkedList* l);

void listDestroyer(void* val)
{
    free((int*) val);
}

bool listIndexInputValidator(int inp)
{
    return inp <= (list->size) && inp > -1;
}

bool comparator(void* current, void* toSearch)
{
    return *((int*)current) == *((int*)toSearch);
}

void Integers()
{
    list = createList();
    int numOfFuncs = sizeof(funcs) / sizeof(char*);

    while (1)
    {
        printf("\nAvailable funcs:\n");
        for (int i=0; i < numOfFuncs; i++)
            printf("%d)%s\n", i+1, funcs[i]);
        printf("%d)exit\n", numOfFuncs+1);

        int funcToExecute = IntInput("func to run:");
        switch (funcToExecute-1) {
            //addByIndex
            case 0:
            {
                int index = IntInputWithValidating("index: ", listIndexInputValidator);
                addByIndex(list, index, PtrIntInput("element to add: "));

                printf("%s", "result=");
                printList(list);
                break;
            }

            //addToEnd
            case 1:
                add(list, PtrIntInput("element to add: "));
                printf("%s", "result=");
                printList(list);
                break;

            //addToBeginning
            case 2:
                addToBeginning(list, PtrIntInput("element to add: "));
                printf("%s", "result=");
                printList(list);
                break;

            //addAfterValue
            case 3:
            {
                int* valueToSearch = PtrIntInput("value to add after: ");
                int* value = PtrIntInput("value: ");
                addAfterValue(list, value, comparator, valueToSearch);

                printf("%s", "result=");
                printList(list);
                break;
            }

            //deleteByIndex
            case 4:
            {
                int index = IntInputWithValidating("index: ", listIndexInputValidator);
                delete(list, index);
                printf("%s", "result=");
                printList(list);
                break;
            }

            //deleteFirst
            case 5:
                deleteFirst(list);
                printf("%s", "result=");
                printList(list);
                break;

            //deleteLast
            case 6:
                deleteLast(list);
                printf("%s", "result=");
                printList(list);
                break;

            //deleteByValue
            case 7:
            {
                int* valueToSearch = PtrIntInput("value to delete: ");
                deleteByValue(list, comparator, valueToSearch);

                printf("%s", "result=");
                printList(list);
                break;
            }

            //print
            case 8:
                printf("%s", "list=");
                printList(list);
                break;

            //input n elements
            case 9:
            {
                int n = IntInputWithValidating("n:", PositiveInt);
                char* temp = calloc(5, sizeof(char));
                for (int i=0; i < n; i++)
                {
                    sprintf(temp, "%d=", i);
                    add(list, PtrIntInput(temp));
                }

                free(temp);

                printf("%s", "result=");
                printList(list);
                break;
            }

            //remove negative numbers
            case 10:
            {
                for (int i=0; i < list->size;)
                {
                    if (parseValueAsInt(get(list, i)) < 0)
                        delete(list, i);
                    else
                        i++;
                }

                printf("%s", "result=");
                printList(list);
                break;
            }

            //create list from not even numbers
            case 11:
            {
                LinkedList* notEvenList = createList();
                for (int i=0; i < list->size;)
                {
                    if (parseValueAsInt(get(list, i))%2 != 0)
                    {
                        add(notEvenList, get(list, i)->value);
                        delete(list, i);
                    }
                    else
                        i++;

                }

                printf("%s", "List from not even numbers=");
                printList(notEvenList);

                printf("%s", "list=");
                printList(list);

                destroyList(notEvenList, listDestroyer);
                break;
            }

            case 12:
            {
                destroyList(list, listDestroyer);
                return;
            }

            default:
                printf("func not found");
        }
    }
}

void printList(LinkedList* l)
{
    printf("[");
    LinkedListNode* currentNode = l->firstNode;
    while (currentNode != NULL) {
        if (currentNode->nextNode == NULL)
            printf("%d", parseValueAsInt(currentNode));
        else
            printf("%d,", parseValueAsInt(currentNode));

        currentNode = currentNode->nextNode;
    }

    printf("]\n");
}