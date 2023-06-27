# Отчёт по курсовой работе №6 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Ибрагимов Далгат Магомедалиевич, № по списку 8</ins>

<b>Контакты e-mail:</b> <ins>doly2004e@yandex.ru<ins>

<b>Работа выполнена:</b> «25» <ins>мая</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «27» <ins>июня</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins>3</ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема
Обработка последовательной файловой структуры на языке Си

## 2. Цель работы
Разработать последовательную структуру данных для представления простейшей базы данных на файлах в СП Си в соответствии с заданным вариантом.

## 3. Задание
Составить программу генерации внешнего нетекстового файла заданной структуры, содержащего представительный набор записей. Распечатать содержимое сгенерированного файла в виде таблицы и выполнить над ним заданное действие и распечатать результат.

Действие по выборке данных из файла оформить в виде отдельной программы с параметрами запроса.

Cтруктуры данных и константы, совместно используемые программами, следует вынести в отдельный заголовочный файл.

В процессе отладки и тестирования рекомендуется использовать команды обработки текстовых файлов ОС UNIX и переадресацию ввода-вывода. Сгенерированные и отформатированные тестовые данные необходимо заранее поместить в текстовые файлы и распечатывать при протоколировании. Рекомендуется подобрать реальные или правдоподобные тестовые данные. Число наборов тестовых данных должно быть не менее трёх. Имя файла с бинарными данными является обязательным параметром второй программы.

Действие:
Найти людей с оборудованием WINTEL

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
В person.h хранится структура строки таблицы - информация о составляющих пк людей dump - конвертирует текстовый file1 в бинарный file2 main -f - печать содержимой в бинарном файле file таблицы main -f -p - выполнение задания

## 7. Сценарий выполнения работы
persons.txt
```
Anciborko;2;2;4;1;4;0;2;1024;1;0
Ibragimov;8;1;8;1;8;1;1;2048;2;5
Gurov;4;0;4;2;1;0;3;1024;3;1
Ivanov;2;3;16;1;16;0;8;4048;4;4
Khalimov;1;0;1;2;1;0;1;1;5;0
Ramaldanov;2;2;4;1;4;0;2;1024;6;0
Formalev;1;3;8;1;2;1;1;2048;7;2
Goryunov;4;0;4;2;1;0;3;1024;8;1
Zinoviev;2;3;16;1;16;0;8;4048;9;4
Bylkova;1;0;1;2;1;0;1;1;10;1
Nemkova;2;2;4;1;4;0;2;1024;11;0
Starostina;1;3;8;1;2;1;1;2048;12;2
Dozhd;4;0;4;2;1;0;3;1024;13;3
Klimov;2;3;16;1;16;0;8;4048;14;4
Khaev;1;0;1;2;1;0;1;1;15;4
Kalashnikov;2;2;4;1;4;0;2;1024;16;0
Zaycev;1;3;8;1;2;1;1;2048;17;2
Blinova;4;0;4;2;1;0;3;1024;18;1
Musaelyan;2;3;16;1;16;0;8;4048;19;4
Erofeeva;1;0;1;2;1;0;1;1;20;4
```
person.h
```
#ifndef PERSON_H
#define PERSON_H

#define LINE_SIZE (40U)

#include <stdio.h>
#include <locale.h>
#include <string.h>
#include "stdbool.h"
typedef unsigned int uint;

typedef enum {
    INTEL,
    AMD,
    ARM,
    ELBRUS
} CpuType;

typedef enum {
    EMBEDDED,
    EXTERNAL,
    VIDEO_BUS
} VideoCardType;

typedef enum {
    SAS,
    SATA
} DiskType;

typedef enum {
    LINUX,
    MAC_OS,
    WINDOWS_7,
    WINDOWS_8,
    WINDOWS_10,
    WINDOWS_11
} OperatingSystem;

typedef struct {
    char surname[LINE_SIZE]; //40
    uint cpuCount;
    CpuType cpuType;
    uint memorySize; // Gb
    VideoCardType videoCardType;
    uint videoMemorySize; // Gb
    DiskType diskType;
    uint diskCount;
    uint diskSize; // Gb
    uint externalDevicesCount;
    OperatingSystem operatingSystem;
} Person;

#endif //PERSON_H
```

person_dump.c
```
#include "person.h"

// delimiter - ;
//Anciborko;2;2;4;1;4;0;2;1024;1;0
bool readBase (Person *person, FILE *file) {
        int res = fscanf(file, "%[^;];%u;%u;%u;%u;%u;%u;%u;%u;%u;%u\n",
                           person->surname,
                           &person->cpuCount,
                           &person->cpuType,
                           &person->memorySize,
                           &person->videoCardType,
                                                   &person->videoMemorySize,
                           &person->diskType,
                           &person->diskCount,
                           &person->diskSize,
                           &person->externalDevicesCount,
                           &person->operatingSystem);
        if (res == 11) {
                return true;
        }
        return false;
}

int main(int argc, char* argv[]) {
        setlocale(LC_ALL, "Rus");

        if (argc != 3) {
                printf("Неверный ввод.\n");
                return 1;
        }
        Person person;
        memset(&person, '0', sizeof(Person));
        FILE *base = fopen(argv[1], "r");
        if (!base) {
                perror("Не удается открыть файл1\n");
                return 2;
        }
        FILE *bin = fopen(argv[2], "w");
        if (!bin) {
                perror("Не удается открыть файл\n");
                fclose(base);
                return 2;
        }

        while (readBase(&person, base)) {
                fwrite(&person, sizeof(Person), 1, bin);
        }
        fclose(bin);
        fclose(base);
        return 0;
}
```
main.c
```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <locale.h>
#include <stdbool.h>

#include "person.h"


char * const cpu_type_str[] = { 
    [INTEL] = "  INTEL    ",
    [AMD] = "  AMD      ",
    [ARM] = "  ARM      ",
    [ELBRUS] = "  ELBRUS   ",
    };

char * const vid_type_str[] = { 
    [EMBEDDED] = "   EMBEDDED  ",
    [EXTERNAL] = "   EXTERNAL  ",
    [VIDEO_BUS] = "   VIDEO_BUS "
};

char * const disk_type_str[] = { 
    [SAS] = "     SAS     ",
    [SATA] = "     SATA    "
};

char * const os_type_str[] = { 
    [LINUX] = " LINUX     ",
    [MAC_OS] = " MAC_OS    ",
    [WINDOWS_7] = " WINDOWS_7 ",
    [WINDOWS_8] = " WINDOWS_8   ",
    [WINDOWS_10]= " WINDOWS_10",
    [WINDOWS_11] = " WINDOWS_11"
};


char *stringComplement(char *str, int n) {
    int len = strlen(str);
    for (int ptr = len; ptr < n; ptr++) {
        str[ptr] = ' ';
        str[ptr + 1] = '\0';
    }
    return str;
}

void printBlank(int n) {
    for (int i = 0;i < n;i++) putchar(' ');
}

char* intToString(int val, int base) {
        static char buf[32] = {0};
    if (val == 0) {
        buf[0] = '0';
        buf[1] = '\0';
        return buf;
    }
        int i = 30;
    buf[31] = '\0';
        for(; val && i ; --i, val /= base)
                buf[i] = "0123456789abcdef"[val % base];
        return &buf[i+1];
}

// 20:8:3:11:8:7:7:7:15
const char * HEADER = "|Фамилия                                |Кол-во ядер| Тип проц  | Размер ОЗУ |Тип вид.карты| Видеопамять |   Тип ПЗУ   | Кол-во ПЗУ | Размер ПЗУ |Кол-во периф.|    ОС     |\n";
const char * DELIM =  "|---------------------------------------|-----------|-----------|------------|-------------|-------------|-------------|------------|------------|-------------|-----------|\n";

void printUsage() {
    printf("main <filename> -f - печать таблицы\nmain <filename> -p - вычисление функции по заданию.\n");
}

void personPrint(const Person *person) {
    assert(person != NULL);

    putchar('|');
    char surname[LINE_SIZE];
    strcpy(surname, person->surname);
    printf("%s", stringComplement(surname, LINE_SIZE-1));
    putchar('|');

    char *cpuCount = intToString(person->cpuCount, 10);
    printf("%s", stringComplement(cpuCount, 11));
    putchar('|'); //

    char * cpuType = cpu_type_str[person->cpuType];
    printf("%s", cpuType);
    putchar('|'); //

    char *memorySize = intToString(person->memorySize, 10);
    printf("%sGb", stringComplement(memorySize, 10));
    putchar('|'); //

    char * videoCardType = vid_type_str[person->videoCardType];
    printf("%s", videoCardType);
    putchar('|'); //

    char *videoMemorySize = intToString(person->videoMemorySize, 10);
    printf("%sGb", stringComplement(videoMemorySize, 11));
    putchar('|'); //

    char * diskType = disk_type_str[person->diskType];
    printf("%s", diskType);
    putchar('|'); //

    char *diskCount = intToString(person->diskCount, 10);
    printf("%s", stringComplement(diskCount, 12));
    putchar('|'); //

    char *diskSize = intToString(person->diskSize, 10);
    printf("%sGb", stringComplement(diskSize, 10));
    putchar('|'); //

    char *externalDevicesCount = intToString(person->externalDevicesCount, 10);
    printf("%s", stringComplement(externalDevicesCount, 13));
    putchar('|'); //

    char * operatingSystem = os_type_str[person->operatingSystem];
    printf("%s", operatingSystem);
    putchar('|');

    putchar('\n');
}

void printTable(FILE *file) {
    Person person;
    printf("%s", HEADER);
    printf("%s", DELIM);
    while (fread (&person, sizeof(Person), 1, file) == 1) {
        personPrint(&person);
    }
    printf("%s", DELIM);
}

void func(FILE *file) {
    Person person;
    printf("%s", HEADER);
    printf("%s", DELIM);
    while (fread (&person, sizeof(Person), 1, file) == 1) {
        if (person.cpuType == 0 && (person.operatingSystem >= 2 && person.operatingSystem <= 5 ))
            personPrint(&person);
    }
    printf("%s", DELIM);
}

int main(int argc, char **argv) {
    setlocale(LC_ALL, "Rus");

    if (argc == 1) {
        printUsage();
        return 0;
    }
    int mode = 0; // 0 - not defined; 1 - file print; 2 - function; 3 - undetermined
    bool wasFilename = false;
    char filename[40];
    for (int i = 1;i < argc;i++) {
        if (strcmp(argv[i], "-f") == 0) {
            if (mode == 0)
                mode = 1;
            else 
                mode = 3;
        } else if (strcmp(argv[i], "-p") == 0) {
            if (mode == 0)
                mode = 2;
            else 
                mode = 3;
        } else {
            if (!wasFilename && mode == 0){
                wasFilename = true;
                strcpy(filename, argv[i]);
            }else{
                mode = 3;
            }
        }
    }
    if (wasFilename && mode == 1) {
        if (fopen(filename, "r")){
            FILE *bin = 
            fopen(filename, "r");
            printTable(bin);
            fclose(bin);
        }
        else{
            printf("Ошибка ввода.\n");
            return 0;
        }
    } else if (wasFilename && mode == 2) {
        if (fopen(filename, "r")){
            FILE *bin = fopen(filename, "r");
            func(bin);
            fclose(bin);
        }
        else{

            printf("Ошибка ввода.\n");
            return 0;
        }
    } else {
        printUsage();
    }

    return 0;
}
```
Makefile
```
CC=gcc
LD=gcc
RM=rm -fr
CCFLAGS=-Wall -Werror -Wextra -Wfatal-errors -Wpedantic -pedantic-errors -g
LDFLAGS=
EXECUTABLE=main person_dump

main: src/main.o person_dump
        $(LD) $(LDFLAGS) src/main.o -o main

person_dump: src/person_dump.o
        $(LD) $(LDFLAGS) src/person_dump.o -o person_dump

src/person_dump.o: src/person_dump.c
        $(CC) $(CCFLAGS) -c src/person_dump.c -o src/person_dump.o

src/main.o: src/main.c
        $(CC) $(CCFLAGS) -c src/main.c -o src/main.o

clean:
        $(RM) src/*.o $(EXECUTABLE)
```

## 8. Распечатка протокола

```
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_kp_6$ ./person_dump
Неверный ввод.
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_kp_6$ ./person_dump ./data/persons.txt persons_bin
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_kp_6$ ./main
main <filename> -f - печать таблицы
main <filename> -p - вычисление функции по заданию.
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_kp_6$ ./main persons_bin -f
|Фамилия                                |Кол-во ядер| Тип проц  | Размер ОЗУ |Тип вид.карты| Видеопамять |   Тип ПЗУ   | Кол-во ПЗУ | Размер ПЗУ |Кол-во периф.|    ОС     |
|---------------------------------------|-----------|-----------|------------|-------------|-------------|-------------|------------|------------|-------------|-----------|
|Anciborko                              |2          |  ARM      |4         Gb|   EXTERNAL  |4          Gb|     SAS     |2           |1024      Gb|1            | LINUX     |
|Ibragimov                              |8          |  AMD      |8         Gb|   EXTERNAL  |2          Gb|     SATA    |1           |2048      Gb|2            | WINDOWS_11|
|Gurov                                  |4          |  INTEL    |4         Gb|   VIDEO_BUS |1          Gb|     SAS     |3           |1024      Gb|3            | MAC_OS    |
|Ivanov                                 |2          |  ELBRUS   |16        Gb|   EXTERNAL  |16         Gb|     SAS     |8           |4048      Gb|4            | WINDOWS_10|
|Khalimov                               |1          |  INTEL    |1         Gb|   VIDEO_BUS |1          Gb|     SAS     |1           |1         Gb|5            | LINUX     |
|Ramaldanov                             |2          |  ARM      |4         Gb|   EXTERNAL  |4          Gb|     SAS     |2           |1024      Gb|6            | LINUX     |
|Formalev                               |1          |  ELBRUS   |8         Gb|   EXTERNAL  |2          Gb|     SATA    |1           |2048      Gb|7            | WINDOWS_7 |
|Goryunov                               |4          |  INTEL    |4         Gb|   VIDEO_BUS |1          Gb|     SAS     |3           |1024      Gb|8            | MAC_OS    |
|Zinoviev                               |2          |  ELBRUS   |16        Gb|   EXTERNAL  |16         Gb|     SAS     |8           |4048      Gb|9            | WINDOWS_10|
|Bylkova                                |1          |  INTEL    |1         Gb|   VIDEO_BUS |1          Gb|     SAS     |1           |1         Gb|10           | LINUX     |
|Nemkova                                |2          |  ARM      |4         Gb|   EXTERNAL  |4          Gb|     SAS     |2           |1024      Gb|11           | LINUX     |
|Starostina                             |1          |  ELBRUS   |8         Gb|   EXTERNAL  |2          Gb|     SATA    |1           |2048      Gb|12           | WINDOWS_7 |
|Dozhd                                  |4          |  INTEL    |4         Gb|   VIDEO_BUS |1          Gb|     SAS     |3           |1024      Gb|13           | MAC_OS    |
|Klimov                                 |2          |  ELBRUS   |16        Gb|   EXTERNAL  |16         Gb|     SAS     |8           |4048      Gb|14           | WINDOWS_10|
|Khaev                                  |1          |  INTEL    |1         Gb|   VIDEO_BUS |1          Gb|     SAS     |1           |1         Gb|15           | LINUX     |
|Kalashnikov                            |2          |  ARM      |4         Gb|   EXTERNAL  |4          Gb|     SAS     |2           |1024      Gb|16           | LINUX     |
|Zaycev                                 |1          |  ELBRUS   |8         Gb|   EXTERNAL  |2          Gb|     SATA    |1           |2048      Gb|17           | WINDOWS_7 |
|Blinova                                |4          |  INTEL    |4         Gb|   VIDEO_BUS |1          Gb|     SAS     |3           |1024      Gb|18           | MAC_OS    |
|Musaelyan                              |2          |  ELBRUS   |16        Gb|   EXTERNAL  |16         Gb|     SAS     |8           |4048      Gb|19           | WINDOWS_10|
|Erofeeva                               |1          |  INTEL    |1         Gb|   VIDEO_BUS |1          Gb|     SAS     |1           |1         Gb|20           | LINUX     |
|---------------------------------------|-----------|-----------|------------|-------------|-------------|-------------|------------|------------|-------------|-----------|
lockr@lockR:~/projects/labs/fundamentals-of-computer-science-lockr/focs_kp_6$ ./main persons_bin -p
|Фамилия                                |Кол-во ядер| Тип проц  | Размер ОЗУ |Тип вид.карты| Видеопамять |   Тип ПЗУ   | Кол-во ПЗУ | Размер ПЗУ |Кол-во периф.|    ОС     |
|---------------------------------------|-----------|-----------|------------|-------------|-------------|-------------|------------|------------|-------------|-----------|
|Dozhd                                  |4          |  INTEL    |4         Gb|   VIDEO_BUS |1          Gb|     SAS     |3           |1024      Gb|13           | WINDOWS_8   |
|Khaev                                  |1          |  INTEL    |1         Gb|   VIDEO_BUS |1          Gb|     SAS     |1           |1         Gb|15           | WINDOWS_10|
|Erofeeva                               |1          |  INTEL    |1         Gb|   VIDEO_BUS |1          Gb|     SAS     |1           |1         Gb|20           | WINDOWS_10|
|---------------------------------------|-----------|-----------|------------|-------------|-------------|-------------|------------|------------|-------------|-----------|
```


## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **25.05.23** | **13:00** | **Выполнение лаб. работы** | **-** | **-** |

## 10. Замечания автора по существу работы
Educational Codeforces Round 150 (Rated for Div. 2) \
[Задача 1841A решена на контесте](https://codeforces.com/contest/1841/submission/209455003) \

## 11. Выводы
После выполнения работы, были получены продвинутые навыки обработки строк и бинарных деревьев в языке Си.

<b>Подпись студента:</b> ___________