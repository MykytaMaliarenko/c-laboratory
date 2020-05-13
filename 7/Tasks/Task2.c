//
// Created by Mykyta Maliarenko on 17.03.2020.
//

#include "Task2.h"
#include "../LinkedList/LinkedList.h"
#include "../LinkedList/LinkeListFuncsForLab.h"
#include "../Helpers/Helpers.h"

char* funcs[] = {
        //"addByIndex", "addToEnd", "addToBeginning", "addAfterValue",
        "add",
        //"deleteByIndex", "deleteFirst", "deleteLast", "deleteByValue",
        "delete",
        "print",
        "remove negative numbers", "create list from not even numbers"
};

LinkedList* list;


void printList(LinkedList* l);

void inputList();

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

    inputList();

    int numOfFuncs = sizeof(funcs) / sizeof(char*);
    while (1)
    {
        printf("\nAvailable funcs:\n");
        for (int i=0; i < numOfFuncs; i++)
            printf("%d)%s\n", i+1, funcs[i]);
        printf("%d)exit\n", numOfFuncs+1);

        int funcToExecute = IntInput("func to run:");
        switch (funcToExecute-1) {
            //add
            case 0:
            {
                char* availableSubFuncs[] = {
                        "addByIndex",
                        "addToEnd",
                        "addToBeginning",
                        "addAfterValue"
                };
                int numOfAvailableSubFuncs = sizeof(availableSubFuncs) / sizeof(char*);

                printf("\nAvailable Sub Funcs:\n");
                for (int i = 0; i < numOfAvailableSubFuncs; i++)
                    printf("\t%d)%s\n", i + 1, availableSubFuncs[i]);

                int subFuncToExecute = IntInput("sub func to run:");
                switch (subFuncToExecute - 1) {
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
                    {
                        add(list, PtrIntInput("element to add: "));
                        printf("%s", "result=");
                        printList(list);
                        break;
                    }

                    //addToBeginning
                    case 2:
                    {
                        addToBeginning(list, PtrIntInput("element to add: "));
                        printf("%s", "result=");
                        printList(list);
                        break;
                    }

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

                    default:
                        printf("sub func not found");
                }
                break;
            }

            //delete
            case 1:
            {
                char* availableSubFuncs[] = {
                        "deleteByIndex",
                        "deleteFirst",
                        "deleteLast",
                        "deleteByValue"
                };
                int numOfAvailableSubFuncs = sizeof(availableSubFuncs) / sizeof(char*);
                if (list->size == 0)
                {
                    printf("list is empty\n");
                    break;
                }

                printf("\nAvailable Sub Funcs:\n");
                for (int i = 0; i < numOfAvailableSubFuncs; i++)
                    printf("\t%d)%s\n", i + 1, availableSubFuncs[i]);

                int subFuncToExecute = IntInput("sub func to run:");
                switch (subFuncToExecute - 1) {
                    //deleteByIndex
                    case 0:
                    {
                        int index = IntInputWithValidating("index: ", listIndexInputValidator);
                        delete(list, index);
                        printf("%s", "result=");
                        printList(list);
                        break;
                    }

                    //deleteFirst
                    case 1:
                    {
                        deleteFirst(list);
                        printf("%s", "result=");
                        printList(list);
                        break;
                    }

                    //deleteLast
                    case 2:
                    {
                        deleteLast(list);
                        printf("%s", "result=");
                        printList(list);
                        break;
                    }

                    //deleteByValue
                    case 3:
                    {
                        int* valueToSearch = PtrIntInput("value to delete: ");
                        deleteByValue(list, comparator, valueToSearch);

                        printf("%s", "result=");
                        printList(list);
                        break;
                    }

                    default:
                        printf("sub func not found\n");
                }
                break;
            }

            //print
            case 2:
            {
                printf("%s", "list=");
                printList(list);
                break;
            }

            //remove negative numbers
            case 3:
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
            case 4:
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

            case 5:
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

void inputList()
{
    printf("Input elements for list(to finish input *):\n");

    int error = 0;
    char* temp = calloc(25, sizeof(char));
    char* end;
    while (1)
    {
        int* res = calloc(1, sizeof(int));

        error = scanf("%s", temp);
        CleanStdin();
        if (error != 1)
            continue;

        if (temp[0] == '*')
            break;

        DefaultReplace(temp);

        *res = strtol(temp, &end, 0);
        add(list, res);
    }
}