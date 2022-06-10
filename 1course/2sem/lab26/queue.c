#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

Queue *add(Queue *Q, int el) {
    Queue *q1 = (Queue*) malloc(sizeof(Queue));
    q1 -> val = el;
    q1 -> next = NULL;
    if (Q != NULL) {
        Queue *r = Q;
        while (r -> next != NULL)
            r = r -> next;
        r -> next = q1;
    } else {
        Q = q1;
    }
    return Q;
}

int receive(Queue **Q)
{
    int c = (*Q) -> val;
    Queue *q1 = *Q;
    (*Q) = (*Q) -> next;
    free(q1);
    return c;
}

int destroy(Queue *Q)
{
    Queue *q1 = Q;
    while (Q -> next != NULL) {
        Q = Q -> next;
        free(q1);
        q1 = Q;
    }
    free(q1);
    free(Q);
}
