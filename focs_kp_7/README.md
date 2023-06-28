# Отчёт по курсовой работе №7 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Ибрагимов Далгат Магомедалиевич, № по списку 8</ins>

<b>Контакты e-mail:</b> <ins>doly2004e@yandex.ru<ins>

<b>Работа выполнена:</b> «25» <ins>мая</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «27» <ins>июня</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins>3</ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема
Разреженные матрицы

## 2. Цель работы
Составить и отладить программу на языке Си для обработки разреженных матриц с элементами целого типа.

## 3. Задание
Разреженная матрица на двух векторах. Реализовать сложение и определить симметричность полученной матрицы.

## 4. Оборудование
<b>Процессор:</b> AMD Ryzen 5 5600H (12) @ 3.600GHz<br/>
<b>ОП:</b> 32GiB 3200 MHz LPDDR4<br/>
<b>SSD:</b> 512 GiB<br/>
<b>Адрес:</b> <br/>
<b>Монитор:</b> 23.5-дюймовый (1920 х 1080)<br/>
<b>Графика:</b>AMD Radeon™ RX 6600M 2177 MHz 8GiB GDDR6<br/>

## 5. Программное обеспечение:
<b>Слой совместимости для запуска Linux-приложений в ОС Windows:</b> WSL2 5.10.102.1<br/>
<b>Операционная система семейства UNIX:</b> Ubuntu 20.04 LTS GNU/Linux 5.10.16.3-microsoft-standard-WSL2 x86_64<br/>
<b>Интерпретатор команд:</b> bash версия 5.1.16<br/>
<b>Система программирования:</b> GNU <br/>
<b>Редактор текстов:</b> Visual Studio Code<br/>
<b>Утилиты операционной системы:</b> cd, pwd, ls, cp, mv, mkdir, rmdir, cat, man, ps, rm<br/>
<b>Прикладные системы и программы:</b> gnuplot<br/>
<b>Местонахождение и имена файлов программ и данных на домашнем компьютере:</b> /home/lockr<br/>

## 6. Идея, метод, алгоритм решения задачи

## 7. Сценарий выполнения работы

vector.h
```#ifndef vector_h
#define vector_h


#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

typedef struct { //структура вектора
    int* value; //значение
    int size; //размер 
} vector;

void createVector(vector* v, int size);
bool empty(vector* v);
int sizeVector(vector* v);
int loadVector(vector* v, int i);
void writeVector(vector* v, int i, int value);
void resizeVector(vector* v, int size);
bool equalVector(vector* l, vector* r);
void destroyVector(vector* v);
void destroyElement(vector* vIndex, vector* v, int i);
void checkNullElements(vector* v, vector* vIndex);




#endif
```
vector.c
```
#include "vector.h"

void createVector(vector* v, int size) { //функция создания вектора
    v->size = size;
    v->value = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        v->value[i] = 0;
    }
}


bool empty(vector* v) { //функция проверки на пустоту
    return v->size == 0;
}

int sizeVector(vector* v) {//функция возвращения размера вектора
    return v->size;
}

int loadVector(vector* v, int i) {//функция вывода значения вектора
    if ((i >= 0) && (i < v->size)) {//провека на принадлежность промежутку размера
        return v->value[i];
    } 
    return -9999999;
}

void writeVector(vector* v, int i, int value) {//функция записи в вектор
    if((i >= 0) && (i < v->size)) {//если значение i принадлежит отрезку вектора
        v->value[i] = value;
    }
}

void resizeVector(vector* v, int size) {//функция изменения размера
    v->value = realloc(v->value, size * sizeof(int));
    for (int i = v->size; i < size; i++) {
        v->value[i] = 0;
    }
    v->size = size;
}

bool equal(vector* l, vector* r) {//функция проверки на равенство двух векторов
    if (l->size != r->size) {
        return false;
    } else {
        for (int i = 0; i < l->size; i++) {
            if (l->value[i] != r->value[i]) {
                return false;
            }
        }
        return true;
    }
}


void destroyVector(vector* v) {//функция очистки вектора 
    v->size = 0;
    free(v->value);
    v->value = NULL;
    free(v);
}

void destroyElement(vector* vIndex, vector* v, int i) {//функция перезаписи элемента вектора на 0
    writeVector(v, i, 0);
    
}

void checkNullElements(vector* v, vector* vIndex) {//функция проверки на нулевой элемент
    int i = 0;
    int j = 1;
    for(i = 0; i < sizeVector(vIndex); i++, j++) {
        if(loadVector(vIndex, i) == 0) { //если найден пустой элемент 
            writeVector(vIndex, i, loadVector(vIndex, j));//перезаписываем на место нулевого следующий
            writeVector(v, i, loadVector(v, j));//так же делаем со значением
            writeVector(vIndex, j, 0);//обнуляем взятый
            writeVector(v, j, 0);
        }

    }

}lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_kp_7$ cat matrix.h
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
```
matrix.c
```
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

```
execute.c 
```
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
```
Makefile 
```
CC = gcc
CFLAGS = -std=c99 -g -Wall -Werror
LDFLAGS = -lm
DEBUG = gdb
FILEOUT = vector.out
SOURCES = vector.c execute.c matrix.c

all: $(FILEOUT)

$(FILEOUT): $(SOURCES)
        $(CC) $(CFLAGS) $(SOURCES) $(LDFLAGS) -o $(FILEOUT)

clean:
        rm -f *.out

debug:
        $(CC) $(CFLAGS) -g $(SOURCES) $(LDFLAGS)
        sudo $(DEBUG) $(FILEOUT)

cmp: $(FILEOUT)

run:
        ./$(FILEOUT) $(FILE)
```

## 8. Распечатка протокола

```
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_kp_7$ make
gcc -std=c99 -g -Wall -Werror vector.c execute.c matrix.c -lm -o vector.out
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_kp_7$ valgrind --track-origins=yes ./vector.out matrix1.txt matrix1.txt
==32414== Memcheck, a memory error detector
==32414== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==32414== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==32414== Command: ./vector.out matrix1.txt matrix1.txt
==32414== 
Вас приветствует программа по обработке разряженных матриц!

Исходная матрица 1 равна:

0       0       0       1       1
1       0       2       0       1
0       0       2       0       9
2       0       0       0       11
7       0       0       0       0

Исходная матрица 2 равна:

0       0       0       1       1
1       0       2       0       1
0       0       2       0       9
2       0       0       0       11
7       0       0       0       0

Результат функции:

Полученная матрица равна:

0       0       0       2       2
2       0       4       0       2
0       0       4       0       18
4       0       0       0       22
14      0       0       0       0

 Не симметрична
==32414== 
==32414== HEAP SUMMARY:
==32414==     in use at exit: 0 bytes in 0 blocks
==32414==   total heap usage: 66 allocs, 66 frees, 11,712 bytes allocated
==32414== 
==32414== All heap blocks were freed -- no leaks are possible
==32414== 
==32414== For lists of detected and suppressed errors, rerun with: -s
==32414== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_kp_7$ valgrind --track-origins=yes ./vector.out matrix1.txt matrix2.txt
==32607== Memcheck, a memory error detector
==32607== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==32607== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==32607== Command: ./vector.out matrix1.txt matrix2.txt
==32607== 
Вас приветствует программа по обработке разряженных матриц!

Исходная матрица 1 равна:

0       0       0       1       1
0       0       0       1       1
0       0       0       0       0
0       0       0       1       1
0       0       0       1       1

Исходная матрица 2 равна:

1       1       0       0       0
1       1       0       0       0
0       0       0       0       0
1       1       0       0       0
1       1       0       0       0

Результат функции:

Полученная матрица равна:

1       1       0       1       1
1       1       0       1       1
0       0       0       0       0
1       1       0       1       1
1       1       0       1       1

Симметрична
==32607== 
==32607== HEAP SUMMARY:
==32607==     in use at exit: 0 bytes in 0 blocks
==32607==   total heap usage: 58 allocs, 58 frees, 11,312 bytes allocated
==32607== 
==32607== All heap blocks were freed -- no leaks are possible
==32607== 
==32607== For lists of detected and suppressed errors, rerun with: -s
==32607== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```


## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **25.05.23** | **13:00** | **Выполнение лаб. работы** | **-** | **-** |

## 10. Замечания автора по существу работы
Codeforces Round 881 (Div. 3) \
[Задача 1843A решена на контесте](https://codeforces.com/contest/1843/submission/210417225)

## 11. Выводы
После выполнения работы, были получены навыки устранения утечек памяти с помощью Valgrind, а так же эффективного представления разреженных матриц в памяти.

<b>Подпись студента:</b> ___________