# OS-Lab
---------------------------------------------------------------------------------------------------------------------------------------------------------------------
2. Scheduling-SJF_Non_pre 
Suppose we have four processes P1, P2, P3, and P4 with the following arrival times and burst times:

Process	Arrival Time	Burst Time
P1	0	6
P2	1	3
P3	2	1
P4	3	2
We will run the program with the above input values.

First, the program will ask the user to enter the number of processes, which in this case is 4.

Then the program will read the arrival time and burst time for each process using the for loop. The loop will run four times, and the values will be assigned to the at and burst_time arrays.

Next, the program will calculate the total burst time of all processes and set the last element of the burst_time array to a very large value.

Then the program will simulate the SJF algorithm. The loop will run until all processes have been executed. At each iteration, the program will find the process with the shortest burst time that has arrived at or before the current time.

At time 0, process P1 arrives, so it is selected for execution. The program will print the details of process P1, including its ID, wait time, and turnaround time.

At time 6, process P3 arrives, so it is selected for execution. The program will print the details of process P3.

At time 7, process P2 arrives, so it is selected for execution. The program will print the details of process P2.

At time 10, process P4 arrives, so it is selected for execution. The program will print the details of process P4.

After all processes have been executed, the program will print the average wait time and average turnaround time of all processes.
------------------------------------------------------------------------------------------------------------------------------------------------------------------
3. Scheduling-SJF_pre 
Input:
Please enter number of processes: 4
Enter the Burst Time:
P1: 5
P2: 2
P3: 7
P4: 3

Output:
Process Burst Time Waiting Time Turnaround Time
P2 2 0 2
P4 3 2 5
P1 5 5 10
P3 7 10 17

The code first takes input for the number of processes and their burst times. The burst times are stored in the array burst_time[], and the process IDs are stored in the array p[]. The code then sorts the array burst_time[] in ascending order using selection sort.

After sorting, the code calculates the waiting time for each process. The waiting time for the first process (p1) is 0. For the rest of the processes, the waiting time is calculated as the sum of the burst times of all the previous processes.

Then, the code calculates the turnaround time for each process by adding its burst time and waiting time. The code also calculates the total waiting time and the total turnaround time to calculate the average waiting time and average turnaround time.

Finally, the code prints the process details along with their burst time, waiting time, and turnaround time, and the average waiting time and average turnaround time.

------------------------------------------------------------------------------------------------------------------------------------------------------------------

