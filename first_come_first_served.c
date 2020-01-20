#include <stdio.h>

int main()
{
    int n, i, j, totalWait = 0, totalTurn = 0, sum = 0;
    int burstTime[100], waitTime[100], start[100], finish[100], turnTime[100];
    double avgWait, avgTurnTime;

    printf("\t\nFirst come first scheduling algorithm\n");

    printf("Number of processes: ");
    scanf("%d",&n);

    for(i = 0; i<n; i++)
    {
        printf("\nBurst time of process %d: ",i+1);
        scanf("%d",&burstTime[i]);
    }

    start[0] = 0;

    for(i = 0; i<n; i++)
    {
        sum = sum + burstTime[i];
        start[i+1] = sum;
        finish[i] = burstTime[i] + start[i];
        waitTime[i] = start[i];
        turnTime[i] = waitTime[i] + burstTime[i];
        totalWait+= waitTime[i];
        totalTurn+= turnTime[i];

    }

    avgWait = totalWait/n;
    avgTurnTime = totalTurn/n;

    printf("\n Process   Burst   Start   Finish     Wait    Turn\n");
    for(i = 0; i<n; i++)
        printf("%8d%8d%8d%8d%8d%8d\n",i+1,burstTime[i],start[i],finish[i],waitTime[i],turnTime[i]);
    printf("\nAverage waiting time = %g",avgWait);
    printf("\nAverage turn around time = %g",avgTurnTime);

}
