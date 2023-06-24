# Отчёт по лабораторной работе №25-26 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Ибрагимов Далгат Магомедалиевич, № по списку 8</ins>

<b>Контакты e-mail:</b> <ins>doly2004e@yandex.ru<ins>

<b>Работа выполнена:</b> «25» <ins>мая</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «_» <ins>_________</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins>_</ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема
Динамические структуры данных. Обработка деревьев.

## 2. Цель работы
Составить и отладить модуль определений и модуль реализации по заданной схеме модуля определений для абстрактного(пользовательского) типа данных(стека, очереди, списка или дека, в зависимости от варианта задания). Составить программный модуль, сортирующий экземпляр указанного абстрактного типа данных заданным методом. с помощью утилиты make

## 3. Задание
Структура данных: Очередь. Сортировка и процедура: сортировка простой вставкой(Вставка элемента в очередь, упорядоченную по возрастанию с сохранением порядка).  

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
Сначала будут написаны заголовочные файлы с определением макросов, типов, и функций. Затем соответствующие компилируемые файлы с реализацией описанных функций. Готовая реализация вектора с легкостью может быть переделана в стэк, необходимый для нерекурсивного обхода дерева. После реализации самого дерева с необходимыми функциями, приступим к написанию рекерсивной функции для определения глубины дерева. В конце выполнения лабораторной работы в `main.c` будет реализовано интерактивное меню. Для сборки программы на протяжении всего выполнения лабораторной будет использоваться утилита `make`.

## 7. Сценарий выполнения работы
Очередь — абстрактный тип данных с дисциплиной доступа к элементам «первый пришёл — первый вышел» (FIFO, англ. first in, first out).
Для работы с деком реализованы следующие операции:
```
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_19-20(25-26)/headers$ cat header.h 
#ifndef _HEADER_H
#define _HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"
#include "sort.h"

#endif
    lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_19-20(25-26)/headers$ cat queue.h 
#include <stdbool.h>

typedef struct item item;

struct item {
    double value;
    item* next;
};

typedef struct {
    item* first;
    item* last;
    int size;
} queue;

void    create(queue* q);
bool    is_empty(queue* q);
int     size(queue* q);
bool    push(queue* q, const double value);
double  pop(queue* q);
void    printQ(queue* q);
void    destroy(queue* q);
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_19-20(25-26)/headers$ cat sort.h 
// вставка элемента в отсортированную очередь с сохранением порядка
// сортировка простой вставкой

void insert(queue* q, double elem);
void sort(queue* q);
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_19-20(25-26)/headers$ cd ../
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_19-20(25-26)$ cd src/
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_19-20(25-26)/src$ cat queue.c 
#include "../headers/header.h"

void create(queue* q){
    q->first = q->last = malloc(sizeof(item));
    q->size = 0;
}

bool is_empty(queue* q){
    return q->first == q->last;
}

int size(queue* q){
    return q->size;
}

bool push(queue* q, const double value){
    if (!(q->last->next = malloc(sizeof(item)))){
        return false;
    }
    q->last->value = value;
    q->last = q->last->next;
    q->size++;
    return true;
}

double pop(queue* q){
    item *tmp = q->first;
    double value = tmp->value;
    q->first = q->first->next;
    q->size--;
    free(tmp);
    return value;
}

void printQ(queue* q){
    int len = size(q);
    item *tmp = q->first;
    for (int i = 0; i < len; ++i){
        double value = tmp->value;
        printf("%lf ", value);
        tmp = tmp->next;
    }
    printf("\n");
}

void destroy(queue* q){
    q->last->next = NULL;
    item* tmp = q->first;
    q->first = q->first->next;
    free(tmp);
    if (q->first){
        destroy(q);
    }
    q->last = NULL;
    q->size = 0;
}
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_19-20(25-26)/src$ cat sort.c 
#include "../headers/header.h"

void insert(queue* buffer, double elem){

    int buffer_length = size(buffer);

    if (size(buffer) == 1){
        double cmp = pop(buffer);
        if (cmp >= elem){
            push(buffer, elem);
            push(buffer, cmp);
        } else {
            push(buffer, cmp);
            push(buffer, elem);
        }
    } else {
        double left = pop(buffer);
        double right = pop(buffer);
        int position = 2;
        for (int i = 0; i <= size(buffer); ++i){
            if (elem <= left){
                push(buffer, elem);
                push(buffer, left);
                push(buffer, right);
                for (int j = position; j < size(buffer) - 1; ++j){
                    double tmp = pop(buffer);
                    push(buffer, tmp);
                }
                break;
            } else if (elem > left && elem <= right){
                push(buffer, left);
                push(buffer, elem);
                push(buffer, right);
                for (int j = position; j < size(buffer) - 1; ++j){
                    double tmp = pop(buffer);
                    push(buffer, tmp);
                    printQ(buffer);
                }
                break;
            } else {
                push(buffer, left);
                if (position == buffer_length){
                    push(buffer, right);
                    push(buffer, elem);
                    printQ(buffer);
                    break;
                } else {
                    left = right;
                    right = pop(buffer);
                    position++;
                }
            }
        }
    }

}

void sort(queue* q){

    int sorted = 1;
    if (sorted == size(q)){ return; }

    queue buffer; 
    create(&buffer);

    while (sorted < size(q)){
    
        for (int i = 0; i < sorted; ++i){
            double tmp = pop(q);
            push(&buffer, tmp);
        }

        double elem = pop(q);
        insert(&buffer, elem);

        while (!is_empty(q)){
            double tmp = pop(q);
            push(&buffer, tmp);
        }

        while (!is_empty(&buffer)){
            double tmp = pop(&buffer);
            push(q, tmp);
        }
        
        sorted++;

    }
    destroy(&buffer);

}
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_19-20(25-26)/src$ cat main.c 
#include "../headers/header.h"

void print_result(queue* q){
    printQ(q);
    double elem = pop(q);
    bool is_sorted = true;
    while (!is_empty(q)){
        double next_elem = pop(q);
        if (elem > next_elem){
            is_sorted = false;
        }
        elem = next_elem;
    }
    if (is_sorted){
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main(){

    queue q;
    create(&q);

    int m;
    printf("Input number of elements\n");
    scanf("%d", &m);
    printf("Enter %d values\n", m);
    for (int i = 0; i < m; ++i){
        double n;
        scanf("%lf", &n);
        push(&q, n);
    }
    printQ(&q);
    if (!is_empty(&q)){
        sort(&q);
        print_result(&q);
    } else {
        printf("Empty queue\n");
    }
    destroy(&q);

}
```


## 8. Распечатка протокола

```
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_19-20(25-26)$ make
gcc -g -c -Wall -pedantic --std=c99 src/main.c
gcc -g -c -Wall -pedantic --std=c99 src/queue.c
gcc main.o queue.o sort.o -o main
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_19-20(25-26)$ valgrind --leak-check=full -s ./main
==803== Memcheck, a memory error detector
==803== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==803== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==803== Command: ./main
==803== 
Input number of elements
3
Enter 3 values
2 1 3
2.000000 1.000000 3.000000 
1.000000 2.000000 3.000000 
1.000000 2.000000 3.000000 
Yes
==803== 
==803== HEAP SUMMARY:
==803==     in use at exit: 0 bytes in 0 blocks
==803==   total heap usage: 22 allocs, 22 frees, 2,368 bytes allocated
==803== 
==803== All heap blocks were freed -- no leaks are possible
==803== 
==803== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_19-20(25-26)$ valgrind --leak-check=full -s ./main
==1588== Memcheck, a memory error detector
==1588== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1588== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==1588== Command: ./main
==1588== 
Input number of elements
7
Enter 7 values
-2.5 -28 27 5 3 2 0
-2.500000 -28.000000 27.000000 5.000000 3.000000 2.000000 0.000000 
-28.000000 -2.500000 27.000000 
-28.000000 -2.500000 3.000000 5.000000 27.000000 
27.000000 -28.000000 -2.500000 2.000000 3.000000 5.000000 
-28.000000 -2.500000 2.000000 3.000000 5.000000 27.000000 
5.000000 27.000000 -28.000000 -2.500000 0.000000 2.000000 3.000000 
27.000000 -28.000000 -2.500000 0.000000 2.000000 3.000000 5.000000 
-28.000000 -2.500000 0.000000 2.000000 3.000000 5.000000 27.000000 
-28.000000 -2.500000 0.000000 2.000000 3.000000 5.000000 27.000000 
Yes
==1588== 
==1588== HEAP SUMMARY:
==1588==     in use at exit: 0 bytes in 0 blocks
==1588==   total heap usage: 116 allocs, 116 frees, 3,872 bytes allocated
==1588== 
==1588== All heap blocks were freed -- no leaks are possible
==1588== 
==1588== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```


## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **25.05.23** | **13:00** | **** | **-** | **-** |

## 10. Замечания автора по существу работы
Codeforces Round 873 (Div. 2)
https://codeforces.com/contest/1828/submission/205862989

Educational Codeforces Round 149 (Rated for Div. 2)
https://codeforces.com/contest/1837/submission/207179068


## 11. Выводы
Были получены знания по динамическим структурам, а так же Makefile.

<b>Подпись студента:</b> ___________
