#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <stdio.h>
#include <stdbool.h>

typedef struct _list {
    char key;
    struct List *next;
} List;

int length;
void printer(List *element);

List *add(List *element, char value);
List *delet(List *element, int number);
List *change(List *element, int number);

#endif // FUNCTIONS_H_INCLUDED
