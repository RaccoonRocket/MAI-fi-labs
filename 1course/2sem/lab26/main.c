#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "sort.h"

int main() {
    int c = 0, size = 0;
    Queue *Q = NULL;
    printf("Queue size: ");
    scanf("%d", &size);
    printf("Print queue: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &c);
        Q = add(Q, c);
    }
    for (int i = 0; i < size; i++) Q = sort(Q);
    for (int i = 0; i < size; i++) printf("%d\n", reseive(&Q));
    return 0;
}
