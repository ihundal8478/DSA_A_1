#pragma once
#ifndef QUEUE_H
#define QUEUE_H
// Structure to store information about a game user
typedef struct
{
    char username[11];  // Stores username (10 characters + null terminator)
    int level;// User level from 1 to 60
    char faction[10];
} User;
// Structure for each node in the linked list queue
typedef struct QueueNode
{
    User data; // Stores a User object
    struct QueueNode* next;// Pointer to the next node
} QueueNode;
// Queue structure containing pointers to the first and last nodes
typedef struct
{
    QueueNode* head;// Points to the front of queue
    QueueNode* tail;// Points to the end of queue
} Queue;

void initQueue(Queue* q); // Creates an empty queue
int isEmpty(Queue* q); // Checks whether queue is empty
int enqueue(Queue* q, User user);// Adds a user to the end of queue
User dequeue(Queue* q);// Adds a user to the end of queue
int addRandomUsers(Queue* q, int count);// Creates random users and adds them to queue
#endif
