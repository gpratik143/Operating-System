#include <stdio.h>

#define MAX_PROCESS 5

struct Process {
    int id;
    int burst_time;
    int remaining_time;
    int arrival_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
};

void roundRobin(struct Process processes[], int n, int time_quantum) {
    int remaining_processes = n;
    int current_time = 0;
    int i;
    
    while (remaining_processes > 0) {
        for (i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0 && processes[i].arrival_time <= current_time) {
                int execute_time = (processes[i].remaining_time < time_quantum) ? processes[i].remaining_time : time_quantum;
                
                processes[i].remaining_time -= execute_time;
                current_time += execute_time;
                
                if (processes[i].remaining_time == 0) {
                    remaining_processes--;
                    processes[i].turnaround_time = current_time - processes[i].arrival_time;
                    processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
                }
                
                printf("Process %d executed for %d units of time.\n", processes[i].id, execute_time);
            }
        }
    }
}

int main() {
    struct Process processes[MAX_PROCESS] = {
        {1, 6, 6, 2, 0, 0, 0},
        {2, 2, 2, 5, 0, 0, 0},
        {3, 8, 8, 1, 0, 0, 0},
        {4, 3, 3, 7, 0, 0, 0},
        {5, 4, 4, 4, 0, 0, 0}
    };
    
    int n = sizeof(processes) / sizeof(processes[0]);
    int time_quantum;
    
    printf("Enter time quantum: ");
    scanf("%d", &time_quantum);
    
    roundRobin(processes, n, time_quantum);
    
    // Calculating averages
    float avg_turnaround_time = 0;
    float avg_waiting_time = 0;
    float avg_response_time = 0;
    
    for (int i = 0; i < n; i++) {
        processes[i].response_time = processes[i].waiting_time; // Response time is the same as waiting time in Round Robin
        avg_turnaround_time += processes[i].turnaround_time;
        avg_waiting_time += processes[i].waiting_time;
        avg_response_time += processes[i].response_time;
    }
    
    avg_turnaround_time /= n;
    avg_waiting_time /= n;
    avg_response_time /= n;
    
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);
    printf("Average Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Response Time: %.2f\n", avg_response_time);
    
    return 0;
}
