#include <stdio.h>
#include <stdlib.h>
#include "headers.h"

int main()
{
    int testCases;
    int i = 0;
    scanf("%d", &testCases);
    printf("================================================================================\n");

    while (i < testCases) {
        int numberOfProcesses;
        scanf("%d", &numberOfProcesses);
        printf("Process List %d: \n\n", ++i);

        int *processIDs = malloc(sizeof(int) * numberOfProcesses);
        int *burstTimes = malloc(sizeof(int) * numberOfProcesses);
        int *priorities = malloc(sizeof(int) * numberOfProcesses);

        for (int i = 0; i < numberOfProcesses; i++)
        {
            scanf("%d", &processIDs[i]);
            scanf("%d", &burstTimes[i]);
            scanf("%d", &priorities[i]);

        }

        fcfs(numberOfProcesses, processIDs, burstTimes);
        printf("--------------------------------------------------------------------------------\n");
        sjf(numberOfProcesses, processIDs, burstTimes);
        printf("--------------------------------------------------------------------------------\n");
        priority(numberOfProcesses, processIDs, burstTimes, priorities);
        printf("--------------------------------------------------------------------------------\n");
        roundRobin(numberOfProcesses, processIDs, burstTimes);

        printf("================================================================================\n");
    }
    return 0;
}