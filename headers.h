#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int processID;
    int burstTime;
    int currentBurstTime;
    int waitTime;
    int turnAroundTime;
    int priority;
    struct node *next;
}node;

typedef struct Queue
{
    node *front, *rear;
}Queue;

node *newnode(int processID, int burstTime, int priority);

Queue *createQueue();

void enqueueFCFS(Queue *q, int processID, int burstTime);

void enqueueSJF(Queue *q, int processID, int burstTime);

void enqueuePriority(Queue *q, int processID, int burstTime, int priority);

void enqueueRoundRobin(Queue *q, int processID, int burstTime, int waitTime, int turnAroundTime);

node *dequeue(Queue *q);

void showQueue(Queue *q);

void deleteQueue(Queue *q);

void calculateWaitTime(Queue *q);

void calculateTurnAroundTime(Queue *q);

void fcfs(int numberOfProcesses, int *processIDs, int *burstTimes);

void sjf(int numberOfProcesses, int *processIDs, int *burstTimes);

void priority(int numberOfProcesses, int *processIDs, int *burstTimes, int *priorities);

void roundRobin(int numberOfProcesses, int *processIDs, int *burstTimes);