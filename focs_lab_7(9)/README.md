# Отчёт по лабораторной работе №9 по курсу “Фундаментальная информатика”
<b>Студент группы:</b> <ins>М80-108Б-22 Ибрагимов Далгат Магомедалиевич, № по списку 9</ins> 

<b>Контакты e-mail:</b> <ins>doly2004e@yandex.ru</ins>

<b>Работа выполнена:</b> «10» <ins>ноября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> 5 (отлично) <ins> </ins>

<b>Отчет сдан</b> «19» <ins>ноября</ins> 2022 <ins>2022</ins>  г., <b>итоговая оценка</b> 5 (отлично)<ins></ins>

<b>Подпись преподавателя:</b> ________________




## 1. Тема
Програмирование на языке С
## 2. Цель работы
Составить и отладить простейшую программу на языке C итеративного характера.
## 3. Задание (вариант № 4)
Кольцо, ограниченное двумя окружностями с центром в точке (10. 10), радиус внутренней окружности равен 5, а радиус внешней равен 10
## 4. Оборудование
<b>Процессор:</b> AMD Ryzen 5 5600H (12) @ 3.600GHz<br/>
<b>ОП:</b> 32GiB 3200 MHz LPDDR4<br/>
<b>SSD:</b> 512 GiB<br/>
<b>Адрес:</b> <br/>
<b>Монитор:</b> 27-дюймовый (1920 х 1080)<br/>
<b>Графика:</b>AMD Radeon™ RX 6600M 2177 MHz 8GiB GDDR6<br/>

## 5. Программное обеспечение:
<b>Операционная система семейства:</b> Microsoft Windows 11 Pro <br/>
<b>Компилятор:</b> GNU Compiler Collection <br/>
<b>Текстовый редактор:</b> Visual Studio Code версия 1.73.0 <br/>

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
• Устнаовить и настроить VSCode
• Разобраться с поставленной задачей
• Найти решение с помощью программы на языке С
•	Скомпилировать программу
•	Запустить программу

```/* Лабраторная работа 9.
  Студент гр.08-108 Далгат Ибрагимов
*/
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h> 
 
int MAX(int a, int b){
    if (a > b){
        return a;
    }else{
        return b;
    }
}

int MIN(int a, int b){
    if (a < b){
        return a;
    }else{
        return b;
    }
}

int sign(int a) 
{ 
    if (a > 0){ 
        return 1; 
    } 
 
    if (a == 0){ 
        return 0; 
    } 
 
    return -1; 
} 
typedef struct {
    int i, j, l;
} State;
 
State state_for_ex_k(State a, int ex_k){
    State res = {abs(abs(MAX(a.i*(ex_k+5),(a.j*(ex_k+6)))) - abs(MIN((a.j*(ex_k+7)), (a.l*(ex_k+8))))) % 20, (abs((3 - sign(a.i - a.j))*abs(MIN(MIN((a.i*a.l+5),(a.j*a.l-3)),(a.i*a.j+6)))))%25 - 7, abs(a.i)%10 + abs(a.j)%10 + abs(a.l)%10};
    return res;
}

bool is_in_func(int k, State a){
    if ((a.i >= 5 && a.i <= 15) && (a.j <= -5 && a.j >= -15)){ 
       return true;
    }
    return false;
}

int main() 
{ 
    bool flag = true;
    State a = {10, 20, -1};
    for (int k = 0; k <= 50; k++){ 
        printf("%u) %d %d %d \n", k, a.i, a.j, a.l);
        if (is_in_func(k, a)){ 
            printf("got it in %d = count of attempts, %d - i coord, %d - j coord, %d - l variable \n", k, a.i, a.j, a.l); 
            flag = false;
            break; 
        } 
        a = state_for_ex_k(a, k);
    }
    if (flag){
        printf("missed. %d - i coord, %d - j coord, %d - l variable \n", a.i, a.j, a.l);
    }
}
```
Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
Подпись преподавателя _____________________
## 8. Распечатка протокола 
```
PS C:\Users\lock_R\Documents\cc> gcc lab9.c -pedantic -Wall 
PS C:\Users\lock_R\Documents\cc> .\a.exe
0, 10, 20, -1
1, 12, 10, 1
2, 3, 7, 3
3, 6, -1, 13
4, 18, 0, 10
5, 2, -1, 8
6, 8, 15, 11
7, 6, 15, 14
8, 15, -1, 15
9, 0, 4, 11
10, 4, 13, 5
11, 18, -7, 12
12, 2, 8, 17
13, 8, -1, 17
14, 4, 8, 16
15, 8, -6, 18
got it in 15 = count of attempts, 8 - x coord, 15 - y coord, 22 -l 
```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 10.10.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.

Проверить попадание точки в фигуру(правильная шестиугольная звезда), заданную двумя параметрами.
```#include <stdio.h>
#include <stdbool.h>
#include <math.h>

typedef unsigned int uint;

struct Point {
    double x, y;
};

struct Vector {
    double lx, ly;
};

typedef struct {
    double k, b;
} Line;

struct Triangle {
    struct Point a1, a2, a3; // a2a3 parallel to x-axis
};


struct Point plus(struct Point p, struct Vector v) {
    struct Point res = {p.x + v.lx, p.y + v.ly};
    return res;
}

struct Vector reverse_x_vector(struct Vector v){
    struct Vector res = {v.lx*(-1), v.ly};
    return res;
}

struct Vector reverse_y_vector(struct Vector v){
    struct Vector res = {v.lx, v.ly*(-1)};
    return res;
}


bool upper(Line ln, struct Point p){
    return (p.y >= p.x * ln.k + ln.b ? true : false);
}

bool below(Line ln, struct Point p){
    return (p.y <= p.x * ln.k + ln.b ? true : false);
}

struct Triangle triangle1( struct Point o, uint length) {
    struct Triangle triangle;
    struct Vector v1 = {0, length};
    struct Vector v2 = {length*(pow(3, 0.5)*0.5), 0.5*length};
    v2 = reverse_y_vector(v2);
    triangle.a1 = plus(o, v1);
    triangle.a2 = plus(o, reverse_x_vector(v2));
    triangle.a3 = plus(o, v2);
    return triangle;
}

struct Triangle triangle2( struct Point o, uint length) {
    struct Triangle triangle;
    struct Vector v1 = {0, length};
    v1 = reverse_y_vector(v1);
    struct Vector v2 = {length*(pow(3, 0.5)*0.5), 0.5*length};
    triangle.a1 = plus(o, v1);
    triangle.a2 = plus(o, reverse_x_vector(v2));
    triangle.a3 = plus(o, v2);
    
    return triangle;
}


bool check_in_triangle1(struct Point p, struct Triangle Triangle){
    struct Point A = Triangle.a1;
    struct Point B = Triangle.a2;
    struct Point C = Triangle.a3;

    Line AB = {.k = (A.y - B.y) / (A.x - B.x), .b = B.y - AB.k * B.x};
    Line BC = {.k = (B.y - C.y) / (B.x - C.x), .b = C.y - BC.k * C.x};
    Line AC = {.k = (C.y - A.y) / (C.x - A.x), .b = A.y - AC.k * A.x};

    return(below(AB, p) == true && below(AC, p) == true && upper(BC, p) == true ? true : false);
}

bool check_in_triangle2(struct Point p, struct Triangle Triangle){
    struct Point A = Triangle.a1;
    struct Point B = Triangle.a2;
    struct Point C = Triangle.a3;

    Line AB = {.k = (A.y - B.y) / (A.x - B.x), .b = B.y - AB.k * B.x};
    Line BC = {.k = (B.y - C.y) / (B.x - C.x), .b = C.y - BC.k * C.x};
    Line AC = {.k = (C.y - A.y) / (C.x - A.x), .b = A.y - AC.k * A.x};

    return(upper(AB, p) == true && upper(AC, p) == true && below(BC, p) == true ? true : false);
}



int main()
{
    double x, y;
    uint l;
    printf("enter x y of center\n");
    scanf("%lf %lf", &x, &y);
    struct Point o = {x, y};
    printf("enter length\n");
    scanf("%u", &l);
    printf("enter x y of POINT\n");
    scanf("%lf %lf", &x, &y);
    struct Point POINT = {x, y};
    if (check_in_triangle1(POINT, triangle1(o, l))||check_in_triangle2(POINT, triangle2(o,l))){
        printf("YES");
    }
    return 0;
}
```

## 11. Выводы
Были изучены основы работы с компилятором gcc: установка, компиляция, выполнение программ. Было выяснено, что VScode — наиболее подходящий текстовый редактор для данных задач.

Недочёты при выполнении задания могут быть устранены следующим образом: —

Подпись студента _________________


