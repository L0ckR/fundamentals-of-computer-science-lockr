# Отчёт по лабораторной работе №24 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Ибрагимов Далгат Магомедалиевич, № по списку 8</ins>

<b>Контакты e-mail:</b> <ins>doly2004e@yandex.ru<ins>

<b>Работа выполнена:</b> «25» <ins>мая</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «27» <ins>июня</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins>3</ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема
Деревья арифметических выражений

## 2. Цель работы
Составить программу на Си выполнения заданных преобразований арифметическиз выражений с применением деревьев.

## 3. Задание
Преобразовать выражение в инфиксной записи в дерево арифметического выражения, используя алгоритм сортировочной станции. Над полученным деревом произвести следующее преобразование:

Заменить степень суммой в показателе на произведение степеней: a ^ 3 -> a * a * a 

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
Парсинг инфиксной записи в постфиксную производится с использованием функции-консьюматора, такой подход позволяет использовать одну и ту же функцию для получения и постфиксной записи, и дерева выражения (минуя постфиксную запись)


## 7. Сценарий выполнения работы

expr_tree.h 
```
#ifndef EXPR_TREE_H
#define EXPR_TREE_H

#include <stddef.h>
#include <stdio.h>

#define VARIABLE_LENGTH (16U)
#define NODES_LENGTH (512U)

typedef struct Node Node;

typedef struct {
    Node *left, *right;
    char opChar;
} Operator;

typedef union {
    Operator op;
    char variable[VARIABLE_LENGTH];
    double value;
} NodeUnion;

typedef enum {
    OPERATOR,
    VALUE,
    VARIABLE
} NodeType;

struct Node {
    Node *parent;
    NodeUnion nodeUnion;
    NodeType nodeType;
};

typedef struct {
    Node *root;
} Tree;

void printPostfixFromInfix(FILE *file, const char *expr);

void treeCreateFromInfix(Tree * tree, const char *expr);

void treeDestroy(Tree * tree);

void treeInorderPrint(FILE *file, const Tree *  tree);

double treeCalculate(const Tree * tree, double (*dict)(const char *));

void treeTransform(Tree * tree);

#endif //EXPR_TREE_H
```
stack.h 
```
#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

#include "expr_tree.h"

typedef char StackElem;

typedef struct {
    StackElem *data;
    size_t capacity, depth;
} Stack;

StackElem stackTop(const Stack * const stack);

int stackTopSafe(const Stack *stack, StackElem *value);

size_t stackCapacity(const Stack *stack);

void stackClear(Stack *stack);

void stackCreate(Stack *stack);

bool stackIsEmpty(const Stack *stack);

int stackPopBack(Stack *stack);

int stackPushBack(Stack *stack, StackElem value);

int stackResize(Stack *stack, size_t newSize, StackElem value);

size_t stackDepth(const Stack *stack);

void stackDestroy(Stack *stack);

#endif // STACK_H
```

expr_tree.c 
```
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <assert.h>

#include "../headers/expr_tree.h"
#include "../headers/stack.h"


typedef struct {
    Node *nodes[NODES_LENGTH];
    size_t size;
} Context;

typedef struct {
    double nums[NODES_LENGTH];
    size_t size;
} CalcContext;

enum {ASSOC_LEFT, ASSOC_RIGHT};

static double eval_pow(double a1, double a2) { return pow(a1, a2); }
static double eval_add(double a1, double a2) { return a1+a2; }
static double eval_sub(double a1, double a2) { return a1-a2; }
static double eval_mul(double a1, double a2) { return a1*a2; }
static double eval_div(double a1, double a2) {
  if(!a2) {
    fprintf(stderr, "ERROR: Division by zero\n");
    exit(EXIT_FAILURE);
  }
  return a1/a2;
}
static double eval_mod(double a1, double a2) {
  if(!a2) {
    fprintf(stderr, "ERROR: Division by zero\n");
    exit(EXIT_FAILURE);
  }
  return fmodf(a1, a2);
}

typedef struct {
  char op;
  int prec;
  int assoc;
  bool unary;
  double (*eval)(double a1, double a2);
} OpType;

static OpType getOpType(char c) {
    switch(c)
    {
        case '^':
        return (OpType) {.op = '^', .prec = 2, .assoc = ASSOC_RIGHT, 
                         .unary = false, .eval = eval_pow};
        case '*':
        return (OpType) {.op = '*', .prec = 1, .assoc = ASSOC_LEFT, 
                         .unary = false, .eval = eval_mul};
        case '/':
        return (OpType) {.op = '/', .prec = 1, .assoc = ASSOC_LEFT, 
                         .unary = false, .eval = eval_div};
        case '%':
        return (OpType) {.op = '%', .prec = 1, .assoc = ASSOC_LEFT, 
                         .unary = false, .eval = eval_mod};
        case '+':
        return (OpType) {.op = '+', .prec = 0, .assoc = ASSOC_LEFT, 
                         .unary = false, .eval = eval_add};
        case '-':
        return (OpType) {.op = '-', .prec = 0, .assoc = ASSOC_LEFT, 
                         .unary = false, .eval = eval_sub};
    }
    return (OpType) {.op = '\0', .prec = -1, .assoc = ASSOC_LEFT, .unary = false, .eval = NULL};
}

static bool isOp(char c) {
    return c == '^' || c == '*' || c == '/' || c == '%' || c == '+' || c == '-';
}

static void fromInfix(
    const char *expr,
    void (*consume)(const NodeUnion *, NodeType, void *), // (const *consume)
    void *context
) {
    size_t n = strlen(expr);
    size_t i = 0;
    Stack stack;
    stackCreate(&stack);
    while (i < n) {
        if (expr[i] == ' ') {
            ++i;
            continue;
        }
        if (expr[i] == '(') {
            stackPushBack(&stack, '(');
        }
        else if (expr[i] == ')') {
            while (!stackIsEmpty(&stack) &&  stackTop(&stack) !=  '(') {
                NodeUnion node_union = { .op = { .left = NULL, .right = NULL, .opChar = stackTop(&stack)} };
                NodeType node_type = OPERATOR;
                consume(&node_union, node_type, context);
                stackPopBack(&stack);
            }
            if (stackIsEmpty(&stack)) {
                fprintf(stderr, "ERROR: Incorrect parenthesis\n");
                exit(EXIT_FAILURE);
            }
            stackPopBack(&stack);
        }
        else if (isOp(expr[i])) {
            while (!stackIsEmpty(&stack) && (getOpType(stackTop(&stack)).prec > getOpType(expr[i]).prec || 
                  (getOpType(stackTop(&stack)).prec == getOpType(expr[i]).prec &&
                  getOpType(expr[i]).assoc == ASSOC_LEFT))) {
                NodeUnion node_union = { .op = { .left = NULL, .right = NULL, .opChar = stackTop(&stack)} };
                NodeType node_type = OPERATOR;
                consume(&node_union, node_type, context);
                stackPopBack(&stack);
            }
            stackPushBack(&stack, expr[i]);
        }
        else if (isalpha(expr[i])) {
            size_t start = i;
            do {
                ++i;
            } while (isalpha(expr[i]));
            if (i - start > VARIABLE_LENGTH - 1) {
                fprintf(stderr, "ERROR: Too long name of variable\n");
                exit(EXIT_FAILURE);
            }
            NodeUnion node_union;
            memcpy(node_union.variable, expr + start, i - start);
            node_union.variable[i - start] = '\0';
            NodeType node_type = VARIABLE;
            consume(&node_union, node_type, context);
            --i;
        }
        else if (isdigit(expr[i])) {
            char *end;
            double num = strtod(expr + i, &end);
            i = end - expr;
            NodeUnion node_union = {.value = num};
            NodeType node_type = VALUE;
            consume(&node_union, node_type, context);
            --i;
        }
        else {
            fprintf(stderr, "ERROR: incorrect character %c\n", expr[i]);
            exit(EXIT_FAILURE);
        }
        ++i;
    }
    while (!stackIsEmpty(&stack)) {
        if (stackTop(&stack) != '(') {
            NodeUnion node_union = { .op = { .left = NULL, .right = NULL, .opChar = stackTop(&stack)} };
            NodeType node_type = OPERATOR;
            consume(&node_union, node_type, context);
        }
        stackPopBack(&stack);
    }

    stackDestroy(&stack);

}

static void consumeToStream(const NodeUnion * node_union, NodeType node_type, void * context) {
    if (node_type == VALUE) {
        fprintf((FILE *) context, "%f ", node_union->value);
    }
    if (node_type == VARIABLE) {
        fprintf((FILE *) context, "%s ", node_union->variable);
    }
    if (node_type == OPERATOR) {
        fprintf((FILE *) context, "%c ", node_union->op.opChar);
    }
}

void printPostfixFromInfix(FILE *file, const char *expr) {
    fromInfix(expr, consumeToStream, file);
    fprintf(file, "\n");
}

static void consumeToTree(
    const NodeUnion *node_union,
    NodeType node_type,
    void * const ptr
) {
    Context * const context = (Context *) ptr;
    Node *node = malloc(sizeof(Node));
    if (!node) abort();
    node->nodeUnion = *node_union;
    node->nodeType = node_type;
    if (node->nodeType == OPERATOR) {
        OpType op_type = getOpType(node->nodeUnion.op.opChar);
        if (!op_type.unary) {
            node->nodeUnion.op.right = context->nodes[--context->size];
            node->nodeUnion.op.right->parent = node;
        }
        node->nodeUnion.op.left = context->nodes[--context->size];
        node->nodeUnion.op.left->parent = node;

    }
    context->nodes[context->size++] = node;
}

void treeCreateFromInfix(Tree * const tree, const char *expr) {
    
    Context context = {.size = 0};

    fromInfix(expr, consumeToTree, &context);

    tree->root = context.size != 0 ? context.nodes[0] : NULL;
}

static void postorderDestroy(Node * const node) {
    if (node->nodeType == OPERATOR) {
        postorderDestroy(node->nodeUnion.op.left);
        postorderDestroy(node->nodeUnion.op.right);
    }
    free(node);
}

void treeDestroy(Tree * const tree) {
    Node *node = tree->root;
    if (node != NULL) {
        postorderDestroy(node);
    }
}

static void inorderPrint(FILE *file, const Node * const node,  size_t _depth) {
    if (node->nodeType == OPERATOR) {
        inorderPrint(file, node->nodeUnion.op.right,  _depth+1);
        for (size_t i=0; i < _depth; ++i) {
            fprintf(file, " ");
        }
        fprintf(file, "%c\n", node->nodeUnion.op.opChar);
        inorderPrint(file, node->nodeUnion.op.left,  _depth+1);
    }
    else {
        for (size_t i=0; i < _depth; ++i) {
            fprintf(file, " ");
        }
        if (node->nodeType == VALUE) fprintf(file, "%f\n", node->nodeUnion.value);
        else fprintf(file, "%s\n", node->nodeUnion.variable);
    }
}

void treeInorderPrint(FILE *file, const Tree * const tree) {
    Node *node = tree->root;
    if (node != NULL) {
        inorderPrint(file, node, 0);
    }
}

static void postorderCalculate(const Node * const node, void * const ptr, double (*dict)(const char *)) {
    CalcContext * const context = (CalcContext *) ptr;
    if (node->nodeType == OPERATOR) {
        postorderCalculate(node->nodeUnion.op.left, context, dict);
        postorderCalculate(node->nodeUnion.op.right, context, dict);
        OpType op_type = getOpType(node->nodeUnion.op.opChar);
        double y = context->nums[--context->size];
        double x = context->nums[--context->size];
        context->nums[context->size++]=op_type.eval(x, y);
    }
    else if (node->nodeType == VALUE) {
        context->nums[context->size++] = node->nodeUnion.value;
    }
    else {
        context->nums[context->size++] = dict(node->nodeUnion.variable);
    }
}

double treeCalculate(const Tree * const tree, double (*dict)(const char *)) {
    CalcContext calc_context = {.size = 0};
    Node *node = tree->root;
    assert(node != NULL);
    postorderCalculate(node, &calc_context, dict);
    assert(calc_context.size == 1);
    return calc_context.nums[0];
}

static Node *nodeDeepCopy(Node * const node) {
    Node *new_node = malloc(sizeof(Node));
    if (!new_node) abort(); 
    memcpy(new_node, node, sizeof(Node));
    if (node && node->nodeType != OPERATOR) {
        return new_node;
    }
    new_node->nodeUnion.op.left = nodeDeepCopy(node->nodeUnion.op.left);
    new_node->nodeUnion.op.right = nodeDeepCopy(node->nodeUnion.op.right);
    return new_node;
}

static void preorderTransform(Node *const node)
{
    if (node->nodeType == OPERATOR)
    {
        if (node->nodeUnion.op.opChar == '^' && 
            node->nodeUnion.op.right->nodeType == VALUE && 
            floor(node->nodeUnion.op.right->nodeUnion.value) == ceil(node->nodeUnion.op.right->nodeUnion.value) ) 
        {

            long long int degree = (long long int)node->nodeUnion.op.right->nodeUnion.value;
            
            if (degree == 0)
            {
                postorderDestroy(node->nodeUnion.op.left);
                postorderDestroy(node->nodeUnion.op.right);
                node->nodeType = VALUE;
                node->nodeUnion.value = 1;
                return;

            }else if(degree < 0)
            {
                Node *tmp = nodeDeepCopy(node->nodeUnion.op.left);
                postorderDestroy(node->nodeUnion.op.left);
                postorderDestroy(node->nodeUnion.op.right);
                node->nodeUnion.op.left = malloc(sizeof(Node));
                node->nodeUnion.op.left->nodeType = VALUE;
                node->nodeUnion.op.left->nodeUnion.value = 1; 
                node->nodeUnion.op.opChar = '/';
                tmp->nodeUnion.op.right->nodeUnion.value = tmp->nodeUnion.op.right->nodeUnion.value *(-1);
                node->nodeUnion.op.right = tmp;
                
            }else if(degree > 0)
            {  
                if (degree == 1){
                    memcpy(node, node->nodeUnion.op.left, sizeof(Node));
                    return;
                }else{
                    Node *tmp = nodeDeepCopy(node);
                    node->nodeUnion.op.opChar = '*';
                    --tmp->nodeUnion.op.right->nodeUnion.value;
                    node->nodeUnion.op.right = tmp;
                }
            }
        }
        preorderTransform(node->nodeUnion.op.left);
        preorderTransform(node->nodeUnion.op.right);
    }
}

void treeTransform(Tree * const tree) {
    Node *node = tree->root;
    preorderTransform(node);
}
```

stack.c
```
#include <assert.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>

#include "../headers/stack.h"

static size_t newCapacity(size_t capacity);

int stackTopSafe(const Stack * const stack, StackElem * const value) {
    if (stack->depth == 0) {
        errno = EINVAL;
        return -1;
    }
    *value = stack->data[stack->depth - 1];
    return 0;
}

StackElem stackTop(const Stack * const stack) {
    return stack->data[stack->depth - 1];
}

size_t stackCapacity(const Stack * const stack) {
    return stack->capacity;
}

void stackClear(Stack * const stack) {
    stack->depth = 0;
}

void stackCreate(Stack * stack) {
    stack->data = NULL;
    stack->capacity = stack->depth = 0;
}

void stackDestroy(Stack * const stack) {
    free(stack->data);
}

bool stackIsEmpty(const Stack * const stack) {
    return stack->depth == 0;
}

int stackPushBack(Stack * const stack, const StackElem value) {
    assert(stack->capacity >= stack->depth);
    if (stack->capacity == stack->depth) {
        const size_t capacity = newCapacity(stack->capacity);
        StackElem * const data = realloc(stack->data, capacity * sizeof(StackElem));
        if (data == NULL)
            return -1;
        stack->data = data;
        stack->capacity = capacity;
    }
    assert(stack->capacity > stack->depth);

    stack->data[stack->depth++] = value;
    return 0;
}


int stackPopBack(Stack * const stack) {
    if (stack->depth == 0) {
        errno = EINVAL;
        return -1;
    }
    --stack->depth;
    return 0;
}

int stackResize(Stack * const stack, const size_t newSize, const StackElem value) {
    if (newSize <= stack->depth) {
        stack->depth = newSize;
        return 0;
    }
    assert(newSize > stack->depth);
    if (newSize <= stack->capacity) {
        while (stack->depth < newSize)
            stack->data[stack->depth++] = value;
        return 0;
    }
    assert(newSize > stack->capacity);
    StackElem * const data = realloc(stack->data, newSize * sizeof(StackElem));
    if (data == NULL)
        return -1;
    stack->data = data;
    stack->capacity = newSize;
    while (stack->depth < newSize)
        stack->data[stack->depth++] = value;
    return 0;
}

size_t stackDepth(const Stack * const stack) {
    return stack->depth;
}

static size_t newCapacity(const size_t capacity) {
    if (capacity == 0)
        return 1;
    return capacity <= SIZE_MAX / 2 ? capacity * 2 : SIZE_MAX;
}
```

main.c
```
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../headers/expr_tree.h"

double exampleDict (const char * var) {
    if (strcmp(var, "a") == 0) {
        return 6;
    }
    else if (strcmp(var, "b") == 0) {
        return 7;
    }
    else if (strcmp(var, "c") == 0) {
        return 8;
    }
    else {
        fprintf(stderr, "ERROR: Undefined variable\n");
        exit(EXIT_FAILURE);
    }
}

static char *inputString(FILE* fp){
    size_t size = 16;
    char *str;
    int ch;
    size_t len = 0;
    str = malloc(size);
    if (!str) return str;
    while((ch=fgetc(fp)) != '\n'){
        if (ch == EOF) {
            if (len==0) {
                free(str);
                return NULL;
            }
            else break;
        };
        str[len++]=ch;
        if(len==size) {
            str = realloc(str, size*=2);
            if (!str) return str;
        }
    }
    str[len++]='\0';
    return realloc(str, len);
}

int main(void) {
    char *expr = inputString(stdin);
    if (!expr) abort();
    fprintf(stdout, "%s\n", expr);
    fprintf(stdout, "----------------------\n");
    printPostfixFromInfix(stdout, expr);
    fprintf(stdout, "----------------------\n");
    Tree tree;
    treeCreateFromInfix(&tree, expr);
    free(expr);
    treeInorderPrint(stdout, &tree);
    fprintf(stdout, "----------------------\n");
    double res = treeCalculate(&tree, exampleDict);
    fprintf(stdout, "Calculated: %f\n", res);
    fprintf(stdout, "----------------------\n");
    fprintf(stdout, "Transformation:\n");
    treeTransform(&tree);
    treeInorderPrint(stdout, &tree);
    fprintf(stdout, "----------------------\n");
    res = treeCalculate(&tree, exampleDict);
    fprintf(stdout, "Calculated: %f\n", res);
    treeDestroy(&tree);
}
```

Makefile
```
CC=gcc
CFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18
LDFLAGS=
LDLIBS= -lm
SOURCES= src/main.c src/expr_tree.c src/stack.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=main

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
        $(CC) $(LDFLAGS) $(OBJECTS) $(LDLIBS) -o $@

%.o: %.c
        $(CC) $(CFLAGS) -c $< -o $@

clean:
        rm -rf src/*.o $(EXECUTABLE)

debug: CFLAGS+=-Og -g

```

## 8. Распечатка протокола

```
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_18(24)$ make all
gcc -Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -std=c18 -c src/expr_tree.c -o src/expr_tree.o
gcc  src/main.o src/expr_tree.o src/stack.o -lm -o main
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_18(24)$ valgrind --leak-check=full  ./main < test.txt
==909== Memcheck, a memory error detector
==909== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==909== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==909== Command: ./main
==909== 
(5+8)^(1)
----------------------
5.000000 8.000000 + 1.000000 ^ 
----------------------
 1.000000
^
  8.000000
 +
  5.000000
----------------------
Calculated: 13.000000
----------------------
Transformation:
 8.000000
+
 5.000000
----------------------
Calculated: 13.000000
==909== 
==909== HEAP SUMMARY:
==909==     in use at exit: 0 bytes in 0 blocks
==909==   total heap usage: 16 allocs, 16 frees, 5,472 bytes allocated
==909== 
==909== All heap blocks were freed -- no leaks are possible
==909== 
==909== For lists of detected and suppressed errors, rerun with: -s
==909== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_18(24)$ valgrind --leak-check=full  ./main < test.txt
==996== Memcheck, a memory error detector
==996== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==996== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==996== Command: ./main
==996== 
((5+8)^(1)+(5-8)^(3))^(5)
----------------------
5.000000 8.000000 + 1.000000 ^ 5.000000 8.000000 - 3.000000 ^ + 5.000000 ^ 
----------------------
 5.000000
^
   3.000000
  ^
    8.000000
   -
    5.000000
 +
   1.000000
  ^
    8.000000
   +
    5.000000
----------------------
Calculated: -537824.000000
----------------------
Transformation:
      3.000000
     ^
       8.000000
      -
       5.000000
    +
      1.000000
     ^
       8.000000
      +
       5.000000
   *
        8.000000
       -
        5.000000
      *
        8.000000
       -
        5.000000
     *
       8.000000
      -
       5.000000
    +
      8.000000
     +
      5.000000
  *
       8.000000
      -
       5.000000
     *
       8.000000
      -
       5.000000
    *
      8.000000
     -
      5.000000
   +
     8.000000
    +
     5.000000
 *
      8.000000
     -
      5.000000
    *
      8.000000
     -
      5.000000
   *
     8.000000
    -
     5.000000
  +
    8.000000
   +
    5.000000
*
     8.000000
    -
     5.000000
   *
     8.000000
    -
     5.000000
  *
    8.000000
   -
    5.000000
 +
   8.000000
  +
   5.000000
----------------------
Calculated: -537824.000000
==996== 
==996== HEAP SUMMARY:
==996==     in use at exit: 0 bytes in 0 blocks
==996==   total heap usage: 151 allocs, 151 frees, 10,808 bytes allocated
==996== 
==996== All heap blocks were freed -- no leaks are possible
==996== 
==996== For lists of detected and suppressed errors, rerun with: -s
==996== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_lab_18(24)$ valgrind --leak-check=full --show-leak-kinds=all -s ./main < test.txt
==10452== Memcheck, a memory error detector
==10452== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==10452== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==10452== Command: ./main
==10452== 
(5-8)^(0)
----------------------
5.000000 8.000000 - 0.000000 ^ 
----------------------
 0.000000
^
  8.000000
 -
  5.000000
----------------------
Calculated: 1.000000
----------------------
Transformation:
1.000000
----------------------
Calculated: 1.000000
==10452== 
==10452== HEAP SUMMARY:
==10452==     in use at exit: 0 bytes in 0 blocks
==10452==   total heap usage: 13 allocs, 13 frees, 5,352 bytes allocated
==10452== 
==10452== All heap blocks were freed -- no leaks are possible
==10452== 
==10452== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

```


## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **25.05.23** | **13:00** | **Выполнение лаб. работы** | **-** | **-** |

## 10. Замечания автора по существу работы
Codeforces Round 876 (Div. 2) \
[Задача 1839A решена на контесте](https://codeforces.com/contest/1839/submission/208344759)

## 11. Выводы
После выполнения работы, были получены продвинутые навыки обработки строк и бинарных деревьев в языке Си.

<b>Подпись студента:</b> ___________