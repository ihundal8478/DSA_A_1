#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Queue.h"
// Initializes a blank queue
void initQueue(Queue* q)
{
    q->head = NULL; // Both head and tail start as NULL
    q->tail = NULL;
}
// Checks if queue has no elements
// Returns 1 if empty, otherwise 0
int isEmpty(Queue* q)
{
    return q->head == NULL;
}
// Adds a new user to the rear of the queue
int enqueue(Queue* q, User user) {
    QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode)); // Allocates mempory for a new node
    if (newnode == NULL) { // Check if memeory allocation failed
        return 1;
    }
    newnode->data = user;  // Store user data inside the node
    newnode->next = NULL;   // New node will be last, so next is NULL
    if (isEmpty(q)) {  // If queue is empty, new node becomes first and last
        q->head = newnode;
        q->tail = newnode;
    }
    else {  // Otherwise add node after current tail
        q->tail->next = newnode;
        q->tail = newnode;
    }

}
User dequeue(Queue *q){ // Removes a user from the front of the queue
    User tempuser = { "",0,"" };// Default empty user
    if (isEmpty(q)) {   // If queue is empty, return empty user
        return tempuser;
    }
    QueueNode* temp = q->head; // Store current first node
    tempuser = temp->data;// Copy user data before deleting node
    q->head = q->head->next;// Move head to next node
    if (q->head == NULL)  // If queue becomes empty update tail
        q->tail = NULL;
    free(temp); // Free removed node memory
    return tempuser ; // Return removed user

}

// Generates a random username
static void generate_username(char username[]) {
    char chars[] = "abcdefghijklmnopqrstuvwxyz0123456789"; // characters allowed to generate username
    for (int i = 0; i < 10; i++) { // generate 10 random characters
        username[i] = chars[rand() % 36];
    }
    username[10] = '\0'; // add end of file character
}

int addRandomUsers(Queue* q, int count)
{
    char* factions[] =
    {
        "red",
        "blue",
        "green"
    };

    for (int i = 0; i < count; i++)
    {
        User u;

        generate_username(u.username); 

        u.level = rand() % 60 + 1;

        strcpy_s(u.faction,sizeof(u.faction),factions[rand() % 3]); // randomly assign factions

        enqueue(q, u);// add user to queue
    }

    return 0;
}