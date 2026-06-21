#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"

void initQueue(Queue* q)
{
    q->head = NULL;
    q->tail = NULL;
}

int isEmpty(Queue* q)
{
    return q->head == NULL;
}