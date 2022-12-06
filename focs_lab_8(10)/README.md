# Отчёт по лабораторной работе №10 по курсу "Фундаментальная информатика"

<b>Студент группы:</b> <ins>М80-108Б-22 Ибрагимов Далгат Магомедалиевич, № по списку 9</ins> 

<b>Контакты e-mail:</b> <ins>doly2004e@yandex.ru</ins>

<b>Работа выполнена:</b> «20» <ins>ноября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> 5 (отлично) <ins></ins>

<b>Отчет сдан</b> «26» <ins></ins> Ноября <ins>2022</ins> 2022 г., <b>итоговая оценка</b> 5 (отлично)  <ins></ins>

<b>Подпись преподавателя:</b> ________________


# 1. Тема
Отладчик системы программирования ОС UNIX
## 2. Цель работы
Научиться отлаживать простейшие программы, написанные на языке Си.
## 3. Задание (вариант № -)
Написать простейшую программу на языке и отладить её.
## 4. Оборудование
<b>Процессор:</b> AMD Ryzen 5 5600H (12) @ 3.600GHz<br/>
<b>ОП:</b> 32GiB 3200 MHz LPDDR4<br/>
<b>Текстовый редактор:</b> Visual Studio Code версия 1.73.0 <br/>
## 5. Программное обеспечение:
<b>Операционная система семейства:</b> Microsoft Windows 11 Pro <br/>
<b>Компилятор:</b> GNU Compiler Collection <br/>
<b>Текстовый редактор:</b> Visual Studio Code версия 1.73.0 <br/>
## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)

| gdb |  Описание команды |
| ------ | ------ |
| help [раздел] | Подсказка по разделу отладчика. Без параметров выводит список разделов. |
| list [имя фукнции/файла:] [номер строки] | Распечатка текста функции/процедуры/файла или всей программы, начиная с указанной строки. По умолчанию распечатываются 10 строк программы. Распечатываемый файл становится текущим файлом исходного текста отлаживаемой программы. |
| break [номер строки/имя функции] | Задание точки остановки на строке/функции текущего исходного файла программы. |
| run [параметры] | Запуск программы на выполнение. Могут указываться необязательные параметры командной строки и операции перенаправления ввода-вывода. gdb запоминает параметры и подставляет их для дальнейших вызовах run. |
| set args [параметры] | Предварительная установка параметров командной строки. |
| show args | Вывод параметров командной строки. |
| print [выражение] | Печать значения выражения, которое может включать и переменные, и вызовы функций программы. |
| next [n] | Выполнение очередной строки программы при пошаговой трассировке (процедуры и функции не трассируются, а выполняются за один такт). Необязательный параметр n указывает число строк программы для выполнения. По умолчанию n = 1. |
| step [n] | step [n]	Выполнение очередной строки программы (с трассировкой процедур и функций). Перед выполнением next/step программа должна быть запущена командой run. |
| set var [имя] = [выражение] | Присваивание значения переменной. |
| pytype [имя переменной] | Выводит тип переменной. |
| backtrace/bt | Распечатка содержимого стека вызовов. |
| continue | Продолжение выполнения программы после остановки. |
| quit | Выход из отладчика. |

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
```
/* Лабраторная работа 9.
  Студент гр.08-108 Далгат Ибрагимов
*/
#include <stdio.h>  
#include <stdlib.h> 
#include <stdbool.h> 
 
#define MAX(a,b) ((a > b))? (a) : (b) 
#define MIN(a,b) ((a < b))? (a) : (b) 

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
<b>Подпись преподавателя:</b> ________________
## 8. Распечатка протокола 
```

PS C:\Users\lock_R\Documents\cc> gdb a.exe
GNU gdb (GDB) 12.1
Copyright (C) 2022 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-w64-mingw32".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<https://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.
--Type <RET> for more, q to quit, c to continue without paging--

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from a.exe...
(gdb) b 44 if k%2==0
Breakpoint 1 at 0x14000184c: file lab9.c, line 44.
(gdb) run
Starting program: C:\Users\lock_R\Documents\cc\a.exe 
[New Thread 4520.0x2d9c]

Thread 1 hit Breakpoint 1, main () at lab9.c:44
44              printf("%u) %d %d %d \n", k, a.i, a.j, a.l);
(gdb) print k
$1 = 0
(gdb) display k  
1: k = 0
(gdb) display a.i
2: a.i = 10
(gdb) continue 
Continuing.
0) 10 20 -1
1) 12 10 1

Thread 1 hit Breakpoint 1, main () at lab9.c:44
44              printf("%u) %d %d %d \n", k, a.i, a.j, a.l);
1: k = 2
2: a.i = 3
(gdb) continue 
Continuing.
2) 3 7 3
3) 6 -1 13

Thread 1 hit Breakpoint 1, main () at lab9.c:44
44              printf("%u) %d %d %d \n", k, a.i, a.j, a.l);
1: k = 4
2: a.i = 18
(gdb) continue 
Continuing.
4) 18 0 10
5) 2 -1 8

Thread 1 hit Breakpoint 1, main () at lab9.c:44
44              printf("%u) %d %d %d \n", k, a.i, a.j, a.l);
1: k = 6
2: a.i = 8
(gdb) continue 
Continuing.
6) 8 15 11
7) 6 15 14

Thread 1 hit Breakpoint 1, main () at lab9.c:44
44              printf("%u) %d %d %d \n", k, a.i, a.j, a.l);
1: k = 8
2: a.i = 15
(gdb) quit
A debugging session is active.

        Inferior 1 [process 4520] will be killed.

Quit anyway? (y or n) y

```

## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 20.11.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
Защита была проведена без замечаний.
## 11. Выводы
Была написана и отлажена простейшая программа на языке на Си. В результате выполнения работы, были приобретены навыки, которые будут полезны для выполнения других лабораторных работ.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________

