#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

/* Calculates wait time for all processes in a Queue
 * Wait time is the amount of time a process needs to wait before it is executed on the CPU
 * The wait time of the first process is zero
 * The wait time of a process is the sum of the wait time and burst time of the previous process
 *           waitTime[ i ] = waitTime[ i - 1 ] + burstTime[ i - 1 ]
 */
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

/* Calculates turnaround time for all processes in a Queue
 * Turnaround time is the time interval from the submission of a process to the completion of the process
 * The turnaround time of a process is the sum of the wait time and burst time of the process
 *           turnAroundTime[ i ] = waitTime[ i ] + burstTime[ i ]
 */
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