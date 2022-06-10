#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matx *mtx_guard;

Matx *add_matrix(Matx *element, float number)
{
    Matx *tmp = malloc(sizeof(Matx));
    tmp -> key = number;
    if (element) {
        element -> next = tmp;
        tmp -> next = NULL;
    } else {
        tmp -> next = NULL;
        mtx_guard = tmp;
    }
    element = tmp;
    return element;
}

void print_matrix(int stolb)
{
    Matx *runner = mtx_guard;
    int count = 0;
    printf("Original matrix is\n");
    while (runner->next) {
        printf("%.3f ", runner->key);
        runner = runner -> next;
        count++;
        if (count == stolb) {
            count = 0;
            printf("\n");
        }
    }
    printf("%.3f\n\n", runner->key);
}
