#include <stdio.h>
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int  burstTime[n], priority[n];
    int waitingTime[n];
    int totalWaitingTime = 0;
    for (int i = 0; i < n; i++) {
        printf("\nEnter Burst Time, and Priority for Process %d\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &burstTime[i]);
        printf("Priority: ");
        scanf("%d", &priority[i]);
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (priority[i] > priority[j]) {
                int temp = burstTime[i];
                burstTime[i] = burstTime[j];
                burstTime[j] = temp;
                temp = priority[i];
                priority[i] = priority[j];
                priority[j] = temp;
            }
        }
    }
    waitingTime[0] = 0;  
    for (int i = 1; i < n; i++) {
        waitingTime[i] = waitingTime[i - 1] + burstTime[i - 1];
    }
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1,  burstTime[i], priority[i], waitingTime[i]);
    }
    for (int i = 0; i < n; i++) {
        totalWaitingTime += waitingTime[i];
    }
    printf("\nAverage Waiting Time: %.2f", (float)totalWaitingTime / n);
    return 0;
}



output
Enter number of processes: 3

Enter Burst Time, and Priority for Process 1
Burst Time: 4
Priority: 3

Enter Burst Time, and Priority for Process 2
Burst Time: 2
Priority: 1

Enter Burst Time, and Priority for Process 3
Burst Time: 6
Priority: 0

Process	Burst Time	Priority	Waiting Time
1	6		0		0
2	2		1		6
3	4		3		8

Average Waiting Time: 4.67
