#pragma once
#ifndef QUEUE_H
#define QUEUE_H

typedef struct
{
    char username[11];
    int level;
    char faction[10];
} User;

typedef struct QueueNode
{
    User data;
    struct QueueNode* next;
} QueueNode;

typedef struct
{
    QueueNode* head;
    QueueNode* tail;
} Queue;

void initQueue(Queue* q);
int isEmpty(Queue* q);
int enqueue(Queue* q, User user);
User dequeue(Queue* q);
int addRandomUsers(Queue* q, int count);
#endif
