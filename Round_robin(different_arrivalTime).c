#include <stdio.h>

int main()
{
    int flag = 0;
    int n, i, j, remaining, timeslice, remainTime[100];
    int burstTime[100], arrivalTime[100], time;
    double avgWait, avgTurnTime,totalWait = 0, totalTurn = 0;

    printf("\t\nRound Robin scheduling algorithm\n");

    printf("Number of processes: ");
    scanf("%d",&n);

    remaining = n;

    for(i = 0; i<n; i++)
    {
        printf("\nBurst time and arrivalTime of process %d: ",i+1);
        scanf("%d %d",&burstTime[i],&arrivalTime[i]);
        remainTime[i] = burstTime[i];
    }
    printf("Time slice: ");
    scanf("%d",&timeslice);

     printf("\n\n Process    Turn    wait\n");

     for(time = arrivalTime[0],i = 0; remaining !=0;)
     {
         if (arrivalTime[i]<time)
         {

             if(remainTime[i]<=timeslice && remainTime[i]>0)
             {
                 time = time+ remainTime[i];
                 remainTime[i] = 0;
                 flag = 1;

             }

            else if(remainTime[i]>0)
            {
                remainTime[i]-=timeslice;
                time+=timeslice;
            }

            if(remainTime[i]==0 && flag==1)
            {
                remaining--;
                printf("%8d%8d%8d\n",i+1,time,time-arrivalTime[i]-burstTime[i]);
                totalWait+=time-arrivalTime[i]-burstTime[i];
                totalTurn+=time-arrivalTime[i];
                flag = 0;
            }
         }
            if(i==n-1)
                i=0;
            else
                i++;

     }

       avgWait = totalWait/n;
    avgTurnTime = totalTurn/n;

    printf("\nAverage waiting time = %lf\n",avgWait);
    printf("Average turnaround time = %lf",avgTurnTime);

}


