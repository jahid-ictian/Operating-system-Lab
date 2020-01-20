#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sortFunction(int priority[], int n, int process[], int burst[])
{
    int i, j, shortest, temp;;

    for(i = 0; i<n; i++)
    {
        shortest = i;
        for(j = i; j<n; j++)
            if(priority[j]<priority[shortest])
                shortest = j;

        swap(priority+shortest, priority+i);
        swap(process+shortest, process+i);
        swap(burst+shortest, burst+i);
    }
}

int main()
{
    int n, i, j, totalWait = 0, totalTurn = 0, sum = 0;
    int burstTime[100], waitTime[100], start[100], finish[100], turnTime[100], process[100], priority[100];
    double avgWait, avgTurnTime;
    start[0] = 0;

    printf("\t\nPriority scheduling algorithm\n");

    printf("Number of processes: ");
    scanf("%d",&n);

    for(i = 0; i<n; i++)
    {
        printf("\nBurst time and priority of process %d: ",i+1);
        scanf("%d %d",&burstTime[i],&priority[i]);
        process[i] = i+1;
    }


    sortFunction(priority, n, process, burstTime);

    for(i = 0; i<n; i++)
    {
        sum+=burstTime[i];
        start[i+1]=sum;
        finish[i]=burstTime[i]+start[i];
        waitTime[i]=start[i];
        turnTime[i]=burstTime[i]+waitTime[i];
        totalWait+=waitTime[i];
        totalTurn+=turnTime[i];
    }
    avgWait = totalWait/n;
    avgTurnTime = totalTurn/n;

    printf("\n Process   Burst Priority   Start  Finish    Wait    Turn\n");
    for(i=0;i<n;i++)
        printf("%8d%8d %8d%8d%8d%8d%8d\n",process[i],burstTime[i],priority[i],start[i],finish[i],waitTime[i],turnTime[i]);
    printf("\nAverage waiting time = %lf",avgWait);
    printf("\nAverage turn around time  = %lf",avgTurnTime);

    return 0;

}
