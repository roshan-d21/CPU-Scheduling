#include <stdio.h>
#include <stdlib.h>
#include "queue.c"

void calculateWaitTime(Queue *q)
{
    node *ptr = q->front;
    if (ptr == NULL)
        return;
    while (ptr->next != NULL)
    {
        ptr->next->waitTime = ptr->waitTime + ptr->burstTime;
        ptr = ptr->next;
    }
}

void calculateTurnAroundTime(Queue *q)
{
    node *ptr = q->front;
    if (ptr == NULL)
        return;
    while (ptr!= NULL)
    {
        ptr->turnAroundTime = ptr->burstTime + ptr->waitTime;
        ptr = ptr->next;
    }
}

void fcfs()
{
    Queue *q = createQueue();
    enqueue(q, 1, 10);
    enqueue(q, 2, 5);
    enqueue(q, 3, 8);
    calculateWaitTime(q);
    calculateTurnAroundTime(q);
    showQueue(q);
    deleteQueue(q);
}