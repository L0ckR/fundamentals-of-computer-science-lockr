#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "matrix.h"


int main(int argc, const char* argv[]) {
    if (argc != 3) {
        printf("Используйте: %s <filename>\n", argv[0]);
        return 1;
    }
    const char* filename1 = argv[1];
    const char* filename2 = argv[2];
    Matrix * matrix1 = (Matrix*)malloc(sizeof(Matrix));
    Matrix * matrix2 = (Matrix*)malloc(sizeof(Matrix));
    createMatrix(matrix1);
    createMatrix(matrix2);
    printf("Вас приветствует программа по обработке разряженных матриц!\n");

    if (inputMatrix(matrix1, filename1) == 0){
        destroyMatrix(matrix1);
        destroyMatrix(matrix2);
        return 0;
    }
    if (inputMatrix(matrix2, filename2) == 0){
        destroyMatrix(matrix1);
        destroyMatrix(matrix2);
        return 0;
    }
    printf("\nИсходная матрица 1 равна:\n");
    printMatrix(matrix1);
    printf("\n");
    printf("\nИсходная матрица 2 равна:\n");
    printMatrix(matrix2);
    printf("\n");
    printf("\nРезультат функции:\n");
    if (!((matrix1->sizeColumn == matrix2->sizeColumn )&&(matrix1->sizeRow == matrix2->sizeRow))) { 
        printf("Невозможно сложить\n");
        destroyMatrix(matrix1);
        destroyMatrix(matrix2);
        return 0;
    } else { 
        Matrix * res_matrix = (Matrix *)malloc(sizeof(Matrix));
        createMatrix(res_matrix);
        sumMatrix(res_matrix, matrix1, matrix2);
        printf("\nПолученная матрица равна:\n");
        printMatrix(res_matrix);
        printf("\n");
        if (isSim(res_matrix))
            printf("\nСимметрична");
        else
            printf("\n Не симметрична");
        destroyMatrix(res_matrix);
        destroyMatrix(matrix1);
        destroyMatrix(matrix2);
        printf("\n");
    }
    return 0;
}
