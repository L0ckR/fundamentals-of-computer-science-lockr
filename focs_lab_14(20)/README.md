# Отчёт по лабораторной работе №20 по курсу «Языки и методы программирования»

<b>Студент группы:</b> <ins>М8О-108Б-22, Немкова Анастасия Романовна, № по списку 13</ins>

<b>Контакты e-mail:</b> <ins>nastya.nemkova.04@mail.ru<ins>

<b>Работа выполнена:</b> «01» <ins>марта</ins> <ins>2023</ins>

<b>Преподаватель:</b> <ins>асп. каф.806 Сахарин Никита Александрович</ins>

<b>Отчет сдан</b> «11» <ins>марта</ins> <ins>2023</ins> г., <b>итоговая оценка</b> <ins></ins>

<b>Подпись преподавателя:</b> ___________

## 1. Тема

Стандартные утилиты UNIX для обработки файлов

## 2. Цель работы

Научиться работать с утилитами, позволяющими производить сложные работы с файлами путем последовательного и конвейерного выполнения этих программ

## 3. Задание

Вариант 4, 20, 24: dd, gzip, bzip2

## 4. Оборудование

Процессор: AMD RYZEN 7 5800H 3.20GHz ОП 16 ГБ

HDD: 952 ГБ

Монитор: 3840x2400

## 5. Программное обеспечение

Операционная система семейства: Linux Ubuntu, версия 22.04.1 LTS

Интерпретатор команд: bash, версия 5.0.17(1)

Система программирования: -

Редактор текстов: emacs

Утилиты операционной системы: dd, gzip, bzip2, wc, comm, grep, sort, tail, tar, diff, cmp, cut, od, iconv, df, cpp, xargs, paste, ed, tee, head, split, sum

Местонахождение и имена файлов программ и данных на домашнем компьютере: -

## 6. Идея, метод, алгоритм решения задачи

При помощи команд и ключей, приведенных в пункте 7, провести операции над текстовыми файлами и директориями 

## 7. Сценарий выполнения работы

**Команды для обработки файлов**

| _Команда_ | _Флаг_ |_Назначение команды_ |
| --- | --- | --- |
| **``dd``** | Конвертация и копирование файла  |
| --- | ``bs = BYTES`` | Чтение и запись до BYTES байтов за раз |
| --- | ``cbs = BYTES`` | Конвертация до BYTES байтов за раз |
| --- | ``count = N`` | Копировать только N входных блоков|
| --- | ``conv = `` | Преобразование файла в соответствии со списком символов перечисленных через запятую|
| --- | ``ibs = BYTES`` | Считывание до BYTES байтов за раз (по умолчанию 512) |
| --- | ``оbs = BYTES`` | Запись указанного количества байт (BYTES) за раз |
| --- | ``seek = N`` | Пропустить N блоков размером obs перед началом вывода |
| --- | ``skip = N`` | Пропустить перед началом ввода N блоков размером ibs|
| **``gzip``** | Сжатие и распаковка файлов |
| --- | ``-c `` | Запись на стандартный вывод |
| --- | ``-d `` | Распаковка |
| --- | ``-f `` | Принудительное сжатие или распаковка |
| --- | ``-k `` | Сохранение входного файла при сжатии или распаковке |
| --- | ``-l `` | Список содержимого сжатого файла |
| --- | ``-r `` | Рекурсивное перемещение по структуре каталогов|
| --- | ``-v `` | Отобразите имя и процентное сокращение для каждого сжатого или распакованного файла |
| --- | ``-1`` | Указывает на самый быстрый метод сжатия (меньшее сжатие) |
| --- | ``-9`` | Указывает на самый медленный метод сжатия (наилучшее сжатие) |
| **``bzip2``** | Сжатие файлов |
| --- | ``-d `` | Принудительная распаковка |
| --- | ``-z`` | Принудительное сжатие |
| --- | ``-k `` | Сохранение входных файлов при распаковке или сжатии |
| --- | ``-с `` | Сжатие или распаковка до стандартного вывода |
| --- | ``-s `` | Уменьшение использования памяти для сжатия, распаковки или тестирования |
| --- | ``-f `` | Принудительная перезапись входных файлов |
| **``wc``** | ---  |Подсчет количество строк, слов, символов и байтов каждого заданного файла или ввода |
| **``comm``** |  ---  |Сравнение двух отсортированных файлов построчно|
| **``grep``** |  ---  |Поиск строк, соответствующих строке в тексте или содержимому файла|
| **``sort``** |  ---  |Сортировка, объединение или проверка последовательности текстовых файлов |
| **``tail``** | ---  | Вывод последней части файлов |
| **``tar``** | ---  | Архивирование файлов |
| **``diff``** | ---  | Выводит различие между двумя файлами|
| **``cmp``** |  ---  |Побайтовое сравнение двух текстов файлов |
| **``cut``** | ---  | Позволяет вырезать часть строк из указанных файлов или данных по конвейеру |
| **``od``** | ---  | Преобразование содержимого входных данных в различные форматы с восьмеричным форматом по умолчанию|
| **``iconv``** | ---  | Преобразование текста из одной кодировки символов в другую |
| **``df``** | ---  | Отображение информации, связанной с файловыми системами, об общем объеме и доступном пространстве |
| **``cpp``** | ---  | Препроцессор языка C |
| **``xargs``** | ---  | Сборка и выполнение командных строк из стандартного ввода |
| **``paste``** | ---  | Объединение строк файлов по горизонтали|
| **``ed``** | ---  | Запуск текстового редактора ed |
| **``tee``** | ---  | Считывание стандартного ввода и записывание его как в стандартный вывод |
| **``head``** | ---  | Вывод верхнего числа N данных заданного ввода |
| **``split``** | ---  | Разделение больших файлов на файлы меньшего размера |
| **``sum``** | ---  | Поиск контрольной суммы и подсчет блоков в файле|

**8. Распечатка протокола**

```
anastasia@anastasia-VirtualBox:~$ wc
Hello
world
      2       2      12
anastasia@anastasia-VirtualBox:~$ wc test.txt
  7  27 162 test.txt
anastasia@anastasia-VirtualBox:~$ cd dir1
anastasia@anastasia-VirtualBox:~/dir1$ wc *.txt
  29  192 1010 a1.txt
   6   14   60 bam.txt
  23   81  440 llala.txt
  58  287 1510 итого
anastasia@anastasia-VirtualBox:~/dir1$ cd
anastasia@anastasia-VirtualBox:~$ cat file1.txt
Apdfghg
Huret
Myusdtc
Nydct
Yugcgd
anastasia@anastasia-VirtualBox:~$ cat file2.txt
Goudfoihvi
Nhsihciwhv
Pagcgwkcgw
Rfsgsac
Zxcf
anastasia@anastasia-VirtualBox:~$ comm file1.txt file2.txt
Apdfghg
	Goudfoihvi
Huret
Myusdtc
	Nhsihciwhv
Nydct
	Pagcgwkcgw
	Rfsgsac
Yugcgd
	Zxcf
anastasia@anastasia-VirtualBox:~$ comm -1  file1.txt file2.txt
Goudfoihvi
Nhsihciwhv
Pagcgwkcgw
Rfsgsac
Zxcf
anastasia@anastasia-VirtualBox:~$ comm --nocheck-order file1.txt file2.txt
Apdfghg

	Goudfoihvi
Myusdtc
	Nhsihciwhv
Nydct
	Pagcgwkcgw
	Rfsgsac
Yugcgd
Huret
	Zxcf
anastasia@anastasia-VirtualBox:~$ cat test.txt
Cat is a dog
CAt is a desk
cat is a flat
Cat ia you
CAT is we

anastasia@anastasia-VirtualBox:~$ grep -i "Cat" test.txt
Cat is a dog
CAt is a desk
cat is a flat
Cat ia you
CAT is we
anastasia@anastasia-VirtualBox:~$ grep -c "Cat" test.txt
2
anastasia@anastasia-VirtualBox:~$ grep -l "cat" *.txt
test.txt
anastasia@anastasia-VirtualBox:~$ grep -n "CAt" test.txt
2:CAt is a desk
anastasia@anastasia-VirtualBox:~$ grep -v "CAt" test.txt
Cat is a dog
cat is a flat
Cat ia you
CAT is we
anastasia@anastasia-VirtualBox:~$ sort test.txt

Cat ia you
CAt is a desk
Cat is a dog
cat is a flat
CAT is we
anastasia@anastasia-VirtualBox:~$ sort -r test.txt
CAT is we
cat is a flat
Cat is a dog
CAt is a desk
Cat ia you

anastasia@anastasia-VirtualBox:~$ sort -k4  test.txt

Cat ia you
CAT is we
CAt is a desk
Cat is a dog
cat is a flat
anastasia@anastasia-VirtualBox:~$ tail file1.txt
l1
l2
l3
l4
l5
l6
l7
l8
l9
anastasia@anastasia-VirtualBox:~$ tail -n 3 file1.txt
l7
l8
l9
anastasia@anastasia-VirtualBox:~$ tail +3 file1.txt
l3
l4
l5
l6
l7
l8
l9
anastasia@anastasia-VirtualBox:~$ tail -c 32 file1.txt
l1
l2
l3
l4
l5
l6
l7
l8
l9
anastasia@anastasia-VirtualBox:~$ tail -c -6  file1.txt
l8
l9
anastasia@anastasia-VirtualBox:~$ tail -c 8  file1.txt
7
l8
l9
anastasia@anastasia-VirtualBox:~$ cd dir1
anastasia@anastasia-VirtualBox:~/dir1$ tar --totals -cvf archive.tar a1.txt bam.txt llala.txt
a1.txt
bam.txt
llala.txt
Всего записано байт: 20480 (20KiB, 31MiB/s)
anastasia@anastasia-VirtualBox:~/dir1$ ls
a1.txt  archive.tar  bam.txt  file1  file1.pub  file2  llala.txt
anastasia@anastasia-VirtualBox:~/dir1$ tar -tvf archive.tar
-rw-rw-r-- anastasia/anastasia 10240 2023-03-03 00:10 a1.txt
-rw-rw-r-- anastasia/anastasia    60 2023-03-01 00:46 bam.txt
-rw-rw-r-- anastasia/anastasia   440 2023-03-01 00:47 llala.txt
anastasia@anastasia-VirtualBox:~/dir1$ tar -xvf archive.tar
a1.txt
bam.txt
llala.txt
anastasia@anastasia-VirtualBox:~/dir1$ ls
a1.txt  archive.tar  bam.txt  file1  file1.pub  file2  llala.txt
anastasia@anastasia-VirtualBox:~/dir1$ cat t1.c
#include <stdio.h>

int main(){
    int a = 5;
    int b = 4;
    int c = a + b;
    printf("%d\n", c);
}
anastasia@anastasia-VirtualBox:~/dir1$ cat t2.c
#include <stdio.h>

int main(){
    int a = 8;
    int b = 4;
    int c = a * b;
    printf("%d\n", c);
}
anastasia@anastasia-VirtualBox:~/dir1$ diff t1.c t2.c
4c4
<     int a = 5;
---
>     int a = 8;
6c6
<     int c = a + b;
---
>     int c = a * b;
anastasia@anastasia-VirtualBox:~/dir1$ diff -u t1.c t2.c
--- t1.c	2023-03-03 00:21:10.871375921 +0300
+++ t2.c	2023-03-03 00:18:50.315146723 +0300
@@ -1,8 +1,8 @@
 #include <stdio.h>
 
 int main(){
-    int a = 5;
+    int a = 8;
     int b = 4;
-    int c = a + b;
+    int c = a * b;
     printf("%d\n", c);
 }
anastasia@anastasia-VirtualBox:~$ cat file1.txt
Hello World!
anastasia@anastasia-VirtualBox:~$ cat file2.txt
helo World
anastasia@anastasia-VirtualBox:~$ cmp file1.txt file2.txt
file1.txt file2.txt различаются: байт 1, строка 1
anastasia@anastasia-VirtualBox:~$ cmp -c file1.txt file2.txt
file1.txt file2.txt различаются: байт 1, строка 1 равен 110 H 150 h
anastasia@anastasia-VirtualBox:~$ cmp -cl file1.txt file2.txt
 1 110 H    150 h
 4 154 l    157 o
 5 157 o     40  
 6  40      127 W
 7 127 W    157 o
 8 157 o    162 r
 9 162 r    154 l
10 154 l    144 d
11 144 d     12 ^J
cmp: EOF в file2.txt после байта 11
anastasia@anastasia-VirtualBox:~$ cat file1.txt
Hello World!
anastasia@anastasia-VirtualBox:~$ cut -c 2,3 file1.txt
el
anastasia@anastasia-VirtualBox:~$ cut -b 1 file1.txt
H
anastasia@anastasia-VirtualBox:~$ cut -b 1,5  file1.txt
Ho
anastasia@anastasia-VirtualBox:~$ cut -b 4-7  file1.txt
lo W
anastasia@anastasia-VirtualBox:~$ cut -b -7 file1.txt
Hello W
anastasia@anastasia-VirtualBox:~$ cat file2.txt
12345 456
anastasia@anastasia-VirtualBox:~$ od -b file2.txt
0000000 061 062 063 064 065 040 064 065 066 012
0000012
anastasia@anastasia-VirtualBox:~$ od -c file2.txt
0000000   1   2   3   4   5       4   5   6  \n
0000012
anastasia@anastasia-VirtualBox:~$ od -i file2.txt
0000000   875770417   892608565        2614
0000012
anastasia@anastasia-VirtualBox:~$ od -An -c file2.txt
   1   2   3   4   5       4   5   6  \n
anastasia@anastasia-VirtualBox:~$ cat file1.txt
Hello World!
123 576
anastasia@anastasia-VirtualBox:~$ iconv -f ASCII -t UTF-16 file1.txt
  Hello World!
123 576
anastasia@anastasia-VirtualBox:~$ echo abc ß α € àḃç | iconv -f UTF-8 -t ASCII//TRANSLIT
abc ss ? EUR abc
anastasia@anastasia-VirtualBox:~$ df
Файл.система   1K-блоков Использовано Доступно Использовано% Cмонтировано в
udev             1969572            0  1969572            0% /dev
tmpfs             401800         1344   400456            1% /run
/dev/sda5       16850736     10371720  5597712           65% /
tmpfs            2008996            0  2008996            0% /dev/shm
tmpfs               5120            4     5116            1% /run/lock
tmpfs            2008996            0  2008996            0% /sys/fs/cgroup
/dev/loop0           128          128        0          100% /snap/bare/5
/dev/loop3        354688       354688        0          100% /snap/gnome-3-38-2004/119
/dev/loop2        354688       354688        0          100% /snap/gnome-3-38-2004/115
/dev/loop1         64896        64896        0          100% /snap/core20/1822
/dev/loop4         93952        93952        0          100% /snap/gtk-common-themes/1535
/dev/loop5         47104        47104        0          100% /snap/snap-store/599
/dev/loop8         47104        47104        0          100% /snap/snap-store/638
/dev/loop6         51072        51072        0          100% /snap/snapd/17950
/dev/loop9         64896        64896        0          100% /snap/core20/1778
/dev/loop7         51072        51072        0          100% /snap/snapd/18357
/dev/sda1         523248            4   523244            1% /boot/efi
tmpfs             401796           24   401772            1% /run/user/1000
/dev/sr0           62390        62390        0          100% /media/anastasia/VBox_GAs_6.1.38
anastasia@anastasia-VirtualBox:~$ df -h
Файл.система   Размер Использовано  Дост Использовано% Cмонтировано в
udev             1,9G            0  1,9G            0% /dev
tmpfs            393M         1,4M  392M            1% /run
/dev/sda5         17G         9,9G  5,4G           65% /
tmpfs            2,0G            0  2,0G            0% /dev/shm
tmpfs            5,0M         4,0K  5,0M            1% /run/lock
tmpfs            2,0G            0  2,0G            0% /sys/fs/cgroup
/dev/loop0       128K         128K     0          100% /snap/bare/5
/dev/loop3       347M         347M     0          100% /snap/gnome-3-38-2004/119
/dev/loop2       347M         347M     0          100% /snap/gnome-3-38-2004/115
/dev/loop1        64M          64M     0          100% /snap/core20/1822
/dev/loop4        92M          92M     0          100% /snap/gtk-common-themes/1535
/dev/loop5        46M          46M     0          100% /snap/snap-store/599
/dev/loop8        46M          46M     0          100% /snap/snap-store/638
/dev/loop6        50M          50M     0          100% /snap/snapd/17950
/dev/loop9        64M          64M     0          100% /snap/core20/1778
/dev/loop7        50M          50M     0          100% /snap/snapd/18357
/dev/sda1        511M         4,0K  511M            1% /boot/efi
tmpfs            393M          24K  393M            1% /run/user/1000
/dev/sr0          61M          61M     0          100% /media/anastasia/VBox_GAs_6.1.38
anastasia@anastasia-VirtualBox:~$ df .
Файл.система   1K-блоков Использовано Доступно Использовано% Cмонтировано в
/dev/sda5       16850736     10371720  5597712           65% /
anastasia@anastasia-VirtualBox:~/dir1$ cpp -Wcomment t1.c
# 1 "t1.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "t1.c"
…
# 858 "/usr/include/stdio.h" 3 4
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);
# 873 "/usr/include/stdio.h" 3 4
anastasia@anastasia-VirtualBox:~/dir1$ cpp t1.c
# 1 "t1.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 31 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 32 "<command-line>" 2
# 1 "t1.c"
…
# 858 "/usr/include/stdio.h" 3 4
extern int __uflow (FILE *);
extern int __overflow (FILE *, int);
# 873 "/usr/include/stdio.h" 3 4
# 2 "t1.c" 2
# 3 "t1.c"
int main(){
    int a = 5;
    int b = 4;
    int c = a + b;
    printf("%d\n", c);
}
anastasia@anastasia-VirtualBox:~/dir1$ cd
anastasia@anastasia-VirtualBox:~$ ls dir1 |xargs
a1.txt archive.tar bam.txt file1 file1.pub file2 llala.txt t1.c t2.c
anastasia@anastasia-VirtualBox:~$ find dir1 -name "*.txt" | xargs echo
dir1/a1.txt dir1/llala.txt dir1/bam.txt
anastasia@anastasia-VirtualBox:~$ cd dir1
anastasia@anastasia-VirtualBox:~/dir1$ ls
a1.txt  archive.tar  bam.txt  file1  file1.pub  file2  llala.txt  t1.c  t2.c
anastasia@anastasia-VirtualBox:~/dir1$ echo "f1 f2 f3" | xargs touch
anastasia@anastasia-VirtualBox:~/dir1$ ls
a1.txt       bam.txt  f2  file1      file2      t1.c
archive.tar  f1       f3  file1.pub  llala.txt  t2.c
anastasia@anastasia-VirtualBox:~$ cat file1.txt
AB
CD
ED
FG
VB
anastasia@anastasia-VirtualBox:~$ cat file2.txt
1
2
3
4
5
anastasia@anastasia-VirtualBox:~$ paste file2.txt file1.txt
1	AB
2	CD
3	ED
4	FG
5	VB
anastasia@anastasia-VirtualBox:~$ paste -d '-' file2.txt file1.txt
1-AB
2-CD
3-ED
4-FG
5-VB
anastasia@anastasia-VirtualBox:~$ paste -s file2.txt file1.txt
1	2	3	4	5
AB	CD	ED	FG	VB
anastasia@anastasia-VirtualBox:~$ ed
a
aaa vv dfg hrty
25647yf 83
.
p
25647yf 83
,p
aaa vv dfg hrty
25647yf 83
f edd.txt
edd.txt
w
27
Q
anastasia@anastasia-VirtualBox:~$ ls -la | tee file1.txt
итого 324
drwxr-xr-x 22 anastasia anastasia  4096 мар  3 01:50 .
drwxr-xr-x  3 root      root       4096 сен  8 18:54 ..
-rwxrwxr-x  1 anastasia anastasia 16824 мар  2 20:05 a.out
drwxrwxr-x  2 anastasia anastasia  4096 сен 29 02:33 ar1
-rw-rw-r--  1 anastasia anastasia 10752 ноя 19 16:47 archive.tar
-rw-rw-r--  1 anastasia anastasia  1463 сен 29 02:56 archive.tgz
-rw-------  1 anastasia anastasia 23977 мар  1 17:23 .bash_history
-rw-r--r--  1 anastasia anastasia   220 сен  8 18:54 .bash_logout
-rw-r--r--  1 anastasia anastasia  3771 сен  8 18:54 .bashrc
drwx------ 16 anastasia anastasia  4096 мар  3 01:36 .cache
drwx------ 16 anastasia anastasia  4096 окт  3 20:19 .config
drwxrwxr-x  2 anastasia anastasia  4096 мар  3 01:41 dir1
drwxrwxr-x  2 anastasia anastasia  4096 сен 24 23:31 dir2
-rw-rw-r--  1 anastasia anastasia    27 мар  3 01:50 edd.txt
drwx------  3 anastasia anastasia  4096 окт 24 21:40 .emacs.d
-rw-rw-r--  1 anastasia anastasia 13784 янв 23 03:26 exzam.c
-rw-rw-r--  1 anastasia anastasia  1967 дек  3 02:04 f.c
-rw-rw-r--  1 anastasia anastasia     0 мар  3 01:58 file1.txt
-rw-rw-r--  1 anastasia anastasia    10 мар  3 01:41 file2.txt
-rw-rw-r--  1 anastasia anastasia   110 дек 16 23:45 f.txt
drwx------  3 anastasia anastasia  4096 янв 23 03:25 .gnupg
-rw-------  1 anastasia anastasia   847 сен 20 00:07 .gnuplot_history
-rw-rw-r--  1 anastasia anastasia  3158 мар  3 00:24 kf.c
-rw-rw-r--  1 anastasia anastasia  1821 янв 29 00:07 kp3.c
-rw-rw-r--  1 anastasia anastasia   798 фев 17 01:16 kp3dop.c
-rw-rw-r--  1 anastasia anastasia  3802 янв 23 20:14 kp4.c
-rw-rw-r--  1 anastasia anastasia  1979 фев  5 20:30 kp4dop.c
-rw-rw-r--  1 anastasia anastasia   414 окт 25 00:22 lab10.c
-rw-rw-r--  1 anastasia anastasia   404 окт 24 21:47 lab10.c~
-rw-rw-r--  1 anastasia anastasia  1246 ноя 16 17:05 lab11.c
-rw-rw-r--  1 anastasia anastasia  1450 ноя 25 10:17 lab11dop.c
-rw-rw-r--  1 anastasia anastasia  1403 дек  9 01:19 lab13.c
-rw-rw-r--  1 anastasia anastasia   456 дек 16 17:13 lab13dop.c
-rw-rw-r--  1 anastasia anastasia  3001 дек 16 03:06 lab14.c
-rw-rw-r--  1 anastasia anastasia  1724 дек 16 23:56 lab14dop.c
-rw-rw-r--  1 anastasia anastasia  1049 дек 16 00:24 lab15.c
-rw-rw-r--  1 anastasia anastasia   906 дек 16 13:59 lab15dop.c
-rw-rw-r--  1 anastasia anastasia   835 окт 29 14:00 lab9.c
-rw-rw-r--  1 anastasia anastasia  1332 ноя 19 13:47 lab9dop.c
-rw-rw-r--  1 anastasia anastasia   319 ноя  9 01:51 laba12.c
-rw-rw-r--  1 anastasia anastasia  1612 ноя 26 17:35 laba12dop.c
-rw-rw-r--  1 anastasia anastasia   355 янв 26 20:25 lala.c
drwxr-xr-x  3 anastasia anastasia  4096 сен  8 19:01 .local
-rw-rw-r--  1 anastasia anastasia  1572 дек  3 11:27 m.c
drwx------  4 anastasia anastasia  4096 сен 24 09:27 .mozilla
-rw-r--r--  1 anastasia anastasia   807 сен  8 18:54 .profile
drwx------  3 anastasia anastasia  4096 окт  1 23:00 snap
drwx------  2 anastasia anastasia  4096 сен 27 01:31 .ssh
-rw-r--r--  1 anastasia anastasia     0 сен  8 19:07 .sudo_as_admin_successful
-rw-rw-r--  1 anastasia anastasia    63 мар  1 01:10 test.txt
-rwxrwxr-x  1 anastasia anastasia 17312 янв  8 22:20 theaded_program
drwx------  6 anastasia anastasia  4096 сен 27 18:23 .thunderbird
-rw-rw-r--  1 anastasia anastasia    77 дек 16 23:45 t.txt
-rw-r-----  1 anastasia anastasia     5 мар  2 17:38 .vboxclient-clipboard.pid
-rw-r-----  1 anastasia anastasia     5 мар  2 17:38 .vboxclient-display-svga-x11.pid
-rw-r-----  1 anastasia anastasia     5 мар  2 17:38 .vboxclient-draganddrop.pid
-rw-r-----  1 anastasia anastasia     5 мар  2 17:38 .vboxclient-seamless.pid
drwxr-xr-x  2 anastasia anastasia  4096 сен  8 19:01 Видео
drwxr-xr-x  3 anastasia anastasia  4096 окт  5 13:08 Документы
drwxr-xr-x  4 anastasia anastasia  4096 окт 12 19:06 Загрузки
drwxr-xr-x  2 anastasia anastasia  4096 сен  8 19:01 Изображения
drwxr-xr-x  2 anastasia anastasia  4096 сен  8 19:01 Музыка
drwxr-xr-x  2 anastasia anastasia  4096 сен  8 19:01 Общедоступные
drwxr-xr-x  2 anastasia anastasia  4096 окт  3 20:02 Рабочий стол
drwxr-xr-x  2 anastasia anastasia  4096 сен  8 19:01 Шаблоны
anastasia@anastasia-VirtualBox:~$ pwd | tee -a file1.txt
/home/anastasia
anastasia@anastasia-VirtualBox:~$ date | tee file1.txt
Пт 03 мар 2023 01:59:54 MSK
anastasia@anastasia-VirtualBox:~$ cat file1.txt
Пт 03 мар 2023 01:59:54 MSK
anastasia@anastasia-VirtualBox:~$ cat test.txt
Cat is a dog
CAt is a desk
cat is a flat
Cat ia you
CAT is we

anastasia@anastasia-VirtualBox:~$ head -v test.txt
==> test.txt <==
Cat is a dog
CAt is a desk
cat is a flat
Cat ia you
CAT is we

anastasia@anastasia-VirtualBox:~$ head -n 2 test.txt
Cat is a dog
CAt is a desk
anastasia@anastasia-VirtualBox:~$ head -c 32 test.txt
Cat is a dog
CAt is a desk
cat ianastasia@anastasia-VirtualBox:~$ head --lines=-5 test.txt
Cat is a dog
anastasia@anastasia-VirtualBox:~/dir1$ split f1
anastasia@anastasia-VirtualBox:~/dir1$ ls
archive.tar  bam.txt  f1  f2  f3  file1  file1.pub  file2  llala.txt  t1.c  t2.c  xaa
anastasia@anastasia-VirtualBox:~/dir1$ split -l 5 f1 split_file
anastasia@anastasia-VirtualBox:~/dir1$ cat split_fileaa
l1
l2
l3
l4
l5
anastasia@anastasia-VirtualBox:~/dir1$ cat split_fileab
l6
l7
l8
anastasia@anastasia-VirtualBox:~/dir1$ split f1 -l 7 --verbose
создаётся файл 'xaa'
создаётся файл 'xab'
anastasia@anastasia-VirtualBox:~/dir1$ split -b 32 f1 file
anastasia@anastasia-VirtualBox:~/dir1$ cat fileab
cat: fileab: Нет такого файла или каталога
anastasia@anastasia-VirtualBox:~/dir1$ cat fileaa
l1
l2
l3
l4
l5
l6
l7
l8
anastasia@anastasia-VirtualBox:~/dir1$ split -b 8 f1 file
anastasia@anastasia-VirtualBox:~/dir1$ cat fileaa
l1
l2
l3anastasia@anastasia-VirtualBox:~/dir1$ cat fileab

l4
l5
lanastasia@anastasia-VirtualBox:~/dir1$ cat fileac
6
l7
l8
anastasia@anastasia-VirtualBox:~/dir1$ split -n 3 f1
anastasia@anastasia-VirtualBox:~/dir1$ cat xaa
l1
l2
l3anastasia@anastasia-VirtualBox:~/dir1$ cat xab

l4
l5
lanastasia@anastasia-VirtualBox:~/dir1$ cat xac
6
l7
l8
anastasia@anastasia-VirtualBox:~/dir1$ sum f1
41096     1
anastasia@anastasia-VirtualBox:~/dir1$ sum -s f1
1364 1 f1
anastasia@anastasia-VirtualBox:~/dir1$ sum -r f1
41096     1
anastasia@anastasia-VirtualBox:~/dir1$ sum bam.txt
55474     1
anastasia@anastasia-VirtualBox:~$ cat file1.txt
hd vzfsj ma
anastasia@anastasia-VirtualBox:~$ cat file2.txt
hysdch sdjf asbc
anastasia@anastasia-VirtualBox:~$ dd if=file1.txt of=file2.txt
0+1 записей получено
0+1 записей отправлено
12 байт скопировано, 0,000250932 s, 47,8 kB/s
anastasia@anastasia-VirtualBox:~$ cat file2.txt
hd vzfsj ma
anastasia@anastasia-VirtualBox:~$ cat file1.txt
hd vzfsj ma
anastasia@anastasia-VirtualBox:~$ cat > file2.txt
dhwg wertyu scxf uoihufhvlk;
^C
anastasia@anastasia-VirtualBox:~$ dd if=file1.txt of=file2.txt bs=1 seek=8
12+0 записей получено
12+0 записей отправлено
12 байт скопировано, 0,00022461 s, 53,4 kB/s
anastasia@anastasia-VirtualBox:~$ cat file2.txt
dhwg werhd vzfsj ma
anastasia@anastasia-VirtualBox:~$ cat file1.txt
hd vzfsj ma
anastasia@anastasia-VirtualBox:~$ cat > file2.txt
ddfadc akhcugwugh
^C
anastasia@anastasia-VirtualBox:~$ dd if=file1.txt of=file2.txt skip=2 seek=8
dd: file1.txt: невозможно пропустить до заданного смещения
0+0 записей получено
0+0 записей отправлено
0 байт скопировано, 0,00228209 s, 0,0 kB/s
anastasia@anastasia-VirtualBox:~$ cat file1.txt
hd vzfsj maqygdhvchvh sajhcuiigchwv sjj
anastasia@anastasia-VirtualBox:~$ cat file2.txt
ddfadc akhcugwugh
anastasia@anastasia-VirtualBox:~$ dd if=file1.txt of=file2.txt bs=1 skip=1 seek=3
39+0 записей получено
39+0 записей отправлено
39 байт скопировано, 0,00022135 s, 176 kB/s
anastasia@anastasia-VirtualBox:~$ cat file1.txt
hd vzfsj maqygdhvchvh sajhcuiigchwv sjj
anastasia@anastasia-VirtualBox:~$ cat file2.txt
ddfd vzfsj maqygdhvchvh sajhcuiigchwv sjj
anastasia@anastasia-VirtualBox:~$ cat < file2.txt
ddfd vzfsj maqygdhvchvh sajhcuiigchwv sjj
anastasia@anastasia-VirtualBox:~$ cat > file2.txt
dfgirot dhshc
^C
anastasia@anastasia-VirtualBox:~$ dd if=file1.txt of=file2.txt bs=1 count=10 seek=3
10+0 записей получено
10+0 записей отправлено
10 байт скопировано, 0,000180424 s, 55,4 kB/s
anastasia@anastasia-VirtualBox:~$ cat file2.txt
anastasia@anastasia-VirtualBox:~$ cat file1.txt
hd vzfsj maqygdhvchvh sajhcuiigchwv sjj
anastasia@anastasia-VirtualBox:~$ cat > file2.txt
sah jhfeau
^C
anastasia@anastasia-VirtualBox:~$ dd if=file1.txt of=file2.txt bs=1w count=10 seek=3
10+0 записей получено
10+0 записей отправлено
20 байт скопировано, 0,00015029 s, 133 kB/s
anastasia@anastasia-VirtualBox:~$ cat file2.txt
anastasia@anastasia-VirtualBox:~$ cat file2.txt
sah jhhd vzfsj maqygdhvchvanastasia@anastasia-VirtualBox:~$ 
anastasia@anastasia-VirtualBox:~$ cat > file2.txt
edwyg sdgcgy
^C
anastasia@anastasia-VirtualBox:~$ dd if=file1.txt of=file2.txt ibs=1 obs=2 skip=1 seek=3
39+0 записей получено
19+1 записей отправлено
39 байт скопировано, 0,000410566 s, 95,0 kB/s
anastasia@anastasia-VirtualBox:~$ cat file2.txt
edwyg d vzfsj maqygdhvchvh sajhcuiigchwv sjj
anastasia@anastasia-VirtualBox:~$ cat > file2.txt
eduegw chhvisv
^C
anastasia@anastasia-VirtualBox:~$ dd if=file1.txt of=file2.txt conv=ucase
0+1 записей получено
0+1 записей отправлено
40 байт скопировано, 0,000324411 s, 123 kB/s
anastasia@anastasia-VirtualBox:~$ cat file2.txt
HD VZFSJ MAQYGDHVCHVH SAJHCUIIGCHWV SJJ
anastasia@anastasia-VirtualBox:~$ dd if=file1.txt of=file2.txt conv=lcase
0+1 записей получено
0+1 записей отправлено
40 байт скопировано, 0,000278118 s, 144 kB/s
anastasia@anastasia-VirtualBox:~$ cat file2.txt
hd vzfsj maqygdhvchvh sajhcuiigchwv sjj
anastasia@anastasia-VirtualBox:~$ gzip -vk test.txt
test.txt:	 25.4% -- created test.txt.gz
anastasia@anastasia-VirtualBox:~$ gzip -c f.txt > f.txt.gz
anastasia@anastasia-VirtualBox:~$ gzip -fvk -9 test.txt
test.txt:	 25.4% -- created test.txt.gz
anastasia@anastasia-VirtualBox:~$ gzip -lv test.txt.gz
method  crc     date  time           compressed        uncompressed  ratio uncompressed_name
defla d5f95159 Mar  1 01:10                  74                  63  25.4% test.txt
anastasia@anastasia-VirtualBox:~$ gzip -dv f.txt.gz
gzip: f.txt already exists; do you wish to overwrite (y or n)? y
f.txt.gz:	 40.0% -- replaced with f.txt
anastasia@anastasia-VirtualBox:~$ cd ar1
anastasia@anastasia-VirtualBox:~/ar1$ bzip2 -z m2
anastasia@anastasia-VirtualBox:~/ar1$ ls
m2.bz2  m3
anastasia@anastasia-VirtualBox:~/ar1$ bzip2 -k m3
anastasia@anastasia-VirtualBox:~/ar1$ ls
m2.bz2  m3  m3.bz2
anastasia@anastasia-VirtualBox:~/ar1$ bzip2 -dv m2.bz2
  m2.bz2:  done
anastasia@anastasia-VirtualBox:~/ar1$ ls
m2  m3  m3.bz2
anastasia@anastasia-VirtualBox:~/ar1$ bzip2 -vt m3.bz2
  m3.bz2:  ok
anastasia@anastasia-VirtualBox:~/ar1$ bzip2 -zvk m2
  m2:       0.133:1, 60.000 bits/byte, -650.00% saved, 6 in, 45 out.
anastasia@anastasia-VirtualBox:~/ar1$ ls
m2  m2.bz2  m3  m3.bz2
anastasia@anastasia-VirtualBox:~/ar1$ bzip2 -d m2.bz2
bzip2: Output file m2 already exists.
anastasia@anastasia-VirtualBox:~/ar1$ bzip2 -v -1 m2
  m2:       0.133:1, 60.000 bits/byte, -650.00% saved, 6 in, 45 out.
```

## 9. Дневник отладки

| **№** | **Лаб.Или Дом.** | **Дата** | **Время** | **Событие** | **Действие по исправлению** | **Примечание** |
| --- | --- | --- | --- | --- | --- | --- |
| **1** | **Дом.** | **01.03.23** | **13:00** | **Освоение команд ОС UNIX для обработки файлов** | **-** | **-** |

## 10. Замечания автора по существу работы


## 11. Выводы

Благодаря лабораторной работе было изучено программное обеспечение ОС UNIX. Были освоены команды по обработке текстовых файлов и каталогов. Были наиболее подробно рассмотрены команды dd, позволяющая конвертировать и копировать файлы, gzip, использующаяся для сжатия и распаковки файлов, и bzip2, также позволяющая сжимать и распаковывать файлы, делая это медленнее, но с более высокой степенью сжатия.

<b>Подпись студента:</b> ___________
