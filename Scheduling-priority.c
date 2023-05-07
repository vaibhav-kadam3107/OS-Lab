#include <stdio.h>

void main()
{
    int n, i, j, sum = 0, bt[20], wt[20], tat[20], p[20], pr[20], temp;
    float avgwt = 0, avgtat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst time and priority of the processes:\n");
    for (i = 0; i < n; i++)
    {
        printf("P[%d] : ", i + 1);
        scanf("%d %d", &bt[i], &pr[i]);
        p[i] = i + 1;
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (pr[i] > pr[j])
            {
                temp = pr[i];
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
        sum += wt[i];
    }

    avgwt = (float)sum / n;
    sum = 0;

    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");

    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        sum += tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    avgtat = (float)sum / n;
    printf("\n\nAverage Waiting Time = %.2f", avgwt);
    printf("\nAverage Turnaround Time = %.2f\n", avgtat);
}
