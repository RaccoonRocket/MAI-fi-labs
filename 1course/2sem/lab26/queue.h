#ifndef LAB2526_QUEUE_H
#define LAB2526_QUEUE_H

typedef struct Queue {
  int val;
  struct Queue *next;
}Queue;

Queue *add(Queue *q, int element);
int receive(Queue **q);
void queue_destroy(Queue *q);

#endif
