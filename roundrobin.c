#include <stdio.h>

struct Process {
    int id;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int completion_time;
    int waiting_time;
    int turnaround_time;
};

void roundRobin(struct Process processes[], int n, int time_quantum) {
    int time = 0;
    int completed = 0;
    int i;
    while (completed < n) {
        int all_done = 1;
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= time) {
                all_done = 0;
                if (processes[i].remaining_time > time_quantum) {
                    time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                } else {
                    time += processes[i].remaining_time;
                    processes[i].completion_time = time;
                    processes[i].remaining_time = 0;
                    processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                    completed++;
                    printf("Process %d completed at time %d\n", processes[i].id, time);
                }
            }
        }
        if (all_done) {
            time++;
        }
    }
    
    printf("\nProcess ID | Arrival Time | Burst Time | Completion Time | Waiting Time | Turnaround Time\n");
    int total_waiting_time = 0;
    for (i = 0; i < n; i++) {
        printf("%9d | %12d | %10d | %15d | %12d | %15d\n",
               processes[i].id,
               processes[i].arrival_time,
               processes[i].burst_time,
               processes[i].completion_time,
               processes[i].waiting_time,
               processes[i].turnaround_time);
        total_waiting_time += processes[i].waiting_time;
    }

    float average_waiting_time = (float) total_waiting_time / n;
    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
}

int main() {
    int n, time_quantum;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the time quantum: ");
    scanf("%d", &time_quantum);
    
    struct Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burst_time);
        processes[i].remaining_time = processes[i].burst_time;
    }

    roundRobin(processes, n, time_quantum);
    return 0;
}




output
Enter the number of processes: 3
Enter the time quantum: 4
Enter arrival time for process 1: 5
Enter burst time for process 1: 6
Enter arrival time for process 2: 4
Enter burst time for process 2: 6
Enter arrival time for process 3: 2
Enter burst time for process 3: 5
Process 3 completed at time 15
Process 1 completed at time 17
Process 2 completed at time 19

Process ID | Arrival Time | Burst Time | Completion Time | Waiting Time | Turnaround Time
        1 |            5 |          6 |              17 |            6 |              12
        2 |            4 |          6 |              19 |            9 |              15
        3 |            2 |          5 |              15 |            8 |              13

Average Waiting Time: 7.67
