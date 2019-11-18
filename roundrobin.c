#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

#define quantum 1

void enqueueRoundRobin(Queue *q, int processID, int burstTime, int waitTime, int turnAroundTime)
{
    node *new = newnode(processID, burstTime, 0);
    new->waitTime = waitTime;
    new->turnAroundTime = turnAroundTime;

    if (!q->front) {
        q->front = q->rear = new;
        return;
    } else {
        q->rear->next = new;
        q->rear = q->rear->next;
    }
}

void roundRobin()
{
    printf("Round Robin Scheduling:\n\n");
    Queue *q = createQueue();
    Queue *qCopy = createQueue();

    enqueueRoundRobin(q, 1, 10, 0, 0);
    enqueueRoundRobin(q, 2, 5, 0, 0);
    enqueueRoundRobin(q, 3, 8, 0, 0);

    // Perform round robin here
    while (q->front) {
        q->front->currentBurstTime -= quantum;

        node *temp = q->front->next;
        while (temp) {
            temp->waitTime += quantum;
            temp = temp->next;
        }

        if (q->front->currentBurstTime <= 0) {
            enqueueRoundRobin(qCopy, q->front->processID, q->front->burstTime, q->front->waitTime, q->front->burstTime + q->front->waitTime);
            dequeue(q);
        } else {
            if (q->front->processID != q->rear->processID) {
                // More than one process left, so swap the first and last
                q->rear->next = q->front;
                q->rear = q->rear->next;

                node *newFront = malloc(sizeof(node));
                newFront = q->front->next;

                q->rear->next = NULL;
                q->front = newFront;
            }
        }
    }

    showQueue(qCopy);
    deleteQueue(q);
    deleteQueue(qCopy);
}