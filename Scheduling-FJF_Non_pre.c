#include<stdio.h>

int main(){
    int burst_time[10] , at[10] , n , time , sum_bt = 0 , smallest , sumtat = 0 , sumwt = 0;
    printf("Enter number of processes : ");
    scanf("%d", &n);
    //take input of AT and BT
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter AT of P%d : ", i+1);
        scanf("%d", &at[i]);

        printf("Enter BT of P%d : ", i+1);
        scanf("%d", &burst_time[i]);
        sum_bt += burst_time[i];
    }
    burst_time[9] = 999;

    for (int time = 0; time < sum_bt;)
    {
        //check for every process the lowest burst time
        smallest = 9;
        for (int i = 0; i < n; i++)
        {
            if(at[i] <= time && burst_time[i] > 0 && burst_time[i] < burst_time[smallest]){
                smallest = i;
                printf("Smallest = %d\n", smallest);
            }
        }
        printf("Process\t|\tTAT\t|\tWT\n");
        printf("P[%d]\t|\t%d\t|\t%d\n" , smallest + 1 , time + burst_time[smallest] - at[smallest] , time - at[smallest] );
        sumtat += time + burst_time[smallest] - at[smallest];
        sumwt += time - at[smallest];
        time += burst_time[smallest];
        burst_time[smallest] = 0;
    }
    printf("\nAvg TAT = %f\n", sumtat * 1.0 / n);
    printf("\nAvg WT = %f\n", sumwt * 1.0 / n);
    
    return 0;
}