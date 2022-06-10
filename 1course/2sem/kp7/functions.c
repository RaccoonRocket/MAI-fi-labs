#include <stdio.h>
#include <float.h>
#include "functions.h"


void task_1(int str, int stolb, float mtx1[str][stolb], float mtx_task[str][stolb])
{
    float scan, t, number;
    printf("Enter the element: ");
    scanf("%f", &scan);
    printf("\n");
    float difference = FLT_MAX;
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stolb; j++) {
            if (mtx1[i][j] > scan) {
                t = mtx1[i][j] - scan;
            } else {
                t = scan - mtx1[i][j];
            }
            if (t < difference) {
                difference = t;
                number = mtx1[i][j];
            }
        }
    }
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stolb; j++) {
            mtx_task[i][j] = mtx1[i][j];
        }
    }
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stolb; j++) {
            if (mtx1[i][j] == number) {
                for (int k = 0; k < stolb; k++) {
                    mtx_task[i][k] /= number;
                }
                for (int k = 0; k < stolb; k++) {
                    mtx_task[k][j] /= number;
                }
            }
        }
    }
    printf("Matrix by task:\n");
    for (int i = 0; i < str; i++) {
        for (int j = 0; j < stolb; j++) {
            printf("%.3f ", mtx_task[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int make_vectors(int jitter, int str, int stolb, float mtx1[str][stolb])
{
    float helper;
    int qs = jitter;
    int vec1[str];
    int vec2[jitter+1];
    float vec3[jitter];
    for (int i = 0; i < str; i++)
        vec1[i] = 0;
    for (int i = 0; i < jitter; i++) {
        vec2[i] = 0;
        vec3[i] = 0;
    }
    vec2[jitter] = 0;
    jitter--;
    for (int i = str - 1; i >= 0; i--) {
        for (int j = stolb - 1; j >= 0; j--) {
            helper = mtx1[i][j];
            if (helper != 0) {
                vec3[jitter] = helper;
                vec2[jitter] = j + 1;
                jitter--;
                if ((vec1[i] >= j+1) || (vec1[i] == 0)) {
                    vec1[i] = j+1;
                }
            }
        }
    }
    printf("vectors are\n");
    for (int i = 0; i < str; i++)
        printf("%d ", vec1[i]);
    printf("\n");
    for (int i = 0; i <= qs; i++)
        printf("%d ", vec2[i]);
    printf("\n");
    for (int i = 0; i < qs; i++)
        printf("%.3f ", vec3[i]);
    printf("\n\n");
}


int make_task_1(int jitter, int str, int stolb, float mtx_task[str][stolb]) {
    int count = 0, sum = jitter*2+str+1, cfp = jitter+str+1, c_cfp = 0;
    float helper;
    int vec1[str], position[cfp];
    float vec2[sum];

    for (int i = 0; i < str; i++)
        vec1[i] = 0;

    for (int i = 0; i < cfp; ++i)  // необязательно
        position[i] = 0;

    for (int i = 0; i < str; ++i) {
        for (int  j = 0; j < stolb; ++j) {
            helper = mtx_task[i][j];
            if (helper != 0) {
                position[c_cfp++] = count;
                vec2[count++] = j+1;
                vec2[count++] = helper;
                if (vec1[i] == 0) {
                    vec1[i] = j+1;
                }
            }
        }
        vec2[count++] = 0;
        position[c_cfp++] = count-1;
    }
    vec2[count++] = 0;
    position[c_cfp++] = count-1;

    printf("Task`s vector are\n");
    for (int i = 0; i < str; ++i) {
        printf("%d ", vec1[i]);
    }
    printf("\n");

    c_cfp = 0;
    for (int i = 0; i < sum; ++i) {
        if (position[c_cfp] == i) {
            printf("%d ", (int)vec2[i]);
            ++c_cfp;
        } else {
            printf("%.3f ", vec2[i]);
        }
    }
    printf("\n");
}
