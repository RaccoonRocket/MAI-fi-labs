#include <stdio.h>
#include "functions.h"
#include "matrix.h"
#include "functions.c"
#include "matrix.c"
#include <float.h>

int main(void)
{
    FILE *in = fopen("in.txt", "r");
    int str, stolb, jitter = 0;
    float a;
    fscanf(in, "%d", &str);
    fscanf(in, "%d", &stolb);
    Matx *result_matrix = NULL;
    float mtx1[str][stolb], stolbec[stolb];
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stolb; j++) {
            fscanf(in, "%f", &a);
            mtx1[i][j] = a;
            if (a != 0)
                jitter++;
            result_matrix = add_matrix(result_matrix, a);
        }
    }
    print_matrix(stolb);
    //===================================================
    printf("Original ");
    make_vectors(jitter, str, stolb, mtx1);
    //===================================================
    float mtx_task[str][stolb];
    task_1(str, stolb, mtx1, mtx_task);
    //===================================================
    printf("Task`s ");
    make_vectors(jitter, str, stolb, mtx_task);
    //===================================================
    make_task_1(jitter, str, stolb, mtx_task);
    //===================================================
    return 0;
}
