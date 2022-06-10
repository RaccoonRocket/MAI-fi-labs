#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "functions.h"

length = 0;
cond = 0;
help = 0;

int reader(FILE *in, Student *person)
{
    fscanf(in, "%s", person->Name);
    fscanf(in, "%s", person->Initials);
    fscanf(in, "%s", &person->gender);
    fscanf(in, "%d", &person->group);
    fscanf(in, "%d", &person->math);
    fscanf(in, "%d", &person->rus);
    fscanf(in, "%d", &person->phis);
    fscanf(in, "%d", &person->info);
}

List *create(List *stips, Student *person)
    {
    List *temp = malloc(sizeof(List));
    temp->next = NULL;
    temp->prev = NULL;
    temp->person = *person;
    stips = temp;
    length++;
    return stips;
}

List *add(List *stips, Student *person)
{
    List *temp = malloc(sizeof(List));
    temp->next = NULL;
    temp->prev = stips;
    temp->person = *person;
    stips->next = temp;
    stips = temp;
    length++;
    return stips;
}

void printer(List *element)
{
    Student man;
    if (length != 0) {
    while (element -> prev != NULL) {
        element = element -> prev;
    }
    man = element->person;
    printf("%s ", man.Name);
    printf("%s\n", man.Initials);
    while (element -> next != NULL) {
        element = element -> next;
        man = element->person;
        printf("%s ", man.Name);
        printf("%s\n", man.Initials);
        }
    }
}


int pop(struct st** HEAD)
{
    struct st* TMP;
    int help_var;
    if (*HEAD == NULL) {
        return '\0';
    }
    TMP = *HEAD;
    help_var = TMP -> val;
    *HEAD = TMP -> next;
    free(TMP);
    return help_var;
}

void print_st(struct st* st) {
    help = st -> val;
    printf("%d ", help);
    if (st -> next != NULL) print_st(st -> next);
}
