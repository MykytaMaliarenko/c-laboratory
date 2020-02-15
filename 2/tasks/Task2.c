//
// Created by Asus on 10.02.2020.
//
#include "../helpers/ArrayHelpers.h"
#include <stdio.h>

int getPosOfMinElement(double* arr, int *len);

int getPosOfMaxElement(double* arr, int * len);

int getPosOfElement(double* arr, int *len, double val);


void SaddlePoint()
{
    int rows = 3, cols = 3;
    double** matrix = InputDoubleMatrix("Matrix", &rows, &cols);
    //double matrix[3][3] = {{4, -5, 3}, {0, -1, 2}, {2, -6, 4}};

    int minElementsInRows[rows];
    double minElementInRowsValues[rows];

    int maxElementsInColumns[cols];
    double maxElementInColumnsValues[cols];

    int i;
    for (i = 0; i < rows; i++)
    {
        minElementsInRows[i] = getPosOfMinElement(matrix[i], &cols);
        minElementInRowsValues[i] = matrix[i][minElementsInRows[i]];
    }

    int j;
    double colArr[rows];
    for (j = 0;j < cols; j++)
    {
        for (i = 0;i < rows; i++)
            colArr[i] = matrix[i][j];

        maxElementsInColumns[j] = getPosOfMaxElement(colArr, &rows);
        maxElementInColumnsValues[j] = colArr[maxElementsInColumns[j]];
    }

    printf("Matrix: \n");
    for (i=0; i<rows; i++)
    {
        for(j=0; j<cols; j++)
        {
            printf("%0.2f     ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Saddle Points:\n");
    int pos, posOfMinElementInRow;
    double el;
    for (i = 0; i < rows; i++)
    {
        posOfMinElementInRow = minElementsInRows[i];
        el = matrix[i][posOfMinElementInRow];
        pos = getPosOfElement(maxElementInColumnsValues, &rows, el);

        if (pos != -1){
            printf("[%d][%d] = %.2f", i, pos, el);
        }
    }
    printf("\n");
}


int getPosOfMinElement(double* arr, int *len)
{
    int i = 0, pos = 0;
    double t = arr[i];

    for (i = 1; i < *len; i++)
    {
        if (t > arr[i])
        {
            t = arr[i];
            pos = i;
        }
    }

    return pos;
}


int getPosOfMaxElement(double* arr, int *len)
{
    int i = 0, pos = 0, b;
    double t = arr[i];

    for (i = 1; i < *len; i++)
    {
        if (t < arr[i])
        {
            t = arr[i];
            pos = i;
        }
    }

    return pos;
}


int getPosOfElement(double* arr, int *len, double val)
{
    int i;
    for (i = 0; i < *len; i++)
    {
        if (arr[i] == val)
            return i;
    }

    return -1;
}