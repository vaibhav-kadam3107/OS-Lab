#include<stdio.h>
 
void main()
{
    int i, n, tq, total = 0, ct = 0, wt = 0, tat = 0;
    int at[10], bt[10], rt[10];
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter the arrival time and burst time for each process:\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d] : ", i+1);
        scanf("%d %d",&at[i],&bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter the time quantum: ");
    scanf("%d",&tq);
    printf("\nProcess\t    Arrival Time    \tBurst Time\tWaiting Time\tTurnaround Time");
    for(ct=0,i=0; n>0;)
    {
        if(rt[i]<=tq && rt[i]>0)
        {
            ct+=rt[i];
            rt[i]=0;
            total=1;
        }
        else if(rt[i]>0)
        {
            rt[i]-=tq;
            ct+=tq;
        }
        if(rt[i]==0 && total==1)
        {
            n--;
            printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d\t\t%d", i+1, at[i], bt[i], ct-at[i]-bt[i], ct-at[i]);
            wt+=ct-at[i]-bt[i];
            tat+=ct-at[i];
            total=0;
        }
        if(i==n-1)
            i=0;
        else if(at[i+1]<=ct)
            i++;
        else
            i=0;
    }
    printf("\n\nAverage Waiting Time = %.2f", (float)wt/n);
    printf("\nAverage Turnaround Time = %.2f\n", (float)tat/n);
}
