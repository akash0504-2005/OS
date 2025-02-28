#include <stdio.h>
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int burstTime[n], waitingTime[n];
    for (int i = 0; i < n; i++) {
        printf("\nEnter Burst Time for Process %d\n", i+1);
        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
    }
    waitingTime[0] = 0; 
    for (int i = 1; i < n; i++) {
        waitingTime[i] = burstTime[i-1] + waitingTime[i-1];
    }
    printf("\nProcess\tBurst Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i+1, burstTime[i], waitingTime[i]);
    }
    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
    }
    printf("\nAverage Waiting Time: %.2f", (float)totalWaitingTime / n);
    return 0;
}


 output

Enter number of processes: 3

Enter Burst Time for Process 1
Burst Time: 4

Enter Burst Time for Process 2
Burst Time: 3

Enter Burst Time for Process 3
Burst Time: 2

Process	Burst Time	Waiting Time
1	4		0
2	3		4
3	2		7

Average Waiting Time: 3.67
