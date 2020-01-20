#include <stdio.h>

int main()
{
    int n, i, j, totalWait = 0, totalTurn = 0, sum;
    int burstTime[100], arrivalTime[100], waitTime[100], start[100], finish[100], turnTime[100];
    double avgWait, avgTurnTime;

    printf("\t\nFirst come first scheduling algorithm\n");

    printf("Number of processes: ");
    scanf("%d",&n);

    for(i = 0; i<n; i++)
    {
        printf("\nBurst time and arrival time of process %d: ",i+1);
        scanf("%d%d",&burstTime[i],&arrivalTime[i]);
    }
    sum = start[0] = arrivalTime[0] = 0;

    for(i = 0; i<n; i++)
    {
        sum = sum + burstTime[i];
        start[i+1] = (sum>arrivalTime[i+1]? sum:arrivalTime[i+1]);
        finish[i] = burstTime[i] + start[i];
        waitTime[i] = start[i] - arrivalTime[i ];
        turnTime[i] = waitTime[i] + burstTime[i];
        totalWait+= waitTime[i];
        totalTurn+= turnTime[i];

    }

     avgWait = totalWait/n;
    avgTurnTime = totalTurn/n;

    printf("\n Process Arrival   Burst   Start  Finish    Wait    Turn\n");
    for(i = 0; i<n; i++)
        printf("%8d%8d%8d%8d%8d%8d%8d\n",i+1,arrivalTime[i],burstTime[i],start[i],finish[i],waitTime[i],turnTime[i]);
    printf("\nAverage waiting time= %g",avgWait);
    printf("\nAverage turn around time= %g",avgTurnTime);

}

