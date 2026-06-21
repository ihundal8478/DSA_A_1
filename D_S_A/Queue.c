#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"

void initQueue(Queue* q)
{
    q->head = NULL;
    q->tail = NULL;
}

int isEmpty(Queue* q)
{
    return q->head == NULL;
}
void enqueue(Queue* q, User user) {
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
    if (newnode == NULL) {
        return 1;
    }
    newnode->data = user;
    newnode->next = NULL;
    if (isEmpty(q)) {
        q->head = newnode;
        q->tail = newnode;
    }
    else {
        q->tail->next = newnode;
        q->tail = newnode;
    }

}