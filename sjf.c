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

void enqueueSJF(Queue *q, int processID, int burstTime)
{
    node *newNode = newnode(processID, burstTime);
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