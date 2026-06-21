#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Queue.h"

int main(int argc, char* argv[]) // main function that servers as the entry point of the program, which takes command line arguments for number of users to enqueue and process the queue accordingly
{
    if (argc != 2) // check the number of users entered by the user
    {
        printf("Usage: %s number_of_users\n",
            argv[0]);
        return 1;
    }

    int numUsers = atoi(argv[1]); // Convert command line argument into integer

    srand(time(NULL));// Initialize random number generator

    Queue q;// create queue variable 

    initQueue(&q); // Initialize empty queue
    // add random users to queue
    if (addRandomUsers(&q, numUsers) != 0)
    {
        printf("Error creating users\n");
        return 1;
    }

    while (!isEmpty(&q))     // Remove users until queue becomes empty
    {
        User u = dequeue(&q);
        // display removed user info
        printf("Username: %s\n", u.username);
        printf("Level: %d\n", u.level);
        printf("Faction: %s\n\n", u.faction);
    }

    return 0;
}