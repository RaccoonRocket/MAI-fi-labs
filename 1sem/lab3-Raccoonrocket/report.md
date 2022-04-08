# Отчет по лабораторной работе N 3 по курсу
# "Фундаментальная информатика"

Студент группы: M80-104Б, Борисов Сергей Павлович\
Контакты: 9802432172sergei@gmail.com\
Работа выполнена: 25.09.2021\
Преподаватель: Безлуцкая Елизавета Николаевна

## 1. Тема

Сети и телекоммуникации в ОС UNIX

## 2. Цель работы

Научиться в взаимодействовать с удаленными серверами при помощи сетевых команд ОС UNIX.

## 3. Задание

Придумать осмысленный сценарий использования сетевых команд OC UNIX, включающий основные способы взаимодействия с удалёнными серверами.

## 4. Оборудование

Процессор: AMD Ryzen 5 3500U @ 2.1 GHz\
ОП: 8192 Мб\
НМД: 256 Гб\
Монитор: 1920x1080\

## 5. Программное обеспечение

Операционная система семейства: **linux (ubuntu)**, версия **20.04 focal**\
Интерпретатор команд: **bash**, версия **5.0.17**.\
Система программирования: **--**, версия **--**\
Редактор текстов: **emacs**, версия **25.2.2**\
Утилиты операционной системы: **--**\
Прикладные системы и программы: **--**\
Местонахождение и имена файлов программ и данных на домашнем компьютере: **F:\Ubuntu 20.04**\

## 6. Идея, метод, алгоритм решения задачи

Подключиться к удаленному серверу, скопировать с него и на него директории/файлы, изменить кодировку файл, заархировать некоторые файлы и скопировать на удаленный сервер

## 7. Сценарий выполнения работы

1. Проверить есть ли связь с удалённым сервером
2. Подключиться к удалённому серверу
3. Создать файл на локальной машине
4. Скопировать его на удалённый сервер
5. Проверить наличие скопированного файла на удалённом сервере
6. Создать директорию на локальной машине
7. Создать новый файл в этой директории
8. Скопировать созданную директорию на удалённый сервер
9. Проверить наличие скопированной директории на удалённом сервере
10. Скопировать файл с удаленного сервера на локальную машину при помощи scp
11. Скопировать файл с удаленного сервера на локальную машину при помощи rsync
12. Узнать кодировку скопированного файла
13. Изменить кодировку скопированного файла на UTF-8
14. Заархивировать директорию с файлами
15. Скопировать созданный архив на удалённый сервер
16. Проверить наличие скопированного архива на удалённом сервере

## 8. Распечатка протокола

```
raccoonrocket@raccoonrocket-VirtualBox:~$ ping -c 4 194.58.90.16
PING 194.58.90.16 (194.58.90.16) 56(84) bytes of data.
64 bytes from 194.58.90.16: icmp_seq=1 ttl=49 time=272 ms
64 bytes from 194.58.90.16: icmp_seq=2 ttl=49 time=390 ms
64 bytes from 194.58.90.16: icmp_seq=3 ttl=49 time=559 ms
64 bytes from 194.58.90.16: icmp_seq=4 ttl=49 time=442 ms

--- 194.58.90.16 ping statistics ---
4 packets transmitted, 4 received, 0% packet loss, time 3025ms
rtt min/avg/max/mdev = 271.726/415.480/558.589/103.077 ms
raccoonrocket@raccoonrocket-VirtualBox:~$ ssh -p 8003 borisov@194.58.90.16
borisov@194.58.90.16's password:
Last login: Fri Sep 24 12:15:26 2021 from 185.215.176.13
borisov@4c2ffb3ebf63:~$ exit
logout
Connection to 194.58.90.16 closed.
raccoonrocket@raccoonrocket-VirtualBox:~$ ls
file1.txt Документы Изображения Общедоступные Шаблоны
Видео Загрузки Музыка 'Рабочий стол'
raccoonrocket@raccoonrocket-VirtualBox:~$ scp -rP 8003 file1.txt borisov@194.58.90.16:~/data
borisov@194.58.90.16's password:
file1.txt 100% 0 0.0KB/s 00:00
raccoonrocket@raccoonrocket-VirtualBox:~$ ssh -p 8003 borisov@194.58.90.16
borisov@194.58.90.16's password:
Last login: Sat Sep 25 12:52:05 2021 from 213.87.162.114
borisov@4c2ffb3ebf63:~$ cd data
borisov@4c2ffb3ebf63:~/data$ ls
28p4u1ug 5s3hr4gv 8foty9iw c7m9t5fi file1.txt gzlnoez6
3ni8eym3 6qq91mqx azgcd6xn cqlzdnxz fvcno84e
borisov@4c2ffb3ebf63:~/data$ cd
borisov@4c2ffb3ebf63:~$ exit
logout
Connection to 194.58.90.16 closed.
raccoonrocket@raccoonrocket-VirtualBox:~$ mkdir dir1
raccoonrocket@raccoonrocket-VirtualBox:~$ cd dir1
raccoonrocket@raccoonrocket-VirtualBox:~/dir1$ touch file2.txt
raccoonrocket@raccoonrocket-VirtualBox:~/dir1$ cd
raccoonrocket@raccoonrocket-VirtualBox:~$ scp -rP 8003 dir1 borisov@194.58.90.16:~/data
borisov@194.58.90.16's password:
file2.txt 100% 0 0.0KB/s 00:00
raccoonrocket@raccoonrocket-VirtualBox:~$ ssh -p 8003 borisov@194.58.90.16
borisov@194.58.90.16's password:
Last login: Sat Sep 25 12:58:51 2021 from 213.87.162.114
borisov@4c2ffb3ebf63:~$ cd data
borisov@4c2ffb3ebf63:~/data$ ls
28p4u1ug 5s3hr4gv 8foty9iw c7m9t5fi dir1 fvcno84e
3ni8eym3 6qq91mqx azgcd6xn cqlzdnxz file1.txt gzlnoez6
borisov@4c2ffb3ebf63:~/data$ cd dir1
borisov@4c2ffb3ebf63:~/data/dir1$ ls
file2.txt
borisov@4c2ffb3ebf63:~/data/dir1$ cd ..
borisov@4c2ffb3ebf63:~/data$ ls
28p4u1ug 5s3hr4gv 8foty9iw c7m9t5fi dir1 fvcno84e
3ni8eym3 6qq91mqx azgcd6xn cqlzdnxz file1.txt gzlnoez6
borisov@4c2ffb3ebf63:~/data$ cd gzlnoez6
borisov@4c2ffb3ebf63:~/data/gzlnoez6$ ls
bacyq.txt frecn.txt.txt oryrb.data rzsil.data untqm.txt
bacyq.txt.txt hdltl.data oxexu.data scame.data untqm.txt.txt
cazvz.txt hobdt.txt qbuvg.txt sprbr.data vtqwc.data
cazvz.txt.txt hobdt.txt.txt qbuvg.txt.txt tbaqj.txt
ezlkf.txt koqfc.txt qgosy.data tbaqj.txt.txt
ezlkf.txt.txt koqfc.txt.txt qlaxo.txt uhoal.data
frecn.txt lmvnu.data qlaxo.txt.txt umkly.data
borisov@4c2ffb3ebf63:~/data/gzlnoez6$ pwd
/home/borisov/data/gzlnoez6
borisov@4c2ffb3ebf63:~/data/gzlnoez6$ exit
logout
Connection to 194.58.90.16 closed.
raccoonrocket@raccoonrocket-VirtualBox:~$ scp -rP 8003 borisov@194.58.90.16:/home/borisov/data/gzlnoez6/bacyq.txt ~
borisov@194.58.90.16's password:
bacyq.txt 100% 220KB 85.4KB/s 00:02
raccoonrocket@raccoonrocket-VirtualBox:~$ rsync -e "ssh -p 8003" borisov@194.58.90.16:/home/borisov/data/gzlnoez6/cazvz.txt ~
borisov@194.58.90.16's password:
raccoonrocket@raccoonrocket-VirtualBox:~$ ls
bacyq.txt file1.txt Загрузки Общедоступные
cazvz.txt Видео Изображения 'Рабочий стол'
dir1 Документы Музыка Шаблоны
raccoonrocket@raccoonrocket-VirtualBox:~$ file cazvz.txt
cazvz.txt: ASCII text, with very long lines, with no line terminators
raccoonrocket@raccoonrocket-VirtualBox:~$ iconv -f ASCII -t UTF-8 cazvz.txt
8Dx8OE4wc682pMUq62rHYkgL3uHURyXEV9IHn8JXlPD133b9oyxoKcwjIq6xE7B3ViM18ay2Foz3pjgy….
raccoonrocket@raccoonrocket-VirtualBox:~$ ls
bacyq.txt file1.txt Загрузки Общедоступные
cazvz.txt Видео Изображения 'Рабочий стол'
dir1 Документы Музыка Шаблоны
raccoonrocket@raccoonrocket-VirtualBox:~$ tar -cf zip.tar bacyq.txt cazvz.txt file1.txt
raccoonrocket@raccoonrocket-VirtualBox:~$ ls
bacyq.txt file1.txt Документы Музыка Шаблоны
cazvz.txt zip.tar Загрузки Общедоступные
dir1 Видео Изображения 'Рабочий стол'
raccoonrocket@raccoonrocket-VirtualBox:~$ tar -tf zip.tar
bacyq.txt
cazvz.txt
file1.txt
raccoonrocket@raccoonrocket-VirtualBox:~$ scp -rP 8003 zip.tar borisov@194.58.90.16:~/data
borisov@194.58.90.16's password:
zip.tar 100% 530KB 233.3KB/s 00:02
raccoonrocket@raccoonrocket-VirtualBox:~$ ssh -p 8003 borisov@194.58.90.16
borisov@194.58.90.16's password:
Last login: Sat Sep 25 14:10:38 2021 from 213.87.162.114
borisov@4c2ffb3ebf63:~$ cd data
borisov@4c2ffb3ebf63:~/data$ ls
28p4u1ug 5s3hr4gv 8foty9iw c7m9t5fi dir1 fvcno84e zip.tar
3ni8eym3 6qq91mqx azgcd6xn cqlzdnxz file1.txt gzlnoez6
borisov@4c2ffb3ebf63:~/data$ tar -tf zip.tar
bacyq.txt
cazvz.txt
file1.txt
borisov@4c2ffb3ebf63:~/data$ exit
logout
Connection to 194.58.90.16 closed.

```

## 9. Дневник отладки

| № | Лаб. или дом | Дата______| Время | Событие _____________ | Действие по исправлению | Примечание  |\
| 0_  | Дом__________ |25.09.2021 | 17:35_ | Выполнил `tar -cf`__ | Неисправимо______________             | Мне грустно_|


## 10. Замечания автора по существу работы

Замечаний, жалоб, заявлений, предложения по лабораторной работе не имею.

## 11. Выводы

На данной лабораторной работе смог научиться ызаимодействовать с удаленными серверами при помощи сетевых команд OC UNIX. Считаю, полученные мной знания, пригодятся мне в будущей работе, так как взаимодействие с удаленными серверами очень важный навык, ведь как говорил Козьма Прутков: "Компьютер без сети подобен телефону, не включенному в розетку".

