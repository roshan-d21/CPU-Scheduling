#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

node *newnode(int processID, int burstTime, int priority)
{
    node *n = (node *)malloc(sizeof(node));
    n->processID = processID;
    n->burstTime = burstTime;
    n->currentBurstTime = burstTime;
    n->priority = priority;
    n->waitTime = 0;
    n->turnAroundTime = 0;
    n->next = NULL;
    return n;
}

Queue *createQueue()
{
    Queue *newqueue = (Queue *)malloc(sizeof(Queue));
    newqueue->front = newqueue->rear = NULL;
    return newqueue;
}

// void enqueue(Queue *q, int processID, int burstTime, int priority)
// {
//     node *temp = newnode(processID, burstTime, priority);
//     if (q->rear == NULL)
//     {
//         q->rear = q->front = temp;
//     }
//     else
//     {
//         q->rear->next = temp;
//         q->rear = temp;
//     }
// }

node *dequeue(Queue *q)
{
    if (q->front == NULL)
    {
        return NULL;
    }
    else
    {
        node *temp = q->front;
        q->front = q->front->next;
        if (q->front == NULL)
        {
            q->rear = NULL;
        }
        return temp;
    }
}

/* Prints the queue in the following format:
 *  Process ID, Burst Time, Wait Time, Turnaround Time, Priority
 */
void showQueue(Queue *q)
{
    node *ptr = q->front;
    if (ptr == NULL)
    {
        printf("EMPTY\n");
        return;
    }
    printf("Process ID\tBurst Time\tWait Time\tTurnaround Time\tPriority\n");
    while (ptr != NULL)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", ptr->processID, ptr->burstTime, ptr->waitTime, ptr->turnAroundTime, ptr->priority);
        ptr = ptr->next;
    }
    printf("\n");
}

void deleteQueue(Queue *q)
{
    node *temp;
    while((temp = dequeue(q)) != NULL)
        free(temp);
    free(q);
}