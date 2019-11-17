#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

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