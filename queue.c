#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int processID;
    int burstTime;
    int waitTime;
    int turnAroundTime;
    struct node *next;
}node;

typedef struct Queue
{
    node *front, *rear;
}Queue;

node *newnode(int processID, int burstTime)
{
    node *n = (node *)malloc(sizeof(node));
    n->processID = processID;
    n->burstTime = burstTime;
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

void enqueue(Queue *q, int processID, int burstTime)
{
    node *temp = newnode(processID, burstTime);
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

void showQueue(Queue *q)
{
    node *ptr = q->front;
    if (ptr == NULL)
    {
        printf("EMPTY\n");
        return;
    }
    printf("Process ID\tBurst Time\tWait Time\tTurnaround Time\n");
    while (ptr != NULL)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\n", ptr->processID, ptr->burstTime, ptr->waitTime, ptr->turnAroundTime);
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