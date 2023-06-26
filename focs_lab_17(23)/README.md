# Отчёт по лабораторной работе №20 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Ибрагимов Далгат Магомедалиевич, № по списку 8</ins>

<b>Контакты e-mail:</b> <ins>doly2004e@yandex.ru<ins>

<b>Работа выполнена:</b> «25» <ins>мая</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «26» <ins>июня</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins>3</ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема
Динамические структуры данных. Обработка деревьев.

## 2. Цель работы
Написать интерактивную программу для обработки с дерева.

## 3. Задание
Составить программу на языке Си для построения и обработки упорядоченного дерева, содержащего узлы типа float. Основные функции работы с деревьями реализовать в виде универсальных процедур или функций. После того, как дерево создано, его обработка должна производиться в режиме текстового меню со следующими действиями:
- добавление нового узла
- текстовая визуализация дерева (нерекурсивный обход + с отступами, равными глубине узла)
- удаление узла
- определить число вершин дерева, степень которых совпадает со значением элемента.

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
Структура дерева:\
 •tree_t value – значение\
 •tree_node left – указатель на левое поддерево \
 •tree_node right – указатель на правое поддерево\

 Основные функции для работы с двоичным деревом:
1. int tree_insert(tree * tree, tree_t value) - вставка значения value в дерево tree
2. void simple_print_tree(tree * tree); - вывод дерева на экран
3. int tree_erase(tree * tree, tree_t value); - удаление вершины со значением value из дерева tree
4. size_t whole_tree_degree(const tree * const tree); - функция по варианту
Дополнительная функция: void Menu() – вывод меню для работы с деревом


## 7. Сценарий выполнения работы
header.h
```
#ifndef _HEADER_H
#define _HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "tree.h"

#endif
```
stack.h
```
#ifndef _STACK_H_
#define _STACK_H_
#include "tree.h"
#include <stdbool.h>
#include <stddef.h>

typedef  tree_node * stack_t;

typedef struct
{
    stack_t *data;
    size_t capacity, depth;
} stack;

int stack_top(const stack *stack, stack_t *value);

size_t stack_capacity(const stack *stack);

void stack_clear(stack *stack);

void stack_create(stack *stack);

bool stack_is_empty(const stack *stack);

int stack_pop_back(stack *stack);

int stack_push_back(stack *stack, stack_t value);

int stack_resize(stack *stack, size_t newSize, stack_t value);

size_t stack_depth(const stack *stack);

void stack_destroy(stack *stack);

#endif // _STACK_H_/
```
tree_func.h 
```
#ifndef _TREE_FUNC_H_
#define _TREE_FUNC_H_
#include "tree.h"
#include <stdio.h>

size_t whole_tree_degree(const tree * const tree);
#endif //_TREE_FUNC_H_
```

tree.h
```
#ifndef _TREE_H_
#define _TREE_H_
#include <stdbool.h>
#include <stddef.h>
#define TREE_FORMAT_STR "%.3f\n"

typedef float tree_t; 

typedef struct tree_node
{
    struct tree_node * left, * right;
    tree_t value;
} tree_node;

typedef struct
{
    tree_node * root;
    size_t size;
} tree;

bool tree_is_empty(const tree * tree);

void tree_clear(tree * tree);

bool tree_contains(const tree * tree, tree_t value);

void tree_create(tree * tree);

void simple_print_tree(tree * tree);

void simple_print_node(tree_node * t);

int tree_erase(tree * tree, tree_t value);

int tree_insert(tree * tree, tree_t value);

size_t tree_size(const tree * tree);

void tree_destroy(tree * tree);

void tree_print_inorder(const tree * tree);

void tree_print_preorder(const tree * tree);

void tree_print_postorder(const tree * tree);

#endif // _TREE_H_
```

main.c
```
#include "../headers/tree.h"
#include "../headers/stack.h"
#include "../headers/tree_func.h"
#include <stdio.h>
#include <stdlib.h>

static void Menu()
{
    printf(
        "1 - добавить узел\n"
        "2 - удалить узел\n"
        "3 - вывести дерево\n"
        "4 - КЛП обход\n"
        "5 - ЛКП обход\n"
        "6 - ЛПК обход\n"
        "7 - пример дерева\n"
        "8 - очистить дерево\n"
        "9 - вывести число вершин, где значения совпадают со степенью\n"
        "0 - выход\n"
        ">>> "
    );
}


static void example(tree * tree)
{
    tree_insert(tree, 2);
    tree_insert(tree, 3);
    tree_insert(tree, 1);
    tree_insert(tree, 38);
    tree_insert(tree, -2);
    tree_insert(tree, 2.3);
    tree_insert(tree, 0);
    tree_insert(tree, 21);
    tree_insert(tree, 54.7);
    tree_insert(tree, 5);
    tree_insert(tree, 11);
    tree_insert(tree, 28.5);
}


static void output()
{
    tree tr;
    tree_create(&tr);
    int command;
    float n;
    while (true)
    {
        Menu();
        scanf("%d", &command);
        switch (command)
        {
            case 1:
                printf("Введите float значение узла\n");
                scanf("%f", &n);
                tree_insert(&tr, n);
                continue;
            case 2:
                printf("Введите float значение узла\n");
                scanf("%f", &n); 
                tree_erase(&tr, n);
                continue;
            case 3:
                simple_print_tree(&tr);
                continue;
            case 4:
                tree_print_preorder(&tr);
                continue;
            case 5:
                tree_print_inorder(&tr);
                continue;
            case 6:
                tree_print_postorder(&tr);  
                continue; 
            case 7:
                example(&tr);
                continue;
            case 8:
                tree_clear(&tr);
                continue;
            case 9:
                printf("\nКоличество вершин, где значения совпадают со степенью:\n%ld\n\n", whole_tree_degree(&tr));
                continue;
            case 0:
                tree_destroy(&tr);
                return;
        }
    }
}

int main(void)
{
    output();
}
```
stack.c
```
#include "../headers/stack.h"
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

static size_t new_capacity(size_t capacity);

int stack_top(const stack * const stack, stack_t * const value)
{
    if (stack->depth == 0) {
        return -1;
    }
    *value = stack->data[stack->depth - 1];
    return 0;
}

size_t stack_capacity(const stack * const stack)
{
    return stack->capacity;
}

void stack_clear(stack * const stack)
{
    stack->depth = 0;
}

void stack_create(stack * stack)
{
    stack->data = NULL;
    stack->capacity = stack->depth = 0;
}

void stack_destroy(stack * const stack)
{
    free(stack->data);
}

bool stack_is_empty(const stack * const stack)
{
    return stack->depth == 0;
}

int stack_push_back(stack * const stack, const stack_t value)
{
    assert(stack->capacity >= stack->depth);
    if (stack->capacity == stack->depth)
    {
        const size_t capacity = new_capacity(stack->capacity);
        stack_t * const data = realloc(stack->data, capacity * sizeof(stack_t));
        if (data == NULL)
            return -1;
        stack->data = data;
        stack->capacity = capacity;
    }
    assert(stack->capacity > stack->depth);

    stack->data[stack->depth++] = value;
    return 0;
}


int stack_pop_back(stack * const stack) 
{
    if (stack->depth == 0) {
        return -1;
    }
    --stack->depth;
    return 0;
}

int stack_resize(stack * const stack, const size_t newSize, const stack_t value)
{
    if (newSize <= stack->depth)
    {
        stack->depth = newSize;
        return 0;
    }
    assert(newSize > stack->depth);
    if (newSize <= stack->capacity)
    {
        while (stack->depth < newSize)
            stack->data[stack->depth++] = value;
        return 0;
    }
    assert(newSize > stack->capacity);
    stack_t * const data = realloc(stack->data, newSize * sizeof(stack_t));
    if (data == NULL)
        return -1;
    stack->data = data;
    stack->capacity = newSize;
    while (stack->depth < newSize)
        stack->data[stack->depth++] = value;
    return 0;
}

size_t stack_depth(const stack * const stack)
{
    return stack->depth;
}

static size_t new_capacity(const size_t capacity)
{
    if (capacity == 0)
        return 1;
    return (capacity <= SIZE_MAX / 2 ? capacity * 2 : SIZE_MAX);
}/src$ cat tree_func.c
#include "../headers/tree_func.h"
#include "../headers/tree.h"


static size_t node_degree(const tree_node * const  node)
{
    if ((node->left == NULL) && (node->right == NULL))
    {
        return ((node->value == (tree_t)0) ? 1 : 0);
    }
    else if (((node->left == NULL) && (node->right != NULL)))
    {
        return node_degree(node->right) + ((node->value == (tree_t)1) ? 1 : 0);
    }
    else if (((node->right == NULL) && (node->left != NULL)))
    {
        return node_degree(node->left) + ((node->value == (tree_t)1) ? 1 : 0);
    }
    else
    {
        return node_degree(node->left) + node_degree(node->right) + (((node->value) == (tree_t)2) ? 1 : 0);
    }
}

size_t whole_tree_degree(const tree * const tree)
{
    return node_degree(tree->root);
}
```

tree.c
```
#include "../headers/tree.h"
#include "../headers/stack.h"
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void tree_destroy(tree * const tree)
{
    tree->size=0;
    tree_node * node = tree->root;
    tree_node * last_visited_node = NULL;
    stack st;
    stack_create(&st);
    while(!stack_is_empty(&st) || node)
    {
        if (node)
        {
            stack_push_back(&st, node);
            node = node->right;
        }
        else
        {
            tree_node * top_node;
            stack_top(&st, &top_node);
            if (top_node->left && (last_visited_node != top_node->left))
                node = top_node->left;
            else
            {
                free(top_node);
                stack_top(&st, &last_visited_node);
                stack_pop_back(&st);
            }
        }
    }
    stack_destroy(&st);
}

bool tree_contains(const tree * const tree, const tree_t value)
{
    tree_node *node = tree->root;
    while (node != NULL)
    {
        if (node->value > value)
            node = node->left;
        else if (node->value < value)
            node = node->right;
        else
            return true;
    }
    return false;
}

void tree_create(tree * const tree)
{
    tree->root = NULL;
    tree->size = 0;
}

int tree_erase(tree * const tree, const tree_t value)
{
    tree_node **ptr = &tree->root, *node = NULL;
    while (*ptr != NULL)
    {
        node = *ptr;
        if (node->value > value)
            ptr = &node->left;
        else if (node->value < value)
            ptr = &node->right;
        else
        {
            break;
        }
    }

    if (*ptr == NULL)
    {
        return -1;
    }
    assert(node->value == value);
    if (node->left != NULL && node->right != NULL)
    {
        tree_t * const value = &node->value;
        ptr = &node->right;
        node = node->right;
        while (node->left != NULL)
        {
            ptr = &node->left;
            node = node->left;
        }
        *value = node->value;
    }
    if (node->left != NULL)
    {
        assert(node->right == NULL);
        *ptr = node->left;
    }
    else if (node->right != NULL)
    {
        assert(node->left == NULL);
        *ptr = node->right;
    }
    else
        *ptr = NULL;
    free(node);
    --tree->size;
    return 0;
}

int tree_insert(tree * const tree, const tree_t value)
{
    tree_node **ptr = &tree->root, *node = NULL;
    while (*ptr != NULL)
    {
        node = *ptr;
        if (value < node->value)
            ptr = &node->left;
        else if (value > node->value) 
            ptr = &node->right;
        else
        {
            return -1;
        }
    }
    *ptr = malloc(sizeof(tree_node));
    if (*ptr == NULL)
        return -1;
    ++tree->size;
    (*ptr)->left = NULL;
    (*ptr)->right = NULL;
    (*ptr)->value = value;
    return 0;
}

bool tree_is_empty(const tree * const tree)
{
    return tree->size == 0;
}

size_t tree_size(const tree * const tree)
{
    return tree->size;
}

void tree_clear(tree * const tree)
{
    tree_destroy(tree);
    tree_create(tree);
}

void simple_print_node(tree_node * t)
{
    static size_t l = 0;
    l++;
    if (t)
    {
        simple_print_node(t->right);
        for (size_t i = 0; i < l; i++) printf("          ");
        printf(" %f\n", t->value);
        simple_print_node(t->left);
    }
    l--;
}

void simple_print_tree(tree * tree){
    if (!tree_is_empty(tree))
        simple_print_node(tree->root);
}

static size_t tree_node_depth(const tree * const tree, const tree_t value)
{
    tree_node *node = tree->root;
    size_t depth = 0;
    while (node != NULL || (!tree->root->right && !tree->root->left))
    {
        if (node->value > value)
        {
            depth++;
            node = node->left;
        }
        else if (node->value < value)
        {       
            depth++;
            node = node->right;
        }
        else
            return depth;
    }
    return 0;
}

void tree_print_postorder(const tree * const tree)
{
    if (tree_is_empty(tree))
    {
        printf("EMPTY\n");
        return;
    }
    tree_node * node = tree->root;
    tree_node * last_visited_node = NULL;
    stack st;
    stack_create(&st);
    while(!stack_is_empty(&st) || node)
    {
        if (node)
        {
            stack_push_back(&st, node);
            node = node->right;
        }
        else {
            tree_node * top_node;
            stack_top(&st, &top_node);
            if (top_node->left && (last_visited_node != top_node->left))
                node=top_node->left;
            else {
                for(size_t i=0;i<tree_node_depth(tree,top_node->value);i++) printf(" ");
                printf(TREE_FORMAT_STR, top_node->value);
                stack_top(&st, &last_visited_node);
                stack_pop_back(&st);
            }
        }
    }
    stack_destroy(&st);
}

void tree_print_preorder(const tree * const tree)
{
    if (tree_is_empty(tree))
    {
        printf("EMPTY\n");
        return;
    }
    tree_node * node = tree->root;
    stack st;
    stack_create(&st);
    stack_push_back(&st,node);
    while (!stack_is_empty(&st))
    {
        stack_top(&st, &node);
        stack_pop_back(&st);
        for(size_t i=0;i<tree_node_depth(tree,node->value);i++) printf(" ");
        printf(TREE_FORMAT_STR, node->value);
        if (node->right)
            stack_push_back(&st, node->right);
        if (node->left)
            stack_push_back(&st, node->left);
    } 
    stack_destroy(&st);
}

void tree_print_inorder(const tree * const tree)
{
    if (tree_is_empty(tree))
    {
        printf("EMPTY\n");
        return;
    }
    tree_node * node = tree->root;
    stack st;
    stack_create(&st);
    while (!stack_is_empty(&st) || node)
    {
        if (node)
        {
            stack_push_back(&st, node);
            node = node->right;
        }
        else {
            stack_top(&st, &node);
            stack_pop_back(&st);
            for(size_t i=0;i<tree_node_depth(tree,node->value);i++) printf(" ");
            printf(TREE_FORMAT_STR, node->value);
            node = node->left;
        }
    }
}
```

Makefile
```
CC=gcc
RM=rm -fr
CFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18
LDFLAGS=
LDLIBS=
SOURCES= src/stack.c src/tree.c src/main.c src/tree_func.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
        $(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.o: %.c
        $(CC) $(CFLAGS) -c $< -o $@

clean:
        $(RM) *.o $(EXECUTABLE)

debug: CFLAGS+=-Og -g
```

## 8. Распечатка протокола

```
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_17(23)$ make
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c src/main.c -o src/main.o
gcc  src/stack.o src/tree.o src/main.o src/tree_func.o  -o main
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_17(23)$ valgrind --leak-check=full -s ./main
==1018== Memcheck, a memory error detector
==1018== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==1018== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==1018== Command: ./main
==1018== 
1 - добавить узел
2 - удалить узел
3 - вывести дерево
4 - КЛП обход
5 - ЛКП обход
6 - ЛПК обход
7 - пример дерева
8 - очистить дерево
9 - вывести число вершин, где значения совпадают со степенью
0 - выход
>>> 7    
1 - добавить узел
2 - удалить узел
3 - вывести дерево
4 - КЛП обход
5 - ЛКП обход
6 - ЛПК обход
7 - пример дерева
8 - очистить дерево
9 - вывести число вершин, где значения совпадают со степенью
0 - выход
>>> 3
                                         54.700001
                               38.000000
                                                   28.500000
                                         21.000000
                                                             11.000000
                                                   5.000000
                     3.000000
                               2.300000
           2.000000
                     1.000000
                                         0.000000
                               -2.000000
1 - добавить узел
2 - удалить узел
3 - вывести дерево
4 - КЛП обход
5 - ЛКП обход
6 - ЛПК обход
7 - пример дерева
8 - очистить дерево
9 - вывести число вершин, где значения совпадают со степенью
0 - выход
>>> 2
Введите float значение узла
2
1 - добавить узел
2 - удалить узел
3 - вывести дерево
4 - КЛП обход
5 - ЛКП обход
6 - ЛПК обход
7 - пример дерева
8 - очистить дерево
9 - вывести число вершин, где значения совпадают со степенью
0 - выход
>>> 1
Введите float значение узла
17.67
1 - добавить узел
2 - удалить узел
3 - вывести дерево
4 - КЛП обход
5 - ЛКП обход
6 - ЛПК обход
7 - пример дерева
8 - очистить дерево
9 - вывести число вершин, где значения совпадают со степенью
0 - выход
>>> 3
                                         54.700001
                               38.000000
                                                   28.500000
                                         21.000000
                                                                       17.670000
                                                             11.000000
                                                   5.000000
                     3.000000
           2.300000
                     1.000000
                                         0.000000
                               -2.000000
1 - добавить узел
2 - удалить узел
3 - вывести дерево
4 - КЛП обход
5 - ЛКП обход
6 - ЛПК обход
7 - пример дерева
8 - очистить дерево
9 - вывести число вершин, где значения совпадают со степенью
0 - выход
>>> 9

Количество вершин, где значения совпадают со степенью:
2

1 - добавить узел
2 - удалить узел
3 - вывести дерево
4 - КЛП обход
5 - ЛКП обход
6 - ЛПК обход
7 - пример дерева
8 - очистить дерево
9 - вывести число вершин, где значения совпадают со степенью
0 - выход
>>> 4
2.300
 1.000
  -2.000
   0.000
 3.000
  38.000
   21.000
    5.000
     11.000
      17.670
    28.500
   54.700
1 - добавить узел
2 - удалить узел
3 - вывести дерево
4 - КЛП обход
5 - ЛКП обход
6 - ЛПК обход
7 - пример дерева
8 - очистить дерево
9 - вывести число вершин, где значения совпадают со степенью
0 - выход
>>> 5
   54.700
  38.000
    28.500
   21.000
      17.670
     11.000
    5.000
 3.000
2.300
 1.000
   0.000
  -2.000
1 - добавить узел
2 - удалить узел
3 - вывести дерево
4 - КЛП обход
5 - ЛКП обход
6 - ЛПК обход
7 - пример дерева
8 - очистить дерево
9 - вывести число вершин, где значения совпадают со степенью
0 - выход
>>> 6
   54.700
    28.500
      17.670
     11.000
    5.000
   21.000
  38.000
 3.000
   0.000
  -2.000
 1.000
2.300
1 - добавить узел
2 - удалить узел
3 - вывести дерево
4 - КЛП обход
5 - ЛКП обход
6 - ЛПК обход
7 - пример дерева
8 - очистить дерево
9 - вывести число вершин, где значения совпадают со степенью
0 - выход
>>> 8
1 - добавить узел
2 - удалить узел
3 - вывести дерево
4 - КЛП обход
5 - ЛКП обход
6 - ЛПК обход
7 - пример дерева
8 - очистить дерево
9 - вывести число вершин, где значения совпадают со степенью
0 - выход
>>> 3
1 - добавить узел
2 - удалить узел
3 - вывести дерево
4 - КЛП обход
5 - ЛКП обход
6 - ЛПК обход
7 - пример дерева
8 - очистить дерево
9 - вывести число вершин, где значения совпадают со степенью
0 - выход
>>> 1
Введите float значение узла
2
1 - добавить узел
2 - удалить узел
3 - вывести дерево
4 - КЛП обход
5 - ЛКП обход
6 - ЛПК обход
7 - пример дерева
8 - очистить дерево
9 - вывести число вершин, где значения совпадают со степенью
0 - выход
>>> 3
           2.000000
1 - добавить узел
2 - удалить узел
3 - вывести дерево
4 - КЛП обход
5 - ЛКП обход
6 - ЛПК обход
7 - пример дерева
8 - очистить дерево
9 - вывести число вершин, где значения совпадают со степенью
0 - выход
>>> 0
==1018== 
==1018== HEAP SUMMARY:
==1018==     in use at exit: 64 bytes in 1 blocks
==1018==   total heap usage: 32 allocs, 31 frees, 2,808 bytes allocated
==1018== 
==1018== 64 bytes in 1 blocks are definitely lost in loss record 1 of 1
==1018==    at 0x484DCD3: realloc (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==1018==    by 0x1093D4: stack_push_back (in /home/lockr/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_17(23)/main)
==1018==    by 0x10A0A4: tree_print_inorder (in /home/lockr/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_17(23)/main)
==1018==    by 0x10A3DE: output (in /home/lockr/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_17(23)/main)
==1018==    by 0x10A46B: main (in /home/lockr/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_17(23)/main)
==1018== 
==1018== LEAK SUMMARY:
==1018==    definitely lost: 64 bytes in 1 blocks
==1018==    indirectly lost: 0 bytes in 0 blocks
==1018==      possibly lost: 0 bytes in 0 blocks
==1018==    still reachable: 0 bytes in 0 blocks
==1018==         suppressed: 0 bytes in 0 blocks
==1018== 
==1018== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
```


## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **25.05.23** | **13:00** | **Выполнение лаб. работы** | **-** | **-** |

## 10. Замечания автора по существу работы
Контест Codeforces Round 866 (Div. 2) \
[Задача 1816A решена на контесте](https://codeforces.com/contest/1820/submission/202224104) \

## 11. Выводы
Были получены знания о структуре данных упорядоченное бинарное дерево, была проведена работа с этой структурой данных, а также со структурой данных stack для реализации нерекурсивных способов обхода дерева.

<b>Подпись студента:</b> ___________
