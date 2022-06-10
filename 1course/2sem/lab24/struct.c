#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "struct.h"


int help;
int length = 0;

struct st* push(struct st* HEAD, char a)
{
    struct st* TMP;
    if ((TMP = malloc(sizeof(struct st))) == NULL)
    {
        printf("Нет памяти");
    }
    TMP -> val = a;
    TMP -> next = HEAD;
    return TMP;
}

char pop(struct st* HEAD)
{
    struct st* TMP;
    char help_var;
    if (*HEAD == NULL) {
        return '\0';
    }
    TMP = *HEAD;
    help_var = TMP -> val;
    *HEAD = TMP -> next;
    free(TMP);
    return help_var;
}
/*---------------------------------*/
int operand(char cur)
{
    switch(cur)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return 1;
    }
    return 0;
}
/*---------------------------------*/
int prior(char s)
{
    switch(s)
    {
     case '*':
     case '/':
        return 3;
     case '+':
     case '-':
        return 2;
     case '(':
        return 1;
    }
    return 0;
}
/*---------------------------------*/
char last_st(struct st* op) {
    char s;
    if (op == NULL) return 0;
    s = op -> val;
    return s;
}
/*---------------------------------*/
void print_st(struct st* st) {
    help = st -> val;
    printf("%c ", help);
    if (st -> next != NULL) print_st(st -> next);
}
/*---------------------------------*/

st *polish_back() {
    char symbol, c;
    st *result = NULL, *opers = NULL; // результ - стек с обр польской записью; оперс - промежуточный стек для операндов
    while ((symbol = getchar()) != '\n') {
            if (symbol == ' ') continue; // избавляемся от пробелов
            if (symbol == '(') {
                opers = push(opers, symbol); // видим ( - заносим в стек с операторами
            } if (symbol == ')') {
                while ((opers->val) != '(') { // видим ) - выталкиваем операнды до тех пор, пока не дойдем до (
                    result = push(result, pop(&opers));
                }
                c = pop(&opers); // избавляемся от (
            } if (isdigit(symbol) || isalpha(symbol)) { // числа и переменные добавляем в стек результата
                result = push(result, symbol);
                ++length;
            } if (operand(symbol)) { // видим операнд - сравниваем с крайним в стеке оперс
                c = last_st(opers); // 'с' - крайний операнд в стеке оперс
                if (prior(symbol) <= prior(c)) result = push(result, pop(&opers)); // если приоритет <= приоритета 'с' - выталкиваем 'с' в результ
                opers = push(opers, symbol);
                ++length;
            }
    }
    while (opers != NULL) { //  выталкиваем оставшиеся операнды
        c = pop(&opers);
        result = push(result, c);
    }
    if (result == NULL) return 0;
    printf("polish: ");
    print_st(result);
    printf("\n\n");
    return result;
}
