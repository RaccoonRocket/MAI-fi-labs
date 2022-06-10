#include <stdlib.h>
#include <stdbool.h>

#include "sort.h"
#include "queue.h"

Queue *sort(Queue * Q) {
    Queue *q_next = Q -> next;
    Queue *q_val = Q;
    while (q_next -> next != NULL){
    if (q_val -> val > q_next -> val){
        int k = q_val -> val;
        q_val -> val = q_next -> val;
        q_next -> val = k;
    }
    q_val = q_next;
    q_next = q_next -> next;
    }
    if (q_val -> val > q_next -> val){
        int k = q_val -> val;
        q_val -> val = q_next -> val;
        q_next -> val = k;
    }
    return Q;
}
