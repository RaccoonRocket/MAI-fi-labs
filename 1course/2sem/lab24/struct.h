#ifndef _STACK_H_
#define _STACK_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct st
{
    char val;
    struct st* next;
}st;

struct st* push(struct st* HEAD, char a);
char pop(stract st** HEAD);
int operand(char cur);
int prior(char s);
char last_st(struct st* op);
void print_st(struct st* st);
st *polish_back();

#endif
