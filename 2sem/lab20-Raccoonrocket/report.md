# Отчет по лабораторной работе N 20 по курсу
# "Фундаментальная информатика"

Студент группы: M80-104Б, Борисов Сергей Павлович\
Контакты: 9802432172sergei@gmail.com\
Работа выполнена: 25.02.2022\
Преподаватель: Безлуцкая Елизавета Николаевна

## 1. Тема

Стандартный утилиты UNIX для обработки файлов.

## 2. Цель работы

Изучение и освоение программного обеспечения ОС UNIX и приобретение навыков, необходимых для выполнения курсовых и лабораторных работ в среде UNIX.

## 3. Задание

Изучить и освоить ОС Unix, написать осмысленный сценарий использования команд, занести результаты работы в протокол.

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
Местонахождение и имена файлов программ и данных на домашнем компьютере: **F:\Ubuntu 20.04**

## 6. Идея, метод, алгоритм решения задачи

В данной лабораторной работе, мной задумано было создать ряд команд, который включал бы в себя как можно больше их количество, изученных самостоятельно и на занятиях, не забывая применять флаги.

## 7. Сценарий выполнения работы

1. Скопировать несколько файлов в созданный временный каталог
2. Использовать утилиты сравнения файлов
3. Попробовать реализовать редактирование файла при помощи встроенного редактора
4. Произвести контроль занятого/свободного пространства на диске
5. Изменить кодировку файла
6. Разделить файл на несколько частей, затем заново собрать, при этом проверить файл на целостность (контроль суммы)
7. Архивировать файлы, сжать, при этом следить за занимаемым ими местом

## 8. Распечатка протокола

~~~
raccoonrocket@raccoonrocket-VirtualBox:~$ mktemp -d
/tmp/tmp.U32kr9ACJR
raccoonrocket@raccoonrocket-VirtualBox:~$ cp kp3.c test.c /tmp/tmp.U32kr9ACJR
raccoonrocket@raccoonrocket-VirtualBox:~$ cd /tmp/tmp.U32kr9ACJR
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ ls
kp3.c test.c
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ diff -u kp3.c test.c > different_file.txt
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ du -a
4 ./different_file.txt
4 ./test.c
4 ./kp3.c
16 .
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ ls
different_file.txt kp3.c test.c
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ df
Файл.система 1K-блоков Использовано Доступно Использовано% Cмонтировано в
udev 1976632 0 1976632 0% /dev
tmpfs 402024 1420 400604 1% /run
/dev/sda5 19475088 12413264 6049500 68% /
tmpfs 2010100 0 2010100 0% /dev/shm
tmpfs 5120 4 5116 1% /run/lock
tmpfs 2010100 0 2010100 0% /sys/fs/cgroup
/dev/loop0 128 128 0 100% /snap/bare/5
/dev/loop1 56832 56832 0 100% /snap/core18/2253
/dev/loop2 66688 66688 0 100% /snap/gtk-common-themes/1515
/dev/loop3 52224 52224 0 100% /snap/snap-store/547
/dev/loop4 253952 253952 0 100% /snap/gnome-3-38-2004/87
/dev/loop5 66816 66816 0 100% /snap/gtk-common-themes/1519
/dev/loop6 224256 224256 0 100% /snap/gnome-3-34-1804/72
/dev/loop7 44672 44672 0 100% /snap/snapd/14978
/dev/loop8 224256 224256 0 100% /snap/gnome-3-34-1804/77
/dev/loop9 56960 56960 0 100% /snap/core18/2284
/dev/loop10 254848 254848 0 100% /snap/gnome-3-38-2004/99
/dev/loop11 63488 63488 0 100% /snap/core20/1361
/dev/loop12 55552 55552 0 100% /snap/snap-store/558
/dev/loop13 63488 63488 0 100% /snap/core20/1328
/dev/sda2 524272 4 524268 1% /boot/efi
tmpfs 402020 68 401952 1% /run/user/1000
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ wc -l different_file.txt
52 different_file.txt
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ ed
e different_file.txt
1661
1,5p
--- kp3.c 2022-02-25 15:53:57.244744873 +0300
+++ test.c 2022-02-25 15:53:57.244744873 +0300
@@ -7,30 +7,36 @@
return log(2 + arg);
example
5d
1,5p
--- kp3.c 2022-02-25 15:53:57.244744873 +0300
+++ test.c 2022-02-25 15:53:57.244744873 +0300
@@ -7,30 +7,36 @@
return log(2 + arg);
}
Q
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ ed different_file.txt
1661
50,52p
}
return 0;
}
a
example text
.
w
1674
Q
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ cat different_file.txt
--- kp3.c 2022-02-25 15:53:57.244744873 +0300
+++ test.c 2022-02-25 15:53:57.244744873 +0300
@@ -7,30 +7,36 @@
return log(2 + arg);
example
}
[остальная часть программы]

return 0;
}
example text
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ ls
different_file.txt kp3.c test.c
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ du -b different_file.txt
1674 different_file.txt
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ split -n 3 different_file.txt
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ ls
different_file.txt kp3.c test.c xaa xab xac
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ ls -lh x*
-rw-rw-r-- 1 raccoonrocket raccoonrocket 558 фев 25 17:03 xaa
-rw-rw-r-- 1 raccoonrocket raccoonrocket 558 фев 25 17:03 xab
-rw-rw-r-- 1 raccoonrocket raccoonrocket 558 фев 25 17:03 xac
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ cat x* > built.txt
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ cat built.txt
--- kp3.c 2022-02-25 15:53:57.244744873 +0300
+++ test.c 2022-02-25 15:53:57.244744873 +0300
@@ -7,30 +7,36 @@
return log(2 + arg);
example
}
-double function_taylor(double arg)

[остальная часть программы]

return 0;
}
example text
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ md5sum *.txt
8716d46670b09e2771b8d5d4d84aba31 built.txt
8716d46670b09e2771b8d5d4d84aba31 different_file.txt
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ ls
built.txt different_file.txt kp3.c test.c xaa xab xac
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ iconv -l
Следующий список содержит все известные встроенные кодировки. Это не
обязательно означает, что можно использовать любые комбинации данных
имён в параметрах командной строки FROM и TO. Одна и та же кодировка
может быть указана под несколькими именами (псевдонимами).

437, 500, [*all кодировка*], WS2, YU
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ file built.txt
built.txt: unified diff output, UTF-8 Unicode text
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ iconv -f UTF-8 -t UTF-16 built.txt -o rebuilt.txt
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ ls
built.txt different_file.txt kp3.c rebuilt.txt test.c xaa xab xac
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ file rebuilt.txt
rebuilt.txt: unified diff output, Little-endian UTF-16 Unicode text
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ cat rebuilt.txt
��--- kp3.c 2022-02-25 15:53:57.244744873 +0300
+++ test.c 2022-02-25 15:53:57.244744873 +0300
@@ -7,30 +7,36 @@
return log(2 + arg);
example
}
-double function_taylor(double arg)
+double function_taylor(double arg, double eps)
{
- double res = log(2) + (arg / 2), prev = (arg / 2), pres = 0.0;
- int iter = 1;
- for (iter; fabs(prev) > DBL_EPSILON && iter <= 100; ++iter) {
- pres = prev * (((-1) * arg * iter) / ((iter + 1) * 2));
+ double res = log(2), prev = log(2), pres = 0.0;
+ for(int iter = 1; iter <= 100 && prev < eps; ++iter) {
+ pres = prev * ((-arg) * iter / (iter + 1) / 2);
res += pres;
prev = pres;
}
- printf("|n = %d |", iter);
return res;
}
-int main(void)

[остальная часть программы]

return 0;
}
example text
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ du -b built.txt
1674 built.txt
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ du -b rebuilt.txt
3162 rebuilt.txt
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ sum rebuilt.txt
49162 4
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ tar -cf archive.tar rebuilt.txt
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ ls
archive.tar different_file.txt rebuilt.txt xaa xac
built.txt kp3.c test.c xab
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ du -b archive.tar
10240 archive.tar
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ bzip2 archive.tar
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ du -b archive.tar
du: невозможно получить доступ к 'archive.tar': Нет такого файла или каталога
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ ls
archive.tar.bz2 different_file.txt rebuilt.txt xaa xac
built.txt kp3.c test.c xab
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ du -b archive.tar.bz2
924 archive.tar.bz2
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ tar -cf archive_2.tar built.txt
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ du -b archive_2.tar
10240 archive_2.tar
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ bzip2 archive_2.tar
raccoonrocket@raccoonrocket-VirtualBox:/tmp/tmp.U32kr9ACJR$ du -b archive_2.tar.bz2
884 archive_2.tar.bz2
~~~

## 9. Дневник отладки
```
|№|Лаб.или дом| Дата     |Время| Событие                                          | Действие по исправлению                |
|0|    Дом    |25.02.2022|17:00| Редактирование и выход в/из строкового редактора | Изучение работы и команд данной утилиты|
```

## 10. Замечания автора по существу работы
Замечаний, жалоб, предложения по данной лабораторной работе не имею.

## 11. Выводы
Я в достаточной мере преисполнился в освоении OC Unix и уверен, что полученные знания, в ходе выполнения лабораторной работы, пригодятся мне в будущем.\
Итог: Выполнение лабораторной работы заняло относительно немного времени, так как в данной среде уже имеется маленький опыт работы (лаб. 2, 3). 
