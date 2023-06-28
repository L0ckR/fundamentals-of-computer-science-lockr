#include "matrix.h"

void createMatrix(Matrix* matrix){
    matrix->sizeColumn = 0;
    matrix->sizeRow = 0;
    matrix->valuesMatrix = (vector *)malloc(sizeof(vector));
    matrix->indexMatrix = (vector*)malloc(sizeof(vector));
    createVector(matrix->indexMatrix, 1);
    createVector(matrix->valuesMatrix, 1);
}



int plusIndex(int i, int j) { //функция создания индекса элемента матрицы
    int checkLen;
    int len = 0;
    checkLen = j;
    while (checkLen) { //вычисляем длину правого индекса(столбца)
        checkLen /= 10;
        len++;
    }
    return i * pow(10, len) + j;
}


void printMatrix(Matrix* matrix) { //функция вывода матрицы
    vector * v = matrix->valuesMatrix;
    vector * vIndex = matrix->indexMatrix;
    int sizeRow = matrix->sizeRow;
    int sizeColumn = matrix->sizeColumn;
    checkNullElements(v, vIndex);//проверяем на нулевые индексы
    int i = 1;
    int j = 1;
    int check = 0;
    int countNums = sizeRow * sizeColumn; //количество элементов
    for (int k = 0; k < countNums; k++) {//цикл пока не вывели все элементы
        if (k % sizeColumn == 0) {//если вывели всю строку, то печатаем перенос
            printf("\n");
        }
        if (loadVector(vIndex, check) == plusIndex(i, j)) {//если индекс перебора совпал с индексом не нулевого элемента
            printf("%d\t", loadVector(v, check));//выводим его
            check++;//увеличиваем счетчик вывода таких элементов
        }
        else {
            printf("0\t");//печатаем ноль, так как матрица разряженна
        }
        if (j == sizeRow) {//если столбцы закончилась, то увеличиваем счетчик строк
            j = 0;//обнуляем счетчик столбцов
            i++;
        }
        j++;//увеличиваем счетчик прохода по столбцу
    }
}



int inputMatrix(Matrix * matrix, const char * filename){
    FILE * input = fopen(filename, "r");
    if (input == NULL) { // проверка на возможность открытия файла
        printf("Не удалось открыть файл!\n");
        fclose(input);
        return 0;
    }
    fscanf(input, "%d %d", &matrix->sizeRow, &matrix->sizeColumn);//считываем размер из файла
    int indexRow = 1;
    int indexColumn = 1;
    int indexVector = 0;
    while (!feof(input)) { //пока файл не пуст, считываем данные 
        int scanNum;
        fscanf(input, "%d", &scanNum);
        if (scanNum != 0) {
            writeVector(matrix->valuesMatrix, indexVector, scanNum);
            resizeVector(matrix->valuesMatrix, sizeVector(matrix->valuesMatrix) + 1);
            writeVector(matrix->indexMatrix, indexVector, plusIndex(indexColumn, indexRow));
            resizeVector(matrix->indexMatrix, sizeVector(matrix->indexMatrix) + 1);
            indexVector++;
        }
        indexRow++;
        if (indexRow == matrix->sizeRow + 1) {
            indexColumn++;
            indexRow = 1;
        }
    }
    resizeVector(matrix->indexMatrix, sizeVector(matrix->indexMatrix) - 1);
    resizeVector(matrix->valuesMatrix, sizeVector(matrix->valuesMatrix) - 1);
    fclose(input); //закрываем файл
    return 1;
}

void destroyMatrix(Matrix * matrix){
    destroyVector(matrix->indexMatrix);
    destroyVector(matrix->valuesMatrix); 
    free(matrix);
}


void sumMatrix(Matrix * res, Matrix*m1, Matrix * m2){
    resizeVector(res->indexMatrix, sizeVector(m1->indexMatrix) + sizeVector(m2->indexMatrix));
    resizeVector(res->valuesMatrix, sizeVector(m1->valuesMatrix) + sizeVector(m2->valuesMatrix));
    res->sizeRow = m1->sizeRow;
    res->sizeColumn = m1->sizeColumn;
    int i = 0;//параметры циклов
    int j = 0;
    int k = 0;
    vector * eIndex = m1->indexMatrix;
    vector * vIndex = m2->indexMatrix;
    vector * E = m1->valuesMatrix;
    vector * v = m2->valuesMatrix;
    vector * resIndex = res->indexMatrix;
    vector * resValues = res->valuesMatrix;
    

    while (i < sizeVector(eIndex) && j < sizeVector(vIndex)) {//цикл соединения 2 вектором в один отдельный
        if (loadVector(eIndex, i) < loadVector(vIndex, j)) {//если индекс единичной матрицы меньше матрицы М
            writeVector(resIndex, k, loadVector(eIndex, i));//записываем в массив индексов индекс из массива единичной
            writeVector(resValues, k, loadVector(E, i));//записываем соответствующее значение
            i++;
        }
        else if (loadVector(eIndex, i) > loadVector(vIndex, j)) {//противоположна ситуация первого if
            writeVector(resIndex, k, loadVector(vIndex, j));
            writeVector(resValues, k, loadVector(v, j));
            j++;
        }
        else { // если индексы совпали, то записываем сумму значений двух массивов, а в массив индексов идет индекс из массиво единичной
            writeVector(resIndex, k, loadVector(eIndex, i));
            writeVector(resValues, k, loadVector(E, i) + loadVector(v, j));
            i++;
            j++;
        }
        k++;
    }
    while (i < sizeVector(eIndex)) {//если массив индексов не единичной кончился, то нужно дописать оставшиеся 
        writeVector(resIndex, k, loadVector(eIndex, i));
        writeVector(resValues, k, loadVector(E, i));
        i++;
        k++;
    }
    while (j < sizeVector(vIndex)) {//если массив индексов единичной кончился, то дописываем оставшиеся из не единичной
        writeVector(resIndex, k, loadVector(vIndex, j));
        writeVector(resValues, k, loadVector(v, j));
        j++;
        k++;
    }
    k = 0;
    for (k = 0; k < sizeVector(resIndex); k++) {//если найден нулевой индекс, то соответствующее значение из вектора обнуляем
        if (loadVector(resIndex, k) == 0) {
            destroyElement(resIndex, resValues, k);
        }
    }

}


bool isSim(Matrix * matrix) {

    if (matrix->sizeColumn != matrix->sizeRow){
        return false;
    }else{
        vector * v = matrix->valuesMatrix;
        vector * vIndex = matrix->indexMatrix;
        int sizeRow = matrix->sizeRow;
        int sizeColumn = matrix->sizeColumn;
        checkNullElements(v, vIndex);//проверяем на нулевые индексы
        int i = 1;
        int j = 1;
        int check = 0;
        int countNums = sizeRow * sizeColumn; //количество элементов
        for (int k = 0; k < countNums; k++) {//цикл пока не вывели все элементы
            if (loadVector(vIndex, check) == plusIndex(i, j)) {//если индекс перебора совпал с индексом не нулевого элемента
                bool flag = false;
                for (int z = 0; z < sizeVector(vIndex); z++) {   
                    if (loadVector(vIndex, z) == plusIndex(j, i)){
                        flag = true;
                        break;
                    }
                }
                if (!flag) 
                    return false;
                check++;//увеличиваем счетчик вывода таких элементов
            }
            if (j == sizeRow) {//если столбцы закончилась, то увеличиваем счетчик строк
                j = 0;//обнуляем счетчик столбцов
                i++;
            }
            j++;//увеличиваем счетчик прохода по столбцу
            
        }
        return true;
    }
}


