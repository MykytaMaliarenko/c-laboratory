//
// Created by Asus on 10.02.2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../helpers/ArrayHelpers.h"

double getSmallestNumber(double* arr, int *n);

void sort(double* a, int *n);

void GetAverageOfSmallest()
{
    int n1 = 0, n2 = 0;

    double* a = InputDoubleArray("a", &n1);
    double* b = InputDoubleArray("b", &n2);
    printf("Res: %.2f", (getSmallestNumber(a, &n1) + getSmallestNumber(b, &n2)) / 2);
}

double getSmallestNumber(double* arr, int *n)
{
    int i = 0;
    double res = arr[i];

    for (i = 1; i < *n; i++)
    {
        if (res > arr[i])
            res = arr[i];
    }

    return res;
}

void ShuttleSort()
{
    int n = 0, i;
    double* a = InputDoubleArray("a", &n);
    sort(a, &n);

    printf("\nRes:");

    char pr[50] = "";
    char t[20];
    for (i = 0; i < n; i++)
    {
        strcat(pr, "a[");
        itoa(i, t, 10);
        strcat(pr, t);
        strcat(pr, "]=");
        sprintf(t,"%.2f", a[i]);
        strcat(pr, t);

        printf("%s", pr);
        memset(pr, 0, sizeof(pr));
    }
}

void sort(double* a, int *n) {
    double temp;
    int i, j;

    for  (i = 0; i < *n - 1; i++)
    {
        if  (a[i] > a[i + 1])
        {
            j = i - 1;
            temp = a[i + 1];
            a[i + 1] = a[i];
            while  (j >= 0  &&  a[j] > temp)
            {
                a[j + 1] = a[j];
                j = j - 1;
            }
            a[j + 1] = temp;
        }
    }
}