#include <stdio.h>
#include <stdbool.h>

#include "function.h"

length = 0;

void printer(List *element)
{
    if (length == 0) {
        printf("Список пуст");
    } else {
        List *tmp = element;
        for (int i = 1; i<=length; i++) {
            printf("%c ", tmp->key);
            if (tmp -> next)
                tmp = tmp -> next;
        }
    }
    printf("\n");
}

List *add(List *element, char value)
{
    List *tmp = malloc(sizeof(List));
    tmp -> key = value;
    tmp -> next = NULL;
    if (element) {
        List *runner = element;
        while (runner -> next) {
            runner = runner -> next;
        }
        runner -> next = tmp;
    } else {
        element = tmp;
    }
    length++;
    return element;
}

List *delet(List *element, int number)
{
    if (number > length) {
        printf("Элемента под этим номером нет в списке\n");
        return element;
    }
    if (number < 0) {
        printf("Выход за границы\n");
        return element;
    }
    if (number == 1) {
        if (length == 1) {
            element = NULL;
            free(element);
        } else {
            List *tmp = element;
            element = element -> next;
            tmp = NULL;
            free(tmp);
        }
    } else {
        List *tmp = element;
        for (int i = 1; i<number-1; i++) {
            tmp = tmp -> next;
        }
        List tester = *tmp;
        List *guard = tmp;
        if (tmp->next) {
            tmp = tmp -> next;
            guard -> next = tmp -> next;
            free(tmp);
        } else {
            free(tmp);
        }
    }
    length--;
    return element;
}

List *change(List *element, int number)
{
    if (number < 1 || number > length) {
        printf("Выход за границы списка\n");
        return element;
    } else if (number == 1 || number == length) {
        printf("В крайних точках нельзя поменять соседние элементы\n");
        return element;
    }
    char box1, box2;
    List *t1 = element, *t2 = element;
    for (int i = 1; i < number-1; i++) {
        t1 = t1->next;
    }
    box1 = t1->key;
    t1 = t1->next;
    t1 = t1->next;
    box2 = t1->key;
    t1->key = box1;
    for (int i = 1; i < number-1; i++) {
        t2 = t2->next;
    }
    t2->key = box2;
    return element;
}
