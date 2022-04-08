# Отчет по лабораторной работе N 10 по курсу
# "Фундаментальная информатика"

Студент группы: M80-104Б, Борисов Сергей Павлович\
Контакты: 9802432172sergei@gmail.com\
Работа выполнена: 19.11.2021\
Преподаватель: Безлуцкая Елизавета Николаевна

## 1. Тема

Отладчик системы программирования системы Unix.

## 2. Цель работы

Научиться взаимодействовать c отладчиком в инерактивном режиме, путем ввода команд в терминал.

## 3. Задание

Произвести процесс поиска сбоев, ошибок, с помощью внутреннего отладчика.

## 4. Оборудование

Процессор: AMD Ryzen 5 3500U @ 2.1 GHz\
ОП: 8192 Мб\
НМД: 256 Гб\
Монитор: 1920x1080

## 5. Программное обеспечение

Операционная система семейства: **linux (ubuntu)**, версия **20.04 focal**\
Интерпретатор команд: **bash**, версия **5.0.17**.\
Система программирования: **--**, версия **--**\
Редактор текстов: **emacs**, версия **25.2.2**\
Утилиты операционной системы: **--**\
Прикладные системы и программы: **--**\
Местонахождение и имена файлов программ и данных на домашнем компьютере: **F:\Ubuntu 20.04**\

## 6. Идея, метод, алгоритм решения задачи

Изучить материалы по пользованию отладчика gdb и произвести "дебаг".

## 7. Сценарий выполнения работы

1. Скомпилировать файл с ключом компилятора -g.
2. Зайти в отладчик.
3. Просмотреть (распечатать файл).
4. Выбрать точку остановки.
5. Запустить программу.
6. В ходе выполнения программы, выводить значения и тип нужных переменных.
7. Убедиться, что в тестовой программе аномалий не обнаружено.

## 8. Распечатка протокола

```
raccoonrocket@raccoonrocket-VirtualBox:~$ gcc -g -o test Lab12.c
raccoonrocket@raccoonrocket-VirtualBox:~$ gdb test
GNU gdb (Ubuntu 9.2-0ubuntu1~20.04) 9.2
Copyright (C) 2020 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.
Type "show copying" and "show warranty" for details.
This GDB was configured as "x86_64-linux-gnu".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
    <http://www.gnu.org/software/gdb/documentation/>.

For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from test...
(gdb) list 15
10	            continue;
11	        }
12	        a = num;
13	        unone = a % 10;
14	        while (a != 0) {
15	            a /= 10;
16	            n *= 10;
17	        }
18	        n /= 10;
19	        one = num / n;
(gdb) break 13
Breakpoint 1 at 0x11e7: file Lab12.c, line 13.
(gdb) run
Starting program: /home/raccoonrocket/test 
1234567

Breakpoint 1, main () at Lab12.c:13
13	        unone = a % 10;
(gdb) print a
$1 = 1234567
(gdb) next
14	        while (a != 0) {
(gdb) print unone
$2 = 7
(gdb) ptype n
type = long long
(gdb) step
15	            a /= 10;
(gdb) step 2
14	        while (a != 0) {
(gdb) step3
Undefined command: "step3".  Try "help".
(gdb) step 3
14	        while (a != 0) {
(gdb) print n
$3 = 100
(gdb) step 5
16	            n *= 10;
(gdb) print n
$4 = 1000
(gdb) step 10
14	        while (a != 0) {
(gdb) print n
$5 = 10000000
(gdb) next
18	        n /= 10;
(gdb) next
19	        one = num / n;
(gdb) print n
$6 = 1000000
(gdb) next
20	        num %= n;
(gdb) print one
$7 = 1
(gdb)
```

## 9. Дневник отладки

```
+---+---------------+------------+-------+------------------------+-------------------------+-------------+
| № | Лаб. или дом. | Дата       | Время | Событие                | Действие по исправлению | Примечание  |
+===+===============+============+=======+========================+=========================+=============+
|0  | Дом           | 17.11.2021 | 21:00 | Не вызывается отладчик | Не поставлен флаг "-g"  | Исправлено  |
+-------------------+------------+-------+------------------------+-------------------------+-------------+
```

## 10. Замечания автора по существу работы

Замечаний и претензий по выполненной работе не имею.

## 11. Выводы

"Использование отладчика - последнее средство перед тем, как бросить системное программирование и заняться чем-нибудь полегче." - Э.Йодан
 
