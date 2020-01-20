#include<stdio.h>
#define MAX 20

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int burst[], int start, int n, int process[])
{
    int i, j, shortest, temp;;

    for(i=start; i<n; i++)
    {
        shortest = i;
        for(j=i; j<n; j++)
            if(burst[j]<burst[shortest])
                shortest = j;

        swap(burst+shortest, burst+i);
        swap(process+shortest, process+i);
    }
}
int main()
{
    int n,i,j,sum=0,time,next_process;
    int arrival[MAX],burst[MAX],start[MAX],process[MAX],flag[MAX];
    int finish[MAX],wait[MAX],turn[MAX];
    float totalturn=0,totalwait=0;
    start[0]=0;

    printf("Enter the number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter the arrival time and  burst time of process-%d: ",i+1);
        scanf("%d %d",&arrival[i],&burst[i]);
        process[i] = i+1;
        //flag[i]=1;
    }


    time = arrival[0];
    next_process=0;
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
            if(arrival[j]>time)
                break;

        sort(burst,i,j,process);

        start[i]=time;
        time+=burst[i];
        finish[i]=burst[i]+start[i];
        wait[i]=start[i]-arrival[i];
        turn[i]=burst[i]+wait[i];
        totalwait+=wait[i];
        totalturn+=turn[i];
    }

    printf("\n Process   Burst   Start  Finish    Wait    Turn\n");
    for(i=0;i<n;i++)
        printf("%8d%8d%8d%8d%8d%8d\n",process[i],burst[i],start[i],finish[i],wait[i],turn[i]);
    printf("\nAverage waiting time= %g",totalwait/n);
    printf("\nAverage turn around time= %g\n\n",totalturn/n);

    return 0;
}
