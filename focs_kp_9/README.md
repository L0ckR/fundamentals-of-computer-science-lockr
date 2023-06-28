# Отчёт по курсовой работе №9 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Ибрагимов Далгат Магомедалиевич, № по списку 8</ins>

<b>Контакты e-mail:</b> <ins>doly2004e@yandex.ru<ins>

<b>Работа выполнена:</b> «25» <ins>мая</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «27» <ins>июня</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins>3</ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема
Сортировка и поиск

## 2. Цель работы
Составить программу на языке Си с использованием процедур и функций для сортировки таблицы заданным методом и двоичного поиска по ключу в таблице.

## 3. Задание
Шейкер-сорт. Структура таблицы строковый ключ длины 6 байт, ключ и данные хранятся вместе. 12-14 элементов таблицы.

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
Были реализованы следующие функции:
void createVector(vector* v, int size);
bool empty(vector* v);
int sizeVector(vector* v);
value loadVector(vector* v, int i);
void writeVector(vector* v, int i, value data);
void resizeVector(vector* v, int size);
void destroyVector(vector* v);
int compareKeys(value x, value y);
void printTable(vector* v);
void swap(value* x, value* y);
void sortShake(vector* v);
value binarySearch(vector* table, char key[6]);
bool checkSortTable(vector* table);
bool checkSortTableDescending(vector* table);
void vectorReverse(vector* a, vector* b);

## 7. Сценарий выполнения работы

table.h
```
#ifndef table_h
#define table_h

#include <math.h>
#include <ctype.h>
#include <stdio.h> 
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#define STRSIZE 100

typedef struct value {
    char key[6]; //ключ
    char string[STRSIZE]; //строка стихотворения
} value;

typedef struct { //структура вектора
    value* data; //значение
    int size; //размер 
} vector;

void createVector(vector* v, int size);
bool empty(vector* v);
int sizeVector(vector* v);
value loadVector(vector* v, int i);
void writeVector(vector* v, int i, value data);
void resizeVector(vector* v, int size);
void destroyVector(vector* v);
int compareKeys(value x, value y);
void printTable(vector* v);
void swap(value* x, value* y);
void sortShake(vector* v);
value binarySearch(vector* table, char key[6]);
bool checkSortTable(vector* table);
bool checkSortTableDescending(vector* table);
void vectorReverse(vector* a, vector* b);
#endif
```
table.c
```
#include "table.h"

void createVector(vector* v, int size) {
    v->size = size;
    v->data = (value*)malloc(size * sizeof(value));
    for (int i = 0; i < size; i++) {
        strcpy(v->data[i].key, "");
        strcpy(v->data[i].string, "");
    }
}


bool empty(vector* v) { //функция проверки на пустоту
    return v->size == 0;
}

int sizeVector(vector* v) {//функция возвращения размера вектора
    return v->size;
}

value loadVector(vector* v, int i) {//функция вывода элемента вектора
    value emptyValue;
    strcpy(emptyValue.key, ""); //нулевые значения
    strcpy(emptyValue.string, "");
    
    if (i >= 0 && i < v->size) {
        return v->data[i];
    } else {
        return emptyValue;
    }
}

void writeVector(vector* v, int i, value val) {
    if (i >= 0 && i < v->size) {
        v->data[i] = val;
    }
}

void resizeVector(vector* v, int size) { //функция изменения размера вектора
    value* new_values = (value*)realloc(v->data, size * sizeof(value));
    v->data = new_values;
    v->size = size;

    if (v->size > size) {
        for (int i = size; i < v->size; i++) {
            strcpy(v->data[i].key, "");
            strcpy(v->data[i].string, "");
        }
    }
}

void destroyVector(vector* v) {//функция очистки вектора 
    v->size = 0;
    free(v->data);
    v->data = NULL;
}

void printTable(vector* v) { //функция вывода таблицы
    int size = sizeVector(v);
    printf("|============================================|\n");
    printf("|  Ключ  | Значение                          |\n");
    printf("|============================================|\n");
    for (int i = 0; i < size; i++) {
        value tmp = loadVector(v, i);
        printf("| %6s | %-41s \n", tmp.key, tmp.string);
    }
    printf("|============================================|\n");
}

int compareKeys(value x, value y) {
    return strcmp(x.key, y.key);
}

void swap(value* x, value* y) { //функция свапа указателей 
    value temp = *x;
    *x = *y;
    *y = temp;
}

void sortShake(vector* v) { //функция шейк-сортировки
    int left = 0; 
    int right = v->size - 1;
    bool swapped = true;

    while (left < right && swapped) {
        swapped = false;

        for (int i = left; i < right; i++) {
            if (compareKeys(v->data[i], v->data[i + 1]) > 0) {
                swap(&v->data[i], &v->data[i + 1]);
                swapped = true;
            }
        }

        right--;

        for (int i = right; i > left; i--) {
            if (compareKeys(v->data[i - 1], v->data[i]) > 0) {
                swap(&v->data[i - 1], &v->data[i]);
                swapped = true;
            }
        }

        left++;
    }
}

value binarySearch(vector* table, char key[6]) { //функция бинарного поиска по ключу
    int left = 0;
    int right = sizeVector(table) - 1;
    int middle;
    value def = { "", "" }; //если ничено не найдем, то вернем пустой объект

    while (left <= right) {
        middle = (left + right) / 2;

        if (strcmp(key, table->data[middle].key) < 0) {
            right = middle - 1;
        } else if (strcmp(key, table->data[middle].key) > 0) {
            left = middle + 1;
        } else {
            return table->data[middle];
        }
    }

    return def;
}

bool checkSortTable(vector* table) { // функция проверки на отсортированность таблицы
    int size = sizeVector(table);
    for (int i = 0; i < size - 1; i++) {
        value a = loadVector(table, i);
        value b = loadVector(table, i + 1);

        if (compareKeys(a, b) > 0) { //если нарушен порядок
            return false;
        }
    }

    return true;
}

bool checkSortTableDescending(vector* table) {// функция проверки на убывание(обратные порядок)
    int size = sizeVector(table);
    for (int i = 0; i < size - 1; i++) {
        value a = loadVector(table, i);
        value b = loadVector(table, i + 1);

        if (compareKeys(a, b) < 0) { // если нарушен порядок
            return false;
        }
    }

    return true;
}

void vectorReverse(vector* a, vector* b) { //функция записи реверс вектора
    int size = sizeVector(a);
    int pos = 0;
    for(int i = size - 1; i >= 0; i--) {
        value tmp = loadVector(a, i);
        writeVector(b, pos, tmp);
        pos++;
    }
}

```
main.c
```
#include <math.h>
#include <ctype.h>
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "table.h"

void printMenu() {
    printf("\nВыберите дейтсвие:\n");
    printf("0)Выход\n");
    printf("1)Отсортировать таблицу\n");
    printf("2)Найти строку по ключу\n");
    printf("3)Распечатать таблицу\n");
    printf("4)Перезаписать файл\n");
}

void rewriteFile(const char* filename, vector* table) { //функция перезаписи файла
    FILE* file = fopen(filename, "w"); //открываем файл с разрешением на запись
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return;
    }

    int size = sizeVector(table);
    for (int i = 0; i < size; i++) {
        value tmp = loadVector(table, i); //берем каждый элемент вектора
        fprintf(file, "%s %s\n", tmp.key, tmp.string); //записываем в файл
    }

    fclose(file);
}

int main(int argc, char const* argv[]) {
    if (argc != 2) {
        printf("Используйте: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Не удалось открыть файл.\n");
        return 1;
    }

    vector* table = (vector*)malloc(sizeof(vector)); //выделяем память под вектор
    createVector(table, 0);

    char line[STRSIZE]; //линия из файла
    while (fgets(line, sizeof(line), file) != NULL) {
        char key[6];
        char string[STRSIZE];
        sscanf(line, "%5s %[^\n]", key, string); //считываем значения

        value element;
        strcpy(element.key, key); //добавляем их к элементу
        strcpy(element.string, string);
        resizeVector(table, sizeVector(table) + 1);
        writeVector(table, sizeVector(table) - 1, element); 
    }

    fclose(file);

    int size = sizeVector(table);
    printf("Исходная таблица выглядит так:\n");
    printf("|============================================|\n");
    printf("|  Ключ  | Значение                          |\n");
    printf("|============================================|\n");
    for (int i = 0; i < size; i++) {
        value tmp = loadVector(table, i);
        printf("| %6s | %-41s \n", tmp.key, tmp.string);
    }
    printf("|============================================|\n");
    char find[6]; //переменная для поиска по ключу
    int choose = 1;
    while(choose) {
        printMenu();
        scanf("%d", &choose);
        switch(choose) {
            case 0: //выход
                choose = 0;
                destroyVector(table);
                free(table);
                return 0;
                break;
            case 1: //сортировка
                sortShake(table);
                printTable(table);
                break;
            case 2: //поиск
                if (checkSortTableDescending(table)) {
                    vector* reverseTable = (vector*)malloc(sizeof(vector));
                    createVector(reverseTable, sizeVector(table));
                    vectorReverse(table, reverseTable);
                    printf("Введите ключ: ");
                    scanf("%5s", find);
                    if (strcmp(binarySearch(reverseTable, find).key, "")) {
                        printf("| %6s | %s |\n", binarySearch(reverseTable, find).key, binarySearch(reverseTable, find).string);
                    } else {
                        printf("Указанного ключа в таблице нет\n");
                    }
                    destroyVector(reverseTable);
                    free(reverseTable);
                    break;
                } else if (checkSortTable(table) == 0) { //если таблица не отсортирована
                    printf("Для начала отсортируйте таблицу!\n");
                    break;
                } else {
                    printf("Введите ключ: ");
                    scanf("%5s", find);
                    if (strcmp(binarySearch(table, find).key, "")) {
                        printf("| %6s | %s |\n", binarySearch(table, find).key, binarySearch(table, find).string);
                    } else {
                        printf("Указанного ключа в таблице нет\n");
                    }
                    break;
                }
            case 3: //вывод таблицы
                printTable(table);
                break;
            case 4:
                rewriteFile(argv[1], table);
                printf("Файл успешно перезаписан!\n");
                break;
            default:
                printf("Указанного действия не существует!\n");
                break;
            
        }
    }
    return 0;
```
Makefile 
```
CC = gcc
CFLAGS = -std=c99 -Wall -Werror
DEBUG = gdb
FILEOUT = table.out
SOURCES = table.c main.c

all:
        $(CC) $(CFLAGS) $(SOURCES)  -o $(FILEOUT)
clean:
        rm -f *.out
debug:
        $(CC) $(CFLAGS) -g $(SOURCES)
        sudo $(DEBUG) $(FILEOUT)
cmp:
        $(CC) $(CFLAGS) $(SOURCES) -o $(FILEOUT)
run:
        ./$(FILEOUT) $(FILE)
```

## 8. Распечатка протокола

```
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_kp_9$ valgrind --track-origins=yes ./table.out t1.txt
==848== Memcheck, a memory error detector
==848== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==848== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==848== Command: ./table.out t1.txt
==848== 
Не удалось открыть файл.
==848== 
==848== HEAP SUMMARY:
==848==     in use at exit: 0 bytes in 0 blocks
==848==   total heap usage: 2 allocs, 2 frees, 1,496 bytes allocated
==848== 
==848== All heap blocks were freed -- no leaks are possible
==848== 
==848== For lists of detected and suppressed errors, rerun with: -s
==848== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_kp_9$ valgrind --track-origins=yes ./table.out
==926== Memcheck, a memory error detector
==926== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==926== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==926== Command: ./table.out
==926== 
Используйте: ./table.out <filename>
==926== 
==926== HEAP SUMMARY:
==926==     in use at exit: 0 bytes in 0 blocks
==926==   total heap usage: 1 allocs, 1 frees, 1,024 bytes allocated
==926== 
==926== All heap blocks were freed -- no leaks are possible
==926== 
==926== For lists of detected and suppressed errors, rerun with: -s
==926== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_kp_9$ valgrind --track-origins=yes ./table.out t1.txt
==997== Memcheck, a memory error detector
==997== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==997== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==997== Command: ./table.out t1.txt
==997== 
Исходная таблица выглядит так:
|============================================|
|  Ключ  | Значение                          |
|============================================|
|      a | У лукоморья дуб зелёный; 
|     aa | Златая цепь на дубе том: 
|   aaaa | И днём и ночью кот учёный 
|  aaaah | Следы невиданных зверей; 
|  aaaaa | Всё ходит по цепи кругом; 
|  aaaac | Налево — сказку говорит. 
|  aaaab | Идёт направо — песнь заводит, 
|  aaaaf | Русалка на ветвях сидит; 
|  aaaae | Там чудеса: там леший бродит, 
|  aaaag | Там на неведомых дорожках 
|============================================|

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
2
Для начала отсортируйте таблицу!

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
1
|============================================|
|  Ключ  | Значение                          |
|============================================|
|      a | У лукоморья дуб зелёный; 
|     aa | Златая цепь на дубе том: 
|   aaaa | И днём и ночью кот учёный 
|  aaaaa | Всё ходит по цепи кругом; 
|  aaaab | Идёт направо — песнь заводит, 
|  aaaac | Налево — сказку говорит. 
|  aaaae | Там чудеса: там леший бродит, 
|  aaaaf | Русалка на ветвях сидит; 
|  aaaag | Там на неведомых дорожках 
|  aaaah | Следы невиданных зверей; 
|============================================|

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
2
Введите ключ: aaaab
|  aaaab | Идёт направо — песнь заводит, |

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
4
Файл успешно перезаписан!

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
3
|============================================|
|  Ключ  | Значение                          |
|============================================|
|      a | У лукоморья дуб зелёный; 
|     aa | Златая цепь на дубе том: 
|   aaaa | И днём и ночью кот учёный 
|  aaaaa | Всё ходит по цепи кругом; 
|  aaaab | Идёт направо — песнь заводит, 
|  aaaac | Налево — сказку говорит. 
|  aaaae | Там чудеса: там леший бродит, 
|  aaaaf | Русалка на ветвях сидит; 
|  aaaag | Там на неведомых дорожках 
|  aaaah | Следы невиданных зверей; 
|============================================|

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
1
|============================================|
|  Ключ  | Значение                          |
|============================================|
|      a | У лукоморья дуб зелёный; 
|     aa | Златая цепь на дубе том: 
|   aaaa | И днём и ночью кот учёный 
|  aaaaa | Всё ходит по цепи кругом; 
|  aaaab | Идёт направо — песнь заводит, 
|  aaaac | Налево — сказку говорит. 
|  aaaae | Там чудеса: там леший бродит, 
|  aaaaf | Русалка на ветвях сидит; 
|  aaaag | Там на неведомых дорожках 
|  aaaah | Следы невиданных зверей; 
|============================================|

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
3
|============================================|
|  Ключ  | Значение                          |
|============================================|
|      a | У лукоморья дуб зелёный; 
|     aa | Златая цепь на дубе том: 
|   aaaa | И днём и ночью кот учёный 
|  aaaaa | Всё ходит по цепи кругом; 
|  aaaab | Идёт направо — песнь заводит, 
|  aaaac | Налево — сказку говорит. 
|  aaaae | Там чудеса: там леший бродит, 
|  aaaaf | Русалка на ветвях сидит; 
|  aaaag | Там на неведомых дорожках 
|  aaaah | Следы невиданных зверей; 
|============================================|

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
0
==997== 
==997== HEAP SUMMARY:
==997==     in use at exit: 0 bytes in 0 blocks
==997==   total heap usage: 18 allocs, 18 frees, 17,030 bytes allocated
==997== 
==997== All heap blocks were freed -- no leaks are possible
==997== 
==997== For lists of detected and suppressed errors, rerun with: -s
==997== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_kp_9$ valgrind --track-origins=yes ./table.out t2.txt
==1732== Memcheck, a memory error detector
==1732== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1732== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==1732== Command: ./table.out t2.txt
==1732== 
Исходная таблица выглядит так:
|============================================|
|  Ключ  | Значение                          |
|============================================|
|      a | hi                                        
|     aa | wow                                       
|    aaa | wooooooow                                 
|    aaa | wooooooow                                 
|    abb | meow                                      
|============================================|

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
3
|============================================|
|  Ключ  | Значение                          |
|============================================|
|      a | hi                                        
|     aa | wow                                       
|    aaa | wooooooow                                 
|    aaa | wooooooow                                 
|    abb | meow                                      
|============================================|

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
1
|============================================|
|  Ключ  | Значение                          |
|============================================|
|      a | hi                                        
|     aa | wow                                       
|    aaa | wooooooow                                 
|    aaa | wooooooow                                 
|    abb | meow                                      
|============================================|

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
2
Введите ключ: aaa
|    aaa | wooooooow |

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
4
Файл успешно перезаписан!

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
0
==1732== 
==1732== HEAP SUMMARY:
==1732==     in use at exit: 0 bytes in 0 blocks
==1732==   total heap usage: 13 allocs, 13 frees, 12,790 bytes allocated
==1732== 
==1732== All heap blocks were freed -- no leaks are possible
==1732== 
==1732== For lists of detected and suppressed errors, rerun with: -s
==1732== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_kp_9$  valgrind --track-origins=yes ./table.out t3.txt
==1843== Memcheck, a memory error detector
==1843== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1843== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==1843== Command: ./table.out t3.txt
==1843== 
Исходная таблица выглядит так:
|============================================|
|  Ключ  | Значение                          |
|============================================|
|  aaaab | one lol kek                               
|  aaaaa | two hello                                 
|   aaaa | three                                     
|    aaa | four                                      
|     aa | five                                      
|      a | six                                       
|============================================|

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
1
|============================================|
|  Ключ  | Значение                          |
|============================================|
|      a | six                                       
|     aa | five                                      
|    aaa | four                                      
|   aaaa | three                                     
|  aaaaa | two hello                                 
|  aaaab | one lol kek                               
|============================================|

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
3
|============================================|
|  Ключ  | Значение                          |
|============================================|
|      a | six                                       
|     aa | five                                      
|    aaa | four                                      
|   aaaa | three                                     
|  aaaaa | two hello                                 
|  aaaab | one lol kek                               
|============================================|

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
2
Введите ключ: aaab
Указанного ключа в таблице нет

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
2       
Введите ключ: aaaab
|  aaaab | one lol kek |

Выберите дейтсвие:
0)Выход
1)Отсортировать таблицу
2)Найти строку по ключу
3)Распечатать таблицу
4)Перезаписать файл
0
==1843== 
==1843== HEAP SUMMARY:
==1843==     in use at exit: 0 bytes in 0 blocks
==1843==   total heap usage: 12 allocs, 12 frees, 8,858 bytes allocated
==1843== 
==1843== All heap blocks were freed -- no leaks are possible
==1843== 
==1843== For lists of detected and suppressed errors, rerun with: -s
==1843== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```


## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **25.05.23** | **13:00** | **Выполнение лаб. работы** | **-** | **-** |

## 10. Замечания автора по существу работы
Codeforces Round 877 (Div. 2) \
[Задача 1838A решена на контесте](https://codeforces.com/contest/1838/submission/208459660)

## 11. Выводы
После выполнения работы, были получены продвинутые навыки обработки строк и бинарных деревьев в языке Си.

<b>Подпись студента:</b> ___________