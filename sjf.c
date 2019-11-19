#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

/*
 * Processes are enqueued in the Shortest Job First manner
 * Processes are inserted in the increasing order of their burst times
 * The process with the shortest job is pointed to by q->front
 * The process with the longest job is pointed to by q->rear
 */
void enqueueSJF(Queue *q, int processID, int burstTime)
{
    // create new queue node with priority = 0
    node *newNode = newnode(processID, burstTime, 0);

    // if queue is empty
    if (q->rear == NULL)
    {
        q->rear = q->front = newNode;
    }
    else
    {
        // if the burst time of the new process is less than that of the process currently in the front of the queue
        if (newNode->burstTime <= q->front->burstTime)
        {
            if (newNode->burstTime == q->front->burstTime) {
                newNode->next = q->front->next;
                q->front->next = newNode;
            } else {
            newNode->next = q->front;
            q->front = newNode;
            }
        }

        // if the burst time of the new process is greater than that of the process currently in the end of the queue
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

void sjf(int numberOfProcesses, int *processIDs, int *burstTimes)
{
    printf("Shortest Job First:\n\n");
    Queue *q = createQueue();
    for (int i = 0; i < numberOfProcesses; i++)
    {
        enqueueSJF(q, processIDs[i], burstTimes[i]);
    }

    calculateWaitTime(q);
    calculateTurnAroundTime(q);
    showQueue(q);
    deleteQueue(q);
}