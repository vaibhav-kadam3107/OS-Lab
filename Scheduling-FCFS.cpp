#include <iostream>
using namespace std;

void find_waiting_time(int processes[] , int n , int bt[] , int wt[]){
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = bt[i-1] + wt[i-1];
    }
    
}

void find_turnaroundtime(int processes[] , int n , int bt[] , int wt[] , int tat[]){
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
    }
    
}

void find_avgTime(int processes[] , int n , int burst_time[]){
    int wt[n] , tat[n] , total_wt = 0 , total_tat = 0;

    find_waiting_time(processes, n, burst_time , wt);

    find_turnaroundtime(processes, n, burst_time , wt, tat);

    cout << "processes" << " burst time " << "waiting time" << "turn around time\n";

    for (int i = 0; i < n; i++)
    {
        total_wt = total_wt + wt[i];
        total_tat = total_tat + tat[i];
        cout<< "  " << i+1 << "\t\t" << burst_time[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << "\t\t" <<endl; 
    }
    cout<<"average waiting time :"<< (float)total_wt/(float)n <<endl;
    cout<<"average tat time :"<< (float)total_tat/(float)n<<endl;
}

int main(){
    int processes[] = { 1 , 2 , 3 };
    int n = sizeof processes / sizeof processes[0];
    int burst_time[] = { 10 , 5 , 8};

    find_avgTime(processes , n , burst_time);
    return 0;
}