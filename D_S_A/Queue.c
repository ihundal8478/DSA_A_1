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
void dequeue(Queue* q, User * user) {
    if (q->head == NULL)
        return 1;
    QueueNode* temp = q->head;
    *user = temp->data;
    q->head = q->head->next;
    if (q->head == NULL)
        q->tail = NULL;
    free(temp);
    return 0;

}


static void generate_username(char username[]) {
    const char chars[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < 10; i++) {
        username[i] = chars[rand() % 36];
    }
    username[10] = '\0';
}

int addRandomUsers(Queue* q, int count)
{
    const char* factions[] =
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

        strcpy(u.faction,
            factions[rand() % 3]);

        enqueue(q, u);
    }

    return 0;
}