#include <stdio.h>
#include <stdbool.h>
#define MAX_PROCESSES 5
#define MAX_RESOURCES 3
bool isDeadlocked(int processes, int resources, int available[], int allocation[][MAX_RESOURCES], int request[][MAX_RESOURCES]) {
    int work[resources], finish[processes];
    for (int i = 0; i < resources; i++) {
        work[i] = available[i];
    }
    for (int i = 0; i < processes; i++) {
        finish[i] = 0;
    }
    int count = 0;
    while (count < processes) {
        bool found = false;
        for (int i = 0; i < processes; i++) {
            if (!finish[i]) {
                bool canAllocate = true;
                for (int j = 0; j < resources; j++) {
                    if (request[i][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int j = 0; j < resources; j++) {
                        work[j] += allocation[i][j]; 
                    }
                    finish[i] = 1; 
                    found = true;
                    count++;
                    break;
                }
            }
        }
        if (!found) {
            return true; 
        }
    }
    return false; 
}
int main() {
    int processes, resources;
    printf("Enter number of processes: ");
    scanf("%d", &processes);
    printf("Enter number of resources: ");
    scanf("%d", &resources);
    int available[MAX_RESOURCES], allocation[MAX_PROCESSES][MAX_RESOURCES], request[MAX_PROCESSES][MAX_RESOURCES];
    printf("Enter the available resources:\n");
    for (int i = 0; i < resources; i++) {
        scanf("%d", &available[i]);
    }
    printf("Enter the allocation matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &allocation[i][j]);
        }
    }
    printf("Enter the request matrix:\n");
    for (int i = 0; i < processes; i++) {
        for (int j = 0; j < resources; j++) {
            scanf("%d", &request[i][j]);
        }
    }
    if (isDeadlocked(processes, resources, available, allocation, request)) {
        printf("The system is in a deadlocked state.\n");
    } else {
        printf("The system is not in a deadlocked state.\n");
    }
    return 0;
}
output
Enter number of processes: 5
Enter number of resources: 3
Enter the available resources:
0 0 0
Enter the allocation matrix:
0 1 0
2 0 0
3 0 3
2 1 1
0 0 2
Enter the request matrix:
0 0 0
2 0 2
0 0 0
1 0 0
0 0 2
The system is not in a deadlocked state.
