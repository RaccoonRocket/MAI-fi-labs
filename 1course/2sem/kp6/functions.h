#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#define NAME_SIZE 30
#define INITIALS_SIZE 4

int length;
int cond;
int help;

typedef struct _student {
    char Name[NAME_SIZE];
    char Initials[NAME_SIZE];
    char gender;
    int group;
    int math;
    int rus;
    int phis;
    int info;
    int sum;
} Student;

typedef struct _list {
    Student person;
    Student *next;
    Student *prev;
} List;

int reader(FILE *in, Student *person);
List *create(List *stips, Student *person);
List *add(List *stips, Student *person);
void printer(List *element);


typedef struct st
{
    int val;
    struct st* next;
}st;

struct st* push(struct st* HEAD, int a)
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


#endif // FUNCTIONS_H_INCLUDED
