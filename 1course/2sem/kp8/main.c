#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "function.h"
#include "function.c"

int main(void)
{
    List *element = NULL;
    printf("Выберите действие над списком, нажав соответствующую клавишу:\n");
    printf("1) Добавить элемент в список\n2) Удалить элемент из списка\n");
    printf("3) Вывести длину списка\n4) Вывести весь список\n");
    printf("5) Обменять местами (k-1) и (k+1) элементы списка\n6) Остановить программу\n");
    int switcher;
    int getter;
    char getter_char;
    while ((switcher = getchar()) != EOF) {
        switch(switcher) {
            case('1'):
                printf("Введите новый элемент \n");
                getter_char = getchar();
                scanf("%c", &getter_char);
                if (!isalpha(getter_char)) {
                    printf("Неверный ввод, повторите.\n");
                    break;
                }
                element = add(element, getter_char);
                printf("Готово. Вводите дальше.\n");
                break;
            case('2'):
                printf("Введите номер элемента, который нужно удалить.\n");
                scanf("%d", &getter);
                element = delet(element, getter);
                printf("Готово. Вводите дальше\n");
                break;
            case('3'):
                printf("Длина списка = %d\n", length);
                printf("Готово. Вводите дальше.\n");
                break;
            case('4'):
                printer(element);
                printf("Готово. Вводите дальше.\n");
                break;
            case('5'):
                if (length > 2) {
                    printf("Введите k\n");
                    printf("k = ");
                    scanf("%d", &getter);
                    printf("\n");
                    element = change(element, getter);
                } else if (length == 0) {
                    printf("Список пуст, менять нечего\n");
                } else {
                    printf("Список недостаточно большой, чтобы менять элементы\n");
                }
                printf("Готово. Вводите дальше.\n");
                break;
            case('6'):
                free(element);
                return 0;
                case('\n'):
                break;
            default:
                printf("Такого действия нет, повторите ввод.\n");
                break;
        }
    }
    return 0;
}
