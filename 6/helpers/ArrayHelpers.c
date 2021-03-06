//
// Created by Asus on 10.02.2020.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Helpers.h"

double* InputDoubleArray(char* arrayName, int *n)
{
    if (*n == 0)
        *n = IntInput("\nArray length:");
    int i;
    double *p = (double*) malloc(*n * sizeof(double));

    char pr[20] = "";
    char t[5];
    for (i = 0; i < *n; i++)
    {
        itoa(i, t, 10);

        strcat(pr, arrayName);
        strcat(pr, "[");
        strcat(pr, t);
        strcat(pr, "]=");

        p[i] = DoubletInput(pr);
        memset(pr, 0, sizeof(pr));
    }

    return p;
}

double** InputDoubleMatrix(char* arrayName, int *rows, int *cols)
{
    printf("\n%s:\n", arrayName);
    if (*rows == -1)
        *rows = IntInput("\nNum of Rows:");

    if (*cols == -1)
        *cols = IntInput("Num of Columns:");

    bool randomly = BoolInput("Do you want input randomly(t/f)?");

    double **mat = (double **) malloc(*rows * sizeof(double *));

    char pr[20] = "";
    char t[5];
    for(int i = 0; i < *rows; i++)
    {
        itoa(i, t, 10);

        strcat(pr, arrayName);
        strcat(pr, "[");
        strcat(pr, t);
        strcat(pr, "]");

        if (randomly == false)
            mat[i] = InputDoubleArray(pr, cols);

        memset(pr, 0, sizeof(pr));
    }

    return mat;
}
