#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

void enqueueFCFS(Queue *q, int processID, int burstTime)
{
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
    Queue *q = createQueue();
    enqueueFCFS(q, 1, 10);
    enqueueFCFS(q, 2, 5);
    enqueueFCFS(q, 3, 8);
    calculateWaitTime(q);
    calculateTurnAroundTime(q);
    showQueue(q);
    deleteQueue(q);
}