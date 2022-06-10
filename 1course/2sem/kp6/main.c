#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "functions.h"
#include "functions.c"


int main(int argc, char *argv[]) {
    int group = 0, q = 0;
    FILE *in = fopen("Database.bin", "r");
    FILE *out = fopen("Output.bin", "wb");
    if((!in)||(!out))
    printf("Error, can't open file\n");
    Student person;
    List *stips = NULL, *result = NULL;
    st *numbers = NULL; // memorize F with the maximum score
    int c; // for trash
    printf("=====================================================================\n");
    printf("Фамилия\t|И.О.\t|Пол\t|№ гр.\t|Math\t|Russian|Phisics|Inf\t|Sum|\n");
    printf("=====================================================================\n");
    int sum = 0, sum_max = 0;
    int step = 0;
    while (feof(in) == 0) {
        if (person.Name == NULL) break;
        reader(in, &person);
        sum = person.math + person.rus + person.phis + person.info;
        person.sum = sum;
        if (person.gender == 'F') {
            if (sum == sum_max) {
                numbers = push(numbers, step+1);
            }
            if (sum > sum_max) {
                while (numbers != NULL) {
                    c = pop(&numbers);
                }
                sum_max = sum;
                numbers = push(numbers, step+1);
            }
        }
        printf( "%s\t|", person.Name);
        printf( "%s\t|", person.Initials);
        printf( "%s\t|", &person.gender);
        printf( "%d\t|", person.group);
        printf( "%d\t|", person.math);
        printf( "%d\t|", person.rus);
        printf( "%d\t|", person.phis);
        printf( "%d\t|", person.info);
        printf( "%d|\n", sum);
        ++step;
        if (stips == NULL) {
            stips = create(stips, &person);
        } else {
            stips = add(stips, &person);
        }
    }
    printf("=====================================================================\n");
    if (numbers == NULL) {
        printf("Студенток не найдено(");
        return 0;
    }
    int step_result = 0;
    c = pop(&numbers);
    if (c == step) {
        stips = stips->prev;
        person = stips->person;
        --step;
    } else {
        numbers = add(numbers, c);
    }
    int Array[step];
    int counter = step;
    while (counter > 0) {
        if (numbers == NULL) {
            break;
        }
        c = pop(&numbers);
        while (counter != c) {
            stips = stips->prev;
            person = stips->person;
            --counter;
        }
        if (result == NULL)
            result = create(result, &person);
        else
            result = add(result, &person);
        Array[step_result] = person.group;
        ++step_result;
    }
    printf("\nСтудентки с max ср. баллом:\n");
    printer(result);
    printf("\n");

    int BiggestCounter = 0, CurrentCounter = 0, FrequentEl;

    for (int i = 0; i < step_result; i++)
    {
        for(int j = i; j < step_result; j++)
        {
            if(Array[i] == Array[j])
            {
                 CurrentCounter++;
            }
        }
        if(CurrentCounter > BiggestCounter)
        {
             BiggestCounter = CurrentCounter;
             FrequentEl = Array[i];
        }
        CurrentCounter = 0;
    }
    printf("Искомая группа: %d\n", FrequentEl);

    person = result->person;
    counter = step_result;
    printf("\nЛюди, прошедшие выборку:\n");
    while (counter > 0) {
        if (person.group == FrequentEl) {
            printf("%s %s %s %d %d %d %d %d\n", person.Name, person.Initials, &person.gender, person.group, person.math, person.rus, person.phis, person.info);
            fprintf(out, "%s %s %s %d %d %d %d %d\n", person.Name, person.Initials, &person.gender, person.group, person.math, person.rus, person.phis, person.info);
        }
        if (counter == 1) break;
        result = result->prev;
        person = result->person;
        --counter;
    }
    fclose(in);
    fclose(out);
    free(stips);
    free(result);
    return 0;
}
