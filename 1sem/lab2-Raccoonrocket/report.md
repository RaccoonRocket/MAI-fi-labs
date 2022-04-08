# Отчет по лабораторной работе № 2 по курсу
# "Фундаментальная информатика"

Студент группы: M80-104Б, Борисов Сергей Павлович\
Контакты: 9802432172sergei@gmail.com\
Работа выполнена: 18.09.2021\
Преподаватель: Безлуцкая Елизавета Николаевна

## 1. Тема

Операционная среда ОС UNIX

## 2. Цель работы

Изучение и освоение программного обеспечения ОС UNIX и приобритение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX.

## 3. Задание

Изучить и освоить ОС Unix, написать осмысленный сценарий использования команд, занести результаты работы в протокол.

## 4. Оборудование

Процессор: AMD Ryzen 5 3500U @ 2.1 GHz\
ОП: 8 Гб\
НМД: 256 Гб\
Монитор: 1920x1080

## 5. Программное обеспечение

Операционная система семейства: **linux (ubuntu)**, версия **20.04 focal**\
Интерпретатор команд: **bash**, версия **5.0.17**\
Система программирования: **--**, версия **--**\
Редактор текстов: **emacs**, версия **25.2.2**\
Утилиты операционной системы: **--**\
Прикладные системы и программы: **--**\
Местонахождение и имена файлов программ и данных на домашнем компьютере: **F:\Ubuntu 20.04**

## 6. Идея, метод, алгоритм решения задачи

В данной лабораторной работе, для выполнения задачи "изучение и освоение OC Unix", Я задумал создать ряд команд, который включал бы в себя как можно больше команд, изученных самостоятельно и на занятиях, не забывая применять флаги, конвейеры и операторы.

## 7. Сценарий выполнения работы

План работы:\
Создать несколько директория\
В одной директории создать файл и изменить права для файла, чтобы при прочтении выдало ошибку\
Ошибку запишем во второй, нами созданный, файл\
Скопировать второй файл в другую директорию, переменовать и изменить права\
Создать нового пользователя и предоставить доступ к последнему файлу\
Во второй директории создать файл и записать в него что-нибудь\
Права второй директории передать новому пользователю\
Удалить лишние директории\
Проверить запущенные процессы\
Усовершенствовать программу по мере её написания

## 8. Распечатка протокола

```
raccoonrocket@raccoonrocket-VirtualBox:~$ mkdir dir{0..2}
raccoonrocket@raccoonrocket-VirtualBox:~$ ls
 dir0   dir2    Документы   Изображения   Общедоступные   Шаблоны
 dir1   Видео   Загрузки    Музыка       'Рабочий стол'
raccoonrocket@raccoonrocket-VirtualBox:~$ cd dir0
raccoonrocket@raccoonrocket-VirtualBox:~/dir0$ touch example.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir0$ echo write error > example.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir0$ cat example.txt
write error
raccoonrocket@raccoonrocket-VirtualBox:~/dir0$ chmod 111 example.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir0$ cat example.txt
cat: example.txt: Отказано в доступе
raccoonrocket@raccoonrocket-VirtualBox:~/dir0$ echo | cat example.txt 2> error.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir0$ ls
error.txt  example.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir0$ cat error.txt
cat: example.txt: Отказано в доступе
raccoonrocket@raccoonrocket-VirtualBox:~/dir0$ cd
raccoonrocket@raccoonrocket-VirtualBox:~$ pwd
/home/raccoonrocket
raccoonrocket@raccoonrocket-VirtualBox:~$ ls
 dir0   dir2    Документы   Изображения   Общедоступные   Шаблоны
 dir1   Видео   Загрузки    Музыка       'Рабочий стол'
raccoonrocket@raccoonrocket-VirtualBox:~$ cd dir0
raccoonrocket@raccoonrocket-VirtualBox:~/dir0$ cp error.txt /home/raccoonrocket/dir2
raccoonrocket@raccoonrocket-VirtualBox:~/dir0$ cd
raccoonrocket@raccoonrocket-VirtualBox:~$ cd dir2
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ ls
error.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ mv error.txt firsterror.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ chmod 777 firsterror.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ cd
raccoonrocket@raccoonrocket-VirtualBox:~$ sudo useradd test
raccoonrocket@raccoonrocket-VirtualBox:~$ cd dir2
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ ls
firsterror.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ sudo chown test firsterror.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ ls -l
итого 4
-rwxrwxrwx 1 test raccoonrocket 53 сен 17 10:10 firsterror.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ cat firsterror.txt
cat: example.txt: Отказано в доступе
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ sudo chmod 711 firsterror.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ cat firsterror.txt
cat: firsterror.txt: Отказано в доступе
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ echo | cat firsterror.txt 2> seconderror.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ ls
firsterror.txt  seconderror.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ cat seconderror.txt
cat: firsterror.txt: Отказано в доступе
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ cd
raccoonrocket@raccoonrocket-VirtualBox:~$ sudo chmod 700 dir2
raccoonrocket@raccoonrocket-VirtualBox:~$ cd dir2
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ ls
firsterror.txt  seconderror.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir2$ cd
raccoonrocket@raccoonrocket-VirtualBox:~$ sudo chown test dir2
raccoonrocket@raccoonrocket-VirtualBox:~$ cd dir2
bash: cd: dir2: Отказано в доступе
raccoonrocket@raccoonrocket-VirtualBox:~$ ls -l
итого 44
drwxrwxr-x 2 raccoonrocket raccoonrocket 4096 сен 17 10:08  dir0
drwxrwxr-x 2 raccoonrocket raccoonrocket 4096 сен 17 10:07  dir1
drwx------ 2 test          raccoonrocket 4096 сен 17 10:15  dir2
drwxr-xr-x 2 raccoonrocket raccoonrocket 4096 сен 11 16:06  Видео
drwxr-xr-x 2 raccoonrocket raccoonrocket 4096 сен 11 16:06  Документы
drwxr-xr-x 2 raccoonrocket raccoonrocket 4096 сен 11 16:06  Загрузки
drwxr-xr-x 2 raccoonrocket raccoonrocket 4096 сен 11 16:06  Изображения
drwxr-xr-x 2 raccoonrocket raccoonrocket 4096 сен 11 16:06  Музыка
drwxr-xr-x 2 raccoonrocket raccoonrocket 4096 сен 11 16:06  Общедоступные
drwxr-xr-x 2 raccoonrocket raccoonrocket 4096 сен 17 10:00 'Рабочий стол'
drwxr-xr-x 2 raccoonrocket raccoonrocket 4096 сен 11 16:06  Шаблоны
raccoonrocket@raccoonrocket-VirtualBox:~$ rm -rf dir{0..1}
raccoonrocket@raccoonrocket-VirtualBox:~$ ps
    PID TTY          TIME CMD
   1417 pts/0    00:00:00 bash
   1624 pts/0    00:00:00 ps
raccoonrocket@raccoonrocket-VirtualBox:~$ sleep 10000 &
[1] 1627
raccoonrocket@raccoonrocket-VirtualBox:~$ ps
    PID TTY          TIME CMD
   1417 pts/0    00:00:00 bash
   1627 pts/0    00:00:00 sleep
   1628 pts/0    00:00:00 ps
raccoonrocket@raccoonrocket-VirtualBox:~$ kill 1627
raccoonrocket@raccoonrocket-VirtualBox:~$ ps
    PID TTY          TIME CMD
   1417 pts/0    00:00:00 bash
   1630 pts/0    00:00:00 ps
[1]+  Завершено      sleep 10000
raccoonrocket@raccoonrocket-VirtualBox:~$ mkdir dir{0..1}
raccoonrocket@raccoonrocket-VirtualBox:~$ sleep 10 && rm -rf dir{0..1}
raccoonrocket@raccoonrocket-VirtualBox:~$ ls
 dir2    Документы   Изображения   Общедоступные   Шаблоны
 Видео   Загрузки    Музыка       'Рабочий стол'
raccoonrocket@raccoonrocket-VirtualBox:~$
```

## 9. Дневник отладки

| № | Лаб. или дом | Дата______| Время | Событие _____________ | Действие по исправлению | Примечание  |\
| 0_  | Дом__________ |16.09.2021 | 13:00_ | Выполнил `rmdir -rf` | Неисправимо______________             | Мне грустно_|

## 10. Замечания автора по существу работы

Замечаний нет

## 11. Выводы

Я в достаточной мере преисполнился в освоении OC Unix и уверен, что полученные знания, в ходе выполнения лабораторной работы, пригодятся мне в будущем.\
Итог: Так как это моя первая лабораторная работа, Я научился не только устанавливать Linix (OC Unix) и работать в ней, но и оформлять отчёты по лаборатоным работам, что на ближайшие годы будет являться необходимостью. 
