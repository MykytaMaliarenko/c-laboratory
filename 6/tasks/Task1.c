//
// Created by Mykyta Maliarenko on 24.02.2020.
//
#include <stdlib.h>
#include <stdio.h>
#include "../helpers/Helpers.h"
#include "../helpers/ArrayHelpers.h"

bool biggerThenZero(int value)
{
    return value > 0;
}

void printMatrix(char* matrixName, double** matrix, int rows, int cols);


void MatrixMultiplication()
{
    int m, k, n;
    double sum = 0;
    m = IntInputWithValidating("m:", biggerThenZero);
    k = IntInputWithValidating("k:", biggerThenZero);
    n = IntInputWithValidating("n:", biggerThenZero);

    double** matrixA = InputDoubleMatrix("A", &m, &k);
    double** matrixB = InputDoubleMatrix("B", &k, &n);

    printMatrix("\ninputted matrix A", matrixA, m, k);
    printMatrix("\ninputted matrix B", matrixB, k, n);

    double** matrixC = malloc(m * sizeof(double*));
    for (int i = 0; i < m; i++) {
        matrixC[i] = malloc(n * sizeof(double));
        for (int d = 0; d < n; d++) {
            for (int kIter = 0; kIter < k; kIter++) {
                sum += matrixA[i][kIter]*matrixB[kIter][d];
            }

            matrixC[i][d] = sum;
            sum = 0;
        }
    }

    printMatrix("\nA * B", matrixC, m, n);

    free(matrixA);
    free(matrixB);
    free(matrixC);
}

void printMatrix(char* matrixName, double** matrix, int rows, int cols)
{
    printf("%s: \n", matrixName);
    for (int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            printf("%0.2f     ", matrix[i][j]);
        }
        printf("\n");
    }
}