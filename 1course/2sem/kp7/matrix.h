#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED
#include <stdio.h>

typedef struct Matx {
    float key;
    struct Matx *next;
} Matx;
Matx *mtx_guard;
Matx *add_matrix(Matx *element, float number);
void print_matrix(int stolb);

#endif // MATRIX_H_INCLUDED
