#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

#define quantum 1

// A basic enqueue implementation
void enqueueRoundRobin(Queue *q, int processID, int burstTime, int waitTime, int turnAroundTime)
{
    node *new = newnode(processID, burstTime, 0);
    new->waitTime = waitTime;
    new->turnAroundTime = turnAroundTime;

    if (!q->front)
    {
        q->front = q->rear = new;
        return;
    }
    else
    {
        q->rear->next = new;
        q->rear = q->rear->next;
    }
}

/*
 * Overview of Round-Robin Scheduling:
 *
 * The incoming processes are enqueued together.
 * Each process is allocated some time (aka. quantum) on the CPU.
 * Regardless of whether a process was fully completed, at the end of the quantum, the current process is added to the end of the queue and the process next-in-line is allowed time on the CPU.
 * When a process is completed, it gets dequeued.
 */
void roundRobin(int numberOfProcesses, int *processIDs, int *burstTimes)
{
    printf("Round Robin Scheduling:\n\n");
    Queue *q = createQueue();
    Queue *qCopy = createQueue();   // A queue created solely to store the output (becasue the original queue becomes fully empty after round-robin scheduling)

    for (int i = 0; i < numberOfProcesses; i++)
    {
        enqueueRoundRobin(q, processIDs[i], burstTimes[i], 0, 0);
    }
    // enqueueRoundRobin(q, 1, 3, 0, 0);
    // enqueueRoundRobin(q, 2, 4, 0, 0);
    // enqueueRoundRobin(q, 3, 3, 0, 0);

    // Perform round robin scheduling as long as there are processes to be executed
    while (q->front)
    {
        q->front->currentBurstTime -= quantum;

        node *temp = q->front->next;
        while (temp)
        {
            temp->waitTime += quantum;
            temp = temp->next;
        }

        if (q->front->currentBurstTime <= 0)
        {
            enqueueRoundRobin(qCopy, q->front->processID, q->front->burstTime, q->front->waitTime, 0);
            dequeue(q);
        }
        else if (q->front->processID != q->rear->processID)
        {
            // More than one process left, so move the first to the end
            q->rear->next = q->front;
            q->rear = q->rear->next;
            q->front = q->front->next;
            q->rear->next = NULL;
        }
    }

    calculateTurnAroundTime(qCopy);

    showQueue(qCopy);

    deleteQueue(q);
    deleteQueue(qCopy);
}