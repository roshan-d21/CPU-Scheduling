#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

/*
 * Processes are enqueued in the first come first serve manner
 * New processes are inserted in the rear
 * The first process is pointed to by q->front
 * The last process is pointed to by q->rear
 */
void enqueueFCFS(Queue *q, int processID, int burstTime)
{
    // create new queue node with priority = 0
    node *temp = newnode(processID, burstTime, 0);
    
    if (q->rear == NULL)
    {
        q->rear = q->front = temp;
    }
    else
    {
        q->rear->next = temp;
        q->rear = temp;
    }
}

void fcfs()
{
    printf("First Come First Serve:\n\n");
    Queue *q = createQueue();
    enqueueFCFS(q, 1, 10);
    enqueueFCFS(q, 2, 5);
    enqueueFCFS(q, 3, 8);
    calculateWaitTime(q);
    calculateTurnAroundTime(q);
    showQueue(q);
    deleteQueue(q);
}