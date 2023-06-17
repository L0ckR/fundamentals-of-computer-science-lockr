# Отчёт по лабораторной работе №13 по курсу "Фундаментальная информатика"

<b>Студент группы:</b> <ins>М80-108Б-22 Ибрагимов Далгат Магомедалиевич, № по списку 9</ins> 

<b>Контакты e-mail:</b> <ins>doly2004e@yandex.ru</ins>

<b>Работа выполнена:</b> <ins> «26» <ins>ноября</ins> <ins>2022</ins> г.

<b>Преподаватель:</b> <ins>асп. каф. 806 Сахарин Никита Александрович</ins>

<b>Входной контроль знаний с оценкой:</b> <ins>5 (отлично)</ins>

<b>Отчет сдан</b> <ins>«3» Декабря 2022</ins> г., <b>итоговая оценка</b> <ins>5 (отлично)</ins>

<b>Подпись преподавателя:</b> ________________


## 1. Тема
Множества.
## 2. Цель работы
В соответствии с вариантом задания составить программу проверки характеристик введённых последовательностей слов и печати развёрнутого ответа.
## 3. Задание (вариант № 9)
Есть ли соседние слова, состоящие из одного и того же набора букв?
## 4. Оборудование
<b>Процессор:</b> AMD Ryzen 5 5600H (12) @ 3.600GHz<br/>
<b>ОП:</b> 32GiB 3200 MHz LPDDR4<br/>
<b>Текстовый редактор:</b> Visual Studio Code версия 1.73.0 <br/>

## 5. Программное обеспечение:
<b>Операционная система семейства:</b> Microsoft Windows 11 Pro <br/>
<b>Компилятор:</b> GNU Compiler Collection <br/>
<b>Текстовый редактор:</b> Visual Studio Code версия 1.73.0 <br/>

## 6. Идея, метод, алгоритм решения задачи (в формах: словесной, псевдокода, графической [блок-схема, диаграмма, рисунок, таблица] или формальные спецификации с пред- и постусловиями)
1. Записывааем set букв использованных в каждом слове;
2. Сравниваем с предыдущим, если есть хоть один одинаковый набор букв, то меняем значение флага;
3. Выводим Да или Нет в зависимости от значения флага;

## 7. Сценарий выполнения работы [план работы, первоначальный текст программы в черновике (можно на отдельном листе) и тесты либо соображения по тестированию]. 
```#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#define UINT_WIDTH (32)
#define MAX_ALPHABET ((UINT_MAX >> (UINT_WIDTH - (26U))) + 1)

typedef enum
{
    OUTSIDE,
    INSIDE
} Conditions;

typedef unsigned int uint;

uint char_to_set(char c)
{
    c = tolower(c);
    if(c < 'a' || c > 'z')
    {
        return 0;
    }else{
        return 1u<<(c-'a');
    }
}

void check_neighboured(){
    bool flag = false;
    uint set_2;
    uint set_1 = MAX_ALPHABET;
    Conditions condition = OUTSIDE;
    for (char ch = getchar(); ch != EOF; ch = getchar())
    {
        switch(condition)
        {
            case OUTSIDE:
                if (isalpha(ch) || ch == ',')
                {
                    putchar(ch);
                    set_2 = char_to_set(ch);
                    condition = INSIDE;
                    continue;
                } else
                {
                    putchar(ch);
                    continue;
                }
            case INSIDE:
                if (isalpha(ch) || ch == ',')
                {
                    putchar(ch);
                    set_2 = set_2 | char_to_set(ch);
                    continue;
                } else if(isspace(ch))
                {
                    putchar(ch);
                    if ((set_1 == set_2)&&(set_1 != MAX_ALPHABET)){
                        flag = true;
                    }
                    set_1 = set_2;
                    condition = OUTSIDE;
                    continue;
                } else
                {
                    putchar(ch);
                    continue;
                }    
        }
    }
    if ((set_1 == set_2)&&(set_1 != MAX_ALPHABET)){
            flag = true;
    }
    if (flag)
    {
        printf("\n\n\nYEEEES");
    } else{
        printf("\n\n\nNO");
    }
}


int main()
{
    check_neighboured();
    return 0;
}
```

Пункты 1-7 отчета составляются сторого до начала лабораторной работы.
Допущен к выполнению работы.  
<b>Подпись преподавателя:</b> ________________
## 8. Распечатка протокола 
```
PS C:\Users\lock_R\Documents\cc> Get-Content t.txt | .\a.exe            

d
a
b
c
d s f g h



NO
PS C:\Users\lock_R\Documents\cc> Get-Content t.txt | .\a.exe
asdfg asdfggggggggg asddddfg gfdsaasdf
asdfg asdfgasdfg asdfgasdfg



YEEEES
PS C:\Users\lock_R\Documents\cc> Get-Content t.txt | .\a.exe
asdfg asdfggggggggg o
o
p
o
o



YEEEES

```
## 9. Дневник отладки должен содержать дату и время сеансов отладки и основные события (ошибки в сценарии и программе, нестандартные ситуации) и краткие комментарии к ним. В дневнике отладки приводятся сведения об использовании других ЭВМ, существенном участии преподавателя и других лиц в написании и отладке программы.

| № |  Лаб. или дом. | Дата | Время | Событие | Действие по исправлению | Примечание |
| ------ | ------ | ------ | ------ | ------ | ------ | ------ |
| 1 | дом. | 26.11.22 | 13:00 | Выполнение лабораторной работы | - | - |
## 10. Замечания автора по существу работы — Написание команд для отработки навыков работы в ОС UNIX.
[Защита 1202](https://codeforces.com/contest/1202/submission/183731066)
## 11. Выводы

Была написана программа на языке на Си, выполняющая указанное вариантом действие над значениями в целом типе данных. В результате выполнения работы, были приобретены навыки для работы с числами в целом типе данных.

Недочёты при выполнении задания могут быть устранены следующим образом: —

<b>Подпись студента:</b> ____________________
