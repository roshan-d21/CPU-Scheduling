#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

/*
 * Processes are enqueued based on the priorities assigned to them
 * Processes are inserted in the decreasing order of their priorities
 * The process with the highest priority is pointed to by q->front
 * The process with the lowest priority is pointed to by q->rear
 */
void enqueuePriority(Queue *q, int processID, int burstTime, int priority)
{
    // create new queue node
    node *newNode = newnode(processID, burstTime, priority);

    // if queue is empty
    if (q->rear == NULL)
    {
        q->rear = q->front = newNode;
    }
    else
    {
        // if the priority of the new process is greater than that of the process currently in the front of the queue
        if (newNode->priority > q->front->priority)
        {
            newNode->next = q->front;
            q->front = newNode;
        }

        // if the priority of the new process is less than that of the process currently in the end of the queue
        else if (newNode->priority <= q->rear->priority)
        {
            q->rear->next = newNode;
            q->rear = q->rear->next;
        }

        else
        {
            node *ptr = q->front, *prev = NULL;
            while (ptr->next != NULL && newNode->priority < ptr->priority)
            {
                prev = ptr;
                ptr = ptr->next;
            }
            prev->next = newNode;
            newNode->next = ptr;
        }
    }
}

void priority(int numberOfProcesses, int *processIDs, int *burstTimes, int *priorities)
{
    printf("Priority Based Scheduling:\n\n");
    Queue *q = createQueue();

    for (int i = 0; i < numberOfProcesses; i++)
    {
        enqueuePriority(q, processIDs[i], burstTimes[i], priorities[i]);
    }

    calculateWaitTime(q);
    calculateTurnAroundTime(q);
    showQueue(q);
    deleteQueue(q);
}