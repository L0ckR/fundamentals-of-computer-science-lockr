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