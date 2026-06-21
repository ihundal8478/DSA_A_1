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
void enqueue(Queue* q, User user);
void dequeue(Queue* q, User user);
int addRandomUsers(Queue* q, int count);
#endif
