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