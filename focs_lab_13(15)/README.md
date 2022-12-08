# Отчёт по лабораторной работе №15 по курсу "Фундаментальная информатика"
<b>Студент группы:</b> <ins>М80-108Б-22 Ибрагимов Далгат Магомедалиевич, № по списку 9</ins> 

<b>Контакты e-mail:</b> <ins>doly2004e@yandex.ru</ins>

<b>Работа выполнена:</b> <ins> «29» <ins>ноября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5 (отлично)</ins>

<b>Отчет сдан</b> <ins>«3» Декабря 2022</ins> г., <b>итоговая оценка</b> <ins>5 (отлично)</ins>

<b>Подпись преподавателя:</b> ________________

## 1. Тема
Обработка матриц
## 2. Цель работы
Составить программу на языке Си, производящую обработку квадратной матрицы порядка NxN (1 <= N <= 8), из целых чисел, вводимой из стандартного входного текстового файла.
## 3. Задание (вариант № 9*)
Циклический сдвиг элементов матрицы в её строчном представлении на 8 элементов.(8 - номер группы)
## 4. Оборудование
<b>Процессор:</b> AMD Ryzen 5 5600H (12) @ 3.600GHz<br/>
<b>ОП:</b> 32GiB 3200 MHz LPDDR4<br/>
<b>Текстовый редактор:</b> Visual Studio Code версия 1.73.0 <br/>

## 5. Программное обеспечение:
<b>Операционная система семейства:</b> Microsoft Windows 11 Pro <br/>
<b>Компилятор:</b> GNU Compiler Collection <br/>
<b>Текстовый редактор:</b> Visual Studio Code версия 1.73.0 <br/>
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
1. Ввод размера матрицы; 
2. Создание матрицы;
3. Написание функций, необходимых для выполнения задачи;
4. Вывод ответа.

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
```c:lab.c

#include <stdio.h>
#include <stdlib.h>

void out(int N, int m[], int n_g){
  int b[N*N];
  for (int k = n_g%(N*N) - 1; k >= 0; --k)
  {
    b[k] = m[N*N - (n_g%(N*N) - k)];
  }
  for (int k = 0; k < N*N - n_g%(N*N); k++)
  {
    b[k + n_g%(N*N)] = m[k];
  }
  printf("OUT:\n");
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++) {
      printf("%d ", b[i * N + j]);
    }
    printf("\n");
  }
}


int main() {
  int N;
  //  = 7;
  int n_g;
  printf("GROUP NUMBER\n");
  scanf("%d", &n_g);
  printf("MATRIX SIZE:\n");
  scanf("%d", &N);
  int m[N*N];
  // = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49};
   
  printf("MATRIX:\n");

  for (int k = 0; k != N*N; k++)
  {
      scanf("%d", &m[k]);
  }
  out(N, m, n_g);
  
}
```
Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> ________________
## 8. Распечатка протокола 
```
PS C:\Users\lock_R\Documents\cc> gcc -g lab15.c -pedantic -Wall
PS C:\Users\lock_R\Documents\cc> ./a.exe
GROUP NUMBER
2
MATRIX SIZE:
3
MATRIX:
1 2 3 4 5 6 7 8 9
OUT:
8 9 1
2 3 4
5 6 7
PS C:\Users\lock_R\Documents\cc> gcc -g lab15.c -pedantic -Wall
PS C:\Users\lock_R\Documents\cc> ./a.exe
GROUP NUMBER
9
MATRIX SIZE:
3
MATRIX:
1 2 3 4 5 6 7 8 9
OUT:
1 2 3
4 5 6
7 8 9
PS C:\Users\lock_R\Documents\cc> ./a.exe      
GROUP NUMBER
3
MATRIX SIZE:
4
MATRIX:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
OUT:
14 15 16 1
2 3 4 5
6 7 8 9
10 11 12 13
PS C:\Users\lock_R\Documents\cc> gcc .\lab15.c
PS C:\Users\lock_R\Documents\cc> ./a.exe      
GROUP NUMBER
12
MATRIX SIZE:
4
MATRIX:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
OUT:
5 6 7 8
9 10 11 12
13 14 15 16
1 2 3 4
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 29.11.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
[A. Странная сумма](https://codeforces.com/contest/1648/problem/A)
[Решение:](https://codeforces.com/contest/1648/submission/184075476)
```c:lab.c
#include <stdio.h>
#include <stdlib.h>
#define N (100000)
 
typedef long long ll;
 
 
typedef struct{
    ll color;
    ll m, n;
} color_index;
 
int comp_m (const void *_a, const void *_b)
{
    color_index *a = (color_index *) _a;
    color_index *b = (color_index *) _b;
    if (a->color == b->color){
        return a->m - b->m;
    }
    return a->color - b->color;
}
 
 
int comp_n (const void *_a, const void *_b)
{
    color_index *a = (color_index *) _a;
    color_index *b = (color_index *) _b;
    if (a->color == b->color){
        return a->n - b->n;
    }
    return a->color - b->color;
}
 
 
int main()
{
    ll i, j;
    scanf("%lld %lld", &i, &j);
    color_index color_mas[i*j];
    ll color_counter[N + 1] = {0};
    ll k = 0;
    for (ll m = 0; m < i; m++)
    {
        for (ll n = 0; n < j; n++)
        {
            ll col;
            scanf("%lld", &col);
            color_mas[k].color = col;
            color_mas[k].m = m;
            color_mas[k].n = n;
            color_counter[col] += 1;
            k++;
        }
    }
    ll full_counter = 0;
    ll f_color = color_mas[0].color;
    ll temp = 0;
    if (i > 1)
    {
        qsort(color_mas, i*j, sizeof(color_index), comp_m);
        for (ll f = 0; f < i*j; ++f)
        {
            if (f_color != color_mas[f].color) 
            {
                temp = f;
                f_color = color_mas[f].color;
            }
            full_counter += (2*(f - temp) + 1 - color_counter[f_color])*color_mas[f].m;
        }
        if (j > 1)
        {
            qsort(color_mas, i*j, sizeof(color_index), comp_n);
            f_color = color_mas[0].color;
            temp = 0;
            for (ll f = 0; f < i*j; ++f)
            {
                if (f_color != color_mas[f].color) 
                {
                    temp = f;
                    f_color = color_mas[f].color;
                }
                full_counter += (2*(f - temp) + 1 - color_counter[f_color])*color_mas[f].n;
            }
        }
    }else if (j > 1)
    {
        qsort(color_mas, i*j, sizeof(color_index), comp_n);
        f_color = color_mas[0].color;
        temp = 0;
        for (ll f = 0; f < i*j; ++f)
        {
            if (f_color != color_mas[f].color) 
            {
                temp = f;
                f_color = color_mas[f].color;
            }
            full_counter += (2*(f - temp) + 1 - color_counter[f_color])*color_mas[f].n;
        }
    }
    printf("%lld", full_counter);
    return 0;
}
```
## 11. Выводы

Была написана программа на языке на Си, выполняющая указанное вариантом действие над квадратной матрицей. В результате выполнения работы, были приобретены навыки для работы с квадратными матрицами и обработки их элементов.

Недочёты при выполнении задания могут быть устранены следующим образом: —
