#ifndef matrix_h
#define matrix_h


#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "vector.h"

typedef struct {
    int sizeRow;//количество строк
    int sizeColumn;//количество столбцов
    vector* indexMatrix;
    vector* valuesMatrix;
}Matrix;


void createMatrix(Matrix* matrix);
void printMatrix(Matrix* matrix);
int inputMatrix(Matrix * matrix, const char * filename);
void destroyMatrix(Matrix * matrix);
void sumMatrix(Matrix * res, Matrix * m1, Matrix * m2);
bool isSim(Matrix * matrix);

#endif
