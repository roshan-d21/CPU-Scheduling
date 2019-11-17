#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

void enqueueSJF(Queue *q, int processID, int burstTime)
{
    node *newNode = newnode(processID, burstTime, 0);
    if (q->rear == NULL)
    {
        q->rear = q->front = newNode;
    }
    else
    {
        if (newNode->burstTime < q->front->burstTime)
        {
            newNode->next = q->front;
            q->front = newNode;
        }
        else if (newNode->burstTime > q->rear->burstTime)
        {
            q->rear->next = newNode;
            q->rear = q->rear->next;
        }
        else
        {
            node *ptr = q->front, *prev = NULL;
            while (ptr->next != NULL && newNode->burstTime > ptr->burstTime)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = newNode;
            newNode->next = ptr;
        }
    }
}

void sjf()
{
    Queue *q = createQueue();
    enqueueSJF(q, 1, 10);
    enqueueSJF(q, 2, 5);
    enqueueSJF(q, 3, 8);
    calculateWaitTime(q);
    calculateTurnAroundTime(q);
    showQueue(q);
    deleteQueue(q);
}